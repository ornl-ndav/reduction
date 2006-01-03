/**
 * $Id$
 *
 * \file axis_manip/src/velocity_to_energy.hpp
 */
#ifndef _VELOCITY_TO_ENERGY
#define _VELOCITY_TO_ENERGY 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.21
  template <typename NumT>
  std::string
  velocity_to_energy(const Nessi::Vector<NumT> & velocity,
		     const Nessi::Vector<NumT> & velocity_err2,
		     Nessi::Vector<NumT> & energy,
		     Nessi::Vector<NumT> & energy_err2,
		     void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_energy] not implemented");
  }

  // 3.21
  template <typename NumT>
  std::string
  velocity_to_energy(const NumT velocity,
		     const NumT velocity_err2,
		     NumT & energy,
		     NumT & energy_err2,
		     void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_energy] not implemented");
  }
} // AxisManip
#endif
