/**
 * $Id$
 *
 * \file axis_manip/src/reverse_array_cp.hpp
 */
#include "reverse_array.hpp"
#include <algorithm>

namespace AxisManip
{
  // 3.11
  template <typename NumT>
  std::string 
  reverse_array_cp(Nessi::Vector<NumT> const & input,
		Nessi::Vector<NumT> & output,
		void *temp=NULL)
  {
    std::string retstr("");

    reverse_copy(input.begin(), input.end(), output.begin());
    
    return retstr;
  }
} // AxisManip
