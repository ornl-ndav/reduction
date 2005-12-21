/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_d_spacing.hpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>

namespace AxisManip
{
  // 3.25
  template <typename NumT>
  std::string
  wavelength_to_d_spacing(Nessi::Vector<NumT> const & wavelength,
			  Nessi::Vector<NumT> const & wavelength_err2,
			  const NumT scatt_angle,
			  const NumT scatt_angle_err2,
			  Nessi::Vector<NumT> & d_spacing,
			  Nessi::Vector<NumT> & d_spacing_err2,
			  void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_d_spacing] not implemented");
  }
} // AxisManip
