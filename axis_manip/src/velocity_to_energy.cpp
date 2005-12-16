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
  velocity_to_energy<float>(std::vector<float> const & velocity,
			    std::vector<float> const & velocity_err2,
			    std::vector<float> & energy,
			    std::vector<float> & energy_err2,
			    void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.21.
   *
   * \see velocity_to_energy()
   */
  template std::string
  velocity_to_energy<double>(std::vector<double> const & velocity,
			     std::vector<double> const & velocity_err2,
			     std::vector<double> & energy,
			     std::vector<double> & energy_err2,
			     void *temp);
} // AxisManip
