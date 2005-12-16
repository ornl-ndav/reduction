/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_Q.cpp
 */
#include "tof_to_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.34.
   *
   * \see tof_to_Q()
   */
  template std::string
  tof_to_Q<float>(std::vector<float> const & tof,
		  std::vector<float> const & tof_err2,
		  const float total_pathlength,
		  const float total_pathlength_err2,
		  const float azimuthal_angle,
		  const float azimuthal_angle_err2,
		  const float polar_angle,
		  const float polar_angle_err2,
		  std::vector<float> & Qx,
		  std::vector<float> & Qx_err2,
		  std::vector<float> & Qy,
		  std::vector<float> & Qy_err2,
		  std::vector<float> & Qz,
		  std::vector<float> & Qz_err2,
		  void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.34.
   *
   * \see tof_to_Q()
   */
  template std::string
  tof_to_Q<double>(std::vector<double> const & tof,
		   std::vector<double> const & tof_err2,
		   const double total_pathlength,
		   const double total_pathlength_err2,
		   const double azimuthal_angle,
		   const double azimuthal_angle_err2,
		   const double polar_angle,
		   const double polar_angle_err2,
		   std::vector<double> & Qx,
		   std::vector<double> & Qx_err2,
		   std::vector<double> & Qy,
		   std::vector<double> & Qy_err2,
		   std::vector<double> & Qz,
		   std::vector<double> & Qz_err2,
		   void *temp);
} // AxisManip
