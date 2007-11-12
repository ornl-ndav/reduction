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
 * \file utils/inc/geometry.hpp
 */
#ifndef _GEOMETRY_HPP
#define _GEOMETRY_HPP 1

#include "nessi.hpp"
#include <string>

namespace Utils
{
  /**
   * \defgroup calc_area_2D_polygon Utils::calc_area_2D_polygon
   * \{
   */
  
  /**
   * \brief This function is described in section 3.59
   *
   * This function takes two arrays of coordinates of a 2D polygon and 
   * calculates the area for that polygon. The coordinates of the polygon can 
   * be in any two-dimensional space. The area is calculated according to 
   * the function
   *
   * \f[
   * A = \frac{1}{2}\sum^{n}_{i=1} \left(x_i \left(y_{i-1} - 
   * y_{i+1}\right)\right)
   * \f]
   *
   * where \f$n\f$ is the size of the polygon, \f$x_i\f$ is the \f$i^{th}\f$ 
   * element in the x coordinate array, \f$y_{i-1}\f$ is the \f$i^{th}-1\f$ 
   * element in the y coordinate array and \f$y_{i+1}\f$ is the \f$i^{th}+1\f$ 
   * element in the y coordinate array. The value of \f$A\f$ is a signed area. 
   * In order to get \f$|A|\f$, the signed_area boolean flag should be set to 
   * false.
   * 
   * <b>The implementation of this formula requires that the coordinate arrays 
   * must have the first ([0]) and second ([1]) elements repeated making the 
   * array sizes size_poly + 2.</b> 
   *
   * \param x_coord (INPUT) the array of x coordinates for the polygon
   * \param y_coord (INPUT) the array of y coordinates for the polygon
   * \param size_poly (INPUT) the size of the polygon (i.e. square: 
   * size_poly=4)
   * \param signed_area (INPUT) flag to pass back the resulting area as a 
   * signed or unsigned quantity
   * \param area (OUTPUT) the area of the polygon
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   *
   * \exception std::invalid_argument is thrown if the size of x_coord is
   * not identical to the size of y_coord
   * \exception std::invalid_argument is thrown if the size of x_coord is
   * not identical to size_poly+2.
   */
  template <typename NumT>
  std::string
  calc_area_2D_polygon(const Nessi::Vector<NumT> & x_coord,
                       const Nessi::Vector<NumT> & y_coord,
                       const std::size_t size_poly,
                       const bool signed_area,
                       NumT & area,
                       void *temp=NULL);

  /**
   * \} // end of calc_area_2D_polygon
   */ 

  /**
   * \defgroup convex_polygon_intersect Utils::convex_polygon_intersect
   * \{
   */
  
  /**
   * \brief This function is described in section 3.60
   *
   * This function calculates the intersection of two convex polygons (labeled 
   * A and B for identification purposes) and returns the overlap polygon 
   * (labeled C). The prescription for this function is taken from section 6.5 
   * of <em>Computational Geometry and Computer Graphics in C++</em> by 
   * Michael Laszlo. It has been modified to fit to the data model 
   * (Nessi::Vectors) of the SNS Common Libraries. The porting of method names 
   * to library functions is not one-to-one and have been modified to fit the
   * library naming conventions. The methodology presented in the book is used
   * as is. 
   *
   * \param ax_coord (INPUT) the x coordinates for polygon A
   * \param ay_coord (INPUT) the y coordinates for polygon A
   * \param bx_coord (INPUT) the x coordinates for polygon B
   * \param by_coord (INPUT) the y coordinates for polygon B
   * \param cx_coord (OUTPUT) the x coordinates for polygon C
   * \param cy_coord (OUTPUT) the y coordinates for polygon C
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   * 
   * \exception std::invalid_argument is thrown if the size of ax_coord is
   * not identical to the size of ay_coord
   * \exception std::invalid_argument is thrown if the size of bx_coord is
   * not identical to the size of by_coord
   * \exception std::invalid_argument is thrown if the size of cx_coord is
   * not identical to the size of cy_coord
   */
  template <typename NumT>
  std::string
  convex_polygon_intersect(const Nessi::Vector<NumT> & ax_coord,
                           const Nessi::Vector<NumT> & ay_coord,
                           const Nessi::Vector<NumT> & bx_coord,
                           const Nessi::Vector<NumT> & by_coord,
                           Nessi::Vector<NumT> & cx_coord,
                           Nessi::Vector<NumT> & cy_coord,
                           void *temp=NULL);

  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   *
   * This function takes a point, which is given by an (x,y) pair and 
   * classifies its location in space relative to a given directed edge. The 
   * edge is represented by a pair of (x,y) pairs.
   *
   * The possible classifications are shown by the following figure.
   *
   * <IMG SRC="../images/Point_Edge_Classification.png">
   *
   * \param pt_x (INPUT) the x-coordinate of the point to classify
   * \param pt_y (INPUT) the y-coordinate of the point to classify
   * \param edge_orig_x (INPUT) the x-coordinate of the edge origin
   * \param edge_orig_y (INPUT) the y-coordinate of the edge origin
   * \param edge_dest_x (INPUT) the x-coordinate of the edge destination (end)
   * \param edge_dest_y (INPUT) the y-coordinate of the edge destination (end)
   *
   * \return The classification of the point with respect to the edge
   */
  template <typename NumT>
  int
  __classify_pt_to_edge(const NumT pt_x, const NumT pt_y,
                        const NumT edge_orig_x, const NumT edge_orig_y,
                        const NumT edge_dest_x, const NumT edge_dest_y);

  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   *
   * This function returns the length of a (x,y) coordinate pair with respect 
   * to the origin by the following formula
   *
   * \f[
   * length = \sqrt{x^2 + y^2}
   * \f]
   *
   * \param x (INPUT) the x-coordinate of the point
   * \param y (INPUT) the y-coordinate of the point
   *
   * \return The length of the point
   */
  template <typename NumT>
  NumT
  __pt_length(const NumT x, const NumT y);

  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   *
   * This function takes two edges and finds the crossing point of the edges 
   * if the orientation allows this.
   *
   * \param orig_x1 (INPUT) the x-coordinate of the origin point of edge 1
   * \param orig_y1 (INPUT) the y-coordinate of the origin point of edge 1
   * \param dest_x1 (INPUT) the x-coordinate of the destination point of edge 1
   * \param dest_y1 (INPUT) the y-coordinate of the destination point of edge 1
   * \param orig_x2 (INPUT) the x-coordinate of the origin point of edge 2
   * \param orig_y2 (INPUT) the y-coordinate of the origin point of edge 2
   * \param dest_x2 (INPUT) the x-coordinate of the destination point of edge 2
   * \param dest_y2 (INPUT) the y-coordinate of the destination point of edge 2
   * \param cross_x (OUTPUT) the x-coordinate of the crossing point
   * \param cross_y (OUTPUT) the y-coordinate of the crossing point
   *
   * \return The orientation of the edges
   */
  template <typename NumT>
  int
  __crossing_pt(const NumT orig_x1, const NumT orig_y1, 
                const NumT dest_x1, const NumT dest_y1,
                const NumT orig_x2, const NumT orig_y2, 
                const NumT dest_x2, const NumT dest_y2,
                NumT & cross_x, NumT & cross_y);

  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   *
   * This function takes two edges and finds the parametric slope for the 
   * intersection if the orientation allows this.
   *
   * \param orig_x1 (INPUT) the x-coordinate of the origin point of edge 1
   * \param orig_y1 (INPUT) the y-coordinate of the origin point of edge 1
   * \param dest_x1 (INPUT) the x-coordinate of the destination point of edge 1
   * \param dest_y1 (INPUT) the y-coordinate of the destination point of edge 1
   * \param orig_x2 (INPUT) the x-coordinate of the origin point of edge 2
   * \param orig_y2 (INPUT) the y-coordinate of the origin point of edge 2
   * \param dest_x2 (INPUT) the x-coordinate of the destination point of edge 2
   * \param dest_y2 (INPUT) the y-coordinate of the destination point of edge 2
   * \param para_slope (OUTPUT) the parametric slope of the intersection
   *
   * \return The orientation of the edges
   */
  template <typename NumT>
  int
  __edge_intersect(const NumT orig_x1, const NumT orig_y1, 
                   const NumT dest_x1, const NumT dest_y1,
                   const NumT orig_x2, const NumT orig_y2, 
                   const NumT dest_x2, const NumT dest_y2,
                   NumT & para_slope);
  
  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   *
   * This function takes an edge and a parametric slope parameter and 
   * calculates a point via the following formula
   *
   * \f[
   * pt_i = orig_i + t * \left(dest_i - orig_i\right)
   * \f]
   *
   * where \f$i\f$ is either the x or y coordinate of the points and \f$t\f$ 
   * is the parametric slope.
   *
   * \param orig_x (INPUT) the x-coordinate of the origin point of edge 
   * \param orig_y (INPUT) the y-coordinate of the origin point of edge 
   * \param dest_x (INPUT) the x-coordinate of the destination point of edge 
   * \param dest_y (INPUT) the y-coordinate of the destination point of edge 
   * \param para_slope (INPUT) the parametric slope for the edge line
   * \param pt_x (OUTPUT) the x-coordinate of the point on the edge line 
   * \param pt_y (OUTPUT) the y-coordinate of the point on the edge line 
   */
  template <typename NumT>
  void
  __edge_pt(const NumT orig_x, const NumT orig_y, 
            const NumT dest_x, const NumT dest_y,
            const NumT para_slope,
            NumT & pt_x, NumT & pt_y);

  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   *
   * This function calculates the dot product between two points via the 
   * following formula
   *
   * \f[
   * \vec{pt1} \cdot \vec{pt2} = pt1_x * pt2_x + pt1_y * pt2_y
   * \f]
   *
   * This function is taken from section 4.4.3 of <em>Computational Geometry 
   * and Computer Graphics in C++</em> by Michael Laszlo.
   *
   * \param pt1_x (INPUT) the x-coordinate of the first point
   * \param pt1_y (INPUT) the y-coordinate of the first point
   * \param pt2_x (INPUT) the x-coordinate of the second point
   * \param pt2_y (INPUT) the y-coordinate of the second point
   *
   * \return The value of the dot product
   */
  template <typename NumT>
  NumT
  __dot_product(const NumT pt1_x, const NumT pt1_y, 
                const NumT pt2_x, const NumT pt2_y);

  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   *
   * This function takes two edges and determines if edge 1 aims at edge 2.
   * This function is taken from section 6.5 of <em>Computational Geometry and 
   * Computer Graphics in C++</em> by Michael Laszlo.
   *
   * Edge 1 aims at edge 2 if:
   *
   * \li \f$\vec{E1} \times \vec{E2} \geq 0\f$ and edge 1 destination point 
   * is not RIGHT of edge 2
   * \li \f$\vec{E1} \times \vec{E2} < 0\f$ and edge 1 destination point is 
   * not LEFT of edge 2
   *
   * \param orig_x1 (INPUT) the x-coordinate of the origin point of edge 1
   * \param orig_y1 (INPUT) the y-coordinate of the origin point of edge 1
   * \param dest_x1 (INPUT) the x-coordinate of the destination point of edge 1
   * \param dest_y1 (INPUT) the y-coordinate of the destination point of edge 1
   * \param orig_x2 (INPUT) the x-coordinate of the origin point of edge 2
   * \param orig_y2 (INPUT) the y-coordinate of the origin point of edge 2
   * \param dest_x2 (INPUT) the x-coordinate of the destination point of edge 2
   * \param dest_y2 (INPUT) the y-coordinate of the destination point of edge 2
   * \param point_class (INPUT) the classification of the destination point of 
   * edge 1 with respect to edge 2
   * \param cross_type (INPUT) the crossing-type classification of the two 
   * edges
   *
   * \return A boolean determining if the two edges aim at each other
   */
  template <typename NumT>
  bool
  __aims_at(const NumT orig_x1, const NumT orig_y1, 
            const NumT dest_x1, const NumT dest_y1,
            const NumT orig_x2, const NumT orig_y2, 
            const NumT dest_x2, const NumT dest_y2,
            const int point_class, const int cross_type);

  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   * 
   * This function takes a polygon's coordinate arrays and the current 
   * coordinate arrays in the intersection polygon and advances the polygon 
   * edge and adds points to the current intersection polygon if those points 
   * lie on the intersection edge. This function is taken from section 6.5 
   * of <em>Computational Geometry and Computer Graphics in C++</em> by 
   * Michael Laszlo.
   * 
   * \param x_coord (INPUT) the x-coordinate array of the polygon to check
   * \param y_coord (INPUT) the y-coordinate array of the polygon to check
   * \param inside (INPUT) the current polygon that is inside the other
   * \param ix_coord (INPUT/OUTPUT) the x-coordinate array of the intersection 
   * polygon
   * \param iy_coord (INPUT/OUTPUT) the y-coordinate array of the intersection 
   * polygon
   * \param orig_pos (INPUT/OUTPUT) the index position of the current edge's 
   * origin
   * \param dest_pos (INPUT/OUTPUT) the index position of the current edge's 
   * destination
   */
  template <typename NumT>
  void
  __advance_edge(const Nessi::Vector<NumT> & x_coord, 
                 const Nessi::Vector<NumT> & y_coord, 
                 const int inside,
                 Nessi::Vector<NumT> & ix_coord,
                 Nessi::Vector<NumT> & iy_coord,
                 std::size_t & orig_pos, 
                 std::size_t & dest_pos);

  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   * 
   * This function checks an index against the size of a polygon. If the 
   * index is equal to or larger that the polygon size, the index is shifted 
   * by subtracting the polygon size. This helps connect the last point in a
   * coordinate array to the first point.
   * 
   * \param curr_index (INPUT) the current coordinate array index
   * \param poly_size (INPUT) the size of the polygon
   *
   * \return A possibly modified index
   */
  std::size_t __wrap_indicies(const std::size_t curr_index, 
                              const std::size_t poly_size);

  /**
   * \brief PRIVATE helper function for Utils::convex_polygon_intersect
   * 
   * This function checks to see if a point is within a convex polygon. This 
   * is taken from section 4.3.5 of <em>Computational Geometry and Computer 
   * Graphics in C++</em> by Michael Laszlo.
   *
   * \param pt_x (INPUT) the x-coordinate of the point to check
   * \param pt_y (INPUT) the y-coordinate of the point to check
   * \param orig_pos (INPUT/OUTPUT) the current origin point index
   * \param x_coord (INPUT) the x-coordinate array of the polygon to check
   * \param y_coord (INPUT) the y-coordinate array of the polygon to check
   *
   * \return A boolean determining if the point is inside the given polygon
   */
  template <typename NumT>
  bool
  __pt_in_convex_polygon(const NumT pt_x, const NumT pt_y,
                         std::size_t & orig_pos, 
                         const Nessi::Vector<NumT> & x_coord, 
                         const Nessi::Vector<NumT> & y_coord);
  /**
   * \} // end of convex_polygon_intersect
   */ 

} // Utils

#endif // _GEOMETRY_HPP
