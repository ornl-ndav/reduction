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
 * \file axis_manip/src/d_spacing_to_tof_focused_det.hpp
 */
#ifndef _D_SPACING_TO_TOF_FOCUSED_DET_HPP
#define _D_SPACING_TO_TOF_FOCUSED_DET_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.39
  template <typename NumT>
  std::string
  d_spacing_to_tof_focused_det(const Nessi::Vector<NumT> & d_spacing,
                               const Nessi::Vector<NumT> & d_spacing_err2,
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

#endif // _D_SPACING_TO_TOF_FOCUSED_DET_HPP
