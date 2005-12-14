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
  fd_comparison (std::vector<NumT> const & value,
		 std::vector<NumT> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max)
  {
      float Max_epsilon = 0.001;
      for (int i=0; i< n_max; i++)
	{
     	  if (fabs(value[i] - true_value[i]) >= 
	      (fabs(value[i]) * numeric_limits<NumT>::epsilon()))
	    {
	      cout << "Inside the if with i= " <<i<<endl;
	      error += add_error;
	      return;
	    }
	}
      
      return;
  }
  
  
  // explicit instantiations
  
  // This is the float declaration
  template void
  fd_comparison (std::vector<float> const & value,
		 std::vector<float> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);
  
  
  // This is the double declaration
  template void
  fd_comparison (std::vector<double> const & value,
		 std::vector<double> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);
  
}
