/**
 * $Id$
 *
 * \file utils/src/iu_comparison.hpp
 */

#include "num_comparison.hpp"
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

namespace Utils
{
  template <typename NumT>
  void
  iu_comparison (std::vector<NumT> const & value,
		 std::vector<NumT> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max)
  {
    for (int i=0; i < n_max; i++)
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
