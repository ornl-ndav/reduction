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
 * \file axis_manip/src/velocity_to_energy.hpp
 */
#ifndef _VELOCITY_TO_ENERGY
#define _VELOCITY_TO_ENERGY 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the velocity_to_energy function name
  const std::string vte_func_str = "AxisManip::velocity_to_energy";

  // 3.21
  template <typename NumT>
  std::string
  velocity_to_energy(const Nessi::Vector<NumT> & velocity,
                     const Nessi::Vector<NumT> & velocity_err2,
                     Nessi::Vector<NumT> & energy,
                     Nessi::Vector<NumT> & energy_err2,
                     void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(velocity, energy);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(vte_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(velocity_err2, energy_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(vte_func_str+" (v,v): err2 "+e.what());
      }

    // check that the velocity arrays are of proper size
    try
      {
        Utils::check_sizes_square(velocity, velocity_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(vte_func_str+" (v,v): velocity "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);

    NumT a;
    NumT b2;

    retstr += __velocity_to_energy_static(a, b2);

    size_t sz = velocity.size();
    for (size_t i = 0; i < sz; ++i)
      {
        retstr += __velocity_to_energy_dynamic(velocity[i],
                                               velocity_err2[i],
                                               energy[i],
                                               energy_err2[i],
                                               a, b2);
      }

    return retstr;
  }

  // 3.21
  template <typename NumT>
  std::string
  velocity_to_energy(const NumT velocity,
                     const NumT velocity_err2,
                     NumT & energy,
                     NumT & energy_err2,
                     void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN);

    NumT a;
    NumT b2;

    retstr += __velocity_to_energy_static(a, b2);

    retstr += __velocity_to_energy_dynamic(velocity,velocity_err2,
                                           energy, energy_err2, 
                                           a, b2);

    return retstr;
  }

 /**
   * \ingroup velocity_to_energy
   *
   * This is a PRIVATE helper function for velocity_to_energy that
   * calculates the parameters invariant across the array calculation.
   *
   * \param a (OUTPUT) the value of the mass of the neutron, \f$m_n\f$,
   * in units of \f$(\mu sec^2 / meters^2) \times meV\f$, multiplied by 0.5 
   * \param b2 (OUTPUT) \f$m^2_n\f$
   */
  template <typename NumT>
  std::string
  __velocity_to_energy_static(NumT & a,
                              NumT & b2)
  {
    a = static_cast<NumT>(0.5 * PhysConst::MNEUT_VEQ);
    NumT b = static_cast<NumT>(PhysConst::MNEUT_VEQ);
    b2 = b * b;
   
    
    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup velocity_to_energy
   *
   * This is a PRIVATE helper function for velocity_to_energy that
   * calculates the energy and its uncertainty.
   *
   * \param velocity (INPUT) same as the parameter in
   * velocity_to_energy()
   * \param velocity_err2 (INPUT) same as the parameter in
   * velocity_to_energy()
   * \param energy (OUTPUT) same as the parameter in
   * velocity_to_energy()
   * \param energy_err2 (OUTPUT) same as the parameter in
   * velocity_to_energy()
   * \param a (INPUT) same as the parameter in
   * __velocity_to_energy_static()
   * \param b2 (INPUT) same as the parameter in
   * __velocity_to_energy_static()
   */
  template <typename NumT>
  std::string
  __velocity_to_energy_dynamic(const NumT velocity,
                               const NumT velocity_err2,
                               NumT & energy,
                               NumT & energy_err2,
                               const NumT a,
                               const NumT b2)
  {
    NumT velocity2 = velocity * velocity;

    energy = static_cast<NumT>(a * velocity2);
    energy_err2 = b2 * velocity2 * velocity_err2;

    return Nessi::EMPTY_WARN;
  }

} // AxisManip

#endif // _VELOCITY_TO_ENERGY
