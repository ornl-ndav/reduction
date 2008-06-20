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
 * \file array_manip/src/abs_val.hpp
 */
#ifndef _ABS_VAL_HPP
#define _ABS_VAL_HPP 1

#include "arith.hpp"
#include "nessi_warn.hpp"
#include <algorithm>
#include <cmath>

namespace  ArrayManip
{
  /// String for holding the absolute value function name
  const std::string abs_func_str = "ArrayManip::abs_val";

  // 3.55
  template <typename NumT>
  std::string
  abs_val(const Nessi::Vector<NumT> & input,
          Nessi::Vector<NumT> & output,
          void *temp=NULL)
  {
    int size = (int) input.size(); 
	

	#pragma omp parallel for  
    for (int i = 0; i < size; i++)
    {
        	output[i] = static_cast<NumT>(std::abs(static_cast<double>(input[i])));
    }

    return Nessi::EMPTY_WARN;
  }
} // ArrayManip

#endif // _ABS_VAL_HPP


