/**
 * $Id$
 *
 * \file utils/src/peak_integration.cpp
 */
#include "utils.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace Utils
{
  // 3.35
  template <typename NumT>
  std::string
  peak_integration(std::vector<NumT> const & input,
		   std::vector<NumT> const & input_err2,
		   std::vector<NumT> const & start_bin,
		   NumT & output,
		   NumT & output_err2,
                   unsigned int & tag,
		   NumT & num_bins,
		   void *temp=NULL)
  {
    throw std::runtime_error("Function [peak_integration] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.35.
   *
   * \see peak_integration()
   */
  template std::string
  peak_integration<float>(std::vector<float> const & input,
			  std::vector<float> const & input_err2,
			  std::vector<float> const & start_bin,
			  float & output,
			  float & output_err2,
                          unsigned int & tag,
			  float & num_bins,
			  void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.35.
   *
   * \see peak_integration()
   */
  template std::string
  peak_integration<double>(std::vector<double> const & input,
			   std::vector<double> const & input_err2,
			   std::vector<double> const & start_bin,
			   double & output,
			   double & output_err2,
                           unsigned int & tag,
			   double & num_bins,
			   void *temp);

  /**
   * This is the integer declaration of the function defined in 3.35.
   *
   * \see peak_integration()
   */
  template std::string
  peak_integration<int>(std::vector<int> const & input,
			std::vector<int> const & input_err2,
			std::vector<int> const & start_bin,
			int & output,
			int & output_err2,
			unsigned int & tag,
			int & num_bins,
			void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.35.
   *
   * \see peak_integration()
   */
  template std::string
  peak_integration<unsigned int>(std::vector<unsigned int> const & input,
			     std::vector<unsigned int> const & input_err2,
			     std::vector<unsigned int> const & start_bin,
			     unsigned int & output,
			     unsigned int & output_err2,
			     unsigned int & tag,
			     unsigned int & num_bins,
			     void *temp);
 
} // Utils
