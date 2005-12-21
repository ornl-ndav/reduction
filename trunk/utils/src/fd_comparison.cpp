/**
 * $Id:$
 *
 * \file utils/src/fd_comparison.cpp
 */
#include "fd_comparison.hpp"

#define Precision_range 1e-6

using namespace std;

namespace Utils
{
  
  // explicit instantiations
  
  // This is the float declaration
  template void
  fd_comparison (Nessi::Vector<float> const & value,
		 Nessi::Vector<float> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);
  
  
  // This is the double declaration
  template void
  fd_comparison (Nessi::Vector<double> const & value,
		 Nessi::Vector<double> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);
  
}
