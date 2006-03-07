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
 * \file utils/inc/size_checks.hpp
 */
#ifndef _SIZE_CHECKS_HPP
#define _SIZE_CHECKS_HPP 1

#include "nessi.hpp"
#include <string>

namespace Utils
{
  /**
   * \defgroup check_histo_sizes Utils::check_histo_sizes
   * \{
   */

  /**
   * \brief This function checks data, error2 and axis vectors for
   * consistent sizes.
   *
   * This function checks the sizes of data, error2 and an axis vector for
   * the correct sizes in terms of a histogram model. The data and error2
   * vectors should be one element shorter than the axis vector. If the
   * vectors have inconsistent sizes, an exception is thrown.
   *
   * \param input (INPUT) is the histogram data
   * \param input_err2 (INPUT) is the histogram uncertainty squared
   * \param axis (INPUT) is the histogram axis
   *
   * \exception std::invalid_argument is thrown if the size of axis is
   * not one more than input and input_err2.
   */
  template <typename NumT>
  void check_histo_sizes(const Nessi::Vector<NumT> & input,
                         const Nessi::Vector<NumT> & input_err2,
                         const Nessi::Vector<NumT> & axis);

  /**
   * \}
   */ // end of check_histo_sizes group

  /**
   * \defgroup check_sizes_square Utils::check_sizes_square
   * \{
   */

  /**
   * \brief This function checks three vectors for consistent sizes.
   *
   * This function checks the sizes of three vector for consistent sizes.
   * If the vectors do not have consistent sizes, an exception is thrown.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param array1 (INPUT) is a vector that needs size checking
   * \param array2 (INPUT) is a vector that needs size checking
   * \param array3 (INPUT) is a vector that needs size checking
   *
   * \exception std::invalid_argument is thrown if the size of array1,
   * array2, and array3 are not identical.
   */
  template <typename NumT>
  void check_sizes_square(const Nessi::Vector<NumT> & array1,
                          const Nessi::Vector<NumT> & array2,
                          const Nessi::Vector<NumT> & array3);

  /**
   * \brief This function checks two vectors for consistent sizes.
   *
   * This function checks the sizes of two vectors for consistent sizes.
   * If the vectors do not have consistent sizes, an exception is thrown.
   *
   * \param array1 (INPUT) is a vector that needs size checking
   * \param array2 (INPUT) is a vector that needs size checking
   *
   * \exception std::invalid_argument is thrown if the size of array1
   * and array2 are not identical.
   */
  template <typename NumT>
  void check_sizes_square(const Nessi::Vector<NumT> & array1,
                          const Nessi::Vector<NumT> & array2);

  /**
   * \}
   */ // end of check_sizes_square group

} // Utils

#endif // _SIZE_CHECKS_HPP
