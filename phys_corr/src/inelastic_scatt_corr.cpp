/**
 * $Id$
 *
 * \file phys_corr/src/inelastic_scatt_corr.cpp
 */
#include "inelastic_scatt_corr.hpp"

namespace PhysCorr
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.40.
   *
   * \see inelastic_scatt_corr()
   */
  template std::string
  inelastic_scatt_corr<float>(const Nessi::Vector<float> & axis_in,
			      const Nessi::Vector<float> & input,
			      const Nessi::Vector<float> & input_err2,
			      Nessi::Vector<float> & output,
			      Nessi::Vector<float> & output_err2,
			      void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.40.
   *
   * \see inelastic_scatt_corr()
   */
  template std::string
  inelastic_scatt_corr<double>(const Nessi::Vector<double> & axis_in,
			       const Nessi::Vector<double> & input,
			       const Nessi::Vector<double> & input_err2,
			       Nessi::Vector<double> & output,
			       Nessi::Vector<double> & output_err2,
			       void *temp);
} // PhysCorr
