/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_initial_velocity_igs.cpp
 */
#include "conversions.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.28
  template <typename NumT>
  std::string
  tof_to_initial_velocity_igs(std::vector<NumT> const & tof,
			      std::vector<NumT> const & tof_err2,
			      const NumT final_velocity,
			      const NumT time_offset,
			      const NumT dist_source_sample,
			      const NumT dist_sample_detector,
			      std::vector<NumT> & initial_velocity,
			      std::vector<NumT> & initial_velocity_err2,
			      void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_initial_velocity_igs] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.28.
   *
   * \see tof_to_initial_velocity_igs()
   */
  template std::string
  tof_to_initial_velocity_igs<float>(
                                    std::vector<float> const & tof,
                                    std::vector<float> const & tof_err2,
                                    const float final_velocity,
                                    const float time_offset,
                                    const float dist_source_sample,
                                    const float dist_sample_detector,
                                    std::vector<float> & initial_velocity,
                                    std::vector<float> & initial_velocity_err2,
                                    void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.28.
   *
   * \see tof_to_initial_velocity_igs()
   */
  template std::string
  tof_to_initial_velocity_igs<double>(
                                   std::vector<double> const & tof,
                                   std::vector<double> const & tof_err2,
                                   const double final_velocity,
                                   const double time_offset,
                                   const double dist_source_sample,
                                   const double dist_sample_detector,
                                   std::vector<double> & initial_velocity,
				   std::vector<double> & initial_velocity_err2,
                                   void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.28.
   *
   * \see tof_to_initial_velocity_igs()
   */
  template std::string
  tof_to_initial_velocity_igs<int>(std::vector<int> const & tof,
				   std::vector<int> const & tof_err2,
				   const int final_velocity,
				   const int time_offset,
				   const int dist_source_sample,
				   const int dist_sample_detector,
				   std::vector<int> & initial_velocity,
				   std::vector<int> & initial_velocity_err2,
				   void *temp);

  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.28.
   *
   * \see tof_to_initial_velocity_igs()
   */
  template std::string
  tof_to_initial_velocity_igs<unsigned int >(
                             std::vector<unsigned int> const & tof,
                             std::vector<unsigned int> const & tof_err2,
                             const unsigned int final_velocity,
                             const unsigned int time_offset,
                             const unsigned int dist_source_sample,
                             const unsigned int dist_sample_detector,
                             std::vector<unsigned int> & initial_velocity,
                             std::vector<unsigned int> & initial_velocity_err2,
                             void *temp);

} // AxisManip
