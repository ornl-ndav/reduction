/**
 * $Id$
 *
 * \file utils/src/check_sizes_square.cpp
 */
#include "check_sizes_square.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void 
  check_sizes_square<float>(const Nessi::Vector<float> & array1, 
			    const Nessi::Vector<float> & array2, 
			    const Nessi::Vector<float> & array3);
  
  /**
   * This is the double declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void 
  check_sizes_square<double>(const Nessi::Vector<double> & array1, 
			     const Nessi::Vector<double> & array2, 
			     const Nessi::Vector<double> & array3);
  
  /**
   * This is the integer declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void 
  check_sizes_square<int>(const Nessi::Vector<int> & array1, 
			  const Nessi::Vector<int> & array2, 
			  const Nessi::Vector<int> & array3);
  
  /**
   * This is the unsigned integer declaration of the check_sizes_square 
   * function
   *
   * \ingroup check_sizes_square
   */
  template void 
  check_sizes_square<unsigned int>(const Nessi::Vector<unsigned int> & array1, 
				   const Nessi::Vector<unsigned int> & array2, 
				   const Nessi::Vector<unsigned int> & array3);
  
  /**
   * This is the float declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void 
  check_sizes_square<float>(const Nessi::Vector<float> & array1, 
			    const Nessi::Vector<float> & array2);
  
  /**
   * This is the double declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void 
  check_sizes_square<double>(const Nessi::Vector<double> & array1, 
			     const Nessi::Vector<double> & array2);
  
  /**
   * This is the integer declaration of the check_sizes_square function
   *
   * \ingroup check_sizes_square
   */
  template void 
  check_sizes_square<int>(const Nessi::Vector<int> & array1, 
			  const Nessi::Vector<int> & array2);
  
  /**
   * This is the unsigned integer declaration of the check_sizes_square 
   * function
   *
   * \ingroup check_sizes_square
   */
  template void 
  check_sizes_square<unsigned int>(const Nessi::Vector<unsigned int> & array1, 
				   const Nessi::Vector<unsigned int> & array2);
  
} // Utils
