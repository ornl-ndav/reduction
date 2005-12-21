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
  rebin_axis_2D<float>(Nessi::Vector<float> const & axis_in_1,
		       Nessi::Vector<float> const & axis_in_2,
		       Nessi::Vector<float> const & input,
		       Nessi::Vector<float> const & input_err2,
		       Nessi::Vector<float> const & axis_out_1,
		       Nessi::Vector<float> const & axis_out_2,
		       Nessi::Vector<float> & output,
		       Nessi::Vector<float> & output_err2,
		       void *temp);
  
  /**
   * This is the double precision float declaraion of the function
   * defined in 3.13.
   *
   * \see rebin_axis_2D()
   */
  template std::string 
  rebin_axis_2D<double>(Nessi::Vector<double> const & axis_in_1,
			Nessi::Vector<double> const & axis_in_2,
			Nessi::Vector<double> const & input,
			Nessi::Vector<double> const & input_err2,
			Nessi::Vector<double> const & axis_out_1,
			Nessi::Vector<double> const & axis_out_2,
			Nessi::Vector<double> & output,
			Nessi::Vector<double> & output_err2,
			void *temp);
} // AxisManip
