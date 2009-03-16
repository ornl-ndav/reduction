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
 * \file axis_manip/src/rebin_2D_quad_to_rectlin.cpp
 */
#include "rebin_2D_quad_to_rectlin.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.61.
   *
   * \ingroup rebin_2D_quad_to_rectlin
   */
  template std::string
  rebin_2D_quad_to_rectlin<float>(const Nessi::Vector<float> & axis_in_x1,
                                  const Nessi::Vector<float> & axis_in_y1,
                                  const Nessi::Vector<float> & axis_in_x2,
                                  const Nessi::Vector<float> & axis_in_y2,
                                  const Nessi::Vector<float> & axis_in_x3,
                                  const Nessi::Vector<float> & axis_in_y3,
                                  const Nessi::Vector<float> & axis_in_x4,
                                  const Nessi::Vector<float> & axis_in_y4,
                                  const Nessi::Vector<float> & input,
                                  const Nessi::Vector<float> & input_err2,
                                  const Nessi::Vector<float> & axis_out_1,
                                  const Nessi::Vector<float> & axis_out_2,
                                  Nessi::Vector<float> & orig_bin_x,
                                  Nessi::Vector<float> & orig_bin_y,
                                  Nessi::Vector<float> & rebin_bin_x,
                                  Nessi::Vector<float> & rebin_bin_y,
                                  Nessi::Vector<float> & frac_bin_x,
                                  Nessi::Vector<float> & frac_bin_y,
                                  Nessi::Vector<float> & output,
                                  Nessi::Vector<float> & output_err2,
                                  Nessi::Vector<float> & frac_area,
                                  Nessi::Vector<float> & bin_count,
                                  void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.61.
   *
   * \ingroup rebin_2D_quad_to_rectlin
   */
  template std::string
  rebin_2D_quad_to_rectlin<double>(const Nessi::Vector<double> & axis_in_x1,
                                   const Nessi::Vector<double> & axis_in_y1,
                                   const Nessi::Vector<double> & axis_in_x2,
                                   const Nessi::Vector<double> & axis_in_y2,
                                   const Nessi::Vector<double> & axis_in_x3,
                                   const Nessi::Vector<double> & axis_in_y3,
                                   const Nessi::Vector<double> & axis_in_x4,
                                   const Nessi::Vector<double> & axis_in_y4,
                                   const Nessi::Vector<double> & input,
                                   const Nessi::Vector<double> & input_err2,
                                   const Nessi::Vector<double> & axis_out_1,
                                   const Nessi::Vector<double> & axis_out_2,
                                   Nessi::Vector<double> & orig_bin_x,
                                   Nessi::Vector<double> & orig_bin_y,
                                   Nessi::Vector<double> & rebin_bin_x,
                                   Nessi::Vector<double> & rebin_bin_y,
                                   Nessi::Vector<double> & frac_bin_x,
                                   Nessi::Vector<double> & frac_bin_y,
                                   Nessi::Vector<double> & output,
                                   Nessi::Vector<double> & output_err2,
                                   Nessi::Vector<double> & frac_area,
                                   Nessi::Vector<double> & bin_count,
                                   void *temp);
} // AxisManip
