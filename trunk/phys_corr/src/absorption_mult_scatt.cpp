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
  absorption_mult_scatt<float>(Nessi::Vector<float> const & axis_in,
			       Nessi::Vector<float> const & input,
			       Nessi::Vector<float> const & input_err2,
			       float pathlength,
			       float polar_angle,
			       Nessi::Vector<float> & output,
			       Nessi::Vector<float> & output_err2,
			       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.36.
   *
   * \see absorption_mult_scatt()
   */
  template std::string
  absorption_mult_scatt<double>(Nessi::Vector<double> const & axis_in,
				Nessi::Vector<double> const & input,
				Nessi::Vector<double> const & input_err2,
				double pathlength,
				double polar_angle,
				Nessi::Vector<double> & output,
				Nessi::Vector<double> & output_err2,
				void *temp);

} // PhysCorr
