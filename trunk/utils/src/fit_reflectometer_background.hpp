/**
 * $Id$
 *
 * \file utils/src/fit_reflectometer_background.hpp
 */
#ifndef _FIT_REFLECTOMETER_BACKGROUND_HPP
#define _FIT_REFLECTOMETER_BACKGROUND_HPP 1

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

#endif // _FIT_REFLECTOMETER_BACKGROUND_HPP
