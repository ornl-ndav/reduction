/**
 * $Id$
 *
 * \file axis_manip/src/rebin_axis_2D.hpp
 */
#include "rebinning.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.13 
  template <typename NumT>
  std::string 
  rebin_axis_2D(std::vector<NumT> const & axis_in_1,
		std::vector<NumT> const & axis_in_2,
		std::vector<NumT> const & input,
		std::vector<NumT> const & input_err2,
		std::vector<NumT> const & axis_out_1,
		std::vector<NumT> const & axis_out_2,
		std::vector<NumT> & output,
		std::vector<NumT> & output_err2,
		void *temp=NULL)
  {
    throw std::runtime_error("Function [rebin_axis_2D] not implemented");
  }
} // AxisManip
