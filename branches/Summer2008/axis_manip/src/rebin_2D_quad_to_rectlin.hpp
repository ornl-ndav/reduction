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
 * \file axis_manip/src/rebin_2D_quad_to_rectlin.hpp
 */
#ifndef _REBIN_2D_QUAD_TO_RECTLIN_HPP
#define _REBIN_2D_QUAD_TO_RECTLIN_HPP 1

#include "geometry.hpp"
#include "nessi_warn.hpp"
#include "rebinning.hpp"
#include "size_checks.hpp"
#include "utils.hpp"
#include <algorithm>
#include <limits>
#include <sstream>
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the rebin_2D_quad_to_rectlin function name
  const std::string r2qtl_func_str = "AxisManip::rebin_2D_quad_to_rectlin";

  /// Size (points) of a quadrilateral or rectilinear bin
  static const std::size_t SIZE_QUAD = 4;

  /// Over-Maximum Size (points) of a quadrilateral and rectilinear bin overlap
  static const std::size_t SIZE_TWO_QUADS = 2 * SIZE_QUAD;

  /// Minimum size of a polygon is 3 points
  static const std::size_t MIN_SIZE_POLY = 3;

  // 3.61
  template <typename NumT>
  std::string
  rebin_2D_quad_to_rectlin(const Nessi::Vector<NumT> & axis_in_x1,
                           const Nessi::Vector<NumT> & axis_in_y1,
                           const Nessi::Vector<NumT> & axis_in_x2,
                           const Nessi::Vector<NumT> & axis_in_y2,
                           const Nessi::Vector<NumT> & axis_in_x3,
                           const Nessi::Vector<NumT> & axis_in_y3,
                           const Nessi::Vector<NumT> & axis_in_x4,
                           const Nessi::Vector<NumT> & axis_in_y4,
                           const Nessi::Vector<NumT> & input,
                           const Nessi::Vector<NumT> & input_err2,
                           const Nessi::Vector<NumT> & axis_out_1,
                           const Nessi::Vector<NumT> & axis_out_2,
                           Nessi::Vector<NumT> & orig_bin_x,
                           Nessi::Vector<NumT> & orig_bin_y,
                           Nessi::Vector<NumT> & rebin_bin_x,
                           Nessi::Vector<NumT> & rebin_bin_y,
                           Nessi::Vector<NumT> & frac_bin_x,
                           Nessi::Vector<NumT> & frac_bin_y,
                           Nessi::Vector<NumT> & output,
                           Nessi::Vector<NumT> & output_err2,
                           Nessi::Vector<NumT> & frac_area,
                           void *temp=NULL)
  {
    // check that the coordinate pair arrays for the 1st corner are the proper 
    // size
    try
      {
        Utils::check_sizes_square(axis_in_x1, axis_in_y1);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": input axes (x1,y1) "
                                    +e.what());
      }
    // check that the coordinate pair arrays for the 2nd corner are the proper 
    // size
    try
      {
        Utils::check_sizes_square(axis_in_x2, axis_in_y2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": input axes (x2,y2) "
                                    +e.what());
      }
    // check that the coordinate pair arrays for the 3rd corner are the proper 
    // size
    try
      {
        Utils::check_sizes_square(axis_in_x3, axis_in_y3);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": input axes (x3,y3) "
                                    +e.what());
      }
    // check that the coordinate pair arrays for the 4th corner are the proper 
    // size
    try
      {
        Utils::check_sizes_square(axis_in_x4, axis_in_y4);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": input axes (x4,y4) "
                                    +e.what());
      }
    // check that the x-coordinate pair arrays for the 1st and 2nd corners are 
    // the proper size
    try
      {
        Utils::check_sizes_square(axis_in_x1, axis_in_x2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": input axes (x1,x2) "
                                    +e.what());
      }
    // check that the x-coordinate pair arrays for the 2nd and 3rd corners are 
    // the proper size
    try
      {
        Utils::check_sizes_square(axis_in_x2, axis_in_x3);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": input axes (x2,x3) "
                                    +e.what());
      }
    // check that the x-coordinate pair arrays for the 3rd and 4th corners are 
    // the proper size
    try
      {
        Utils::check_sizes_square(axis_in_x3, axis_in_x4);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": input axes (x3,x4) "
                                    +e.what());
      }
    // check that the original histogram is of the proper size
    try
      {
        Utils::check_sizes_square(input, input_err2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": original histogram "
                                    +e.what());
      }
    // check that the original histogram and x-coordinate of the 1st corner are
    // the proper size
    try
      {
        Utils::check_sizes_square(input, axis_in_x1);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": original histogram, x1 "
                                    +e.what());
      }
    // check that the rebinned histogram is of the proper size
    try
      {
        Utils::check_histo_sizes(output, output_err2, axis_out_1, axis_out_2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": rebinned histogram "
                                    +e.what());
      }
    // check that the coordinate pair arrays for the original bin placehoder 
    // are the proper size
    try
      {
        Utils::check_sizes_square(orig_bin_x, orig_bin_y);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": original bin (x,y) "
                                    +e.what());
      }
    // check that the coordinate pair arrays for the rebin bin placehoder 
    // are the proper size
    try
      {
        Utils::check_sizes_square(rebin_bin_x, rebin_bin_y);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": rebin bin (x,y) "
                                    +e.what());
      }
    // check that the coordinate pair arrays for the fraction bin placehoder 
    // are the proper size
    try
      {
        Utils::check_sizes_square(frac_bin_x, frac_bin_y);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(r2qtl_func_str+": fraction bin (x,y) "
                                    +e.what());
      }
    // check that the original bin placeholder x-coordinate array is the 
    // right size
    if (orig_bin_x.size() != SIZE_QUAD)
      {
        throw std::invalid_argument(r2qtl_func_str+": original bin must be "
                                    +"size 4");
      }
    // check that the rebin bin placeholder x-coordinate array is the 
    // right size
    if (rebin_bin_x.size() != SIZE_QUAD)
      {
        throw std::invalid_argument(r2qtl_func_str+": rebin bin must be "
                                    +"size 4");
      }
    // check that the fraction bin placeholder x-coordinate array is the 
    // right size
    if (frac_bin_x.size() != SIZE_TWO_QUADS)
      {
        throw std::invalid_argument(r2qtl_func_str+": fraction bin must be "
                                    +"size 8 (2*4)");
      }

    std::string retstr(Nessi::EMPTY_WARN);

    std::size_t input_size = input.size();

    std::vector<std::size_t> length_axis_out;
    length_axis_out.push_back(axis_out_1.size() - 1);
    length_axis_out.push_back(axis_out_2.size() - 1);

    for(std::size_t k = 0; k < input_size; ++k)
      {
        // Get the bin boundaries in out of the original axes
        orig_bin_x[0] = axis_in_x1[k];
        orig_bin_x[1] = axis_in_x2[k];
        orig_bin_x[2] = axis_in_x3[k];
        orig_bin_x[3] = axis_in_x4[k];

        orig_bin_y[0] = axis_in_y1[k];
        orig_bin_y[1] = axis_in_y2[k];
        orig_bin_y[2] = axis_in_y3[k];
        orig_bin_y[3] = axis_in_y4[k];

        // Find the minimum and maximum values for the x and y coordinates
        NumT x_min = *std::min_element(orig_bin_x.begin(), orig_bin_x.end());
        NumT x_max = *std::max_element(orig_bin_x.begin(), orig_bin_x.end());

        NumT y_min = *std::min_element(orig_bin_y.begin(), orig_bin_y.end());
        NumT y_max = *std::max_element(orig_bin_y.begin(), orig_bin_y.end());

        // Check to see if the original bin boundaries are outside the 
        // rebinned axes boundaries
        bool check1 = (x_min < axis_out_1[0] && 
                       x_max < axis_out_1[0]);
        bool check2 = (x_min > axis_out_1[length_axis_out[0]] && 
                       x_max > axis_out_1[length_axis_out[0]]);
        bool check3 = (y_min < axis_out_2[0] && 
                       y_max < axis_out_2[0]);
        bool check4 = (y_min > axis_out_2[length_axis_out[1]] && 
                       y_max > axis_out_2[length_axis_out[1]]);

        if(check1 || check2 || check3 || check4)
          {
            continue;
          }
        
        // Determine the range of indices to rebin over
        std::size_t index_x_left;
        std::size_t index_x_right;
        std::size_t index_y_left;
        std::size_t index_y_right;

        Utils::bisect_helper(axis_out_1, x_min, index_x_left);
        Utils::bisect_helper(axis_out_1, x_max, index_x_right);
        Utils::bisect_helper(axis_out_2, y_min, index_y_left);
        Utils::bisect_helper(axis_out_2, y_max, index_y_right);
        
        if(index_x_left == std::numeric_limits<std::size_t>::max() || 
           index_y_left == std::numeric_limits<std::size_t>::max())
          {
            continue;
          }

        // Actually do the rebinning
        for(std::size_t i = index_x_left; i <= index_x_right; ++i)
          {
            for(std::size_t j = index_y_left; j <= index_y_right; ++j)
              {
                // Construct the rectlinear grid bin
                rebin_bin_x[0] = axis_out_1[i];
                rebin_bin_x[1] = axis_out_1[i];
                rebin_bin_x[2] = axis_out_1[i+1];
                rebin_bin_x[3] = axis_out_1[i+1];

                rebin_bin_y[0] = axis_out_2[j];
                rebin_bin_y[1] = axis_out_2[j+1];
                rebin_bin_y[2] = axis_out_2[j+1];
                rebin_bin_y[3] = axis_out_2[j];
                
                try
                  {
                    Utils::convex_polygon_intersect(orig_bin_x, orig_bin_y,
                                                    rebin_bin_x, rebin_bin_y,
                                                    frac_bin_x, frac_bin_y);
                  }
                catch (std::exception &e)
                  {
                    std::ostringstream bad_index;
                    bad_index << "[" << k << "] ";

                    throw std::invalid_argument(r2qtl_func_str + " index"
                                                + bad_index.str() + ": "
                                                + e.what());
                  }

                std::size_t length_poly = frac_bin_x.size();
                if (length_poly < MIN_SIZE_POLY)
                  {
                    // Overlap is not a polygon, so area can't be calculated
                    continue;
                  }

                // Add first two coordinates back into the coordinate arrays 
                // for area calculation
                frac_bin_x.push_back(frac_bin_x[0]);
                frac_bin_x.push_back(frac_bin_x[1]);

                frac_bin_y.push_back(frac_bin_y[0]);
                frac_bin_y.push_back(frac_bin_y[1]);

                NumT portion;

                Utils::calc_area_2D_polygon(frac_bin_x, frac_bin_y, 
                                            length_poly, false,
                                            portion);

                std::size_t channel = j + i * length_axis_out[1];

                output[channel] += input[k] * portion;                
                output_err2[channel] += input_err2[k] * portion * portion;
                frac_area[channel] += portion;
              }
          }
      }
    
    return retstr;
  }

} // AxisManip

#endif // _REBIN_2D_QUAD_TO_RECTLIN_HPP
