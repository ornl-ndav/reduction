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
			    const Nessi::Vector<float> & input1, 
			    const Nessi::Vector<float> & input2, 
			    const Nessi::Vector<float> & output);
  
  /**
   * This is the double declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<double>(std::string & errstr, 
			     const Nessi::Vector<double> & input1, 
			     const Nessi::Vector<double> & input2, 
			     const Nessi::Vector<double> & output);
  
  /**
   * This is the int declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<int>(std::string & errstr, 
			  const Nessi::Vector<int> & input1, 
			  const Nessi::Vector<int> & input2, 
			  const Nessi::Vector<int> & output);
  
  /**
   * This is the unsigned declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<unsigned>(std::string & errstr, 
			       const Nessi::Vector<unsigned> & input1, 
			       const Nessi::Vector<unsigned> & input2, 
			       const Nessi::Vector<unsigned> & output);
  
  /**
   * This is the float declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<float>(std::string & errstr, 
			    const Nessi::Vector<float> & input, 
			    const Nessi::Vector<float> & output);
  
  /**
   * This is the double declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<double>(std::string & errstr, 
			     const Nessi::Vector<double> & input, 
			     const Nessi::Vector<double> & output);
  
  /**
   * This is the int declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<int>(std::string & errstr, 
			  const Nessi::Vector<int> & input, 
			  const Nessi::Vector<int> & output);
  
  /**
   * This is the unsigned declaration of the check_sizes_square function
   *
   * \see check_sizes_square()
   */
  template void 
  check_sizes_square<unsigned>(std::string & errstr, 
			       const Nessi::Vector<unsigned> & input, 
			       const Nessi::Vector<unsigned> & output);
  
} // Utils
