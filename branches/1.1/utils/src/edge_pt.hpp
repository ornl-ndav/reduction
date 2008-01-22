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
 * \file utils/src/edge_pt.hpp
 */

#ifndef _EDGE_PT_HPP
#define _EDGE_PT_HPP 1

#include "geometry.hpp"

namespace Utils
{
  template <typename NumT>
  void
  __edge_pt(const NumT orig_x, const NumT orig_y, 
            const NumT dest_x, const NumT dest_y,
            const NumT para_slope,
            NumT & pt_x, NumT & pt_y)
  {
    pt_x = orig_x + (para_slope * (dest_x - orig_x));
    pt_y = orig_y + (para_slope * (dest_y - orig_y));
  }

} // Utils

#endif // _EDGE_PT_HPP
