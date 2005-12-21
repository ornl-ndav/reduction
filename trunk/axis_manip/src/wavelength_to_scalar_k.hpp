/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_k.hpp
 */
#include "conversions.hpp"
#include "constants.hpp"
#include <string>

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
    std::string retstr("");

    NumT a = 2 * static_cast<NumT>(PhysConst::PI);
    NumT a2 = a * a;
    
    size_t sz = wavelength.size();
    for (size_t i = 0; i < sz; ++i)
      {
        wavevector[i] = a / wavelength[i];
        wavevector_err2[i] = (a2 * wavelength_err2[i]) / 
	  (wavelength[i] * wavelength[i] * wavelength[i] * wavelength[i]);
      }

    return retstr;
  }
} // AxisManip
