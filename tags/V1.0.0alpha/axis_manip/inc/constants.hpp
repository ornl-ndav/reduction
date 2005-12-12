/**
 * $Id$
 *
 * \file axis_manip/inc/constants.hpp
 */
#ifndef _CONSTANTS_H
#define _CONSTANTS_H 1

namespace PhysConst
{
  /**
   * The value of \f$\pi\f$ to 29 decimal digits.
   */
  static const double PI = 3.14159265358979323846264338328;

  /**
   * The value of \f$h/m_n\f$ where \f$h\f$ is Plank's constant and
   * \f$m_n\f$ is the mass of the neutron. The units of this constant
   * is \f$meters \times Angstroms / microseconds\f$
   */
  static const double H_OVER_MNEUT = 0.003961617; 

  /**
   * The value of \f$h^2/(2 m_n)\f$ where \f$h\f$ is Plank's constant
   * and \f$m_n\f$ is the mass of the neutron. The units of this
   * constant is \f$ Angstroms^2 \times meV\f$
   */
  static const double H2_OVER_2MNEUT = 81.83;

  /**
   * The value of Plank's constant, \f$h\f$, in units of \f$meV /
   * THz\f$
   */
  static const double H = 4.1357;
}

#endif // _CONSTANTS_H
