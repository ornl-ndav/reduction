/**
 * $Id: $
 *
 * \file array_manip/src/add_ncerr.hpp
 */
#ifndef _ADD_NCERR_H
#define _ADD_NCERR_H 1

#include "arith.hpp"
#include "check_inputs.hpp"
#include <algorithm>
#include <stdexcept>

namespace ArrayManip
{
  // 3.1
  template <typename NumT>
  std::string 
  add_ncerr(Nessi::Vector<NumT> const & array_in, 
            Nessi::Vector<NumT> const & array_in_err2, 
            NumT scalar,
            NumT scalar_err2,
            Nessi::Vector<NumT> & array_out,
            Nessi::Vector<NumT> & array_out_err2,
            void *temp=NULL)
  {
    std::string errstr("");

    size_t size = array_in.size();
    for (size_t i = 0; i < size; ++i)
      {
	array_out[i] = array_in[i] + scalar;
	array_out_err2[i] = array_in_err2[i] + scalar_err2;
      }
    return errstr;
  }  

  // 3.6
  template <typename NumT>
  std::string 
  add_ncerr(Nessi::Vector<NumT> const & input1, 
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

#endif // _ADD_NCERR_H
