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

namespace Utils
{
  template <typename NumT>
  int
  __classify_pt_to_edge(const NumT pt_x, const NumT pt_y,
                        const NumT edge_orig_x, const NumT edge_orig_y,
                        const NumT edge_dest_x, const NumT edge_dest_y)
  {

    return BETWEEN;
  }
} // Utils

#endif // _CLASSIFY_PT_TO_EDGE_HPP
