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
 * \file axis_manip/src/init_scatt_wavevector_to_Q.cpp
 */
#include "init_scatt_wavevector_to_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.32.
   *
   * \ingroup init_scatt_wavevector_to_Q
   */
  template std::string
  init_scatt_wavevector_to_Q<float>(
                          const Nessi::Vector<float> & initial_wavevector,
                          const Nessi::Vector<float> & initial_wavevector_err2,
                          const Nessi::Vector<float> & final_wavevector,
                          const Nessi::Vector<float> & final_wavevector_err2,
                          const float azimuthal_angle,
                          const float azimuthal_angle_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Qx,
                          Nessi::Vector<float> & Qx_err2,
                          Nessi::Vector<float> & Qy,
                          Nessi::Vector<float> & Qy_err2,
                          Nessi::Vector<float> & Qz,
                          Nessi::Vector<float> & Qz_err2,
                          void *temp=NULL);

  /**
   * This is the float declaration of the function defined in 3.32.
   *
   * \ingroup init_scatt_wavevector_to_Q
   */
  template std::string
  init_scatt_wavevector_to_Q<float>(
                          const float initial_wavevector,
                          const float initial_wavevector_err2,
                          const Nessi::Vector<float> & final_wavevector,
                          const Nessi::Vector<float> & final_wavevector_err2,
                          const float azimuthal_angle,
                          const float azimuthal_angle_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Qx,
                          Nessi::Vector<float> & Qx_err2,
                          Nessi::Vector<float> & Qy,
                          Nessi::Vector<float> & Qy_err2,
                          Nessi::Vector<float> & Qz,
                          Nessi::Vector<float> & Qz_err2,
                          void *temp=NULL);

  /**
   * This is the float declaration of the function defined in 3.32.
   *
   * \ingroup init_scatt_wavevector_to_Q
   */
  template std::string
  init_scatt_wavevector_to_Q<float>(
                          const Nessi::Vector<float> & initial_wavevector,
                          const Nessi::Vector<float> & initial_wavevector_err2,
                          const float final_wavevector,
                          const float final_wavevector_err2,
                          const float azimuthal_angle,
                          const float azimuthal_angle_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Qx,
                          Nessi::Vector<float> & Qx_err2,
                          Nessi::Vector<float> & Qy,
                          Nessi::Vector<float> & Qy_err2,
                          Nessi::Vector<float> & Qz,
                          Nessi::Vector<float> & Qz_err2,
                          void *temp=NULL);

  /**
   * This is the float declaration of the function defined in 3.32.
   *
   * \ingroup init_scatt_wavevector_to_Q
   */
  template std::string
  init_scatt_wavevector_to_Q<float>(
                          const float initial_wavevector,
                          const float initial_wavevector_err2,
                          const float final_wavevector,
                          const float final_wavevector_err2,
                          const float azimuthal_angle,
                          const float azimuthal_angle_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          float & Qx,
                          float & Qx_err2,
                          float & Qy,
                          float & Qy_err2,
                          float & Qz,
                          float & Qz_err2,
                          void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.32.
   *
   * \ingroup init_scatt_wavevector_to_Q
   */
  template std::string
  init_scatt_wavevector_to_Q<double>(
                         const Nessi::Vector<double> & initial_wavevector,
                         const Nessi::Vector<double> & initial_wavevector_err2,
                         const Nessi::Vector<double> & final_wavevector,
                         const Nessi::Vector<double> & final_wavevector_err2,
                         const double azimuthal_angle,
                         const double azimuthal_angle_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Qx,
                         Nessi::Vector<double> & Qx_err2,
                         Nessi::Vector<double> & Qy,
                         Nessi::Vector<double> & Qy_err2,
                         Nessi::Vector<double> & Qz,
                         Nessi::Vector<double> & Qz_err2,
                         void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.32.
   *
   * \ingroup init_scatt_wavevector_to_Q
   */
  template std::string
  init_scatt_wavevector_to_Q<double>(
                         const double initial_wavevector,
                         const double initial_wavevector_err2,
                         const Nessi::Vector<double> & final_wavevector,
                         const Nessi::Vector<double> & final_wavevector_err2,
                         const double azimuthal_angle,
                         const double azimuthal_angle_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Qx,
                         Nessi::Vector<double> & Qx_err2,
                         Nessi::Vector<double> & Qy,
                         Nessi::Vector<double> & Qy_err2,
                         Nessi::Vector<double> & Qz,
                         Nessi::Vector<double> & Qz_err2,
                         void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.32.
   *
   * \ingroup init_scatt_wavevector_to_Q
   */
  template std::string
  init_scatt_wavevector_to_Q<double>(
                         const Nessi::Vector<double> & initial_wavevector,
                         const Nessi::Vector<double> & initial_wavevector_err2,
                         const double final_wavevector,
                         const double final_wavevector_err2,
                         const double azimuthal_angle,
                         const double azimuthal_angle_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Qx,
                         Nessi::Vector<double> & Qx_err2,
                         Nessi::Vector<double> & Qy,
                         Nessi::Vector<double> & Qy_err2,
                         Nessi::Vector<double> & Qz,
                         Nessi::Vector<double> & Qz_err2,
                         void *temp=NULL);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.32.
   *
   * \ingroup init_scatt_wavevector_to_Q
   */
  template std::string
  init_scatt_wavevector_to_Q<double>(
                         const double initial_wavevector,
                         const double initial_wavevector_err2,
                         const double final_wavevector,
                         const double final_wavevector_err2,
                         const double azimuthal_angle,
                         const double azimuthal_angle_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         double & Qx,
                         double & Qx_err2,
                         double & Qy,
                         double & Qy_err2,
                         double & Qz,
                         double & Qz_err2,
                         void *temp=NULL);
} // AxisManip
