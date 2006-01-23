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
 * \file utils/src/peak_integration.cpp
 */
#include "peak_integration.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.35.
   *
   * \ingroup peak_integration
   */
  template std::string
  peak_integration<float>(const Nessi::Vector<float> & input,
                          const Nessi::Vector<float> & input_err2,
                          const Nessi::Vector<float> & start_bin,
                          float & output,
                          float & output_err2,
                          unsigned int & tag,
                          float & num_bins,
                          void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.35.
   *
   * \ingroup peak_integration
   */
  template std::string
  peak_integration<double>(const Nessi::Vector<double> & input,
                           const Nessi::Vector<double> & input_err2,
                           const Nessi::Vector<double> & start_bin,
                           double & output,
                           double & output_err2,
                           unsigned int & tag,
                           double & num_bins,
                           void *temp);

} // Utils
