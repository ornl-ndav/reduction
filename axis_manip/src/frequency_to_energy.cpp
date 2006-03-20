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
 * \file axis_manip/src/frequency_energy.cpp
 */
#include "frequency_to_energy.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.47.
   *
   * \ingroup frequency_to_energy
   */
  template std::string
  frequency_to_energy<float>(
			     const Nessi::Vector<float> & frequency,
			     const Nessi::Vector<float> & frequency_err2,
			     Nessi::Vector<float> & energy,
			     Nessi::Vector<float> & energy_err2,
			     void *temp);

  /**
   * This is the float declaration of the function defined in 3.47.
   *
   * \ingroup frequency_to_energy
   */
  template std::string
  frequency_to_energy<float>(const float frequency,
			     const float frequency_err2,
			     float & energy,
			     float & energy_err2,
			     void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.47.
   *
   * \ingroup frequency_to_energy
   */
  template std::string
  frequency_to_energy<double>(
			      const Nessi::Vector<double> & frequency,
			      const Nessi::Vector<double> & frequency_err2,
			      Nessi::Vector<double> & energy,
			      Nessi::Vector<double> & energy_err2,
			      void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.47.
   *
   * \ingroup frequency_to_energy
   */
  template std::string
  frequency_to_energy<double>(const double frequency,
			      const double frequency_err2,
			      double & energy,
			      double & energy_err2,
			      void *temp);
} // AxisManip
