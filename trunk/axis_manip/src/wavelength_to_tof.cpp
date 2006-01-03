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
  wavelength_to_tof<float>(const Nessi::Vector<float> & wavelength,
			   const Nessi::Vector<float> & wavelength_err2,
			   const float pathlength,
			   const float pathlength_err2,
			   Nessi::Vector<float> & tof,
			   Nessi::Vector<float> & tof_err2,
			   void *temp);
  
  /**
   * This is the float declaration of the function defined in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<float>(const float wavelength,
			   const float wavelength_err2,
			   const float pathlength,
			   const float pathlength_err2,
			   float & tof,
			   float & tof_err2,
			   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<double>(const Nessi::Vector<double> & wavelength,
			    const Nessi::Vector<double> & wavelength_err2,
			    const double pathlength,
			    const double pathlength_err2,
			    Nessi::Vector<double> & tof,
			    Nessi::Vector<double> & tof_err2,
			    void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<double>(const double wavelength,
			    const double wavelength_err2,
			    const double pathlength,
			    const double pathlength_err2,
			    double & tof,
			    double & tof_err2,
			    void *temp);
} // AxisManip
