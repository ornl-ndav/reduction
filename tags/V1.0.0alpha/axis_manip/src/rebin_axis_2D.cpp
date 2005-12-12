/**
 * $Id$
 *
 * \file axis_manip/src/rebin_axis_2D.cpp
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
		std::vector<NumT> const & input_err,
		std::vector<NumT> const & axis_out_1,
		std::vector<NumT> const & axis_out_2,
		std::vector<NumT> & output,
		std::vector<NumT> & output_err,
		void *temp=NULL)
  {
    throw std::runtime_error("Function [rebin_axis_2D] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaraion of the function defined in 3.13.
   *
   * \see rebin_axis_2D()
   */
  template std::string 
  rebin_axis_2D<float>(std::vector<float> const & axis_in_1,
		       std::vector<float> const & axis_in_2,
		       std::vector<float> const & input,
		       std::vector<float> const & input_err,
		       std::vector<float> const & axis_out_1,
		       std::vector<float> const & axis_out_2,
		       std::vector<float> & output,
		       std::vector<float> & output_err,
		       void *temp);
  
  /**
   * This is the double precision float declaraion of the function
   * defined in 3.13.
   *
   * \see rebin_axis_2D()
   */
  template std::string 
  rebin_axis_2D<double>(std::vector<double> const & axis_in_1,
			std::vector<double> const & axis_in_2,
			std::vector<double> const & input,
			std::vector<double> const & input_err,
			std::vector<double> const & axis_out_1,
			std::vector<double> const & axis_out_2,
			std::vector<double> & output,
			std::vector<double> & output_err,
			void *temp);

  /**
   * This is the integer declaraion of the function defined in 3.13.
   *
   * \see rebin_axis_2D()
   */
  template std::string 
  rebin_axis_2D<int>(std::vector<int> const & axis_in_1,
		     std::vector<int> const & axis_in_2,
		     std::vector<int> const & input,
		     std::vector<int> const & input_err,
		     std::vector<int> const & axis_out_1,
		     std::vector<int> const & axis_out_2,
		     std::vector<int> & output,
		     std::vector<int> & output_err,
		     void *temp);

  /**
   * This is the unsigned integer declaraion of the function defined
   * in 3.13.
   *
   * \see rebin_axis_2D()
   */
  template std::string 
  rebin_axis_2D<unsigned int>(std::vector<unsigned int> const & axis_in_1,
                              std::vector<unsigned int> const & axis_in_2,
                              std::vector<unsigned int> const & input,
                              std::vector<unsigned int> const & input_err,
                              std::vector<unsigned int> const & axis_out_1,
                              std::vector<unsigned int> const & axis_out_2,
                              std::vector<unsigned int> & output,
                              std::vector<unsigned int> & output_err,
                              void *temp);
  

} // AxisManip
