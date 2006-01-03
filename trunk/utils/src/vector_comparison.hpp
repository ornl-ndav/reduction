/**
 * $Id$
 *
 * \file utils/src/vector_comparison.hpp
 */
#ifndef _VECTOR_COMPARISON_HPP
#define _VECTOR_COMPARISON_HPP 1

#include "num_comparison.hpp"

namespace Utils
{
  template <typename NumT>
  void
  vector_comparison (const Nessi::Vector<NumT> & value,
                     const Nessi::Vector<NumT> & true_value,
                     int & error,
                     const int add_error,
                     const int n_max)
  {
    for (int i = 0 ; i < n_max ; i++)
      {
	if (value[i] != true_value[i])
	  {
	    error += add_error;
	    break;
	  }
      }
    return;
  }
}

#endif // _VECTOR_COMPARISON_HPP
