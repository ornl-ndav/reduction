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
 * \file utils/src/pt_in_convex_polygon.hpp
 */

#ifndef _PT_IN_CONVEX_POLYGON_HPP
#define _PT_IN_CONVEX_POLYGON_HPP 1

#include "convex_polygon_intersect.hpp"
#include "num_comparison.hpp"

namespace Utils
{
  template <typename NumT>
  bool
  __pt_in_convex_polygon(const NumT pt_x, const NumT pt_y,
                         std::size_t & orig_pos, 
                         const Nessi::Vector<NumT> & x_coord, 
                         const Nessi::Vector<NumT> & y_coord)

  {
    std::size_t poly_size = x_coord.size();

    orig_pos = __wrap_indicies(orig_pos, poly_size);

    // Get edge destination point
    std::size_t dest_pos = __wrap_indicies(orig_pos+1, poly_size);

    if (1 == poly_size)
      {
        // Incoming polygon is a point so they must be equal to coincide
        int x_compare = compare(pt_x, x_coord[orig_pos]);
        int y_compare = compare(pt_y, y_coord[orig_pos]);
        return (0 == x_compare && 0 == y_compare);
      }
    if (2 == poly_size)
      {
        // Incoming polygon is a line, so the point to check must lie on the 
        // line if is it "inside".
        eEdgeClass c = __classify_pt_to_edge(pt_x, pt_y, 
                                             x_coord[orig_pos], 
                                             y_coord[orig_pos],
                                             x_coord[dest_pos], 
                                             y_coord[dest_pos]);
        return ((BETWEEN == c) || (ORIGIN == c) || (DESTINATION == c));
      }
	int returnType = 0;
    
    // Have a standard polygon. If the point lies inside the polygon, the
    // classification is anything but LEFT. A LEFT classification denotes that 
    // point lies outside the polygon.
	#pragma omp parallel for reduction(+:returnType)
    for (int i = 0; i < static_cast<int>(poly_size); ++i)
      {
        std::size_t orig_pos_t = 
				__wrap_indicies(orig_pos + static_cast<std::size_t>(i), poly_size);
        std::size_t dest_pos_t = 
				__wrap_indicies(dest_pos + static_cast<std::size_t>(i), poly_size);

        eEdgeClass c = __classify_pt_to_edge(pt_x, pt_y,
                                             x_coord[orig_pos_t], 
                                             y_coord[orig_pos_t],
                                             x_coord[dest_pos_t],
                                             y_coord[dest_pos_t]);
		int addReturn = 0;

        if (LEFT == c)
          {
            addReturn = 1;
          }
		returnType += addReturn;
      }

	if (returnType > 0)
		return false;
	else
    	return true;
  }
} // Utils

#endif // _PT_IN_CONVEX_POLYGON_HPP
