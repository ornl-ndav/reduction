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
 * \file axis_manip/src/frequency_to_angular_frequency.hpp
 */
#ifndef _FREQUENCY_TO_ANGULAR_FREQUENCY_HPP
#define _FREQUENCY_TO_ANGULAR_FREQUENCY_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.31
  template <typename NumT>
  std::string
  frequency_to_angular_frequency(const Nessi::Vector<NumT> & frequency,
                                 const Nessi::Vector<NumT> & frequency_err2,
                                 Nessi::Vector<NumT> & angular_frequency,
                                 Nessi::Vector<NumT> & angular_frequency_err2,
                                 void *temp=NULL)
  {
    throw std::runtime_error("Function [frequency_to_angular_frequency] not implemented");
  }

  // 3.31
  template <typename NumT>
  std::string
  frequency_to_angular_frequency(const NumT frequency,
                                 const NumT frequency_err2,
                                 NumT & angular_frequency,
                                 NumT & angular_frequency_err2,
                                 void *temp=NULL)
  {
    throw std::runtime_error("Function [frequency_to_angular_frequency] not implemented");
  }
} // AxisManip

#endif // _FREQUENCY_TO_ANGULAR_FREQUENCY_HPP