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
 * \file utils/src/fit_linear_background.cpp
 */
#include "fit_linear_background.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.43.
   *
   * \ingroup fit_linear_background
   */
  template std::string
  fit_linear_background<float>(const Nessi::Vector<float> & axis_in,
                               const Nessi::Vector<float> & input,
                               const Nessi::Vector<float> & input_err2,
                               float min_val,
                               float max_val,
                               float slope_start,
                               float intercept_start,
                               float & slope_out,
                               float & slope_out_err2,
                               float & intercept_out,
                               float & intercept_out_err2,
                               void *temp);
  /**
   * This is the double precision float declaration of the function
   * defined in 3.43.
   *
   * \ingroup fit_linear_background
   */
  template std::string
  fit_linear_background<double>(const Nessi::Vector<double> & axis_in,
                                const Nessi::Vector<double> & input,
                                const Nessi::Vector<double> & input_err2,
                                double min_val,
                                double max_val,
                                double slope_start,
                                double intercept_start,
                                double & slope_out,
                                double & slope_out_err2,
                                double & intercept_out,
                                double & intercept_out_err2,
                                void *temp);
} // Utils
