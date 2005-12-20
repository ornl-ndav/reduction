/**
 * $Id$
 *
 * \file array_manip/src/add_vec_vec_ncerr.hpp
 */
#ifndef _ADD_VEC_VEC_NCERR_H
#define _ADD_VEC_VEC_NCERR_H 1

#include "vec_vec_arith.hpp"
#include "check_inputs.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>
//#include <vector>

namespace ArrayManip
{
  // 3.6
  template <typename NumT>
  std::string 
  add_vec_vec_ncerr(Nessi::Vector<NumT> const & input1, 
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
	std::string errstr("ArrayManip::add_vec_vec_ncerr: data ");
	check_sizes_2in1out(errstr, input1, input2, output);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    try 
      {
	std::string errstr("ArrayManip::add_vec_vec_ncerr: error ");
	check_sizes_2in1out(errstr, input1_err2, input2_err2, output_err2);
      }
    catch (std::invalid_argument e)
      {
	throw e;
      }

    std::transform(input1.begin(), input1.end(), input2.begin(), 
		   output.begin(), std::plus<NumT>());
    std::transform(input1_err2.begin(), input1_err2.end(), 
		   input2_err2.begin(), output_err2.begin(), 
		   std::plus<NumT>());

    return retstr;
  }
} // ArrayManip

#endif // _ADD_VEC_VEC_NCERR_H
