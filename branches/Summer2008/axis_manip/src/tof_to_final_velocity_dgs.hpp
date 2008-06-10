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
 * \file axis_manip/src/tof_to_final_velocity_dgs.hpp
 */
#ifndef _TOF_TO_FINAL_VELOCITY_DGS_HPP
#define _TOF_TO_FINAL_VELOCITY_DGS_HPP 1

#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the tof_to_final_velocity_dgs function name
  const std::string ttfvd_func_str = "AxisManip::tof_to_final_velocity_dgs";

  // 3.27
  template <typename NumT>
  std::string
  tof_to_final_velocity_dgs(const Nessi::Vector<NumT> & tof,
                            const Nessi::Vector<NumT> & tof_err2,
                            const NumT initial_velocity,
                            const NumT initial_velocity_err2,
                            const NumT time_offset,
                            const NumT time_offset_err2,
                            const NumT dist_source_sample,
                            const NumT dist_source_sample_err2,
                            const NumT dist_sample_detector,
                            const NumT dist_sample_detector_err2,
                            Nessi::Vector<NumT> & final_velocity,
                            Nessi::Vector<NumT> & final_velocity_err2,
                            void *temp=NULL)
  {
   // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(tof, final_velocity);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttfvd_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(tof_err2, final_velocity_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttfvd_func_str+" (v,v): err2 "+e.what());
      }

    // check that the tof arrays are of proper size
    try
      {
        Utils::check_sizes_square(tof, tof_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttfvd_func_str+" (v,v): err2 "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);    // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT b;
    NumT c;
    NumT c2;
    NumT ld2;
   
    // calculate static paramters
    retstr +=__tof_to_final_velocity_dgs_static(initial_velocity,
                                                dist_source_sample,
                                                time_offset,
                                                dist_sample_detector,
                                                a, a2, b, c, c2, ld2);

    // fill the results array
    size_t size_tof = tof.size();

	#pragma omp parallel for default(shared) private(i, retstr) \
		reduction(+:retstr)
    for (size_t i = 0 ; i < size_tof ; ++i)
      {
        retstr +=
          __tof_to_final_velocity_dgs_dynamic(tof[i], 
                                              tof_err2[i],
                                              initial_velocity_err2,
                                              time_offset_err2,
                                              dist_source_sample_err2,
                                              dist_sample_detector,
                                              dist_sample_detector_err2,
                                              final_velocity[i],
                                              final_velocity_err2[i],
                                              a, a2, b, c, c2, ld2);
      }

    // send back all warnings
    return retstr;
  }

  // 3.27
  template <typename NumT>
  std::string
  tof_to_final_velocity_dgs(const NumT tof,
                            const NumT tof_err2,
                            const NumT initial_velocity,
                            const NumT initial_velocity_err2,
                            const NumT time_offset,
                            const NumT time_offset_err2,
                            const NumT dist_source_sample,
                            const NumT dist_source_sample_err2,
                            const NumT dist_sample_detector,
                            const NumT dist_sample_detector_err2,
                            NumT & final_velocity,
                            NumT & final_velocity_err2,
                            void *temp=NULL)
  {
   // define some parameters that are static across the array calculation
    NumT a;
    NumT a2;
    NumT b;
    NumT c;
    NumT c2;
    NumT ld2;

    // some string parameters for dealing with warnings
    std::string retstr(Nessi::EMPTY_WARN);

    // calculate static paramters
    retstr +=__tof_to_final_velocity_dgs_static(initial_velocity,
                                                dist_source_sample,
                                                time_offset,
                                                dist_sample_detector,
                                                a, a2, b, c, c2, ld2);       

    // fill the results
    retstr +=__tof_to_final_velocity_dgs_dynamic(tof, 
                                                 tof_err2,
                                                 initial_velocity_err2,
                                                 time_offset_err2,
                                                 dist_source_sample_err2,
                                                 dist_sample_detector,
                                                 dist_sample_detector_err2,
                                                 final_velocity,
                                                 final_velocity_err2,
                                                 a, a2, b, c, c2, ld2);

    // send back all warnings
    return retstr;
  }

 /**
   * \ingroup tof_to_final_velocity_dgs
   *
   * This is a PRIVATE helper function for
   * tof_to_final_velocity_dgs that calculates parameters
   * invariant across the array calculation.
   *
   * \param initial_velocity (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param dist_source_sample (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param time_offset (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param dist_sample_detector (INPUT) same as parameter in
   * tof_to_final_velocity_dgs() 
   * \param a (OUTPUT) \f$=\frac{1}{initial\_velocity}\f$
   * \param a2 (OUTPUT) \f$=a^2\f$
   * \param b (OUTPUT) \f$=dist\_source\_sample\times a + time\_offset\f$
   * \param c (OUTPUT) \f$=\frac{dist\_source\_sample}{a2}\f$
   * \param c2 (OUTPUT) \f$=c^2\f$
   * \param ld2 (OUTPUT) \f$=dist\_sample\_detector\times dist\_sample\_detector\f$
   */
  template <typename NumT>
  std::string __tof_to_final_velocity_dgs_static(const NumT initial_velocity,
                                                 const NumT dist_source_sample,
                                                 const NumT time_offset,
                                                 const NumT dist_sample_detector,
                                                 NumT & a, 
                                                 NumT & a2, 
                                                 NumT & b, 
                                                 NumT & c, 
                                                 NumT & c2,
                                                 NumT & ld2)
                                              
  {
    a = static_cast<NumT>(1.0 / initial_velocity);
    a2 = a * a;
    b = (dist_source_sample * a) + time_offset;
    c = (dist_source_sample / a2);
    c2 = c*c;
    ld2 = dist_sample_detector * dist_sample_detector;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup tof_to_final_velocity_dgs
   *
   * This is a PRIVATE helper function for
   * tof_to_final_velocity_dgs that calculates the
   * initial_wavelength and its uncertainty.
   *
   * \param tof (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param tof_err2 (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param initial_velocity_err2 (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param time_offset_err2 (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param dist_source_sample_err2 (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param dist_sample_detector (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param dist_sample_detector_err2 (INPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param final_velocity (OUTPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param final_velocity_err2 (OUTPUT) same as parameter in
   * tof_to_final_velocity_dgs()
   * \param a (INPUT) same as parameter in
   * __tof_to_final_velocity_dgs_static()
   * \param a2 (INPUT) same as parameter in
   * __tof_to_final_velocity_dgs_static()
   * \param b (INPUT) same as parameter in
   * __tof_to_final_velocity_dgs_static()
   * \param c (INPUT) same as parameter in
   * __tof_to_final_velocity_dgs_static()
   * \param c2 (INPUT) same as parameter in
   * __tof_to_final_velocity_dgs_static()
   * \param ld2 (INPUT) same as parameter in
   * __tof_to_final_velocity_dgs_static()
   */
  template <typename NumT>
  std::string __tof_to_final_velocity_dgs_dynamic(const NumT tof,
                                                  const NumT tof_err2,
                                                  const NumT initial_velocity_err2,
                                                  const NumT time_offset_err2,
                                                  const NumT dist_source_sample_err2,
                                                  const NumT dist_sample_detector,
                                                  const NumT dist_sample_detector_err2,
                                                  NumT & final_velocity,
                                                  NumT & final_velocity_err2,
                                                  const NumT a,
                                                  const NumT a2,
                                                  const NumT b,
                                                  const NumT c,
                                                  const NumT c2,
                                                  const NumT ld2)
  {
    NumT tb = tof - b;
    NumT tb2 = tb * tb;
    NumT tb4 = tb2 * tb2;

    // the result
    final_velocity = static_cast<NumT>(dist_sample_detector / tb);

    // the uncertainty in the result
    final_velocity_err2 = (dist_sample_detector_err2 / tb2);
    final_velocity_err2 += (a2 * ld2 * dist_source_sample_err2 / tb4);
    final_velocity_err2 += (c2 * ld2 * initial_velocity_err2 / tb4);
    final_velocity_err2 += (ld2 * time_offset_err2 / tb4);
    final_velocity_err2 += (ld2 * tof_err2 / tb4);

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _TOF_TO_FINAL_VELOCITY_DGS_HPP
