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
 * \file axis_manip/src/frequency_to_energy.hpp
 */
#ifndef _FREQUENCY_TO_ENERGY_HPP
#define _FREQUENCY_TO_ENERGY_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the frequency_to_energy function name
  const std::string fte_func_str = "AxisManip::frequency_to_energy";

  // 3.47
  template <typename NumT>
  std::string
  frequency_to_energy(const Nessi::Vector<NumT> & frequency,
                      const Nessi::Vector<NumT> & frequency_err2,
                      Nessi::Vector<NumT> & energy,
                      Nessi::Vector<NumT> & energy_err2,
                      void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(frequency,energy);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(fte_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(frequency_err2, energy_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(fte_func_str+" (v,v): err2 "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    NumT h;
    NumT h2;

    warn = __frequency_to_energy_static(h,h2);

    if (!warn.empty())
      {
        retstr += warn;
      }

    size_t sz = frequency.size();
    for (size_t i=0; i < sz; ++i)
      {
        warn == __frequency_to_energy_dynamic(frequency[i],
                                              frequency_err2[i],
                                              energy[i],
                                              energy_err2[i],
                                              h,
                                              h2);

        if (!warn.empty())
          {
            retstr += warn;
          }
      }

    return retstr;
  }

  // 3.47
  template <typename NumT>
  std::string
  frequency_to_energy(const NumT frequency,
                      const NumT frequency_err2,
                      NumT & energy,
                      NumT & energy_err2,
                      void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    NumT h;
    NumT h2;

    warn = __frequency_to_energy_static(h,h2);

    if (!warn.empty())
      {
        retstr += warn;
      }

    warn = __frequency_to_energy_dynamic(frequency,
                                         frequency_err2,
                                         energy,
                                         energy_err2,
                                         h,
                                         h2);

    if (!warn.empty())
      {
        retstr += warn;
      }

    return retstr;
  }

  /**
   * \ingroup frequency_to_energy
   *
   * This is a PRIVATE helper function for frequency_to_energy that
   * calculates the parameters invariant across the array calculation.
   *
   * \param h (OUTPUT) Planck's constant
   * \param h2 (OUTPUT) square of Planck's constant
   */
  template <typename NumT>
  std::string
  __frequency_to_energy_static(NumT & h,
                               NumT & h2)
  {
    h = static_cast<NumT>(PhysConst::H);
    h2 = h*h;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup frequency_to_energy
   *
   * This is a PRIVATE helper function for frequency_to_energy that
   * calculates the energy and its uncertainty
   *
   * \param frequency (INPUT) same as parameter in frequency_to_energy()
   * \param frequency_err2 (INPUT) same as parameter in frequency_to_energy()
   * \param energy (OUTPUT) same as parameter in frequency_to_energy()
   * \param energy_err2 (OUTPUT) same as parameter in frequency_to_energy()
   * \param h (INPUT) same as parameter in __frequency_to_energy_static()
   * \param h2 (INPUT) same as parameter in __frequency_to_energy_static()
   */
  template <typename NumT>
  std::string
  __frequency_to_energy_dynamic(const NumT frequency,
                                const NumT frequency_err2,
                                NumT & energy,
                                NumT & energy_err2,
                                const NumT h,
                                const NumT h2)
  {
    energy = frequency * h;
    energy_err2 = h2 * frequency_err2;

    return Nessi::EMPTY_WARN;
  }

} // AxisManip

#endif // _FREQUENCY_TO_ENERGY_HPP
