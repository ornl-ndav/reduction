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
  tof_to_wavelength<float>(std::vector<float> const & tof,
			   std::vector<float> const & tof_err2,
			   const float pathlength,
			   const float pathlength_err2,
			   std::vector<float> & wavelength,
			   std::vector<float> & wavelength_err2,
			   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \see tof_to_wavelength()
   */
  template std::string
  tof_to_wavelength<double>(std::vector<double> const & tof,
			    std::vector<double> const & tof_err2,
			    const double pathlength,
			    const double pathlength_err2,
			    std::vector<double> & wavelength,
			    std::vector<double> & wavelength_err2,
			    void *temp);
} // AxisManip
