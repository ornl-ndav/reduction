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
  tof_to_initial_wavelength_igs<float>(
                                Nessi::Vector<float> const & tof,
                                Nessi::Vector<float> const & tof_err2,
                                const float final_wavelength,
                                const float final_wavelength_err2,
                                const float time_offset,
                                const float time_offset_err2,
                                const float dist_source_sample,
                                const float dist_source_sample_err2,
                                const float dist_sample_detector,
                                const float dist_sample_detector_err2,
				Nessi::Vector<float> & initial_wavelength,
				Nessi::Vector<float> & initial_wavelength_err2,
                                void *temp=NULL);
  
  /**
   * This is the float declaration of the function defined in 3.29.
   *
   * \see tof_to_initial_wavelength_igs()
   */
  template std::string
  tof_to_initial_wavelength_igs<float>(
                                const float tof,
                                const float tof_err2,
                                const float final_wavelength,
                                const float final_wavelength_err2,
                                const float time_offset,
                                const float time_offset_err2,
                                const float dist_source_sample,
                                const float dist_source_sample_err2,
                                const float dist_sample_detector,
                                const float dist_sample_detector_err2,
				float & initial_wavelength,
				float & initial_wavelength_err2,
                                void *temp=NULL);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.29.
   *
   * \see tof_to_initial_wavelength_igs()
   */
  template std::string
  tof_to_initial_wavelength_igs<double>(
                               Nessi::Vector<double> const & tof,
                               Nessi::Vector<double> const & tof_err2,
                               const double final_wavelength,
                               const double final_wavelength_err2,
                               const double time_offset,
                               const double time_offset_err2,
                               const double dist_source_sample,
                               const double dist_source_sample_err2,
                               const double dist_sample_detector,
                               const double dist_sample_detector_err2,
                               Nessi::Vector<double> & initial_wavelength,
                               Nessi::Vector<double> & initial_wavelength_err2,
                               void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.29.
   *
   * \see tof_to_initial_wavelength_igs()
   */
  template std::string
  tof_to_initial_wavelength_igs<double>(
                               const double tof,
                               const double tof_err2,
                               const double final_wavelength,
                               const double final_wavelength_err2,
                               const double time_offset,
                               const double time_offset_err2,
                               const double dist_source_sample,
                               const double dist_source_sample_err2,
                               const double dist_sample_detector,
                               const double dist_sample_detector_err2,
                               double & initial_wavelength,
                               double & initial_wavelength_err2,
                               void *temp=NULL);
} // AxisManip
