/**
 * $Id$
 *
 * \file phys_corr/src/incoherent_scatt_corr.cpp
 */
#include "incoherent_scatt_corr.hpp"

namespace PhysCorr
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.41.
   *
   * \see incoherent_scatt_corr()
   */
  template std::string
  incoherent_scatt_corr<float>(Nessi::Vector<float> const & axis_in,
			       Nessi::Vector<float> const & input,
			       Nessi::Vector<float> const & input_err2,
			       Nessi::Vector<float> & output,
			       Nessi::Vector<float> & output_err2,
			       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.41.
   *
   * \see incoherent_scatt_corr()
   */
  template std::string
  incoherent_scatt_corr<double>(Nessi::Vector<double> const & axis_in,
				Nessi::Vector<double> const & input,
				Nessi::Vector<double> const & input_err2,
				Nessi::Vector<double> & output,
				Nessi::Vector<double> & output_err2,
				void *temp);
} // PhysCorr
