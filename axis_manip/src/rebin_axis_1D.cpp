/**
 * $Id$
 *
 * \file axis_manip/src/rebin_axis_1D.cpp
 */
#include "rebinning.hpp"
#include "check_histo.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.12 
  template <typename NumT>
  std::string 
  rebin_axis_1D(std::vector<NumT> const & axis_in,
		std::vector<NumT> const & input,
		std::vector<NumT> const & input_err2,
		std::vector<NumT> const & axis_out,
		std::vector<NumT> & output,
		std::vector<NumT> & output_err2,
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

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.12.
   *
   * \see rebin_axis_1D()
   */
  template std::string 
  rebin_axis_1D<float>(std::vector<float> const & axis_in,
		       std::vector<float> const & input,
		       std::vector<float> const & input_err2,
		       std::vector<float> const & axis_out,
		       std::vector<float> & output,
		       std::vector<float> & output_err2,
		       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.12.
   *
   * \see rebin_axis_1D()
   */
  template std::string 
  rebin_axis_1D<double>(std::vector<double> const & axis_in,
			std::vector<double> const & input,
			std::vector<double> const & input_err2,
			std::vector<double> const & axis_out,
			std::vector<double> & output,
			std::vector<double> & output_err2,
			void *temp);

  /**
   * This is the integer declaration of the function defined in 3.12.
   *
   * \see rebin_axis_1D()
   */
  template std::string 
  rebin_axis_1D<int>(std::vector<int> const & axis_in,
		     std::vector<int> const & input,
		     std::vector<int> const & input_err2,
		     std::vector<int> const & axis_out,
		     std::vector<int> & output,
		     std::vector<int> & output_err2,
		     void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.12.
   *
   * \see rebin_axis_1D()
   */
  template std::string 
  rebin_axis_1D<unsigned int>(std::vector<unsigned int> const & axis_in,
                              std::vector<unsigned int> const & input,
                              std::vector<unsigned int> const & input_err2,
                              std::vector<unsigned int> const & axis_out,
                              std::vector<unsigned int> & output,
                              std::vector<unsigned int> & output_err2,
                              void *temp);
  

} // AxisManip
