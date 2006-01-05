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
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<float>(std::string & errstr, 
			    const Nessi::Vector<float> & array1, 
			    const Nessi::Vector<float> & array2, 
			    const Nessi::Vector<float> & array3);
  
  /**
   * This is the double declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<double>(std::string & errstr, 
			     const Nessi::Vector<double> & array1, 
			     const Nessi::Vector<double> & array2, 
			     const Nessi::Vector<double> & array3);
  
  /**
   * This is the int declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<int>(std::string & errstr, 
			  const Nessi::Vector<int> & array1, 
			  const Nessi::Vector<int> & array2, 
			  const Nessi::Vector<int> & array3);
  
  /**
   * This is the unsigned declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<unsigned>(std::string & errstr, 
			       const Nessi::Vector<unsigned> & array1, 
			       const Nessi::Vector<unsigned> & array2, 
			       const Nessi::Vector<unsigned> & array3);
  
  /**
   * This is the float declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<float>(std::string & errstr, 
			    const Nessi::Vector<float> & array1, 
			    const Nessi::Vector<float> & array2);
  
  /**
   * This is the double declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<double>(std::string & errstr, 
			     const Nessi::Vector<double> & array1, 
			     const Nessi::Vector<double> & array2);
  
  /**
   * This is the int declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<int>(std::string & errstr, 
			  const Nessi::Vector<int> & array1, 
			  const Nessi::Vector<int> & array2);
  
  /**
   * This is the unsigned declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<unsigned>(std::string & errstr, 
			       const Nessi::Vector<unsigned> & array1, 
			       const Nessi::Vector<unsigned> & array2);
  
} // Utils
