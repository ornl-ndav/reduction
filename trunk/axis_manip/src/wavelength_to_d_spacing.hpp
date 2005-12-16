/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_d_spacing.hpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.25
  template <typename NumT>
  std::string
  wavelength_to_d_spacing(std::vector<NumT> const & wavelength,
			  std::vector<NumT> const & wavelength_err2,
			  const NumT scatt_angle,
			  const NumT scatt_angle_err2,
			  std::vector<NumT> & d_spacing,
			  std::vector<NumT> & d_spacing_err2,
			  void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_d_spacing] not implemented");
  }
} // AxisManip
