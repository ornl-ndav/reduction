/**
 * $Id$
 *
 * \file axis_manip/src/rebin_axis_1D.hpp
 */
#include "rebinning.hpp"
#include "check_histo.hpp"
#include <stdexcept>
#include <string>

namespace AxisManip
{
  // 3.12 
  template <typename NumT>
  std::string 
  rebin_axis_1D(Nessi::Vector<NumT> const & axis_in,
		Nessi::Vector<NumT> const & input,
		Nessi::Vector<NumT> const & input_err2,
		Nessi::Vector<NumT> const & axis_out,
		Nessi::Vector<NumT> & output,
		Nessi::Vector<NumT> & output_err2,
		void *temp=NULL)
  {
    std::string retstr("");
    try
      {
	std::string errstr("AxisManip::rebin_axis_1D: original histogram ");
	check_histo_sizes(errstr, input, input_err2, axis_in);
      }
    catch(std::invalid_argument e)
      {
	throw e;
      }
    try
      {
	std::string errstr("AxisManip::rebin_axis_1D: rebinned histogram ");
	check_histo_sizes(errstr, output, output_err2, axis_out);
      }
    catch(std::invalid_argument e)
      {
	throw e;
      }

    size_t iold = 0;
    size_t inew = 0;

    size_t nold = input.size();
    size_t nnew = output.size();
    
    // Traverse both sets of bin edges, and if there is an overlap, add the 
    // portion of the overlapping old bin to the new bin.
    while (inew < nnew && iold < nold)
      {
	const NumT axis_in_lo = axis_in[iold];
	const NumT axis_in_hi = axis_in[iold + 1];
	const NumT axis_out_lo = axis_out[inew];
	const NumT axis_out_hi = axis_out[inew + 1];

	// FIXME These comparison statements don't make any sense for floating
	// point numbers
	if (axis_out_hi <= axis_in_lo)
	  inew++;
	else if (axis_in_hi <= axis_out_lo)
	  iold++;
	else
	  {
	    // delta is the overlap of the bins on the axis
	    const NumT delta = std::min(axis_in_hi, axis_out_hi) - 
	      std::max(axis_in_lo, axis_out_lo); 
	    const NumT width = axis_in_hi - axis_in_lo;
	    const NumT portion = delta / width;

	    output[inew] += input[iold] * portion;
	    output_err2[inew] += input_err2[iold] * portion * portion;
	    if (axis_out_hi > axis_in_hi)
	      iold++;
	    else
	      inew++;
	  }
      }

    return retstr;
  }
} // AxisManip
