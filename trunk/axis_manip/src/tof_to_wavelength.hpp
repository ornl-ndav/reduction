/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_wavelength.hpp
 */
#include "conversions.hpp"
#include "constants.hpp"
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.15
  template <typename NumT>
  std::string
  tof_to_wavelength(std::vector<NumT> const & tof,
		    std::vector<NumT> const & tof_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    std::vector<NumT> & wavelength,
		    std::vector<NumT> & wavelength_err2,
		    void *temp=NULL)
  {
    std::string retstr("");

    // calculate the factor to multiply each element by
    NumT a = static_cast<NumT>(PhysConst::H_OVER_MNEUT) / pathlength;
    // the result of these two lines is the uncertainty in the
    // multiplicative factor
    NumT a_err2 = static_cast<NumT>(PhysConst::H_OVER_MNEUT)/pathlength;
    a_err2=a_err2*a_err2*pathlength_err2;

    size_t sz = tof.size();
    for (size_t i = 0; i < sz; ++i)
      {
	wavelength[i] = a * tof[i];
	wavelength_err2[i] = ((a*a)*tof_err2[i]) + ((tof[i]*tof[i])*a_err2);
      }

    return retstr;
  }
} // AxisManip
