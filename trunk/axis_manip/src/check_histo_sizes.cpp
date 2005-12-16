/**
 * $Id$
 *
 * \file axis_manip/src/check_histo.cpp
 */
#include "check_histo.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  template <typename NumT>
  void 
  check_histo_sizes(std::string & errstr,
		    std::vector<NumT> const & input,
		    std::vector<NumT> const & input_err2,
		    std::vector<NumT> const & axis)
  {
    size_t szi1 = input.size();
    size_t szie1 = input_err2.size();
    size_t szai = axis.size();

    if (szi1 != szie1)
      {
	errstr += "input and input_err2 are not the same size";
	throw std::invalid_argument(errstr);
      }

    if(szai != szi1+1)
      {
	errstr += "axis size is not input size + 1";
	throw std::invalid_argument(errstr);
      }

    if(szai != szie1+1)
      {
	errstr += "axis size is not input_err2 size + 1";
	throw std::invalid_argument(errstr);
      }

    return;
  }

  // explicit instantiations

  /**
   * This is the float declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<float>(std::string & errstr,
			   std::vector<float> const & input,
			   std::vector<float> const & input_err2,
			   std::vector<float> const & axis);

  /**
   * This is the double declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<double>(std::string & errstr,
			    std::vector<double> const & input,
			    std::vector<double> const & input_err2,
			    std::vector<double> const & axis);

  /**
   * This is the int declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<int>(std::string & errstr,
			 std::vector<int> const & input,
			 std::vector<int> const & input_err2,
			 std::vector<int> const & axis);
  
  /**
   * This is the unsigned declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<unsigned>(std::string & errstr,
			      std::vector<unsigned> const & input,
			      std::vector<unsigned> const & input_err2,
			      std::vector<unsigned> const & axis); 

} // AxisManip
