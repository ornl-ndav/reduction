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
 * \file utils/src/fit_linear_background.hpp
 */
#ifndef _FIT_LINEAR_BACKGROUND_HPP
#define _FIT_LINEAR_BACKGROUND_HPP 1

#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include "utils.hpp"
#include <limits>
#include <stdexcept>

namespace Utils
{
  /// String for holding the fit_linear_background function name 
  const std::string flb_func_str = "Utils::fit_linear_background";

  // 3.43
  template <typename NumT>
  std::string
  fit_linear_background(const Nessi::Vector<NumT> & axis_in,
                        const Nessi::Vector<NumT> & input,
                        const Nessi::Vector<NumT> & input_err2,
                        const std::size_t min_bin,
                        const std::size_t max_bin,
                        NumT & slope,
                        NumT & slope_err2,
                        NumT & intercept,
                        NumT & intercept_err2,
                        void *temp=NULL)
  {
    // check that the input and input err2 arrays are of proper size
    try
      {
        Utils::check_sizes_square(input, input_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(flb_func_str + " input data & err2 "
                                    + e.what());
      }
    // check that the input and axis_in arrays are of proper size
    try
      {
        Utils::check_sizes_square(axis_in, input);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(flb_func_str + " input data & axis "
                                    + e.what());
      }
    std::string retstr(Nessi::EMPTY_WARN);
	std::string warn;

    // Setup place holders for sums

    NumT axis2_sum = static_cast<NumT>(0.0);
    NumT axis_sum = static_cast<NumT>(0.0);
    NumT inv_err2_sum = static_cast<NumT>(0.0);
    NumT data_sum = static_cast<NumT>(0.0);
    NumT axis_data_sum = static_cast<NumT>(0.0);

    std::size_t start_bin;
    std::size_t end_bin;

    // Setup the bin range for the fit. If max_bin is 0, the full array 
    // is assumed.

    // Setup the starting bin
    start_bin = min_bin;

    // Setup the ending bin
    if (max_bin == 0 || max_bin > (input.size() - 1))
      {
        end_bin = input.size() - 1;
      }
    else 
      {
        end_bin = max_bin;
      }

    // Now that start_bin and end_bin have been set from min_bin and max_bin, 
    // check to make sure that start_bin is less than end_bin
    if (start_bin >= end_bin)
      {
        throw std::invalid_argument(flb_func_str + " min_bin must be less "\
                                    +"than max_bin");
      }

    for (std::size_t i =  start_bin; i <= end_bin; ++i)
    {
        retstr += __fit_linear_background_dynamic(axis_in[i], input[i], 
                                               input_err2[i], axis2_sum,
                                               axis_sum, inv_err2_sum,
                                               data_sum, axis_data_sum);    
    }


    warn = __fit_linear_background_static(axis2_sum, axis_sum, inv_err2_sum,
                                          data_sum, axis_data_sum, slope,
                                          slope_err2, intercept, 
                                          intercept_err2);
    if (!warn.empty())
      {
        retstr += warn;
      }

    return retstr;
  }

  /**
   * \ingroup fit_linear_background
   * 
   * This is a PRIVATE helper function for fit_linear_background that 
   * calculates parameters invariant across array calculation
   *
   * \param axis2_sum (INPUT) same as parameter in
   *  __fit_linear_background_dynamic()
   * \param axis_sum (INPUT) same as parameter in
   *  __fit_linear_background_dynamic()
   * \param inv_err2_sum (INPUT) same as parameter in
   *  __fit_linear_background_dynamic()
   * \param data_sum (INPUT) same as parameter in
   *  __fit_linear_background_dynamic()
   * \param axis_data_sum (INPUT) same as parameter in
   *  __fit_linear_background_dynamic()
   * \param slope (OUTPUT) same as parameter in fit_linear_background()
   * \param slope_err2 (OUTPUT) same as parameter in fit_linear_background()
   * \param intercept (OUTPUT) same as parameter in fit_linear_background()
   * \param intercept_err2 (OUTPUT) same as parameter in 
   * fit_linear_background()
   */
  template <typename NumT>
  std::string
  __fit_linear_background_static(const NumT axis2_sum, 
                                 const NumT axis_sum,
                                 const NumT inv_err2_sum,
                                 const NumT data_sum,
                                 const NumT axis_data_sum,
                                 NumT & slope,
                                 NumT & slope_err2,
                                 NumT & intercept,
                                 NumT & intercept_err2)
  {
    NumT delta = (inv_err2_sum * axis2_sum) - (axis_sum * axis_sum);
    
    slope = ((inv_err2_sum * axis_data_sum) - (axis_sum * data_sum)) / delta;
    slope_err2 = inv_err2_sum / delta;

    intercept = ((axis2_sum * data_sum) - (axis_sum * axis_data_sum)) / delta;
    intercept_err2 = axis2_sum / delta;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup fit_linear_background
   * 
   * This is a PRIVATE helper function for fit_linear_background that 
   * calculates the sums necessary for calculating the fit parameters
   *
   * \param axis_in (INPUT) same as parameter in fit_linear_background()
   * \param input (INPUT) same as parameter in fit_linear_background()
   * \param input_err2 (INPUT) same as parameter in fit_linear_background()
   * \param axis2_sum (INPUT/OUTPUT) the value of 
   * \f$\sum\frac{axis^2_i[i]}{\sigma^2_i[i]}\f$
   * \param axis_sum (INPUT/OUTPUT) the value of 
   * \f$\sum\frac{axis_i[i]}{\sigma^2_i[i]}\f$
   * \param inv_err2_sum (INPUT/OUTPUT) the value of 
   * \f$\sum\frac{1}{\sigma^2_i[i]}\f$
   * \param data_sum (INPUT/OUTPUT) the value of 
   * \f$\sum\frac{data_i[i]}{\sigma^2_i[i]}\f$
   * \param axis_data_sum (INPUT/OUTPUT) the value of 
   * \f$\sum\frac{axis_i[i]\:data_i[i]}{\sigma^2_i[i]}\f$
   */
  template <typename NumT>
  std::string
  __fit_linear_background_dynamic(const NumT axis_in,
                                  const NumT input,
                                  const NumT input_err2,
                                  NumT & axis2_sum, 
                                  NumT & axis_sum,
                                  NumT & inv_err2_sum,
                                  NumT & data_sum,
                                  NumT & axis_data_sum)
  {
    axis2_sum += ((axis_in * axis_in) / input_err2);
    axis_sum += (axis_in / input_err2);
    inv_err2_sum += (static_cast<NumT>(1.0) / input_err2);
    data_sum += (input / input_err2);
    axis_data_sum += ((axis_in * input) / input_err2);

    return Nessi::EMPTY_WARN;
  }

} // Utils

#endif // _FIT_LINEAR_BACKGROUND_HPP
