/**
 * $Id$
 *
 * \file utils/inc/utils.hpp
 */
#ifndef _UTILS_HPP
#define _UTILS_HPP 1

#include "nessi.hpp"
#include <string>

/**
 * \namespace Utils
 *
 * \brief This sub-library contains various functions that do not
 * specifically reside in any of the other sub-libraries.
 *
 * All of these functions are written in reference to SNS
 * 107030214-TD0001-R00, "Data Reduction Library Software Requirements
 * and Specifications."
 */
namespace Utils
{
  /**
   * \defgroup peak_integration Utils::peak_integration
   * \{
   */

  /**
   * \brief This function is described in section 3.35.
   *
   * Starting with the \f$x_0\f$ bin, sum the values of the function and
   * associated uncertainty from adjecent bins using a box-type
   * method, an amoeba method (nearest neighbors), or other summation
   * method. Calculate the signal-to-noise ration via
   * \f[
   * \frac{\sum_i^{bins} F(x)}{\sum_i^{bins} \sigma_F(x)}
   * \f]
   * and continue summation from adjacent bins until a maximum in the
   * ratio is found. Determine quality of peak finding procedure and
   * return the outputs listed below.
   *
   * \param input (INPUT) is the function, \f$f(x)\f$, to be
   * integrated
   * \param input_err2 (INPUT) is the square of the uncertainty in the
   * function to be integrated
   * \param start_bin (INPUT) is the starting bin, \f$x_0\f$, to
   * integrate the function around
   * \param output (OUTPUT) is the value of the integrated function
   * \param output_err2 (OUTPUT) is the square of the uncertainty of
   * the integral
   * \param tag (OUTPUT) is a flag providing information on the
   * quality of the peak
   * \param num_bins (OUTPUT) is the number of histogram bins used in
   * the integration
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    peak_integration(const Nessi::Vector<NumT> & input,
		     const Nessi::Vector<NumT> & input_err2,
		     const Nessi::Vector<NumT> & start_bin,
		     NumT & output,
		     NumT & output_err2,
		     unsigned int & tag,
		     NumT & num_bins,
		     void *temp=NULL);
 
  /**
   * \}
   */ // end of peak_integration group

  /**
   * \defgroup matrix_multiplication Utils::matrix_multiplication
   * \{
   */

  /**
   * \brief This function is described in section 3.37.
   *
   * THIS FUNCTION NEEDS TO BE DOCUMENTED
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    matrix_multiplication(const Nessi::Vector<NumT> & input,
			  const Nessi::Vector<NumT> & input_err2,
			  Nessi::Vector<NumT> & output,
			  Nessi::Vector<NumT> & output_err2,
			  void *temp=NULL);
  
  /**
   * \}
   */ // end of matrix_multiplication group

  /** 
   * \defgroup fit_reflectometer_background Utils::fit_reflectometer_background
   * \{
   */

  /**
   * \brief This function is described in section 3.42.
   *
   * THIS FUNCTION NEEDS TO BE DOCUMENTED
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    fit_reflectometer_background(const Nessi::Vector<NumT> & axis_in,
				 const Nessi::Vector<NumT> & input,
				 const Nessi::Vector<NumT> & input_err2,
				 const Nessi::Vector<NumT> & params_in,
				 Nessi::Vector<NumT> & output,
				 Nessi::Vector<NumT> & output_err2,
				 Nessi::Vector<NumT> & params_out,
				 Nessi::Vector<NumT> & params_out_err2,
				 void *temp=NULL);

  /**
   * \}
   */ // end of fit_reflectometer_background group

  /**
   * \defgroup fit_linear_background Utils::fit_linear_background
   * \{
   */

  /**
   * \brief This function is described in section 3.43.
   *
   * THIS FUNCTION NEEDS TO BE DOCUMENTED
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string
    fit_linear_background(const Nessi::Vector<NumT> & axis_in,
			  const Nessi::Vector<NumT> & input,
			  const Nessi::Vector<NumT> & input_err2,
			  NumT min_val,
                          NumT max_val,
			  NumT slope_start, 
			  NumT intercept_start,
			  NumT & slope_out,
                          NumT & slope_out_err2,
			  NumT & intercept_out,
			  NumT & intercept_out_err2,
			  void *temp=NULL);

  /**
   * \}
   */ // end of fit_linear_background group

} // Utils

#endif // _UTILS_HPP
