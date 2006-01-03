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
  rebin_axis_4D<float>(const Nessi::Vector<float> & axis_in_1,
		       const Nessi::Vector<float> & axis_in_2,
		       const Nessi::Vector<float> & axis_in_3,
		       const Nessi::Vector<float> & axis_in_4,
		       const Nessi::Vector<float> & input,
		       const Nessi::Vector<float> & input_err2,
		       const Nessi::Vector<float> & axis_out_1,
		       const Nessi::Vector<float> & axis_out_2,
		       const Nessi::Vector<float> & axis_out_3,
		       const Nessi::Vector<float> & axis_out_4,
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
  rebin_axis_4D<double>(const Nessi::Vector<double> & axis_in_1,
			const Nessi::Vector<double> & axis_in_2,
			const Nessi::Vector<double> & axis_in_3,
			const Nessi::Vector<double> & axis_in_4,
			const Nessi::Vector<double> & input,
			const Nessi::Vector<double> & input_err2,
			const Nessi::Vector<double> & axis_out_1,
			const Nessi::Vector<double> & axis_out_2,
			const Nessi::Vector<double> & axis_out_3,
			const Nessi::Vector<double> & axis_out_4,
			Nessi::Vector<double> & output,
			Nessi::Vector<double> & output_err2,
			void *temp);
} // AxisManip
