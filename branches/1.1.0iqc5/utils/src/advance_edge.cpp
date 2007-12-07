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
 * \file utils/src/advance_edge.cpp
 */

#include "advance_edge.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the advance_edge function
   *
   * \ingroup convex_polygon_intersect
   */
  template void
  __advance_edge(const Nessi::Vector<float> & x_coord, 
                 const Nessi::Vector<float> & y_coord, 
                 const bool inside,
                 Nessi::Vector<float> & ix_coord,
                 Nessi::Vector<float> & iy_coord,
                 std::size_t & orig_pos, 
                 std::size_t & dest_pos);


  /**
   * This is the double precision float declaration of the advance_edge
   *
   * \ingroup convex_polygon_intersect
   */
  template void
  __advance_edge(const Nessi::Vector<double> & x_coord, 
                 const Nessi::Vector<double> & y_coord, 
                 const bool inside,
                 Nessi::Vector<double> & ix_coord,
                 Nessi::Vector<double> & iy_coord,
                 std::size_t & orig_pos, 
                 std::size_t & dest_pos);

} // Utils
