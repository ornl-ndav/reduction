/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_tof.hpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(std::vector<NumT> const & wavelength,
		    std::vector<NumT> const & wavelength_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    std::vector<NumT> & tof,
		    std::vector<NumT> & tof_err2,
		    void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_tof] not implemented");
  }
} // AxisManip
