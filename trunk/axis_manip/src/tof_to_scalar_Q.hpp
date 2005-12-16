/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_scalar_Q.hpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.17
  template <typename NumT>
  std::string
  tof_to_scalar_Q(std::vector<NumT> const & tof,
		  std::vector<NumT> const & tof_err2,
		  const NumT pathlength,
		  const NumT pathlength_err2,
                  const NumT scatt_angle,
		  const NumT scatt_angle_err2,
		  std::vector<NumT> & Q,
		  std::vector<NumT> & Q_err2,
		  void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_scalar_Q] not implemented");    
  }
} // AxisManip
