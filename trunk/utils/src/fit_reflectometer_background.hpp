/**
 * $Id: $
 *
 * \file utils/src/fit_reflectometer_background.hpp
 */
#include "utils.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace Utils
{
  // 3.42
  template <typename NumT>
  std::string
  fit_reflectometer_background(std::vector<NumT> const & axis_in,
			       std::vector<NumT> const & input,
			       std::vector<NumT> const & input_err2,
			       std::vector<NumT> const & params_in,
			       std::vector<NumT> & output,
			       std::vector<NumT> & output_err2,
			       std::vector<NumT> & params_out,
			       std::vector<NumT> & params_out_err2,
			       void *temp=NULL)
  {
    throw std::runtime_error("Function [fit_reflectometer_background] not implemented");
  }
} // Utils
