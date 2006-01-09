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
   * \defgroup check_sizes_square Utils::check_sizes_square
   * \{
   */

  /**
   * \brief This function checks three vectors for consistent sizes.
   *
   * This function checks the sizes of three vector for consistent sizes. 
   * If the vectors do not have consistent sizes, an exception is thrown. 
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param errstr (INPUT/OUTPUT) is a string containing the calling function. 
   * errstr is also used as a thrown exception if the vectors are not of 
   * consistent sizes.
   * \param array1 (INPUT) is a vector that needs size checking
   * \param array2 (INPUT) is a vector that needs size checking
   * \param array3 (INPUT) is a vector that needs size checking
   */
  template <typename NumT>
    void check_sizes_square(std::string & errstr, 
			    const Nessi::Vector<NumT> & array1, 
			    const Nessi::Vector<NumT> & array2, 
			    const Nessi::Vector<NumT> & array3);

  /**
   * \brief This function checks two vectors for consistent sizes.
   *
   * This function checks the sizes of two vectors for consistent sizes. 
   * If the vectors do not have consistent sizes, an exception is thrown. 
   *
   * \param errstr (INPUT/OUTPUT) is a string containing the calling function. 
   * errstr is also used as a thrown exception if the vectors are not of 
   * consistent sizes.
   * \param array1 (INPUT) is a vector that needs size checking
   * \param array2 (INPUT) is a vector that needs size checking
   */
  template <typename NumT>
    void check_sizes_square(std::string & errstr, 
			    const Nessi::Vector<NumT> & array1, 
			    const Nessi::Vector<NumT> & array2);

  /**
   * \}
   */ // end of check_sizes_square group

  /**
   * \defgroup check_histo_sizes Utils::check_histo_sizes
   * \{
   */

  /**
   * \brief This function checks data, error2 and axis vectors for 
   * consistent sizes.
   *
   * This function checks the sizes of data, error2 and an axis vector for 
   * the correct sizes in terms of a histogram model. The data and error2 
   * vectors should be one element shorter than the axis vector. If the 
   * vectors have inconsistent sizes, an exception is thrown.
   *
   * \param errstr (INPUT/OUTPUT) is a string containing the calling function. 
   * errstr is also used as a thrown exception if the vectors are not of 
   * consistent sizes.
   * \param input (INPUT) is the histogram data
   * \param input_err2 (INPUT) is the histogram uncertainty squared
   * \param axis (INPUT) is the histogram axis
   *
   */
  template <typename NumT>
  void check_histo_sizes(std::string & errstr,
                         const Nessi::Vector<NumT> & input,
                         const Nessi::Vector<NumT> & input_err2,
                         const Nessi::Vector<NumT> & axis);

  /**
   * \}
   */ // end of check_histo_sizes group

} // Utils

#endif // _SIZE_CHECKS_HPP
