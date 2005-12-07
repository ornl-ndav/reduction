/**
 * $Id$
 *
 * \file phys_corr/src/absorption_mult_scatt.cpp
 */
#include "physcorr.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace PhysCorr
{
  // 3.36
  template <typename NumT>
  std::string
  absorption_mult_scatt(std::vector<NumT> const & axis_in,
			std::vector<NumT> const & input,
			std::vector<NumT> const & input_err2,
			NumT pathlength,
			NumT polar_angle,
			std::vector<NumT> & output,
			std::vector<NumT> & output_err2,
			void *temp=NULL)
  {
    throw std::runtime_error("Function [absorption_mult_scatt] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.36.
   *
   * \see absorption_mult_scatt()
   */
  template std::string
  absorption_mult_scatt<float>(std::vector<float> const & axis_in,
			       std::vector<float> const & input,
			       std::vector<float> const & input_err2,
			       float pathlength,
			       float polar_angle,
			       std::vector<float> & output,
			       std::vector<float> & output_err2,
			       void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.36.
   *
   * \see absorption_mult_scatt()
   */
  template std::string
  absorption_mult_scatt<double>(std::vector<double> const & axis_in,
				std::vector<double> const & input,
				std::vector<double> const & input_err2,
				double pathlength,
				double polar_angle,
				std::vector<double> & output,
				std::vector<double> & output_err2,
				void *temp);

  /**
   * This is the integer declaration of the function defined in 3.36.
   *
   * \see absorption_mult_scatt()
   */
  template std::string
  absorption_mult_scatt<int>(std::vector<int> const & axis_in,
			     std::vector<int> const & input,
			     std::vector<int> const & input_err2,
			     int pathlength,
			     int polar_angle,
			     std::vector<int> & output,
			     std::vector<int> & output_err2,
			     void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.36.
   *
   * \see absorption_mult_scatt()
   */
  template std::string
  absorption_mult_scatt<unsigned int>(
                                  std::vector<unsigned int> const & axis_in,
                                  std::vector<unsigned int> const & input,
                                  std::vector<unsigned int> const & input_err2,
				  unsigned int pathlength,
				  unsigned int polar_angle,
				  std::vector<unsigned int> & output,
				  std::vector<unsigned int> & output_err2,
				  void *temp);

} // PhysCorr
