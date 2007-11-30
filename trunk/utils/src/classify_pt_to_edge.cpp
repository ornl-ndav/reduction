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
 * \file utils/src/classify_pt_to_edge.cpp
 */

#include "classify_pt_to_edge.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the classify_pt_to_edge function
   *
   * \ingroup convex_polygon_intersect
   */
  template int
  __classify_pt_to_edge(const float pt_x, const float pt_y,
                        const float edge_orig_x, const float edge_orig_y,
                        const float edge_dest_x, const float edge_dest_y);
  
  /**
   * This is the double precision float declaration of the classify_pt_to_edge
   *
   * \ingroup convex_polygon_intersect
   */
  template int
  __classify_pt_to_edge(const double pt_x, const double pt_y,
                        const double edge_orig_x, const double edge_orig_y,
                        const double edge_dest_x, const double edge_dest_y);

} // Utils
