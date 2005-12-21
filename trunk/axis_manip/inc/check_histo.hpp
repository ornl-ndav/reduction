/**
 * $Id$
 *
 * \file axis_manip/inc/check_histo.hpp
 */
#ifndef _CHECK_HISTO_H
#define _CHECK_HISTO_H 1

#include "nessi.hpp"
#include <string>

namespace AxisManip
{
  /**
   * \brief This function checks data, error2 and axis vectors for correct sizes.
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
			 Nessi::Vector<NumT> const & input,
			 Nessi::Vector<NumT> const & input_err2,
			 Nessi::Vector<NumT> const & axis);
  
} // AxisManip

#endif // _CHECK_HISTO_H
