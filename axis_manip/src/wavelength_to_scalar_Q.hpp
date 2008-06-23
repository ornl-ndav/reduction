/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 *
 * For this software and its associated documentation, permission is granted
 * to reproduce, prepare derivative works, and distribute copies to the public
 * for any purpose and without fee.
 *
 * This material was prepared as an account of work sponsored by an agency of
 * the United States Government.  Neither the United States Government nor the
 * United States Department of Energy, nor any of their employees, makes any
 * warranty, express or implied, or assumes any legal liability or
 * responsibility for the accuracy, completeness, or usefulness of any
 * information, apparatus, product, or process disclosed, or represents that
 * its use would not infringe privately owned rights.
 *
 */

/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_Q.hpp
 */
#ifndef _WAVELENGTH_TO_SCALAR_Q_HPP
#define _WAVELENGTH_TO_SCALAR_Q_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <cmath>
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the wavelength_to_scalar_Q function name
  const std::string wtsq_func_str = "AxisManip::wavelength_to_scalar_Q";

  // 3.18
  template <typename NumT>
  std::string
  wavelength_to_scalar_Q(const Nessi::Vector<NumT> & wavelength,
                         const Nessi::Vector<NumT> & wavelength_err2,
                         const NumT polar_angle,
                         const NumT polar_angle_err2,
                         Nessi::Vector<NumT> & Q,
                         Nessi::Vector<NumT> & Q_err2,
                         void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, Q);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtsq_func_str+" (v,s): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(wavelength_err2, Q_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtsq_func_str+" (v,s): err2 "+e.what());
      }

    // check that the wavelength arrays are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtsq_func_str+" (v,s): wavelength "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT _4Pi;
    NumT sin;
    NumT sin2;
    NumT term;

    // fill the local variables
    retstr += __wavelength_to_scalar_Q_static(polar_angle, polar_angle_err2, 
                                              _4Pi, sin, sin2, term);

    // do the calculation
    size_t size_wavelength = wavelength.size();

	#pragma omp parallel for
    for (int i=0; i < static_cast<int>(size_wavelength) ; ++i)
    {
        std::string tempS = __wavelength_to_scalar_Q_dynamic(wavelength[i],
                                                   wavelength_err2[i],
                                                   _4Pi, sin, sin2, term,
                                                   Q[i], 
                                                   Q_err2[i]);
		if (!tempS.empty())
		{
			#pragma omp critical
			{
				retstr += tempS;
			}
		}
    }

    return retstr;
  }

  template <typename NumT>
  std::string
  wavelength_to_scalar_Q(const NumT wavelength,
                         const NumT wavelength_err2,
                         const NumT polar_angle,
                         const NumT polar_angle_err2,
                         NumT & Q,
                         NumT & Q_err2,
                         void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT _4Pi;
    NumT sin;
    NumT sin2;
    NumT term;

    // fill the local variables
    retstr += __wavelength_to_scalar_Q_static(polar_angle, polar_angle_err2,
                                              _4Pi, sin, sin2, term);

    // do the calculation
    retstr += __wavelength_to_scalar_Q_dynamic(wavelength,
                                               wavelength_err2,
                                               _4Pi, sin, sin2, term,
                                               Q,
                                               Q_err2);

    return retstr;
  }

  /**
   * \ingroup wavelength_to_scalar_Q
   *
   * This is a PRIVATE helper function for wavelength_to_scalar_Q that
   * calculates parameters invariant across array calculation
   *
   * \param polar_angle (INPUT) same as parameter in wavelength_to_scalar_Q()
   * \param polar_angle_err2 (INPUT) same as parameter in 
   * wavelength_to_scalar_Q()
   * \param _4Pi (OUTPUT) the value of 4 times Pi
   * \param sin (OUTPUT) the sinus of the angle between positive z axis
   * and direction of the scattered neutrons
   * \param sin2 (OUTPUT) the square of the sinus of the angle between positive
   * z axis and direction of the scattered neutrons
   * \param term (OUTPUT) \f$\frac{cos^2(polar/2)}{4}\times \sigma_{polar}^2\f$
   */
  template <typename NumT>
  std::string
  __wavelength_to_scalar_Q_static(const NumT polar_angle,
                                  const NumT polar_angle_err2,
                                  NumT & _4Pi,
                                  NumT & sin,
                                  NumT & sin2,
                                  NumT & term)
  {
    _4Pi = 4.*static_cast<NumT>(PhysConst::PI);
    sin=static_cast<NumT>(std::sin(static_cast<double>(polar_angle/2.0)));
    sin2=sin*sin;
    NumT cos
      = static_cast<NumT>(std::cos(static_cast<double>(polar_angle/2.0)));
    term = ((cos * cos) / static_cast<NumT>(4.0)) * polar_angle_err2;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup wavelength_to_scalar_Q
   *
   * This is a PRIVATE helper function for wavelength_to_scalar_Q that
   * calculates the scalar momentum transfer and its uncertainty
   *
   * \param wavelength (INPUT) same as parameter in wavelength_to_scalar_Q()
   * \param wavelength_err2 (INPUT) same as parameter in
   * wavelength_to_scalar_Q()
   * \param _4Pi (INPUT) same as parameter in __wavelength_to_scalar_Q_static()
   * \param sin (INPUT) same as parameter in __wavelength_to_scalar_Q_static()
   * \param sin2 (INPUT) same as parameter in __wavelength_to_scalar_Q_static()
   * \param term (INPUT) same as parameter in __wavelength_to_scalar_Q_static()
   * \param Q (OUTPUT) same as parameter in wavelength_to_scalar_Q()
   * \param Q_err2 (OUTPUT) same as parameter in wavelength_to_scalar_Q()
   */
  template <typename NumT>
  std::string
  __wavelength_to_scalar_Q_dynamic(const NumT wavelength,
                                   const NumT wavelength_err2,
                                   const NumT _4Pi,
                                   const NumT sin,
                                   const NumT sin2,
                                   const NumT term,
                                   NumT & Q,
                                   NumT & Q_err2)
  {
    NumT _4Pi_wave = _4Pi / wavelength;

    // the result
    Q = sin * _4Pi_wave;

    // the uncertainty in the result
    Q_err2 = term;
    Q_err2 += (sin2 * wavelength_err2)/(wavelength*wavelength);
    Q_err2 *= _4Pi_wave*_4Pi_wave;

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _WAVELENGTH_TO_SCALAR_Q_HPP
