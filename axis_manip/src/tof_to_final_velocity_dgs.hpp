/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_final_velocity_dgs.hpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.27
  template <typename NumT>
  std::string
  tof_to_final_velocity_dgs(std::vector<NumT> const & tof,
			    std::vector<NumT> const & tof_err2,
			    const NumT initial_velocity,
			    const NumT initial_velocity_err2,
			    const NumT time_offset,
			    const NumT time_offset_err2,
			    const NumT dist_source_sample,
			    const NumT dist_source_sample_err2,
			    const NumT dist_sample_detector,
			    const NumT dist_sample_detector_err2,
			    std::vector<NumT> & final_velocity,
			    std::vector<NumT> & final_velocity_err2,
			    void *temp=NULL)
  {
    throw std::runtime_error("Function [time_to_final_velocity_dgs] not implemented");
  }
} // AxisManip
