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
  tof_to_scalar_Q(const Nessi::Vector<NumT> & tof,
		  const Nessi::Vector<NumT> & tof_err2,
		  const NumT pathlength,
		  const NumT pathlength_err2,
                  const NumT scatt_angle,
		  const NumT scatt_angle_err2,
		  Nessi::Vector<NumT> & Q,
		  Nessi::Vector<NumT> & Q_err2,
		  void *temp=NULL)
  {
    std::string retstr("");
    std::string warn;

    NumT a;
    NumT a2;
    NumT sang;
    NumT term1;
    NumT term2;
    NumT term3;

    warn = __tof_to_scalar_Q_static(pathlength, pathlength_err2, scatt_angle, 
				    scatt_angle_err2, a, a2, sang, 
				    term1, term2, term3);
    if (warn.size() > 0)
      retstr += warn;

    size_t size_tof = tof.size();
    for (size_t i = 0; i < size_tof; ++i)
      {
	warn = __tof_to_scalar_Q_dynamic(tof[i], tof_err2[i], pathlength, 
					 Q[i], Q_err2[i], a, a2, sang, 
					 term1, term2, term3);

	if (warn.size() > 0)
	  retstr += warn;
      }



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
    std::string retstr("");
    std::string warn;

    NumT a;
    NumT a2;
    NumT sang;
    NumT term1;
    NumT term2;
    NumT term3;

    warn = __tof_to_scalar_Q_static(pathlength, pathlength_err2, scatt_angle, 
				    scatt_angle_err2, a, a2, sang, 
				    term1, term2, term3);
    if (warn.size() > 0)
      retstr += warn;
    
    warn = __tof_to_scalar_Q_dynamic(tof, tof_err2, pathlength, Q, Q_err2, 
				     a, a2, sang, term1, term2, term3);

    if (warn.size() > 0)
      retstr += warn;

    return retstr;
  }

  /**
   * This is a PRIVATE helper function for tof_to_scalar_Q that calculates the 
   * parameters invariant across the array calculation.
   */
  template <typename NumT>
  std::string
  __tof_to_scalar_Q_static(const NumT pathlength,
			   const NumT pathlength_err2,
			   const NumT scatt_angle,
			   const NumT scatt_angle_err2,
			   NumT & a, 
			   NumT & a2, 
			   NumT & sang, 
			   NumT & term1, 
			   NumT & term2, 
			   NumT & term3)
  {
    a = static_cast<NumT>(1./ PhysConst::H_OVER_MNEUT);
    a *= static_cast<NumT>(4. * PhysConst::PI);
    a2 = a * a;
    
    NumT cang = static_cast<NumT>(std::cos(static_cast<double>(scatt_angle)));
    NumT cang2 = cang * cang;
    sang = static_cast<NumT>(std::cos(static_cast<double>(scatt_angle)));
    NumT sang2 = sang * sang;
    
    term1 = sang2 * pathlength_err2 * pathlength_err2;
    term2 = cang2 * pathlength * pathlength;
    term2 *= (scatt_angle_err2 * scatt_angle_err2);
    
    term3 = sang2 * pathlength * pathlength;

    return std::string("");
  }

  /**
   * This is a PRIVATE helper function for tof_to_scalar_Q that calculates the 
   * scalar_Q and its uncertainty.
   */
  template <typename NumT>
  std::string
  __tof_to_scalar_Q_dynamic(const NumT tof,
			    const NumT tof_err2,
			    const NumT pathlength, 
			    NumT & Q, 
			    NumT & Q_err2,
			    const NumT a, 
			    const NumT a2, 
			    const NumT sang, 
			    const NumT term1, 
			    const NumT term2, 
			    const NumT term3)
  {
    Q = sang / tof;
    Q *= (a * pathlength);
    
    Q_err2 = tof_err2 * tof_err2;
    Q_err2 /= tof * tof;
    Q_err2 *= term3;
    Q_err2 += term1 + term2;
    Q_err2 *= a2 / (tof * tof);

    return std::string("");
  }

} // AxisManip

#endif // _TOF_TO_SCALAR_Q_HPP
