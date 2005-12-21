/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_final_velocity_dgs.cpp
 */
#include "tof_to_final_velocity_dgs.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.27.
   *
   * \see tof_to_final_velocity_dgs()
   */
  template std::string
  tof_to_final_velocity_dgs<float>(Nessi::Vector<float> const & tof,
				   Nessi::Vector<float> const & tof_err2,
				   const float initial_velocity,
				   const float initial_velocity_err2,
				   const float time_offset,
				   const float time_offset_err2,
				   const float dist_source_sample,
				   const float dist_source_sample_err2,
				   const float dist_sample_detector,
				   const float dist_sample_detector_err2,
				   Nessi::Vector<float> & final_velocity,
				   Nessi::Vector<float> & final_velocity_err2,
				   void *temp=NULL);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.27.
   *
   * \see tof_to_final_velocity_dgs()
   */
  template std::string
  tof_to_final_velocity_dgs<double>(Nessi::Vector<double> const & tof,
				    Nessi::Vector<double> const & tof_err2,
				    const double initial_velocity,
				    const double initial_velocity_err2,
				    const double time_offset,
				    const double time_offset_err2,
				    const double dist_source_sample,
				    const double dist_source_sample_err2,
				    const double dist_sample_detector,
				    const double dist_sample_detector_err2,
				    Nessi::Vector<double> & final_velocity,
				    Nessi::Vector<double> & final_velocity_err2,
				    void *temp=NULL);
} // AxisManip
