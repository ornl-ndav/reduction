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
   * \ingroup tof_to_Q
   */
  template std::string
  tof_to_Q<float>(const Nessi::Vector<float> & tof,
		  const Nessi::Vector<float> & tof_err2,
		  const float total_pathlength,
		  const float total_pathlength_err2,
		  const float azimuthal_angle,
		  const float azimuthal_angle_err2,
		  const float polar_angle,
		  const float polar_angle_err2,
		  Nessi::Vector<float> & Qx,
		  Nessi::Vector<float> & Qx_err2,
		  Nessi::Vector<float> & Qy,
		  Nessi::Vector<float> & Qy_err2,
		  Nessi::Vector<float> & Qz,
		  Nessi::Vector<float> & Qz_err2,
		  void *temp);
  /**
   * This is the float declaration of the function defined in 3.34.
   *
   * \ingroup tof_to_Q
   */
  template std::string
  tof_to_Q<float>(const float tof,
		  const float tof_err2,
		  const float total_pathlength,
		  const float total_pathlength_err2,
		  const float azimuthal_angle,
		  const float azimuthal_angle_err2,
		  const float polar_angle,
		  const float polar_angle_err2,
		  float & Qx,
		  float & Qx_err2,
		  float & Qy,
		  float & Qy_err2,
		  float & Qz,
		  float & Qz_err2,
		  void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.34.
   *
   * \ingroup tof_to_Q
   */
  template std::string
  tof_to_Q<double>(const Nessi::Vector<double> & tof,
		   const Nessi::Vector<double> & tof_err2,
		   const double total_pathlength,
		   const double total_pathlength_err2,
		   const double azimuthal_angle,
		   const double azimuthal_angle_err2,
		   const double polar_angle,
		   const double polar_angle_err2,
		   Nessi::Vector<double> & Qx,
		   Nessi::Vector<double> & Qx_err2,
		   Nessi::Vector<double> & Qy,
		   Nessi::Vector<double> & Qy_err2,
		   Nessi::Vector<double> & Qz,
		   Nessi::Vector<double> & Qz_err2,
		   void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.34.
   *
   * \ingroup tof_to_Q
   */
  template std::string
  tof_to_Q<double>(const double tof,
		   const double tof_err2,
		   const double total_pathlength,
		   const double total_pathlength_err2,
		   const double azimuthal_angle,
		   const double azimuthal_angle_err2,
		   const double polar_angle,
		   const double polar_angle_err2,
		   double & Qx,
		   double & Qx_err2,
		   double & Qy,
		   double & Qy_err2,
		   double & Qz,
		   double & Qz_err2,
		   void *temp);
} // AxisManip
