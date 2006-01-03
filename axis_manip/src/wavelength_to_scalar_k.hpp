/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_k.hpp
 */
#ifndef _WAVELENGTH_TO_SCALAR_K_HPP
#define _WAVELENGTH_TO_SCALAR_K_HPP 1

#include "conversions.hpp"
#include "constants.hpp"

namespace AxisManip
{
  // 3.24
  template <typename NumT>
  std::string
  wavelength_to_scalar_k(Nessi::Vector<NumT> const & wavelength,
			 Nessi::Vector<NumT> const & wavelength_err2,
			 Nessi::Vector<NumT> & wavevector,
			 Nessi::Vector<NumT> & wavevector_err2,
			 void *temp=NULL)
  {
    // VARIABLES WITH BAD NAMES: a, a2

    NumT a = 2 * static_cast<NumT>(PhysConst::PI);
    NumT a2 = a * a;
    
    size_t size_wavelength = wavelength.size();
    for (size_t i = 0 ; i < size_wavelength ; ++i)
      {
        wavevector[i] = a / wavelength[i];
        wavevector_err2[i] = (a2 * wavelength_err2[i]) / 
	  (wavelength[i] * wavelength[i] * wavelength[i] * wavelength[i]);
      }

    std::string retstr("");
    return retstr;
  }
} // AxisManip
#endif
