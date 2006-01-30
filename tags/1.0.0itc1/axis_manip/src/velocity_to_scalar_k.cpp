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
   * \ingroup velocity_to_scalar_k
   */
  template std::string
  velocity_to_scalar_k<float>(const Nessi::Vector<float> & velocity,
			      const Nessi::Vector<float> & velocity_err2,
			      Nessi::Vector<float> & wavevector,
			      Nessi::Vector<float> & wavevector_err2,
			      void *temp);

  /**
   * This is the float declaration of the function defined in 3.23.
   *
   * \ingroup velocity_to_scalar_k
   */
  template std::string
  velocity_to_scalar_k<float>(const float velocity,
			      const float velocity_err2,
			      float & wavevector,
			      float & wavevector_err2,
			      void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.23.
   *
   * \ingroup velocity_to_scalar_k
   */
  template std::string
  velocity_to_scalar_k<double>(const Nessi::Vector<double> & velocity,
			       const Nessi::Vector<double> & velocity_err2,
			       Nessi::Vector<double> & wavevector,
			       Nessi::Vector<double> & wavevector_err2,
			       void *temp);


  /**
   * This is the double precision float declaration of the function
   * defined in 3.23.
   *
   * \ingroup velocity_to_scalar_k
   */
  template std::string
  velocity_to_scalar_k<double>(const double velocity,
			       const double velocity_err2,
			       double & wavevector,
			       double & wavevector_err2,
			       void *temp);
} // AxisManip
