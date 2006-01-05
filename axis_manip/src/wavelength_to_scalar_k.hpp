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
  wavelength_to_scalar_k(const Nessi::Vector<NumT> & wavelength,
			 const Nessi::Vector<NumT> & wavelength_err2,
			 Nessi::Vector<NumT> & wavevector,
			 Nessi::Vector<NumT> & wavevector_err2,
			 void *temp=NULL)
  {
    std::string retstr("");
    std::string warn;

    NumT a;
    NumT a2;

    warn = __wavelength_to_scalar_k_static(a, a2);
    
    if (warn.size() > 0)
      retstr += warn;
 
    size_t size_wavelength = wavelength.size();
    for (size_t i = 0 ; i < size_wavelength ; ++i)
      {
	warn = __wavelength_to_scalar_k_dynamic(wavelength[i], 
						wavelength_err2[i], 
						wavevector[i], 
						wavevector_err2[i], 
						a, a2);

	if (warn.size() > 0)
	  retstr += warn;
      }

    return retstr;
  }

  // 3.24
  template <typename NumT>
  std::string
  wavelength_to_scalar_k(const NumT wavelength,
			 const NumT wavelength_err2,
			 NumT & wavevector,
			 NumT & wavevector_err2,
			 void *temp=NULL)
  {
    std::string retstr("");
   std::string warn;

    NumT a;
    NumT a2;

    warn = __wavelength_to_scalar_k_static(a, a2);

    if (warn.size() > 0)
      retstr += warn;
    
    warn = __wavelength_to_scalar_k_dynamic(wavelength, wavelength_err2, 
					    wavevector, wavevector_err2, 
					    a, a2);

    if (warn.size() > 0)
      retstr += warn;
 
    return retstr;
  }
  
  /**
   * This is a PRIVATE helper function for wavelength_to_scalar_k that 
   * calculates the parameters invariant across the array calculation.
   */
  template <typename NumT>
  std::string
  __wavelength_to_scalar_k_static(NumT & a,
				  NumT & a2)
  {
    a = static_cast<NumT>(2. * PhysConst::PI);
    a2 = a * a;

    return std::string("");
  }

  /**
   * This is a PRIVATE helper function for wavelength_to_scalar_k that 
   * calculates the scalar_k and its uncertainty.
   */
  template <typename NumT>
  std::string
  __wavelength_to_scalar_k_dynamic(const NumT wavelength,
				   const NumT wavelength_err2,
				   NumT & wavevector,
				   NumT & wavevector_err2,
				   const NumT a,
				   const NumT a2)
  {
    wavevector = a / wavelength;
    wavevector_err2 = (a2 * wavelength_err2)
      / (wavelength * wavelength * wavelength * wavelength);
    
    return std::string("");
  }

} // AxisManip

#endif // _WAVELENGTH_TO_SCALAR_K_HPP
