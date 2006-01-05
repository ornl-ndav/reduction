/**
 * $Id$
 *
 * \file axis_manip/src/reverse_array_nc.hpp
 */
#ifndef _REVERSE_ARRAY_NC_HPP
#define _REVERSE_ARRAY_NC_HPP 1

#include "reverse_array.hpp"
#include <algorithm>

namespace AxisManip
{
  // 3.11
  template <typename NumT>
  std::string 
  reverse_array_nc(Nessi::Vector<NumT> & inout,
		   void *temp=NULL)
  {
    std::string retstr("");

    reverse(inout.begin(), inout.end());
    
    return retstr;
  }
} // AxisManip

#endif// _REVERSE_ARRAY_NC_HPP
