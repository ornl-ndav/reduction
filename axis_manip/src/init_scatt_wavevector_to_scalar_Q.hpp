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
 * \file axis_manip/src/init_scatt_wavevector_to_scalar_Q.hpp
 */
#ifndef _INIT_SCATT_WAVEVECTOR_TO_SCALAR_Q_HPP
#define _INIT_SCATT_WAVEVECTOR_TO_SCALAR_Q_HPP 1

#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <cmath>
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the init_scatt_wavevector_to_scalar_Q function name
  const std::string
  iswtsq_func_str = "AxisManip::init_scatt_wavevector_to_scalar_Q";

  // 3.33
  template <typename NumT>
  std::string
  init_scatt_wavevector_to_scalar_Q(
                                    const Nessi::Vector<NumT> & initial_wavevector,
                                    const Nessi::Vector<NumT> & initial_wavevector_err2,
                                    const Nessi::Vector<NumT> & final_wavevector,
                                    const Nessi::Vector<NumT> & final_wavevector_err2,
                                    const NumT polar_angle,
                                    const NumT polar_angle_err2,
                                    Nessi::Vector<NumT> & Q,
                                    Nessi::Vector<NumT> & Q_err2,
                                    void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector, final_wavevector, Q);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector_err2,
                                  final_wavevector_err2, Q_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (v,v): err2 "+e.what());
      }

    // check that the initial_wavevector arrays are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector, initial_wavevector_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtsq_func_str
                                    +" (v,v): initial_wavevector "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT b;
    NumT sang;

    // fill the local variables
    retstr += __init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, b,
                                                         sang);

    // do the calculation
    size_t size_wavevector=initial_wavevector.size();
    for (size_t i = 0 ; i < size_wavevector ; ++i)
      {
        retstr += 
          __init_scatt_wavevector_to_scalar_Q_dynamic(
                                                      initial_wavevector[i],
                                                      initial_wavevector_err2[i],
                                                      final_wavevector[i],
                                                      final_wavevector_err2[i],
                                                      polar_angle_err2, a, b,
                                                      sang, Q[i], Q_err2[i]);
      }

    return retstr;
  }

  // 3.33
  template <typename NumT>
  std::string
  init_scatt_wavevector_to_scalar_Q(
                                    const NumT initial_wavevector,
                                    const NumT initial_wavevector_err2,
                                    const Nessi::Vector<NumT> & final_wavevector,
                                    const Nessi::Vector<NumT> & final_wavevector_err2,
                                    const NumT polar_angle,
                                    const NumT polar_angle_err2,
                                    Nessi::Vector<NumT> & Q,
                                    Nessi::Vector<NumT> & Q_err2,
                                    void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(final_wavevector, Q);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (s,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(final_wavevector_err2, Q_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (s,v): err2 "+e.what());
      }

    // check that the final_wavevector arrays are of proper size
    try
      {
        Utils::check_sizes_square(final_wavevector, final_wavevector_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtsq_func_str
                                    +" (s,v): final_wavevector "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT b;
    NumT sang;

    // fill the local variables
    retstr += __init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, b,
                                                         sang);

    // do the calculation
    size_t size_wavevector=final_wavevector.size();
    for (size_t i = 0 ; i < size_wavevector ; ++i)
      {
        retstr += 
          __init_scatt_wavevector_to_scalar_Q_dynamic(
                                                      initial_wavevector,
                                                      initial_wavevector_err2,
                                                      final_wavevector[i],
                                                      final_wavevector_err2[i],
                                                      polar_angle_err2, a, b,
                                                      sang, Q[i], Q_err2[i]);
      }

    return retstr;
  }

  // 3.33
  template <typename NumT>
  std::string
  init_scatt_wavevector_to_scalar_Q(
                                    const Nessi::Vector<NumT> & initial_wavevector,
                                    const Nessi::Vector<NumT> & initial_wavevector_err2,
                                    const NumT final_wavevector,
                                    const NumT final_wavevector_err2,
                                    const NumT polar_angle,
                                    const NumT polar_angle_err2,
                                    Nessi::Vector<NumT> & Q,
                                    Nessi::Vector<NumT> & Q_err2,
                                    void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector, Q);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (v,s): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector_err2, Q_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (v,s): err2 "+e.what());
      }

    // check that the initial_wavevector arrays are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector, initial_wavevector_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtsq_func_str
                                    +" (v,s): initial_wavevector "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT b;
    NumT c;

    // fill the local variables
    retstr += __init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, b,
                                                         c);
    // do the calculation
    size_t size_wavevector=initial_wavevector.size();
    for (size_t i = 0 ; i < size_wavevector ; ++i)
      {
        retstr += 
          __init_scatt_wavevector_to_scalar_Q_dynamic(
                                                      initial_wavevector[i],
                                                      initial_wavevector_err2[i],
                                                      final_wavevector,
                                                      final_wavevector_err2,
                                                      polar_angle_err2, a, b,
                                                      c, Q[i], Q_err2[i]);
      }

    return retstr;
  }

  // 3.33
  template <typename NumT>
  std::string
  init_scatt_wavevector_to_scalar_Q(
                                    const NumT initial_wavevector,
                                    const NumT initial_wavevector_err2,
                                    const NumT final_wavevector,
                                    const NumT final_wavevector_err2,
                                    const NumT polar_angle,
                                    const NumT polar_angle_err2,
                                    NumT & Q,
                                    NumT & Q_err2,
                                    void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT b;
    NumT c;

    // fill the local variables
    retstr += __init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, b,
                                                         c);
    // do the calculation
    retstr += 
      __init_scatt_wavevector_to_scalar_Q_dynamic(initial_wavevector,
                                                  initial_wavevector_err2,
                                                  final_wavevector,
                                                  final_wavevector_err2,
                                                  polar_angle_err2, a, b,
                                                  c, Q, Q_err2);

    return retstr;
  }

  /**
   * \ingroup init_scatt_wavevector_to_scalar_Q
   *
   * This is a PRIVATE helper function for
   * init_scatt_wavevector_to_scalar_Q that calculates parameters
   * invariant across array calculation.
   *
   * \param polar_angle (INPUT) same as parameter in
   * init_scatt_wavevector_to_scalar_Q()
   * \param a (OUTPUT) \f$=2\times\cos(polar\_angle)\f$
   * \param b (OUTPUT) \f$=\cos(polar\_angle)\f$
   * \param c (OUTPUT) \f$=\sin(polar\_angle)\f$
   */
  template <typename NumT>
  std::string
  __init_scatt_wavevector_to_scalar_Q_static(const NumT polar_angle,
                                             NumT & a,
                                             NumT & b,
                                             NumT & c)
  {
    a = static_cast<NumT>(2. * std::cos(static_cast<double>(polar_angle)));
    b = static_cast<NumT>(std::cos(static_cast<double>(polar_angle)));
    c = static_cast<NumT>(std::sin(static_cast<double>(polar_angle)));

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup init_scatt_wavevector_to_scalar_Q
   *
   * This is a PRIVATE helper function for
   * init_scatt_wavevector_to_scalar_Q that calculates the scalar
   * momentum transfer and its uncertainty
   *
   * \param initial_wavevector (INPUT) same as parameter in
   * init_scatt_wavevector_to_scalar_Q()
   * \param initial_wavevector_err2 (INPUT) same as parameter in
   * init_scatt_wavevector_to_scalar_Q()
   * \param final_wavevector (INPUT) same as parameter in
   * init_scatt_wavevector_to_scalar_Q()
   * \param final_wavevector_err2 (INPUT) same as parameter in
   * init_scatt_wavevector_to_scalar_Q()
   * \param polar_angle_err2 (INPUT) same as parameter in
   * init_scatt_wavevector_to_scalar_Q()
   * \param a (INPUT) same as a parameter of
   * __init_scatt_wavevector_to_scalar_Q_static()
   * \param b (INPUT) same as b parameter of
   * __init_scatt_wavevector_to_scalar_Q_static()
   * \param c (INPUT) same as c parameter of
   * __init_scatt_wavevector_to_scalar_Q_static()
   * \param Q (OUTPUT) same as parameter in
   * init_scatt_wavevector_to_scalar_Q()
   * \param Q_err2 (OUTPUT) same as parameter in
   * init_scatt_wavevector_to_scalar_Q()
   */
  template <typename NumT>
  std::string
  __init_scatt_wavevector_to_scalar_Q_dynamic(
                                            const NumT initial_wavevector,
                                            const NumT initial_wavevector_err2,
                                            const NumT final_wavevector,
                                            const NumT final_wavevector_err2,
                                            const NumT polar_angle_err2,
                                            const NumT a,
                                            const NumT b,
                                            const NumT c,
                                            NumT & Q,
                                            NumT & Q_err2)
  {
    NumT ki2 = initial_wavevector * initial_wavevector;
    NumT kf2 = final_wavevector * final_wavevector;
    NumT akikf = a * initial_wavevector * final_wavevector;

    Q = static_cast<NumT>
      (std::sqrt(static_cast<double>(ki2 + kf2 - akikf)));

    NumT termi2 = initial_wavevector - (final_wavevector * b);
    termi2 = termi2 * termi2;
    NumT termf2 = final_wavevector - (initial_wavevector * b);
    termf2 = termf2 * termf2;

    NumT e2 = final_wavevector * initial_wavevector;
    e2 = e2 * c;
    e2 = e2 * e2;

    NumT front = static_cast<NumT>(1.) / (Q * Q);

    Q_err2 = final_wavevector_err2 * termf2;
    Q_err2 += initial_wavevector_err2 * termi2;
    Q_err2 += (polar_angle_err2 * e2);
    Q_err2 *= front;

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _INIT_SCATT_WAVEVECTOR_TO_SCALAR_Q_HPP
