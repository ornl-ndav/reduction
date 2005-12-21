/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_initial_wavelength_igs.hpp
 */
#include "constants.hpp"
#include "conversions.hpp"
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.29
  template <typename NumT>
  std::string
  tof_to_initial_wavelength_igs(std::vector<NumT> const & tof,
				std::vector<NumT> const & tof_err2,
				const NumT final_wavelength,
				const NumT final_wavelength_err2,
				const NumT time_offset,
				const NumT time_offset_err2,
				const NumT dist_source_sample,
				const NumT dist_source_sample_err2,
				const NumT dist_sample_detector,
				const NumT dist_sample_detector_err2,
				std::vector<NumT> & initial_wavelength,
				std::vector<NumT> & initial_wavelength_err2,
				void *temp=NULL)
  {
    std::string retstr("");

    NumT a = static_cast<NumT>(PhysConst::H_OVER_MNEUT / dist_source_sample);
    NumT a2 = a * a;

    NumT b = (dist_sample_detector * final_wavelength) / dist_source_sample;
    b += (a * time_offset);

    NumT c = final_wavelength / dist_source_sample;
    NumT c2 = c * c;
    
    NumT d = dist_sample_detector / dist_source_sample;
    NumT d2 = d * d;

    NumT ls2 = dist_source_sample * dist_source_sample;

    size_t sz = tof.size();
    for (size_t i = 0; i < sz; ++i)
      {
	initial_wavelength[i] = a * tof[i] - b;
	initial_wavelength_err2[i] = a2 * (tof_err2[i] + time_offset_err2);
	initial_wavelength_err2[i] += c2 * dist_sample_detector_err2;
	initial_wavelength_err2[i] += d2 * final_wavelength_err2;
	initial_wavelength_err2[i] += initial_wavelength[i] * 
	  initial_wavelength[i] * dist_source_sample_err2 / ls2;
      }

    return retstr;
  }
} // AxisManip
