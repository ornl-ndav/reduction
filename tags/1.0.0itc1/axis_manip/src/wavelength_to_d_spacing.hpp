/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_d_spacing.hpp
 */
#ifndef _WAVELENGTH_TO_D_SPACING_HPP
#define _WAVELENGTH_TO_D_SPACING_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.25
  template <typename NumT>
  std::string
  wavelength_to_d_spacing(const Nessi::Vector<NumT> & wavelength,
			  const Nessi::Vector<NumT> & wavelength_err2,
			  const NumT scatt_angle,
			  const NumT scatt_angle_err2,
			  Nessi::Vector<NumT> & d_spacing,
			  Nessi::Vector<NumT> & d_spacing_err2,
			  void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_d_spacing] not implemented");
  }

  // 3.25
  template <typename NumT>
  std::string
  wavelength_to_d_spacing(const NumT wavelength,
			  const NumT wavelength_err2,
			  const NumT scatt_angle,
			  const NumT scatt_angle_err2,
			  NumT & d_spacing,
			  NumT & d_spacing_err2,
			  void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_d_spacing] not implemented");
  }
} // AxisManip

#endif // _WAVELENGTH_TO_D_SPACING_HPP
