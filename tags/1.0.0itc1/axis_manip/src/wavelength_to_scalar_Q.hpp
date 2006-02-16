/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_Q.hpp
 */
#ifndef _WAVELENGTH_TO_SCALAR_Q_HPP
#define _WAVELENGTH_TO_SCALAR_Q_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.18
  template <typename NumT>
  std::string
  wavelength_to_scalar_Q(const Nessi::Vector<NumT> & wavelength,
			 const Nessi::Vector<NumT> & wavelength_err2,
			 const NumT scatt_angle,
			 const NumT scatt_angle_err2,
			 Nessi::Vector<NumT> & Q,
			 Nessi::Vector<NumT> & Q_err2,
			 void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_scalar_Q] not implemented");
  }

  // 3.18
  template <typename NumT>
  std::string
  wavelength_to_scalar_Q(const NumT wavelength,
			 const NumT wavelength_err2,
			 const NumT scatt_angle,
			 const NumT scatt_angle_err2,
			 NumT & Q,
			 NumT & Q_err2,
			 void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_scalar_Q] not implemented");
  }
} // AxisManip

#endif // _WAVELENGTH_TO_SCALAR_Q_HPP