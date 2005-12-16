/**
 * $Id$
 *
 * \file array_manip/src/sub_scalar_vec_ncerr.hpp
 */
#ifndef _SUB_SCALAR_VEC_NCERR_H
#define _SUB_SCALAR_VEC_NCERR_H 1

#include "vec_scalar_arith.hpp"
#include <string>
#include <vector>

namespace ArrayManip
{
  // 3.2
  template <typename NumT>
  std::string 
  sub_scalar_vec_ncerr(std::vector<NumT> const & array_in, 
		       std::vector<NumT> const & array_in_err2, 
		       std::vector<NumT> & array_out,
		       std::vector<NumT> & array_out_err2,
		       NumT scalar, NumT scalar_err2,
		       void *temp=NULL)
  {
    std::string errstr("");

    size_t size = array_in.size();
    for (size_t i = 0; i < size; ++i)
      {
	array_out[i] = array_in[i] - scalar;
        array_out_err2[i] = array_in_err2[i] + scalar_err2;
      }
    return errstr;
  }
} // ArrayManip 

#endif // _SUB_SCALAR_VEC_NCERR_H
