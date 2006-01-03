/**
 * $Id$
 *
 * \file utils/src/vector_comparison.cpp
 */
#include "vector_comparison.hpp"
#include <iomanip>
#include <limits>

namespace Utils
{
  // specialized function for float
  void vector_comparison (const Nessi::Vector<float> & value,
                          const Nessi::Vector<float> & true_value,
                          int & error,
                          const int add_error)
  {
    int n_max = true_value.size();
    for (int i = 0 ; i < n_max ; i++)
      {
	if (fabs(value[i] - true_value[i]) > 
	    std::numeric_limits<float>::epsilon())
	  {
	    std::cout << "At index #" << i << ": ";
	    std::cout << "Value expected was ";
	    std::cout << std::setprecision(std::numeric_limits<float>::digits10);
	    std::cout << true_value[i];
	    std::cout << ", Value returned was " << value[i] << std::endl;
	    error += add_error;
	  }
	return;
      }
    
    return;
  }
  
  // specialized function for double
  void vector_comparison (const Nessi::Vector<double> & value,
                          const Nessi::Vector<double> & true_value,
                          int & error,
                          const int add_error)
  {
    int n_max = true_value.size();
    for (int i = 0 ; i < n_max ; i++)
      {
	if (fabs(value[i] - true_value[i]) > 
	    std::numeric_limits<double>::epsilon())
	  {
	    std::cout << "At index #" << i << ": ";
	    std::cout << "Value expected was ";
	    std::cout << std::setprecision(std::numeric_limits<double>::digits10);
	    std::cout << true_value[i];
	    std::cout << ", Value returned was " << value[i] << std::endl;
	    error += add_error;
	  }
	return;
      }
    
    return;
  }
  
  // explicit instantiations
  
  template void
  vector_comparison<int>(const Nessi::Vector<int> & value,
                         const Nessi::Vector<int> & true_value,
                         int & error,
                         const int add_error);

  template void
  vector_comparison<unsigned int>(
                               const Nessi::Vector<unsigned int> & value,
                               const Nessi::Vector<unsigned int> & true_value,
                               int & error,
                               const int add_error);
}
