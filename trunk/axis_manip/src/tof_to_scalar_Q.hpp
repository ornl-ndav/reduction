/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_scalar_Q.hpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>

namespace AxisManip
{
  // 3.17
  template <typename NumT>
  std::string
  tof_to_scalar_Q(Nessi::Vector<NumT> const & tof,
		  Nessi::Vector<NumT> const & tof_err2,
		  const NumT pathlength,
		  const NumT pathlength_err2,
                  const NumT scatt_angle,
		  const NumT scatt_angle_err2,
		  Nessi::Vector<NumT> & Q,
		  Nessi::Vector<NumT> & Q_err2,
		  void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_scalar_Q] not implemented");    
  }
} // AxisManip
