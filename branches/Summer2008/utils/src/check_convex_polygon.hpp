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
 * \file utils/src/check_convex_polygon.hpp
 */

#ifndef _CHECK_CONVEX_POLYGON_HPP
#define _CHECK_CONVEX_POLYGON_HPP 1

#include "convex_polygon_intersect.hpp"

namespace Utils 
{
  template <typename NumT>
  bool
  __check_convex_polygon(const Nessi::Vector<NumT> & xcoord,
                         const Nessi::Vector<NumT> & ycoord,
                         const bool isCW)
  {
    std::size_t poly_size = xcoord.size();
    // If we encounter empty, a point or a line, return false
    if (poly_size < 3)
      {
        return false;
      }

    std::size_t orig_pt = 0;
    std::size_t dest_pt = orig_pt + 1;
    std::size_t class_pt = dest_pt + 1;

    eEdgeClass pt_class;
    if (isCW)
      {
        pt_class = RIGHT;
      }
    else
      {
        pt_class = LEFT;
      }

    for (std::size_t i = 0; i < poly_size; ++i)
      {
        eEdgeClass class_check = __classify_pt_to_edge(xcoord[class_pt], 
                                                       ycoord[class_pt],
                                                       xcoord[orig_pt],
                                                       ycoord[orig_pt],
                                                       xcoord[dest_pt],
                                                       ycoord[dest_pt]);
          
        if (class_check != pt_class)
          {
            // Polygon must be concave
            return false;
          }

        orig_pt = __wrap_indicies(++orig_pt, poly_size);
        dest_pt = __wrap_indicies(++dest_pt, poly_size);
        class_pt = __wrap_indicies(++class_pt, poly_size);
      }

    // Polygon must be convex
    return true;
  }
} // Utils

#endif // _CHECK_CONVEX_POLYGON_HPP
