/**
 * $Id$
 *
 * \file phys_corr/src/dead_time_corr.hpp
 */
#ifndef _DEAD_TIME_CORR_H
#define _DEAD_TIME_CORR_H 1

#include "physcorr.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace PhysCorr
{
  // 3.36
  template <typename NumT>
  std::string
  dead_time_corr(std::vector<NumT> const & axis_in,
		 std::vector<NumT> const & input,
		 std::vector<NumT> const & input_err2,
		 NumT corr_factor,
		 std::vector<NumT> & output,
		 std::vector<NumT> & output_err2,
		 void *temp=NULL)
  {
    throw std::runtime_error("Function [dead_time_corr] not implemented");
  }
} // PhysCorr

#endif // _DEAD_TIME_CORR_H
