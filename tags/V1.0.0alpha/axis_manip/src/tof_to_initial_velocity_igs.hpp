/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_initial_velocity_igs.hpp
 */
#ifndef _TOF_TO_INITIAL_VELOCITY_IGS_HPP
#define _TOF_TO_INITIAL_VELOCITY_IGS_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.28
  template <typename NumT>
  std::string
  tof_to_initial_velocity_igs(const Nessi::Vector<NumT> & tof,
			      const Nessi::Vector<NumT> & tof_err2,
			      const NumT final_velocity,
			      const NumT final_velocity_err2,
			      const NumT time_offset,
			      const NumT time_offset_err2,
			      const NumT dist_source_sample,
			      const NumT dist_source_sample_err2,
			      const NumT dist_sample_detector,
			      const NumT dist_sample_detector_err2,
			      Nessi::Vector<NumT> & initial_velocity,
			      Nessi::Vector<NumT> & initial_velocity_err2,
			      void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_initial_velocity_igs] not implemented");
  }

  // 3.28
  template <typename NumT>
  std::string
  tof_to_initial_velocity_igs(const NumT tof,
			      const NumT tof_err2,
			      const NumT final_velocity,
			      const NumT final_velocity_err2,
			      const NumT time_offset,
			      const NumT time_offset_err2,
			      const NumT dist_source_sample,
			      const NumT dist_source_sample_err2,
			      const NumT dist_sample_detector,
			      const NumT dist_sample_detector_err2,
			      NumT & initial_velocity,
			      NumT & initial_velocity_err2,
			      void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_initial_velocity_igs] not implemented");
  }
} // AxisManip

#endif // _TOF_TO_INITIAL_VELOCITY_IGS_HPP
