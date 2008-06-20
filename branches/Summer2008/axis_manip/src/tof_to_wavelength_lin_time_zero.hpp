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
 * \file axis_manip/src/tof_to_wavelength_lin_time_zero.hpp
 */
#ifndef _TOF_TO_WAVELENGTH_LIN_TIME_ZERO_HPP
#define _TOF_TO_WAVELENGTH_LIN_TIME_ZERO_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the tof_to_wavelength_lin_time_zero function name
  const std::string ttwltz_func_str = \
  "AxisManip::tof_to_wavelength_lin_time_zero";

  // 3.50
  template <typename NumT>
  std::string
  tof_to_wavelength_lin_time_zero(const Nessi::Vector<NumT> & tof,
                                  const Nessi::Vector<NumT> & tof_err2,
                                  const NumT pathlength,
                                  const NumT pathlength_err2,
                                  const NumT time_0_slope,
                                  const NumT time_0_slope_err2,
                                  const NumT time_0_offset,
                                  const NumT time_0_offset_err2,
                                  Nessi::Vector<NumT> & wavelength,
                                  Nessi::Vector<NumT> & wavelength_err2,
                                  void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(tof, wavelength);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttwltz_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(tof_err2, wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttwltz_func_str+" (v,v): err2 "+e.what());
      }

    // check that the tof arrays are of proper size
    try
      {
        Utils::check_sizes_square(tof, tof_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttwltz_func_str+" (v,v): tof "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT b;
    NumT c;

    // fill the local variables
    retstr += __tof_to_wavelength_lin_time_zero_static(pathlength, 
                                                       pathlength_err2,
                                                       time_0_slope,
                                                       time_0_slope_err2,
                                                       time_0_offset,
                                                       a, a2, b, c);

    // do the calculation
    size_t size_tof = tof.size();

    for (size_t i = 0; i < size_tof; ++i)
      {
        retstr += __tof_to_wavelength_lin_time_zero_dynamic(
                                                         tof[i], 
                                                         tof_err2[i],
                                                         time_0_offset_err2,
                                                         a, a2, b, c,
                                                         wavelength[i],
                                                         wavelength_err2[i]);
      }

    return retstr;
  }

  // 3.50
  template <typename NumT>
  std::string
  tof_to_wavelength_lin_time_zero(const NumT tof,
                                  const NumT tof_err2,
                                  const NumT pathlength,
                                  const NumT pathlength_err2,
                                  const NumT time_0_slope,
                                  const NumT time_0_slope_err2,
                                  const NumT time_0_offset,
                                  const NumT time_0_offset_err2,
                                  NumT & wavelength,
                                  NumT & wavelength_err2,
                                  void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT b;
    NumT c;

    // fill the local variables
    retstr += __tof_to_wavelength_lin_time_zero_static(pathlength, 
                                                       pathlength_err2,
                                                       time_0_slope,
                                                       time_0_slope_err2,
                                                       time_0_offset,
                                                       a, a2, b, c);

    // do the calculation
    retstr += __tof_to_wavelength_lin_time_zero_dynamic(tof, tof_err2, 
                                                        time_0_offset_err2,
                                                        a, a2, b, c,
                                                        wavelength, 
                                                        wavelength_err2);

    return retstr;
  }

  /**
   * \ingroup tof_to_wavelength_lin_time_zero
   *
   * This is a PRIVATE helper function for tof_to_wavelength_lin_time_zero that
   * calculates parameters invariant across array calculation.
   *
   * \param pathlength (INPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   * \param pathlength_err2 (INPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   * \param time_0_slope (INPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   * \param time_0_slope_err2 (INPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   * \param time_0_offset (INPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   * \param a (OUTPUT) \f$=\frac{1}{\frac{m_n pathlength}{h} + 
   * time\_0\_slope}\f$
   * \param a2 (OUTPUT) \f$=a * a\f$
   * \param b (OUTPUT) \f$=t\_0\_offset * a\f$
   * \param c (OUTPUT) \f$=(\frac{m_n}{h})^2 pathlength\_err2 + 
   * time\_0\_slope\_err2\f$
   */
  template <typename NumT>
  std::string  __tof_to_wavelength_lin_time_zero_static(
                                             const NumT pathlength,
                                             const NumT pathlength_err2,
                                             const NumT time_0_slope,
                                             const NumT time_0_slope_err2,
                                             const NumT time_0_offset,
                                             NumT & a,
                                             NumT & a2,
                                             NumT & b,
                                             NumT & c)
  {
    // calculate the factor to multiply each element by
    NumT k =  static_cast<NumT>(1.) / 
      static_cast<NumT>(PhysConst::H_OVER_MNEUT);

    a = static_cast<NumT>(1.) / ((k * pathlength) + time_0_slope);

    a2 = a * a;

    b = time_0_offset * a;

    c = (k * k * pathlength_err2) + time_0_slope_err2;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup tof_to_wavelength_lin_time_zero
   *
   * This is a PRIVATE helper function for tof_to_wavelength_lin_time_zero that
   * calculates the wavelength and its uncertainty
   *
   * \param tof (INPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   * \param tof_err2 (INPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   * \param time_0_offset_err2 (INPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   * \param a (INPUT) same as the parameter in
   * __tof_to_wavelength_lin_time_zero_static()
   * \param a2 (INPUT) same as the parameter in
   * __tof_to_wavelength_lin_time_zero_static()
   * \param b (INPUT) same as the parameter in
   * __tof_to_wavelength_lin_time_zero_static()
   * \param c (INPUT) same as the parameter in
   * __tof_to_wavelength_lin_time_zero_static()
   * \param wavelength (OUTPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   * \param wavelength_err2 (OUTPUT) same as the parameter in
   * tof_to_wavelength_lin_time_zero()
   */
  template <typename NumT>
  std::string  __tof_to_wavelength_lin_time_zero_dynamic(
                                                const NumT tof,
                                                const NumT tof_err2,
                                                const NumT time_0_offset_err2,
                                                const NumT a,
                                                const NumT a2,
                                                const NumT b,
                                                const NumT c,
                                                NumT & wavelength,
                                                NumT & wavelength_err2)
  {
    // calculate the value
    wavelength = a * tof - b;

    // calculate the uncertainty
    NumT wavelength2 = wavelength * wavelength;
    wavelength_err2 = tof_err2 + time_0_offset_err2 + (wavelength2 * c);
    wavelength_err2 *= a2;

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _TOF_TO_WAVELENGTH_LIN_TIME_ZERO_HPP
