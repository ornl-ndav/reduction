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
 * \file axis_manip/src/energy_transfer.cpp
 */
#include "energy_transfer.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<float>(const Nessi::Vector<float> & initial_energy,
                         const Nessi::Vector<float> & initial_energy_err2,
                         const Nessi::Vector<float> & final_energy,
                         const Nessi::Vector<float> & final_energy_err2,
                         Nessi::Vector<float> & energy_transfer,
                         Nessi::Vector<float> & energy_transfer_err2,
                         void *temp);

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<float>(const Nessi::Vector<float> & initial_energy,
                         const Nessi::Vector<float> & initial_energy_err2,
                         const float final_energy,
                         const float final_energy_err2,
                         Nessi::Vector<float> & energy_transfer,
                         Nessi::Vector<float> & energy_transfer_err2,
                         void *temp);

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<float>(const float initial_energy,
                         const float initial_energy_err2,
                         const Nessi::Vector<float> & final_energy,
                         const Nessi::Vector<float> & final_energy_err2,
                         Nessi::Vector<float> & energy_transfer,
                         Nessi::Vector<float> & energy_transfer_err2,
                         void *temp);

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<float>(const float initial_energy,
                         const float initial_energy_err2,
                         const float final_energy,
                         float final_energy_err2,
                         float & energy_transfer,
                         float & energy_transfer_err2,
                         void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<double>(const Nessi::Vector<double> & initial_energy,
                          const Nessi::Vector<double> & initial_energy_err2,
                          const Nessi::Vector<double> & final_energy,
                          const Nessi::Vector<double> & final_energy_err2,
                          Nessi::Vector<double> & energy_transfer,
                          Nessi::Vector<double> & energy_transfer_err2,
                          void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<double>(const Nessi::Vector<double> & initial_energy,
                          const Nessi::Vector<double> & initial_energy_err2,
                          const double final_energy,
                          const double final_energy_err2,
                          Nessi::Vector<double> & energy_transfer,
                          Nessi::Vector<double> & energy_transfer_err2,
                          void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<double>(const double initial_energy,
                          const double initial_energy_err2,
                          const Nessi::Vector<double> & final_energy,
                          const Nessi::Vector<double> & final_energy_err2,
                          Nessi::Vector<double> & energy_transfer,
                          Nessi::Vector<double> & energy_transfer_err2,
                          void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<double>(const double initial_energy,
                          const double initial_energy_err2,
                          const double final_energy,
                          const double final_energy_err2,
                          double & energy_transfer,
                          double & energy_transfer_err2,
                          void *temp);
} // AxisManip
