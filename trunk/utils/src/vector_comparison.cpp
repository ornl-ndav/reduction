/**
 * $Id: $
 *
 * \file utils/src/vector_comparison.cpp
 */

#include "num_comparison.hpp"
#include <limits>
#define Precision_range 1e-6

namespace Utils
{
  void vector_comparison (Nessi::Vector<int> const & value,
                          Nessi::Vector<int> const & true_value,
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

  void vector_comparison (Nessi::Vector<unsigned int> const & value,
                          Nessi::Vector<unsigned int> const & true_value,
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
}
