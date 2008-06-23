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
 * \file axis_manip/src/wavelength_to_energy.hpp
 */
#ifndef _WAVELENGTH_TO_ENERGY_HPP
#define _WAVELENGTH_TO_ENERGY_HPP 1

#include "constants.hpp"
#include "conversions.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the wavelength_to_energy function name
  const std::string wte_func_str = "AxisManip::wavelength_to_energy";

  // 3.22
  template <typename NumT>
  std::string
  wavelength_to_energy(const Nessi::Vector<NumT> & wavelength,
                       const Nessi::Vector<NumT> & wavelength_err2,
                       Nessi::Vector<NumT> & energy,
                       Nessi::Vector<NumT> & energy_err2,
                       void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, energy);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wte_func_str+" (v,v): data "+e.what());
      }

    // check that the uncertainties are of proper size
    try
      {
        Utils::check_sizes_square(wavelength_err2, energy_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wte_func_str+" (v,v): err2 "+e.what());
      }

    // check that the wavelength arrays are of proper size
    try
      {
        Utils::check_sizes_square(wavelength, wavelength_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(wte_func_str+" (v,v): wavelength "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);

    NumT a2;

    retstr += __wavelength_to_energy_static(a2);

    size_t sz = wavelength.size();

	#pragma omp parallel for
    for (int i = 0; i < static_cast<int>(sz); ++i)
    {
        std::string tempS = __wavelength_to_energy_dynamic(wavelength[i],
                                              wavelength_err2[i],
                                              energy[i],
                                              energy_err2[i],
                                              a2);
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

  // 3.22
  template <typename NumT>
  std::string
  wavelength_to_energy(const NumT wavelength,
                       const NumT wavelength_err2,
                       NumT & energy,
                       NumT & energy_err2,
                       void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN);

    NumT a2;

    retstr += __wavelength_to_energy_static(a2);

    retstr += __wavelength_to_energy_dynamic(wavelength,wavelength_err2,
                                             energy, energy_err2, a2);

    return retstr;
  }

  /**
   * \ingroup wavelength_to_energy
   *
   * This is a PRIVATE helper function for wavelength_to_energy that
   * calculates the parameters invariant across the array calculation.
   *
   * \param a2 (OUTPUT) \f$=\frac{h^4}{m_n^2}\f$
   */
  template <typename NumT>
  std::string
  __wavelength_to_energy_static(NumT & a2)
  {
    a2 = 4. * static_cast<NumT>(PhysConst::H2_OVER_2MNEUT) *
      static_cast<NumT>(PhysConst::H2_OVER_2MNEUT);
    return Nessi::EMPTY_WARN;
  }

  /**
   * \ingroup wavelength_to_energy
   *
   * This is a PRIVATE helper function for wavelength_to_energy that
   * calculates the energy and its uncertainty.
   *
   * \param wavelength (INPUT) same as the parameter in
   * wavelength_to_energy()
   * \param wavelength_err2 (INPUT) same as the parameter in
   * wavelength_to_energy()
   * \param energy (OUTPUT) same as the parameter in
   * wavelength_to_energy()
   * \param energy_err2 (OUTPUT) same as the parameter in
   * wavelength_to_energy()
   * \param a2 (INPUT) same as the parameter in
   * __wavelength_to_energy_static()
   */
  template <typename NumT>
  std::string
  __wavelength_to_energy_dynamic(const NumT wavelength,
                                 const NumT wavelength_err2,
                                 NumT & energy,
                                 NumT & energy_err2,
                                 const NumT a2)
  {
    NumT wavelength2 = wavelength * wavelength;

    energy = static_cast<NumT>(PhysConst::H2_OVER_2MNEUT) / wavelength2;
    energy_err2 = (a2 * wavelength_err2);
    energy_err2 /= (wavelength2 * wavelength2 * wavelength2);

    return Nessi::EMPTY_WARN;
  }

} // AxisManip

#endif // _WAVELENGTH_TO_ENERGY_HPP
