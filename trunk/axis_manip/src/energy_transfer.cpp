/**
 * $Id$
 *
 * \file axis_manip/src/energy_transfer.cpp
 */
#include "energy_transfer.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \see energy_transfer()
   */
  template std::string
  energy_transfer<float>(std::vector<float> const & initial_energy,
			 std::vector<float> const & initial_energy_err2,
			 std::vector<float> const & final_energy,
			 std::vector<float> const & final_energy_err2,
			 std::vector<float> & energy_transfer,
			 std::vector<float> & energy_transfer_err2,
			 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \see energy_transfer()
   */
  template std::string
  energy_transfer<double>(std::vector<double> const & initial_energy,
			  std::vector<double> const & initial_energy_err2,
			  std::vector<double> const & final_energy,
			  std::vector<double> const & final_energy_err2,
			  std::vector<double> & energy_transfer,
			  std::vector<double> & energy_transfer_err2,
			  void *temp);
} // AxisManip
