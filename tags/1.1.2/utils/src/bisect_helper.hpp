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
 * \file utils/src/bisect_helper.hpp
 */
#ifndef _BISECT_HELPER_HPP
#define _BISECT_HELPER_HPP 1

#include "utils.hpp"
#include "nessi_warn.hpp"
#include <algorithm>

namespace Utils
{
  template <typename NumT>
  std::string
  bisect_helper(const Nessi::Vector<NumT> & axis,
                const NumT value,
                std::size_t & index,
                void *temp=NULL)
  {
    std::pair<typename Nessi::Vector<NumT>::const_iterator, 
      typename Nessi::Vector<NumT>::const_iterator> range1;

    range1 = std::equal_range(axis.begin(), axis.end(), value);

    std::size_t index1 = range1.second - axis.begin();
    std::size_t index2 = range1.first - axis.begin();

    index = __fix_index2(std::max(index1, index2) - 1, axis.size() - 1);

    return Nessi::EMPTY_WARN;
  }


} // Utils

#endif // _BISECT_HELPER_HPP
