/**
 * $Id$
 *
 * \file axis_manip/src/initial_velocity_dgs.hpp
 */
#ifndef _INITIAL_VELOCITY_DGS_HPP
#define _INITIAL_VELOCITY_DGS_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.19
  template <typename NumT>
  std::string
  initial_velocity_dgs(const NumT dist_upsteam_mon,
                       const NumT dist_upstream_mon_err2,
                       const NumT time_upstream_mon,
                       const NumT time_upstream_mon_err2,
                       const NumT dist_downstream_mon,
                       const NumT dist_downstream_mon_err2,
                       const NumT time_downstream_mon,
                       const NumT time_downstream_mon_err2,
                       NumT & initial_velocity,
                       NumT & initial_velocity_err2,
                       void *temp=NULL)
  {
    throw std::runtime_error("Function [initial_velocity_dgs] not implemented");
  }
} // AxisManip

#endif // _INITIAL_VELOCITY_DGS_HPP
