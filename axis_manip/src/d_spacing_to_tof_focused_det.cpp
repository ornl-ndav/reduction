/**
 * $Id$
 *
 * \file axis_manip/src/d_spacing_to_tof_focused_det.cpp
 */
#include "conversions.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.39
  template <typename NumT>
  std::string
  d_spacing_to_tof_focused_det(std::vector<NumT> const & d_spacing,
			       std::vector<NumT> const & d_spacing_err2,
			       const NumT pathlength_focused,
			       const NumT polar_angle_focused,
			       std::vector<NumT> & tof,
			       std::vector<NumT> & tof_err2,
			       void *temp=NULL)
  {
    throw std::runtime_error("Function [d_spacing_to_tof_focused_det] not implemented");
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.39.
   *
   * \see d_spacing_to_tof_focused_det()
   */
  template std::string
  d_spacing_to_tof_focused_det<float>(std::vector<float> const & d_spacing,
				      std::vector<float> const & d_spacing_err2,
				      const float pathlength_focused,
				      const float polar_angle_focused,
				      std::vector<float> & tof,
				      std::vector<float> & tof_err2,
				      void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.39.
   *
   * \see d_spacing_to_tof_focused_det()
   */
  template std::string
  d_spacing_to_tof_focused_det<double>(std::vector<double> const & d_spacing,
				       std::vector<double> const & d_spacing_err2,
				       const double pathlength_focused,
				       const double polar_angle_focused,
				       std::vector<double> & tof,
				       std::vector<double> & tof_err2,
				       void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.39.
   *
   * \see d_spacing_to_tof_focused_det()
   */
  template std::string
  d_spacing_to_tof_focused_det<int>(std::vector<int> const & d_spacing,
				    std::vector<int> const & d_spacing_err2,
				    const int pathlength_focused,
				    const int polar_angle_focused,
				    std::vector<int> & tof,
				    std::vector<int> & tof_err2,
				    void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.39.
   *
   * \see d_spacing_to_tof_focused_det()
   */
  template std::string
  d_spacing_to_tof_focused_det<unsigned int>(
					     std::vector<unsigned int> const & d_spacing,
					     std::vector<unsigned int> const & d_spacing_err2,
					     const unsigned int pathlength_focused,
					     const unsigned int polar_angle_focused,
					     std::vector<unsigned int> & tof,
					     std::vector<unsigned int> & tof_err2,
					     void *temp);
  
} // AxisManip
