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
 * \file axis_manip/src/time_offset_dgs.hpp
 */
#ifndef _TIME_OFFSET_DGS_HPP
#define _TIME_OFFSET_DGS_HPP 1

#include "conversions.hpp"
#include "nessi_warn.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.26
  template <typename NumT>
  std::string
  time_offset_dgs(const NumT dist_downstream_monitor,
                  const NumT dist_downstream_monitor_err2,
                  const NumT time_downstream_monitor,
                  const NumT time_downstream_monitor_err2,
                  const NumT initial_velocity,
                  const NumT initial_velocity_err2,
                  NumT & time_offset,
                  NumT & time_offset_err2,
                  void *temp=NULL)
  {
  std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT b;
    NumT b2;
 
    // fill the local variables
    retstr += __time_offset_dgs_static(dist_downstream_monitor,
                                       initial_velocity,
                                       a, a2, b, b2);

    // do the calculation
    retstr += __time_offset_dgs_dynamic(dist_downstream_monitor_err2,
                                        time_downstream_monitor,
                                        time_downstream_monitor_err2,
                                        initial_velocity_err2,
                                        a, a2, b, b2,
                                        time_offset,
                                        time_offset_err2);

    return retstr; 
  }

/**
   * \ingroup time_offset_dgs
   *
   * This is a PRIVATE helper function for time_offset_dgs that
   * calculates parameters invariant across array calculation.
   *
   * \param dist_downstream_monitor (INPUT) is the total flight path
   * for the downstream monitor.
   * \param initial_velocity (INPUT) is the velocity of the incident
   * neutrons.
   * \param a (OUTPUT) \f$ = \frac {1} {initial\_velocity} \f$
   * \param a2 (OUTPUT) \f$ = a^2 \f$
   * \param b (OUTPUT) \f$ = dist\_downstream\_monitor\f$
   * \param b2 (OUTPUT) \f$ = b^2 \f$
   */
  template <typename NumT>
  std::string
  __time_offset_dgs_static(const NumT dist_downstream_monitor,
                           const NumT initial_velocity,
                           NumT & a,
                           NumT & a2,
                           NumT & b,
                           NumT & b2)
  {
    
    a = static_cast<NumT>(1.0/initial_velocity);
    a2 = a*a;
    b = dist_downstream_monitor;
    b2 = b*b;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup time_offset_dgs
   *
   * This is a PRIVATE helper function for time_offset_dgs that
   * calculates the time_offset and its uncertainty
   *
   * \param dist_downstream_monitor_err2 (INPUT) same as parameter in 
   * time_offset_dgs()
   * \param time_downstream_monitor (INPUT) same as parameter in
   * time_offset_dgs()
   * \param time_downstream_monitor_err2 (INPUT) same as parameter in 
   * time_offset_dgs()
   * \param initial_velocity_err2 (INPUT) same as parameter in
   * time_offset_dgs()
   * \param a (INPUT) same as parameter in __time_offset_dgs_static()
   * \param a2 (INPUT) same as parameter in __time_offset_dgs_static()
   * \param b (INPUT) same as parameter in __time_offset_dgs_static()
   * \param b2 (INPUT) same as parameter in __time_offset_dgs_static()
   * \param time_offset (OUTPUT) same as parameter in time_offset_dgs()
   * \param time_offset_err2 (OUTPUT) same as parameter in time_offset_dgs()
   */
  template <typename NumT>
  std::string
  __time_offset_dgs_dynamic(const NumT dist_downstream_monitor_err2,
                            const NumT time_downstream_monitor,
                            const NumT time_downstream_monitor_err2,
                            const NumT initial_velocity_err2,
                            const NumT a,
                            const NumT a2,
                            const NumT b,
                            const NumT b2,
                            NumT & time_offset,
                            NumT & time_offset_err2)
  {

    // the result
    time_offset = time_downstream_monitor - (a*b);

    // the uncertainty in the result
    time_offset_err2 = ((a2 * dist_downstream_monitor_err2) 
      + (a2 * a2 * b2 * initial_velocity_err2));

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _TIME_OFFSET_DGS_HPP
