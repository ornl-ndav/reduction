/**
 * $Id$
 *
 * \file utils/src/fit_linear_background.hpp
 */
#ifndef _FIT_LINEAR_BACKGROUND_HPP
#define _FIT_LINEAR_BACKGROUND_HPP 1

#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  // 3.43
  template <typename NumT>
  std::string
  fit_linear_background(const Nessi::Vector<NumT> & axis_in,
                        const Nessi::Vector<NumT> & input,
                        const Nessi::Vector<NumT> & input_err2,
                        NumT min_val,
                        NumT max_val,
                        NumT slope_start,
                        NumT intercept_start,
                        NumT & slope_out,
                        NumT & slope_out_err2,
                        NumT & intercept_out,
                        NumT & intercept_out_err2,
                        void *temp=NULL)
  {
    throw std::runtime_error("Function [fit_linear_background] not implemented");
  }

} // Utils

#endif // _FIT_LINEAR_BACKGROUND_HPP
