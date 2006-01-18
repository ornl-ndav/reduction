/**
 * $Id$
 *
 * \file axis_manip/src/velocity_to_scalar_k.hpp
 */
#ifndef _VELOCITY_TO_SCALAR_K_HPP
#define _VELOCITY_TO_SCALAR_K_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.23
  template <typename NumT>
  std::string
  velocity_to_scalar_k(const Nessi::Vector<NumT> & velocity,
                       const Nessi::Vector<NumT> & velocity_err2,
                       Nessi::Vector<NumT> & wavevector,
                       Nessi::Vector<NumT> & wavevector_err2,
                       void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_scalar_k] not implemented");
  }

  // 3.23
  template <typename NumT>
  std::string
  velocity_to_scalar_k(const NumT velocity,
                       const NumT velocity_err2,
                       NumT & wavevector,
                       NumT & wavevector_err2,
                       void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_scalar_k] not implemented");
  }
} // AxisManip

#endif // _VELOCITY_TO_SCALAR_K_HPP
