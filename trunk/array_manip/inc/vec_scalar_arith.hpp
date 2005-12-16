/**
 * $Id$
 *
 * \file array_manip/inc/vec_scalar_arith.hpp
 */
#ifndef _VEC_SCALAR_ARITH_H
#define _VEC_SCALAR_ARITH_H 1

#include <string>
#include <vector>

namespace ArrayManip
{
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
    add_scalar_vec_ncerr(std::vector<NumT> const & array_in, 
			 std::vector<NumT> const & array_in_err2, 
			 std::vector<NumT> & array_out,
			 std::vector<NumT> & array_out_err2,
			 NumT scalar, NumT scalar_err2,
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
    sub_scalar_vec_ncerr(std::vector<NumT> const & array_in, 
			 std::vector<NumT> const & array_in_err2, 
			 std::vector<NumT> & array_out,
			 std::vector<NumT> & array_out_err2,
			 NumT scalar, NumT scalar_err2,
			 void *temp=NULL);
  
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
    mult_scalar_vec_ncerr(std::vector<NumT> const & array_in, 
			  std::vector<NumT> const & array_in_err2, 
			  std::vector<NumT> & array_out,
			  std::vector<NumT> & array_out_err2,
			  NumT scalar, NumT scalar_err2,
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
    div_scalar_vec_ncerr(std::vector<NumT> const & array_in, 
			 std::vector<NumT> const & array_in_err2, 
			 std::vector<NumT> & array_out,
			 std::vector<NumT> & array_out_err2,
			 NumT scalar, NumT scalar_err2,
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
    div_vec_scalar_ncerr(std::vector<NumT> const & array_in, 
			 std::vector<NumT> const & array_in_err2, 
			 std::vector<NumT> & array_out,
			 std::vector<NumT> & array_out_err2,
			 NumT scalar, NumT scalar_err2,
			 void *temp=NULL);
  
  
} // ArrayManip

#endif // _VEC_SCALAR_ARITH_H 
