/**
 * $Id$
 *
 * \file axis_manip/src/frequency_to_angular_frequency.hpp
 */
#include "conversions.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.31
  template <typename NumT>
  std::string
  frequency_to_angular_frequency(std::vector<NumT> const & frequency,
				 std::vector<NumT> const & frequency_err2,
				 std::vector<NumT> & angular_frequency,
				 std::vector<NumT> & angular_frequency_err2,
				 void *temp=NULL)
  {
    throw std::runtime_error("Function [frequency_to_angular_frequency] not implemented");
  }
} // AxisManip
