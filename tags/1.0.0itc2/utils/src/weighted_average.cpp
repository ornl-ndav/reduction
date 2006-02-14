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
 * \file utils/src/weighted_average.cpp
 */
#include "weighted_average.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the weighted_average function
   *
   * \ingroup weighted_average
   */
  template std::string
  weighted_average<float>(const Nessi::Vector<float> & input,
                          const Nessi::Vector<float> & input_err2,
                          const float start_bin,
                          const float end_bin,
                          float & weighted_ave,
                          float & weighted_ave_err2,
                          void *temp);
  
  /**
   * This is the double declaration of the weighted_average function
   *
   * \ingroup weighted_average
   */
  template std::string
  weighted_average<double>(const Nessi::Vector<double> & input,
                           const Nessi::Vector<double> & input_err2,
                           const double start_bin,
                           const double end_bin,
                           double & weighted_ave,
                           double & weighted_ave_err2,
                           void *temp);
  
} // Utils
