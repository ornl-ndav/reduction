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
 * \file utils/src/crossing_pt.hpp
 */

#ifndef _CROSSING_PT_HPP
#define _CROSSING_PT_HPP 1

#include "convex_polygon_intersect.hpp"
#include "num_comparison.hpp"
#include <limits>
#include <iostream>

namespace Utils
{
  template <typename NumT>
  int
  __crossing_pt(const NumT orig_x1, const NumT orig_y1, 
                const NumT dest_x1, const NumT dest_y1,
                const NumT orig_x2, const NumT orig_y2, 
                const NumT dest_x2, const NumT dest_y2,
                NumT & cross_x, NumT & cross_y)
  {
    static const NumT EPSILON = std::numeric_limits<NumT>::epsilon();

    // Parametric slope holders
    NumT s; // Edge 2 intersection with edge 1
    NumT t; // Edge 1 intersection with edge 2

    // Compute parametric slope for intersection for infinite edge 2
    int classe = __edge_intersect(orig_x1, orig_y1, dest_x1, dest_y1,
                                  orig_x2, orig_y2, dest_x2, dest_y2,
                                  s);

    // Classification does not allow edge 1 and edge 2 to cross
    if ((classe == COLLINEAR) || (classe == PARALLEL))
      {
        return classe;
      }

    NumT lene = __pt_length(dest_x1-orig_x1, dest_y1-orig_y1);

    // If the parametric slope for intersection from edge 2 is not between 
    // 0-ep and 1+ep, the edges cannot cross.
    if ((s < -EPSILON*lene) || (s > static_cast<NumT>(1.0)+EPSILON*lene))
      {
        return SKEW_NO_CROSS;
      }

    // Compute parametric slope for intersection for infinite edge 1
    __edge_intersect(orig_x2, orig_y2, dest_x2, dest_y2,
                     orig_x1, orig_y1, dest_x1, dest_y1,
                     t);    

    NumT lenf = __pt_length(orig_x2-dest_x2, orig_y2-dest_y2);

    // We now check the reverse case to the above. If the parametric slope for 
    // intersection from edge 1 is not between 0-ep and 1+ep, the edges cannot 
    // cross.
    if (compare(-EPSILON*lenf, t) <= 0 && 
        compare(t, static_cast<NumT>(1.0)+EPSILON*lenf) <= 0)
      {
        // Crossing happens at edge 2's origin point
        if (compare(t, EPSILON*lenf) <= 0)
          {
            cross_x = orig_x2;
            cross_y = orig_y2;
          }
        // Crossing happens at edge 2's destination point
        else if (compare(t, static_cast<NumT>(1.0)-EPSILON*lenf) >= 0)
          {
            cross_x = dest_x2;
            cross_y = dest_y2;
          }
        // Crossing happens at edge 1's origin point
        else if (compare(s, EPSILON*lene) <= 0)
          {
            cross_x = orig_x1;
            cross_y = orig_y1;
          }
        // Crossing happens at edge 1's destination point
        else if (compare(s, static_cast<NumT>(1.0)-EPSILON*lene) >= 0)
          {
            cross_x = dest_x1;
            cross_y = dest_y1;
          }
        // Crossing occurs somewhere along edge 2
        else
          {
            __edge_pt(orig_x2, orig_y2, dest_x2, dest_y2, t, cross_x, cross_y);
          }
        return SKEW_CROSS;
      }
    // OK, now they definitely do not cross.
    else
      {
        return SKEW_NO_CROSS;
      }
  }

} // Utils

#endif // _CROSSING_PT_HPP
