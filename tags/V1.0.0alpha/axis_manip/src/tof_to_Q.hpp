/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_Q.hpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.34
  template <typename NumT>
  std::string
  tof_to_Q(std::vector<NumT> const & tof,
	   std::vector<NumT> const & tof_err2,
	   const NumT total_pathlength,
	   const NumT total_pathlength_err2,
	   const NumT azimuthal_angle,
	   const NumT azimuthal_angle_err2,
	   const NumT polar_angle,
	   const NumT polar_angle_err2,
	   std::vector<NumT> & Qx,
	   std::vector<NumT> & Qx_err2,
	   std::vector<NumT> & Qy,
	   std::vector<NumT> & Qy_err2,
	   std::vector<NumT> & Qz,
	   std::vector<NumT> & Qz_err2,
	   void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_Q] not implemented");    
  }
} // AxisManip
