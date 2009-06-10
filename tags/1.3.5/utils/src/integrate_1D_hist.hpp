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
 * \file utils/src/integrate_1D_hist.hpp
 */
#ifndef _INTEGRATE_1D_HIST
#define _INTEGRATE_1D_HIST 1

#include <cmath>
#include <limits>
#include "size_checks.hpp"
#include "utils.hpp"

namespace Utils
{
  // String for holding integrate_1D_hist function name
  const std::string i1h_func_str = "Utils::integrate_1D_hist";

  // 3.65
  template <typename NumT>
  std::string
  integrate_1D_hist(const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const Nessi::Vector<NumT> & axis_in,
                    const bool width,
                    const Nessi::Vector<NumT> & axis_bw_in,
                    NumT & output,
                    NumT & output_err2,
                    void *temp=NULL)
  {
    // Simply call the other function
    return integrate_1D_hist(input, input_err2, axis_in,
                             std::numeric_limits<NumT>::infinity(),
                             std::numeric_limits<NumT>::infinity(),
                             width, axis_bw_in,
                             output, output_err2, temp);
  }

  // 3.65
  template <typename NumT>
  std::string
  integrate_1D_hist(const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const Nessi::Vector<NumT> & axis_in,
                    const NumT min_int,
                    const NumT max_int, 
                    const bool width,
                    const Nessi::Vector<NumT> & axis_bw_in,
                    NumT & output,
                    NumT & output_err2,
                    void *temp=NULL)
  {
    // Check input is histogram
    Utils::check_histo_sizes(i1h_func_str 
                             + std::string(" input histogram data:"),
                             input, input_err2, axis_in);

    // Check that input and axis_bw_in are the same size if width is true
    if (width)
      {
        Utils::check_sizes_square(i1h_func_str
                                  + std::string(" input data & bin widths:"),
                                  input, axis_bw_in);
      }

    // Zero output holders 
    output = static_cast<NumT>(0.0);
    output_err2 = static_cast<NumT>(0.0);

    std::size_t min_bin;
    std::size_t max_bin;

    std::string warn = "";

    // Determine the lower bin index
    if (std::isinf(min_int))
      {
        min_bin = 0;
      }
    else
      {
        warn += Utils::bisect_helper(axis_in, min_int, min_bin);
      }

    // Determine the upper bin index
    if (std::isinf(max_int))
      {
        max_bin = input.size() - 1;
      }
    else
      {
        warn += Utils::bisect_helper(axis_in, max_int, max_bin);
      }

    for (std::size_t i = min_bin; i <= max_bin; ++i)
      {
        if (!std::isnan(input[i]) && !std::isnan(input_err2[i]) && 
            !std::isinf(input[i]) && !std::isinf(input_err2[i]))
          {
            if (width)
              {
                output += (axis_bw_in[i] * input[i]);
                output_err2 += (axis_bw_in[i] * axis_bw_in[i] * input_err2[i]);
              }
            else
              {
                output += input[i];
                output_err2 += input_err2[i];
              }
          }
      }

    return warn;
  }
} // Utils

#endif // _INTEGRATE_1D_HIST
