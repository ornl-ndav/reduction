/**
 * $Id$
 *
 * \file utils/src/vector_comparison.hpp
 */
#ifndef _VECTOR_COMPARISON_HPP
#define _VECTOR_COMPARISON_HPP 1

#include "num_comparison.hpp"
#include <iostream>

namespace Utils
{
  template <typename NumT>
  void
  vector_comparison (const Nessi::Vector<NumT> & value,
                     const Nessi::Vector<NumT> & true_value,
                     int & error,
                     const int add_error)
  {
    int n_max = true_value.size();
    for (int i = 0 ; i < n_max ; i++)
      {
	if (compare(value[i], true_value[i]) != 0)
	  {	    
	    std::cout << "At index #" << i << ": ";
	    std::cout << "Value expected was ";
	    std::cout << true_value[i];
	    std::cout << ", Value returned was " << value[i] << std::endl;
	    error += add_error;
	    break;
	  }
      }
    return;
  }
} // Utils

#endif // _VECTOR_COMPARISON_HPP
