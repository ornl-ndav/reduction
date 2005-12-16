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
			     std::vector<float> const & input1, 
			     std::vector<float> const & input2, 
			     std::vector<float> const & output);
  
  /**
   * This is the double declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<double>(std::string & errstr, 
			      std::vector<double> const & input1, 
			      std::vector<double> const & input2, 
			      std::vector<double> const & output);

  /**
   * This is the int declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<int>(std::string & errstr, 
			   std::vector<int> const & input1, 
			   std::vector<int> const & input2, 
			   std::vector<int> const & output);

  /**
   * This is the unsigned declaration of the check_sizes_2in1out function
   *
   * \see check_sizes_2in1out()
   */
  template void 
  check_sizes_2in1out<unsigned>(std::string & errstr, 
				std::vector<unsigned> const & input1, 
				std::vector<unsigned> const & input2, 
				std::vector<unsigned> const & output);

} // ArrayManip
