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
  
  /**
   * This is the integer declaration of the function defined in 3.34.
   *
   * \see tof_to_Q()
   */
  template std::string
  tof_to_Q<int>(std::vector<int> const & tof,
		std::vector<int> const & tof_err2,
		const int total_pathlength,
		const int total_pathlength_err2,
		const int azimuthal_angle,
		const int azimuthal_angle_err2,
		const int polar_angle,
		const int polar_angle_err2,
		std::vector<int> & Qx,
		std::vector<int> & Qx_err2,
		std::vector<int> & Qy,
		std::vector<int> & Qy_err2,
		std::vector<int> & Qz,
		std::vector<int> & Qz_err2,
		void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.34.
   *
   * \see tof_to_Q()
   */
  template std::string
  tof_to_Q<unsigned int>(std::vector<unsigned int> const & tof,
                         std::vector<unsigned int> const & tof_err2,
			 const unsigned int total_pathlength,
			 const unsigned int total_pathlength_err2,
			 const unsigned int azimuthal_angle,
			 const unsigned int azimuthal_angle_err2,
			 const unsigned int polar_angle,
			 const unsigned int polar_angle_err2,
                         std::vector<unsigned int> & Qx,
                         std::vector<unsigned int> & Qx_err2,
                         std::vector<unsigned int> & Qy,
                         std::vector<unsigned int> & Qy_err2,
                         std::vector<unsigned int> & Qz,
                         std::vector<unsigned int> & Qz_err2,
                         void *temp);
  
} // AxisManip
