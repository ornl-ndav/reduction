/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_scalar_Q.cpp
 */
#include "tof_to_scalar_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.17.
   *
   * \see tof_to_scalar_Q()
   */
  template std::string
  tof_to_scalar_Q<float>(Nessi::Vector<float> const & tof,
			 Nessi::Vector<float> const & tof_err2,
			 const float pathlength,
			 const float pathlength_err2,
                         const float scatt_angle,
			 const float scatt_angle_err2,
			 Nessi::Vector<float> & Q,
			 Nessi::Vector<float> & Q_err2,
			 void *temp);
  
  /**
   * This is the float declaration of the function defined in 3.17.
   *
   * \see tof_to_scalar_Q()
   */
  template std::string
  tof_to_scalar_Q<float>(const float tof,
			 const float tof_err2,
			 const float pathlength,
			 const float pathlength_err2,
                         const float scatt_angle,
			 const float scatt_angle_err2,
			 float & Q,
			 float & Q_err2,
			 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.17.
   *
   * \see tof_to_scalar_Q()
   */
  template std::string
  tof_to_scalar_Q<double>(Nessi::Vector<double> const & tof,
			  Nessi::Vector<double> const & tof_err2,
			  const double pathlength,
			  const double pathlength_err2,
                          const double scatt_angle,
			  const double scatt_angle_err2,
			  Nessi::Vector<double> & Q,
			  Nessi::Vector<double> & Q_err2,
			  void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.17.
   *
   * \see tof_to_scalar_Q()
   */
  template std::string
  tof_to_scalar_Q<double>(const double tof,
			  const double tof_err2,
			  const double pathlength,
			  const double pathlength_err2,
                          const double scatt_angle,
			  const double scatt_angle_err2,
			  double & Q,
			  double & Q_err2,
			  void *temp);
} // AxisManip
