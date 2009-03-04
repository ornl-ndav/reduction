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
 * \file axis_manip/src/velocity_to_wavelength.hpp
 */
#ifndef _VELOCITY_TO_WAVELENGTH_HPP
#define _VELOCITY_TO_WAVELENGTH_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the velocity_to_wavelength function name
  const std::string vtw_func_str = "AxisManip::velocity_to_wavelength";

  // 3.58
  template <typename NumT>
  std::string
  velocity_to_wavelength(const Nessi::Vector<NumT> velocity,
                         const Nessi::Vector<NumT> velocity_err2,
                         Nessi::Vector<NumT> & wavelength,
                         Nessi::Vector<NumT> & wavelength_err2,
                         void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(velocity, wavelength);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(vtw_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(velocity_err2, wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(vtw_func_str+" (v,v): err2 "+e.what());
      }

    // check that the velocity arrays are of proper size
    try
      {
        Utils::check_sizes_square(velocity, velocity_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(vtw_func_str+" (v,v): velocity "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string
    
    
    // do the calculation
    size_t size_velocity = velocity.size();
    for(size_t i = 0; i < size_velocity; ++i)
      {
        retstr += __velocity_to_wavelength_dynamic(velocity[i],
                                                   velocity_err2[i],
                                                   wavelength[i],
                                                   wavelength_err2[i]);
      }

    return retstr;
  }

  // 3.58
  template <typename NumT>
  std::string
  velocity_to_wavelength(const NumT velocity,
                         const NumT velocity_err2,
                         NumT & wavelength,
                         NumT & wavelength_err2,
                         void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // do the calculation
    retstr += __velocity_to_wavelength_dynamic(velocity,
                                               velocity_err2,
                                               wavelength,
                                               wavelength_err2);

    return retstr;
  }

  /**
   * \ingroup velocity_to_wavelength
   *
   * This is a PRIVATE helper function for velocity_to_wavelength that
   * calculates the velocity and its uncertainty
   *
   * \param velocity (INPUT) same as the parameter in
   * velocity_to_wavelength()
   * \param velocity_err2 (INPUT) same as the parameter in
   * velocity_to_wavelength()
   * \param wavelength (OUTPUT) same as the parameter in
   * velocity_to_wavelength()
   * \param wavelength_err2 (OUTPUT) same as the parameter in
   * velocity_to_wavelength() 
   */
  template <typename NumT>
  std::string __velocity_to_wavelength_dynamic(const NumT velocity,
                                               const NumT velocity_err2,
                                               NumT & wavelength,
                                               NumT & wavelength_err2)
  {
    // calculate the value
    wavelength = PhysConst::H_OVER_MNEUT / velocity;

    // calculate the uncertainty
    wavelength_err2 = ((wavelength * wavelength) / (velocity * velocity)) 
      * velocity_err2;
    
    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _VELOCITY_TO_WAVELENGTH_HPP
