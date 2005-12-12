/**
 * $Id$
 *
 * \file utils/src/fit_linear_background.cpp
 */
#include "utils.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace Utils
{
  // 3.43
  template <typename NumT>
  std::string
  fit_linear_background(std::vector<NumT> const & axis_in,
			std::vector<NumT> const & input,
			std::vector<NumT> const & input_err2,
			NumT min_val, NumT max_val,
			NumT slope_start, 
			NumT intercept_start,
			NumT & slope_out, NumT & slope_out_err2,
			NumT & intercept_out,
			NumT & intercept_out_err2,
			void *temp=NULL)
  {
    throw std::runtime_error("Function [fit_linear_background] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.43.
   *
   * \see fit_linear_background()
   */
  template std::string
  fit_linear_background<float>(std::vector<float> const & axis_in,
			       std::vector<float> const & input,
			       std::vector<float> const & input_err2,
			       float min_val, float max_val,
			       float slope_start, 
			       float intercept_start,
			       float & slope_out, float & slope_out_err2,
			       float & intercept_out,
			       float & intercept_out_err2,
			       void *temp);
  /**
   * This is the double precision float declaration of the function
   * defined in 3.43.
   *
   * \see fit_linear_background()
   */
  template std::string
  fit_linear_background<double>(std::vector<double> const & axis_in,
				std::vector<double> const & input,
				std::vector<double> const & input_err2,
				double min_val, double max_val,
				double slope_start, 
				double intercept_start,
				double & slope_out, double & slope_out_err2,
				double & intercept_out,
				double & intercept_out_err2,
				void *temp);

  /**
   * This is the integer declaration of the function defined in 3.43.
   *
   * \see fit_linear_background()
   */
  template std::string
  fit_linear_background<int>(std::vector<int> const & axis_in,
			     std::vector<int> const & input,
			     std::vector<int> const & input_err2,
			     int min_val, int max_val,
			     int slope_start, 
			     int intercept_start,
			     int & slope_out, int & slope_out_err2,
			     int & intercept_out,
			     int & intercept_out_err2,
			     void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.43.
   *
   * \see fit_linear_background()
   */
  template std::string
  fit_linear_background<unsigned int>(
                                  std::vector<unsigned int> const & axis_in,
				  std::vector<unsigned int> const & input,
                                  std::vector<unsigned int> const & input_err2,
				  unsigned int min_val, unsigned int max_val,
				  unsigned int slope_start, 
				  unsigned int intercept_start,
				  unsigned int & slope_out,
                                  unsigned int & slope_out_err2,
				  unsigned int & intercept_out,
				  unsigned int & intercept_out_err2,
				  void *temp);
  
} // Utils
