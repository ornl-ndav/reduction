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

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
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
    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    NumT a;
    NumT a2;
    NumT b;
    NumT c;

    warn = __wavelength_to_tof_static(pathlength, pathlength_err2,
                                      a, a2, b, c);
    if (!warn.empty())
      {
        retstr += warn;
      }

    size_t size_wavelength = wavelength.size();
    for (size_t i = 0; i < size_wavelength ; ++i)
      {
        warn = __wavelength_to_tof_dynamic(wavelength[i], wavelength_err2[i],
                                           pathlength, pathlength_err2,
                                           tof[i], tof_err2[i], a, a2, b, c);

        if (!warn.empty())
          {
            retstr += warn;
          }
      }

    return retstr;
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
    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    NumT a;
    NumT a2;
    NumT b;
    NumT c;

    warn = __wavelength_to_tof_static(pathlength, pathlength_err2,
                                      a, a2, b, c);
    if (!warn.empty())
      {
        retstr += warn;
      }

    warn = __wavelength_to_tof_dynamic(wavelength, wavelength_err2,
                                       pathlength, pathlength_err2,
                                       tof, tof_err2, a, a2, b, c);

    if (!warn.empty())
      {
        retstr += warn;
      }

    return retstr;
  }

  /**
   * \ingroup wavelength_to_tof
   *
   * This is a PRIVATE helper function for wavelength_to_tof that calculates
   * the parameters invariant across the array calculation.
   *
   * \param pathlength (INPUT) same as the parameter in wavelength_to_tof()
   * \param pathlength_err2 (INPUT) same as the parameter in
   * wavelength_to_tof()
   * \param a (OUTPUT) \f$=\frac{m_n pathlength}{h}\f$
   * \param a2 (OUTPUT) \f$=a^2\f$
   * \param b (OUTPUT) \f$=pathlength^2\f$
   * \param c (OUTPUT) \f$=path_length\_err2^2\f$
   */
  template <typename NumT>
  std::string
  __wavelength_to_tof_static(const NumT pathlength,
                             const NumT pathlength_err2,
                             NumT & a,
                             NumT & a2,
                             NumT & b,
                             NumT & c)
  {
    a = static_cast<NumT>(1. / (PhysConst::H_OVER_MNEUT));
    a *= pathlength;

    a2 = a * a;

    b = pathlength * pathlength;

    c = pathlength_err2 * pathlength_err2;

    return Nessi::EMPTY_WARN;
  }

 /**
   * \ingroup wavelength_to_tof
   *
   * This is a PRIVATE helper function for wavelength_to_tof that calculates
   * tof and its uncertainty.
   *
   * \param wavelength (INPUT) same as the parameter in
   * wavelength_to_tof()
   * \param wavelength_err2 (INPUT) same as the parameter in
   * wavelength_to_tof()
   * \param pathlength (INPUT) same as the parameter in
   * wavelength_to_tof()
   * \param pathlength_err2 (INPUT) same as the parameter in
   * wavelength_to_tof()
   * \param tof (OUTPUT) same as the parameter in wavelength_to_tof()
   * \param tof_err2 (OUTPUT) same as the parameter in wavelength_to_tof()
   * \param a (INPUT) same as the parameter in __wavelength_to_tof_static()
   * \param a2 (INPUT) same as the parameter in __wavelength_to_tof_static()
   * \param b (INPUT) same as the parameter in __wavelength_to_tof_static()
   * \param c (INPUT) same as the parameter in __wavelength_to_tof_static()
   */
  template <typename NumT>
  std::string
  __wavelength_to_tof_dynamic(const NumT wavelength,
                              const NumT wavelength_err2,
                              const NumT pathlength,
                              const NumT pathlength_err2,
                              NumT & tof,
                              NumT & tof_err2,
                              const NumT a,
                              const NumT a2,
                              const NumT b,
                              const NumT c)
  {
    tof = a * wavelength;
    tof_err2 = wavelength * wavelength * c;
    tof_err2 += b * (wavelength_err2 * wavelength_err2);
    tof_err2 *= a2;

    return Nessi::EMPTY_WARN;
  }

} // AxisManip

#endif // _WAVELENGTH_TO_TOF_HPP
