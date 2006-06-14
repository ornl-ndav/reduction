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
 * \file axis_manip/src/velocity_to_scalar_k.hpp
 */
#ifndef _VELOCITY_TO_SCALAR_K_HPP
#define _VELOCITY_TO_SCALAR_K_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the velocity_to_scalar_k function name
  const std::string vtsk_func_str = "AxisManip::velocity_to_scalar_k";

  // 3.23
  template <typename NumT>
  std::string
  velocity_to_scalar_k(const Nessi::Vector<NumT> & velocity,
                       const Nessi::Vector<NumT> & velocity_err2,
                       Nessi::Vector<NumT> & wavevector,
                       Nessi::Vector<NumT> & wavevector_err2,
                       void *temp=NULL)
  {
      // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(velocity,wavevector);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(vtsk_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(velocity_err2, wavevector_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(vtsk_func_str+" (v,v): err2 "+e.what());
      }

    // check that the velocity arrays are of proper size
    try
      {
        Utils::check_sizes_square(velocity,velocity_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(vtsk_func_str+" (v,v): velocity "
                                    +e.what());
      }
    std::string retstr(Nessi::EMPTY_WARN);

    NumT mh;
    NumT mh2;

    retstr += __velocity_to_scalar_k_static(mh,mh2);

    size_t sz = velocity.size();
    for (size_t i=0; i < sz; ++i)
      {
        retstr += __velocity_to_scalar_k_dynamic(velocity[i],
                                                 velocity_err2[i],
                                                 wavevector[i],
                                                 wavevector_err2[i],
                                                 mh,
                                                 mh2);
      }

    return retstr;
  }

  // 3.23
  template <typename NumT>
  std::string
  velocity_to_scalar_k(const NumT velocity,
                       const NumT velocity_err2,
                       NumT & wavevector,
                       NumT & wavevector_err2,
                       void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN);

    NumT mh;
    NumT mh2;

    retstr += __velocity_to_scalar_k_static(mh,mh2);

    retstr += __velocity_to_scalar_k_dynamic(velocity,
                                             velocity_err2,
                                             wavevector,
                                             wavevector_err2,
                                             mh,
                                             mh2);

    return retstr;
  }

  /**
   * \ingroup velocity_to_scalar_k
   *
   * This is a PRIVATE helper function for velocity_to_scalar_k that
   * calculates the parameters invariant across the array calculation.
   *
   * \param mh (OUTPUT) Planck's constant divided by the mass of the neutron
   * \param mh2 (OUTPUT) square of Planck's constant divided by the mass of 
   *                     the neutron
   */
  template <typename NumT>
  std::string
  __velocity_to_scalar_k_static(NumT & mh,
                                NumT & mh2)
  {
    mh = static_cast<NumT>(1.0/PhysConst::H_OVER_MNEUT);
    mh2 = mh*mh;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup velocity_to_scalar_k
   *
   * This is a PRIVATE helper function for velocity_to_scalar_k that
   * calculates the scalar_k and its uncertainty
   *
   * \param velocity (INPUT) same as parameter in velocity_to_scalar_k()
   * \param velocity_err2 (INPUT) same as parameter in velocity_to_scalar_k()
   * \param wavevector (OUTPUT) same as parameter in velocity_to_scalar_k()
   * \param wavevector_err2 (OUTPUT) same as parameter in velocity_to_scalar_k()
   * \param mh (INPUT) same as parameter in __velocity_to_scalar_k_static()
   * \param mh2 (INPUT) same as parameter in __velocity_to_scalar_k_static()
   */
  template <typename NumT>
  std::string
  __velocity_to_scalar_k_dynamic(const NumT velocity,
                                 const NumT velocity_err2,
                                 NumT & wavevector,
                                 NumT & wavevector_err2,
                                 const NumT mh,
                                 const NumT mh2)
  {
    wavevector = velocity * mh;
    wavevector_err2 = mh2 * velocity_err2;

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _VELOCITY_TO_SCALAR_K_HPP
