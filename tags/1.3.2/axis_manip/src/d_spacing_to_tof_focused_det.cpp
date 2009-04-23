/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 *
 * For this software and its associated documentation, permission is granted
 * to reproduce, prepare derivative works, and distribute copies to the public
 * for any purpose and without fee.
 *
 * This material was prepared as an account of work sponsored by an agency of
 * the United States Government.  Neither the United States Government nor the
 * United States Department of Energy, nor any of their employees, makes any
 * warranty, express or implied, or assumes any legal liability or
 * responsibility for the accuracy, completeness, or usefulness of any
 * information, apparatus, product, or process disclosed, or represents that
 * its use would not infringe privately owned rights.
 *
 */

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
