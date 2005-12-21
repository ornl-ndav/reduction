/**
 * $Id$
 *
 * \file axis_manip/src/velocity_to_scalar_k.cpp
 */
#include "velocity_to_scalar_k.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.23.
   *
   * \see velocity_to_scalar_k()
   */
  template std::string
  velocity_to_scalar_k<float>(Nessi::Vector<float> const & velocity,
			      Nessi::Vector<float> const & velocity_err2,
			      Nessi::Vector<float> & wavevector,
			      Nessi::Vector<float> & wavevector_err2,
			      void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.23.
   *
   * \see velocity_to_scalar_k()
   */
  template std::string
  velocity_to_scalar_k<double>(Nessi::Vector<double> const & velocity,
			       Nessi::Vector<double> const & velocity_err2,
			       Nessi::Vector<double> & wavevector,
			       Nessi::Vector<double> & wavevector_err2,
			       void *temp);
} // AxisManip
