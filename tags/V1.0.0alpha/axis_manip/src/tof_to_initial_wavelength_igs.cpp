/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_initial_wavelength_igs.cpp
 */
#include "tof_to_initial_wavelength_igs.hpp"
#include "conversions.hpp"
#include <string>
#include <vector>

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.29.
   *
   * \see tof_to_initial_wavelength_igs()
   */
  template std::string
  tof_to_initial_wavelength_igs<float>(std::vector<float> const & tof,
				       std::vector<float> const & tof_err2,
				       const float final_wavelength,
				       const float final_wavelength_err2,
				       const float time_offset,
				       const float time_offset_err2,
				       const float dist_source_sample,
				       const float dist_source_sample_err2,
				       const float dist_sample_detector,
				       const float dist_sample_detector_err2,
				       std::vector<float> & initial_wavelength,
				       std::vector<float> & initial_wavelength_err2,
				       void *temp=NULL);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.29.
   *
   * \see tof_to_initial_wavelength_igs()
   */
  template std::string
  tof_to_initial_wavelength_igs<double>(std::vector<double> const & tof,
					std::vector<double> const & tof_err2,
					const double final_wavelength,
					const double final_wavelength_err2,
					const double time_offset,
					const double time_offset_err2,
					const double dist_source_sample,
					const double dist_source_sample_err2,
					const double dist_sample_detector,
					const double dist_sample_detector_err2,
					std::vector<double> & initial_wavelength,
					std::vector<double> & initial_wavelength_err2,
					void *temp=NULL);
} // AxisManip
