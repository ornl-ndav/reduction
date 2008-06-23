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
 * \file axis_manip/src/wavelength_to_d_spacing.hpp
 */
#ifndef _WAVELENGTH_TO_D_SPACING_HPP
#define _WAVELENGTH_TO_D_SPACING_HPP 1

#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <cmath>
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the wavelength_to_d_spacing function name
  const std::string wtds_func_str = "AxisManip::wavelength_to_d_spacing";

  // 3.25
  template <typename NumT>
  std::string
  wavelength_to_d_spacing(const Nessi::Vector<NumT> & wavelength,
                          const Nessi::Vector<NumT> & wavelength_err2,
                          const NumT polar_angle,
                          const NumT polar_angle_err2,
                          Nessi::Vector<NumT> & d_spacing,
                          Nessi::Vector<NumT> & d_spacing_err2,
                          void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, d_spacing);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtds_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(wavelength_err2, d_spacing_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtds_func_str+" (v,v): err2 "+e.what());
      }

    // check that the wavelength arrays are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtds_func_str+" (v,v): wavelength "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT b2;

    // fill the local variables
    retstr += __wavelength_to_d_spacing_static(polar_angle, a, a2, b2);

    // do the calculation
    size_t size_wavelength = wavelength.size();

	#pragma omp parallel for
    for (int i=0; i < static_cast<int>(size_wavelength) ; ++i)
    {
        std::string tempS = __wavelength_to_d_spacing_dynamic(wavelength[i],
                                                    wavelength_err2[i],
                                                    polar_angle,
                                                    polar_angle_err2,
                                                    a, a2, b2,
                                                    d_spacing[i],
                                                    d_spacing_err2[i]);
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

  // 3.25
  template <typename NumT>
  std::string
  wavelength_to_d_spacing(const NumT wavelength,
                          const NumT wavelength_err2,
                          const NumT polar_angle,
                          const NumT polar_angle_err2,
                          NumT & d_spacing,
                          NumT & d_spacing_err2,
                          void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT b2;

    // fill the local variables
    retstr += __wavelength_to_d_spacing_static(polar_angle, a, a2, b2);

    // do the calculation
    retstr += __wavelength_to_d_spacing_dynamic(wavelength,
                                                wavelength_err2,
                                                polar_angle,
                                                polar_angle_err2,
                                                a, a2, b2,
                                                d_spacing,
                                                d_spacing_err2);

    return retstr;
  }

 /**
   * \ingroup wavelength_to_d_spacing
   *
   * This is a PRIVATE helper function for wavelength_to_d_spacing that
   * calculates parameters invariant across array calculation
   *
   * \param polar_angle (INPUT) same as parameter in wavelength_to_d_spacing()
   * \param a (OUTPUT) the value of 2 times the sine of the angle between 
   * positive z axis and direction of the scattered neutrons
   * \param a2 (OUTPUT) \f$=a^2\f$
   * \param b2 (OUTPUT) the square of the cotangent of the angle between the 
   * positive z axis and the direction of the scattered neutrons
   */
  template <typename NumT>
  std::string
  __wavelength_to_d_spacing_static(const NumT polar_angle,
                                   NumT & a,
                                   NumT & a2,
                                   NumT & b2) 
                                 
  {
    a = static_cast<NumT>(2.0 * std::sin(static_cast<double>(polar_angle / 2.0)));
    a2 = a * a;
    NumT b = static_cast<NumT>(std::cos(static_cast<double>(polar_angle / 2.0))
                               / 
                               std::sin(static_cast<double>(polar_angle / 2.0)));
    b2 = b * b;
    
    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup wavelength_to_d_spacing
   *
   * This is a PRIVATE helper function for wavelength_to_d_spacing that
   * calculates the scalar momentum transfer and its uncertainty
   *
   * \param wavelength (INPUT) same as parameter in wavelength_to_d_spacing()
   * \param wavelength_err2 (INPUT) same as parameter in
   * wavelength_to_d_spacing()
   * \param polar_angle (INPUT) same as parameter in wavelength_to_d_spacing()
   * \param polar_angle_err2 (INPUT) same as parameter in
   * wavelength_to_d_spacing()
   * \param a (INPUT) same as parameter in __wavelength_to_d_spacing_static()
   * \param a2 (INPUT) same as parameter in __wavelength_to_d_spacing_static()
   * \param b2 (INPUT) same as parameter in __wavelength_to_d_spacing_static()
   * \param d_spacing (OUTPUT) same as parameter in wavelength_to_d_spacing()
   * \param d_spacing_err2 (OUTPUT) same as parameter
   * in wavelength_to_d_spacing()
   */
  template <typename NumT>
  std::string
  __wavelength_to_d_spacing_dynamic(const NumT wavelength,
                                    const NumT wavelength_err2,
                                    const NumT polar_angle,
                                    const NumT polar_angle_err2,
                                    const NumT a,
                                    const NumT a2,
                                    const NumT b2,
                                    NumT & d_spacing,
                                    NumT & d_spacing_err2)
  {
    NumT wl = wavelength;
    NumT wl2 = static_cast<NumT>(wl * wl / 4.0);

    // the result
    d_spacing = wl/a;

    // the uncertainty in the result
    d_spacing_err2 = (wavelength_err2 / a2) + 
      (wl2 * b2 * polar_angle_err2 / a2);

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _WAVELENGTH_TO_D_SPACING_HPP
