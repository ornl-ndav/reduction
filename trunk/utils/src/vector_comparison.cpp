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
	if (compare(value[i], true_value[i]) != 0)
	  {
	    std::cout << "At index #" << i << ": ";
	    std::cout << "Value expected was ";

	    std::cout.setf(std::ios::fixed);
	    std::cout << std::setprecision(std::numeric_limits<float>::digits10+1);
	    std::cout << true_value[i];
	    std::cout << ", Value returned was " << value[i] << std::endl;
	    std::cout << "Difference (Returned - Expected): ";
	    std::cout.setf(std::ios::scientific);
	    std::cout << value[i] - true_value[i] << std::endl;
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
	if (compare(value[i], true_value[i]) != 0)
	  {
	    std::cout << "At index #" << i << ": ";
	    std::cout << "Value expected was ";
	    std::cout.setf(std::ios::fixed);
	    std::cout << std::setprecision(std::numeric_limits<double>::digits10+1);
	    std::cout << true_value[i];
	    std::cout << ", Value returned was " << value[i] << std::endl;
	    std::cout << "Difference (Returned - Expected): ";
	    std::cout.setf(std::ios::scientific);
	    std::cout << value[i] - true_value[i] << std::endl;
	    error += add_error;
	  }
	return;
      }
    
    return;
  }
  
  // explicit instantiations
  
  /**
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<int>(const Nessi::Vector<int> & value,
                         const Nessi::Vector<int> & true_value,
                         int & error,
                         const int add_error);

  /**
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<unsigned int>(
                               const Nessi::Vector<unsigned int> & value,
                               const Nessi::Vector<unsigned int> & true_value,
                               int & error,
                               const int add_error);
} // Utils
