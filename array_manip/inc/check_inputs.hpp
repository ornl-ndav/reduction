/**
 * $Id$
 *
 * \file array_manip/inc/check_inputs.hpp
 */
#ifndef _CHECK_INPUTS_HPP
#define _CHECK_INPUTS_HPP 1

#include "nessi.hpp"
#include <string>

namespace ArrayManip
{
  /**
   * \brief This function checks input and output vectors for correct sizes.
   *
   * This function checks the sizes of two input vector and one output vector 
   * for consistant sizes. If the vectors do not have consistent sizes, an 
   * exception is thrown. 
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param errstr (INPUT/OUTPUT) is a string containing the calling function. 
   * errstr is also used as a thrown exception if the vectors are not of 
   * consistent sizes.
   * \param input1 (INPUT) is an incoming vector that needs size checking
   * \param input2 (INPUT) is an incoming vector that needs size checking
   * \param output (INPUT) is an output vector that needs size checking
   */
  template <typename NumT>
    void check_sizes_2in1out(std::string & errstr, 
			     Nessi::Vector<NumT> const & input1, 
			     Nessi::Vector<NumT> const & input2, 
			     Nessi::Vector<NumT> const & output);
} // ArrayManip

#endif // _CHECK_INPUTS_HPP
