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
 * \file utils/src/integrate_1D_hist.cpp
 */

#include "integrate_1D_hist.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the integrate_1D_hist function defined 
   * in 3.65.
   *
   * \ingroup integrate_1D_hist
   */
  template std::string
  integrate_1D_hist<float>(const Nessi::Vector<float> & input,
                           const Nessi::Vector<float> & input_err2,
                           const bool width,
                           const Nessi::Vector<float> & axis_bw_in,
                           float & output,
                           float & output_err2,
                           void *temp);
  /**
   * This is the double declaration of the integrate_1D_hist function defined 
   * in 3.65.
   *
   * \ingroup integrate_1D_hist
   */
  template std::string
  integrate_1D_hist<double>(const Nessi::Vector<double> & input,
                            const Nessi::Vector<double> & input_err2,
                            const bool width,
                            const Nessi::Vector<double> & axis_bw_in,
                            double & output,
                            double & output_err2,
                            void *temp);

  
  /**
   * This is the float declaration of the integrate_1D_hist function defined 
   * in 3.65.
   *
   * \ingroup integrate_1D_hist
   */
  template std::string
  integrate_1D_hist<float>(const Nessi::Vector<float> & input,
                           const Nessi::Vector<float> & input_err2,
                           const Nessi::Vector<float> & axis_in,
                           const float min_int,
                           const float max_int, 
                           const bool width,
                           const Nessi::Vector<float> & axis_bw_in,
                           float & output,
                           float & output_err2,
                           void *temp);
  /**
   * This is the double declaration of the integrate_1D_hist function defined 
   * in 3.65.
   *
   * \ingroup integrate_1D_hist
   */
  template std::string
  integrate_1D_hist<double>(const Nessi::Vector<double> & input,
                            const Nessi::Vector<double> & input_err2,
                            const Nessi::Vector<double> & axis_in,
                            const double min_int,
                            const double max_int, 
                            const bool width,
                            const Nessi::Vector<double> & axis_bw_in,
                            double & output,
                            double & output_err2,
                            void *temp);

} // Utils
