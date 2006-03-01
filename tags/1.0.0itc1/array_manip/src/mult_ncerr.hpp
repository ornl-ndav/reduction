/**
 * $Id$
 *
 * \file array_manip/src/mult_ncerr.hpp
 */
#ifndef _MULT_NCERR_HPP
#define _MULT_NCERR_HPP 1

#include "arith.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace ArrayManip
{
  // 3.3
  template <typename NumT>
  std::string 
  mult_ncerr(const Nessi::Vector<NumT> & array_in, 
             const Nessi::Vector<NumT> & array_in_err2, 
             const NumT scalar,
             const NumT scalar_err2,
             Nessi::Vector<NumT> & array_out,
             Nessi::Vector<NumT> & array_out_err2,
             void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        std::string errstr("ArrayManip::mult_ncerr: data ");
        Utils::check_sizes_square(errstr,array_in,array_out);
      }
    catch (std::invalid_argument e)
      {
        throw e;
      }
    // check that the uncertainties are of proper size
    try
      {
        std::string errstr("ArrayManip::mult_ncerr: error ");
        Utils::check_sizes_square(errstr,array_in_err2,array_out_err2);
      }
    catch (std::invalid_argument e)
      {
        throw e;
      }

    std::string errstr("");

    size_t size = array_in.size();
    for (size_t i = 0; i < size; ++i)
      {
	array_out[i] = array_in[i] * scalar;
        array_out_err2[i] = ((scalar * scalar) * array_in_err2[i]) + 
	  ((array_in[i] * array_in[i]) * scalar_err2);
      }
    return errstr;
  }

  // 3.8
  template <typename NumT>
  std::string 
  mult_ncerr(const Nessi::Vector<NumT> & input1, 
             const Nessi::Vector<NumT> & input1_err2, 
             const Nessi::Vector<NumT> & input2, 
             const Nessi::Vector<NumT> & input2_err2, 
             Nessi::Vector<NumT> & output,
             Nessi::Vector<NumT> & output_err2,
             void *temp=NULL)
  {
    std::string retstr("");

    try 
      {
	std::string errstr("ArrayManip::mult_vec_vec_ncerr: data ");
	Utils::check_sizes_square(errstr, input1, input2, output);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    try 
      {
	std::string errstr("ArrayManip::mult_vec_vec_ncerr: error ");
	Utils::check_sizes_square(errstr, input1_err2, input2_err2, 
				  output_err2);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    std::transform(input1.begin(), input1.end(), input2.begin(), 
                   output.begin(), std::multiplies<NumT>());

    size_t sz = input1.size();
    for (size_t i = 0; i < sz; ++i)
      {
	output_err2[i] = (input2[i] * input2[i] * input1_err2[i]) + 
	  (input1[i] * input1[i] * input2_err2[i]);
      }

    return retstr;
  }
} // ArrayManip

#endif // _MULT_NCERR_HPP