/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_tof.cpp
 */
#include "wavelength_to_tof.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<float>(Nessi::Vector<float> const & wavelength,
			   Nessi::Vector<float> const & wavelength_err2,
			   const float pathlength,
			   const float pathlength_err2,
			   Nessi::Vector<float> & tof,
			   Nessi::Vector<float> & tof_err2,
			   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<double>(Nessi::Vector<double> const & wavelength,
			    Nessi::Vector<double> const & wavelength_err2,
			    const double pathlength,
			    const double pathlength_err2,
			    Nessi::Vector<double> & tof,
			    Nessi::Vector<double> & tof_err2,
			    void *temp);
} // AxisManip
