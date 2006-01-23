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
 * \file utils/src/vector_comparison.cpp
 */
#include "vector_comparison.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the vector_comparison function.
   *
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<float>(const Nessi::Vector<float> & value,
                           const Nessi::Vector<float> & true_value,
                           int & error,
                           const int add_error);

  /**
   * This is the double declaration of the vector_comparison function.
   *
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<double>(const Nessi::Vector<double> & value,
                            const Nessi::Vector<double> & true_value,
                            int & error,
                            const int add_error);

  /**
   * This is the integer declaration of the vector_comparison function.
   *
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<int>(const Nessi::Vector<int> & value,
                         const Nessi::Vector<int> & true_value,
                         int & error,
                         const int add_error);

  /**
   * This is the unsigned integer declaration of the vector_comparison
   * function.
   *
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<unsigned int>(
                               const Nessi::Vector<unsigned int> & value,
                               const Nessi::Vector<unsigned int> & true_value,
                               int & error,
                               const int add_error);
} // Utils
