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
 * \file utils/src/calc_area_2D_polygon.hpp
 */
#ifndef _CALC_AREA_2D_POLYGON_HPP
#define _CALC_AREA_2D_POLYGON_HPP 1

#include "geometry.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <cmath>
#include <stdexcept>

namespace Utils
{
  /// String for holding the calc_area_2D_polygon function name
  const std::string ca2p_func_str = "Utils::calc_area_2D_polygon";

  // 3.59
  template <typename NumT>
  std::string
  calc_area_2D_polygon(const Nessi::Vector<NumT> & x_coord,
                       const Nessi::Vector<NumT> & y_coord,
                       const std::size_t size_poly,
                       const bool signed_area,
                       NumT & area,
                       void *temp=NULL)
  {
    // check to see that the polygon is area-calculable
    if (size_poly <= 2) 
      {
        throw std::invalid_argument(ca2p_func_str + " incoming polygon " +
                                    "cannot be empty, a point or a line.");
      }
    // check that the x_coord and y_coord arrays are of proper size
    try
      {
        Utils::check_sizes_square(x_coord, y_coord);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(ca2p_func_str + " x_coord & y_coord "
                                    + e.what());
      }
    // check that x_coord size is size_poly+2
    if (x_coord.size() != (size_poly + 2))
      {
        throw std::invalid_argument(ca2p_func_str + " x_coord and y_coord " +
                                    "must have the first and second " + 
                                    "elements repeated at end of arrays.");
      }

    area = static_cast<NumT>(0.0);
    
    for (std::size_t i = 1; i <= size_poly; ++i)
      {
        area += (x_coord[i] * (y_coord[i+1] - y_coord[i-1]));
      }

    area /= static_cast<NumT>(2.0);

    if (!signed_area) 
      {
        area = static_cast<NumT>(std::abs(static_cast<double>(area)));
      }

    return Nessi::EMPTY_WARN;
  }

} // Utils

#endif // _CALC_AREA_2D_POLYGON_HPP
