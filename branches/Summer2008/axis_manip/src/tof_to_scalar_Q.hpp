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
 * \file axis_manip/src/tof_to_scalar_Q.hpp
 */
#ifndef _TOF_TO_SCALAR_Q_HPP
#define _TOF_TO_SCALAR_Q_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include <cmath>
#include <stdexcept>

namespace AxisManip
{
  // 3.17
  template <typename NumT>
  std::string
  tof_to_scalar_Q(const Nessi::Vector<NumT> & tof,
                  const Nessi::Vector<NumT> & tof_err2,
                  const NumT pathlength,
                  const NumT pathlength_err2,
                  const NumT polar,
                  const NumT polar_err2,
                  Nessi::Vector<NumT> & Q,
                  Nessi::Vector<NumT> & Q_err2,
                  void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    NumT a2;
    NumT b;
    NumT term1;
    NumT term2;

    warn = __tof_to_scalar_Q_static(pathlength, pathlength_err2, polar,
                                    polar_err2, a2, b, term1, term2);
    if (!warn.empty())
      {
        retstr += warn;
      }

    size_t size_tof = tof.size();
    for (size_t i = 0; i < size_tof; ++i)
      {
        warn = __tof_to_scalar_Q_dynamic(tof[i], tof_err2[i], Q[i], Q_err2[i], 
                                         a2, b, term1, term2);

        if (!warn.empty())
          {
            retstr += warn;
          }
      }



    return retstr;
  }

  // 3.17
  template <typename NumT>
  std::string
  tof_to_scalar_Q(const NumT tof,
                  const NumT tof_err2,
                  const NumT pathlength,
                  const NumT pathlength_err2,
                  const NumT polar,
                  const NumT polar_err2,
                  NumT & Q,
                  NumT & Q_err2,
                  void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    NumT a2;
    NumT b;
    NumT term1;
    NumT term2;

    warn = __tof_to_scalar_Q_static(pathlength, pathlength_err2, polar,
                                    polar_err2, a2, b, term1, term2);
    if (!warn.empty())
      {
        retstr += warn;
      }

    warn = __tof_to_scalar_Q_dynamic(tof, tof_err2, Q, Q_err2, a2, b, 
                                     term1, term2);

    if (!warn.empty())
      {
        retstr += warn;
      }

    return retstr;
  }

  /**
   * \ingroup tof_to_scalar_Q
   *
   * This is a PRIVATE helper function for tof_to_scalar_Q that calculates the
   * parameters invariant across the array calculation.
   *
   * \param pathlength (INPUT) same as the parameter in tof_to_scalar_Q()
   * \param pathlength_err2 (INPUT) same as the parameter in tof_to_scalar_Q()
   * \param polar (INPUT) same as the parameter in tof_to_scalar_Q()
   * \param polar_err2 (INPUT) same as the parameter in tof_to_scalar_Q()
   * \param a2 (OUTPUT) \f$=(4\pi m_n/h)^2\f$
   * \param b (OUTPUT) \f$=4\pi m_n\times pathlength\times 
   *                   sin(polar/2)/h\f$
   * \param term1 (OUTPUT) \f$=\sin^2(polar/2)\times pathlength\_err2 + 
   *                       \cos^2(polar/2)\times pathlength^2\times 
   *                       polar\_err2/4\f$
   * \param term2 (OUTPUT) \f$\sin^2(polar/2)\times pathlength^2\f$
   */
  template <typename NumT>
  std::string
  __tof_to_scalar_Q_static(const NumT pathlength,
                           const NumT pathlength_err2,
                           const NumT polar,
                           const NumT polar_err2,
                           NumT & a2,
                           NumT & b,
                           NumT & term1,
                           NumT & term2)
  {
    NumT a = static_cast<NumT>(1./ PhysConst::H_OVER_MNEUT);
    a *= static_cast<NumT>(4. * PhysConst::PI);
    a2 = a * a;

    NumT cang = static_cast<NumT>(std::cos(static_cast<double>(polar / 2.0)));
    NumT cang2 = cang * cang;
    NumT sang = static_cast<NumT>(std::sin(static_cast<double>(polar / 2.0)));
    NumT sang2 = sang * sang;

    b = a * pathlength * sang;

    NumT pathlength2 = pathlength * pathlength;

    term1 = (sang2 * pathlength_err2) + 
      (cang2 * pathlength2 * polar_err2 / static_cast<NumT>(4.0));

    term2 = sang2 * pathlength2;

    return std::string(Nessi::EMPTY_WARN);
  }

  /**
   * \ingroup tof_to_scalar_Q
   *
   * This is a PRIVATE helper function for tof_to_scalar_Q that calculates the
   * scalar_Q and its uncertainty.
   *
   * \param tof (INPUT) same as the parameter in tof_to_scalar_Q()
   * \param tof_err2 (INPUT) same as the parameter in tof_to_scalar_Q()
   * \param Q (OUTPUT) same as the parameter in tof_to_scalar_Q()
   * \param Q_err2 (OUTPUT) same as the parameter in tof_to_scalar_Q()
   * \param a2 (INPUT) same as the parameter in __tof_to_scalar_Q_static()
   * \param b (INPUT) same as the parameter in __tof_to_scalar_Q_static()
   * \param term1 (INPUT) same as the parameter in __tof_to_scalar_Q_static()
   * \param term2 (INPUT) same as the parameter in __tof_to_scalar_Q_static()
   */
  template <typename NumT>
  std::string
  __tof_to_scalar_Q_dynamic(const NumT tof,
                            const NumT tof_err2,
                            NumT & Q,
                            NumT & Q_err2,
                            const NumT a2,
                            const NumT b,
                            const NumT term1,
                            const NumT term2)
  {
    Q = b / tof;

    NumT tof2 = tof * tof;

    Q_err2 = (term2 * tof_err2) / tof2;
    Q_err2 += term1;
    Q_err2 *= (a2 / tof2);

    return Nessi::EMPTY_WARN;
  }

} // AxisManip

#endif // _TOF_TO_SCALAR_Q_HPP
