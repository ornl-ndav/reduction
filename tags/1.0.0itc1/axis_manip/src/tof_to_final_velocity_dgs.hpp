/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_final_velocity_dgs.hpp
 */
#ifndef _TOF_TO_FINAL_VELOCITY_DGS_HPP
#define _TOF_TO_FINAL_VELOCITY_DGS_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
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
    throw std::runtime_error("Function [time_to_final_velocity_dgs] not implemented");
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
    throw std::runtime_error("Function [time_to_final_velocity_dgs] not implemented");
  }
} // AxisManip

#endif // _TOF_TO_FINAL_VELOCITY_DGS_HPP
