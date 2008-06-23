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
 * \file axis_manip/src/init_scatt_wavevector_to_Q.hpp
 */
#ifndef _INIT_SCATT_WAVEVECTOR_TO_Q_HPP
#define _INIT_SCATT_WAVEVECTOR_TO_Q_HPP 1

#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <cmath>
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the init_scatt_wavevector_to_Q function name
  const std::string
  iswtq_func_str = "AxisManip::init_scatt_wavevector_to_Q";

  // 3.32
  template <typename NumT>
  std::string
  init_scatt_wavevector_to_Q(const Nessi::Vector<NumT> & initial_wavevector,
                             const Nessi::Vector<NumT> & initial_wavevector_err2,
                             const Nessi::Vector<NumT> & final_wavevector,
                             const Nessi::Vector<NumT> & final_wavevector_err2,
                             const NumT azimuthal_angle,
                             const NumT azimuthal_angle_err2,
                             const NumT polar_angle,
                             const NumT polar_angle_err2,
                             Nessi::Vector<NumT> & Qx,
                             Nessi::Vector<NumT> & Qx_err2,
                             Nessi::Vector<NumT> & Qy,
                             Nessi::Vector<NumT> & Qy_err2,
                             Nessi::Vector<NumT> & Qz,
                             Nessi::Vector<NumT> & Qz_err2,
                             void *temp=NULL)
 {
   // check that the values are of proper size
   try
     {
       Utils::check_sizes_square(initial_wavevector, final_wavevector, Qx);
     }
   catch(std::invalid_argument &e)
     {
       throw std::invalid_argument(iswtq_func_str+" (v,v): data "+e.what());
     }

   try
     {
       Utils::check_sizes_square(initial_wavevector, Qy, Qz);
     }
   catch(std::invalid_argument &e)
     {
       throw std::invalid_argument(iswtq_func_str+" (v,v): data "+e.what());
     }
       

   // check that the uncertainties are of proper size
   try
     {
       Utils::check_sizes_square(initial_wavevector_err2, 
                                 final_wavevector_err2, Qx_err2);
      }
   catch(std::invalid_argument &e)
     {
       throw std::invalid_argument(iswtq_func_str+" (v,v): err2 "+e.what());
     }

   try
     {
       Utils::check_sizes_square(initial_wavevector_err2, Qy_err2, Qz_err2);
      }
   catch(std::invalid_argument &e)
     {
       throw std::invalid_argument(iswtq_func_str+" (v,v): err2 "+e.what());
     }

   // check that the initial_wavevector arrays are of proper size
   try
     {
       Utils::check_sizes_square(initial_wavevector, initial_wavevector_err2);
     }
   catch(std::invalid_argument &e)
     {
       throw std::invalid_argument(iswtq_func_str
                                    +" (v,v): initial_wavevector "+e.what());
     }

   std::string retstr(Nessi::EMPTY_WARN); // the warning string

   // allocate local variables
   NumT a;
   NumT a2;
   NumT b;
   NumT b2;
   NumT c;
   NumT c2;
   NumT d;
   NumT d2;

   // fill the local variables
   retstr += __init_scatt_wavevector_to_Q_static(azimuthal_angle, 
                                                 polar_angle, 
                                                 a, a2, b, b2,
                                                 c, c2, d, d2);

   // do the calculation
   size_t size_wavevector=initial_wavevector.size();
	#pragma omp parallel for
   	for (int i = 0 ; i < static_cast<int>(size_wavevector) ; ++i)
    {
       std::string tempS =
         __init_scatt_wavevector_to_Q_dynamic(initial_wavevector[i],
                                              initial_wavevector_err2[i],
                                              final_wavevector[i],
                                              final_wavevector_err2[i],
                                              azimuthal_angle,
                                              azimuthal_angle_err2,
                                              polar_angle,
                                              polar_angle_err2, 
                                              a, a2, b, b2,
                                              c, c2, d, d2,
                                              Qx[i], 
                                              Qx_err2[i],
                                              Qy[i],
                                              Qy_err2[i],
                                              Qz[i],
                                              Qz_err2[i]);
		if (!tempS.empty())
		{
			#pragma omp critical
			{
				retstr += tempS;
			}
		}
   	}

   return retstr;
 }

  template <typename NumT>
  std::string
  init_scatt_wavevector_to_Q(const NumT initial_wavevector,
                             const NumT initial_wavevector_err2,
                             const Nessi::Vector<NumT> & final_wavevector,
                             const Nessi::Vector<NumT> & final_wavevector_err2,
                             const NumT azimuthal,
                             const NumT azimuthal_err2,
                             const NumT polar,
                             const NumT polar_err2,
                             Nessi::Vector<NumT> & Qx,
                             Nessi::Vector<NumT> & Qx_err2,
                             Nessi::Vector<NumT> & Qy,
                             Nessi::Vector<NumT> & Qy_err2,
                             Nessi::Vector<NumT> & Qz,
                             Nessi::Vector<NumT> & Qz_err2,
                             void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(final_wavevector, Qx, Qy);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str+" (s,v): data "+e.what());
      }

    try
      {
        Utils::check_sizes_square(final_wavevector, Qz);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str+" (s,v): data "+e.what());
      }
    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(final_wavevector_err2, Qx_err2, Qy_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str+" (s,v): err2 "+e.what());
      }

    try
      {
        Utils::check_sizes_square(final_wavevector_err2, Qz_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str+" (s,v): err2 "+e.what());
      }

    // check that the final_wavevector arrays are of proper size
    try
      {
        Utils::check_sizes_square(final_wavevector, final_wavevector_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str
                                    +" (s,v): final_wavevector "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT b;
    NumT b2;
    NumT c;
    NumT c2;
    NumT d;
    NumT d2;

    // fill the local variables
    retstr += __init_scatt_wavevector_to_Q_static(azimuthal, 
                                                  polar, 
                                                  a, a2, b, b2,
                                                  c, c2, d, d2);

    // do the calculation
    size_t size_wavevector=final_wavevector.size();

	#pragma omp parallel for
    for (int i = 0 ; i < static_cast<int>(size_wavevector) ; ++i)
    {
        std::string tempS =
          __init_scatt_wavevector_to_Q_dynamic(initial_wavevector,
                                               initial_wavevector_err2,
                                               final_wavevector[i],
                                               final_wavevector_err2[i],
                                               azimuthal,
                                               azimuthal_err2,
                                               polar,
                                               polar_err2, 
                                               a, a2, b, b2,
                                               c, c2, d, d2,
                                               Qx[i], 
                                               Qx_err2[i],
                                               Qy[i],
                                               Qy_err2[i],
                                               Qz[i],
                                               Qz_err2[i]);
		if (!tempS.empty())
		{
			#pragma omp critical
			{
				retstr += tempS;
			}
		}
    }

    return retstr; 
  }

  template <typename NumT>
  std::string
  init_scatt_wavevector_to_Q(const Nessi::Vector<NumT> & initial_wavevector,
                             const Nessi::Vector<NumT> & initial_wavevector_err2,
                             const NumT final_wavevector,
                             const NumT final_wavevector_err2,
                             const NumT azimuthal,
                             const NumT azimuthal_err2,
                             const NumT polar,
                             const NumT polar_err2,
                             Nessi::Vector<NumT> & Qx,
                             Nessi::Vector<NumT> & Qx_err2,
                             Nessi::Vector<NumT> & Qy,
                             Nessi::Vector<NumT> & Qy_err2,
                             Nessi::Vector<NumT> & Qz,
                             Nessi::Vector<NumT> & Qz_err2,
                             void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector, Qx, Qy);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str+" (v,s): data "+e.what());
      }

    try
      {
        Utils::check_sizes_square(initial_wavevector, Qz);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str+" (v,s): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector_err2, Qx_err2, Qy_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str+" (v,s): err2 "+e.what());
      }

    try
      {
        Utils::check_sizes_square(initial_wavevector_err2, Qz_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str+" (v,s): err2 "+e.what());
      }

    // check that the initial_wavevector arrays are of proper size
    try
      {
        Utils::check_sizes_square(initial_wavevector, initial_wavevector_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(iswtq_func_str
                                    +" (v,s): initial_wavevector "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT b;
    NumT b2;
    NumT c;
    NumT c2;
    NumT d;
    NumT d2;

    // fill the local variables
    retstr += __init_scatt_wavevector_to_Q_static(azimuthal, 
                                                  polar, 
                                                  a, a2, b, b2,
                                                  c, c2, d, d2);
    // do the calculation
    size_t size_wavevector=initial_wavevector.size();

	#pragma omp parallel for
    for (int i = 0 ; i < static_cast<int>(size_wavevector) ; ++i)
    {
        std::string tempS =
          __init_scatt_wavevector_to_Q_dynamic(initial_wavevector[i],
                                               initial_wavevector_err2[i],
                                               final_wavevector,
                                               final_wavevector_err2,
                                               azimuthal,
                                               azimuthal_err2,
                                               polar,
                                               polar_err2, 
                                               a, a2, b, b2,
                                               c, c2, d, d2,
                                               Qx[i], 
                                               Qx_err2[i],
                                               Qy[i],
                                               Qy_err2[i],
                                               Qz[i],
                                               Qz_err2[i]);
		if (!tempS.empty())
		{
			#pragma omp critical
			{
				retstr += tempS;
			}
		}
    }

    return retstr;
  }

  template <typename NumT>
  std::string
  init_scatt_wavevector_to_Q(const NumT initial_wavevector,
                             const NumT initial_wavevector_err2,
                             const NumT final_wavevector,
                             const NumT final_wavevector_err2,
                             const NumT azimuthal,
                             const NumT azimuthal_err2,
                             const NumT polar,
                             const NumT polar_err2,
                             NumT & Qx,
                             NumT & Qx_err2,
                             NumT & Qy,
                             NumT & Qy_err2,
                             NumT & Qz,
                             NumT & Qz_err2,
                             void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT b;
    NumT b2;
    NumT c;
    NumT c2;
    NumT d;
    NumT d2;

    // fill the local variables
    retstr += __init_scatt_wavevector_to_Q_static(azimuthal, 
                                                  polar, 
                                                  a, a2, b, b2,
                                                  c, c2, d, d2);
    
    // do the calculation
    retstr +=
      __init_scatt_wavevector_to_Q_dynamic(initial_wavevector,
                                           initial_wavevector_err2,
                                           final_wavevector,
                                           final_wavevector_err2,
                                           azimuthal,
                                           azimuthal_err2,
                                           polar,
                                           polar_err2, 
                                           a, a2, b, b2,
                                           c, c2, d, d2,
                                           Qx, 
                                           Qx_err2,
                                           Qy,
                                           Qy_err2,
                                           Qz,
                                           Qz_err2);

    return retstr;
  }
  
  /**
   * \ingroup init_scatt_wavevector_to_Q
   *
   * This is a PRIVATE helper function for
   * init_scatt_wavevector_to_Q that calculates parameters
   * invariant across array calculation.
   * 
   * \param azimuthal (INPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param polar (INPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param a (OUTPUT) \f$=\cos(azimuthal)\f$
   * \param a2 (OUTPUT) \f$=a*a\f$
   * \param b (OUTPUT) \f$=\sin(azimuthal)\f$
   * \param b2 (OUTPUT) \f$=b*b\f$
   * \param c (OUTPUT) \f$=\cos(polar)\f$
   * \param c2 (OUTPUT) \f$=c*c\f$
   * \param d (OUTPUT) \f$=\sin(polar)\f$
   * \param d2 (OUTPUT) \f$=d*d\f$
   */
  template <typename NumT>
  std::string
  __init_scatt_wavevector_to_Q_static(const NumT azimuthal, 
                                      const NumT polar, 
                                      NumT & a, 
                                      NumT & a2, 
                                      NumT & b, 
                                      NumT & b2,
                                      NumT & c, 
                                      NumT & c2, 
                                      NumT & d, 
                                      NumT & d2)

  {
    a = static_cast<NumT>(std::cos(static_cast<double>(azimuthal)));
    a2 = a * a;
    b = static_cast<NumT>(std::sin(static_cast<double>(azimuthal)));
    b2 = b * b;
    c = static_cast<NumT>(std::cos(static_cast<double>(polar)));
    c2 = c * c;
    d = static_cast<NumT>(std::sin(static_cast<double>(polar)));
    d2 = d * d;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup init_scatt_wavevector_to_Q
   *
   * This is a PRIVATE helper function for
   * init_scatt_wavevector_to_Q that calculates the 
   * momentum transfer and its uncertainty
   *
   * \param initial_wavevector (INPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param initial_wavevector_err2 (INPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param final_wavevector (INPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param final_wavevector_err2 (INPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param azimuthal (INPUT) same as parameter in init_scatt_wavevector_to_Q()
   * \param azimuthal_err2 (INPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param polar (INPUT) same as parameter in init_scatt_wavevector_to_Q()
   * \param polar_err2 (INPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param a (INPUT) same as a parameter of
   * __init_scatt_wavevector_to_Q_static()
   * \param a2 (INPUT) same as a2 parameter of
   * __init_scatt_wavevector_to_Q_static()
   * \param b (INPUT) same as b parameter of
   * __init_scatt_wavevector_to_Q_static()
   * \param b2 (INPUT) same as b2 parameter of
   * __init_scatt_wavevector_to_Q_static()
   * \param c (INPUT) same as c parameter of
   * __init_scatt_wavevector_to_Q_static()
   * \param c2 (INPUT) same as c2 parameter of
   * __init_scatt_wavevector_to_Q_static()
   * \param d (INPUT) same as d parameter of
   * __init_scatt_wavevector_to_Q_static()
   * \param d2 (INPUT) same as d2 parameter of
   * __init_scatt_wavevector_to_Q_static()
   * \param Qx (OUTPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param Qx_err2 (OUTPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param Qy (OUTPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param Qy_err2 (OUTPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param Qz (OUTPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   * \param Qz_err2 (OUTPUT) same as parameter in
   * init_scatt_wavevector_to_Q()
   *
   */
  template <typename NumT>
  std::string
  __init_scatt_wavevector_to_Q_dynamic(const NumT initial_wavevector,
                                       const NumT initial_wavevector_err2,
                                       const NumT final_wavevector,
                                       const NumT final_wavevector_err2,
                                       const NumT azimuthal,
                                       const NumT azimuthal_err2,
                                       const NumT polar,
                                       const NumT polar_err2,
                                       const NumT a,
                                       const NumT a2,
                                       const NumT b,
                                       const NumT b2,
                                       const NumT c,
                                       const NumT c2,
                                       const NumT d,
                                       const NumT d2,
                                       NumT & Qx,
                                       NumT & Qx_err2,
                                       NumT & Qy,
                                       NumT & Qy_err2,
                                       NumT & Qz,
                                       NumT & Qz_err2)
  
  {
    NumT kf = final_wavevector;
    NumT kf2 = kf * kf;

    Qx = static_cast<NumT>(-kf * a * d);
    Qy = static_cast<NumT>(-kf * b * d);
    Qz = static_cast<NumT>(initial_wavevector - (kf * c));

    Qx_err2 = static_cast<NumT>((a2 * d2 * final_wavevector_err2)
                                + (kf2 * b2 * d2 * azimuthal_err2)
                                + (kf2 * a2 * c2 * polar_err2));
    
    Qy_err2 = static_cast<NumT>((b2 * d2 * final_wavevector_err2)
                                + (kf2 * a2 * d2 * azimuthal_err2)
                                + (kf2 * b2 * c2 * polar_err2));

    Qz_err2 = static_cast<NumT>((initial_wavevector_err2)
                                + (c2 * final_wavevector_err2)
                                + (kf2 * d2 * polar_err2));

    

   

    return Nessi::EMPTY_WARN;
  }
} // AxisManip

#endif // _INIT_SCATT_WAVEVECTOR_TO_Q_HPP
