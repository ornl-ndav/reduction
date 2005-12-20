/**
 * $Id$
 *
 * \file axis_manip/src/d_spacing_to_tof_focused_det.cpp
 */
#include "d_spacing_to_tof_focused_det.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.39.
   *
   * \see d_spacing_to_tof_focused_det()
   */
  template std::string
  d_spacing_to_tof_focused_det<float>(std::vector<float> const & d_spacing,
				      std::vector<float> const & d_spacing_err2,
				      const float pathlength_focused,
				      const float pathlength_focused_err2,
				      const float polar_angle_focused,
				      const float polar_angle_focused_err2,
				      std::vector<float> & tof,
				      std::vector<float> & tof_err2,
				      void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.39.
   *
   * \see d_spacing_to_tof_focused_det()
   */
  template std::string
  d_spacing_to_tof_focused_det<double>(std::vector<double> const & d_spacing,
				       std::vector<double> const & d_spacing_err2,
				       const double pathlength_focused,
				       const double pathlength_focused_err2,
				       const double polar_angle_focused,
				       const double polar_angle_focused_err2,
				       std::vector<double> & tof,
				       std::vector<double> & tof_err2,
				       void *temp);
} // AxisManip
