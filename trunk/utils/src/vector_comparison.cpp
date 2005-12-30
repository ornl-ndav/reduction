/**
 * $Id: $
 *
 * \file utils/src/vector_comparison.cpp
 */

#include "vector_comparison.hpp"
#include <limits>
#define Precision_range 1e-6

namespace Utils
{
  // specialized function for float
  void vector_comparison (Nessi::Vector<float> const & value,
                          Nessi::Vector<float> const & true_value,
                          int & error,
                          const int add_error,
                          const int n_max)
  {
      for (int i = 0 ; i < n_max ; i++)
	{
          if (fabs(value[i] - true_value[i]) 
              > fabs(value[i])*Precision_range)
              //              > std::numeric_limits<float>::epsilon())
            {
              error += add_error;
            }
          return;
        }
      
      return;
  }

  // specialized function for double
  void vector_comparison (Nessi::Vector<double> const & value,
                          Nessi::Vector<double> const & true_value,
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
              error += add_error;
            }
          return;
        }
      
      return;
  }

  // explicit instantiations

  template void
  vector_comparison<int>(Nessi::Vector<int> const & value,
                         Nessi::Vector<int> const & true_value,
                         int & error,
                         const int add_error,
                         const int n_max);

  template void
  vector_comparison<unsigned int>(
                               Nessi::Vector<unsigned int> const & value,
                               Nessi::Vector<unsigned int> const & true_value,
                               int & error,
                               const int add_error,
                               const int n_max);
}
