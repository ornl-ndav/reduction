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
 * \file utils/src/fix_index2.cpp
 */
#include "utils.hpp"
#include <limits>

namespace Utils
{
  std::size_t __fix_index2(const std::size_t index, 
                           const std::size_t end_index)
  {
    if(index == std::numeric_limits<std::size_t>::max())
      {
        return 0;
      }
    else if(index == end_index)
      {
        return index - 1;
      }
    else
      {
        return index;
      }
  }
} // Utils
