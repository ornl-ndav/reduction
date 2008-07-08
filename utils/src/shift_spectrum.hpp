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
 * \file utils/src/shift_spectrum.hpp
 */
#ifndef _SHIFT_SPECTRUM_HPP
#define _SHIFT_SPECTRUM_HPP 1

#include "num_comparison.hpp"
#include "size_checks.hpp"
#include "utils.hpp"

namespace Utils
{
  // String for holding shift_spectrum function name
  const std::string ss_func_str = "Utils::shift_spectrum";

  // 3.64
  template <typename NumT>
  std::string
  shift_spectrum(const Nessi::Vector<NumT> & input,
                 const Nessi::Vector<NumT> & input_err2,
                 const Nessi::Vector<NumT> & axis_in,
                 const Nessi::Vector<NumT> & axis_bc_in,
                 const NumT xshift,
                 const NumT xmin,
                 const NumT xmax,
                 Nessi::Vector<NumT> & output,
                 Nessi::Vector<NumT> & output_err2,
                 void *temp=NULL)
  {
    // Check input is histogram
    Utils::check_histo_sizes(ss_func_str
                             + std::string(" input histogram data "), 
                             input, input_err2, axis_in);
    
    // Check output is histogram
    Utils::check_histo_sizes(ss_func_str
                             + std::string(" output histogram data "), 
                             output, output_err2, axis_in);

    // Check input and output are same size
    Utils::check_sizes_square(ss_func_str 
                              + std::string(" input & output data "),
                              input, output);

    // Check input and axis_bc_in are same size
    Utils::check_sizes_square(ss_func_str 
                              + std::string(" input data & bin centers "),
                              input, axis_bc_in);

    size_t ie_index;
    size_t ae_index;
    size_t pos_index;
    NumT axis_pos;

    std::string warn = "";

    warn += Utils::bisect_helper(axis_in, xmin, ie_index);
    warn += Utils::bisect_helper(axis_in, xmax, ae_index);

    for (size_t i = ie_index; i <= ae_index; ++i)
      {
        if (Utils::compare(axis_bc_in[i], xshift) < 1)
          {
            axis_pos = axis_bc_in[i] + (xmax - xshift);
          }
        else
          {
            axis_pos = axis_bc_in[i] - (xshift - xmin);
          }
        warn += Utils::bisect_helper(axis_in, axis_pos, pos_index);
        output[i] = input[pos_index];
        output_err2[i] = input_err2[pos_index];
      }

    return warn;
  }
} // Utils

#endif // _SHIFT_SPECTRUM_HPP
