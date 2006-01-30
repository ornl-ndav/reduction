/**
 * $Id$
 *
 * \file utils/src/vector_comparison.cpp
 */
#include "vector_comparison.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the vector_comparison function.
   *
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<float>(const Nessi::Vector<float> & value,
			   const Nessi::Vector<float> & true_value,
			   int & error,
			   const int add_error);
  
  /**
   * This is the double declaration of the vector_comparison function.
   *
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<double>(const Nessi::Vector<double> & value,
			    const Nessi::Vector<double> & true_value,
			    int & error,
			    const int add_error);
  
  /**
   * This is the integer declaration of the vector_comparison function.
   *
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<int>(const Nessi::Vector<int> & value,
                         const Nessi::Vector<int> & true_value,
                         int & error,
                         const int add_error);

  /**
   * This is the unsigned integer declaration of the vector_comparison 
   * function.
   *
   * \ingroup vector_comparison
   */
  template void
  vector_comparison<unsigned int>(
                               const Nessi::Vector<unsigned int> & value,
                               const Nessi::Vector<unsigned int> & true_value,
                               int & error,
                               const int add_error);
} // Utils
