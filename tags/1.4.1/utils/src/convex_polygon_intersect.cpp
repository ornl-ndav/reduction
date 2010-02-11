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
 * \file utils/src/convex_polygon_intersect.cpp
 */

#include "convex_polygon_intersect.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the convex_polygon_intersect function 
   * defined in 3.60
   *
   * \ingroup convex_polygon_intersect
   */
  template std::string
  convex_polygon_intersect(Nessi::Vector<float> & ax_coord,
                           Nessi::Vector<float> & ay_coord,
                           Nessi::Vector<float> & bx_coord,
                           Nessi::Vector<float> & by_coord,
                           Nessi::Vector<float> & cx_coord,
                           Nessi::Vector<float> & cy_coord,
                           void *temp);

  /**
   * This is the double precision float declaration of the 
   * convex_polygon_intersect function defined in 3.60
   *
   * \ingroup convex_polygon_intersect
   */
  template std::string
  convex_polygon_intersect(Nessi::Vector<double> & ax_coord,
                           Nessi::Vector<double> & ay_coord,
                           Nessi::Vector<double> & bx_coord,
                           Nessi::Vector<double> & by_coord,
                           Nessi::Vector<double> & cx_coord,
                           Nessi::Vector<double> & cy_coord,
                           void *temp);

} // Utils
