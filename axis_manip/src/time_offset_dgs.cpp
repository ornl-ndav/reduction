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
 * \file axis_manip/src/time_offset_dgs.cpp
 */
#include "time_offset_dgs.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.26.
   *
   * \ingroup time_offset_dgs
   */
  template std::string
  time_offset_dgs<float>(const float dist_downstream_monitor,
                         const float dist_downstream_monitor_err2,
                         const float time_downstream_monitor,
                         const float time_downstream_monitor_err2,
                         const float initial_velocity,
                         const float initial_velocity_err2,
                         float & time_offset,
                         float & time_offset_err2,
                         void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.26.
   *
   * \ingroup time_offset_dgs
   */
  template std::string
  time_offset_dgs<double>(const double dist_downstream_monitor,
                          const double dist_downstream_monitor_err2,
                          const double time_downstream_monitor,
                          const double time_downstream_monitor_err2,
                          const double initial_velocity,
                          const double initial_velocity_err2,
                          double & time_offset,
                          double & time_offset_err2,
                          void *temp);
} // AxisManip
