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
 * \file axis_manip/src/reverse_array_nc.hpp
 */
#ifndef _REVERSE_ARRAY_NC_HPP
#define _REVERSE_ARRAY_NC_HPP 1

#include "nessi_warn.hpp"
#include "reverse_array.hpp"
#include <algorithm>

namespace AxisManip
{
  // 3.11
  template <typename NumT>
  std::string
  reverse_array_nc(Nessi::Vector<NumT> & inout,
                   void *temp=NULL)
  {
    reverse(inout.begin(), inout.end());

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif// _REVERSE_ARRAY_NC_HPP
