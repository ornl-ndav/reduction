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
#include "num_comparison.hpp"
#include "size_checks.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>

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

  /**
   * Enumeration for handling edge orientations
   */
  enum {
    COLLINEAR,      /**< Edges lie on the same line */
    PARALLEL,       /**< Edges point in the same direction */
    SKEW,           /**< Edges are at an angle to each other */
    SKEW_CROSS,     /**< Edges are at an angle and intersect */
    SKEW_NO_CROSS   /**< Edges are at an angle and do not intersect */
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
   
    // The current intersection point
    NumT x_i = static_cast<NumT>(0.0);
    NumT y_i = static_cast<NumT>(0.0);

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

    std::size_t max_iters = 2 * (a_size + b_size);
    std::cout << "Max Iterations: " << max_iters << std::endl;
    for (std::size_t i = 1; (i <= max_iters) || (2 == phase); ++i)
      {
        std::cout << "Iteration " << i << ", Phase " << phase << " Edge 1 (";
        std::cout << a_orig << ",";
        std::cout << a_dest << "), Edge 2 (" << b_orig << "," << b_dest;
        std::cout << ")" << std::endl;
        std::cout << "Edge 1 orig: (" << ax_coord[a_orig] << ",";
        std::cout << ay_coord[a_orig] << "), dest: (" << ax_coord[a_dest];
        std::cout << "," << ay_coord[a_dest] << "), Edge 2 orig: (";
        std::cout << bx_coord[b_orig] << ",";
        std::cout << by_coord[b_orig] << "), dest: (" << bx_coord[b_dest];
        std::cout << "," << by_coord[b_dest] << ")" << std::endl;
        std::cout << "Trap: (" << (i <= max_iters) << "," << (2 == phase) << ")";
        std::cout << std::endl;

        int aclass = __classify_pt_to_edge(ax_coord[a_dest], ay_coord[a_dest],
                                           bx_coord[b_orig], by_coord[b_orig],
                                           bx_coord[b_dest], by_coord[b_dest]);

        int bclass = __classify_pt_to_edge(bx_coord[b_dest], by_coord[b_dest],
                                           ax_coord[a_orig], ay_coord[a_orig],
                                           ax_coord[a_dest], ay_coord[a_dest]);

        int cross_type = __crossing_pt(ax_coord[a_orig], ay_coord[a_orig],
                                       ax_coord[a_dest], ay_coord[a_dest],
                                       bx_coord[b_orig], by_coord[b_orig],
                                       bx_coord[b_dest], by_coord[b_dest],
                                       x_i, y_i);

        std::cout << "Cross Type: " << cross_type << ", A Class: " << aclass;
        std::cout << ", B Class: " << bclass << std::endl;

        if (cross_type == SKEW_CROSS)
          {
            if (1 == phase) 
              {
                std::cout << "Cross-pt 1: (" << x_i << "," << y_i << ")";
                std::cout << std::endl;

                phase = 2;
                cx_coord.push_back(x_i);
                cy_coord.push_back(y_i);

                x_start = x_i;
                y_start = y_i;
              }
            else if (compare(x_i, cx_coord.back()) != 0 && 
                     compare(y_i, cy_coord.back()) != 0)
              {
                std::cout << "Cross-pt 2: (" << x_i << "," << y_i << ")";
                std::cout << std::endl;
                if (compare(x_i, x_start) != 0 && 
                    compare(y_i, y_start) != 0)
                  {
                    std::cout << "Adding intersection point" << std::endl;
                    cx_coord.push_back(x_i);
                    cy_coord.push_back(y_i);
                  }
                else
                  {
                    std::cout << "Size of intersection: " << cx_coord.size();
                    std::cout << std::endl;
                    return Nessi::EMPTY_WARN;
                  }
              }
            if (aclass == RIGHT)
              {
                std::cout << "A is inside" << std::endl;
                inflag = A_IS_INSIDE;
              }
            else if (bclass == RIGHT)
              {
                std::cout << "B is inside" << std::endl;
                inflag = B_IS_INSIDE;
              }
            else
              {
                std::cout << "Edge is unknown" << std::endl;
                inflag = UNKNOWN;
              }
          }
        else if (cross_type == COLLINEAR && 
                 ((aclass != BEHIND) && (bclass != BEHIND)))
          {
            inflag = UNKNOWN;
          }

        bool a_aims_b = __aims_at(ax_coord[a_orig], ay_coord[a_orig],
                                  ax_coord[a_dest], ay_coord[a_dest],
                                  bx_coord[b_orig], by_coord[b_orig],
                                  bx_coord[b_dest], by_coord[b_dest],
                                  aclass, cross_type);
        bool b_aims_a = __aims_at(bx_coord[b_orig], by_coord[b_orig],
                                  bx_coord[b_dest], by_coord[b_dest],
                                  ax_coord[a_orig], ay_coord[a_orig],
                                  ax_coord[a_dest], ay_coord[a_dest],
                                  bclass, cross_type);

        std::cout << "InFlag = " << inflag << std::endl;
        std::cout << "A_aims_B = " << a_aims_b << ", B_aims_A = " << b_aims_a;
        std::cout << std::endl;
        
        if (a_aims_b && b_aims_a)
          {
            if ((inflag == B_IS_INSIDE) || 
                ((inflag == UNKNOWN) && (aclass == LEFT)))
              {
                std::cout << "Advance Edge 1" << std::endl;
                __advance_edge(ax_coord, ay_coord, false, 
                               cx_coord, cy_coord, a_orig, a_dest);
              }
            else
              {
                std::cout << "Advance Edge 2" << std::endl;
                __advance_edge(bx_coord, by_coord, false, 
                               cx_coord, cy_coord, b_orig, b_dest);
              }
          }
        else if (a_aims_b)
          {
            std::cout << "Advance Edge 3" << std::endl;
            __advance_edge(ax_coord, ay_coord, inflag==A_IS_INSIDE, 
                           cx_coord, cy_coord, a_orig, a_dest);
          }
        else if (b_aims_a)
          {
            std::cout << "Advance Edge 4" << std::endl;
            __advance_edge(bx_coord, by_coord, inflag==B_IS_INSIDE, 
                           cx_coord, cy_coord, b_orig, b_dest);
          }
        else
          {
            if ((inflag == B_IS_INSIDE) || 
                ((inflag == UNKNOWN) && (aclass == LEFT)))
              {
                std::cout << "Advance Edge 5" << std::endl;
                __advance_edge(ax_coord, ay_coord, false, 
                               cx_coord, cy_coord, a_orig, a_dest);
              }
            else
              {
                std::cout << "Advance Edge 6" << std::endl;
                __advance_edge(bx_coord, by_coord, false, 
                               cx_coord, cy_coord, b_orig, b_dest);
              }
          }
      } // for

    if(__pt_in_convex_polygon(ax_coord[a_orig], ay_coord[a_orig],
                              b_orig, bx_coord, by_coord))
      {
        std::copy(ax_coord.begin(), ax_coord.end(), 
                  std::back_inserter(cx_coord));
        std::copy(ay_coord.begin(), ay_coord.end(), 
                  std::back_inserter(cy_coord));
        return Nessi::EMPTY_WARN;
      }
    else if (__pt_in_convex_polygon(bx_coord[b_orig], by_coord[b_orig],
                                    a_orig, ax_coord, ay_coord))
      {
        std::copy(bx_coord.begin(), bx_coord.end(), 
                  std::back_inserter(cx_coord));
        std::copy(by_coord.begin(), by_coord.end(), 
                  std::back_inserter(cy_coord));
        return Nessi::EMPTY_WARN;
      }

    cx_coord.push_back(static_cast<NumT>(0.0));
    cy_coord.push_back(static_cast<NumT>(0.0));
    return Nessi::EMPTY_WARN;
  }
} // Utils

#endif // _CONVEX_POLYGON_INTERSECT_HPP
