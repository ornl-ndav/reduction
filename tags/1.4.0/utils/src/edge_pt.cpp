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
 * \file utils/src/edge_pt.cpp
 */

#include "edge_pt.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the edge_pt function
   *
   * \ingroup convex_polygon_intersect
   */
  template void
  __edge_pt(const float orig_x, const float orig_y, 
            const float dest_x, const float dest_y,
            const float para_slope,
            float & pt_x, float & pt_y);

  /**
   * This is the double precision float declaration of the edge_pt
   *
   * \ingroup convex_polygon_intersect
   */
  template void
  __edge_pt(const double orig_x, const double orig_y, 
            const double dest_x, const double dest_y,
            const double para_slope,
            double & pt_x, double & pt_y);

} // Utils
