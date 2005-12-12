/**
 * $Id$
 *
 * \file axis_manip/src/time_offset_dgs.cpp
 */
#include "conversions.hpp"
#include <string>
#include <stdexcept>

namespace AxisManip
{
  // 3.26
  template <typename NumT>
  std::string
  time_offset_dgs(const NumT dist_downstream_monitor,
		  const NumT time_downstream_monitor,
		  const NumT initial_velocity,
		  NumT & time_offset,
		  void *temp=NULL)
  {
    throw std::runtime_error("Function [time_offset_dgs] not implemented");
  }
  
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.26.
   *
   * \see time_offset_dgs()
   */
  template std::string
  time_offset_dgs<float>(const float dist_downstream_monitor,
			 const float time_downstream_monitor,
			 const float initial_velocity,
			 float & time_offset,
			 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.26.
   *
   * \see time_offset_dgs()
   */
  template std::string
  time_offset_dgs<double>(const double dist_downstream_monitor,
			  const double time_downstream_monitor,
			  const double initial_velocity,
			  double & time_offset,
			  void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.26.
   *
   * \see time_offset_dgs()
   */
  template std::string
  time_offset_dgs<int>(const int dist_downstream_monitor,
		       const int time_downstream_monitor,
		       int initial_velocity,
		       int & time_offset,
		       void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.26.
   *
   * \see time_offset_dgs()
   */
  template std::string
  time_offset_dgs<unsigned int>(const unsigned int dist_downstream_monitor,
                                const unsigned int time_downstream_monitor,
                                const unsigned int initial_velocity,
                                unsigned int & time_offset,
                                void *temp);
  
} // AxisManip
