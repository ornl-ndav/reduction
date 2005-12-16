/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_k.cpp
 */
#include "wavelength_to_scalar_k.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.24.
   *
   * \see wavelength_to_scalar_k()
   */
  template std::string
  wavelength_to_scalar_k<float>(std::vector<float> const & wavelength,
				std::vector<float> const & wavelength_err2,
				std::vector<float> & wavevector,
				std::vector<float> & wavevector_err2,
				void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.24.
   *
   * \see wavelength_to_scalar_k()
   */
  template std::string
  wavelength_to_scalar_k<double>(std::vector<double> const & wavelength,
				 std::vector<double> const & wavelength_err2,
				 std::vector<double> & wavevector,
				 std::vector<double> & wavevector_err2,
				 void *temp);
} // AxisManip
