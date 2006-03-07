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
 * \file axis_manip/src/tof_to_scalar_Q.cpp
 */
#include "tof_to_scalar_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.17.
   *
   * \ingroup tof_to_scalar_Q
   */
  template std::string
  tof_to_scalar_Q<float>(const Nessi::Vector<float> & tof,
                         const Nessi::Vector<float> & tof_err2,
                         const float pathlength,
                         const float pathlength_err2,
                         const float scatt_angle,
                         const float scatt_angle_err2,
                         Nessi::Vector<float> & Q,
                         Nessi::Vector<float> & Q_err2,
                         void *temp);

  /**
   * This is the float declaration of the function defined in 3.17.
   *
   * \ingroup tof_to_scalar_Q
   */
  template std::string
  tof_to_scalar_Q<float>(const float tof,
                         const float tof_err2,
                         const float pathlength,
                         const float pathlength_err2,
                         const float scatt_angle,
                         const float scatt_angle_err2,
                         float & Q,
                         float & Q_err2,
                         void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.17.
   *
   * \ingroup tof_to_scalar_Q
   */
  template std::string
  tof_to_scalar_Q<double>(const Nessi::Vector<double> & tof,
                          const Nessi::Vector<double> & tof_err2,
                          const double pathlength,
                          const double pathlength_err2,
                          const double scatt_angle,
                          const double scatt_angle_err2,
                          Nessi::Vector<double> & Q,
                          Nessi::Vector<double> & Q_err2,
                          void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.17.
   *
   * \ingroup tof_to_scalar_Q
   */
  template std::string
  tof_to_scalar_Q<double>(const double tof,
                          const double tof_err2,
                          const double pathlength,
                          const double pathlength_err2,
                          const double scatt_angle,
                          const double scatt_angle_err2,
                          double & Q,
                          double & Q_err2,
                          void *temp);
} // AxisManip
