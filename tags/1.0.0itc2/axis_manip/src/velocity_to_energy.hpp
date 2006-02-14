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
 * \file axis_manip/src/velocity_to_energy.hpp
 */
#ifndef _VELOCITY_TO_ENERGY
#define _VELOCITY_TO_ENERGY 1

#include "conversions.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.21
  template <typename NumT>
  std::string
  velocity_to_energy(const Nessi::Vector<NumT> & velocity,
                     const Nessi::Vector<NumT> & velocity_err2,
                     Nessi::Vector<NumT> & energy,
                     Nessi::Vector<NumT> & energy_err2,
                     void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_energy] not implemented");
  }

  // 3.21
  template <typename NumT>
  std::string
  velocity_to_energy(const NumT velocity,
                     const NumT velocity_err2,
                     NumT & energy,
                     NumT & energy_err2,
                     void *temp=NULL)
  {
    throw std::runtime_error("Function [velocity_to_energy] not implemented");
  }
} // AxisManip

#endif // _VELOCITY_TO_ENERGY
