/**
 * $Id$
 *
 * \file array_manip/src/div_vec_vec_ncerr.hpp
 */
#ifndef _DIV_VEC_VEC_NCERR_H
#define _DIV_VEC_VEC_NCERR_H 1

#include "vec_vec_arith.hpp"
#include "check_inputs.hpp"
#include <stdexcept>
#include <string>

namespace ArrayManip
{
  // 3.9
  template <typename NumT>
  std::string 
  div_vec_vec_ncerr(Nessi::Vector<NumT> const & input1, 
		    Nessi::Vector<NumT> const & input1_err2, 
		    Nessi::Vector<NumT> const & input2, 
		    Nessi::Vector<NumT> const & input2_err2, 
		    Nessi::Vector<NumT> & output,
		    Nessi::Vector<NumT> & output_err2,
		    void *temp=NULL)
  {
    std::string retstr("");

    try 
      {
	std::string errstr("ArrayManip::div_vec_vec_ncerr: data ");
	check_sizes_2in1out(errstr, input1, input2, output);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    try 
      {
	std::string errstr("ArrayManip::div_vec_vec_ncerr: error ");
	check_sizes_2in1out(errstr, input1_err2, input2_err2, output_err2);
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

#endif // _DIV_VEC_VEC_NCERR_H
