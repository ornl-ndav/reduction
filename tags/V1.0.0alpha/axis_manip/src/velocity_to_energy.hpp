/**
 * $Id$
 *
 * \file axis_manip/src/velocity_to_energy.hpp
 */
#include "conversions.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.21
  template <typename NumT>
  std::string
  velocity_to_energy(std::vector<NumT> const & velocity,
		     std::vector<NumT> const & velocity_err2,
		     std::vector<NumT> & energy,
		     std::vector<NumT> & energy_err2,
		     void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_energy] not implemented");
  }
} // AxisManip
