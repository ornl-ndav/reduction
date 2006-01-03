/**
 * $Id$
 *
 * \file axis_manip/src/velocity_to_energy.cpp
 */
#include "velocity_to_energy.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.21.
   *
   * \see velocity_to_energy()
   */
  template std::string
  velocity_to_energy<float>(Nessi::Vector<float> const & velocity,
			    Nessi::Vector<float> const & velocity_err2,
			    Nessi::Vector<float> & energy,
			    Nessi::Vector<float> & energy_err2,
			    void *temp);
  
  /**
   * This is the float declaration of the function defined in 3.21.
   *
   * \see velocity_to_energy()
   */
  template std::string
  velocity_to_energy<float>(const float velocity,
			    const float velocity_err2,
			    float & energy,
			    float & energy_err2,
			    void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.21.
   *
   * \see velocity_to_energy()
   */
  template std::string
  velocity_to_energy<double>(Nessi::Vector<double> const & velocity,
			     Nessi::Vector<double> const & velocity_err2,
			     Nessi::Vector<double> & energy,
			     Nessi::Vector<double> & energy_err2,
			     void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.21.
   *
   * \see velocity_to_energy()
   */
  template std::string
  velocity_to_energy<double>(const double velocity,
			     const double velocity_err2,
			     double & energy,
			     double & energy_err2,
			     void *temp);
} // AxisManip
