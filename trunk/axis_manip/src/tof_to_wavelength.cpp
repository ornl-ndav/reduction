/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_wavelength.cpp
 */
#include "tof_to_wavelength.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \see tof_to_wavelength()
   */
  template std::string
  tof_to_wavelength<float>(Nessi::Vector<float> const & tof,
			   Nessi::Vector<float> const & tof_err2,
			   const float pathlength,
			   const float pathlength_err2,
			   Nessi::Vector<float> & wavelength,
			   Nessi::Vector<float> & wavelength_err2,
			   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \see tof_to_wavelength()
   */
  template std::string
  tof_to_wavelength<double>(Nessi::Vector<double> const & tof,
			    Nessi::Vector<double> const & tof_err2,
			    const double pathlength,
			    const double pathlength_err2,
			    Nessi::Vector<double> & wavelength,
			    Nessi::Vector<double> & wavelength_err2,
			    void *temp);
} // AxisManip
