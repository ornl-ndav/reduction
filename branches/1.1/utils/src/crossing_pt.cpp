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
 * \file utils/src/crossing_pt.cpp
 */

#include "crossing_pt.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the crossing_pt function
   *
   * \ingroup convex_polygon_intersect
   */
  template eEdgeOrient
  __crossing_pt(const float orig_x1, const float orig_y1, 
                const float dest_x1, const float dest_y1,
                const float orig_x2, const float orig_y2, 
                const float dest_x2, const float dest_y2,
                float & cross_x, float & cross_y);

  /**
   * This is the double precision float declaration of the crossing_pt
   *
   * \ingroup convex_polygon_intersect
   */
  template eEdgeOrient
  __crossing_pt(const double orig_x1, const double orig_y1, 
                const double dest_x1, const double dest_y1,
                const double orig_x2, const double orig_y2, 
                const double dest_x2, const double dest_y2,
                double & cross_x, double & cross_y);

} // Utils
