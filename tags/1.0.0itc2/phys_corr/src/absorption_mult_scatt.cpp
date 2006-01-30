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
 * \file phys_corr/src/absorption_mult_scatt.cpp
 */
#include "absorption_mult_scatt.hpp"

namespace PhysCorr
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.36.
   *
   * \ingroup absorption_mult_scatt
   */
  template std::string
  absorption_mult_scatt<float>(const Nessi::Vector<float> & axis_in,
                               const Nessi::Vector<float> & input,
                               const Nessi::Vector<float> & input_err2,
                               float pathlength,
                               float polar_angle,
                               Nessi::Vector<float> & output,
                               Nessi::Vector<float> & output_err2,
                               void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.36.
   *
   * \ingroup absorption_mult_scatt
   */
  template std::string
  absorption_mult_scatt<double>(const Nessi::Vector<double> & axis_in,
                                const Nessi::Vector<double> & input,
                                const Nessi::Vector<double> & input_err2,
                                double pathlength,
                                double polar_angle,
                                Nessi::Vector<double> & output,
                                Nessi::Vector<double> & output_err2,
                                void *temp);

} // PhysCorr
