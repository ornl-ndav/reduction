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

#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  // 3.43
  template <typename NumT>
  std::string
  fit_linear_background(const Nessi::Vector<NumT> & axis_in,
                        const Nessi::Vector<NumT> & input,
                        const Nessi::Vector<NumT> & input_err2,
                        NumT min_val,
                        NumT max_val,
                        NumT slope_start,
                        NumT intercept_start,
                        NumT & slope_out,
                        NumT & slope_out_err2,
                        NumT & intercept_out,
                        NumT & intercept_out_err2,
                        void *temp=NULL)
  {
    throw std::runtime_error("Function [fit_linear_background] not implemented");
  }

} // Utils

#endif // _FIT_LINEAR_BACKGROUND_HPP
