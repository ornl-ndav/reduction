/**
 * $Id$
 *
 * \file array_manip/src/div_scalar_vec_ncerr.hpp
 */
#ifndef _DIV_SCALAR_VEC_NCERR_H
#define _DIV_SCALAR_VEC_NCERR_H 1

#include "vec_scalar_arith.hpp"

namespace ArrayManip
{
  // 3.4
  template <typename NumT>
  std::string 
  div_scalar_vec_ncerr(Nessi::Vector<NumT> const & array_in, 
		       Nessi::Vector<NumT> const & array_in_err2, 
		       Nessi::Vector<NumT> & array_out,
		       Nessi::Vector<NumT> & array_out_err2,
		       NumT scalar, NumT scalar_err2,
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
} // ArrayManip 

#endif // _DIV_SCALAR_VEC_NCERR_H
