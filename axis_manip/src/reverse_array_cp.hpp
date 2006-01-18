/**
 * $Id$
 *
 * \file axis_manip/src/reverse_array_cp.hpp
 */
#ifndef _REVERSE_ARRAY_CP_HPP
#define _REVERSE_ARRAY_CP_HPP 1

#include "reverse_array.hpp"
#include <algorithm>

namespace AxisManip
{
  // 3.11
  template <typename NumT>
  std::string
  reverse_array_cp(const Nessi::Vector<NumT> & input,
                   Nessi::Vector<NumT> & output,
                   void *temp=NULL)
  {
    std::string retstr("");

    std::reverse_copy(input.begin(), input.end(), output.begin());

    return retstr;
  }
} // AxisManip

#endif // _REVERSE_ARRAY_CP_HPP
