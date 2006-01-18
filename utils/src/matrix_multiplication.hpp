/**
 * $Id$
 *
 * \file utils/src/matrix_multiplication.hpp
 */
#ifndef _MATRIX_MULTIPLICATION_HPP
#define _MATRIX_MULTIPLICATION_HPP 1

#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  // 3.37
  template <typename NumT>
  std::string
  matrix_multiplication(const Nessi::Vector<NumT> & input,
                        const Nessi::Vector<NumT> & input_err2,
                        Nessi::Vector<NumT> & output,
                        Nessi::Vector<NumT> & output_err2,
                        void *temp=NULL)
  {
    throw std::runtime_error("Function [matrix_multiplication] not implemented");
  }
} // AxisManip

#endif // _MATRIX_MULTIPLICATION_HPP
