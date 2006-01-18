/**
 * $Id$
 *
 * \file phys_corr/src/dead_time_corr.hpp
 */
#ifndef _DEAD_TIME_CORR_HPP
#define _DEAD_TIME_CORR_HPP 1

#include "physcorr.hpp"
#include <stdexcept>

namespace PhysCorr
{
  // 3.38
  template <typename NumT>
  std::string
  dead_time_corr(const Nessi::Vector<NumT> & axis_in,
                 const Nessi::Vector<NumT> & input,
                 const Nessi::Vector<NumT> & input_err2,
                 NumT corr_factor,
                 Nessi::Vector<NumT> & output,
                 Nessi::Vector<NumT> & output_err2,
                 void *temp=NULL)
  {
    throw std::runtime_error("Function [dead_time_corr] not implemented");
  }
} // PhysCorr

#endif // _DEAD_TIME_CORR_HPP
