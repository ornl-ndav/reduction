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
 * \file utils/src/calc_area_2D_polygon.cpp
 */

#include "calc_area_2D_polygon.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the calc_area_2D_polygon function 
   * defined in 3.59
   *
   * \ingroup calc_area_2D_polygon
   */
  template std::string
  calc_area_2D_polygon(const Nessi::Vector<float> & x_coord,
                       const Nessi::Vector<float> & y_coord,
                       const std::size_t size_poly,
                       const bool signed_area,
                       float & area,
                       void *temp);

  /**
   * This is the double precision float declaration of the 
   * calc_area_2D_polygon function defined in 3.59
   *
   * \ingroup calc_area_2D_polygon
   */
  template std::string
  calc_area_2D_polygon(const Nessi::Vector<double> & x_coord,
                       const Nessi::Vector<double> & y_coord,
                       const std::size_t size_poly,
                       const bool signed_area,
                       double & area,
                       void *temp);

} // Utils
