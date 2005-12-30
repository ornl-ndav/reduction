/**
 * $Id$
 *
 * \file axis_manip/src/frequency_to_angular_frequency.hpp
 */
#include "conversions.hpp"
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

  // 3.31
  template <typename NumT>
  std::string
  frequency_to_angular_frequency(const NumT frequency,
				 const NumT frequency_err2,
				 NumT & angular_frequency,
				 NumT & angular_frequency_err2,
				 void *temp=NULL)
  {
    throw std::runtime_error("Function [frequency_to_angular_frequency] not implemented");
  }
} // AxisManip
