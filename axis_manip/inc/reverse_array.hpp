/**
 * $Id$
 *
 * \file axis_manip/inc/reverse_array.hpp
 */
#ifndef _REVERSE_ARRAY_H
#define _REVERSE_ARRAY_H 1

#include <string>
#include <vector>

namespace AxisManip
{
  /**
   * \brief This function is described in section 3.11.
   *
   * This function will reorder an array so the last element of the
   * supplied array is the first element of the result array.
   *
   * \param input (INPUT) is the array to be reversed
   * \param output (OUTPUT) is the reversed array
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    reverse_array_cp(std::vector<NumT> const & input,
		  std::vector<NumT> & output,
		  void *temp=NULL);

  /**
   * \brief This function is not described but is based on section 3.11.
   *  
   * This function will reorder an array so the last element of the
   * supplied array is the first element of the supplied array. This array 
   * reversal is done in place on the supplied array (i.e. no copy).
   *
   * \param inout (INPUT/OUTPUT) is the array to be reversed. It also is the 
   * place holder for the reversed array.
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    reverse_array_nc(std::vector<NumT> & inout,
		     void *temp=NULL);
  
} // AxisManip

#endif // _REVERSE_ARRAY_H
