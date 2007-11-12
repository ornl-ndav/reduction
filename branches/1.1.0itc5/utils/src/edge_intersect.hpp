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
 * \file utils/src/edge_intersect.hpp
 */

#ifndef _EDGE_INTERSECT_HPP
#define _EDGE_INTERSECT_HPP 1

#include "convex_polygon_intersect.hpp"
#include "num_comparison.hpp"

namespace Utils
{
  template <typename NumT>
  int
  __edge_intersect(const NumT orig_x1, const NumT orig_y1, 
                   const NumT dest_x1, const NumT dest_y1,
                   const NumT orig_x2, const NumT orig_y2, 
                   const NumT dest_x2, const NumT dest_y2,
                   NumT & para_slope)
  {
    // Make perpendicular vector by rotating edge 2 by 90 degrees clockwise 
    // about center
    NumT n_x = dest_y2 - orig_y2;
    NumT n_y = orig_x2 - dest_x2;

    // Make edge 1 vector
    NumT m_x = dest_x1 - orig_x1;
    NumT m_y = dest_y1 - orig_y1;

    NumT denom = __dot_product(n_x, n_y, m_x, m_y);

    if (compare(denom, static_cast<NumT>(0.0)) == 0)
      {
        // Both edges lie in same direction and do not cross, so they are 
        // either PARALLEL or COLLINEAR
        int aclass = __classify_pt_to_edge(orig_x1, orig_y1, orig_x2, orig_y2,
                                           dest_x2, dest_y2);
        if (aclass == LEFT || aclass == RIGHT)
          {
            return PARALLEL;
          }
        else
          {
            return COLLINEAR;
          }
      }

    // Both edges are SKEW, so calculate parametric slope of perpendicular 
    // vector
    NumT l_x = orig_x1 - orig_x2;
    NumT l_y = orig_y1 - orig_y2;

    NumT numer = __dot_product(n_x, n_y, l_x, l_y);
    para_slope = -numer / denom;
    return SKEW;
  }

} // Utils

#endif // _EDGE_INTERSECT_HPP
