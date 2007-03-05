/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 *
 * For this software and its associated documentation, permission is granted
 * to reproduce, prepare derivative works, and distribute copies to the public
 * for any purpose and without fee.
 *
 * This material was prepared as an account of work sponsored by an agency of
 * the United States Government.  Neither the United States Government nor the
 * United States Department of Energy, nor any of their employees, makes any
 * warranty, express or implied, or assumes any legal liability or
 * responsibility for the accuracy, completeness, or usefulness of any
 * information, apparatus, product, or process disclosed, or represents that
 * its use would not infringe privately owned rights.
 *
 */

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
   * \defgroup linear_order_jacobian Utils::linear_order_jacobian
   * \{
   */

  /**
   * \brief This function is documented in section 3.49
   *
   * This function corrects the input based on the ratio of differences 
   * between bin boundaries from the associated orignal and transformed axes.
   * This correction only applies to histogram data. The incoming axes and 
   * counts arrays should be in their original form (no reversing), otherwise 
   * the calculation of the Jacobians will be done incorrectly. The 
   * calculation of the linear order Jacobian is accomplished by:
   *
   * \f[
   * I'[k] = I[k] \times \left|\frac{x[k+1] - x[k]}{x'[k+1] - x'[k]}\right|
   * \f]
   *
   * where \f$I'[k]\f$ is the \f$k^{th}\f$ element of the corrected counts, 
   * \f$I[k]\f$ is the \f$k^{th}\f$ element of the counts associated with a 
   * particular histogram bin \f$k\f$, \f$x[k+1]\f$ is the high bin boundary 
   * and \f$x[k]\f$ is the low bin boundary from the original axis and 
   * \f$x'[k+1]\f$ is the high bin boundary and \f$x'[k]\f$ is the low bin 
   * boundary from the transformed axis. 
   *
   * The square of the uncertainty is calculated via:
   * 
   * \f[
   * \sigma^2_{I'}[k] = \sigma^2_I[k] \times \left(\frac{x[k+1] - x[k]}
   * {x'[k+1] - x'[k]}\right)^2
   * \f]
   *
   * where \f$\sigma^2_{I'}[k]\f$ is the \f$k^{th}\f$ element of the square of 
   * the uncertainty of the corrected counts, \f$\sigma^2_I[k]\f$ is the 
   * \f$k^{th}\f$ element of the square of the uncertainty in the counts 
   * associated with a particular histogram bin \f$k\f$, \f$x[k+1]\f$ is the 
   * high bin boundary and \f$x[k]\f$ is the low bin boundary from the 
   * original axis and \f$x'[k+1]\f$ is the high bin boundary and \f$x'[k]\f$ 
   * is the low bin boundary from the transformed axis.
   *
   * \param orig_axis (INPUT) is the original histogram axis associated with 
   * the data
   * \param transform_axis (INPUT) is the transformed histogram axis 
   * associated with the data
   * \param input (INPUT) is the counts data
   * \param input_err2 (INPUT) is the square of the uncertainty in the counts 
   * data
   * \param output (OUTPUT) is the corrected counts array
   * \param output_err2 (OUTPUT) is the corrected square of the uncertainty 
   * in the counts array
   * \param temp holds temporary memory to be passed to the funtion
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string 
  linear_order_jacobian(const Nessi::Vector<NumT> & orig_axis,
                        const Nessi::Vector<NumT> & transform_axis,
                        const Nessi::Vector<NumT> & input,
                        const Nessi::Vector<NumT> & input_err2,
                        Nessi::Vector<NumT> & output,
                        Nessi::Vector<NumT> & output_err2,
                        void *temp=NULL);

  /**
   * \brief This function is documented in section 3.49
   *
   * This  function corrects the input based on the ratio of differences 
   * between bin boundaries from the associated orignal and transformed axes.
   * This correction only applies to histogram data. The bin boundaries should 
   * be in their original order (no reversing) with respect to the counts, 
   * otherwise the calculation of the Jacobian will be incorrect. The 
   * calculation of the linear order Jacobian is accomplished by:
   *
   * \f[
   * I' = I \times \left|\frac{x_{hi} - x_{lo}}{x'_{hi} - x'_{lo}}\right|
   * \f]
   *
   * where \f$I'\f$ is the corrected counts, \f$I\f$ is the counts associated 
   * with a particular histogram bin, \f$x_{hi}\f$ is the high bin boundary 
   * and \f$x_{lo}\f$ is the low bin boundary from the original axis and 
   * \f$x'_{hi}\f$ is the high bin boundary and \f$x'_{lo}\f$ is the low bin 
   * boundary from the transformed axis.
   *
   * The square of the uncertainty is calculated via:
   * 
   * \f[
   * \sigma^2_{I'} = \sigma^2_I \times \left(\frac{x_{hi} - x_{lo}}
   * {x'_{hi} - x'_{lo}}\right)^2
   * \f]
   *
   * where \f$\sigma^2_{I'}\f$ is the square of the uncertainty of the 
   * corrected counts, \f$\sigma^2_I\f$ is the square of the uncertainty in 
   * the counts associated with a particular histogram bin, \f$x_{hi}\f$ is 
   * the high bin boundary and \f$x_{lo}\f$ is the low bin boundary from the 
   * original axis and \f$x'_{hi}\f$ is the high bin boundary and 
   * \f$x'_{lo}\f$ is the low bin boundary from the transformed axis.
   *
   * \param orig_axis_lo (INPUT) is the low bin boundary of the original 
   * histogram axis associated with the data
   * \param orig_axis_hi (INPUT) is the high bin boundary of the original 
   * histogram axis associated with the data
   * \param transform_axis_lo (INPUT) is the low bin boundary of the 
   * transformed histogram axis associated with the data
   * \param transform_axis_hi (INPUT) is the high bin boundary of the 
   * transformed histogram axis associated with the data
   * \param input (INPUT) is the counts data
   * \param input_err2 (INPUT) is the square of the uncertainty in the counts 
   * data
   * \param output (OUTPUT) is the corrected counts array
   * \param output_err2 (OUTPUT) is the corrected square of the uncertainty 
   * in the counts array
   * \param temp holds temporary memory to be passed to the funtion
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
  std::string 
  linear_order_jacobian(const NumT & orig_axis_lo,
                        const NumT & orig_axis_hi,
                        const NumT & transform_axis_lo,
                        const NumT & transform_axis_hi,
                        const NumT & input,
                        const NumT & input_err2,
                        NumT & output,
                        NumT & output_err2,
                        void *temp=NULL);

  /**
   * \}
   */ // end of linear_order_jacobian group

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
   * \defgroup weighted_average Utils::weighted_average
   * \{
   */

  /**
   * \brief This function is described in section 3.46
   *
   * This function takes a slice of an array and calculates the weighted
   * average of that slice. The weighted average is calculated according to
   * the function
   *
   * \f[
   * \mu = \frac{\sum^{bin_{end}}_{i=bin_{start}} \frac{x_i}{\sigma_i^2}}
   * {\sum^{bin_{end}}_{i=bin_{start}} \frac{1}{\sigma_i^2}}
   * \f]
   *
   *  where \f$x_i\f$ is the \f$i^{th}\f$ element in the input array,
   * \f$\sigma_i^2\f$ is the square of the uncertainty associated with the
   * input array, \f$bin_{start}\f$ is the starting bin of the array from
   * which to calculate the weighted average, \f$bin_{end}\f$ is the ending
   * bin of the array where to stop the calculation, and \f$\mu\f$ is the
   * weighted average.
   *
   * The square of the uncertainty is calculated according to the following
   * function
   *
   * \f[
   * \sigma_{\mu}^2 = \frac{1}{\sum^{bin_{end}}_{i=bin_{start}} \frac{1}
   * {\sigma_i^2}}
   * \f]
   *
   *  where the other symbols are exactly as those mentioned above and
   * \f$\sigma_{\mu}^2\f$ is the square of the uncertainty in the weighted
   * average.
   *
   * \param input (INPUT) the array from which to calculate the weighted
   * average
   * \param input_err2 (INPUT) the square of the uncertainty in the associated
   * array from which calculate the weighted average
   * \param bin_start (INPUT) the bin of the array from which to start the
   * calculation
   * \param bin_end (INPUT) the bin of the array at which to end the
   * calculation
   * \param weighted_ave (OUTPUT) the weighted average of the array slice
   * \param weighted_ave_err2 (OUTPUT) the square of the uncertainty of the
   * weighted average of the array slice
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   *
   * \exception std::invalid_argument is thrown if the size of input is
   * not identical to the size of input_err2.
   */
  template <typename NumT>
  std::string
  weighted_average(const Nessi::Vector<NumT> & input,
                   const Nessi::Vector<NumT> & input_err2,
                   const std::size_t bin_start,
                   const std::size_t bin_end,
                   NumT & weighted_ave,
                   NumT & weighted_ave_err2,
                   void *temp=NULL);

  /**
   * \}
   */ // end of weighted_average group

} // Utils

#endif // _UTILS_HPP
