/**
 *  $Id$
 *
 * \file axis_manip/src/rebin_axis_4D.hpp
 */
#include "rebinning.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.14
  template <typename NumT>
  std::string 
  rebin_axis_4D(std::vector<NumT> const & axis_in_1,
		std::vector<NumT> const & axis_in_2,
		std::vector<NumT> const & axis_in_3,
		std::vector<NumT> const & axis_in_4,
		std::vector<NumT> const & input,
		std::vector<NumT> const & input_err2,
		std::vector<NumT> const & axis_out_1,
		std::vector<NumT> const & axis_out_2,
		std::vector<NumT> const & axis_out_3,
		std::vector<NumT> const & axis_out_4,
		std::vector<NumT> & output,
		std::vector<NumT> & output_err2,
		void *temp=NULL)
  {
    throw std::runtime_error("Function [rebin_axis_4D] not implemented");
  }
} // AxisManip
