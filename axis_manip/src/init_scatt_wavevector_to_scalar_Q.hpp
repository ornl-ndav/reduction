/**
 * $Id$
 *
 * \file axis_manip/src/init_scatt_wavevector_to_scalar_Q.hpp
 */
#ifndef _INIT_SCATT_WAVEVECTOR_TO_SCALAR_Q_HPP
#define _INIT_SCATT_WAVEVECTOR_TO_SCALAR_Q_HPP 1

#include "conversions.hpp"
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
    catch(std::invalid_argument e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector_err2,
  			  final_wavevector_err2, Q_err2);
      }
    catch(std::invalid_argument e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (v,v): err2 "+e.what());
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT a;
    NumT b;
    NumT sang;

    // fill the local variables
    warn=__init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, b,
                                                    sang);
    if(!(warn.empty()))
      retstr+=warn;

    // do the calculation
    size_t size_wavevector=initial_wavevector.size();
    for (size_t i = 0 ; i < size_wavevector ; ++i)
      {
        warn=__init_scatt_wavevector_to_scalar_Q_dynamic(
                                                    initial_wavevector[i],
                                                    initial_wavevector_err2[i],
                                                    final_wavevector[i],
                                                    final_wavevector_err2[i],
                                                    polar_angle_err2, a, b,
                                                    sang, Q[i], Q_err2[i]);
        if(!(warn.empty()))
          retstr+=warn;
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
    catch(std::invalid_argument e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (s,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(final_wavevector_err2, Q_err2);
      }
    catch(std::invalid_argument e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (s,v): err2 "+e.what());
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT a;
    NumT b;
    NumT sang;

    // fill the local variables
    warn=__init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, b,
                                                    sang);
    if(!(warn.empty()))
      retstr+=warn;

    // do the calculation
    size_t size_wavevector=final_wavevector.size();
    for (size_t i = 0 ; i < size_wavevector ; ++i)
      {
        warn=__init_scatt_wavevector_to_scalar_Q_dynamic(
                                                    initial_wavevector,
                                                    initial_wavevector_err2,
                                                    final_wavevector[i],
                                                    final_wavevector_err2[i],
                                                    polar_angle_err2, a, b,
                                                    sang, Q[i], Q_err2[i]);
        if(!(warn.empty()))
          retstr+=warn;
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
    catch(std::invalid_argument e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (v,s): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector_err2, Q_err2);
      }
    catch(std::invalid_argument e)
      {
        throw std::invalid_argument(iswtsq_func_str+" (v,s): err2 "+e.what());
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT a;
    NumT b;
    NumT c;

    // fill the local variables
    warn=__init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, b,
                                                    c);
    if(!(warn.empty()))
      retstr+=warn;

    // do the calculation
    size_t size_wavevector=initial_wavevector.size();
    for (size_t i = 0 ; i < size_wavevector ; ++i)
      {
        warn=__init_scatt_wavevector_to_scalar_Q_dynamic(
                                                    initial_wavevector[i],
                                                    initial_wavevector_err2[i],
                                                    final_wavevector,
                                                    final_wavevector_err2,
                                                    polar_angle_err2, a, b,
                                                    c, Q[i], Q_err2[i]);
        if(!(warn.empty()))
          retstr+=warn;
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
    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT a;
    NumT b;
    NumT c;

    // fill the local variables
    warn=__init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, b,
                                                    c);
    if(!(warn.empty()))
      retstr+=warn;

    // do the calculation
    warn=__init_scatt_wavevector_to_scalar_Q_dynamic(initial_wavevector,
                                                     initial_wavevector_err2,
                                                     final_wavevector,
                                                     final_wavevector_err2,
                                                     polar_angle_err2, a, b,
                                                     c, Q, Q_err2);
    if(!(warn.empty()))
      retstr+=warn;

    return retstr;
  }

  /**
   * \ingroup init_scatt_wavevector_to_scalar_Q
   *
   * This is a PRIVATE helper function for
   * init_scatt_wavevector_to_scalar_Q that calculates parameters
   * invariant across array calculation.
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

    return std::string("");
  }

  /**
   * \ingroup init_scatt_wavevector_to_scalar_Q
   *
   * This is a PRIVATE helper function for
   * init_scatt_wavevector_to_scalar_Q that calculates the scalar
   * momentum transfer and its uncertainty
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

    return std::string("");
  }
} // AxisManip

#endif // _INIT_SCATT_WAVEVECTOR_TO_SCALAR_Q_HPP
