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
 * \file utils/src/check_sizes_square.cpp
 */
#include "check_sizes_square.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void
  check_sizes_square<float>(const Nessi::Vector<float> & array1,
                            const Nessi::Vector<float> & array2,
                            const Nessi::Vector<float> & array3);

  /**
   * This is the double declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void
  check_sizes_square<double>(const Nessi::Vector<double> & array1,
                             const Nessi::Vector<double> & array2,
                             const Nessi::Vector<double> & array3);

  /**
   * This is the integer declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void
  check_sizes_square<int>(const Nessi::Vector<int> & array1,
                          const Nessi::Vector<int> & array2,
                          const Nessi::Vector<int> & array3);

  /**
   * This is the unsigned integer declaration of the check_sizes_square
   * function
   *
   * \ingroup check_sizes_square
   */
  template void
  check_sizes_square<unsigned int>(const Nessi::Vector<unsigned int> & array1,
                                   const Nessi::Vector<unsigned int> & array2,
                                   const Nessi::Vector<unsigned int> & array3);

  /**
   * This is the float declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void
  check_sizes_square<float>(const Nessi::Vector<float> & array1,
                            const Nessi::Vector<float> & array2);

  /**
   * This is the double declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void
  check_sizes_square<double>(const Nessi::Vector<double> & array1,
                             const Nessi::Vector<double> & array2);

  /**
   * This is the integer declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void
  check_sizes_square<int>(const Nessi::Vector<int> & array1,
                          const Nessi::Vector<int> & array2);

  /**
   * This is the unsigned integer declaration of the check_sizes_square
   * function
   *
   * \ingroup check_sizes_square
   */
  template void
  check_sizes_square<unsigned int>(const Nessi::Vector<unsigned int> & array1,
                                   const Nessi::Vector<unsigned int> & array2);

} // Utils
