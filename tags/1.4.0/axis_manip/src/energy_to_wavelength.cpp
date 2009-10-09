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
 * \file axis_manip/src/energy_to_wavelength.cpp
 */
#include "energy_to_wavelength.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.51.
   *
   * \ingroup energy_to_wavelength
   */
  template std::string
  energy_to_wavelength<float>(const Nessi::Vector<float> & energy,
                              const Nessi::Vector<float> & energy_err2,
                              Nessi::Vector<float> & wavelength,
                              Nessi::Vector<float> & wavelength_err2,
                              void *temp);

  /**
   * This is the float declaration of the function defined in 3.51.
   *
   * \ingroup energy_to_wavelength
   */
  template std::string
  energy_to_wavelength<float>(const float energy,
                              const float energy_err2,
                              float & wavelength,
                              float & wavelength_err2,
                              void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.51.
   *
   * \ingroup energy_to_wavelength
   */
  template std::string
  energy_to_wavelength<double>(const Nessi::Vector<double> & energy,
                               const Nessi::Vector<double> & energy_err2,
                               Nessi::Vector<double> & wavelength,
                               Nessi::Vector<double> & wavelength_err2,
                               void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.51.
   *
   * \ingroup energy_to_wavelength
   */
  template std::string
  energy_to_wavelength<double>(const double energy,
                               const double energy_err2,
                               double & wavelength,
                               double & wavelength_err2,
                               void *temp);
} // AxisManip
