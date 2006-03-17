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
 * \file phys_const/inc/constants.hpp
 */
#ifndef _CONSTANTS_HPP
#define _CONSTANTS_HPP 1

/**
 * \namespace PhysConst
 *
 * \brief A collection of double precision constants useful in
 * time-of-flight neutron scattering
 *
 * The values for the constants collected here are taken or derived from
 * values provided in the following reference.
 *
 * P. J. Mohr and B. N. Taylor, "The 2002 CODATA Recommended Values of the
 * Fundamental Physical Constants, Web Version 4.0," available at
 * http://physics.nist.gov/constants. This database was developed by J. Baker,
 * M. Douma, and S. Kotochigova. (National Institute of Standards and
 * Technology, Gaithersburg, MD 20899, 9 December 2003).
 */
namespace PhysConst
{
  /**
   * Fundamental constants
   */

  /**
   * The value of Planck's constant, \f$h\f$, in units of \f$meV /
   * THz\f$
   */
  static const double H = 4.13566743;

  /**
   * The value of the mass of the neutron, \f$m_n\f$, in units of \f$grams\f$
   */
  static const double MNEUT = 1.67492728e-24;

  /**
   * The value of the energy equivalent mass of the neutron, \f$m_nc^2\f$, in
   * units of \f$meV\f$
   */
  static const double MNEUT_EEQ = 9.39565360e+11;

  /**
   * The value of the speed of light, \f$c\f$, in units of \f$Angstroms \times
   * THz\f$
   */
  static const double SPEED_OF_LIGHT = 2.99792458e+6;

  /**
   * The value of \f$\pi\f$ to 29 decimal digits.
   */
  static const double PI = 3.14159265358979323846264338328;

  /**
   * The value of \f$h/m_n\f$ where \f$h\f$ is Planck's constant and
   * \f$m_n\f$ is the mass of the neutron. The units of this constant
   * is \f$meters \times Angstroms / microseconds\f$
   */
  static const double H_OVER_MNEUT = 0.003956034;

  /**
   * The value of \f$h^2/(2 m_n)\f$ where \f$h\f$ is Planck's constant
   * and \f$m_n\f$ is the mass of the neutron. The units of this
   * constant is \f$ Angstroms^2 \times meV\f$
   */
  static const double H2_OVER_2MNEUT = 81.8042051;
}

#endif // _CONSTANTS_HPP
