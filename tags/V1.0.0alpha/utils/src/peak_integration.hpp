/**
 * $Id: $
 *
 * \file utils/src/peak_integration.hpp
 */
#include "utils.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace Utils
{
  // 3.35
  template <typename NumT>
  std::string
  peak_integration(std::vector<NumT> const & input,
		   std::vector<NumT> const & input_err2,
		   std::vector<NumT> const & start_bin,
		   NumT & output,
		   NumT & output_err2,
                   unsigned int & tag,
		   NumT & num_bins,
		   void *temp=NULL)
  {
    throw std::runtime_error("Function [peak_integration] not implemented");
  }
} // Utils
