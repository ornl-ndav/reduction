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
 * \file utils/src/advance_edge.hpp
 */

#ifndef _ADVANCE_EDGE_HPP
#define _ADVANCE_EDGE_HPP 1

#include "convex_polygon_intersect.hpp"
#include "num_comparison.hpp"

namespace Utils
{
  template <typename NumT>
  void
  __advance_edge(const Nessi::Vector<NumT> & x_coord, 
                 const Nessi::Vector<NumT> & y_coord, 
                 const int inside,
                 Nessi::Vector<NumT> & ix_coord,
                 Nessi::Vector<NumT> & iy_coord,
                 std::size_t & orig_pos, 
                 std::size_t & dest_pos)
  {
    // Advance to the next edge in the polygon
    orig_pos = __wrap_indicies(++orig_pos, x_coord.size());
    dest_pos = __wrap_indicies(++dest_pos, x_coord.size());

    // Get the polygon coordinates for the new edge origin
    NumT p_orig_x = x_coord[orig_pos];
    NumT p_orig_y = y_coord[orig_pos];

    // Get the last point in the intersection polygon
    NumT i_orig_x = ix_coord.back();
    NumT i_orig_y = iy_coord.back();

    int x_compare = compare(i_orig_x, p_orig_x);
    int y_compare = compare(i_orig_y, p_orig_y);

    if (inside && !(x_compare == 0 && y_compare == 0))
      {
        ix_coord.push_back(p_orig_x);
        iy_coord.push_back(p_orig_y);
      }
  }
} // Utils

#endif // _ADVANCE_EDGE_HPP
