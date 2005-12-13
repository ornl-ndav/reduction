/**
 * $Id$
 *
 * \file array_manip/inc/check_inputs.hpp
 */
#ifndef _CHECK_INPUTS_H
#define _CHECK_INPUTS_H 1

#include <string>
#include <vector>

namespace ArrayManip
{
  /**
   * \brief This function checks input and output vectors for correct sizes.
   *
   * This function checks the sizes of two input vector and one output vector 
   * for consistant sizes. If the vectors do not have consistent sizes, an 
   * exception is thrown. 
   *
   * \param errstr (INPUT/OUTPUT) is a string containing the calling function. 
   * errstr is also used as a thrown exception if the vectors are not of 
   * consistent sizes.
   * \param input1 (INPUT) is an incoming vector that needs size checking
   * \param input2 (INPUT) is an incoming vector that needs size checking
   * \param output (OUTPUT) is an output vector that needs size checking
   */
  template <typename NumT>
    void check_sizes_2in1out(std::string & errstr, 
			     std::vector<NumT> const & input1, 
			     std::vector<NumT> const & input2, 
			     std::vector<NumT> const & output);
			      
} // ArrayManip

#endif // _CHECK_INPUTS_H
