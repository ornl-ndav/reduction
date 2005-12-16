/**
 * $Id$
 *
 * \file axis_manip/src/frequency_to_angular_frequency.cpp
 */
#include "frequency_to_angular_frequency.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.31.
   *
   * \see frequency_to_angular_frequency()
   */
  template std::string
  frequency_to_angular_frequency<float>(
                                   std::vector<float> const & frequency,
                                   std::vector<float> const & frequency_err2,
                                   std::vector<float> & angular_frequency,
                                   std::vector<float> & angular_frequency_err2,
                                   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.31.
   *
   * \see frequency_to_angular_frequency()
   */
  template std::string
  frequency_to_angular_frequency<double>(
                                  std::vector<double> const & frequency,
                                  std::vector<double> const & frequency_err2,
                                  std::vector<double> & angular_frequency,
			          std::vector<double> & angular_frequency_err2,
                                  void *temp);
} // AxisManip
