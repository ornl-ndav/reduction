/**
 * $Id$
 *
 * \file axis_manip/src/frequency_to_angular_frequency.hpp
 */
#include "conversions.hpp"
#include <string>
#include <stdexcept>

namespace AxisManip
{
  // 3.31
  template <typename NumT>
  std::string
  frequency_to_angular_frequency(Nessi::Vector<NumT> const & frequency,
				 Nessi::Vector<NumT> const & frequency_err2,
				 Nessi::Vector<NumT> & angular_frequency,
				 Nessi::Vector<NumT> & angular_frequency_err2,
				 void *temp=NULL)
  {
    throw std::runtime_error("Function [frequency_to_angular_frequency] not implemented");
  }
} // AxisManip
