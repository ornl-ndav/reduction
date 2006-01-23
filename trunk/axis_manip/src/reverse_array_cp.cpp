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
 * \file axis_manip/src/reverse_array_cp.cpp
 */
#include "reverse_array_cp.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration for the function defined in 3.11.
   *
   * \ingroup reverse_array_cp
   */
  template std::string
  reverse_array_cp<float>(const Nessi::Vector<float> & input,
                          Nessi::Vector<float> & output,
                          void *temp);

  /**
   * This is the double precision float declaration for the function
   * defined in 3.11.
   *
   * \ingroup reverse_array_cp
   */
  template std::string
  reverse_array_cp<double>(const Nessi::Vector<double> & input,
                           Nessi::Vector<double> & output,
                           void *temp);

  /**
   * This is the integer declaration for the function defined in 3.11.
   *
   * \ingroup reverse_array_cp
   */
  template std::string
  reverse_array_cp<int>(const Nessi::Vector<int> & input,
                        Nessi::Vector<int> & output,
                        void *temp);

  /**
   * This is the unsigned integer declaration for the function defined
   * in 3.11.
   *
   * \ingroup reverse_array_cp
   */
  template std::string
  reverse_array_cp<unsigned int>(const Nessi::Vector<unsigned int> & input,
                                 Nessi::Vector<unsigned int> & output,
                                 void *temp);

} // AxisManip
