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
 * \file axis_manip/src/d_spacing_to_tof_focused_det.hpp
 */
#ifndef _D_SPACING_TO_TOF_FOCUSED_DET_HPP
#define _D_SPACING_TO_TOF_FOCUSED_DET_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <cmath>
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the d_spacing_to_tof_focused_det function name
  const std::string dsttfd_func_str = "AxisManip::d_spacing_to_tof_focused_det";

  // 3.39
  template <typename NumT>
  std::string
  d_spacing_to_tof_focused_det(const Nessi::Vector<NumT> & d_spacing,
                               const Nessi::Vector<NumT> & d_spacing_err2,
                               const NumT pathlength_focused,
                               const NumT pathlength_focused_err2,
                               const NumT polar_angle_focused,
                               const NumT polar_angle_focused_err2,
                               Nessi::Vector<NumT> & tof,
                               Nessi::Vector<NumT> & tof_err2,
                               void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(d_spacing, tof);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(dsttfd_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(d_spacing_err2, tof_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(dsttfd_func_str+" (v,v): err2 "+e.what());
      }

    // check that the d_spacing arrays are of proper size
    try
      {
        Utils::check_sizes_square(d_spacing, d_spacing_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(dsttfd_func_str+" (v,v): tof "+e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT mh;
    NumT mh2;
    NumT sin;
    NumT sin2;
    NumT cos;
    NumT cos2;

    // fill the local variables
    retstr += __d_spacing_to_tof_focused_det_static(polar_angle_focused,
                                                    a, a2, mh, mh2,
                                                    sin, sin2, cos, cos2);

    // do the calculation
    size_t size_d_spacing = d_spacing.size();
    for (size_t i = 0; i < size_d_spacing; ++i)
      {
        retstr += __d_spacing_to_tof_focused_det_dynamic(d_spacing[i], 
                                                         d_spacing_err2[i],
                                                         pathlength_focused,
                                                         pathlength_focused_err2,
                                                         polar_angle_focused_err2,
                                                         a, a2, mh, mh2,
                                                         sin, sin2, cos, cos2,
                                                         tof[i],
                                                         tof_err2[i]);
      }

    return retstr;
  }

  // 3.39
  template <typename NumT>
    std::string
    d_spacing_to_tof_focused_det(const NumT d_spacing,
                                 const NumT d_spacing_err2,
                                 const NumT pathlength_focused,
                                 const NumT pathlength_focused_err2,
                                 const NumT polar_focused,
                                 const NumT polar_focused_err2,
                                 NumT & tof,
                                 NumT & tof_err2,
                                 void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT mh;
    NumT mh2;
    NumT sin;
    NumT sin2;
    NumT cos;
    NumT cos2;

    // fill the local variables
    retstr += __d_spacing_to_tof_focused_det_static(polar_focused,
                                                    a, a2, mh, mh2,
                                                    sin, sin2, cos, cos2);
                                                   
    // do the calculation
    retstr += __d_spacing_to_tof_focused_det_dynamic(d_spacing, 
                                                     d_spacing_err2,
                                                     pathlength_focused,
                                                     pathlength_focused_err2,
                                                     polar_focused_err2,
                                                     a, a2, mh, mh2,
                                                     sin, sin2, cos, cos2,
                                                     tof,
                                                     tof_err2);
    return retstr;
  }

/**
   * \ingroup d_spacing_to_tof_focused_det
   *
   * This is a PRIVATE helper function for d_spacing_to_tof_focused_det 
   * that calculates parameters invariant across array calculation.
   *
   * \param polar_focused (INPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param a (OUTPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param a2 (OUTPUT) \f$=a*a\f$
   * \param mh (OUTPUT) Planck's constant divided by the mass of the neutron
   * \param mh2 (OUTPUT) square of Planck's constant divided by the mass of 
   * the neutron
   * \param sin (OUTPUT) the sinus of the angle between positive z axis and
   * direction of the scattered neutrons.
   * \param sin2 (OUTPUT)the square of the sinus of the angle between 
   * positive z axis and direction of the scattered neutrons
   * \param cos (OUTPUT) the cosinus of the angle between positive z axis and
   * direction of the scattered neutrons.
   * \param cos2 (OUTPUT) the square of the cosinus of the angle between 
   * positive z axis and direction of the scattered neutrons
   */
  template <typename NumT>
  std::string  
  __d_spacing_to_tof_focused_det_static(const NumT polar_focused,
                                        NumT & a,
                                        NumT & a2,
                                        NumT & mh,
                                        NumT & mh2,
                                        NumT & sin,
                                        NumT & sin2,
                                        NumT & cos,
                                        NumT & cos2)
  {
    // calculate the factor to multiply each element by
    a = static_cast<NumT>(4.0 * PhysConst::PI);
    a2 = a * a;
    mh = static_cast<NumT>(1.0 / PhysConst::H_OVER_MNEUT);
    mh2 = mh * mh;
    sin = static_cast<NumT>(std::sin(static_cast<double>(polar_focused)));
    sin2 = sin * sin;
    cos = static_cast<NumT>(std::cos(static_cast<double>(polar_focused)));
    cos2 = cos * cos;

    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup d_spacing_to_tof_focused_det
   *
   * This is a PRIVATE helper function for d_spacing_to_tof_focused_det that
   * calculates the tof and its uncertainty
   *
   * \param d_spacing (INPUT) same as the parameter in
   * d_spacing_to_tof_focused_det()
   * \param d_spacing_err2 (INPUT) same as the parameter in
   * d_spacing_to_tof_focused_det()
   * \param pathlength_focused (INPUT) same as the parameter in
   * d_spacing_to_tof_focused_det()
   * \param pathlength_focused_err2 (INPUT) same as the parameter 
   * in d_spacing_to_tof_focused_det()
   * \param polar_focused_err2 (INPUT) same as the parameter 
   * in d_spacing_to_tof_focused_det()
   * \param a (INPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param a2 (INPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param mh (INPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param mh2 (INPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param sin (INPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param sin2 (INPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param cos (INPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param cos2 (INPUT) same as the parameter in
   * __d_spacing_to_tof_focused_det_static()
   * \param  tof (OUTPUT) same as the parameter in
   * d_spacing_to_tof_focused_det()
   * \param  tof_err2 (OUTPUT) same as the parameter in
   * d_spacing_to_tof_focused_det()
   */
  template <typename NumT>
  std::string  
  __d_spacing_to_tof_focused_det_dynamic(const NumT d_spacing, 
                                         const NumT d_spacing_err2,
                                         const NumT pathlength_focused,
                                         const NumT pathlength_focused_err2,
                                         const NumT polar_focused_err2,
                                         const NumT a, 
                                         const NumT a2, 
                                         const NumT mh, 
                                         const NumT mh2,
                                         const NumT sin, 
                                         const NumT sin2, 
                                         const NumT cos, 
                                         const NumT cos2,
                                         NumT & tof,
                                         NumT & tof_err2)

  {
    NumT lf2 = pathlength_focused * pathlength_focused;
    NumT d2 = d_spacing * d_spacing;

    // calculate the value
    tof = a * mh * pathlength_focused * sin * d_spacing;

    // calculate the uncertainty
    tof_err2 = static_cast<NumT>((a2 * mh2 * sin2 * d2 * pathlength_focused_err2)
      + (a2 * mh2 * lf2 * cos2 * d2 * polar_focused_err2 / 4.0)
      + (a2 * mh2 * lf2 * sin2 * d_spacing_err2));

    return Nessi::EMPTY_WARN;
  }

} // AxisManip

#endif // _D_SPACING_TO_TOF_FOCUSED_DET_HPP
