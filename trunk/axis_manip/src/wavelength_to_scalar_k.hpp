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
 * \file axis_manip/src/wavelength_to_scalar_k.hpp
 */
#ifndef _WAVELENGTH_TO_SCALAR_K_HPP
#define _WAVELENGTH_TO_SCALAR_K_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the wavelength_to_scalar_k function name
  const std::string wtsk_func_str = "AxisManip::wavelength_to_scalar_k";

  // 3.24
  template <typename NumT>
  std::string
  wavelength_to_scalar_k(const Nessi::Vector<NumT> & wavelength,
                         const Nessi::Vector<NumT> & wavelength_err2,
                         Nessi::Vector<NumT> & wavevector,
                         Nessi::Vector<NumT> & wavevector_err2,
                         void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, wavevector);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtsk_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(wavelength_err2, wavevector_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wtsk_func_str+" (v,v): err2 "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    NumT a;
    NumT a2;

    warn = __wavelength_to_scalar_k_static(a, a2);

    if (!warn.empty())
      {
        retstr += warn;
      }

    size_t size_wavelength = wavelength.size();
    for (size_t i = 0 ; i < size_wavelength ; ++i)
      {
        warn = __wavelength_to_scalar_k_dynamic(wavelength[i],
                                                wavelength_err2[i],
                                                wavevector[i],
                                                wavevector_err2[i],
                                                a, a2);

        if (!warn.empty())
          {
            retstr += warn;
          }
      }

    return retstr;
  }

  // 3.24
  template <typename NumT>
  std::string
  wavelength_to_scalar_k(const NumT wavelength,
                         const NumT wavelength_err2,
                         NumT & wavevector,
                         NumT & wavevector_err2,
                         void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN);
   std::string warn;

    NumT a;
    NumT a2;

    warn = __wavelength_to_scalar_k_static(a, a2);

    if (!warn.empty())
      {
        retstr += warn;
      }

    warn = __wavelength_to_scalar_k_dynamic(wavelength, wavelength_err2,
                                            wavevector, wavevector_err2,
                                            a, a2);

    if (!warn.empty())
      {
        retstr += warn;
      }

    return retstr;
  }

  /**
   * \ingroup wavelength_to_scalar_k
   *
   * This is a PRIVATE helper function for wavelength_to_scalar_k that
   * calculates the parameters invariant across the array calculation.
   *
   * \param a (INPUT) \f$=2\pi\f$
   * \param a2 (INPUT) \f$=4\pi^2\f$
   */
  template <typename NumT>
  std::string
  __wavelength_to_scalar_k_static(NumT & a,
                                  NumT & a2)
  {
    a = static_cast<NumT>(2. * PhysConst::PI);
    a2 = a * a;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup wavelength_to_scalar_k
   *
   * This is a PRIVATE helper function for wavelength_to_scalar_k that
   * calculates the scalar_k and its uncertainty.
   *
   * \param wavelength (INPUT) same as the parameter in
   * wavelength_to_scalar_k()
   * \param wavelength_err2 (INPUT) same as the parameter in
   * wavelength_to_scalar_k()
   * \param wavevector (OUTPUT) same as the parameter in
   * wavelength_to_scalar_k()
   * \param wavevector_err2 (OUTPUT) same as the parameter in
   * wavelength_to_scalar_k()
   * \param a (INPUT) same as the parameter in
   * __wavelength_to_scalar_k_static()
   * \param a2 (INPUT) same as the parameter in
   * __wavelength_to_scalar_k_static()
   */
  template <typename NumT>
  std::string
  __wavelength_to_scalar_k_dynamic(const NumT wavelength,
                                   const NumT wavelength_err2,
                                   NumT & wavevector,
                                   NumT & wavevector_err2,
                                   const NumT a,
                                   const NumT a2)
  {
    wavevector = a / wavelength;
    wavevector_err2 = (a2 * wavelength_err2)
      / (wavelength * wavelength * wavelength * wavelength);

    return Nessi::EMPTY_WARN;
  }

} // AxisManip

#endif // _WAVELENGTH_TO_SCALAR_K_HPP
