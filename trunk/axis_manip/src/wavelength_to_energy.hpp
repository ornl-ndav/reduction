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
  wavelength_to_energy(Nessi::Vector<NumT> const & wavelength,
		       Nessi::Vector<NumT> const & wavelength_err2,
		       Nessi::Vector<NumT> & energy,
		       Nessi::Vector<NumT> & energy_err2,
		       void *temp=NULL)
  {
    std::string retstr("");
    
    NumT a2 = 4 * static_cast<NumT>(PhysConst::H2_OVER_2MNEUT) * 
      static_cast<NumT>(PhysConst::H2_OVER_2MNEUT);

    size_t sz = wavelength.size();
    for (size_t i = 0; i < sz; ++i)
      {
	NumT wavelength2 = wavelength[i] * wavelength[i];
        energy[i] = static_cast<NumT>(PhysConst::H2_OVER_2MNEUT) / wavelength2;
	energy_err2[i] = (a2 * wavelength_err2[i]) / (wavelength2 * wavelength2 * wavelength2);
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
    
    NumT a2 = 4 * static_cast<NumT>(PhysConst::H2_OVER_2MNEUT) * 
      static_cast<NumT>(PhysConst::H2_OVER_2MNEUT);

    NumT wavelength2 = wavelength * wavelength;

    energy = static_cast<NumT>(PhysConst::H2_OVER_2MNEUT) / wavelength2;
    energy_err2 = (a2 * wavelength_err2)
      / (wavelength2 * wavelength2 * wavelength2);

    return retstr;
  }
} // AxisManip
#endif
