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
  energy_transfer<float>(Nessi::Vector<float> const & initial_energy,
			 Nessi::Vector<float> const & initial_energy_err2,
			 Nessi::Vector<float> const & final_energy,
			 Nessi::Vector<float> const & final_energy_err2,
			 Nessi::Vector<float> & energy_transfer,
			 Nessi::Vector<float> & energy_transfer_err2,
			 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \see energy_transfer()
   */
  template std::string
  energy_transfer<double>(Nessi::Vector<double> const & initial_energy,
			  Nessi::Vector<double> const & initial_energy_err2,
			  Nessi::Vector<double> const & final_energy,
			  Nessi::Vector<double> const & final_energy_err2,
			  Nessi::Vector<double> & energy_transfer,
			  Nessi::Vector<double> & energy_transfer_err2,
			  void *temp);
} // AxisManip
