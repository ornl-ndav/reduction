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
 * \file axis_manip/src/wavelength_to_tof.hpp
 */
#ifndef _WAVELENGTH_TO_TOF_HPP
#define _WAVELENGTH_TO_TOF_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the wavelength_to_tof function name
  const std::string wtt_func_str = "AxisManip::wavelength_to_tof";

  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(const Nessi::Vector<NumT> & wavelength,
                    const Nessi::Vector<NumT> & wavelength_err2,
                    const NumT pathlength,
                    const NumT pathlength_err2,
                    Nessi::Vector<NumT> & tof,
                    Nessi::Vector<NumT> & tof_err2,
                    void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, tof);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtt_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(wavelength_err2, tof_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtt_func_str+" (v,v): err2 "+e.what());
      }

    // check that the wavelength arrays are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtt_func_str+" (v,v): wavelength "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT a_err2;

    // fill the local variables
    retstr += __wavelength_to_tof_static(pathlength, pathlength_err2,
                                         a, a2, a_err2);
    // do the calculation 
    size_t size_wavelength = wavelength.size();

	#pragma omp parallel for
    for (int i = 0; i < (int) size_wavelength; ++i)
    {
        std::string tempS = __wavelength_to_tof_dynamic(wavelength[i], 
                                              wavelength_err2[i],
                                              a, a2, a_err2,
                                              tof[i],
                                              tof_err2[i]);
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

  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(const NumT wavelength,
                    const NumT wavelength_err2,
                    const NumT pathlength,
                    const NumT pathlength_err2,
                    NumT & tof,
                    NumT & tof_err2,
                    void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT a_err2;

    // fill the local variables
    retstr += __wavelength_to_tof_static(pathlength, pathlength_err2,
                                         a, a2, a_err2);

    // do the calculation
    retstr += __wavelength_to_tof_dynamic(wavelength, wavelength_err2, 
                                          a, a2, a_err2,
                                          tof, tof_err2);

    return retstr;
  }

  /**
   * \ingroup wavelength_to_tof
   *
   * This is a PRIVATE helper function for wavelength_to_tof that
   * calculates parameters invariant across array calculation.
   *
   * \param pathlength (INPUT) same as the parameter in
   * wavelength_to_tof_static()
   * \param pathlength_err2 (INPUT) same as the parameter in
   * wavelength_to_tof_static()
   * \param a (OUTPUT) \f$=\frac{m_n pathlength}{h}\f$
   * \param a2 (OUTPUT) \f$=a*a\f$
   * \param a_err2 (OUTPUT) \f$=\left(\frac{m_n}{h}\right)^2 
   * pathlength\_err2\f$
   */
  template <typename NumT>
  std::string  __wavelength_to_tof_static(const NumT pathlength,
                                          const NumT pathlength_err2,
                                          NumT & a,
                                          NumT & a2,
                                          NumT & a_err2)
  {
    // calculate the factor to multiply each element by
    a = static_cast<NumT>(1.0 / PhysConst::H_OVER_MNEUT) * pathlength;
    a2 = a * a;

    // the result of these two lines is the uncertainty in the
    // multiplicative factor
    a_err2 = a / pathlength;
    a_err2 = a_err2 * a_err2 * pathlength_err2;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup wavelength_to_tof
   *
   * This is a PRIVATE helper function for wavelength_to_tof that
   * calculates the wavelength and its uncertainty
   *
   * \param wavelength (INPUT) same as the parameter in
   * wavelength_to_tof()
   * \param wavelength_err2 (INPUT) same as the parameter in
   * wavelength_to_tof()
   * \param a (INPUT) same as the parameter in
   * __wavelength_to_tof_static()
   * \param a2 (INPUT) same as the parameter in
   * __wavelength_to_tof_static()
   * \param  a_err2 (INPUT) same as the parameter in
   * __wavelength_to_tof_static()
   * \param  tof (OUTPUT) same as the parameter in
   * wavelength_to_tof()
   * \param  tof_err2 (OUTPUT) same as the parameter in
   * wavelength_to_tof()
   */
  template <typename NumT>
  std::string  __wavelength_to_tof_dynamic(const NumT wavelength,
                                           const NumT wavelength_err2,
                                           const NumT a,
                                           const NumT a2,
                                           const NumT a_err2,
                                           NumT & tof,
                                           NumT & tof_err2)
  {
    // calculate the value
    tof = a * wavelength;

    // calculate the uncertainty
    tof_err2 = (a2 * wavelength_err2) + ((wavelength * wavelength) * a_err2);

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _WAVELENGTH_TO_TOF_HPP
