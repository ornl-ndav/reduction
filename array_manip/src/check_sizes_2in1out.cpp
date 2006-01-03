/**
 * $Id$
 *
 * \file array_manip/src/check_sizes_2in1out.cpp
 */
#include "check_sizes_2in1out.hpp"

namespace ArrayManip
{
 // explicit instantiations

  /**
   * This is the float declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<float>(std::string & errstr, 
			     const Nessi::Vector<float> & input1, 
			     const Nessi::Vector<float> & input2, 
			     const Nessi::Vector<float> & output);
  
  /**
   * This is the double declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<double>(std::string & errstr, 
			      const Nessi::Vector<double> & input1, 
			      const Nessi::Vector<double> & input2, 
			      const Nessi::Vector<double> & output);

  /**
   * This is the int declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<int>(std::string & errstr, 
			   const Nessi::Vector<int> & input1, 
			   const Nessi::Vector<int> & input2, 
			   const Nessi::Vector<int> & output);

  /**
   * This is the unsigned declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<unsigned>(std::string & errstr, 
				const Nessi::Vector<unsigned> & input1, 
				const Nessi::Vector<unsigned> & input2, 
				const Nessi::Vector<unsigned> & output);

} // ArrayManip
