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
 * \file utils/src/vector_comparison.hpp
 */
#ifndef _VECTOR_COMPARISON_HPP
#define _VECTOR_COMPARISON_HPP 1

#include "num_comparison.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

namespace Utils
{
  // vector comparison function
  template <typename NumT>
  void
  vector_comparison (const Nessi::Vector<NumT> & value,
                     const Nessi::Vector<NumT> & true_value,
                     int & error,
                     const int add_error)
  {
    int n_max = true_value.size();
    for (int i = 0 ; i < n_max ; i++)
      {
        if (compare(value[i], true_value[i]) != 0)
          {
            __vector_comparison_dynamic(i, value[i], true_value[i],
                                       error, add_error);
            break;
          }
      }
    return;
  }

  /**
   * This is a PRIVATE helper function for printing debugging information if
   * the equality check fails.
   *
   * \param index (INPUT) what index the values compared come from
   * \param value (INPUT) the value to compare
   * \param true_value (INPUT) the actual value
   * \param error (OUTPUT) changes by add_error if the two values are
   * not equal
   * \param add_error (INPUT) the value that the error should change
   * by if the two values are not equal
   */
  template <typename NumT>
  void
  __vector_comparison_dynamic(const int index,
                             const NumT value,
                             const NumT true_value,
                             int & error,
                             const int add_error)
  {
    std::cout << "At index #" << index << ": ";
    std::cout << "Value expected was ";
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(std::numeric_limits<NumT>::digits10+1);
    std::cout << true_value;
    std::cout << ", Value returned was " << value << std::endl;
    std::cout << "Difference (Returned - Expected): ";
    std::cout.setf(std::ios::scientific);
    std::cout << value - true_value << std::endl;
    error += add_error;

    return;
  }



} // Utils

#endif // _VECTOR_COMPARISON_HPP
