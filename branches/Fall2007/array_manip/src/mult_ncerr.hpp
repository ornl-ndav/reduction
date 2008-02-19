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
 * \file array_manip/src/mult_ncerr.hpp
 */
#ifndef _MULT_NCERR_HPP
#define _MULT_NCERR_HPP 1

#include "arith.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace ArrayManip
{
  /// String for holding the multiplication function name
  const std::string mult_func_str = "ArrayManip::mult_ncerr";

  // 3.3
  template <typename NumT>
  std::string
  mult_ncerr(const Nessi::Vector<NumT> & array_in,
             const Nessi::Vector<NumT> & array_in_err2,
             const NumT scalar,
             const NumT scalar_err2,
             Nessi::Vector<NumT> & array_out,
             Nessi::Vector<NumT> & array_out_err2,
             void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(array_in,array_out);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(mult_func_str+" (v,s): data "+e.what());
      }
    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(array_in_err2,array_out_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(mult_func_str+" (v,s): err2 "+e.what());
      }
    // check that the input arrays are of proper size
    try
      {
        Utils::check_sizes_square(array_in,array_in_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(mult_func_str+" (v,s): input "+e.what());
      }

    NumT scalar2 = scalar * scalar;

    size_t size = array_in.size();
    for (size_t i = 0; i < size; ++i)
      {
        array_out[i] = array_in[i] * scalar;
        array_out_err2[i] = (scalar2 * array_in_err2[i]) +
          ((array_in[i] * array_in[i]) * scalar_err2);
      }
    return Nessi::EMPTY_WARN;
  }

  // 3.8
  template <typename NumT>
  std::string
  mult_ncerr(const Nessi::Vector<NumT> & input1,
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
        Utils::check_sizes_square(input1, input2, output);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(mult_func_str+" (v,v): data "+e.what());
      }
    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(input1_err2, input2_err2, output_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(mult_func_str+" (v,v): err2 "+e.what());
      }
    // check that the input1 arrays are of proper size
    try
      {
        Utils::check_sizes_square(input1,input1_err2);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(mult_func_str+" (v,v): input1 "+e.what());
      }


    std::transform(input1.begin(), input1.end(), input2.begin(),
                   output.begin(), std::multiplies<NumT>());

    size_t sz = input1.size();
    for (size_t i = 0; i < sz; ++i)
      {
        output_err2[i] = (input2[i] * input2[i] * input1_err2[i]) +
          (input1[i] * input1[i] * input2_err2[i]);
      }

    return Nessi::EMPTY_WARN;
  }

  //3.8
  template <typename NumT>
  std::string
  mult_ncerr(const NumT input1,
             const NumT input1_err2,
             const NumT input2,
             const NumT input2_err2,
             NumT & output,
             NumT & output_err2,
             void *temp=NULL)
  {
    output = input1*input2;
    output_err2 = (input2*input1_err2) + (input1*input2_err2);

    return Nessi::EMPTY_WARN;
  }
  
} // ArrayManip

#endif // _MULT_NCERR_HPP
