#ifndef _NUM_COMPARISON_H
#define _NUM_COMPARISON_H

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

namespace Utils
{
  template <typename NumT>
  void
  fd_comparison (std::vector<NumT> const & value,
		 std::vector<NumT> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);

  template <typename NumT>
  void
  iu_comparison (std::vector<NumT> const & value,
		 std::vector<NumT> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);
  
}

#endif    //_NUM_COMPARISON_H
