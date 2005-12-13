/**
 * $Id$
 *
 * \file axis_manip/src/reverse_array_nc.cpp
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
  reverse_array_nc(std::vector<NumT> & inout,
		   void *temp=NULL)
  {
    std::string retstr("");

    reverse(inout.begin(), inout.end());
    
    return retstr;
  }

  // explicit instantiations

  /**
   * This is the float declaration for the function defined in 3.11.
   *
   * \see reverse_array_nc()
   */
  template std::string 
  reverse_array_nc<float>(std::vector<float> & inout,
			  void *temp);
  
  /**
   * This is the double precision float declaration for the function
   * defined in 3.11.
   *
   * \see reverse_array_nc()
   */
  template std::string 
  reverse_array_nc<double>(std::vector<double> & inout,
			   void *temp);
  
  /**
   * This is the integer declaration for the function defined in 3.11.
   *
   * \see reverse_array_nc()
   */
  template std::string 
  reverse_array_nc<int>(std::vector<int> & inout,
			void *temp);
  
  /**
   * This is the unsigned integer declaration for the function defined
   * in 3.11.
   *
   * \see reverse_array_nc()
   */
  template std::string 
  reverse_array_nc<unsigned int>(std::vector<unsigned int> & inout,
				 void *temp);
  
} // AxisManip
