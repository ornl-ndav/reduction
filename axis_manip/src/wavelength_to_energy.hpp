/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_energy.hpp
 */
#ifndef _WAVELENGTH_TO_ENERGY_HPP
#define _WAVELENGTH_TO_ENERGY_HPP 1

#include "conversions.hpp"
#include "constants.hpp"

namespace AxisManip
{
  // 3.22
  template <typename NumT>
  std::string
  wavelength_to_energy(const Nessi::Vector<NumT> & wavelength,
		       const Nessi::Vector<NumT> & wavelength_err2,
		       Nessi::Vector<NumT> & energy,
		       Nessi::Vector<NumT> & energy_err2,
		       void *temp=NULL)
  {
    std::string retstr("");
    std::string warn;

    NumT a2;

    warn = __wavelength_to_energy_static(a2);

    if (warn.size() > 0)
      retstr += warn;

    size_t sz = wavelength.size();
    for (size_t i = 0; i < sz; ++i)
      {
	warn = __wavelength_to_energy_dynamic(wavelength[i], 
					      wavelength_err2[i],
					      energy[i], 
					      energy_err2[i], 
					      a2);

	if (warn.size() > 0)
	  retstr += warn;
      }

    return retstr;
  }

  // 3.22
  template <typename NumT>
  std::string
  wavelength_to_energy(const NumT wavelength,
		       const NumT wavelength_err2,
		       NumT & energy,
		       NumT & energy_err2,
		       void *temp=NULL)
  {
    std::string retstr("");
    std::string warn;

    NumT a2;

    warn = __wavelength_to_energy_static(a2);

    if (warn.size() > 0)
      retstr += warn;

    warn = __wavelength_to_energy_dynamic(wavelength,wavelength_err2,
					  energy, energy_err2, a2);

    if (warn.size() > 0)
      retstr += warn;

    return retstr;
  }

  /**
   * This is a PRIVATE helper function for wavelength_to_energy that 
   * calculates the parameters invariant across the array calculation.
   */
  template <typename NumT>
  std::string
  __wavelength_to_energy_static(NumT & a2)
  {
    a2 = static_cast<NumT>(4. * PhysConst::H2_OVER_2MNEUT * 
			   PhysConst::H2_OVER_2MNEUT);
    return std::string("");
  }

  /**
   * This is a PRIVATE helper function for wavelength_to_energy that 
   * calculates the energy and its uncertainty.
   */
  template <typename NumT>
  std::string
  __wavelength_to_energy_dynamic(const NumT wavelength,
				 const NumT wavelength_err2,
				 NumT energy,
				 NumT energy_err2,
				 const NumT a2)
  {
    NumT wavelength2 = wavelength * wavelength;
    
    energy = static_cast<NumT>(PhysConst::H2_OVER_2MNEUT / wavelength2);
    energy_err2 = (a2 * wavelength_err2)
      / (wavelength2 * wavelength2 * wavelength2);

    return std::string("");
  }

} // AxisManip

#endif // _WAVELENGTH_TO_ENERGY_HPP
