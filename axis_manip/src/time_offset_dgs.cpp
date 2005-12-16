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
   * \see time_offset_dgs()
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
   * \see time_offset_dgs()
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
  
  /**
   * This is the integer declaration of the function defined in 3.26.
   *
   * \see time_offset_dgs()
   */
  template std::string
  time_offset_dgs<int>(const int dist_downstream_monitor,
		       const int dist_downstream_monitor_err2,
		       const int time_downstream_monitor,
		       const int time_downstream_monitor_err2,
		       const int initial_velocity,
		       const int initial_velocity_err2,
		       int & time_offset,
		       int & time_offset_err2,
		       void *temp=NULL);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.26.
   *
   * \see time_offset_dgs()
   */
  template std::string
  time_offset_dgs<unsigned int>(const unsigned int dist_downstream_monitor,
				const unsigned int dist_downstream_monitor_err2,
				const unsigned int time_downstream_monitor,
				const unsigned int time_downstream_monitor_err2,
				const unsigned int initial_velocity,
				const unsigned int initial_velocity_err2,
				unsigned int & time_offset,
				unsigned int & time_offset_err2,
				void *temp=NULL);
  
} // AxisManip
