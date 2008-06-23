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
 * \file array_manip/src/sumw_ncerr.hpp
 */
#ifndef _SUMW_NCERR_HPP
#define _SUMW_NCERR_HPP 1

#include "arith.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <cmath>
#include <stdexcept>

namespace ArrayManip
{
  /// String for holding the sum with weighted uncertainties function name
  const std::string sumw_func_str = "ArrayManip::sumw_ncerr";

  // 3.10
  template <typename NumT>
  std::string
  sumw_ncerr(const Nessi::Vector<NumT> & input1,
             const Nessi::Vector<NumT> & input1_err2,
             const Nessi::Vector<NumT> & input2,
             const Nessi::Vector<NumT> & input2_err2,
             Nessi::Vector<NumT> & output,
             Nessi::Vector<NumT> & output_err2,
             void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(input1,input2,output);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(sumw_func_str+" (v,v): data "+e.what());
      }
    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(input1_err2,input2_err2,output_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(sumw_func_str+" (v,v): err2 "+e.what());
      }
    // check that the input1 arrays are of proper size
    try
      {
        Utils::check_sizes_square(input1,input1_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(sumw_func_str+" (v,v): input1 "+e.what());
      }


    int sz = static_cast<int>(input1.size());

	#pragma omp parallel for 
    for (int i = 0; i < sz; i++)
    {
        // calculate the value
        NumT input1_err =
          	static_cast<NumT>(std::sqrt(static_cast<double>(input1_err2[i])));
        NumT input2_err =
          	static_cast<NumT>(std::sqrt(static_cast<double>(input2_err2[i])));
        NumT sum_err = input1_err + input2_err;
        output[i] = (input1[i] / input1_err) + (input2[i] / input2_err);
        output[i] *= sum_err / static_cast<NumT>(2.);

        // calculate the uncertainty
        output_err2[i]=(input1_err2[i]*input2_err+input2_err2[i]*input1_err)
          	*(input1_err+input2_err);
    }

    return Nessi::EMPTY_WARN;
  }
} // ArrayManip

#endif // _SUMW_NCERR_HPP
