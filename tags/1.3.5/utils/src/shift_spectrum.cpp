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
 * \file utils/src/shift_spectrum.cpp
 */
#include "shift_spectrum.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the shift_spectrum function defined in 
   * 3.64.
   *
   * \ingroup shift_spectrum
   */
  template std::string
  shift_spectrum<float>(const Nessi::Vector<float> & input,
                        const Nessi::Vector<float> & input_err2,
                        const Nessi::Vector<float> & axis_in,
                        const Nessi::Vector<float> & axis_bc_in,
                        const float xshift,
                        const float xmin,
                        const float xmax,
                        Nessi::Vector<float> & output,
                        Nessi::Vector<float> & output_err2,
                        void *temp);

  /**
   * This is the double declaration of the shift_spectrum function defined in 
   * 3.64.
   *
   * \ingroup shift_spectrum
   */
  template std::string
  shift_spectrum<double>(const Nessi::Vector<double> & input,
                         const Nessi::Vector<double> & input_err2,
                         const Nessi::Vector<double> & axis_in,
                         const Nessi::Vector<double> & axis_bc_in,
                         const double xshift,
                         const double xmin,
                         const double xmax,
                         Nessi::Vector<double> & output,
                         Nessi::Vector<double> & output_err2,
                         void *temp);

} // Utils
