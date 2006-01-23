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
 * \file axis_manip/src/tof_to_initial_wavelength_igs.cpp
 */
#include "tof_to_initial_wavelength_igs.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.29.
   *
   * \ingroup tof_to_initial_wavelength_igs
   */
  template std::string
  tof_to_initial_wavelength_igs<float>(
                                const Nessi::Vector<float> & tof,
                                const Nessi::Vector<float> & tof_err2,
                                const float final_wavelength,
                                const float final_wavelength_err2,
                                const float time_offset,
                                const float time_offset_err2,
                                const float dist_source_sample,
                                const float dist_source_sample_err2,
                                const float dist_sample_detector,
                                const float dist_sample_detector_err2,
                                Nessi::Vector<float> & initial_wavelength,
                                Nessi::Vector<float> & initial_wavelength_err2,
                                void *temp=NULL);

  /**
   * This is the float declaration of the function defined in 3.29.
   *
   * \ingroup tof_to_initial_wavelength_igs
   */
  template std::string
  tof_to_initial_wavelength_igs<float>(
                                const float tof,
                                const float tof_err2,
                                const float final_wavelength,
                                const float final_wavelength_err2,
                                const float time_offset,
                                const float time_offset_err2,
                                const float dist_source_sample,
                                const float dist_source_sample_err2,
                                const float dist_sample_detector,
                                const float dist_sample_detector_err2,
                                float & initial_wavelength,
                                float & initial_wavelength_err2,
                                void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.29.
   *
   * \ingroup tof_to_initial_wavelength_igs
   */
  template std::string
  tof_to_initial_wavelength_igs<double>(
                               const Nessi::Vector<double> & tof,
                               const Nessi::Vector<double> & tof_err2,
                               const double final_wavelength,
                               const double final_wavelength_err2,
                               const double time_offset,
                               const double time_offset_err2,
                               const double dist_source_sample,
                               const double dist_source_sample_err2,
                               const double dist_sample_detector,
                               const double dist_sample_detector_err2,
                               Nessi::Vector<double> & initial_wavelength,
                               Nessi::Vector<double> & initial_wavelength_err2,
                               void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.29.
   *
   * \ingroup tof_to_initial_wavelength_igs
   */
  template std::string
  tof_to_initial_wavelength_igs<double>(
                               const double tof,
                               const double tof_err2,
                               const double final_wavelength,
                               const double final_wavelength_err2,
                               const double time_offset,
                               const double time_offset_err2,
                               const double dist_source_sample,
                               const double dist_source_sample_err2,
                               const double dist_sample_detector,
                               const double dist_sample_detector_err2,
                               double & initial_wavelength,
                               double & initial_wavelength_err2,
                               void *temp=NULL);
} // AxisManip
