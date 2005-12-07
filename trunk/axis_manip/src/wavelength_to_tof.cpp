/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_tof.cpp
 */
#include "conversions.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.16
  template <typename NumT>
  std::string
  wavelength_to_tof(std::vector<NumT> const & wavelength,
		    std::vector<NumT> const & wavelength_err2,
		    const NumT pathlength,
		    std::vector<NumT> & tof,
		    std::vector<NumT> & tof_err2,
		    void *temp=NULL)
  {
    throw std::runtime_error("Function [wavelength_to_tof] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<float>(std::vector<float> const & wavelength,
			   std::vector<float> const & wavelength_err2,
			   const float pathlength,
			   std::vector<float> & tof,
			   std::vector<float> & tof_err2,
			   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<double>(std::vector<double> const & wavelength,
			    std::vector<double> const & wavelength_err2,
			    const double pathlength,
			    std::vector<double> & tof,
			    std::vector<double> & tof_err2,
			    void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<int>(std::vector<int> const & wavelength,
			 std::vector<int> const & wavelength_err2,
			 const int pathlength,
			 std::vector<int> & tof,
			 std::vector<int> & tof_err2,
			 void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.16.
   *
   * \see wavelength_to_tof()
   */
  template std::string
  wavelength_to_tof<unsigned int>(
                             std::vector<unsigned int> const & wavelength,
                             std::vector<unsigned int> const & wavelength_err2,
                             const unsigned int pathlength,
                             std::vector<unsigned int> & tof,
                             std::vector<unsigned int> & tof_err2,
                             void *temp);
  
} // AxisManip
