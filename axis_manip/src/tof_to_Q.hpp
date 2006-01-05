/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_Q.hpp
 */
#ifndef _TOF_TO_Q_HPP
#define _TOF_TO_Q_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.34
  template <typename NumT>
  std::string
  tof_to_Q(const Nessi::Vector<NumT> & tof,
	   const Nessi::Vector<NumT> & tof_err2,
	   const NumT total_pathlength,
	   const NumT total_pathlength_err2,
	   const NumT azimuthal_angle,
	   const NumT azimuthal_angle_err2,
	   const NumT polar_angle,
	   const NumT polar_angle_err2,
	   Nessi::Vector<NumT> & Qx,
	   Nessi::Vector<NumT> & Qx_err2,
	   Nessi::Vector<NumT> & Qy,
	   Nessi::Vector<NumT> & Qy_err2,
	   Nessi::Vector<NumT> & Qz,
	   Nessi::Vector<NumT> & Qz_err2,
	   void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_Q] not implemented");    
  }

  // 3.34
  template <typename NumT>
  std::string
  tof_to_Q(const NumT tof,
	   const NumT tof_err2,
	   const NumT total_pathlength,
	   const NumT total_pathlength_err2,
	   const NumT azimuthal_angle,
	   const NumT azimuthal_angle_err2,
	   const NumT polar_angle,
	   const NumT polar_angle_err2,
	   NumT & Qx,
	   NumT & Qx_err2,
	   NumT & Qy,
	   NumT & Qy_err2,
	   NumT & Qz,
	   NumT & Qz_err2,
	   void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_Q] not implemented");    
  }
} // AxisManip

#endif // _TOF_TO_Q_HPP
