/**
 * $Id$
 *
 * \file axis_manip/src/initial_velocity_dgs.cpp
 */
#include "initial_velocity_dgs.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.19.
   *
   * \see initial_velocity_dgs()
   */
  template std::string
  initial_velocity_dgs<float>(const float dist_upsteam_mon,
			      const float dist_upstream_mon_err2,
			      const float time_upstream_mon,
			      const float time_upstream_mon_err2,
			      const float dist_downstream_mon,
			      const float dist_downstream_mon_err2,
			      const float time_downstream_mon,
			      const float time_downstream_mon_err2,
			      float & initial_velocity,
			      float & initial_velocity_err2,
			      void *temp=NULL);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.19.
   *
   * \see initial_velocity_dgs()
   */
  template std::string
  initial_velocity_dgs<double>(const double dist_upsteam_mon,
			       const double dist_upstream_mon_err2,
			       const double time_upstream_mon,
			       const double time_upstream_mon_err2,
			       const double dist_downstream_mon,
			       const double dist_downstream_mon_err2,
			       const double time_downstream_mon,
			       const double time_downstream_mon_err2,
			       double & initial_velocity,
			       double & initial_velocity_err2,
			       void *temp=NULL);
} // AxisManip
