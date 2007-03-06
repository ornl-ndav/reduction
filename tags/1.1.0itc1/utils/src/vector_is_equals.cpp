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
 * \file utils/src/vector_is_equals.cpp
 */
#include "vector_is_equals.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the vector_is_equals function.
   *
   * \ingroup vector_is_equals
   */
  template bool
  vector_is_equals<float>(const Nessi::Vector<float> & value,
                          const Nessi::Vector<float> & true_value);

  /**
   * This is the double declaration of the vector_is_equals function.
   *
   * \ingroup vector_is_equals
   */
  template bool
  vector_is_equals<double>(const Nessi::Vector<double> & value,
                           const Nessi::Vector<double> & true_value);

  /**
   * This is the integer declaration of the vector_is_equals function.
   *
   * \ingroup vector_is_equals
   */
  template bool
  vector_is_equals<int>(const Nessi::Vector<int> & value,
                        const Nessi::Vector<int> & true_value);

  /**
   * This is the unsigned integer declaration of the vector_is_equals
   * function.
   *
   * \ingroup vector_is_equals
   */
  template bool
  vector_is_equals<unsigned int>(
                               const Nessi::Vector<unsigned int> & value,
                               const Nessi::Vector<unsigned int> & true_value);

} // Utils
