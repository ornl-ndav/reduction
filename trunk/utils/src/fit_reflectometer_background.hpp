/**
 * $Id$
 *
 * \file utils/src/fit_reflectometer_background.hpp
 */
#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  // 3.42
  template <typename NumT>
  std::string
  fit_reflectometer_background(Nessi::Vector<NumT> const & axis_in,
			       Nessi::Vector<NumT> const & input,
			       Nessi::Vector<NumT> const & input_err2,
			       Nessi::Vector<NumT> const & params_in,
			       Nessi::Vector<NumT> & output,
			       Nessi::Vector<NumT> & output_err2,
			       Nessi::Vector<NumT> & params_out,
			       Nessi::Vector<NumT> & params_out_err2,
			       void *temp=NULL)
  {
    throw std::runtime_error("Function [fit_reflectometer_background] not implemented");
  }
} // Utils
