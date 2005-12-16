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
  inelastic_scatt_corr<float>(std::vector<float> const & axis_in,
			      std::vector<float> const & input,
			      std::vector<float> const & input_err2,
			      std::vector<float> & output,
			      std::vector<float> & output_err2,
			      void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.40.
   *
   * \see inelastic_scatt_corr()
   */
  template std::string
  inelastic_scatt_corr<double>(std::vector<double> const & axis_in,
			       std::vector<double> const & input,
			       std::vector<double> const & input_err2,
			       std::vector<double> & output,
			       std::vector<double> & output_err2,
			       void *temp);
} // PhysCorr
