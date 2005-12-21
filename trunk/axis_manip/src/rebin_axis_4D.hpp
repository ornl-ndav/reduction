/**
 *  $Id$
 *
 * \file axis_manip/src/rebin_axis_4D.hpp
 */
#include "rebinning.hpp"
#include <string>
#include <stdexcept>

namespace AxisManip
{
  // 3.14
  template <typename NumT>
  std::string 
  rebin_axis_4D(Nessi::Vector<NumT> const & axis_in_1,
		Nessi::Vector<NumT> const & axis_in_2,
		Nessi::Vector<NumT> const & axis_in_3,
		Nessi::Vector<NumT> const & axis_in_4,
		Nessi::Vector<NumT> const & input,
		Nessi::Vector<NumT> const & input_err2,
		Nessi::Vector<NumT> const & axis_out_1,
		Nessi::Vector<NumT> const & axis_out_2,
		Nessi::Vector<NumT> const & axis_out_3,
		Nessi::Vector<NumT> const & axis_out_4,
		Nessi::Vector<NumT> & output,
		Nessi::Vector<NumT> & output_err2,
		void *temp=NULL)
  {
    throw std::runtime_error("Function [rebin_axis_4D] not implemented");
  }
} // AxisManip
