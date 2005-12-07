/**
 * $Id$
 *
 * \file axis_manip/src/frequency_to_angular_frequency.cpp
 */
#include "conversions.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.31
  template <typename NumT>
  std::string
  frequency_to_angular_frequency(std::vector<NumT> const & frequency,
				 std::vector<NumT> const & frequency_err2,
				 std::vector<NumT> & angular_frequency,
				 std::vector<NumT> & angular_frequency_err2,
				 void *temp=NULL)
  {
    throw std::runtime_error("Function [frequency_to_angular_frequency] not implemented");
  }
  
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
  
  /**
   * This is the integer declaration of the function defined in 3.31.
   *
   * \see frequency_to_angular_frequency()
   */
  template std::string
  frequency_to_angular_frequency<int>(
                                     std::vector<int> const & frequency,
                                     std::vector<int> const & frequency_err2,
                                     std::vector<int> & angular_frequency,
				     std::vector<int> & angular_frequency_err2,
                                     void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined in 3.31.
   *
   * \see frequency_to_angular_frequency()
   */
  template std::string
  frequency_to_angular_frequency<unsigned int>(
                            std::vector<unsigned int> const & frequency,
                            std::vector<unsigned int> const & frequency_err2,
                            std::vector<unsigned int> & angular_frequency,
                            std::vector<unsigned int> & angular_frequency_err2,
                            void *temp);
  
} // AxisManip
