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
   * \ingroup wavelength_to_d_spacing
   */
  template std::string
  wavelength_to_d_spacing<float>(const Nessi::Vector<float> & wavelength,
				 const Nessi::Vector<float> & wavelength_err2,
				 const float scatt_angle,
				 const float scatt_angle_err2,
				 Nessi::Vector<float> & d_spacing,
				 Nessi::Vector<float> & d_spacing_err2,
				 void *temp);
  
  /**
   * This is the float declaration of the function defined in 3.25.
   *
   * \ingroup wavelength_to_d_spacing
   */
  template std::string
  wavelength_to_d_spacing<float>(const float wavelength,
				 const float wavelength_err2,
				 const float scatt_angle,
				 const float scatt_angle_err2,
				 float & d_spacing,
				 float & d_spacing_err2,
				 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.25.
   *
   * \ingroup wavelength_to_d_spacing
   */
  template std::string
  wavelength_to_d_spacing<double>(
                                 const Nessi::Vector<double> & wavelength,
				 const Nessi::Vector<double> & wavelength_err2,
                                 const double scatt_angle,
                                 const double scatt_angle_err2,
                                 Nessi::Vector<double> & d_spacing,
                                 Nessi::Vector<double> & d_spacing_err2,
                                 void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.25.
   *
   * \ingroup wavelength_to_d_spacing
   */
  template std::string
  wavelength_to_d_spacing<double>(const double wavelength,
				  const double wavelength_err2,
				  const double scatt_angle,
				  const double scatt_angle_err2,
				  double & d_spacing,
				  double & d_spacing_err2,
				  void *temp);
} // AxisManip