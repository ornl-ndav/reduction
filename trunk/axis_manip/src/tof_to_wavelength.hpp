/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_wavelength.hpp
 */
#include "conversions.hpp"
#include "constants.hpp"

namespace AxisManip
{
  // 3.15
  template <typename NumT>
  std::string
  tof_to_wavelength(Nessi::Vector<NumT> const & tof,
		    Nessi::Vector<NumT> const & tof_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    Nessi::Vector<NumT> & wavelength,
		    Nessi::Vector<NumT> & wavelength_err2,
		    void *temp=NULL)
  {
    // VARIABLES WITH BAD NAMES: a, a2, a_err2

    // calculate the factor to multiply each element by
    NumT a = static_cast<NumT>(PhysConst::H_OVER_MNEUT) / pathlength;
    NumT a2 = a*a;
    // the result of these two lines is the uncertainty in the
    // multiplicative factor
    NumT a_err2 = static_cast<NumT>(PhysConst::H_OVER_MNEUT)/pathlength;
    a_err2=a_err2*a_err2*pathlength_err2;

    size_t size_tof = tof.size();
    for (size_t i = 0; i < size_tof; ++i)
      {
	wavelength[i] = a * tof[i];
	wavelength_err2[i] = (a2*tof_err2[i]) + ((tof[i]*tof[i])*a_err2);
      }

    std::string retstr("");
    return retstr;
  }
} // AxisManip
