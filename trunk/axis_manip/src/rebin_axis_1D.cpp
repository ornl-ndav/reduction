/**
 * $Id$
 *
 * \file axis_manip/src/rebin_axis_1D.cpp
 */
#include "rebin_axis_1D.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.12.
   *
   * \see rebin_axis_1D()
   */
  template std::string 
  rebin_axis_1D<float>(Nessi::Vector<float> const & axis_in,
		       Nessi::Vector<float> const & input,
		       Nessi::Vector<float> const & input_err2,
		       Nessi::Vector<float> const & axis_out,
		       Nessi::Vector<float> & output,
		       Nessi::Vector<float> & output_err2,
		       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.12.
   *
   * \see rebin_axis_1D()
   */
  template std::string 
  rebin_axis_1D<double>(Nessi::Vector<double> const & axis_in,
			Nessi::Vector<double> const & input,
			Nessi::Vector<double> const & input_err2,
			Nessi::Vector<double> const & axis_out,
			Nessi::Vector<double> & output,
			Nessi::Vector<double> & output_err2,
			void *temp);
} // AxisManip
