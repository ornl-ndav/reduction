/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_k.cpp
 */
#include "conversions.hpp"
#include "constants.hpp"
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.24
  template <typename NumT>
  std::string
  wavelength_to_scalar_k(std::vector<NumT> const & wavelength,
			 std::vector<NumT> const & wavelength_err2,
			 std::vector<NumT> & wavevector,
			 std::vector<NumT> & wavevector_err2,
			 void *temp=NULL)
  {
    std::string retstr("");

    NumT a = 2 * static_cast<NumT>(PhysConst::PI);
    NumT a2 = a * a;
    
    size_t sz = wavelength.size();
    for (size_t i = 0; i < sz; ++i)
      {
        wavevector[i] = a / wavelength[i];
        wavevector_err2[i] = (a2 * wavelength_err2[i]) / 
	  (wavelength[i] * wavelength[i] * wavelength[i] * wavelength[i]);
      }

    return retstr;
  }
  
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.24.
   *
   * \see wavelength_to_scalar_k()
   */
  template std::string
  wavelength_to_scalar_k<float>(std::vector<float> const & wavelength,
				std::vector<float> const & wavelength_err2,
				std::vector<float> & wavevector,
				std::vector<float> & wavevector_err2,
				void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.24.
   *
   * \see wavelength_to_scalar_k()
   */
  template std::string
  wavelength_to_scalar_k<double>(std::vector<double> const & wavelength,
				 std::vector<double> const & wavelength_err2,
				 std::vector<double> & wavevector,
				 std::vector<double> & wavevector_err2,
				 void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.24.
   *
   * \see wavelength_to_scalar_k()
   */
  template std::string
  wavelength_to_scalar_k<int>(std::vector<int> const & wavelength,
			      std::vector<int> const & wavelength_err2,
			      std::vector<int> & wavevector,
			      std::vector<int> & wavevector_err2,
			      void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.24.
   *
   * \see wavelength_to_scalar_k()
   */
  template std::string
  wavelength_to_scalar_k<unsigned int>(
                             std::vector<unsigned int> const & wavelength,
                             std::vector<unsigned int> const & wavelength_err2,
                             std::vector<unsigned int> & wavevector,
                             std::vector<unsigned int> & wavevector_err2,
                             void *temp);
  
} // AxisManip
