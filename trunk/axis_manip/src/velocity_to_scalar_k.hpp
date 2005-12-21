/**
 * $Id$
 *
 * \file axis_manip/src/velocity_to_scalar_k.hpp
 */
#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.23
  template <typename NumT>
  std::string
  velocity_to_scalar_k(Nessi::Vector<NumT> const & velocity,
		       Nessi::Vector<NumT> const & velocity_err2,
		       Nessi::Vector<NumT> & wavevector,
		       Nessi::Vector<NumT> & wavevector_err2,
		       void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_scalar_k] not implemented");
  }
} // AxisManip
