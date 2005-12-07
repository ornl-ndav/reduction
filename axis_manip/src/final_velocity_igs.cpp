/**
 * $Id$
 *
 * \file axis_manip/src/final_velocity_igs.cpp
 */
#include "conversions.hpp"
#include <string>
#include <stdexcept>

namespace AxisManip 
{
  // 3.20
  template <typename NumT>
  std::string
  final_velocity_igs(const NumT analyzer_wavelength,
		     NumT & final_velocity,
		     void *temp=NULL)
  {
    throw std::runtime_error("Function [final_velocity_igs] not implemented");
  }

  // explicit instantiations
  /**
   * This is the float declaration of the function defined in 3.20.
   *
   * \see final_velocity_igs()
   */
  template std::string
  final_velocity_igs<float>(const float analyzer_wavelength,
			    float & final_velocity,
			    void *temp);
 
  /**
   * This is the double precision float declaration of the function
   * defined in 3.20.
   *
   * \see final_velocity_igs()
   */
  template std::string
  final_velocity_igs<double>(const double analyzer_wavelength,
			     double & final_velocity,
			     void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.20.
   *
   * \see final_velocity_igs()
   */
  template std::string
  final_velocity_igs<int>(const int analyzer_wavelength,
			  int & final_velocity,
			  void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.20.
   *
   * \see final_velocity_igs()
   */
  template std::string
  final_velocity_igs<unsigned int>(const unsigned int analyzer_wavelength,
			       unsigned & final_velocity,
			       void *temp);
  
} // AxisManip
