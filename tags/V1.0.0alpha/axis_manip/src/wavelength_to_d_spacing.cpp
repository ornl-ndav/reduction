/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_d_spacing.cpp
 */
#include "conversions.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.25
  template <typename NumT>
  std::string
  wavelength_to_d_spacing(std::vector<NumT> const & wavelength,
			  std::vector<NumT> const & wavelength_err2,
			  const NumT scatt_angle,
			  std::vector<NumT> & d_spacing,
			  std::vector<NumT> & d_spacing_err2,
			  void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_d_spacing] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.25.
   *
   * \see wavelength_to_d_spacing()
   */
  template std::string
  wavelength_to_d_spacing<float>(std::vector<float> const & wavelength,
				 std::vector<float> const & wavelength_err2,
				 const float scatt_angle,
				 std::vector<float> & d_spacing,
				 std::vector<float> & d_spacing_err2,
				 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.25.
   *
   * \see wavelength_to_d_spacing()
   */
  template std::string
  wavelength_to_d_spacing<double>(std::vector<double> const & wavelength,
				  std::vector<double> const & wavelength_err2,
				  const double scatt_angle,
				  std::vector<double> & d_spacing,
				  std::vector<double> & d_spacing_err2,
				  void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.25.
   *
   * \see wavelength_to_d_spacing()
   */
  template std::string
  wavelength_to_d_spacing<int>(std::vector<int> const & wavelength,
			       std::vector<int> const & wavelength_err2,
			       const int scatt_angle,
			       std::vector<int> & d_spacing,
			       std::vector<int> & d_spacing_err2,
			       void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined in 3.25.
   *
   * \see wavelength_to_d_spacing()
   */
  template std::string
  wavelength_to_d_spacing<unsigned int>(
                             std::vector<unsigned int> const & wavelength,
                             std::vector<unsigned int> const & wavelength_err2,
                             const unsigned int scatt_angle,
                             std::vector<unsigned int> & d_spacing,
                             std::vector<unsigned int> & d_spacing_err2,
                             void *temp);
  
} // AxisManip
