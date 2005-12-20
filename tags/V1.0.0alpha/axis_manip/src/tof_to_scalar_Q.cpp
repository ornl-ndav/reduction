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
  tof_to_scalar_Q<float>(std::vector<float> const & tof,
			 std::vector<float> const & tof_err2,
			 const float pathlength,
			 const float pathlength_err2,
                         const float scatt_angle,
			 const float scatt_angle_err2,
			 std::vector<float> & Q,
			 std::vector<float> & Q_err2,
			 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.17.
   *
   * \see tof_to_scalar_Q()
   */
  template std::string
  tof_to_scalar_Q<double>(std::vector<double> const & tof,
			  std::vector<double> const & tof_err2,
			  const double pathlength,
			  const double pathlength_err2,
                          const double scatt_angle,
			  const double scatt_angle_err2,
			  std::vector<double> & Q,
			  std::vector<double> & Q_err2,
			  void *temp);
} // AxisManip
