/**
 * $Id$
 *
 * \file axis_manip/src/initial_velocity_dgs.cpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>

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
  
  /**
   * This is the integer declaration of the function defined in 3.19.
   *
   * \see initial_velocity_dgs()
   */
  template std::string
  initial_velocity_dgs<int>(const int dist_upsteam_mon,
			    const int dist_upstream_mon_err2,
			    const int time_upstream_mon,
			    const int time_upstream_mon_err2,
			    const int dist_downstream_mon,
			    const int dist_downstream_mon_err2,
			    const int time_downstream_mon,
			    const int time_downstream_mon_err2,
			    int & initial_velocity,
			    int & initial_velocity_err2,
			    void *temp=NULL);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.19.
   *
   * \see initial_velocity_dgs()
   */
  template std::string
  initial_velocity_dgs<unsigned int>(const unsigned int dist_upsteam_mon,
				     const unsigned int dist_upstream_mon_err2,
				     const unsigned int time_upstream_mon,
				     const unsigned int time_upstream_mon_err2,
				     const unsigned int dist_downstream_mon,
				     const unsigned int dist_downstream_mon_err2,
				     const unsigned int time_downstream_mon,
				     const unsigned int time_downstream_mon_err2,
				     unsigned int & initial_velocity,
				     unsigned int & initial_velocity_err2,
				     void *temp=NULL);
  
} // AxisManip
