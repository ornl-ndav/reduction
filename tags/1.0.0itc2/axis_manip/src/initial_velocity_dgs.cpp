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
 * \file axis_manip/src/initial_velocity_dgs.cpp
 */
#include "initial_velocity_dgs.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.19.
   *
   * \ingroup initial_velocity_dgs
   */
  template std::string
  initial_velocity_dgs<float>(const float dist_upsteam_mon,
                              const float dist_upstream_mon_err2,
                              const float time_upstream_mon,
                              const float time_upstream_mon_err2,
                              const float dist_downstream_mon,
                              const float dist_downstream_mon_err2,
                              const float time_downstream_mon,
                              const float time_downstream_mon_err2,
                              float & initial_velocity,
                              float & initial_velocity_err2,
                              void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.19.
   *
   * \ingroup initial_velocity_dgs
   */
  template std::string
  initial_velocity_dgs<double>(const double dist_upsteam_mon,
                               const double dist_upstream_mon_err2,
                               const double time_upstream_mon,
                               const double time_upstream_mon_err2,
                               const double dist_downstream_mon,
                               const double dist_downstream_mon_err2,
                               const double time_downstream_mon,
                               const double time_downstream_mon_err2,
                               double & initial_velocity,
                               double & initial_velocity_err2,
                               void *temp=NULL);
} // AxisManip
