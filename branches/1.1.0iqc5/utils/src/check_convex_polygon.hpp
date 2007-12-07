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
    return true;
  }
} // Utils

#endif // _CHECK_CONVEX_POLYGON_HPP
