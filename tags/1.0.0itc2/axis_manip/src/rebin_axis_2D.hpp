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
 * \file axis_manip/src/rebin_axis_2D.hpp
 */
#ifndef _REBIN_AXIS_2D_HPP
#define _REBIN_AXIS_2D_HPP 1

#include "rebinning.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.13
  template <typename NumT>
  std::string
  rebin_axis_2D(const Nessi::Vector<NumT> & axis_in_1,
                const Nessi::Vector<NumT> & axis_in_2,
                const Nessi::Vector<NumT> & input,
                const Nessi::Vector<NumT> & input_err2,
                const Nessi::Vector<NumT> & axis_out_1,
                const Nessi::Vector<NumT> & axis_out_2,
                Nessi::Vector<NumT> & output,
                Nessi::Vector<NumT> & output_err2,
                void *temp=NULL)
  {
    throw std::runtime_error("Function [rebin_axis_2D] not implemented");
  }
} // AxisManip

#endif // _REBIN_AXIS_2D_HPP
