/**
 * $Id$
 *
 * \file utils/src/vector_comparison.cpp
 */

#include "vector_comparison.hpp"
#include <limits>

#define Precision_range 1e-6

namespace Utils
{
  // specialized function for float
  void vector_comparison (const Nessi::Vector<float> & value,
                          const Nessi::Vector<float> & true_value,
                          int & error,
                          const int add_error,
                          const int n_max)
  {
      for (int i = 0 ; i < n_max ; i++)
	{
	  if (fabs(value[i] - true_value[i]) 
		  > fabs(value[i])*Precision_range)
		{
		  std::cout << "At iteration #" << i << " :\n";
		  printf("\tValue expected was:\t%2.10f",true_value[i]);
		  printf("\n\tValue returned:\t\t%2.10f\n",value[i]);
		  error += add_error;
		  return;
		}
	  //	  return;
	}
      
      return;
  }

  // specialized function for double
  void vector_comparison (const Nessi::Vector<double> & value,
                          const Nessi::Vector<double> & true_value,
                          int & error,
                          const int add_error,
                          const int n_max)
  {
      for (int i = 0 ; i < n_max ; i++)
	{
          if (fabs(value[i] - true_value[i]) 
              > fabs(value[i])*Precision_range)
            //              > std::numeric_limits<double>::epsilon())
            {
			  std::cout << "At iteration #" << i << " :\n";
			  printf("\tValue expected was:\t%2.10f",true_value[i]);
			  printf("\n\tValue returned:\t\t%2.10f\n",value[i]);
              error += add_error;
			  return;
            }
		  //          return;
        }
      
      return;
  }

  // explicit instantiations

  template void
  vector_comparison<int>(const Nessi::Vector<int> & value,
                         const Nessi::Vector<int> & true_value,
                         int & error,
                         const int add_error,
                         const int n_max);

  template void
  vector_comparison<unsigned int>(
                               const Nessi::Vector<unsigned int> & value,
                               const Nessi::Vector<unsigned int> & true_value,
                               int & error,
                               const int add_error,
                               const int n_max);
}
