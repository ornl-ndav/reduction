/**
 * $Id$
 *
 * \file axis_manip/src/d_spacing_to_tof_focused_det.cpp
 */
#include "d_spacing_to_tof_focused_det.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.39.
   *
   * \ingroup d_spacing_to_tof_focused_det
   */
  template std::string
  d_spacing_to_tof_focused_det<float>(
                                   const Nessi::Vector<float> & d_spacing,
                                   const Nessi::Vector<float> & d_spacing_err2,
                                   const float pathlength_focused,
                                   const float pathlength_focused_err2,
                                   const float polar_angle_focused,
                                   const float polar_angle_focused_err2,
                                   Nessi::Vector<float> & tof,
                                   Nessi::Vector<float> & tof_err2,
                                   void *temp);

  /**
   * This is the float declaration of the function defined in 3.39.
   *
   * \ingroup d_spacing_to_tof_focused_det
   */
  template std::string
  d_spacing_to_tof_focused_det<float>(
                                   const float d_spacing,
                                   const float d_spacing_err2,
                                   const float pathlength_focused,
                                   const float pathlength_focused_err2,
                                   const float polar_angle_focused,
                                   const float polar_angle_focused_err2,
                                   float & tof,
                                   float & tof_err2,
                                   void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.39.
   *
   * \ingroup d_spacing_to_tof_focused_det
   */
  template std::string
  d_spacing_to_tof_focused_det<double>(
                                  const Nessi::Vector<double> & d_spacing,
                                  const Nessi::Vector<double> & d_spacing_err2,
                                  const double pathlength_focused,
                                  const double pathlength_focused_err2,
                                  const double polar_angle_focused,
                                  const double polar_angle_focused_err2,
                                  Nessi::Vector<double> & tof,
                                  Nessi::Vector<double> & tof_err2,
                                  void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.39.
   *
   * \ingroup d_spacing_to_tof_focused_det
   */
  template std::string
  d_spacing_to_tof_focused_det<double>(
                                  const double d_spacing,
                                  const double d_spacing_err2,
                                  const double pathlength_focused,
                                  const double pathlength_focused_err2,
                                  const double polar_angle_focused,
                                  const double polar_angle_focused_err2,
                                  double & tof,
                                  double & tof_err2,
                                  void *temp);
} // AxisManip
