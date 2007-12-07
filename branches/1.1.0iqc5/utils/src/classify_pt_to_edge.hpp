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
 * \file utils/src/classify_pt_to_edge.hpp
 */

#ifndef _CLASSIFY_PT_TO_EDGE_HPP
#define _CLASSIFY_PT_TO_EDGE_HPP 1

#include "convex_polygon_intersect.hpp"
#include "num_comparison.hpp"

namespace Utils
{
  template <typename NumT>
  eEdgeClass
  __classify_pt_to_edge(const NumT pt_x, const NumT pt_y,
                        const NumT edge_orig_x, const NumT edge_orig_y,
                        const NumT edge_dest_x, const NumT edge_dest_y)
  {
    // Vector for edge
    NumT edge_diff_x = edge_dest_x - edge_orig_x;
    NumT edge_diff_y = edge_dest_y - edge_orig_y;
    
    // Vector for pt to edge origin
    NumT pt_edge_orig_diff_x = pt_x - edge_orig_x;
    NumT pt_edge_orig_diff_y = pt_y - edge_orig_y;

    // Get vecto lengths
    NumT length_edge_diff = __pt_length(edge_diff_x, edge_diff_y);
    NumT length_pt_edge_orig_diff = __pt_length(pt_edge_orig_diff_x, 
                                                pt_edge_orig_diff_y);

    // Create cross-product
    NumT sa = (edge_diff_x * pt_edge_orig_diff_y) - 
      (pt_edge_orig_diff_x * edge_diff_y);

    // The pt is at an angle less than 180 degrees to the edge, so it lies to 
    // the left of the edge
    if (sa > static_cast<NumT>(0.0)) 
      {
        return LEFT;
      }
    // The pt is at an angle greater than 180 degrees to the edge, so it lies 
    // to the right of the edge
    if (sa < static_cast<NumT>(0.0)) 
      {
        return RIGHT;
      }
    // The pt and edge lie on the same line. The lengths now become parametric
    // slopes

    // The parametric slope for pt is less, so it lies behind the edge's origin
    // point
    if ((edge_diff_x * pt_edge_orig_diff_x < static_cast<NumT>(0.0)) || 
        (edge_diff_y * pt_edge_orig_diff_y < static_cast<NumT>(0.0)))
      {
        return BEHIND;
      }
    // The parametric slope for pt is greater, so it lies beyond the edge's 
    // destination point
    if (length_edge_diff < length_pt_edge_orig_diff)
      {
        return BEYOND;
      }
    if ((compare(pt_x, edge_orig_x) == 0) && (compare(pt_y, edge_orig_y) == 0))
      {
        return ORIGIN;
      }
    if ((compare(pt_x, edge_dest_x) == 0) && (compare(pt_y, edge_dest_y) == 0))
      {
        return DESTINATION;
      }

    return BETWEEN;
  }

} // Utils

#endif // _CLASSIFY_PT_TO_EDGE_HPP
