/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_wavelength.cpp
 */
#include "conversions.hpp"
#include "constants.hpp"
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.15
  template <typename NumT>
  std::string
  tof_to_wavelength(std::vector<NumT> const & tof,
		    std::vector<NumT> const & tof_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    std::vector<NumT> & wavelength,
		    std::vector<NumT> & wavelength_err2,
		    void *temp=NULL)
  {
    std::string retstr("");

    NumT a = static_cast<NumT>(PhysConst::H_OVER_MNEUT) / pathlength;
    NumT a2 = a * a;

    size_t sz = tof.size();
    for (size_t i = 0; i < sz; ++i)
      {
	wavelength[i] = a * tof[i];
	wavelength_err2[i] = a2 * tof_err2[i];
      }

    return retstr;
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \see tof_to_wavelength()
   */
  template std::string
  tof_to_wavelength<float>(std::vector<float> const & tof,
			   std::vector<float> const & tof_err2,
			   const float pathlength,
			   const float pathlength_err2,
			   std::vector<float> & wavelength,
			   std::vector<float> & wavelength_err2,
			   void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \see tof_to_wavelength()
   */
  template std::string
  tof_to_wavelength<double>(std::vector<double> const & tof,
			    std::vector<double> const & tof_err2,
			    const double pathlength,
			    const double pathlength_err2,
			    std::vector<double> & wavelength,
			    std::vector<double> & wavelength_err2,
			    void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.30.
   *
   * \see tof_to_wavelength()
   */
  template std::string
  tof_to_wavelength<int>(std::vector<int> const & tof,
			 std::vector<int> const & tof_err2,
			 const int pathlength,
			 const int pathlength_err2,
			 std::vector<int> & wavelength,
			 std::vector<int> & wavelength_err2,
			 void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.30.
   *
   * \see tof_to_wavelength()
   */
  template std::string
  tof_to_wavelength<unsigned int>(std::vector<unsigned int> const & tof,
                                  std::vector<unsigned int> const & tof_err2,
                                  const unsigned int pathlength,
				  const unsigned int pathlength_err2,
                                  std::vector<unsigned int> & wavelength,
                                  std::vector<unsigned int> & wavelength_err2,
                                  void *temp);
  
} // AxisManip
