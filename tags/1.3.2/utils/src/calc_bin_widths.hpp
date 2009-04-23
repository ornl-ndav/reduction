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
 * \file utils/src/calc_bin_widths.hpp
 */
#ifndef _CALC_BIN_WIDTHS_HPP
#define _CALC_BIN_WIDTHS_HPP 1

#include "size_checks.hpp"
#include "utils.hpp"
#include "nessi_warn.hpp"
#include <stdexcept>

namespace Utils
{
  /// String for holding the calc_bin_widths function name
  const std::string cbw_func_str = "Utils::calc_bin_widths";

  // 3.54
  template <typename NumT>
  std::string
  calc_bin_widths(const Nessi::Vector<NumT> & axis,
                  const Nessi::Vector<NumT> & axis_err2,
                  Nessi::Vector<NumT> & bin_widths,
                  Nessi::Vector<NumT> & bin_widths_err2,
                  void *temp=NULL)
  {
    // check that the axis and axis_err2 value arrays are of proper size
    try
      {
        Utils::check_sizes_square(axis, axis_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(cbw_func_str+" axis data "+e.what());
      }
    // check that the axis and bin_widths are of the proper size
    try
      {
        Utils::check_histo_sizes(bin_widths, bin_widths_err2, axis);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(cbw_func_str+":  bin_widths "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;
    
    std::size_t size_bin_widths = bin_widths.size();
    for (std::size_t i = 0; i < size_bin_widths; ++i)
      {
        warn = __calc_bin_widths_dynamic(axis[i], axis[i+1], 
                                         axis_err2[i], axis_err2[i+1], 
                                         bin_widths[i], 
                                         bin_widths_err2[i]);
        if (!warn.empty())
          {
            retstr += warn;
          }
      }

    return retstr;
  }

  /**
   * \ingroup calc_bin_widths
   *
   * This is a PRIVATE helper function for calc_bin_widths() that calculates 
   * the bin width and its uncertainty squared
   *
   * \param low_val (INPUT) is the ith axis value
   * \param high_val (INPUT) is the i+1th axis value
   * \param low_err2 (INPUT) is the ith axis square uncertainty value
   * \param high_err2 (INPUT) is the i+1th axis square uncertainty value
   * \param bin_width (OUTPUT) same as the parameter in calc_bin_widths()
   * \param bin_width_err2 (OUTPUT) same as the parameter in 
   * calc_bin_widths()
   */
  template <typename NumT>
  std::string
  __calc_bin_widths_dynamic(const NumT low_val,
                            const NumT high_val,
                            const NumT low_err2,
                            const NumT high_err2,
                            NumT & bin_width,
                            NumT & bin_width_err2)
  {
    bin_width = high_val - low_val;
    bin_width_err2 = high_err2 + low_err2;

    return Nessi::EMPTY_WARN;
  }

} // Utils

#endif // _CALC_BIN_WIDTHS_HPP
