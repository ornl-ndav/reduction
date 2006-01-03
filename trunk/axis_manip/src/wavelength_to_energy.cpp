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
  wavelength_to_energy<float>(Nessi::Vector<float> const & wavelength,
			      Nessi::Vector<float> const & wavelength_err2,
			      Nessi::Vector<float> & energy,
			      Nessi::Vector<float> & energy_err2,
			      void *temp);
  
  /**
   * This is the float declaration of the function defined in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<float>(const float wavelength,
			      const float wavelength_err2,
			      float & energy,
			      float & energy_err2,
			      void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<double>(Nessi::Vector<double> const & wavelength,
			       Nessi::Vector<double> const & wavelength_err2,
			       Nessi::Vector<double> & energy,
			       Nessi::Vector<double> & energy_err2,
			       void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<double>(const double wavelength,
			       const double wavelength_err2,
			       double & energy,
			       double & energy_err2,
			       void *temp);
} // AxisManip
