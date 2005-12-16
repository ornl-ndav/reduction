/**
 * $Id$
 *
 * \file axis_manip/src/init_scatt_wavevector_to_scalar_Q.cpp
 */
#include "init_scatt_wavevector_to_scalar_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaraion of the function defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<float>(
					   std::vector<float> const & initial_wavevector,
					   std::vector<float> const & initial_wavevector_err2,
					   std::vector<float> const & final_wavevector,
					   std::vector<float> const & final_wavevector_err2,
					   const float polar_angle,
					   const float polar_angle_err2,
					   std::vector<float> & Q,
					   std::vector<float> & Q_err2,
					   void *temp);
  
  /**
   * This is the double precision float declaraion of the function
   * defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<double>(
					    std::vector<double> const & initial_wavevector,
					    std::vector<double> const & initial_wavevector_err2,
					    std::vector<double> const & final_wavevector,
					    std::vector<double> const & final_wavevector_err2,
					    const double polar_angle,
					    const double polar_angle_err2,
					    std::vector<double> & Q,
					    std::vector<double> & Q_err2,
					    void *temp);
} // AxisManip
