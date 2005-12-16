/**
 * $Id: $
 *
 * \file utils/src/fit_linear_background.hpp
 */
#include "utils.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace Utils
{
  // 3.43
  template <typename NumT>
  std::string
  fit_linear_background(std::vector<NumT> const & axis_in,
			std::vector<NumT> const & input,
			std::vector<NumT> const & input_err2,
			NumT min_val, NumT max_val,
			NumT slope_start, 
			NumT intercept_start,
			NumT & slope_out, NumT & slope_out_err2,
			NumT & intercept_out,
			NumT & intercept_out_err2,
			void *temp=NULL)
  {
    throw std::runtime_error("Function [fit_linear_background] not implemented");
  }

} // Utils
