/**
 * $Id$
 *
 * \file utils/src/peak_integration.cpp
 */
#include "peak_integration.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.35.
   *
   * \see peak_integration()
   */
  template std::string
  peak_integration<float>(Nessi::Vector<float> const & input,
			  Nessi::Vector<float> const & input_err2,
			  Nessi::Vector<float> const & start_bin,
			  float & output,
			  float & output_err2,
                          unsigned int & tag,
			  float & num_bins,
			  void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.35.
   *
   * \see peak_integration()
   */
  template std::string
  peak_integration<double>(Nessi::Vector<double> const & input,
			   Nessi::Vector<double> const & input_err2,
			   Nessi::Vector<double> const & start_bin,
			   double & output,
			   double & output_err2,
                           unsigned int & tag,
			   double & num_bins,
			   void *temp);

} // Utils
