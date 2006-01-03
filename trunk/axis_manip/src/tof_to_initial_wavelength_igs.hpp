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
  tof_to_initial_wavelength_igs(Nessi::Vector<NumT> const & tof,
				Nessi::Vector<NumT> const & tof_err2,
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
    // VARIABLES NEED BETTER NAMES: a, a2, b, c, c2, d, d2, ls2
    NumT a = static_cast<NumT>(PhysConst::H_OVER_MNEUT / dist_source_sample);
    NumT a2 = a * a;

    NumT b = (dist_sample_detector * final_wavelength) / dist_source_sample;
    b += (a * time_offset);

    NumT c = final_wavelength / dist_source_sample;
    NumT c2 = c * c;
    
    NumT d = dist_sample_detector / dist_source_sample;
    NumT d2 = d * d;

    NumT ls2 = dist_source_sample * dist_source_sample;

    size_t size_tof = tof.size();
    for (size_t i = 0 ; i < size_tof ; ++i)
      {
	initial_wavelength[i] = a * tof[i] - b;
	initial_wavelength_err2[i] = a2 * (tof_err2[i] + time_offset_err2);
	initial_wavelength_err2[i] += c2 * dist_sample_detector_err2;
	initial_wavelength_err2[i] += d2 * final_wavelength_err2;
	initial_wavelength_err2[i] += initial_wavelength[i] * 
	  initial_wavelength[i] * dist_source_sample_err2 / ls2;
      }

    std::string retstr("");
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
    throw std::runtime_error("Function [tof_to_initial_wavelength_igs] not implemented");
  }
} // AxisManip
#endif
