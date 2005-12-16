/**
 *  $Id$
 *
 * \file axis_manip/src/rebin_axis_4D.cpp
 */
#include "rebin_axis_4D.hpp"

namespace AxisManip
{
  // explicit instantiations  

  /**
   * This is the float declaration of the function defined in 3.14.
   *
   * \see rebin_axis_4D()
   */
  template std::string 
  rebin_axis_4D<float>(std::vector<float> const & axis_in_1,
		       std::vector<float> const & axis_in_2,
		       std::vector<float> const & axis_in_3,
		       std::vector<float> const & axis_in_4,
		       std::vector<float> const & input,
		       std::vector<float> const & input_err2,
		       std::vector<float> const & axis_out_1,
		       std::vector<float> const & axis_out_2,
		       std::vector<float> const & axis_out_3,
		       std::vector<float> const & axis_out_4,
		       std::vector<float> & output,
		       std::vector<float> & output_err2,
		       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.14.
   *
   * \see rebin_axis_4D()
   */
  template std::string 
  rebin_axis_4D<double>(std::vector<double> const & axis_in_1,
			std::vector<double> const & axis_in_2,
			std::vector<double> const & axis_in_3,
			std::vector<double> const & axis_in_4,
			std::vector<double> const & input,
			std::vector<double> const & input_err2,
			std::vector<double> const & axis_out_1,
			std::vector<double> const & axis_out_2,
			std::vector<double> const & axis_out_3,
			std::vector<double> const & axis_out_4,
			std::vector<double> & output,
			std::vector<double> & output_err2,
			void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.14.
   *
   * \see rebin_axis_4D()
   */
  template std::string 
  rebin_axis_4D<int>(std::vector<int> const & axis_in_1,
		     std::vector<int> const & axis_in_2,
		     std::vector<int> const & axis_in_3,
		     std::vector<int> const & axis_in_4,
		     std::vector<int> const & input,
		     std::vector<int> const & input_err2,
		     std::vector<int> const & axis_out_1,
		     std::vector<int> const & axis_out_2,
		     std::vector<int> const & axis_out_3,
		     std::vector<int> const & axis_out_4,
		     std::vector<int> & output,
		     std::vector<int> & output_err2,
		     void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.14.
   *
   * \see rebin_axis_4D()
   */
  template std::string 
  rebin_axis_4D<unsigned int>(std::vector<unsigned int> const & axis_in_1,
                              std::vector<unsigned int> const & axis_in_2,
                              std::vector<unsigned int> const & axis_in_3,
                              std::vector<unsigned int> const & axis_in_4,
                              std::vector<unsigned int> const & input,
                              std::vector<unsigned int> const & input_err2,
                              std::vector<unsigned int> const & axis_out_1,
                              std::vector<unsigned int> const & axis_out_2,
                              std::vector<unsigned int> const & axis_out_3,
                              std::vector<unsigned int> const & axis_out_4,
                              std::vector<unsigned int> & output,
                              std::vector<unsigned int> & output_err2,
                              void *temp);
  
} // AxisManip
