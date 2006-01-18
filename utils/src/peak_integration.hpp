/**
 * $Id$
 *
 * \file utils/src/peak_integration.hpp
 */
#ifndef _PEAK_INTEGRATION_HPP
#define _PEAK_INTEGRATION_HPP 1

#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  // 3.35
  template <typename NumT>
  std::string
  peak_integration(const Nessi::Vector<NumT> & input,
                   const Nessi::Vector<NumT> & input_err2,
                   const Nessi::Vector<NumT> & start_bin,
                   NumT & output,
                   NumT & output_err2,
                   unsigned int & tag,
                   NumT & num_bins,
                   void *temp=NULL)
  {
    throw std::runtime_error("Function [peak_integration] not implemented");
  }
} // Utils

#endif // _PEAK_INTEGRATION_HPP
