/**
 * $Id$
 *
 * \file axis_manip/src/final_velocity_igs.cpp
 */
#include "conversions.hpp"
#include <stdexcept>
#include <string>

namespace AxisManip 
{
  // 3.20
  template <typename NumT>
  std::string
  final_velocity_igs(const NumT analyzer_wavelength,
		     const NumT analyzer_wavelength_err2,
		     NumT & final_velocity,
		     NumT & final_velocity_err2,
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
			    const float analyzer_wavelength_err2,
			    float & final_velocity,
			    float & final_velocity_err2,
			    void *temp);
 
  /**
   * This is the double precision float declaration of the function
   * defined in 3.20.
   *
   * \see final_velocity_igs()
   */
  template std::string
  final_velocity_igs<double>(const double analyzer_wavelength,
			     const double analyzer_wavelength_err2,
			     double & final_velocity,
			     double & final_velocity_err2,
			     void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.20.
   *
   * \see final_velocity_igs()
   */
  template std::string
  final_velocity_igs<int>(const int analyzer_wavelength,
			  const int analyzer_wavelength_err2,
			  int & final_velocity,
			  int & final_velocity_err2,
			  void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.20.
   *
   * \see final_velocity_igs()
   */
  template std::string
  final_velocity_igs<unsigned int>(const unsigned int analyzer_wavelength,
				   const unsigned int analyzer_wavelength_err2,
				   unsigned int & final_velocity,
				   unsigned int & final_velocity_err2,
				   void *temp);
  
} // AxisManip
