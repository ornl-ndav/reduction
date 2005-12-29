/**
 * $Id: $
 *
 * \file array_manip/inc/arith.hpp
 */
#ifndef _ARITH_H
#define _ARITH_H 1

#include "nessi.hpp"
#include <string>

/**
 * This sub-library contains the various array manipulations.
 *
 * All of these functions are written in reference to SNS
 * 107030214-TD0001-R00, "Data Reduction Library Software Requirements
 * and Specifications."
 */
namespace ArrayManip
{
  /**
   * \brief This function is described in section 3.6.
   *
   * This function adds each element, \f$i\f$, of two arrays according
   * to the equation
   * \f[
   * data_o[i]=data_1[i]+data_2[i]
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * (\sigma_o[i])^2=(\sigma_1[i])^2+(\sigma_2[i])^2
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$data_1[i]\f$ is the \f$i^{th}\f$ component of the first
   * array being added, \f$data_2[i]\f$ is the \f$i^{th}\f$ component
   * of the second array being added, \f$\sigma_o[i]\f$ is the
   * \f$i^{th}\f$ component of the uncertainty of the output array,
   * \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty in the first array, and \f$\sigma_2[i]\f$ is the
   * \f$i^{th}\f$ component of the uncertainty in the second array.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param input1 (INPUT) is the first array to be added
   * \param input1_err2 (INPUT) is the square of the uncertainty in
   * the first array to be added
   * \param input2 (INPUT) is the second array to be added
   * \param input2_err2 (INPUT) the square of the uncertainty in the
   * second array to be added
   * \param output (OUTPUT) the result array
   * \param output_err2 (OUTPUT) the square of the uncertainty in the
   * result array
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    add_ncerr(Nessi::Vector<NumT> const & input1, 
              Nessi::Vector<NumT> const & input1_err2, 
              Nessi::Vector<NumT> const & input2, 
              Nessi::Vector<NumT> const & input2_err2, 
              Nessi::Vector<NumT> & output,
              Nessi::Vector<NumT> & output_err2,
              void *temp=NULL);
  
  /**
   * \brief This function is described in section 3.7.
   *
   * This function subtracts each element, \f$i\f$, two arrays
   * according to the equation
   * \f[
   * data_o[i]=data_1[i]-data_2[i]
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * (\sigma_o[i])^2=(\sigma_1[i])^2+(\sigma_2[i])^2
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$data_1[i]\f$ is the \f$i^{th}\f$ being subtracted from
   * each element, \f$data_2[i]\f$ is the \f$i^{th}\f$ component of
   * the array subtracting, \f$\sigma_o[i]\f$ is the \f$i^{th}\f$
   * component of the uncertainty of the output array,
   * \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty in the array begin subtracted from and
   * \f$\sigma_2[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty in the array subtracting.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param input1 (INPUT) is the array to be subtracted from
   * \param input1_err2 (INPUT) is the square of the uncertainty in
   * the array to be subtracted from
   * \param input2 (INPUT) is the array to subtract
   * \param input2_err2 (INPUT) the square of the uncertainty in the
   * array to subtract
   * \param output (OUTPUT) the result array
   * \param output_err2 (OUTPUT) the square of the uncertainty in the
   * result array
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    sub_ncerr(Nessi::Vector<NumT> const & input1, 
              Nessi::Vector<NumT> const & input1_err2, 
              Nessi::Vector<NumT> const & input2, 
              Nessi::Vector<NumT> const & input2_err2, 
              Nessi::Vector<NumT> & output,
              Nessi::Vector<NumT> & output_err2,
              void *temp=NULL);
  
  /**
   * \brief This function is described in section 3.8.
   *
   * This function multiplies each element, \f$i\f$, of two arrays
   * according to the equation
   * \f[
   * data_o[i]=data_1[i]\times data_2[i]
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * (\sigma_o[i])^2=(data_1[i]\times\sigma_2[i])^2
   * +(data_2[i]\times\sigma_1[i])^2
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$data_1[i]\f$ is the \f$i^{th}\f$ component of the first
   * array, \f$data_2[i]\f$ is the \f$i^{th}\f$ component of the
   * second array, \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of
   * the uncertainty of the output array, \f$\sigma_1[i]\f$ is the
   * \f$i^{th}\f$ component of the uncertainty in the first array, and
   * \f$\sigma_2[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty in the second array.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param input1 (INPUT) is the first array to be multiplied
   * \param input1_err2 (INPUT) is the square of the uncertainty in
   * the first array to be multiplied
   * \param input2 (INPUT) is the second array to be multiplied
   * \param input2_err2 (INPUT) the square of the uncertainty in the
   * second array to be multiplied
   * \param output (OUTPUT) the result array
   * \param output_err2 (OUTPUT) the square of the uncertainty in the
   * result array
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    mult_ncerr(Nessi::Vector<NumT> const & input1, 
               Nessi::Vector<NumT> const & input1_err2, 
               Nessi::Vector<NumT> const & input2, 
               Nessi::Vector<NumT> const & input2_err2, 
               Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & output_err2,
               void *temp=NULL);
  
  /**
   * \brief This function is described in section 3.9.
   *
   * This function divides each element, \f$i\f$, of two arrays
   * according to the equation
   * \f[
   * data_o[i]=data_1[i]/data_2[i]
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * (\sigma_o[i])^2=\left(\frac{data_1[i] \sigma_2[i]}{(data_2[i])^2}\right)^2
   *                 +\left(\frac{\sigma_1[i]}{data_2[i]}\right)^2
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$data_1[i]\f$ is the \f$i^{th}\f$ component of the array
   * being divided, \f$data_2[i]\f$ is the \f$i^{th}\f$ component of
   * the dividing array, \f$\sigma_o[i]\f$ is the \f$i^{th}\f$
   * component of the uncertainty of the output array,
   * \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty in the array being divided, and \f$\sigma_i[i]\f$ is
   * the \f$i^{th}\f$ component of the uncertainty in the dividing
   * array.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param input1 (INPUT) is the array to be divided from
   * \param input1_err2 (INPUT) is the square of the uncertainty in
   * the array to be divided from
   * \param input2 (INPUT) is the array to divide by
   * \param input2_err2 (INPUT) the square of the uncertainty in the
   * array to divide by
   * \param output (OUTPUT) the result array
   * \param output_err2 (OUTPUT) the square of the uncertainty in the
   * result array
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    div_ncerr(Nessi::Vector<NumT> const & input1, 
              Nessi::Vector<NumT> const & input1_err2, 
              Nessi::Vector<NumT> const & input2, 
              Nessi::Vector<NumT> const & input2_err2, 
              Nessi::Vector<NumT> & output,
              Nessi::Vector<NumT> & output_err2,
              void *temp=NULL);
  
  /**
   * \brief This function is described in section 3.10.
   *
   * This function adds two arrays weighted by their uncertainties
   * according to the equation
   * \f[
   * data_o[i]=\left( \sum_n \frac{data_n[i]}{\sigma_n[i]}\right)
   * \times\left( \sum_n \sigma_n[i] \right)
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * \sigma_o[i]=\sqrt{\sum_n (\sigma_n[i])^2}
   * \f]
   * However, if the uncertainty in any of the data is not specified,
   * or is zero, the value of the \f$data_o[i]\f$ will be given by
   * \f[
   * data_o[i]=\sum_n data_n[i]
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$data_n[i]\f$ is the \f$i^{th}\f$ component of the
   * \f$n^{th}\f$ array being added, \f$\sigma_o[i]\f$ is the
   * \f$i^{th}\f$ component of the uncertainty of the output array,
   * and \f$\sigma_n[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty in the \f$n^{th}\f$.
   *
   * \param input1 (INPUT) is the first array to be added
   * \param input1_err2 (INPUT) is the square of the uncertainty in
   * the first array to be added
   * \param input2 (INPUT) is the second array to be added
   * \param input2_err2 (INPUT) the square of the uncertainty in the
   * second array to be added
   * \param output (OUTPUT) the result array
   * \param output_err2 (OUTPUT) the square of the uncertainty in the
   * result array
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    sumw_ncerr(Nessi::Vector<NumT> const & input1, 
               Nessi::Vector<NumT> const & input1_err2, 
               Nessi::Vector<NumT> const & input2, 
               Nessi::Vector<NumT> const & input2_err2, 
               Nessi::Vector<NumT> & output,
               Nessi::Vector<NumT> & output_err2,
               void *temp=NULL);

  /**
   * \brief This function is described in section 3.1.
   *
   * This function adds a scalar to each element, \f$i\f$, of an array
   * according to the equation
   * \f[
   * data_o[i]=a+data_i[i]
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * (\sigma_o[i])^2=(\sigma_a)^2+(\sigma_i[i])^2
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$a\f$ is the scalar being added to each element,
   * \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
   * \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty of the output array, \f$\sigma_a\f$ is the
   * uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
   * \f$i^{th}\f$ component of the uncertainty in the input array.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param array_in (INPUT) is the array to be added
   * \param array_in_err2 (INPUT) is the square of the uncertainty in
   * the array to be added
   * \param array_out (OUTPUT) is the result array
   * \param array_out_err2 (OUTPUT) is the square of the uncertainty in
   * the result array
   * \param scalar (INPUT) is the scalar to add to each element of
   * array_in
   * \param scalar_err2 (INPUT) is the square of the uncertainty in the
   * scalar
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    add_ncerr(Nessi::Vector<NumT> const & array_in, 
              Nessi::Vector<NumT> const & array_in_err2, 
              NumT scalar,
              NumT scalar_err2,
              Nessi::Vector<NumT> & array_out,
              Nessi::Vector<NumT> & array_out_err2,
              void *temp=NULL);
  
  /**
   * \brief This function is described in section 3.2.
   *
   * This function subtracts a scalar from each element, \f$i\f$, of
   * an array according to the equation
   * \f[
   * data_o[i]=data_i[i]-a
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * (\sigma_o[i])^2=(\sigma_i[i])^2+(\sigma_a)^2
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$a\f$ is the scalar being subtracted from each element,
   * \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
   * \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty of the output array, \f$\sigma_a\f$ is the
   * uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
   * \f$i^{th}\f$ component of the uncertainty in the input array.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param array_in (INPUT) is the array to be subtracted from
   * \param array_in_err2 (INPUT) is the square of the uncertainty in the
   * array to be subtracted from
   * \param array_out (OUTPUT) is the result array
   * \param array_out_err2 (OUTPUT) is the square of the uncertainty in
   * the result array
   * \param scalar (INPUT) is the scalar to subtract from each element of
   * array_in
   * \param scalar_err2 (INPUT) is the square of the uncertainty in the
   * scalar
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    sub_ncerr(Nessi::Vector<NumT> const & array_in, 
              Nessi::Vector<NumT> const & array_in_err2, 
              NumT scalar,
              NumT scalar_err2,
              Nessi::Vector<NumT> & array_out,
              Nessi::Vector<NumT> & array_out_err2,
              void *temp=NULL);
  
  // NEED SOMETHING THAT DOES scalar-vector

  /**
   * \brief This function is described in section 3.3.
   *
   * This function multiplies a scalar to each element, \f$i\f$, of an
   * array according to the equation
   * \f[
   * data_o[i]=data_i[i]\times a
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * (\sigma_o[i])^2=(a\times\sigma_i[i])^2+(data_i[i]\times\sigma_a)^2
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$a\f$ is the scalar being multiplied to each element,
   * \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
   * \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty of the output array, \f$\sigma_a\f$ is the
   * uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
   * \f$i^{th}\f$ component of the uncertainty in the input array.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param array_in (INPUT) is the array to be multipled
   * \param array_in_err2 (INPUT) is the square of the uncertainty in the
   * array to be multiplied
   * \param array_out (OUTPUT) is the result array
   * \param array_out_err2 (OUTPUT) is the square of the uncertainty in
   * the result array
   * \param scalar (INPUT) is the scalar to multiply to each element
   * of array_in
   * \param scalar_err2 (INPUT) is the square of the uncertainty in the
   * scalar
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    mult_ncerr(Nessi::Vector<NumT> const & array_in, 
               Nessi::Vector<NumT> const & array_in_err2, 
               NumT scalar,
               NumT scalar_err2,
               Nessi::Vector<NumT> & array_out,
               Nessi::Vector<NumT> & array_out_err2,
               void *temp=NULL);

  /**
   * \brief This function is described in section 3.4.
   *
   * This function divides a scalar by each element, \f$i\f$, of an
   * array according to the equation
   * \f[
   * data_o[i]=a/data_i[i]
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * (\sigma_o[i])^2=\left(\frac{a \sigma_i[i]}{(data_i[i])^2}\right)^2
   *                 +\left(\frac{\sigma_a}{data_i[i]}\right)^2
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$a\f$ is the scalar each element is dividing,
   * \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
   * \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty of the output array, \f$\sigma_a\f$ is the
   * uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
   * \f$i^{th}\f$ component of the uncertainty in the input array.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param array_in (INPUT) is the array to divide from the scalar
   * \param array_in_err2 (INPUT) is the square of the uncertainty in the
   * array to divide the scalar
   * \param array_out (OUTPUT) is the result array
   * \param array_out_err2 (OUTPUT) is the square of the uncertainty in
   * the result array
   * \param scalar (INPUT) is the scalar to be divided by each element
   * of array_in
   * \param scalar_err2 (INPUT) is the square of the uncertainty in the
   * scalar
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    div_ncerr(NumT scalar,
              NumT scalar_err2,
              Nessi::Vector<NumT> const & array_in, 
              Nessi::Vector<NumT> const & array_in_err2, 
              Nessi::Vector<NumT> & array_out,
              Nessi::Vector<NumT> & array_out_err2,
              void *temp=NULL);

  /**
   * \brief This function is described in section 3.5.
   *
   * This function divides each element, \f$i\f$, of an array by a
   * scalar according to the equation
   * \f[
   * data_o[i]=data_i[i]/a
   * \f]
   * and the uncorrelated uncertainties will be processed according to
   * the equation
   * \f[
   * (\sigma_o[i])^2=\left(\frac{\sigma_i[i]}{a}\right)^2
   *                 +\left(\frac{data_i[i]\sigma_a}{a^2}\right)^2
   * \f]
   * Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
   * array, \f$a\f$ is the scalar dividing each element,
   * \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
   * \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
   * uncertainty of the output array, \f$\sigma_a\f$ is the
   * uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
   * \f$i^{th}\f$ component of the uncertainty in the input array.
   *
   * This function is an adaptation from the ARCS reduction software written
   * by Tim Kelley (CalTech).
   *
   * \param array_in (INPUT) is the array to be divided by the scalar
   * \param array_in_err2 (INPUT) is the square of the uncertainty in the
   * array to be divided by the scalar
   * \param array_out (OUTPUT) is the result array
   * \param array_out_err2 (OUTPUT) is the square of the uncertainty in
   * the result array
   * \param scalar (INPUT) is the scalar to divide each element of
   * array_in by
   * \param scalar_err2 (INPUT) is the square of the uncertainty in the
   * scalar
   *
   * \param temp holds temporary memory to be passed to the function
   *
   * \return A set of warnings generated by the function
   */
  template <typename NumT>
    std::string 
    div_ncerr(Nessi::Vector<NumT> const & array_in, 
              Nessi::Vector<NumT> const & array_in_err2, 
              NumT scalar,
              NumT scalar_err2,
              Nessi::Vector<NumT> & array_out,
              Nessi::Vector<NumT> & array_out_err2,
              void *temp=NULL);
  
  
} // ArrayManip

#endif // _ARITH_H
