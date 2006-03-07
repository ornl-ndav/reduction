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
 * \file utils/src/weighted_average.hpp
 */
#ifndef _WEIGHTED_AVERAGE_HPP
#define _WEIGHTED_AVERAGE_HPP 1

#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  // String for holding weighted_ave function name
  const std::string wa_func_str = "Utils::weighted_average";

  // 3.46
  template <typename NumT>
  std::string
  weighted_average(const Nessi::Vector<NumT> & input,
                   const Nessi::Vector<NumT> & input_err2,
                   const std::size_t bin_start,
                   const std::size_t bin_end,
                   NumT & weighted_ave,
                   NumT & weighted_ave_err2,
                   void *temp=NULL)
  {
    // check that the value and uncertainty arrays are of proper size
    try
      {
        Utils::check_sizes_square(input, input_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wa_func_str+" data & err "+e.what());
      }

    weighted_ave = static_cast<NumT>(0.0);
    weighted_ave_err2 = static_cast<NumT>(0.0);

    for(std::size_t i = bin_start; i <= bin_end; ++i)
      {
        weighted_ave += (input[i] / input_err2[i]);
        weighted_ave_err2 += (static_cast<NumT>(1.) / input_err2[i]);
      }

    weighted_ave /= weighted_ave_err2;
    weighted_ave_err2 = (static_cast<NumT>(1.) / weighted_ave_err2);

    return Nessi::EMPTY_WARN;
  }

} // Utils

#endif // _WEIGHTED_AVERAGE_HPP
