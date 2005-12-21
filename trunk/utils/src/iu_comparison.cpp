/**
 * $Id: $
 *
 * \file utils/src/iu_comparison.cpp
 */

#include "iu_comparison.hpp"

using namespace std;

namespace Utils
{
  // explicit instantiations

  // This is the int declaration
  template void 
  iu_comparison (Nessi::Vector<int> const & value,
		 Nessi::Vector<int> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);
  
  template void 
  iu_comparison (Nessi::Vector<unsigned int> const & value,
		 Nessi::Vector<unsigned int> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);
  
}
