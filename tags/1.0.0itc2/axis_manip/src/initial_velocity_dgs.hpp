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
 * \file axis_manip/src/initial_velocity_dgs.hpp
 */
#ifndef _INITIAL_VELOCITY_DGS_HPP
#define _INITIAL_VELOCITY_DGS_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.19
  template <typename NumT>
  std::string
  initial_velocity_dgs(const NumT dist_upsteam_mon,
                       const NumT dist_upstream_mon_err2,
                       const NumT time_upstream_mon,
                       const NumT time_upstream_mon_err2,
                       const NumT dist_downstream_mon,
                       const NumT dist_downstream_mon_err2,
                       const NumT time_downstream_mon,
                       const NumT time_downstream_mon_err2,
                       NumT & initial_velocity,
                       NumT & initial_velocity_err2,
                       void *temp=NULL)
  {
    throw std::runtime_error("Function [initial_velocity_dgs] not implemented");
  }
} // AxisManip

#endif // _INITIAL_VELOCITY_DGS_HPP
