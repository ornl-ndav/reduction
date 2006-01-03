/**
 * $Id$
 *
 * \file utils/src/fit_reflectometer_background.cpp
 */
#include "fit_reflectometer_background.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.42.
   *
   * \see fit_reflectometer_background()
   */
  template std::string
  fit_reflectometer_background<float>(const Nessi::Vector<float> & axis_in,
				      const Nessi::Vector<float> & input,
				      const Nessi::Vector<float> & input_err2,
				      const Nessi::Vector<float> & params_in,
				      Nessi::Vector<float> & output,
				      Nessi::Vector<float> & output_err2,
				      Nessi::Vector<float> & params_out,
				      Nessi::Vector<float> & params_out_err2,
				      void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.42.
   *
   * \see fit_reflectometer_background()
   */
  template std::string
  fit_reflectometer_background<double>(const Nessi::Vector<double> & axis_in,
				       const Nessi::Vector<double> & input,
				       const Nessi::Vector<double> & input_err2,
				       const Nessi::Vector<double> & params_in,
				       Nessi::Vector<double> & output,
				       Nessi::Vector<double> & output_err2,
				       Nessi::Vector<double> & params_out,
				       Nessi::Vector<double> & params_out_err2,
				       void *temp);
} // Utils
