/**
 * $Id$
 *
 * \file axis_manip/src/velocity_to_energy.hpp
 */
#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.21
  template <typename NumT>
  std::string
  velocity_to_energy(Nessi::Vector<NumT> const & velocity,
		     Nessi::Vector<NumT> const & velocity_err2,
		     Nessi::Vector<NumT> & energy,
		     Nessi::Vector<NumT> & energy_err2,
		     void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_energy] not implemented");
  }
} // AxisManip
