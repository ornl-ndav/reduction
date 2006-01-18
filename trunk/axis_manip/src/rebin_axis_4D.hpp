/**
 *  $Id$
 *
 * \file axis_manip/src/rebin_axis_4D.hpp
 */
#ifndef _REBIN_AXIS_4D_HPP
#define _REBIN_AXIS_4D_HPP 1

#include "rebinning.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.14
  template <typename NumT>
  std::string
  rebin_axis_4D(const Nessi::Vector<NumT> & axis_in_1,
                const Nessi::Vector<NumT> & axis_in_2,
                const Nessi::Vector<NumT> & axis_in_3,
                const Nessi::Vector<NumT> & axis_in_4,
                const Nessi::Vector<NumT> & input,
                const Nessi::Vector<NumT> & input_err2,
                const Nessi::Vector<NumT> & axis_out_1,
                const Nessi::Vector<NumT> & axis_out_2,
                const Nessi::Vector<NumT> & axis_out_3,
                const Nessi::Vector<NumT> & axis_out_4,
                Nessi::Vector<NumT> & output,
                Nessi::Vector<NumT> & output_err2,
                void *temp=NULL)
  {
    throw std::runtime_error("Function [rebin_axis_4D] not implemented");
  }
} // AxisManip

#endif // _REBIN_AXIS_4D_HPP
