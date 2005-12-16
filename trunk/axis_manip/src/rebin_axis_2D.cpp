/**
 * $Id$
 *
 * \file axis_manip/src/rebin_axis_2D.cpp
 */
#include "rebin_axis_2D.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaraion of the function defined in 3.13.
   *
   * \see rebin_axis_2D()
   */
  template std::string 
  rebin_axis_2D<float>(std::vector<float> const & axis_in_1,
		       std::vector<float> const & axis_in_2,
		       std::vector<float> const & input,
		       std::vector<float> const & input_err2,
		       std::vector<float> const & axis_out_1,
		       std::vector<float> const & axis_out_2,
		       std::vector<float> & output,
		       std::vector<float> & output_err2,
		       void *temp);
  
  /**
   * This is the double precision float declaraion of the function
   * defined in 3.13.
   *
   * \see rebin_axis_2D()
   */
  template std::string 
  rebin_axis_2D<double>(std::vector<double> const & axis_in_1,
			std::vector<double> const & axis_in_2,
			std::vector<double> const & input,
			std::vector<double> const & input_err2,
			std::vector<double> const & axis_out_1,
			std::vector<double> const & axis_out_2,
			std::vector<double> & output,
			std::vector<double> & output_err2,
			void *temp);
} // AxisManip
