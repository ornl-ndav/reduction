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
 * \file utils/src/bisect_helper.cpp
 */
#include "bisect_helper.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the bisect_helper() function
   *
   * \ingroup bisect_helper
   */
  template std::string
  bisect_helper<float>(const Nessi::Vector<float> & axis,
                       float value,
                       std::size_t & index,
                       void *temp);

  /**
   * This is the double precision float declaration of the bisect_helper()
   * function 
   *
   * \ingroup bisect_helper
   */
  template std::string
  bisect_helper<double>(const Nessi::Vector<double> & axis,
                       double value,
                       std::size_t & index,
                       void *temp);

} // Utils
