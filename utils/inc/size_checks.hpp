/**
 * $Id$
 *
 * \file utils/inc/size_checks.hpp
 */
#ifndef _SIZE_CHECKS_HPP
#define _SIZE_CHECKS_HPP 1

#include "nessi.hpp"
#include <string>

namespace Utils
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
    void check_sizes_square(std::string & errstr, 
			    const Nessi::Vector<NumT> & input1, 
			    const Nessi::Vector<NumT> & input2, 
			    const Nessi::Vector<NumT> & output);

  /**
   * \brief This function checks input and output vectors for correct sizes.
   *
   * This function checks the sizes of one input vector and one output vector 
   * for consistant sizes. If the vectors do not have consistent sizes, an 
   * exception is thrown. 
   *
   * \param errstr (INPUT/OUTPUT) is a string containing the calling function. 
   * errstr is also used as a thrown exception if the vectors are not of 
   * consistent sizes.
   * \param input (INPUT) is an incoming vector that needs size checking
   * \param output (INPUT) is an output vector that needs size checking
   */
  template <typename NumT>
    void check_sizes_square(std::string & errstr, 
			    const Nessi::Vector<NumT> & input, 
			    const Nessi::Vector<NumT> & output);
} // Utils

#endif // _SIZE_CHECKS_HPP
