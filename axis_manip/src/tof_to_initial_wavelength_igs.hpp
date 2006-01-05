/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_initial_wavelength_igs.hpp
 */
#ifndef _TOF_TO_INITIAL_WAVELENGTH_IGS_HPP
#define _TOF_TO_INITIAL_WAVELENGTH_IGS_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
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
    // SNS-FIXME: need to check that input and output vectors are of
    // the same length

    // define some parameters that are static across the array calculation
    NumT a;
    NumT a2;
    NumT b;
    NumT c2;
    NumT d2;
    NumT ls2;

    // some string parameters for dealing with warnings
    std::string retstr("");
    std::string warn;

    // calculate static paramters
    warn=__tof_to_initial_wavelength_igs_static(final_wavelength, time_offset,
                                                dist_source_sample,
                                                dist_sample_detector, a, a2,
                                                b, c2, d2, ls2);
    if(!(warn.empty()))
      retstr+=warn;

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
                                                    a, a2, b, c2, d2, ls2);
        if(!(warn.empty()))
          retstr+=warn;
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
    NumT a2;
    NumT b;
    NumT c2;
    NumT d2;
    NumT ls2;

    // some string parameters for dealing with warnings
    std::string retstr("");
    std::string warn;

    // calculate static paramters
    warn=__tof_to_initial_wavelength_igs_static(final_wavelength, time_offset,
                                                dist_source_sample,
                                                dist_sample_detector, a, a2,
                                                b, c2, d2, ls2);
    if(!(warn.empty()))
      retstr+=warn;

    // fill the results
    warn=__tof_to_initial_wavelength_igs_dynamic(tof, tof_err2,
                                                 final_wavelength_err2,
                                                 time_offset_err2,
                                                 dist_source_sample_err2,
                                                 dist_sample_detector_err2,
                                                 initial_wavelength,
                                                 initial_wavelength_err2,
                                                 a, a2, b, c2, d2, ls2);

    if(!(warn.empty()))
      retstr+=warn;

    // send back all warnings
    return retstr;
  }

  /**
   * This is a PRIVATE helper function for
   * tof_to_initial_wavelength_igs that calculates parameters
   * invariant across the array calculation.
   */
  template <typename NumT>
  std::string __tof_to_initial_wavelength_igs_static(
				const NumT final_wavelength,
				const NumT time_offset,
				const NumT dist_source_sample,
				const NumT dist_sample_detector,
                                NumT & a,
                                NumT & a2,
                                NumT & b,
                                NumT & c2,
                                NumT & d2,
                                NumT & ls2)
  {
    a = static_cast<NumT>(PhysConst::H_OVER_MNEUT) / dist_source_sample;
    a2 = a * a;

    b = (dist_sample_detector * final_wavelength) / dist_source_sample;
    b += (a * time_offset);
    c2 = final_wavelength / dist_source_sample;
    c2 = c2 * c2;
    
    d2 = dist_sample_detector / dist_source_sample;
    d2 = d2 * d2;

    ls2 = dist_source_sample * dist_source_sample;

    return std::string("");
  }

  /**
   * This is a PRIVATE helper function for
   * tof_to_initial_wavelength_igs that calculates the
   * initial_wavelength and its uncertainty.
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
                                          const NumT a2,
                                          const NumT b,
                                          const NumT c2,
                                          const NumT d2,
                                          const NumT ls2)
  {
    // the result
    initial_wavelength = a * tof - b;

    // the uncertainty in the result
    initial_wavelength_err2 = a2 * (tof_err2 + time_offset_err2);
    initial_wavelength_err2 += c2 * dist_sample_detector_err2;
    initial_wavelength_err2 += d2 * final_wavelength_err2;
    initial_wavelength_err2 += initial_wavelength * 
      initial_wavelength * dist_source_sample_err2 / ls2;

    return std::string("");
  }
} // AxisManip
#endif
