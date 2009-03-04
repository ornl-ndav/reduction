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
 * \file axis_manip/src/wavelength_to_velocity.hpp
 */
#ifndef _WAVELENGTH_TO_VELOCITY_HPP
#define _WAVELENGTH_TO_VELOCITY_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the wavelength_to_velocity function name
  const std::string wtv_func_str = "AxisManip::wavelength_to_velocity";

  // 3.20
  template <typename NumT>
  std::string
  wavelength_to_velocity(const Nessi::Vector<NumT> wavelength,
                         const Nessi::Vector<NumT> wavelength_err2,
                         Nessi::Vector<NumT> & velocity,
                         Nessi::Vector<NumT> & velocity_err2,
                         void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, velocity);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtv_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(wavelength_err2, velocity_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtv_func_str+" (v,v): err2 "+e.what());
      }

    // check that the wavelength arrays are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtv_func_str+" (v,v): wavelength "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string
    
    
    // do the calculation
    size_t size_wavelength = wavelength.size();
    for(size_t i = 0; i < size_wavelength; ++i)
      {
        retstr += __wavelength_to_velocity_dynamic(wavelength[i],
                                                   wavelength_err2[i],
                                                   velocity[i],
                                                   velocity_err2[i]);
      }

    return retstr;
  }

  // 3.20
  template <typename NumT>
  std::string
  wavelength_to_velocity(const NumT wavelength,
                         const NumT wavelength_err2,
                         NumT & velocity,
                         NumT & velocity_err2,
                         void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // do the calculation
    retstr += __wavelength_to_velocity_dynamic(wavelength,
                                               wavelength_err2,
                                               velocity,
                                               velocity_err2);

    return retstr;
  }

  /**
   * \ingroup wavelength_to_velocity
   *
   * This is a PRIVATE helper function for wavelength_to_velocity that
   * calculates the velocity and its uncertainty
   *
   * \param wavelength (INPUT) same as the parameter in
   * wavelength_to_velocity()
   * \param wavelength_err2 (INPUT) same as the parameter in
   * wavelength_to_velocity()
   * \param velocity (OUTPUT) same as the parameter in
   * wavelength_to_velocity()
   * \param velocity_err2 (OUTPUT) same as the parameter in
   * wavelength_to_velocity() 
   */
  template <typename NumT>
  std::string __wavelength_to_velocity_dynamic(const NumT wavelength,
                                               const NumT wavelength_err2,
                                               NumT & velocity,
                                               NumT & velocity_err2)
  {
    // calculate the value
    velocity = PhysConst::H_OVER_MNEUT / wavelength;

    // calculate the uncertainty
    velocity_err2 = ((velocity * velocity) / (wavelength * wavelength)) 
      * wavelength_err2;
    
    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _WAVELENGTH_TO_VELOCITY_HPP
