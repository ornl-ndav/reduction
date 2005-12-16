/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_energy.cpp
 */
#include "wavelength_to_energy.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<float>(std::vector<float> const & wavelength,
			      std::vector<float> const & wavelength_err2,
			      std::vector<float> & energy,
			      std::vector<float> & energy_err2,
			      void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<double>(std::vector<double> const & wavelength,
			       std::vector<double> const & wavelength_err2,
			       std::vector<double> & energy,
			       std::vector<double> & energy_err2,
			       void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<int>(std::vector<int> const & wavelength,
			    std::vector<int> const & wavelength_err2,
			    std::vector<int> & energy,
			    std::vector<int> & energy_err2,
			    void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<unsigned int>(
                             std::vector<unsigned int> const & wavelength,
                             std::vector<unsigned int> const & wavelength_err2,
                             std::vector<unsigned int> & energy,
                             std::vector<unsigned int> & energy_err2,
                             void *temp);
  
} // AxisManip
