/**
 * $Id$
 *
 * \file axis_manip/src/rebin_axis_1D.cpp
 */
#include "rebin_axis_1D.hpp"
#include <stdexcept>

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.12.
   *
   * \ingroup rebin_axis_1D
   */
  template std::string 
  rebin_axis_1D<float>(const Nessi::Vector<float> & axis_in,
		       const Nessi::Vector<float> & input,
		       const Nessi::Vector<float> & input_err2,
		       const Nessi::Vector<float> & axis_out,
		       Nessi::Vector<float> & output,
		       Nessi::Vector<float> & output_err2,
		       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.12.
   *
   * \ingroup rebin_axis_1D
   */
  template std::string 
  rebin_axis_1D<double>(const Nessi::Vector<double> & axis_in,
			const Nessi::Vector<double> & input,
			const Nessi::Vector<double> & input_err2,
			const Nessi::Vector<double> & axis_out,
			Nessi::Vector<double> & output,
			Nessi::Vector<double> & output_err2,
			void *temp);
} // AxisManip
