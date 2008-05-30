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
 * \file axis_manip/src/wavelength_to_scalar_k.cpp
 */
#include "wavelength_to_scalar_k.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.24.
   *
   * \ingroup wavelength_to_scalar_k
   */
  template std::string
  wavelength_to_scalar_k<float>(const Nessi::Vector<float> & wavelength,
                                const Nessi::Vector<float> & wavelength_err2,
                                Nessi::Vector<float> & wavevector,
                                Nessi::Vector<float> & wavevector_err2,
                                void *temp);

  /**
   * This is the float declaration of the function defined in 3.24.
   *
   * \ingroup wavelength_to_scalar_k
   */
  template std::string
  wavelength_to_scalar_k<float>(const float wavelength,
                                const float wavelength_err2,
                                float & wavevector,
                                float & wavevector_err2,
                                void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.24.
   *
   * \ingroup wavelength_to_scalar_k
   */
  template std::string
  wavelength_to_scalar_k<double>(const Nessi::Vector<double> & wavelength,
                                 const Nessi::Vector<double> & wavelength_err2,
                                 Nessi::Vector<double> & wavevector,
                                 Nessi::Vector<double> & wavevector_err2,
                                 void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.24.
   *
   * \ingroup wavelength_to_scalar_k
   */
  template std::string
  wavelength_to_scalar_k<double>(const double wavelength,
                                 const double wavelength_err2,
                                 double & wavevector,
                                 double & wavevector_err2,
                                 void *temp);
} // AxisManip
