/**
 * $Id: $
 *
 * \file utils/src/matrix_multiplication.hpp
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
} // AxisManip
