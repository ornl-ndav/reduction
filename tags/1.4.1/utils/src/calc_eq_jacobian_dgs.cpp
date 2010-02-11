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
 * \file utils/src/calc_eq_jacobian_dgs.cpp
 */

#include "calc_eq_jacobian_dgs.hpp"

namespace Utils 
{
  // explicit instantiations

  /**
   * This is the float declaration of the calc_eq_jacobian_dgs function
   * defined in 3.68
   *
   * \ingroup calc_eq_jacobian_dgs
   */
  template std::string
  calc_eq_jacobian_dgs<float>(const Nessi::Vector<float> & e1_axis,
                              const Nessi::Vector<float> & e2_axis,
                              const Nessi::Vector<float> & e3_axis,
                              const Nessi::Vector<float> & e4_axis,
                              const Nessi::Vector<float> & q1_axis,
                              const Nessi::Vector<float> & q2_axis,
                              const Nessi::Vector<float> & q3_axis,
                              const Nessi::Vector<float> & q4_axis,
                              Nessi::Vector<float> & jacobian,
                              void *temp);

  /**
   * This is the double precisionfloat declaration of the 
   * calc_eq_jacobian_dgs function defined in 3.68
   *
   * \ingroup calc_eq_jacobian_dgs
   */
  template std::string
  calc_eq_jacobian_dgs<double>(const Nessi::Vector<double> & e1_axis,
                               const Nessi::Vector<double> & e2_axis,
                               const Nessi::Vector<double> & e3_axis,
                               const Nessi::Vector<double> & e4_axis,
                               const Nessi::Vector<double> & q1_axis,
                               const Nessi::Vector<double> & q2_axis,
                               const Nessi::Vector<double> & q3_axis,
                               const Nessi::Vector<double> & q4_axis,
                               Nessi::Vector<double> & jacobian,
                               void *temp);

} // Utils
