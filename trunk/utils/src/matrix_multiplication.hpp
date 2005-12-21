/**
 * $Id$
 *
 * \file utils/src/matrix_multiplication.hpp
 */
#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  // 3.37
  template <typename NumT>
  std::string
  matrix_multiplication(Nessi::Vector<NumT> const & input,
			Nessi::Vector<NumT> const & input_err2,
			Nessi::Vector<NumT> & output,
			Nessi::Vector<NumT> & output_err2,
			void *temp=NULL)
  {
    throw std::runtime_error("Function [matrix_multiplication] not implemented");
  }
} // AxisManip
