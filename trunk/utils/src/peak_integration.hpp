/**
 * $Id$
 *
 * \file utils/src/peak_integration.hpp
 */
#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  // 3.35
  template <typename NumT>
  std::string
  peak_integration(Nessi::Vector<NumT> const & input,
		   Nessi::Vector<NumT> const & input_err2,
		   Nessi::Vector<NumT> const & start_bin,
		   NumT & output,
		   NumT & output_err2,
                   unsigned int & tag,
		   NumT & num_bins,
		   void *temp=NULL)
  {
    throw std::runtime_error("Function [peak_integration] not implemented");
  }
} // Utils
