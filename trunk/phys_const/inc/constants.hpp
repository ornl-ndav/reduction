/**
 * $Id$
 *
 * \file phys_const/inc/constants.hpp
 */
#ifndef _CONSTANTS_HPP
#define _CONSTANTS_HPP 1

#include <string>

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
 * physics.nist.gov/constants. This database was developed by J. Baker, M. 
 * Douma, and S. Kotochigova. (National Institute of Standards and Technology, 
 * Gaithersburg, MD 20899, 9 December 2003).
 */
namespace PhysConst
{
  /// Empty string for no warning to return
  static const std::string EMPTY_WARN("");

  /**
   * Fundamental constants
   */

  /**
   * The value of Plank's constant, \f$h\f$, in units of \f$meV /
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
   * The value of \f$h/m_n\f$ where \f$h\f$ is Plank's constant and
   * \f$m_n\f$ is the mass of the neutron. The units of this constant
   * is \f$meters \times Angstroms / microseconds\f$
   */
  static const double H_OVER_MNEUT = 0.003956034;

  /**
   * The value of \f$h^2/(2 m_n)\f$ where \f$h\f$ is Plank's constant
   * and \f$m_n\f$ is the mass of the neutron. The units of this
   * constant is \f$ Angstroms^2 \times meV\f$
   */
  static const double H2_OVER_2MNEUT = 81.8042051;
}

#endif // _CONSTANTS_HPP
