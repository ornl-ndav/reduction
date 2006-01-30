/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_tof.hpp
 */
#ifndef _WAVELENGTH_TO_TOF_HPP
#define _WAVELENGTH_TO_TOF_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(const Nessi::Vector<NumT> & wavelength,
		    const Nessi::Vector<NumT> & wavelength_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    Nessi::Vector<NumT> & tof,
		    Nessi::Vector<NumT> & tof_err2,
		    void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_tof] not implemented");
  }

  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(const NumT wavelength,
		    const NumT wavelength_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    NumT & tof,
		    NumT & tof_err2,
		    void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_tof] not implemented");
  }
} // AxisManip

#endif // _WAVELENGTH_TO_TOF_HPP
