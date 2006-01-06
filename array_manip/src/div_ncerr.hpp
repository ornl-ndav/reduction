/**
 * $Id$
 *
 * \file array_manip/src/div_ncerr.hpp
 */
#ifndef _DIV_NCERR_HPP
#define _DIV_NCERR_HPP 1

#include "arith.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace ArrayManip
{
  // 3.4
  template <typename NumT>
  std::string 
  div_ncerr(const NumT scalar,
            const NumT scalar_err2,
            const Nessi::Vector<NumT> & array_in, 
            const Nessi::Vector<NumT> & array_in_err2, 
            Nessi::Vector<NumT> & array_out,
            Nessi::Vector<NumT> & array_out_err2,
            void *temp=NULL)
  {
    std::string errstr("");
    
    size_t size = array_in.size();
    for (size_t i = 0; i < size; ++i)
      {
    	array_out[i] = scalar / array_in[i];
	NumT array_in2 = array_in[i] * array_in[i];
        array_out_err2[i] = 
          (((scalar * scalar) / (array_in2 * array_in2)) * array_in_err2[i])
          + (scalar_err2 / array_in2);
      }
    return errstr;
  }

  // 3.5
  template <typename NumT>
  std::string 
  div_ncerr(const Nessi::Vector<NumT> & array_in, 
            const Nessi::Vector<NumT> & array_in_err2, 
            const NumT scalar,
            const NumT scalar_err2,
            Nessi::Vector<NumT> & array_out,
            Nessi::Vector<NumT> & array_out_err2,
            void *temp=NULL)
  {
    std::string errstr("");

    size_t size = array_in.size();
    for (size_t i = 0; i < size; ++i)
      {
    	array_out[i] = array_in[i] / scalar;
	NumT scalar2 = scalar * scalar;
        array_out_err2[i] = (array_in_err2[i] / scalar2)
          + (((array_in[i] * array_in[i])/ (scalar2 * scalar2)) * scalar_err2);
      }
    return errstr;
  }  

  // 3.9
  template <typename NumT>
  std::string 
  div_ncerr(const Nessi::Vector<NumT> & input1, 
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
	std::string errstr("ArrayManip::div_vec_vec_ncerr: data ");
	Utils::check_sizes_square(errstr, input1, input2, output);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    try 
      {
	std::string errstr("ArrayManip::div_vec_vec_ncerr: error ");
	Utils::check_sizes_square(errstr, input1_err2, input2_err2, 
				  output_err2);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    std::transform(input1.begin(), input1.end(), input2.begin(), 
                   output.begin(), std::divides<NumT>());

    size_t sz = input1.size();
    for (size_t i = 0; i < sz; ++i)
      {
	NumT input2_2 = input2[i] * input2[i];
	output_err2[i] = (input1_err2[i] / input2_2) + 
	  (((input1[i] * input1[i]) / (input2_2 * input2_2)) * input2_err2[i]);
      }

    return retstr;
  }
} // ArrayManip

#endif // _DIV_VEC_VEC_NCERR_HPP
