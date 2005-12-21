/**
 * $Id$
 *
 * \file utils/src/matrix_multiplication.cpp
 */
#include "matrix_multiplication.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.37.
   *
   * \see matrix_multiplication()
   */
  template std::string
  matrix_multiplication<float>(Nessi::Vector<float> const & input,
			       Nessi::Vector<float> const & input_err2,
			       Nessi::Vector<float> & output,
			       Nessi::Vector<float> & output_err2,
			       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.37.
   *
   * \see matrix_multiplication()
   */
  template std::string
  matrix_multiplication<double>(Nessi::Vector<double> const & input,
				Nessi::Vector<double> const & input_err2,
				Nessi::Vector<double> & output,
				Nessi::Vector<double> & output_err2,
				void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.37.
   *
   * \see matrix_multiplication()
   */
  template std::string
  matrix_multiplication<int>(Nessi::Vector<int> const & input,
			     Nessi::Vector<int> const & input_err2,
			     Nessi::Vector<int> & output,
			     Nessi::Vector<int> & output_err2,
			     void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.37.
   *
   * \see matrix_multiplication()
   */
  template std::string
  matrix_multiplication<unsigned int>(
                                Nessi::Vector<unsigned int> const & input,
				Nessi::Vector<unsigned int> const & input_err2,
                                Nessi::Vector<unsigned int> & output,
                                Nessi::Vector<unsigned int> & output_err2,
                                void *temp);
  
} // AxisManip
