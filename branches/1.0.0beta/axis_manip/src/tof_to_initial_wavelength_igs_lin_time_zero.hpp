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
 * \file axis_manip/src/tof_to_initial_wavelength_igs_lin_time_zero.hpp
 */
#ifndef _TOF_TO_INITIAL_WAVELENGTH_IGS_LIN_TIME_ZERO_HPP
#define _TOF_TO_INITIAL_WAVELENGTH_IGS_LIN_TIME_ZERO_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the tof_to_initial_wavelength_igs_lin_time_zero 
  /// function name
  const std::string ttiwiltz_func_str = \
  "AxisManip::tof_to_initial_wavelength_igs_lin_time_zero";

  // 3.48
  template <typename NumT>
  std::string
  tof_to_initial_wavelength_igs_lin_time_zero(const Nessi::Vector<NumT> & tof,
                                const Nessi::Vector<NumT> & tof_err2,
                                const NumT final_wavelength,
                                const NumT final_wavelength_err2,
                                const NumT time_0_slope,
                                const NumT time_0_slope_err2,
                                const NumT time_0_offset,
                                const NumT time_0_offset_err2,
                                const NumT dist_source_sample,
                                const NumT dist_source_sample_err2,
                                const NumT dist_sample_detector,
                                const NumT dist_sample_detector_err2,
                                Nessi::Vector<NumT> & initial_wavelength,
                                Nessi::Vector<NumT> & initial_wavelength_err2,
                                void *temp=NULL)

  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(tof, initial_wavelength);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttiwiltz_func_str+" (v,v): data "
                                    +e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(tof_err2, initial_wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttiwiltz_func_str+" (v,v): err2 "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);    // the warning string

    // alloacate local variables
    NumT a;
    NumT a2;
    NumT b;
    NumT c;
    NumT d;

    // calculate static paramters
    retstr += 
      __tof_to_initial_wavelength_igs_lin_time_zero_static(
                                                    final_wavelength,
                                                    final_wavelength_err2,
                                                    time_0_slope,
                                                    time_0_slope_err2,
                                                    time_0_offset,
                                                    time_0_offset_err2,
                                                    dist_source_sample,
                                                    dist_source_sample_err2,
                                                    dist_sample_detector, 
                                                    dist_sample_detector_err2, 
                                                    a, a2, b, c, d);

    // fill the results array
    size_t size_tof = tof.size();
    for (size_t i = 0 ; i < size_tof ; ++i)
      {
        retstr +=
          __tof_to_initial_wavelength_igs_lin_time_zero_dynamic(
                                                  tof[i], 
                                                  tof_err2[i],
                                                  initial_wavelength[i],
                                                  initial_wavelength_err2[i],
                                                  a, a2, b, c, d);
      }

    // send back all warnings
    return retstr;
  }

  // 3.48
  template <typename NumT>
  std::string
  tof_to_initial_wavelength_igs_lin_time_zero(const NumT tof,
                                const NumT tof_err2,
                                const NumT final_wavelength,
                                const NumT final_wavelength_err2,
                                const NumT time_0_slope,
                                const NumT time_0_slope_err2,
                                const NumT time_0_offset,
                                const NumT time_0_offset_err2,
                                const NumT dist_source_sample,
                                const NumT dist_source_sample_err2,
                                const NumT dist_sample_detector,
                                const NumT dist_sample_detector_err2,
                                NumT & initial_wavelength,
                                NumT & initial_wavelength_err2,
                                void *temp=NULL)
  {
    // define some parameters that are static across the array calculation
    NumT a;
    NumT a2;
    NumT b;
    NumT c;
    NumT d;

    // some string parameters for dealing with warnings
    std::string retstr(Nessi::EMPTY_WARN);

    // calculate static paramters
    retstr += 
      __tof_to_initial_wavelength_igs_lin_time_zero_static(
                                                    final_wavelength,
                                                    final_wavelength_err2,
                                                    time_0_slope,
                                                    time_0_slope_err2,
                                                    time_0_offset,
                                                    time_0_offset_err2,
                                                    dist_source_sample,
                                                    dist_source_sample_err2,
                                                    dist_sample_detector, 
                                                    dist_sample_detector_err2, 
                                                    a, a2, b, c, d);

    // fill the results
    retstr +=
      __tof_to_initial_wavelength_igs_lin_time_zero_dynamic(
                                                       tof, 
                                                       tof_err2,
                                                       initial_wavelength,
                                                       initial_wavelength_err2,
                                                       a, a2, b, c, d);

    // send back all warnings
    return retstr;
  }

  /**
   * \ingroup tof_to_initial_wavelength_igs_lin_time_zero
   *
   * This is a PRIVATE helper function for
   * tof_to_initial_wavelength_igs_lin_time_zero that calculates parameters
   * invariant across the array calculation.
   *
   * \param final_wavelength (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param final_wavelength_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param time_0_slope (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param time_0_slope_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param time_0_offset (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param time_0_offset_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param dist_source_sample (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param dist_source_sample_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param dist_sample_detector (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param dist_sample_detector_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param a (OUTPUT) \f$=\frac{1}{\frac{m_n}{h} dist\_source\_sample + 
   * time\_0\_slope}\f$
   * \param a2 (OUTPUT) \f$=a^2\f$
   * \param b (OUTPUT) \f$=\frac{m_n}{h}(dist\_sample\_detector \times 
   * final\_wavelength) + time\_0\_offset\f$
   * \param c (OUTPUT) \f$=\left(\frac{m_n}{h}\right)^2 \times 
   * dist\_source\_sample\_err2 + time\_0\_slope\_err2\f$
   * \param d (OUTPUT) \f$=(dist\_sample\_detector^2 \times 
   * final\_wavelength\_err2) + (final\_wavelength^2 \times 
   * dist\_sample\_detector\_err2) + time\_0\_offset\_err2\f$
   */
  template <typename NumT>
  std::string __tof_to_initial_wavelength_igs_lin_time_zero_static(
                                         const NumT final_wavelength,
                                         const NumT final_wavelength_err2,
                                         const NumT time_0_slope,
                                         const NumT time_0_slope_err2,
                                         const NumT time_0_offset,
                                         const NumT time_0_offset_err2,
                                         const NumT dist_source_sample,
                                         const NumT dist_source_sample_err2,
                                         const NumT dist_sample_detector,
                                         const NumT dist_sample_detector_err2,
                                         NumT & a,
                                         NumT & a2,
                                         NumT & b,
                                         NumT & c,
                                         NumT & d)
  {
    NumT k = static_cast<NumT>(PhysConst::H_OVER_MNEUT);

    a = static_cast<NumT>(1.) / ((dist_source_sample / k) + time_0_slope);

    a2 = a * a;

    b = ((dist_sample_detector * final_wavelength) / k) + time_0_offset;
    b *= a;

    c = (dist_source_sample_err2 / (k * k)) + time_0_slope_err2;
    
    NumT ld2 = dist_sample_detector * dist_sample_detector;
    NumT lf2 = final_wavelength * final_wavelength;
    
    d = (((ld2 * final_wavelength_err2) + 
          (lf2 * dist_sample_detector_err2)) / (k * k)) + time_0_offset_err2;
    
    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup tof_to_initial_wavelength_igs_lin_time_zero
   *
   * This is a PRIVATE helper function for
   * tof_to_initial_wavelength_igs_lin_time_zero that calculates the
   * initial_wavelength and its uncertainty.
   *
   * \param tof (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param tof_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param initial_wavelength (OUTPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param initial_wavelength_err2 (OUTPUT) same as parameter in
   * tof_to_initial_wavelength_igs_lin_time_zero()
   * \param a (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_lin_time_zero_static()
   * \param a2 (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_lin_time_zero_static()
   * \param b (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_lin_time_zero_static()
   * \param c (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_lin_time_zero_static()
   * \param d (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_lin_time_zero_static()
   */
  template <typename NumT>
  std::string __tof_to_initial_wavelength_igs_lin_time_zero_dynamic(
                                         const NumT tof,
                                         const NumT tof_err2,
                                         NumT & initial_wavelength,
                                         NumT & initial_wavelength_err2,
                                         const NumT a,
                                         const NumT a2,
                                         const NumT b,
                                         const NumT c,
                                         const NumT d)
  {
    // the result
    initial_wavelength = a * tof - b;

    // the uncertainty in the result
    initial_wavelength_err2 = initial_wavelength * initial_wavelength * c;
    initial_wavelength_err2 += tof_err2 + d;
    initial_wavelength_err2 *= a2;

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _TOF_TO_INITIAL_WAVELENGTH_IGS_LIN_TIME_ZERO_HPP
