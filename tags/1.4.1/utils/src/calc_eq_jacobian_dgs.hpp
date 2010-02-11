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
 * \file utils/src/calc_eq_jacobian_dgs.hpp
 */
#ifndef _CALC_EQ_JACOBIAN_DGS_HPP
#define _CALC_EQ_JACOBIAN_DGS_HPP 1

#include "geometry.hpp"
#include "nessi_warn.hpp"
#include "utils.hpp"
#include "size_checks.hpp"

namespace Utils
{
  // String for holding the calc_eq_jacobian_dgs function name
  const std::string cejd_func_str = "Utils::calc_eq_jacobian_dgs";

  // 3.68
  template <typename NumT>
  std::string
  calc_eq_jacobian_dgs(const Nessi::Vector<NumT> & e1_axis,
                       const Nessi::Vector<NumT> & e2_axis,
                       const Nessi::Vector<NumT> & e3_axis,
                       const Nessi::Vector<NumT> & e4_axis,
                       const Nessi::Vector<NumT> & q1_axis,
                       const Nessi::Vector<NumT> & q2_axis,
                       const Nessi::Vector<NumT> & q3_axis,
                       const Nessi::Vector<NumT> & q4_axis,
                       Nessi::Vector<NumT> & jacobian,
                       void *temp=NULL)
  {
    // Check the dimensions of the incoming arrays
    Utils::check_sizes_square(cejd_func_str+": e1 & e2", e1_axis, e2_axis);
    Utils::check_sizes_square(cejd_func_str+": e2 & e3", e2_axis, e3_axis);
    Utils::check_sizes_square(cejd_func_str+": e3 & e4", e3_axis, e4_axis);
    Utils::check_sizes_square(cejd_func_str+": e1 & q1", e1_axis, q1_axis);
    Utils::check_sizes_square(cejd_func_str+": q1 & q2", q1_axis, q2_axis);
    Utils::check_sizes_square(cejd_func_str+": q2 & q3", q2_axis, q3_axis);
    Utils::check_sizes_square(cejd_func_str+": q3 & q4", q3_axis, q4_axis);
    Utils::check_sizes_square(cejd_func_str+": e1 & jac", e1_axis, jacobian);

    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;
        
    std::size_t size_e1 = e1_axis.size();

    // Create holders and constants for intermediate information
    Nessi::Vector<NumT> e_points;
    Nessi::Vector<NumT> q_points;
    NumT area;
    static const int poly_size = 4;

    for(std::size_t i = 0; i < size_e1; ++i)
      {
        // Create vertex coordinate arrays for area calculation function
        e_points.push_back(e1_axis[i]);
        e_points.push_back(e2_axis[i]);
        e_points.push_back(e3_axis[i]);
        e_points.push_back(e4_axis[i]);
        e_points.push_back(e1_axis[i]);
        e_points.push_back(e2_axis[i]);

        q_points.push_back(q1_axis[i]);
        q_points.push_back(q2_axis[i]);
        q_points.push_back(q3_axis[i]);
        q_points.push_back(q4_axis[i]);
        q_points.push_back(q1_axis[i]);
        q_points.push_back(q2_axis[i]); 

        warn += Utils::calc_area_2D_polygon(e_points, q_points, 
                                            poly_size, false, area);

        if (!warn.empty())
          {
            retstr += warn;
          }

        jacobian[i] = area;

        e_points.clear();
        q_points.clear();
      }

    return retstr;
  }

} // Utils

#endif // _CALC_EQ_JACOBIAN_DGS_HPP
