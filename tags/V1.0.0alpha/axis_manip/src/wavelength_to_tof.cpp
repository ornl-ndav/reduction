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
  wavelength_to_tof<float>(std::vector<float> const & wavelength,
			   std::vector<float> const & wavelength_err2,
			   const float pathlength,
			   const float pathlength_err2,
			   std::vector<float> & tof,
			   std::vector<float> & tof_err2,
			   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<double>(std::vector<double> const & wavelength,
			    std::vector<double> const & wavelength_err2,
			    const double pathlength,
			    const double pathlength_err2,
			    std::vector<double> & tof,
			    std::vector<double> & tof_err2,
			    void *temp);
} // AxisManip
