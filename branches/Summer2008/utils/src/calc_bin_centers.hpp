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
 * \file utils/src/calc_bin_centers.hpp
 */
#ifndef _CALC_BIN_CENTERS_HPP
#define _CALC_BIN_CENTERS_HPP 1

#include "size_checks.hpp"
#include "utils.hpp"
#include "nessi_warn.hpp"
#include <stdexcept>

namespace Utils
{
  /// String for holding the calc_bin_centers function name
  const std::string cbc_func_str = "Utils::calc_bin_centers";

  // 3.52
  template <typename NumT>
  std::string
  calc_bin_centers(const Nessi::Vector<NumT> & axis,
                   const Nessi::Vector<NumT> & axis_err2,
                   Nessi::Vector<NumT> & bin_centers,
                   Nessi::Vector<NumT> & bin_centers_err2,
                   void *temp=NULL)
  {
    // check that the axis and axis_err2 value arrays are of proper size
    try
      {
        Utils::check_sizes_square(axis, axis_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(cbc_func_str+" axis data "+e.what());
      }
    // check that the axis and bin_centers are of the proper size
    try
      {
        Utils::check_histo_sizes(bin_centers, bin_centers_err2, axis);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(cbc_func_str+":  bin_centers "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);
    
    std::size_t size_bin_centers = bin_centers.size();

	#pragma omp parallel for
    for (int i = 0; i < (int) size_bin_centers; ++i)
    {
        std::string warn = __calc_bin_centers_dynamic(axis[i] + axis[i+1], 
                                          axis_err2[i] + axis_err2[i+1], 
                                          bin_centers[i], 
                                          bin_centers_err2[i]);
        if (!warn.empty())
        {
			#pragma omp critical
			{
				retstr += warn;
			}
        }
		
    }

    return retstr;
  }

  /**
   * \ingroup calc_bin_centers
   *
   * This is a PRIVATE helper function for calc_bin_centers that calculates 
   * the bin center and its uncertainty squared
   *
   * \param val_sum (INPUT) is the sum of the i and i+1 axis values
   * \param err2_sum (INPUT) is the sum of the i and i+1 axis square 
   * uncertainty values
   * \param bin_center (OUTPUT) same as the parameter in calc_bin_centers()
   * \param bin_center_err2 (OUTPUT) same as the parameter in 
   * calc_bin_centers()
   */
  template <typename NumT>
  std::string
  __calc_bin_centers_dynamic(const NumT val_sum,
                             const NumT err2_sum,
                             NumT & bin_center,
                             NumT & bin_center_err2)
  {
    bin_center = static_cast<NumT>(0.5 * static_cast<double>(val_sum));
    bin_center_err2 = static_cast<NumT>(0.25 * static_cast<double>(err2_sum));

    return Nessi::EMPTY_WARN;
  }

} // Utils

#endif // _CALC_BIN_CENTERS_HPP
