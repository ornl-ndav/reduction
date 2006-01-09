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
   * \ingroup peak_integration
   */
  template std::string
  peak_integration<float>(const Nessi::Vector<float> & input,
			  const Nessi::Vector<float> & input_err2,
			  const Nessi::Vector<float> & start_bin,
			  float & output,
			  float & output_err2,
                          unsigned int & tag,
			  float & num_bins,
			  void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.35.
   *
   * \ingroup peak_integration
   */
  template std::string
  peak_integration<double>(const Nessi::Vector<double> & input,
			   const Nessi::Vector<double> & input_err2,
			   const Nessi::Vector<double> & start_bin,
			   double & output,
			   double & output_err2,
                           unsigned int & tag,
			   double & num_bins,
			   void *temp);

} // Utils
