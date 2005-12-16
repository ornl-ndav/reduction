/**
 * $Id$
 *
 * \file axis_manip/src/rebin_axis_1D.cpp
 */
#include "rebin_axis_1D.hpp"

namespace AxisManip
{
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
