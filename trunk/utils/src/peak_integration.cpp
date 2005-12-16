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
  peak_integration<float>(std::vector<float> const & input,
			  std::vector<float> const & input_err2,
			  std::vector<float> const & start_bin,
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
  peak_integration<double>(std::vector<double> const & input,
			   std::vector<double> const & input_err2,
			   std::vector<double> const & start_bin,
			   double & output,
			   double & output_err2,
                           unsigned int & tag,
			   double & num_bins,
			   void *temp);

} // Utils
