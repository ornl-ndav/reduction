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
    std::string retstr("");

    // VARIABLES WITH BAD NAMES: a, a2, b, c

    NumT a = static_cast<NumT>(1. / (PhysConst::H_OVER_MNEUT));
    NumT a2 = a * a;
    a = a * pathlength;
    
    NumT b = pathlength * pathlength;
    
    NumT c = pathlength_err2 * pathlength_err2;
    
    size_t size_wavelength = wavelength.size();
    for (size_t i = 0; i < size_wavelength ; ++i)
      {
	tof[i] = a * wavelength[i];
	tof_err2[i] = wavelength[i] * wavelength[i] * c;
	tof_err2[i] += b * (wavelength_err2[i] * wavelength_err2[i]);
        tof_err2[i] *= a2;
      }
    
    return retstr;
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
    std::string retstr("");

    // VARIABLES WITH BAD NAMES: a, a2, b, c

    NumT a = static_cast<NumT>(1. / (PhysConst::H_OVER_MNEUT));
    NumT a2 = a * a;
    a = a * pathlength;
    
    NumT b = pathlength * pathlength;
    
    NumT c = pathlength_err2 * pathlength_err2;
    
    tof = a * wavelength;
    tof_err2 = wavelength * wavelength * c;
    tof_err2 += b * (wavelength_err2 * wavelength_err2);
    tof_err2 *= a2;
    
    return retstr;
  }
} // AxisManip
#endif
