/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_energy.cpp
 */
#include "conversions.hpp"
#include "constants.hpp"
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.22
  template <typename NumT>
  std::string
  wavelength_to_energy(std::vector<NumT> const & wavelength,
		       std::vector<NumT> const & wavelength_err2,
		       std::vector<NumT> & energy,
		       std::vector<NumT> & energy_err2,
		       void *temp=NULL)
  {
    std::string retstr("");
    
    NumT a2 = 4 * static_cast<NumT>(PhysConst::H2_OVER_2MNEUT) * 
      static_cast<NumT>(PhysConst::H2_OVER_2MNEUT);

    size_t sz = wavelength.size();
    for (size_t i = 0; i < sz; ++i)
      {
	NumT wavelength2 = wavelength[i] * wavelength[i];
        energy[i] = static_cast<NumT>(PhysConst::H2_OVER_2MNEUT) / wavelength2;
	energy_err2[i] = (a2 * wavelength_err2[i]) / (wavelength2 * wavelength2 * wavelength2);
      }

    return retstr;
  }
  
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<float>(std::vector<float> const & wavelength,
			      std::vector<float> const & wavelength_err2,
			      std::vector<float> & energy,
			      std::vector<float> & energy_err2,
			      void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<double>(std::vector<double> const & wavelength,
			       std::vector<double> const & wavelength_err2,
			       std::vector<double> & energy,
			       std::vector<double> & energy_err2,
			       void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<int>(std::vector<int> const & wavelength,
			    std::vector<int> const & wavelength_err2,
			    std::vector<int> & energy,
			    std::vector<int> & energy_err2,
			    void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.22.
   *
   * \see wavelength_to_energy()
   */
  template std::string
  wavelength_to_energy<unsigned int>(
                             std::vector<unsigned int> const & wavelength,
                             std::vector<unsigned int> const & wavelength_err2,
                             std::vector<unsigned int> & energy,
                             std::vector<unsigned int> & energy_err2,
                             void *temp);
  
} // AxisManip
