/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_scalar_Q.hpp
 */
#ifndef _TOF_TO_SCALAR_Q_HPP
#define _TOF_TO_SCALAR_Q_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include <cmath>
#include <stdexcept>

namespace AxisManip
{
  // 3.17
  template <typename NumT>
  std::string
  tof_to_scalar_Q(Nessi::Vector<NumT> const & tof,
		  Nessi::Vector<NumT> const & tof_err2,
		  const NumT pathlength,
		  const NumT pathlength_err2,
                  const NumT scatt_angle,
		  const NumT scatt_angle_err2,
		  Nessi::Vector<NumT> & Q,
		  Nessi::Vector<NumT> & Q_err2,
		  void *temp=NULL)
  {
    // VARIABLES WITH BAD NAMES: a, a2, cang, cang2, sang, sang2,
    //                           term1, term2, term3

    NumT a = static_cast<NumT>(1)/(static_cast<NumT>(PhysConst::H_OVER_MNEUT));
    a *= static_cast<NumT>(4)*static_cast<NumT>(PhysConst::PI);
    NumT a2 = a*a;

    NumT cang = static_cast<NumT>(std::cos(static_cast<double>(scatt_angle)));
    NumT cang2 = cang * cang;
    NumT sang = static_cast<NumT>(std::cos(static_cast<double>(scatt_angle)));
    NumT sang2 = sang * sang;

    NumT term1 = sang2 * pathlength_err2 * pathlength_err2;
    NumT term2 = cang2 * pathlength * pathlength;
    term2 *= (scatt_angle_err2 * scatt_angle_err2);

    NumT term3 = sang2 * pathlength * pathlength;

    size_t size_tof = tof.size();
    for (size_t i = 0; i < size_tof; ++i)
      {
	Q[i] = sang / tof[i];
	Q[i] *= (a * pathlength);

	Q_err2[i] = tof_err2[i] * tof_err2[i];
	Q_err2[i] /= tof[i] * tof[i];
	Q_err2[i] *= term3;
	Q_err2[i] += term1 + term2;
	Q_err2[i] *= a2 / (tof[i] * tof[i]);
      }

    std::string retstr("");
    return retstr;
  }

  // 3.17
  template <typename NumT>
  std::string
  tof_to_scalar_Q(const NumT tof,
		  const NumT tof_err2,
		  const NumT pathlength,
		  const NumT pathlength_err2,
                  const NumT scatt_angle,
		  const NumT scatt_angle_err2,
		  NumT & Q,
		  NumT & Q_err2,
		  void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_scalar_Q] not implemented");
  }
} // AxisManip
#endif
