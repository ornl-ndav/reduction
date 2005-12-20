/**
 * $Id$
 *
 * \file axis_manip/src/reverse_array_cp.hpp
 */
#include "reverse_array.hpp"
#include <algorithm>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.11
  template <typename NumT>
  std::string 
  reverse_array_cp(std::vector<NumT> const & input,
		std::vector<NumT> & output,
		void *temp=NULL)
  {
    std::string retstr("");

    reverse_copy(input.begin(), input.end(), output.begin());
    
    return retstr;
  }
} // AxisManip
