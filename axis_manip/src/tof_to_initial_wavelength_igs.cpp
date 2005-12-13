/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_initial_wavelength_igs.cpp
 */
#include "constants.hpp"
#include "conversions.hpp"
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.29
  template <typename NumT>
  std::string
  tof_to_initial_wavelength_igs(std::vector<NumT> const & tof,
				std::vector<NumT> const & tof_err2,
				const NumT final_wavelength,
				const NumT final_wavelength_err2,
				const NumT time_offset,
				const NumT time_offset_err2,
				const NumT dist_source_sample,
				const NumT dist_source_sample_err2,
				const NumT dist_sample_detector,
				const NumT dist_sample_detector_err2,
				std::vector<NumT> & initial_wavelength,
				std::vector<NumT> & initial_wavelength_err2,
				void *temp=NULL)
  {
    std::string retstr("");

    NumT a = static_cast<NumT>(1 / (PhysConst::H_OVER_MNEUT * 
				    dist_sample_detector));
    NumT a2 = a * a;

    NumT b = (dist_sample_detector * final_wavelength) / dist_source_sample;
    b += (a * time_offset);

    size_t sz = tof.size();
    for (size_t i = 0; i < sz; ++i)
      {
	initial_wavelength[i] = a * tof[i] - b;
	initial_wavelength_err2[i] = a2 * tof_err2[i];
      }

    return retstr;
  }
  
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.29.
   *
   * \see tof_to_initial_wavelength_igs()
   */
  template std::string
  tof_to_initial_wavelength_igs<float>(std::vector<float> const & tof,
				       std::vector<float> const & tof_err2,
				       const float final_wavelength,
				       const float final_wavelength_err2,
				       const float time_offset,
				       const float time_offset_err2,
				       const float dist_source_sample,
				       const float dist_source_sample_err2,
				       const float dist_sample_detector,
				       const float dist_sample_detector_err2,
				       std::vector<float> & initial_wavelength,
				       std::vector<float> & initial_wavelength_err2,
				       void *temp=NULL);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.29.
   *
   * \see tof_to_initial_wavelength_igs()
   */
  template std::string
  tof_to_initial_wavelength_igs<double>(std::vector<double> const & tof,
					std::vector<double> const & tof_err2,
					const double final_wavelength,
					const double final_wavelength_err2,
					const double time_offset,
					const double time_offset_err2,
					const double dist_source_sample,
					const double dist_source_sample_err2,
					const double dist_sample_detector,
					const double dist_sample_detector_err2,
					std::vector<double> & initial_wavelength,
					std::vector<double> & initial_wavelength_err2,
					void *temp=NULL);
  
  /**
   * This is the integer declaration of the function defined in 3.29.
   *
   * \see tof_to_initial_wavelength_igs()
   */
  template std::string
  tof_to_initial_wavelength_igs<int>(std::vector<int> const & tof,
				     std::vector<int> const & tof_err2,
				     const int final_wavelength,
				     const int final_wavelength_err2,
				     const int time_offset,
				     const int time_offset_err2,
				     const int dist_source_sample,
				     const int dist_source_sample_err2,
				     const int dist_sample_detector,
				     const int dist_sample_detector_err2,
				     std::vector<int> & initial_wavelength,
				     std::vector<int> & initial_wavelength_err2,
				     void *temp=NULL);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.29.
   *
   * \see tof_to_initial_wavelength_igs()
   */
  template std::string
  tof_to_initial_wavelength_igs<unsigned int>(std::vector<unsigned int> const & tof,
					      std::vector<unsigned int> const & tof_err2,
					      const unsigned int final_wavelength,
					      const unsigned int final_wavelength_err2,
					      const unsigned int time_offset,
					      const unsigned int time_offset_err2,
					      const unsigned int dist_source_sample,
					      const unsigned int dist_source_sample_err2,
					      const unsigned int dist_sample_detector,
					      const unsigned int dist_sample_detector_err2,
					      std::vector<unsigned int> & initial_wavelength,
					      std::vector<unsigned int> & initial_wavelength_err2,
					      void *temp=NULL);
  
} // AxisManip
