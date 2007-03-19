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
 * \file axis_manip/src/energy_to_wavelength.hpp
 */
#ifndef _ENERGY_TO_WAVELENGTH_HPP
#define _ENERGY_TO_WAVELENGTH_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <cmath>
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the energy_to_wavelength function name
  const std::string etw_func_str = "AxisManip::energy_to_wavelength";

  // 3.51
  template <typename NumT>
  std::string
  energy_to_wavelength(const Nessi::Vector<NumT> & energy,
                       const Nessi::Vector<NumT> & energy_err2,
                       Nessi::Vector<NumT> & wavelength,
                       Nessi::Vector<NumT> & wavelength_err2,
                       void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(energy, wavelength);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(etw_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(energy_err2, wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(etw_func_str+" (v,v): err2 "+e.what());
      }

    // check that the energy arrays are of proper size
    try
      {
        Utils::check_sizes_square(energy, energy_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(etw_func_str+" (v,v): energy "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);

    NumT a;

    retstr += __energy_to_wavelength_static(a);

    size_t sz = energy.size();
    for (size_t i = 0; i < sz; ++i)
      {
        retstr += __energy_to_wavelength_dynamic(energy[i],
                                                 energy_err2[i],
                                                 wavelength[i],
                                                 wavelength_err2[i],
                                                 a);
      }

    return retstr;
  }

  // 3.51
  template <typename NumT>
  std::string
  energy_to_wavelength(const NumT energy,
                       const NumT energy_err2,
                       NumT & wavelength,
                       NumT & wavelength_err2,
                       void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN);

    NumT a;

    retstr += __energy_to_wavelength_static(a);

    retstr += __energy_to_wavelength_dynamic(energy, energy_err2,
                                             wavelength, wavelength_err2, a);

    return retstr;
  }

  /**
   * \ingroup energy_to_wavelength
   *
   * This is a PRIVATE helper function for energy_to_wavelength that
   * calculates the parameters invariant across the array calculation.
   *
   * \param a (OUTPUT) \f$=\frac{h^2}{8 m_n}\f$
   */
  template <typename NumT>
  std::string
  __energy_to_wavelength_static(NumT & a)
  {
    a = static_cast<NumT>(PhysConst::H2_OVER_2MNEUT / 4.);
    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup energy_to_wavelength
   *
   * This is a PRIVATE helper function for energy_to_wavelength that
   * calculates the energy and its uncertainty.
   *
   * \param energy (INPUT) same as the parameter in
   * energy_to_wavelength()
   * \param energy_err2 (INPUT) same as the parameter in
   * energy_to_wavelength()
   * \param wavelength (OUTPUT) same as the parameter in
   * energy_to_wavelength()
   * \param wavelength_err2 (OUTPUT) same as the parameter in
   * energy_to_wavelength()
   * \param a (INPUT) same as the parameter in
   * __energy_to_wavelength_static()
   */
  template <typename NumT>
  std::string
  __energy_to_wavelength_dynamic(const NumT energy,
                                 const NumT energy_err2,
                                 NumT & wavelength,
                                 NumT & wavelength_err2,
                                 const NumT a)
  {
    NumT arg = static_cast<NumT>(PhysConst::H2_OVER_2MNEUT) / energy;
    wavelength = static_cast<NumT>(std::sqrt(static_cast<double>(arg)));
    
    wavelength_err2 = (a * energy_err2);
    wavelength_err2 /= (energy * energy * energy);

    return Nessi::EMPTY_WARN;
  }

} // AxisManip

#endif // _ENERGY_TO_WAVELENGTH_HPP
