/**
 *  $Id$
 *
 * \file axis_manip/src/rebin_axis_4D.cpp
 */
#include "rebin_axis_4D.hpp"

namespace AxisManip
{
  // explicit instantiations  

  /**
   * This is the float declaration of the function defined in 3.14.
   *
   * \see rebin_axis_4D()
   */
  template std::string 
  rebin_axis_4D<float>(Nessi::Vector<float> const & axis_in_1,
		       Nessi::Vector<float> const & axis_in_2,
		       Nessi::Vector<float> const & axis_in_3,
		       Nessi::Vector<float> const & axis_in_4,
		       Nessi::Vector<float> const & input,
		       Nessi::Vector<float> const & input_err2,
		       Nessi::Vector<float> const & axis_out_1,
		       Nessi::Vector<float> const & axis_out_2,
		       Nessi::Vector<float> const & axis_out_3,
		       Nessi::Vector<float> const & axis_out_4,
		       Nessi::Vector<float> & output,
		       Nessi::Vector<float> & output_err2,
		       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.14.
   *
   * \see rebin_axis_4D()
   */
  template std::string 
  rebin_axis_4D<double>(Nessi::Vector<double> const & axis_in_1,
			Nessi::Vector<double> const & axis_in_2,
			Nessi::Vector<double> const & axis_in_3,
			Nessi::Vector<double> const & axis_in_4,
			Nessi::Vector<double> const & input,
			Nessi::Vector<double> const & input_err2,
			Nessi::Vector<double> const & axis_out_1,
			Nessi::Vector<double> const & axis_out_2,
			Nessi::Vector<double> const & axis_out_3,
			Nessi::Vector<double> const & axis_out_4,
			Nessi::Vector<double> & output,
			Nessi::Vector<double> & output_err2,
			void *temp);
} // AxisManip
