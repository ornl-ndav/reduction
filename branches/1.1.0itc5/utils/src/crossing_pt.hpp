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
    NumT s;
    NumT t;

    int classe = __edge_intersect(orig_x1, orig_y1, dest_x1, dest_y1,
                                  orig_x2, orig_y2, dest_x2, dest_y2,
                                  s);

    if ((classe == COLLINEAR) || (classe == PARALLEL))
      {
        return classe;
      }

    NumT lene = __pt_length(dest_x1-orig_x1, dest_y1-orig_y1);

    int classf = __edge_intersect(orig_x2, orig_y2, dest_x2, dest_y2,
                                  orig_x1, orig_y1, dest_x1, dest_y1,
                                  t);    

    NumT lenf = __pt_length(orig_x2-dest_x2, orig_y2-dest_y2);
  }

} // Utils

#endif // _CROSSING_PT_HPP
