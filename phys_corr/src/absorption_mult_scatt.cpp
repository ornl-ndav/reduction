/**
 * $Id$
 *
 * \file phys_corr/src/absorption_mult_scatt.cpp
 */
#include "absorption_mult_scatt.hpp"

namespace PhysCorr
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.36.
   *
   * \see absorption_mult_scatt()
   */
  template std::string
  absorption_mult_scatt<float>(std::vector<float> const & axis_in,
			       std::vector<float> const & input,
			       std::vector<float> const & input_err2,
			       float pathlength,
			       float polar_angle,
			       std::vector<float> & output,
			       std::vector<float> & output_err2,
			       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.36.
   *
   * \see absorption_mult_scatt()
   */
  template std::string
  absorption_mult_scatt<double>(std::vector<double> const & axis_in,
				std::vector<double> const & input,
				std::vector<double> const & input_err2,
				double pathlength,
				double polar_angle,
				std::vector<double> & output,
				std::vector<double> & output_err2,
				void *temp);

} // PhysCorr
