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
  template <typename NumT>
  int 
  compare(const NumT & value1,
	  const NumT & value2)
  {
    if(value1 == value2)
      return 0;
    else if(value1 > value2)
      return 1;
    else 
      return -1;
  }
} // Utils

#endif // _COMPARE_HPP
