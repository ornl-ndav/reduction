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
 * \file utils/src/calc_bin_widths.cpp
 */

#include "calc_bin_widths.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the calc_bin_widths() function defined 
   * in 3.54
   *
   * \ingroup calc_bin_widths
   */
  template std::string
  calc_bin_widths<float>(const Nessi::Vector<float> & axis,
                         const Nessi::Vector<float> & axis_err2,
                         Nessi::Vector<float> & bin_widths,
                         Nessi::Vector<float> & bin_widths_err2,
                         void *temp);
  
  /**
   * This is the double precision float declaration of the calc_bin_widths() 
   * function defined in 3.54
   *
   * \ingroup calc_bin_widths
   */
  template std::string
  calc_bin_widths<double>(const Nessi::Vector<double> & axis,
                          const Nessi::Vector<double> & axis_err2,
                          Nessi::Vector<double> & bin_widths,
                          Nessi::Vector<double> & bin_widths_err2,
                          void *temp);
} // Utils
