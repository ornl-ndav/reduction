/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_Q.cpp
 */
#include "wavelength_to_scalar_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.18.
   *
   * \see wavelength_to_scalar_Q()
   */
  template std::string
  wavelength_to_scalar_Q<float>(Nessi::Vector<float> const & wavelength,
				Nessi::Vector<float> const & wavelength_err2,
				const float scatt_angle,
				const float scatt_angle_err2,
				Nessi::Vector<float> & Q,
				Nessi::Vector<float> & Q_err2,
				void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.18.
   *
   * \see wavelength_to_scalar_Q()
   */
  template std::string
  wavelength_to_scalar_Q<double>(Nessi::Vector<double> const & wavelength,
				 Nessi::Vector<double> const & wavelength_err2,
				 const double scatt_angle,
				 const double scatt_angle_err2,
				 Nessi::Vector<double> & Q,
				 Nessi::Vector<double> & Q_err2,
				 void *temp);
} // AxisManip
