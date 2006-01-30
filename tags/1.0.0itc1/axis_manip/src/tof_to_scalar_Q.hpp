/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_scalar_Q.hpp
 */
#ifndef _TOF_TO_SCALAR_Q_HPP
#define _TOF_TO_SCALAR_Q_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include <cmath>
#include <stdexcept>

namespace AxisManip
{
  // 3.17
  template <typename NumT>
  std::string
  tof_to_scalar_Q(const Nessi::Vector<NumT> & tof,
		  const Nessi::Vector<NumT> & tof_err2,
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

  // 3.17
  template <typename NumT>
  std::string
  tof_to_scalar_Q(const NumT tof,
		  const NumT tof_err2,
		  const NumT pathlength,
		  const NumT pathlength_err2,
                  const NumT scatt_angle,
		  const NumT scatt_angle_err2,
		  NumT & Q,
		  NumT & Q_err2,
		  void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_scalar_Q] not implemented");
  }
} // AxisManip

#endif // _TOF_TO_SCALAR_Q_HPP
