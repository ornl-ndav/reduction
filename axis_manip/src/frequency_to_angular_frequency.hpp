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
 * \file axis_manip/src/frequency_to_angular_frequency.hpp
 */
#ifndef _FREQUENCY_TO_ANGULAR_FREQUENCY_HPP
#define _FREQUENCY_TO_ANGULAR_FREQUENCY_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the frequency_to_angular_frequency function name
  const std::string ftaf_func_str = "AxisManip::frequency_to_angular_frequency";

  // 3.31
  template <typename NumT>
  std::string
  frequency_to_angular_frequency(const Nessi::Vector<NumT> & frequency,
                                 const Nessi::Vector<NumT> & frequency_err2,
                                 Nessi::Vector<NumT> & angular_frequency,
                                 Nessi::Vector<NumT> & angular_frequency_err2,
                                 void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(frequency,angular_frequency);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ftaf_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(frequency_err2, angular_frequency_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ftaf_func_str+" (v,v): err2 "+e.what());
      }

    // check that the frequency arrays are of proper size
    try
      {
        Utils::check_sizes_square(frequency,frequency_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ftaf_func_str+" (v,v): frequency "
                                    +e.what());
      }
    std::string retstr(Nessi::EMPTY_WARN);

    NumT a;
    NumT a2;

    retstr += __frequency_to_angular_frequency_static(a,a2);

    size_t sz = frequency.size();
    for (size_t i=0; i < sz; ++i)
      {
        retstr += __frequency_to_angular_frequency_dynamic(frequency[i],
                                                           frequency_err2[i],
                                                           angular_frequency[i],
                                                           angular_frequency_err2[i],
                                                           a,
                                                           a2);
      }

    return retstr;

  }

  // 3.31
  template <typename NumT>
  std::string
  frequency_to_angular_frequency(const NumT frequency,
                                 const NumT frequency_err2,
                                 NumT & angular_frequency,
                                 NumT & angular_frequency_err2,
                                 void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN);

    NumT a;
    NumT a2;

    retstr += __frequency_to_angular_frequency_static(a,a2);

    retstr += __frequency_to_angular_frequency_dynamic(frequency,
                                                       frequency_err2,
                                                       angular_frequency,
                                                       angular_frequency_err2,
                                                       a,
                                                       a2);

    return retstr;  
  }

 /**
   * \ingroup frequency_to_angular_frequency
   *
   * This is a PRIVATE helper function for frequency_to_angular_frequency that
   * calculates the parameters invariant across the array calculation.
   *
   * \param a (OUTPUT)the value of 2 times Pi times 10^12
   * \param a2 (OUTPUT) the value of a times a
   */
  template <typename NumT>
  std::string
  __frequency_to_angular_frequency_static(NumT & a,
                                          NumT & a2)
  {
    a = static_cast<NumT>(2.0e12 * PhysConst::PI);
    a2 = a*a;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup frequency_to_angular_frequency
   *
   * This is a PRIVATE helper function for frequency_to_angular_frequency that
   * calculates the angular_frequency and its uncertainty
   *
   * \param frequency (INPUT) same as parameter in frequency_to_angular
   * _frequency()
   * \param frequency_err2 (INPUT) same as parameter in frequency_to_angular
   * _frequency()
   * \param angular_frequency (OUTPUT) same as parameter in frequency_to_
   * angular_frequency()
   * \param angular_frequency_err2 (OUTPUT) same as parameter in frequency
   * _to_angular_frequency()
   * \param a (INPUT) same as parameter in __frequency_to_angular_frequency
   * _static()
   * \param a2 (INPUT) same as parameter in __frequency_to_angular_frequency
   * _static()
   */
  template <typename NumT>
  std::string
  __frequency_to_angular_frequency_dynamic(const NumT frequency,
                                           const NumT frequency_err2,
                                           NumT & angular_frequency,
                                           NumT & angular_frequency_err2,
                                           const NumT a,
                                           const NumT a2)
  {
    angular_frequency = frequency * a;
    angular_frequency_err2 = a2 * frequency_err2;

    return Nessi::EMPTY_WARN;
  }

} // AxisManip

#endif // _FREQUENCY_TO_ANGULAR_FREQUENCY_HPP
