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
 * \file axis_manip/src/init_scatt_wavevector_to_scalar_Q.cpp
 */
#include "init_scatt_wavevector_to_scalar_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaraion of the function defined in 3.33.
   *
   * \ingroup init_scatt_wavevector_to_scalar_Q
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<float>(
                          const Nessi::Vector<float> & initial_wavevector,
                          const Nessi::Vector<float> & initial_wavevector_err2,
                          const Nessi::Vector<float> & final_wavevector,
                          const Nessi::Vector<float> & final_wavevector_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Q,
                          Nessi::Vector<float> & Q_err2,
                          void *temp);

  /**
   * This is the float declaraion of the function defined in 3.33.
   *
   * \ingroup init_scatt_wavevector_to_scalar_Q
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<float>(
                          const float initial_wavevector,
                          const float initial_wavevector_err2,
                          const Nessi::Vector<float> & final_wavevector,
                          const Nessi::Vector<float> & final_wavevector_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Q,
                          Nessi::Vector<float> & Q_err2,
                          void *temp);

  /**
   * This is the float declaraion of the function defined in 3.33.
   *
   * \ingroup init_scatt_wavevector_to_scalar_Q
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<float>(
                          const Nessi::Vector<float> & initial_wavevector,
                          const Nessi::Vector<float> & initial_wavevector_err2,
                          const float final_wavevector,
                          const float final_wavevector_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Q,
                          Nessi::Vector<float> & Q_err2,
                          void *temp);

  /**
   * This is the float declaraion of the function defined in 3.33.
   *
   * \ingroup init_scatt_wavevector_to_scalar_Q
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<float>(const float initial_wavevector,
                                           const float initial_wavevector_err2,
                                           const float final_wavevector,
                                           const float final_wavevector_err2,
                                           const float polar_angle,
                                           const float polar_angle_err2,
                                           float & Q,
                                           float & Q_err2,
                                           void *temp);

  /**
   * This is the double precision float declaraion of the function
   * defined in 3.33.
   *
   * \ingroup init_scatt_wavevector_to_scalar_Q
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<double>(
                         const Nessi::Vector<double> & initial_wavevector,
                         const Nessi::Vector<double> & initial_wavevector_err2,
                         const Nessi::Vector<double> & final_wavevector,
                         const Nessi::Vector<double> & final_wavevector_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Q,
                         Nessi::Vector<double> & Q_err2,
                         void *temp);

  /**
   * This is the double precision float declaraion of the function
   * defined in 3.33.
   *
   * \ingroup init_scatt_wavevector_to_scalar_Q
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<double>(
                         const double initial_wavevector,
                         const double initial_wavevector_err2,
                         const Nessi::Vector<double> & final_wavevector,
                         const Nessi::Vector<double> & final_wavevector_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Q,
                         Nessi::Vector<double> & Q_err2,
                         void *temp);

  /**
   * This is the double precision float declaraion of the function
   * defined in 3.33.
   *
   * \ingroup init_scatt_wavevector_to_scalar_Q
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<double>(
                         const Nessi::Vector<double> & initial_wavevector,
                         const Nessi::Vector<double> & initial_wavevector_err2,
                         const double final_wavevector,
                         const double final_wavevector_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Q,
                         Nessi::Vector<double> & Q_err2,
                         void *temp);

  /**
   * This is the double precision float declaraion of the function
   * defined in 3.33.
   *
   * \ingroup init_scatt_wavevector_to_scalar_Q
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<double>(
                         const double initial_wavevector,
                         const double initial_wavevector_err2,
                         const double final_wavevector,
                         const double final_wavevector_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         double & Q,
                         double & Q_err2,
                         void *temp);
} // AxisManip
