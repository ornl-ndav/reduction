/**
 * $Id$
 *
 * \file array_manip/src/check_inputs.cpp
 */
#include "check_inputs.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace ArrayManip
{
  template <typename NumT>
  void check_sizes_2in1out(std::string & errstr, 
			   std::vector<NumT> const & input1, 
			   std::vector<NumT> const & input2, 
			   std::vector<NumT> const & output)
  {
    size_t szi1 = input1.size();
    size_t szi2 = input2.size();
    size_t szo = output.size();

    if (szi1 != szi2)
      {
	errstr += "input1 and input2 are not the same size";
	throw std::invalid_argument(errstr);
      }

    if (szi1 != szo)
      {
	errstr += "output not the same size as input1";
	throw std::invalid_argument(errstr);
      }

    if (szi2 != szo)
      {
	errstr += "output not the same size as input2";
	throw std::invalid_argument(errstr);
      }

    return;
  }
 
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
