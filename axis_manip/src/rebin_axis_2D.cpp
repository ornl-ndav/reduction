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
  rebin_axis_2D<float>(const Nessi::Vector<float> & axis_in_1,
		       const Nessi::Vector<float> & axis_in_2,
		       const Nessi::Vector<float> & input,
		       const Nessi::Vector<float> & input_err2,
		       const Nessi::Vector<float> & axis_out_1,
		       const Nessi::Vector<float> & axis_out_2,
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
  rebin_axis_2D<double>(const Nessi::Vector<double> & axis_in_1,
			const Nessi::Vector<double> & axis_in_2,
			const Nessi::Vector<double> & input,
			const Nessi::Vector<double> & input_err2,
			const Nessi::Vector<double> & axis_out_1,
			const Nessi::Vector<double> & axis_out_2,
			Nessi::Vector<double> & output,
			Nessi::Vector<double> & output_err2,
			void *temp);
} // AxisManip
