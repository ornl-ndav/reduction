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
 * \file axis_manip/src/tof_to_initial_wavelength_igs.hpp
 */
#ifndef _TOF_TO_INITIAL_WAVELENGTH_IGS_HPP
#define _TOF_TO_INITIAL_WAVELENGTH_IGS_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the tof_to_initial_wavelength_igs function name
  const std::string ttiwi_func_str = "AxisManip::tof_to_initial_wavelength_igs";

  // 3.29
  template <typename NumT>
  std::string
  tof_to_initial_wavelength_igs(const Nessi::Vector<NumT> & tof,
                                const Nessi::Vector<NumT> & tof_err2,
                                const NumT final_wavelength,
                                const NumT final_wavelength_err2,
                                const NumT time_offset,
                                const NumT time_offset_err2,
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
        throw std::invalid_argument(ttiwi_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(tof_err2, initial_wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttiwi_func_str+" (v,v): err2 "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);    // the warning string
    std::string warn;                         // the temporary warning string

    // alloacate local variables
    NumT a;
    NumT b;
    NumT c;
    NumT ls2;
    NumT inv_ls2;
    NumT ld2;
    NumT wf2;

    // calculate static paramters
    warn=__tof_to_initial_wavelength_igs_static(final_wavelength, time_offset,
                                                dist_source_sample,
                                                dist_sample_detector, a,
                                                b, c, ls2, inv_ls2, ld2, wf2);
    if(!(warn.empty()))
      {
        retstr+=warn;
      }

    // fill the results array
    size_t size_tof = tof.size();
    for (size_t i = 0 ; i < size_tof ; ++i)
      {
        warn=__tof_to_initial_wavelength_igs_dynamic(
                                                    tof[i], tof_err2[i],
                                                    final_wavelength_err2,
                                                    time_offset_err2,
                                                    dist_source_sample_err2,
                                                    dist_sample_detector_err2,
                                                    initial_wavelength[i],
                                                    initial_wavelength_err2[i],
                                                    a, b, c, ls2, inv_ls2,
                                                    ld2, wf2);
        if(!(warn.empty()))
          {
            retstr+=warn;
          }
      }

    // send back all warnings
    return retstr;
  }

  // 3.29
  template <typename NumT>
  std::string
  tof_to_initial_wavelength_igs(const NumT tof,
                                const NumT tof_err2,
                                const NumT final_wavelength,
                                const NumT final_wavelength_err2,
                                const NumT time_offset,
                                const NumT time_offset_err2,
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
    NumT b;
    NumT c;
    NumT ls2;
    NumT inv_ls2;
    NumT ld2;
    NumT wf2;

    // some string parameters for dealing with warnings
    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    // calculate static paramters
    warn=__tof_to_initial_wavelength_igs_static(final_wavelength, time_offset,
                                                dist_source_sample,
                                                dist_sample_detector, a,
                                                b, c, ls2, inv_ls2, ld2, wf2);
    if(!(warn.empty()))
      {
        retstr+=warn;
      }

    // fill the results
    warn=__tof_to_initial_wavelength_igs_dynamic(tof, tof_err2,
                                                 final_wavelength_err2,
                                                 time_offset_err2,
                                                 dist_source_sample_err2,
                                                 dist_sample_detector_err2,
                                                 initial_wavelength,
                                                 initial_wavelength_err2,
                                                 a, b, c, ls2, inv_ls2, ld2,
                                                 wf2);

    if(!(warn.empty()))
      {
        retstr+=warn;
      }

    // send back all warnings
    return retstr;
  }

  /**
   * \ingroup tof_to_initial_wavelength_igs
   *
   * This is a PRIVATE helper function for
   * tof_to_initial_wavelength_igs that calculates parameters
   * invariant across the array calculation.
   *
   * \param final_wavelength (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param time_offset (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param dist_source_sample (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param dist_sample_detector (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param a (OUTPUT) \f$=h/(m_n \times dist\_source\_sample)\f$
   * \param b (OUTPUT) \f$=\frac{dist\_sample\_detector\times final\_wavelength}{dist\_source\_sample}+a\times time\_offset\f$
   * \param c (OUTPUT) \f$=\left(\frac{h}{m_n}\right)^2\f$
   * \param ls2 (OUTPUT) \f$=dist\_source\_sample^2\f$
   * \param inv_ls2 (OUTPUT) \f$=dist\_source\_sample^{-1}\f$
   * \param ld2 (OUTPUT) \f$=dist\_sample\_detector^2\f$
   * \param wf2 (OUTPUT) \f$=final\_wavelength^2\f$
   */
  template <typename NumT>
  std::string __tof_to_initial_wavelength_igs_static(
                                               const NumT final_wavelength,
                                               const NumT time_offset,
                                               const NumT dist_source_sample,
                                               const NumT dist_sample_detector,
                                               NumT & a,
                                               NumT & b,
                                               NumT & c,
                                               NumT & ls2,
                                               NumT & inv_ls2,
                                               NumT & ld2,
                                               NumT & wf2)
  {
    a = static_cast<NumT>(PhysConst::H_OVER_MNEUT) / dist_source_sample;

    b = (dist_sample_detector * final_wavelength) / dist_source_sample;
    b += (a * time_offset);

    c = static_cast<NumT>(PhysConst::H_OVER_MNEUT);
    c = c*c;

    ls2 = dist_source_sample * dist_source_sample;
    inv_ls2=static_cast<NumT>(1.)/ls2;

    ld2 = dist_sample_detector*dist_sample_detector;

    wf2 = final_wavelength*final_wavelength;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup tof_to_initial_wavelength_igs
   *
   * This is a PRIVATE helper function for
   * tof_to_initial_wavelength_igs that calculates the
   * initial_wavelength and its uncertainty.
   *
   * \param tof (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param tof_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param final_wavelength_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param time_offset_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param dist_source_sample_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param dist_sample_detector_err2 (INPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param initial_wavelength (OUTPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param initial_wavelength_err2 (OUTPUT) same as parameter in
   * tof_to_initial_wavelength_igs()
   * \param a (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_static()
   * \param b (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_static()
   * \param c (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_static()
   * \param ls2 (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_static()
   * \param inv_ls2 (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_static()
   * \param ld2 (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_static()
   * \param wf2 (INPUT) same as parameter in
   * __tof_to_initial_wavelength_igs_static()
   */
  template <typename NumT>
  std::string __tof_to_initial_wavelength_igs_dynamic(
                                          const NumT tof,
                                          const NumT tof_err2,
                                          const NumT final_wavelength_err2,
                                          const NumT time_offset_err2,
                                          const NumT dist_source_sample_err2,
                                          const NumT dist_sample_detector_err2,
                                          NumT & initial_wavelength,
                                          NumT & initial_wavelength_err2,
                                          const NumT a,
                                          const NumT b,
                                          const NumT c,
                                          const NumT ls2,
                                          const NumT inv_ls2,
                                          const NumT ld2,
                                          const NumT wf2)
  {
    // the result
    initial_wavelength = a * tof - b;

    // the uncertainty in the result
    initial_wavelength_err2 = initial_wavelength*initial_wavelength
      *dist_source_sample_err2;
    initial_wavelength_err2 += ld2*final_wavelength_err2;
    initial_wavelength_err2 += c*(tof_err2+time_offset_err2);
    initial_wavelength_err2 *= inv_ls2;

      /*
    initial_wavelength_err2 = a2 * (tof_err2 + time_offset_err2);
    initial_wavelength_err2 += c2 * dist_sample_detector_err2;
    initial_wavelength_err2 += d2 * final_wavelength_err2;
    initial_wavelength_err2 += initial_wavelength *
      initial_wavelength * dist_source_sample_err2 / ls2;
      */

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _TOF_TO_INITIAL_WAVELENGTH_IGS_HPP
