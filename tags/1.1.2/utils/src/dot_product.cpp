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
 * \file utils/src/dot_product.cpp
 */

#include "dot_product.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the dot_product function
   *
   * \ingroup convex_polygon_intersect
   */
  template float
  __dot_product(const float pt1_x, const float pt1_y, 
                const float pt2_x, const float pt2_y);

  /**
   * This is the double precision float declaration of the dot_product
   *
   * \ingroup convex_polygon_intersect
   */
  template double
  __dot_product(const double pt1_x, const double pt1_y, 
                const double pt2_x, const double pt2_y);

} // Utils
