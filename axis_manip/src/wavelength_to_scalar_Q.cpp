/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_Q.cpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.18
  template <typename NumT>
  std::string
  wavelength_to_scalar_Q(std::vector<NumT> const & wavelength,
			 std::vector<NumT> const & wavelength_err2,
			 const NumT scatt_angle,
			 const NumT scatt_angle_err2,
			 std::vector<NumT> & Q,
			 std::vector<NumT> & Q_err2,
			 void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_scalar_Q] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.18.
   *
   * \see wavelength_to_scalar_Q()
   */
  template std::string
  wavelength_to_scalar_Q<float>(std::vector<float> const & wavelength,
				std::vector<float> const & wavelength_err2,
				const float scatt_angle,
				const float scatt_angle_err2,
				std::vector<float> & Q,
				std::vector<float> & Q_err2,
				void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.18.
   *
   * \see wavelength_to_scalar_Q()
   */
  template std::string
  wavelength_to_scalar_Q<double>(std::vector<double> const & wavelength,
				 std::vector<double> const & wavelength_err2,
				 const double scatt_angle,
				 const double scatt_angle_err2,
				 std::vector<double> & Q,
				 std::vector<double> & Q_err2,
				 void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.18.
   *
   * \see wavelength_to_scalar_Q()
   */
  template std::string
  wavelength_to_scalar_Q<int>(std::vector<int> const & wavelength,
			      std::vector<int> const & wavelength_err2,
			      const int scatt_angle,
			      const int scatt_angle_err2,
			      std::vector<int> & Q,
			      std::vector<int> & Q_err2,
			      void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.18.
   *
   * \see wavelength_to_scalar_Q()
   */
  template std::string
  wavelength_to_scalar_Q<unsigned int>(
                             std::vector<unsigned int> const & wavelength,
                             std::vector<unsigned int> const & wavelength_err2,
                             const unsigned int scatt_angle,
			     const unsigned int scatt_angle_err2,
                             std::vector<unsigned int> & Q,
                             std::vector<unsigned int> & Q_err2,
                             void *temp);
  
} // AxisManip
