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
 * \file axis_manip/src/wavelength_to_tof.hpp
 */
#ifndef _WAVELENGTH_TO_TOF_HPP
#define _WAVELENGTH_TO_TOF_HPP 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(const Nessi::Vector<NumT> & wavelength,
                    const Nessi::Vector<NumT> & wavelength_err2,
                    const NumT pathlength,
                    const NumT pathlength_err2,
                    Nessi::Vector<NumT> & tof,
                    Nessi::Vector<NumT> & tof_err2,
                    void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_tof] not implemented");

  }


  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(const NumT wavelength,
                    const NumT wavelength_err2,
                    const NumT pathlength,
                    const NumT pathlength_err2,
                    NumT & tof,
                    NumT & tof_err2,
                    void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_tof] not implemented");

  }

} // AxisManip

#endif // _WAVELENGTH_TO_TOF_HPP
