/**
 * $Id$
 *
 * \file axis_manip/src/d_spacing_to_tof_focused_det.hpp
 */
#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.39
  template <typename NumT>
  std::string
  d_spacing_to_tof_focused_det(Nessi::Vector<NumT> const & d_spacing,
			       Nessi::Vector<NumT> const & d_spacing_err2,
			       const NumT pathlength_focused,
			       const NumT pathlength_focused_err2,
			       const NumT polar_angle_focused,
			       const NumT polar_angle_focused_err2,
			       Nessi::Vector<NumT> & tof,
			       Nessi::Vector<NumT> & tof_err2,
			       void *temp=NULL)
  {
    throw std::runtime_error("Function [d_spacing_to_tof_focused_det] not implemented");
  }

  template <typename NumT>
    std::string
    d_spacing_to_tof_focused_det(const NumT d_spacing,
				 const NumT d_spacing_err2,
				 const NumT pathlength_focused,
				 const NumT pathlength_focused_err2,
				 const NumT polar_focused,
				 const NumT polar_focused_err2,
				 NumT & tof,
				 NumT & tof_err2,
				 void *temp=NULL)
  {
    throw std::runtime_error("Function [d_spacing_to_tof_focused_det] not implemented");
  }
} // AxisManip
