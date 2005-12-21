/**
 * $Id$
 *
 * \file utils/src/fit_linear_background.cpp
 */
#include "fit_linear_background.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.43.
   *
   * \see fit_linear_background()
   */
  template std::string
  fit_linear_background<float>(Nessi::Vector<float> const & axis_in,
			       Nessi::Vector<float> const & input,
			       Nessi::Vector<float> const & input_err2,
			       float min_val, float max_val,
			       float slope_start, 
			       float intercept_start,
			       float & slope_out, float & slope_out_err2,
			       float & intercept_out,
			       float & intercept_out_err2,
			       void *temp);
  /**
   * This is the double precision float declaration of the function
   * defined in 3.43.
   *
   * \see fit_linear_background()
   */
  template std::string
  fit_linear_background<double>(Nessi::Vector<double> const & axis_in,
				Nessi::Vector<double> const & input,
				Nessi::Vector<double> const & input_err2,
				double min_val, double max_val,
				double slope_start, 
				double intercept_start,
				double & slope_out, double & slope_out_err2,
				double & intercept_out,
				double & intercept_out_err2,
				void *temp);
} // Utils
