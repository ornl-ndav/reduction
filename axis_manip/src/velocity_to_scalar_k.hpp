/**
 * $Id$
 *
 * \file axis_manip/src/velocity_to_scalar_k.hpp
 */
#include "conversions.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.23
  template <typename NumT>
  std::string
  velocity_to_scalar_k(std::vector<NumT> const & velocity,
		       std::vector<NumT> const & velocity_err2,
		       std::vector<NumT> & wavevector,
		       std::vector<NumT> & wavevector_err2,
		       void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_scalar_k] not implemented");
  }
} // AxisManip
