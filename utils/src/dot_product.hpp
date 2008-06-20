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
 * \file utils/src/dot_product.hpp
 */

#ifndef _DOT_PRODUCT_HPP
#define _DOT_PRODUCT_HPP 1

#include "geometry.hpp"

namespace Utils
{
  template <typename NumT>
  NumT
  __dot_product(const NumT pt1_x, const NumT pt1_y, 
                const NumT pt2_x, const NumT pt2_y)
  {
    return ((pt1_x * pt2_x) + (pt1_y * pt2_y));
  }

} // Utils

#endif // _DOT_PRODUCT_HPP
