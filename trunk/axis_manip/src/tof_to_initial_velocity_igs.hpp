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
  tof_to_initial_velocity_igs(Nessi::Vector<NumT> const & tof,
			      Nessi::Vector<NumT> const & tof_err2,
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
} // AxisManip
#endif
