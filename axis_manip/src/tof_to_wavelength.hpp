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
 * \file axis_manip/src/tof_to_wavelength.hpp
 */
#ifndef _TOF_TO_WAVELENGTH_HPP
#define _TOF_TO_WAVELENGTH_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the tof_to_wavelength function name
  const std::string ttw_func_str = "AxisManip::tof_to_wavelength";

  // 3.15
  template <typename NumT>
  std::string
  tof_to_wavelength(const Nessi::Vector<NumT> & tof,
                    const Nessi::Vector<NumT> & tof_err2,
                    const NumT pathlength,
                    const NumT pathlength_err2,
                    Nessi::Vector<NumT> & wavelength,
                    Nessi::Vector<NumT> & wavelength_err2,
                    void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(tof, wavelength);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttw_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(tof_err2, wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttw_func_str+" (v,v): err2 "+e.what());
      }

    // check that the tof arrays are of proper size
    try
      {
        Utils::check_sizes_square(tof, tof_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ttw_func_str+" (v,v): tof "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT a_err2;

    // fill the local variables
    retstr += __tof_to_wavelength_static(pathlength, pathlength_err2,
                                         a, a2, a_err2);

    // do the calculation
    size_t size_tof = tof.size();
    for (size_t i = 0; i < size_tof; ++i)
      {
        retstr += __tof_to_wavelength_dynamic(tof[i], tof_err2[i],
                                              a, a2, a_err2,
                                              wavelength[i],
                                              wavelength_err2[i]);
      }

    return retstr;
  }

  // 3.15
  template <typename NumT>
  std::string
  tof_to_wavelength(const NumT tof,
                    const NumT tof_err2,
                    const NumT pathlength,
                    const NumT pathlength_err2,
                    NumT & wavelength,
                    NumT & wavelength_err2,
                    void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT a_err2;

    // fill the local variables
    retstr += __tof_to_wavelength_static(pathlength, pathlength_err2,
                                         a, a2, a_err2);

    // do the calculation
    retstr += __tof_to_wavelength_dynamic(tof, tof_err2, a, a2, a_err2,
                                          wavelength, wavelength_err2);

    return retstr;
  }

  /**
   * \ingroup tof_to_wavelength
   *
   * This is a PRIVATE helper function for tof_to_wavelength that
   * calculates parameters invariant across array calculation.
   *
   * \param pathlength (INPUT) same as the parameter in
   * tof_to_wavelength_static()
   * \param pathlength_err2 (INPUT) same as the parameter in
   * tof_to_wavelength_static()
   * \param a (OUTPUT) \f$=\frac{h}{m_n pathlength}\f$
   * \param a2 (OUTPUT) \f$=a*a\f$
   * \param a_err2 (OUTPUT) \f$=\frac{h}{m_n pathlength^2} a\_err2^2 pathlength\_err2\f$
   */
  template <typename NumT>
  std::string  __tof_to_wavelength_static(const NumT pathlength,
                                          const NumT pathlength_err2,
                                          NumT & a,
                                          NumT & a2,
                                          NumT & a_err2)
  {
    // calculate the factor to multiply each element by
    a = static_cast<NumT>(PhysConst::H_OVER_MNEUT) / pathlength;
    a2 = a*a;

    // the result of these two lines is the uncertainty in the
    // multiplicative factor
    a_err2 = a/pathlength;
    a_err2 = a_err2*a_err2*pathlength_err2;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup tof_to_wavelength
   *
   * This is a PRIVATE helper function for tof_to_wavelength that
   * calculates the wavelength and its uncertainty
   *
   * \param tof (INPUT) same as the parameter in
   * tof_to_wavelength()
   * \param tof_err2 (INPUT) same as the parameter in
   * tof_to_wavelength()
   * \param a (INPUT) same as the parameter in
   * __tof_to_wavelength_static()
   * \param a2 (INPUT) same as the parameter in
   * __tof_to_wavelength_static()
   * \param  a_err2 (INPUT) same as the parameter in
   * __tof_to_wavelength_static()
   * \param  wavelength (OUTPUT) same as the parameter in
   * tof_to_wavelength()
   * \param  wavelength_err2 (OUTPUT) same as the parameter in
   * tof_to_wavelength()
   */
  template <typename NumT>
  std::string  __tof_to_wavelength_dynamic(const NumT tof,
                                           const NumT tof_err2,
                                           const NumT a,
                                           const NumT a2,
                                           const NumT a_err2,
                                           NumT & wavelength,
                                           NumT & wavelength_err2)
  {
    // calculate the value
    wavelength = a * tof;

    // calculate the uncertainty
    wavelength_err2 = (a2*tof_err2) + ((tof*tof)*a_err2);

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _TOF_TO_WAVELENGTH_HPP
