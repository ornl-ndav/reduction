/**
 * $Id$
 *
 * \file axis_manip/inc/rebinning.hpp
 */
#ifndef _REBINNING_H
#define _REBINNING_H 1

#include <string>
#include <vector>

namespace AxisManip
{
  /**
   * \brief This function is described in section 3.12.
   */
  template <typename NumT>
    std::string 
    rebin_axis_1D(std::vector<NumT> const & axis_in,
		  std::vector<NumT> const & input,
		  std::vector<NumT> const & input_err,
		  std::vector<NumT> const & axis_out,
		  std::vector<NumT> & output,
		  std::vector<NumT> & output_err,
		  void *temp=NULL);
  
  /**
   * \brief This function is described in section 3.13.
   */
  template <typename NumT>
    std::string 
    rebin_axis_2D(std::vector<NumT> const & axis_in_1,
		  std::vector<NumT> const & axis_in_2,
		  std::vector<NumT> const & input,
		  std::vector<NumT> const & input_err,
		  std::vector<NumT> const & axis_out_1,
		  std::vector<NumT> const & axis_out_2,
		  std::vector<NumT> & output,
		  std::vector<NumT> & output_err,
		  void *temp=NULL);

  /**
   * \brief This function is described in section 3.14.
   */
  template <typename NumT>
    std::string 
    rebin_axis_4D(std::vector<NumT> const & axis_in_1,
		  std::vector<NumT> const & axis_in_2,
		  std::vector<NumT> const & axis_in_3,
		  std::vector<NumT> const & axis_in_4,
		  std::vector<NumT> const & input,
		  std::vector<NumT> const & input_err,
		  std::vector<NumT> const & axis_out_1,
		  std::vector<NumT> const & axis_out_2,
		  std::vector<NumT> const & axis_out_3,
		  std::vector<NumT> const & axis_out_4,
		  std::vector<NumT> & output,
		  std::vector<NumT> & output_err,
		  void *temp=NULL);
  
} // AxisManip

#endif // _REBINNING_H
