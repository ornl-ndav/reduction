/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_scalar_Q.cpp
 */
#include "conversions.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace AxisManip
{
  // 3.17
  template <typename NumT>
  std::string
  tof_to_scalar_Q(std::vector<NumT> const & tof,
		  std::vector<NumT> const & tof_err2,
		  const NumT pathlength,
                  const NumT scatt_angle,
		  std::vector<NumT> & Q,
		  std::vector<NumT> & Q_err2,
		  void *temp=NULL)
  {
    throw std::runtime_error("Function [tof_to_scalar_Q] not implemented");    
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.17.
   *
   * \see tof_to_scalar_Q()
   */
  template std::string
  tof_to_scalar_Q<float>(std::vector<float> const & tof,
			 std::vector<float> const & tof_err2,
			 const float pathlength,
                         const float scatt_angle,
			 std::vector<float> & Q,
			 std::vector<float> & Q_err2,
			 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.17.
   *
   * \see tof_to_scalar_Q()
   */
  template std::string
  tof_to_scalar_Q<double>(std::vector<double> const & tof,
			  std::vector<double> const & tof_err2,
			  const double pathlength,
                          const double scatt_angle,
			  std::vector<double> & Q,
			  std::vector<double> & Q_err2,
			  void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.17.
   *
   * \see tof_to_scalar_Q()
   */
  template std::string
  tof_to_scalar_Q<int>(std::vector<int> const & tof,
		       std::vector<int> const & tof_err2,
		       const int pathlength,
                       const int scatt_angle,
		       std::vector<int> & Q,
		       std::vector<int> & Q_err2,
		       void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.17.
   *
   * \see tof_to_scalar_Q()
   */
  template std::string
  tof_to_scalar_Q<unsigned int>(std::vector<unsigned int> const & tof,
                                std::vector<unsigned int> const & tof_err2,
                                const unsigned int pathlength,
                                const unsigned int scatt_angle,
                                std::vector<unsigned int> & Q,
                                std::vector<unsigned int> & Q_err2,
                                void *temp);
  
} // AxisManip
