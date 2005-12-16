/**
 * $Id$
 *
 * \file axis_manip/src/reverse_array_cp.cpp
 */
#include "reverse_array.hpp"
#include <algorithm>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.11
  template <typename NumT>
  std::string 
  reverse_array_cp(std::vector<NumT> const & input,
		std::vector<NumT> & output,
		void *temp=NULL)
  {
    std::string retstr("");

    reverse_copy(input.begin(), input.end(), output.begin());
    
    return retstr;
  }

  // explicit instantiations

  /**
   * This is the float declaration for the function defined in 3.11.
   *
   * \see reverse_array_cp()
   */
  template std::string 
  reverse_array_cp<float>(std::vector<float> const & input,
		       std::vector<float> & output,
		       void *temp);
  
  /**
   * This is the double precision float declaration for the function
   * defined in 3.11.
   *
   * \see reverse_array_cp()
   */
  template std::string 
  reverse_array_cp<double>(std::vector<double> const & input,
			std::vector<double> & output,
			void *temp);
  
  /**
   * This is the integer declaration for the function defined in 3.11.
   *
   * \see reverse_array_cp()
   */
  template std::string 
  reverse_array_cp<int>(std::vector<int> const & input,
		     std::vector<int> & output,
		     void *temp);
  
  /**
   * This is the unsigned integer declaration for the function defined
   * in 3.11.
   *
   * \see reverse_array_cp()
   */
  template std::string 
  reverse_array_cp<unsigned int>(std::vector<unsigned int> const & input,
                              std::vector<unsigned int> & output,
                              void *temp);
  
} // AxisManip
