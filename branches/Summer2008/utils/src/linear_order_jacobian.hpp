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
 * \file utils/src/linear_order_jacobian.hpp
 */
#ifndef _LINEAR_ORDER_JACOBIAN_HPP
#define _LINEAR_ORDER_JACOBIAN_HPP 1

#include "size_checks.hpp"
#include "utils.hpp"
#include "nessi_warn.hpp"
#include <cmath>
#include <stdexcept>

namespace Utils 
{
  /// String for holding the linear_order_jacobian function name
  const std::string lojac_func_str = "Utils::linear_order_jacobian";

  // 3.49
  template <typename NumT>
  std::string
  linear_order_jacobian(const Nessi::Vector<NumT> & orig_axis,
                        const Nessi::Vector<NumT> & transform_axis,
                        const Nessi::Vector<NumT> & input,
                        const Nessi::Vector<NumT> & input_err2,
                        Nessi::Vector<NumT> & output,
                        Nessi::Vector<NumT> & output_err2,
                        void *temp=NULL)
  {
    // check that the input and output value arrays are of proper size
    try
      {
        Utils::check_sizes_square(input, output);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(lojac_func_str+" input data & output data "
                                    +e.what());
      }
    // check that the original histogram is of the proper size
    try
      {
        Utils::check_histo_sizes(input, input_err2, orig_axis);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(lojac_func_str+": original histogram "
                                    +e.what());
      }
    // check that the transformed histogram is of the proper size
    try
      {
        Utils::check_histo_sizes(output, output_err2, transform_axis);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(lojac_func_str+": transformed histogram "
                                    +e.what());
      }
    std::string retstr(Nessi::EMPTY_WARN);

    std::size_t size_in = input.size();

    for (std::size_t i = 0; i < size_in; ++i)
      {
       	retstr += linear_order_jacobian(orig_axis[i], orig_axis[i+1],
                                     transform_axis[i], transform_axis[i+1],
                                     input[i], input_err2[i],
                                     output[i], output_err2[i]);
				
      }

    return retstr;
  }

  // 3.49 
  template <typename NumT>
  std::string
  linear_order_jacobian(const NumT orig_axis_lo,
                        const NumT orig_axis_hi,
                        const NumT transform_axis_lo,
                        const NumT transform_axis_hi,
                        const NumT input,
                        const NumT input_err2,
                        NumT & output,
                        NumT & output_err2,
                        void *temp=NULL)
  {
    NumT ratio = (orig_axis_hi - orig_axis_lo) / 
      (transform_axis_hi - transform_axis_lo);

    output = input * static_cast<NumT>(std::fabs(static_cast<double>(ratio)));
    output_err2 = input_err2 * ratio * ratio;

    return Nessi::EMPTY_WARN;
  }

} // Utils

#endif // _LINEAR_ORDER_JACOBIAN_HPP
