/**
 * $Id$
 *
 * \file array_manip/src/div_vec_scalar_ncerr.hpp
 */
#ifndef _DIV_VEC_SCALAR_NCERR_H
#define _DIV_VEC_SCALAR_NCERR_H 1

#include "vec_scalar_arith.hpp"

namespace ArrayManip
{
  // 3.5
  template <typename NumT>
  std::string 
  div_vec_scalar_ncerr(Nessi::Vector<NumT> const & array_in, 
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
    	array_out[i] = array_in[i] / scalar;
	NumT scalar2 = scalar * scalar;
        array_out_err2[i] = (array_in_err2[i] / scalar2)
          + (((array_in[i] * array_in[i])/ (scalar2 * scalar2)) * scalar_err2);
      }
    return errstr;
  }  
} // ArrayManip 

#endif // _DIV_VEC_SCALAR_NCERR_H
