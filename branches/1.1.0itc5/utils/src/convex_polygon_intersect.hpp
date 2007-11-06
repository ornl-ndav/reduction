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
 * \file utils/src/convex_polygon_intersect.hpp
 */

#ifndef _CONVEX_POLYGON_INTERSECT_HPP
#define _CONVEX_POLYGON_INTERSECT_HPP 1

#include "geometry.hpp"
#include "nessi_warn.hpp"
#include "size_checks.hpp"
#include <algorithm>
#include <stdexcept>

namespace Utils
{
  /// String for holding the convex_polygon_intersect function name
  const std::string cpi_func_str = "Utils::convex_polygon_intersect";

  /**
   * Enumeration for handling edge positions
   */
  enum { 
    UNKNOWN,        /**< Which edge is inside the other is not known */
    A_IS_INSIDE,    /**< Edge A is inside of edge B */
    B_IS_INSIDE     /**< Edge B is inside of edge A */
  };

  /** 
   * Enumeration for handling point to edge classifications
   */
  enum {
    LEFT,         /**< Point is to left of edge */
    RIGHT,        /**< Point is to right of edge */
    BEYOND,       /**< Point is right of edge destination */
    BEHIND,       /**< Point is left of edge origin */
    BETWEEN,      /**< Point is between edge origin and destination */
    ORIGIN,       /**< Point equals edge origin */
    DESTINATION   /**< Point equals edge destination */
  };

  // 3.60
  template <typename NumT>
  std::string
  convex_polygon_intersect(const Nessi::Vector<NumT> & ax_coord,
                           const Nessi::Vector<NumT> & ay_coord,
                           const Nessi::Vector<NumT> & bx_coord,
                           const Nessi::Vector<NumT> & by_coord,
                           Nessi::Vector<NumT> & cx_coord,
                           Nessi::Vector<NumT> & cy_coord,
                           void *temp=NULL)
  {
    // check that the ax_coord and ay_coord arrays are of proper size
    try
      {
        Utils::check_sizes_square(ax_coord, ay_coord);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(cpi_func_str + " ax_coord & ay_coord "
                                    + e.what());
      }
    // check that the bx_coord and by_coord arrays are of proper size
    try
      {
        Utils::check_sizes_square(bx_coord, by_coord);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(cpi_func_str + " bx_coord & by_coord "
                                    + e.what());
      }
    // check that the cx_coord and cy_coord arrays are of proper size
    try
      {
        Utils::check_sizes_square(cx_coord, cy_coord);
      }
    catch (std::invalid_argument &e)
      {
        throw std::invalid_argument(cpi_func_str + " cx_coord & cy_coord "
                                    + e.what());
      }

    // Since the memory (size of cx_coord and cy_coord) provided is greater 
    // than the size of the overlap polygon, we clear the contents so that 
    // when the overlap finding is complete, the correct size is reported.
    cx_coord.clear();
    cy_coord.clear();

    // Starting coordinate pair for intersection
    NumT x_start;
    NumT y_start;
   
    // Variables to hold the current origin position of an edge within the 
    // coordinate arrays
    std::size_t a_orig = 0;
    std::size_t b_orig = 0;

    // Variable to hold the current index positions of the destination edge 
    // points 
    std::size_t a_dest = a_orig + 1;
    std::size_t b_dest = b_orig + 1;

    // Variables to hold the sizes of the incoming polygons
    std::size_t a_size = ax_coord.size();
    std::size_t b_size = bx_coord.size();

    int phase = 1;

    int inflag = UNKNOWN;

    std::size_t max_iters = static_cast<std::size_t>(2) * (a_size + b_size);

    for (std::size_t i = 1; (i <= max_iters) || (2 == phase); ++i)
      {
        if (a_dest >= a_size)
          {
            a_dest = a_dest - a_size;
          }
        if (b_dest >= b_size)
          {
            b_dest = b_dest - b_size;
          }

        int pclass = __classify_pt_to_edge(ax_coord[a_dest], ay_coord[a_dest],
                                           bx_coord[b_orig], by_coord[b_orig],
                                           bx_coord[b_dest], by_coord[b_dest]);

        int qclass = __classify_pt_to_edge(bx_coord[b_dest], by_coord[b_dest],
                                           ax_coord[a_orig], ay_coord[a_orig],
                                           ax_coord[a_dest], ay_coord[a_dest]);
      }

    return Nessi::EMPTY_WARN;
  }

  

} // Utils

#endif // _CONVEX_POLYGON_INTERSECT_HPP
