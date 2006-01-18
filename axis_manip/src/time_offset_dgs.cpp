/**
 * $Id$
 *
 * \file axis_manip/src/time_offset_dgs.cpp
 */
#include "time_offset_dgs.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.26.
   *
   * \ingroup time_offset_dgs
   */
  template std::string
  time_offset_dgs<float>(const float dist_downstream_monitor,
                         const float dist_downstream_monitor_err2,
                         const float time_downstream_monitor,
                         const float time_downstream_monitor_err2,
                         const float initial_velocity,
                         const float initial_velocity_err2,
                         float & time_offset,
                         float & time_offset_err2,
                         void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.26.
   *
   * \ingroup time_offset_dgs
   */
  template std::string
  time_offset_dgs<double>(const double dist_downstream_monitor,
                          const double dist_downstream_monitor_err2,
                          const double time_downstream_monitor,
                          const double time_downstream_monitor_err2,
                          const double initial_velocity,
                          const double initial_velocity_err2,
                          double & time_offset,
                          double & time_offset_err2,
                          void *temp=NULL);
} // AxisManip
