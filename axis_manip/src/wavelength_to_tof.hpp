/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_tof.hpp
 */
#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(Nessi::Vector<NumT> const & wavelength,
		    Nessi::Vector<NumT> const & wavelength_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    Nessi::Vector<NumT> & tof,
		    Nessi::Vector<NumT> & tof_err2,
		    void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_tof] not implemented");
  }
} // AxisManip
