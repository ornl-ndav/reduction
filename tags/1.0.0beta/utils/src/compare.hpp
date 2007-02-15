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
 * \file utils/src/compare.hpp
 */
#ifndef _COMPARE_HPP
#define _COMPARE_HPP 1

#include "num_comparison.hpp"

namespace Utils
{
  // compare function
  template <typename NumT>
  int
  compare(const NumT & value1,
          const NumT & value2)
  {
    if(value1 == value2)
      {
        return 0;
      }

    if(value1 > value2)
      {
        return 1;
      }
    else
      {
        return -1;
      }
  }
} // Utils

#endif // _COMPARE_HPP
