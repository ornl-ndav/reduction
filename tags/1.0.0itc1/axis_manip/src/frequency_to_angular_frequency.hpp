/**
 * $Id$
 *
 * \file axis_manip/src/frequency_to_angular_frequency.hpp
 */
#ifndef _FREQUENCY_TO_ANGULAR_FREQUENCY_HPP
#define _FREQUENCY_TO_ANGULAR_FREQUENCY_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.31
  template <typename NumT>
  std::string
  frequency_to_angular_frequency(const Nessi::Vector<NumT> & frequency,
				 const Nessi::Vector<NumT> & frequency_err2,
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

#endif // _FREQUENCY_TO_ANGULAR_FREQUENCY_HPP
