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
 * \file utils/src/linear_order_jacobian.cpp
 */
#include "linear_order_jacobian.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the linear_order_jacobian function
   * 
   * \ingroup linear_order_jacobian
   */
  template std::string
  linear_order_jacobian<float>(const Nessi::Vector<float> & orig_axis,
                               const Nessi::Vector<float> & transform_axis,
                               const Nessi::Vector<float> & input,
                               const Nessi::Vector<float> & input_err2,
                               Nessi::Vector<float> & output,
                               Nessi::Vector<float> & output_err2,
                               void *temp);

  /**
   * This is the double precision float declaration of the 
   * linear_order_jacobian function
   * 
   * \ingroup linear_order_jacobian
   */
  template std::string
  linear_order_jacobian<double>(const Nessi::Vector<double> & orig_axis,
                                const Nessi::Vector<double> & transform_axis,
                                const Nessi::Vector<double> & input,
                                const Nessi::Vector<double> & input_err2,
                                Nessi::Vector<double> & output,
                                Nessi::Vector<double> & output_err2,
                                void *temp);
  
  /**
   * This is the float declaration of the linear_order_jacobian function 
   * defined in 3.49.
   * 
   * \ingroup linear_order_jacobian
   */
  template std::string
  linear_order_jacobian<float>(const float orig_axis_lo,
                               const float orig_axis_hi,
                               const float transform_axis_lo,
                               const float transform_axis_hi,
                               const float input,
                               const float input_err2,
                               float & output,
                               float & output_err2,
                               void *temp);

  /**
   * This is the double precision float declaration of the 
   * linear_order_jacobian function defined in 3.49.
   * 
   * \ingroup linear_order_jacobian
   */
  template std::string
  linear_order_jacobian<double>(const double orig_axis_lo,
                                const double orig_axis_hi,
                                const double transform_axis_lo,
                                const double transform_axis_hi,
                                const double input,
                                const double input_err2,
                                double & output,
                                double & output_err2,
                                void *temp);

} // Utils
