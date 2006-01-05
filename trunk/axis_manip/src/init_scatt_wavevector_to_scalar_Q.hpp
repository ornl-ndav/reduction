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
        std::string errstr("AxisManip::init_scatt_wavevector_to_scalar_Q: data ");
        Utils::check_sizes_square(errstr, initial_wavevector, final_wavevector,
                                  Q);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    // check that the uncertainties are of proper size
    try
      {
        std::string errstr("AxisManip::init_scatt_wavevector_to_scalar_Q: error ");
        Utils::check_sizes_square(errstr, initial_wavevector_err2,
                                  final_wavevector_err2, Q_err2);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT a;
    NumT pang;
    NumT sang;
    
    // fill the local variables
    warn=__init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, pang,
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
                                                    polar_angle_err2, a, pang,
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
        std::string errstr("AxisManip::init_scatt_wavevector_to_scalar_Q: data ");
        Utils::check_sizes_square(errstr, final_wavevector, Q);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    // check that the uncertainties are of proper size
    try
      {
        std::string errstr("AxisManip::init_scatt_wavevector_to_scalar_Q: error ");
        Utils::check_sizes_square(errstr, final_wavevector_err2, Q_err2);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT a;
    NumT pang;
    NumT sang;
    
    // fill the local variables
    warn=__init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, pang,
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
                                                    polar_angle_err2, a, pang,
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
        std::string errstr("AxisManip::init_scatt_wavevector_to_scalar_Q: data ");
        Utils::check_sizes_square(errstr, initial_wavevector, Q);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    // check that the uncertainties are of proper size
    try
      {
        std::string errstr("AxisManip::init_scatt_wavevector_to_scalar_Q: error ");
        Utils::check_sizes_square(errstr, initial_wavevector_err2, Q_err2);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT a;
    NumT pang;
    NumT sang;
    
    // fill the local variables
    warn=__init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, pang,
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
                                                    final_wavevector,
                                                    final_wavevector_err2,
                                                    polar_angle_err2, a, pang,
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
    NumT pang;
    NumT sang;
    
    // fill the local variables
    warn=__init_scatt_wavevector_to_scalar_Q_static(polar_angle, a, pang,
                                                    sang);
    if(!(warn.empty()))
      retstr+=warn;

    // do the calculation
    warn=__init_scatt_wavevector_to_scalar_Q_dynamic(initial_wavevector,
                                                     initial_wavevector_err2,
                                                     final_wavevector,
                                                     final_wavevector_err2,
                                                     polar_angle_err2, a, pang,
                                                     sang, Q, Q_err2);
    if(!(warn.empty()))
      retstr+=warn;

    return retstr;
  }

  /**
   * This is a PRIVATE helper function for
   * init_scatt_wavevector_to_scalar_Q that calculates parameters
   * invariant across array calculation.
   */
  template <typename NumT>
  std::string
  __init_scatt_wavevector_to_scalar_Q_static(const NumT polar_angle,
                                             NumT & a,
                                             NumT & pang,
                                             NumT & sang)
  {
    a = static_cast<NumT>(2 * std::cos(static_cast<double>(polar_angle)));
    pang = static_cast<NumT>(std::cos(static_cast<double>(polar_angle)));
    sang = static_cast<NumT>(std::sin(static_cast<double>(polar_angle)));
    
    return std::string("");
  }

  /**
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
                                            const NumT pang,
                                            const NumT sang,
                                            NumT & Q,
                                            NumT & Q_err2)
  {
    NumT ki2 = initial_wavevector * initial_wavevector;
    NumT kf2 = final_wavevector * final_wavevector;
    NumT akikf = a * initial_wavevector * final_wavevector;

    Q = static_cast<NumT>
      (std::sqrt(static_cast<double>(ki2 + kf2 - akikf)));

    NumT termi = initial_wavevector - (final_wavevector * pang);
    NumT termi2 = termi * termi;

    NumT termf = final_wavevector - (initial_wavevector * pang);
    NumT termf2 = termf * termf;

    NumT polar = final_wavevector * initial_wavevector;
    polar = polar * sang;
    NumT polar2 = polar * polar;

    NumT front = static_cast<NumT>(1) / (Q * Q);

    Q_err2 = final_wavevector_err2 * termf2;
    Q_err2 += initial_wavevector_err2 * termi2;
    Q_err2 += (polar_angle_err2 * polar2);
    Q_err2 *= front;

    return std::string("");
  }
} // AxisManip
#endif
