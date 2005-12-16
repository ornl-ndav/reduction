/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_d_spacing.cpp
 */
#include "wavelength_to_d_spacing.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.25.
   *
   * \see wavelength_to_d_spacing()
   */
  template std::string
  wavelength_to_d_spacing<float>(std::vector<float> const & wavelength,
				 std::vector<float> const & wavelength_err2,
				 const float scatt_angle,
				 const float scatt_angle_err2,
				 std::vector<float> & d_spacing,
				 std::vector<float> & d_spacing_err2,
				 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.25.
   *
   * \see wavelength_to_d_spacing()
   */
  template std::string
  wavelength_to_d_spacing<double>(std::vector<double> const & wavelength,
				  std::vector<double> const & wavelength_err2,
				  const double scatt_angle,
				  const double scatt_angle_err2,
				  std::vector<double> & d_spacing,
				  std::vector<double> & d_spacing_err2,
				  void *temp);
} // AxisManip
