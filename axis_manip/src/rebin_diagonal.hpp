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
 * \file axis_manip/src/rebin_diagonal.hpp
 */
#ifndef _REBIN_DIAGONAL_HPP
#define _REBIN_DIAGONAL_HPP 1

#include "nessi_warn.hpp"
#include "rebinning.hpp"
#include "size_checks.hpp"
#include "utils.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the rebin_diagonal function name
  const std::string rd_func_str = "AxisManip::rebin_diagonal";

  // 3.53
  template <typename NumT>
  std::string
  rebin_diagonal(const Nessi::Vector<NumT> & axis_in_1,
                 const Nessi::Vector<NumT> & axis_in_2,
                 const Nessi::Vector<NumT> & input,
                 const Nessi::Vector<NumT> & input_err2,
                 const Nessi::Vector<NumT> & axis_out_1,
                 const Nessi::Vector<NumT> & axis_out_2,
                 Nessi::Vector<NumT> & output,
                 Nessi::Vector<NumT> & output_err2,
                 void *temp=NULL)
  {
    // check that the original histogram is of the proper size
    try
      {
        Utils::check_histo_sizes(input, input_err2, axis_in_1);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(rd_func_str+": original histogram "
                                    +e.what());
      }
    // check that the incoming axes are the same size
    try
      {
        Utils::check_sizes_square(axis_in_1, axis_in_2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(rd_func_str+": input axes "
                                    +e.what());
      }
    // check that the rebinned histogram is of the proper size
    try
      {
        Utils::check_histo_sizes(output, output_err2, axis_out_1, axis_out_2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(rd_func_str+": rebinned histogram "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);

    std::size_t input_size = input.size();

    std::vector<std::size_t> length_axis_out;
    length_axis_out.push_back(axis_out_1.size() - 1);
    length_axis_out.push_back(axis_out_2.size() - 1);
	bool checkCont = true;


	#pragma omp parallel for private(checkCont)
    for(int k = 0; k < static_cast<int>(input_size); ++k)
    {
        // Get the bin boundaries in out of the original axes
        NumT x_orig_lo = axis_in_1[k];
        NumT x_orig_hi = axis_in_1[k+1];
        NumT y_orig_lo = axis_in_2[k];
        NumT y_orig_hi = axis_in_2[k+1];

        NumT dx_orig = x_orig_hi - x_orig_lo;
        NumT dy_orig = y_orig_hi - y_orig_lo;

        NumT width = dx_orig * dy_orig;

        // Check to see if the original bin boundaries are outside the 
        // rebinned axes boundaries
        bool check1 = (x_orig_lo < axis_out_1[0] && 
                       x_orig_hi < axis_out_1[0]);
        bool check2 = (x_orig_lo > axis_out_1[length_axis_out[0]] && 
                       x_orig_hi > axis_out_1[length_axis_out[0]]);
        bool check3 = (y_orig_lo < axis_out_2[0] && 
                       y_orig_hi < axis_out_2[0]);
        bool check4 = (y_orig_lo > axis_out_2[length_axis_out[1]] && 
                       y_orig_hi > axis_out_2[length_axis_out[1]]);

        if(check1 || check2 || check3 || check4)
        {
            checkCont = false;
        }
		if (checkCont)
		{
        
        	std::pair<typename Nessi::Vector<NumT>::const_iterator, 
          		typename Nessi::Vector<NumT>::const_iterator> range1;
        	std::pair<typename Nessi::Vector<NumT>::const_iterator, 
          		typename Nessi::Vector<NumT>::const_iterator> range2;
        	std::pair<typename Nessi::Vector<NumT>::const_iterator, 
          		typename Nessi::Vector<NumT>::const_iterator> range3;
        	std::pair<typename Nessi::Vector<NumT>::const_iterator, 
          		typename Nessi::Vector<NumT>::const_iterator> range4;

        	// Find the bin boundary indicies in the rebinned axes that correspond 
        	// to the location of the original bin boundaries
        	range1 = std::equal_range(axis_out_1.begin(), axis_out_1.end(), 
                                  x_orig_lo);
        	range2 = std::equal_range(axis_out_1.begin(), axis_out_1.end(), 
                                  x_orig_hi);
        	range3 = std::equal_range(axis_out_2.begin(), axis_out_2.end(), 
                                  y_orig_lo);
        	range4 = std::equal_range(axis_out_2.begin(), axis_out_2.end(), 
                                  y_orig_hi);

        	std::size_t index1 = range1.second - axis_out_1.begin();
        	std::size_t index2 = range2.second - axis_out_1.begin();
        	std::size_t index3 = range3.second - axis_out_2.begin();
        	std::size_t index4 = range4.second - axis_out_2.begin();
        	std::size_t index5 = range1.first - axis_out_1.begin();
        	std::size_t index6 = range2.first - axis_out_1.begin();
        	std::size_t index7 = range3.first - axis_out_2.begin();
        	std::size_t index8 = range4.first - axis_out_2.begin();
        
        	// Determine the range of indices to rebin over
        	std::size_t index_x_left = Utils::__fix_index(std::max(index1,
                                                               index5) - 1, 
                                                      length_axis_out[0]);
        	std::size_t index_x_right = Utils::__fix_index(std::min(index2, 
                                                                index6),
                                                       length_axis_out[0]);
        	std::size_t index_y_left = Utils::__fix_index(std::max(index3, 
                                                               index7) - 1,
                                                      length_axis_out[1]);
        	std::size_t index_y_right = Utils::__fix_index(std::min(index4, 
                                                                index8),
                                                       length_axis_out[1]);
        
        	if(index_x_left == std::numeric_limits<std::size_t>::max() || 
           		index_y_left == std::numeric_limits<std::size_t>::max())
          	{
            	checkCont = false;
          	}
			if (checkCont)
			{

        		// Actually do the rebinning
				#pragma omp parallel for
        		for(int i = static_cast<int>(index_x_left); 
						i < static_cast<int>(index_x_right); ++i)
          		{
            		NumT x_rebin_lo = axis_out_1[i];
            		NumT x_rebin_hi = axis_out_1[i+1];

            		NumT delta_x = std::min(x_orig_hi, x_rebin_hi) - 
              		std::max(x_orig_lo, x_rebin_lo);
			
					#pragma omp parallel for
            		for(int j = static_cast<int>(index_y_left); 
							j <	static_cast<int>(index_y_right); ++j)
              		{
                		NumT y_rebin_lo = axis_out_2[j];
                		NumT y_rebin_hi = axis_out_2[j+1];

                		NumT delta_y = std::min(y_orig_hi, y_rebin_hi) - 
                  			std::max(y_orig_lo, y_rebin_lo);

                		NumT delta = delta_x * delta_y;
                
                		NumT portion = delta / width;

                		std::size_t channel = j + i * length_axis_out[1];
						#pragma omp critical
						{
                			output[channel] += input[k] * portion;                
                			output_err2[channel] += input_err2[k] * portion * portion;
						}
              		}
				}
          	}
		}
	}
    
    return retstr;
  }

} // AxisManip

#endif // _REBIN_DIAGONAL_HPP
