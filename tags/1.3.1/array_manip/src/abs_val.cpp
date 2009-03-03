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
 * \file array_manip/src/abs_val.cpp
 */
#include "abs_val.hpp"

namespace ArrayManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.55.
   *
   * \ingroup abs_val
   */
  template std::string
  abs_val<float>(const Nessi::Vector<float> & input,
                 Nessi::Vector<float> & output,
                 void *temp);

  /**
   * This is the double precision float declaration of the function defined 
   * in 3.55.
   *
   * \ingroup abs_val
   */
  template std::string
  abs_val<double>(const Nessi::Vector<double> & input,
                  Nessi::Vector<double> & output,
                  void *temp);

  /**
   * This is the integer declaration of the function defined in 3.55.
   *
   * \ingroup abs_val
   */
  template std::string
  abs_val<int>(const Nessi::Vector<int> & input,
               Nessi::Vector<int> & output,
               void *temp);

} // ArrayManip
