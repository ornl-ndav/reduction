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
 * \file axis_manip/src/final_velocity_igs.cpp
 */
#include "final_velocity_igs.hpp"

namespace AxisManip
{
  // explicit instantiations
  /**
   * This is the float declaration of the function defined in 3.20.
   *
   * \ingroup final_velocity_igs
   */
  template std::string
  final_velocity_igs<float>(const float analyzer_wavelength,
                            const float analyzer_wavelength_err2,
                            float & final_velocity,
                            float & final_velocity_err2,
                            void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.20.
   *
   * \ingroup final_velocity_igs
   */
  template std::string
  final_velocity_igs<double>(const double analyzer_wavelength,
                             const double analyzer_wavelength_err2,
                             double & final_velocity,
                             double & final_velocity_err2,
                             void *temp);
} // AxisManip
