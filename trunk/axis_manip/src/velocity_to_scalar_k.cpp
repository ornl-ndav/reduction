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
  velocity_to_scalar_k<float>(std::vector<float> const & velocity,
			      std::vector<float> const & velocity_err2,
			      std::vector<float> & wavevector,
			      std::vector<float> & wavevector_err2,
			      void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.23.
   *
   * \see velocity_to_scalar_k()
   */
  template std::string
  velocity_to_scalar_k<double>(std::vector<double> const & velocity,
			       std::vector<double> const & velocity_err2,
			       std::vector<double> & wavevector,
			       std::vector<double> & wavevector_err2,
			       void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.23.
   *
   * \see velocity_to_scalar_k()
   */
  template std::string
  velocity_to_scalar_k<int>(std::vector<int> const & velocity,
			    std::vector<int> const & velocity_err2,
			    std::vector<int> & wavevector,
			    std::vector<int> & wavevector_err2,
			    void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.23.
   *
   * \see velocity_to_scalar_k()
   */
  template std::string
  velocity_to_scalar_k<unsigned int>(
                               std::vector<unsigned int> const & velocity,
                               std::vector<unsigned int> const & velocity_err2,
                               std::vector<unsigned int> & wavevector,
                               std::vector<unsigned int> & wavevector_err2,
                               void *temp);
  
} // AxisManip
