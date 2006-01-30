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
 * \file axis_manip/src/rebin_axis_2D.cpp
 */
#include "rebin_axis_2D.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaraion of the function defined in 3.13.
   *
   * \ingroup rebin_axis_2D
   */
  template std::string
  rebin_axis_2D<float>(const Nessi::Vector<float> & axis_in_1,
                       const Nessi::Vector<float> & axis_in_2,
                       const Nessi::Vector<float> & input,
                       const Nessi::Vector<float> & input_err2,
                       const Nessi::Vector<float> & axis_out_1,
                       const Nessi::Vector<float> & axis_out_2,
                       Nessi::Vector<float> & output,
                       Nessi::Vector<float> & output_err2,
                       void *temp);

  /**
   * This is the double precision float declaraion of the function
   * defined in 3.13.
   *
   * \ingroup rebin_axis_2D
   */
  template std::string
  rebin_axis_2D<double>(const Nessi::Vector<double> & axis_in_1,
                        const Nessi::Vector<double> & axis_in_2,
                        const Nessi::Vector<double> & input,
                        const Nessi::Vector<double> & input_err2,
                        const Nessi::Vector<double> & axis_out_1,
                        const Nessi::Vector<double> & axis_out_2,
                        Nessi::Vector<double> & output,
                        Nessi::Vector<double> & output_err2,
                        void *temp);
} // AxisManip
