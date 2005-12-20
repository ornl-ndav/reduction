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
			     Nessi::Vector<float> const & input1, 
			     Nessi::Vector<float> const & input2, 
			     Nessi::Vector<float> const & output);
  
  /**
   * This is the double declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<double>(std::string & errstr, 
			      Nessi::Vector<double> const & input1, 
			      Nessi::Vector<double> const & input2, 
			      Nessi::Vector<double> const & output);

  /**
   * This is the int declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<int>(std::string & errstr, 
			   Nessi::Vector<int> const & input1, 
			   Nessi::Vector<int> const & input2, 
			   Nessi::Vector<int> const & output);

  /**
   * This is the unsigned declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<unsigned>(std::string & errstr, 
				Nessi::Vector<unsigned> const & input1, 
				Nessi::Vector<unsigned> const & input2, 
				Nessi::Vector<unsigned> const & output);

} // ArrayManip
