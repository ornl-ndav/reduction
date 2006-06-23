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
#include "nessi_warn.hpp"
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
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT ldlu;
 
    // fill the local variables
    retstr += __initial_velocity_dgs_static(dist_upsteam_mon,
                                            dist_downstream_mon,
                                            ldlu);

    // do the calculation
    retstr += __initial_velocity_dgs_dynamic(dist_upstream_mon_err2,
                                             time_upstream_mon,
                                             time_upstream_mon_err2,
                                             dist_downstream_mon_err2,
                                             time_downstream_mon,
                                             time_downstream_mon_err2,
                                             ldlu,
                                             initial_velocity, 
                                             initial_velocity_err2);

    return retstr;
  }

/**
   * \ingroup initial_velocity_dgs
   *
   * This is a PRIVATE helper function for initial_velocity_dgs that
   * calculates parameters invariant across array calculation.
   *
   * \param dist_upsteam_mon (INPUT) is the distance to the upstream monitor.
   * \param dist_downstream_mon (INPUT) is the distance to the downstream 
   * monitor.
   * \param ldlu (OUTPUT) the value of the distance to downstream monitor 
   * subtract by the distance to upstream monitor.
   */
  template <typename NumT>
  std::string
  __initial_velocity_dgs_static(const NumT dist_upsteam_mon,
                                const NumT dist_downstream_mon,
                                NumT & ldlu)
  {
    ldlu = dist_downstream_mon - dist_upsteam_mon;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup initial_velocity_dgs
   *
   * This is a PRIVATE helper function for initial_velocity_dgs that
   * calculates the initial_velocity and its uncertainty
   *
   * \param dist_upstream_mon_err2 (INPUT) same as parameter in 
   * initial_velocity_dgs()
   * \param time_upstream_mon (INPUT) same as parameter in 
   * initial_velocity_dgs()
   * \param time_upstream_mon_err2 (INPUT) same as parameter in 
   * initial_velocity_dgs()
   * \param dist_downstream_mon_err2 (INPUT) same as parameter in 
   * initial_velocity_dgs()
   * \param time_downstream_mon (INPUT) same as parameter in 
   * initial_velocity_dgs()
   * \param time_downstream_mon_err2 (INPUT) same as parameter in 
   * initial_velocity_dgs()
   * \param ldlu (INPUT) same as the parameter of 
   * __initial_velocity_dgs_static()  
   * \param initial_velocity (OUTPUT) same as parameter in 
   * initial_velocity_dgs()
   * \param initial_velocity_err2 (OUTPUT) same as parameter in
   * initial_velocity_dgs()
   */
  template <typename NumT>
  std::string
  __initial_velocity_dgs_dynamic(const NumT dist_upstream_mon_err2,
                                 const NumT time_upstream_mon,
                                 const NumT time_upstream_mon_err2,
                                 const NumT dist_downstream_mon_err2,
                                 const NumT time_downstream_mon,
                                 const NumT time_downstream_mon_err2,
                                 const NumT ldlu,
                                 NumT & initial_velocity, 
                                 NumT & initial_velocity_err2)
                                 
  {
    NumT tdtu = time_downstream_mon - time_upstream_mon;
    NumT tdtu2 = tdtu * tdtu;
    NumT inv_tdtu = static_cast<NumT>(1.0/tdtu);
    NumT inv_tdtu2 = static_cast<NumT>(1.0/tdtu2);

    // the result
    initial_velocity = ldlu * inv_tdtu;

    // the uncertainty in the result
    initial_velocity_err2 = inv_tdtu2 
      * (dist_downstream_mon_err2 + dist_upstream_mon_err2);

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _INITIAL_VELOCITY_DGS_HPP
