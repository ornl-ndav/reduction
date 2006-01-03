/**
 * $Id$
 *
 * \file axis_manip/src/final_velocity_igs.hpp
 */
#ifndef _FINAL_VELOCITY_IGS_HPP
#define _FINAL_VELOCITY_IGS_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip 
{
  // 3.20
  template <typename NumT>
  std::string
  final_velocity_igs(const NumT analyzer_wavelength,
		     const NumT analyzer_wavelength_err2,
		     NumT & final_velocity,
		     NumT & final_velocity_err2,
		     void *temp=NULL)
  {
    throw std::runtime_error("Function [final_velocity_igs] not implemented");
  }
} // AxisManip
#endif
