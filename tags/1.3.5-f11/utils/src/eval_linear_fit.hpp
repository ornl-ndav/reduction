/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 *
 * For this software and its associated documentation, permission is granted
 * to reproduce, prepare derivative works, and distribute copies to the public
 * for any purpose and without fee.
 *
 * This material was prepared as an account of work sponsored by an agency of
 * the United States Government.  Neither the United States Government nor the
 * United States Department of Energy, nor any of their employees, makes any
 * warranty, express or implied, or assumes any legal liability or
 * responsibility for the accuracy, completeness, or usefulness of any
 * information, apparatus, product, or process disclosed, or represents that
 * its use would not infringe privately owned rights.
 *
 */

/**
 * $Id$
 *
 * \file utils/src/eval_linear_fit.hpp
 */
#ifndef _EVAL_LINEAR_FIT_HPP
#define _EVAL_LINEAR_FIT_HPP 1

#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  /// String for holding the eval_linear_fit function name
  const std::string elf_func_str = "Utils::eval_linear_fit";

  // 3.56
  template <typename NumT>
  std::string
  eval_linear_fit(const Nessi::Vector<NumT> & axis_in,
                  const Nessi::Vector<NumT> & axis_in_err2,
                  const NumT slope,
                  const NumT slope_err2,
                  const NumT intercept,
                  const NumT intercept_err2,
                  Nessi::Vector<NumT> & output,
                  Nessi::Vector<NumT> & output_err2,
                  void *temp=NULL)
  {
    // check that the axis_in and axis_in err2 arrays are of proper size
    try
      {
        Utils::check_sizes_square(axis_in, axis_in_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(elf_func_str + " axis_in & err2 "
                                    + e.what());
      }
    // check that the output and axis_in arrays are of proper size
    try
      {
        Utils::check_sizes_square(axis_in, output);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(elf_func_str + " axis & output data "
                                    + e.what());
      }
    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    std::size_t size_axis = axis_in.size();

    for (std::size_t i = 0; i < size_axis; ++i)
      {
        warn = __eval_linear_fit_dynamic(axis_in[i], axis_in_err2[i], 
                                         slope, slope_err2, 
                                         intercept, intercept_err2,
                                         output[i], output_err2[i]);
        if (!warn.empty())
          {
            retstr += warn;
          }
        
      }

    return retstr;
  }

  /**
   * \ingroup eval_linear_fit
   * 
   * This is a PRIVATE helper function for eval_linear_fit that 
   * calculates the value from the axis value and fit parameters
   *
   * \param axis_in (INPUT) same as parameter in eval_linear_fit()
   * \param axis_in_err2 (INPUT) same as parameter in eval_linear_fit()
   * \param slope (INPUT) asame as parameter in eval_linear_fit()
   * \param slope_err2 (INPUT) asame as parameter in eval_linear_fit()
   * \param intercept (INPUT) asame as parameter in eval_linear_fit()
   * \param intercept_err2 (INPUT) asame as parameter in eval_linear_fit()
   * \param output (OUTPUT) same as parameter in eval_linear_fit()
   * \param output_err2 (OUTPUT) same as parameter in eval_linear_fit()
   */
  template <typename NumT>
  std::string
  __eval_linear_fit_dynamic(const NumT axis_in,
                            const NumT axis_in_err2,
                            const NumT slope,
                            const NumT slope_err2,
                            const NumT intercept,
                            const NumT intercept_err2,
                            NumT & output,
                            NumT & output_err2)
  {
    output = slope * axis_in + intercept;

    output_err2 = (axis_in * axis_in * slope_err2) + 
      (slope * slope * axis_in_err2) + intercept_err2;

    return Nessi::EMPTY_WARN;
  }

} // Utils

#endif // _EVAL_LINEAR_FIT_HPP
