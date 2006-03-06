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
 * \file axis_manip/src/reverse_array_nc.cpp
 */
#include "reverse_array_nc.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration for the function defined in 3.11.
   *
   * \ingroup reverse_array_nc
   */
  template std::string
  reverse_array_nc<float>(Nessi::Vector<float> & inout,
                          void *temp);

  /**
   * This is the double precision float declaration for the function
   * defined in 3.11.
   *
   * \ingroup reverse_array_nc
   */
  template std::string
  reverse_array_nc<double>(Nessi::Vector<double> & inout,
                           void *temp);

  /**
   * This is the integer declaration for the function defined in 3.11.
   *
   * \ingroup reverse_array_nc
   */
  template std::string
  reverse_array_nc<int>(Nessi::Vector<int> & inout,
                        void *temp);

  /**
   * This is the unsigned integer declaration for the function defined
   * in 3.11.
   *
   * \ingroup reverse_array_nc
   */
  template std::string
  reverse_array_nc<unsigned int>(Nessi::Vector<unsigned int> & inout,
                                 void *temp);

} // AxisManip
