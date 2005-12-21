/**
 * $Id$
 *
 * \file axis_manip/src/reverse_array_nc.hpp
 */
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
