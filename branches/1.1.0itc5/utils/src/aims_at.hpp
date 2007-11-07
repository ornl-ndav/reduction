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
 * \file utils/src/aims_at.hpp
 */

#ifndef _AIMS_AT_HPP
#define _AIMS_AT_HPP 1

#include "convex_polygon_intersect.hpp"
#include "geometry.hpp"

namespace Utils
{
  template <typename NumT>
  bool
  __aims_at(const NumT orig_x1, const NumT orig_y1, 
            const NumT dest_x1, const NumT dest_y1,
            const NumT orig_x2, const NumT orig_y2, 
            const NumT dest_x2, const NumT dest_y2,
            const int point_class, const int cross_type)
  {
    NumT v1_x = dest_x1 - orig_x1;
    NumT v1_y = dest_y1 - orig_y1;

    NumT v2_x = dest_x2 - orig_x2;
    NumT v2_y = dest_y2 - orig_y2;

    if (cross_type != COLLINEAR)
      {
        NumT cp1 = v1_x * v2_y;
        NumT cp2 = v2_x * v1_y;

        if (cp1 > cp2 || compare(cp1, cp2) == 0)
          {
            return (point_class != RIGHT);
          }
        else
          {
            return (point_class != LEFT);
          }
      }
    else
      {
        return (point_class != BEYOND);
      }
  }

} // Utils

#endif // _AIMS_AT_HPP
