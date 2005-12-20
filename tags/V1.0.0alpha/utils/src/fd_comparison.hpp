/**
 * $Id:$
 *
 * \file utils/src/fd_comparison.hpp
 */
#include "num_comparison.hpp"
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

#define Precision_range 1e-6

using namespace std;

namespace Utils
{
  template <typename NumT>
  void
  fd_comparison (std::vector<NumT> const & value,
		 std::vector<NumT> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max)
  {
      for (int i=0; i< n_max; i++)
	{
//	  if (fabs(value[i] - true_value[i]) > fabs(value[i]) 
//    * numeric_limits<NumT>::epsilon())
	  if (fabs(value[i]-true_value[i])> fabs(value[i])*Precision_range)
	    {
	      error += add_error;
	      return;
	    }
	}
      
      return;
  }
}
