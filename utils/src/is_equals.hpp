/**
 * $Id$
 *
 * \file utils/src/is_equals.hpp
 */
#ifndef _IS_EQUALS_HPP
#define _IS_EQUALS_HPP 1

#include "num_comparison.hpp"

namespace Utils
{
  template <typename NumT>
  bool 
  is_equals(const NumT & value1,
	    const NumT & value2)
  {
    if(value1 == value2)
      return true;
    else
      return false;
  }
} // Utils

#endif // _IS_EQUALS_HPP
