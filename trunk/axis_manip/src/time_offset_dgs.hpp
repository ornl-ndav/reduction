/**
 * $Id$
 *
 * \file axis_manip/src/time_offset_dgs.hpp
 */
#ifndef _TIME_OFFSET_DGS_HPP
#define _TIME_OFFSET_DGS_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.26
  template <typename NumT>
  std::string
  time_offset_dgs(const NumT dist_downstream_monitor,
                  const NumT dist_downstream_monitor_err2,
                  const NumT time_downstream_monitor,
                  const NumT time_downstream_monitor_err2,
                  const NumT initial_velocity,
                  const NumT initial_velocity_err2,
                  NumT & time_offset,
                  NumT & time_offset_err2,
                  void *temp=NULL)
  {
    throw std::runtime_error("Function [time_offset_dgs] not implemented");
  }
} // AxisManip

#endif // _TIME_OFFSET_DGS_HPP
