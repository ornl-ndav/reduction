/**
 * $Id$
 *
 * \file utils/src/matrix_multiplication.cpp
 */
#include "utils.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace Utils
{
  // 3.37
  template <typename NumT>
  std::string
  matrix_multiplication(std::vector<NumT> const & input,
			std::vector<NumT> const & input_err2,
			std::vector<NumT> & output,
			std::vector<NumT> & output_err2,
			void *temp=NULL)
  {
    throw std::runtime_error("Function [matrix_multiplication] not implemented");
  }
  
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.37.
   *
   * \see matrix_multiplication()
   */
  template std::string
  matrix_multiplication<float>(std::vector<float> const & input,
			       std::vector<float> const & input_err2,
			       std::vector<float> & output,
			       std::vector<float> & output_err2,
			       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.37.
   *
   * \see matrix_multiplication()
   */
  template std::string
  matrix_multiplication<double>(std::vector<double> const & input,
				std::vector<double> const & input_err2,
				std::vector<double> & output,
				std::vector<double> & output_err2,
				void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.37.
   *
   * \see matrix_multiplication()
   */
  template std::string
  matrix_multiplication<int>(std::vector<int> const & input,
			     std::vector<int> const & input_err2,
			     std::vector<int> & output,
			     std::vector<int> & output_err2,
			     void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.37.
   *
   * \see matrix_multiplication()
   */
  template std::string
  matrix_multiplication<unsigned int>(std::vector<unsigned int> const & input,
				  std::vector<unsigned int> const & input_err2,
				  std::vector<unsigned int> & output,
				  std::vector<unsigned int> & output_err2,
				  void *temp);
  
} // AxisManip
