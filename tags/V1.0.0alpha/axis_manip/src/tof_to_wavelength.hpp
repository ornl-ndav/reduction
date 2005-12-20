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

    NumT a = static_cast<NumT>(PhysConst::H_OVER_MNEUT) / pathlength;
    NumT a2 = a * a;

    size_t sz = tof.size();
    for (size_t i = 0; i < sz; ++i)
      {
	wavelength[i] = a * tof[i];
	wavelength_err2[i] = a2 * tof_err2[i];
      }

    return retstr;
  }
} // AxisManip
