/**
 * $Id$
 *
 * \file axis_manip/src/init_scatt_wavevector_to_Q.cpp
 */
#include "init_scatt_wavevector_to_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.32.
   *
   * \see init_scatt_wavevector_to_Q()
   */
  template std::string
  init_scatt_wavevector_to_Q<float>(std::vector<float> const & initial_wavevector,
				    std::vector<float> const & initial_wavevector_err2,
				    std::vector<float> const & final_wavevector,
				    std::vector<float> const & final_wavevector_err2,
				    const float azimuthal_angle,
				    const float azimuthal_angle_err2,
				    const float polar_angle,
				    const float polar_angle_err2,
				    std::vector<float> & Qx,
				    std::vector<float> & Qx_err2,
				    std::vector<float> & Qy,
				    std::vector<float> & Qy_err2,
				    std::vector<float> & Qz,
				    std::vector<float> & Qz_err2,
				    void *temp=NULL);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.32.
   *
   * \see init_scatt_wavevector_to_Q()
   */
  template std::string
  init_scatt_wavevector_to_Q<double>(std::vector<double> const & initial_wavevector,
				     std::vector<double> const & initial_wavevector_err2,
				     std::vector<double> const & final_wavevector,
				     std::vector<double> const & final_wavevector_err2,
				     const double azimuthal_angle,
				     const double azimuthal_angle_err2,
				     const double polar_angle,
				     const double polar_angle_err2,
				     std::vector<double> & Qx,
				     std::vector<double> & Qx_err2,
				     std::vector<double> & Qy,
				     std::vector<double> & Qy_err2,
				     std::vector<double> & Qz,
				     std::vector<double> & Qz_err2,
				     void *temp=NULL);
  
  /**
   * This is the integer declaration of the function defined in 3.32.
   *
   * \see init_scatt_wavevector_to_Q()
   */
  template std::string
  init_scatt_wavevector_to_Q<int>(std::vector<int> const & initial_wavevector,
				  std::vector<int> const & initial_wavevector_err2,
				  std::vector<int> const & final_wavevector,
				  std::vector<int> const & final_wavevector_err2,
				  const int azimuthal_angle,
				  const int azimuthal_angle_err2,
				  const int polar_angle,
				  const int polar_angle_err2,
				  std::vector<int> & Qx,
				  std::vector<int> & Qx_err2,
				  std::vector<int> & Qy,
				  std::vector<int> & Qy_err2,
				  std::vector<int> & Qz,
				  std::vector<int> & Qz_err2,
				  void *temp=NULL);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.32.
   *
   * \see init_scatt_wavevector_to_Q()
   */
  template std::string
  init_scatt_wavevector_to_Q<unsigned int>(std::vector<unsigned int> const & initial_wavevector,
					   std::vector<unsigned int> const & initial_wavevector_err2,
					   std::vector<unsigned int> const & final_wavevector,
					   std::vector<unsigned int> const & final_wavevector_err2,
					   const unsigned int azimuthal_angle,
					   const unsigned int azimuthal_angle_err2,
					   const unsigned int polar_angle,
					   const unsigned int polar_angle_err2,
					   std::vector<unsigned int> & Qx,
					   std::vector<unsigned int> & Qx_err2,
					   std::vector<unsigned int> & Qy,
					   std::vector<unsigned int> & Qy_err2,
					   std::vector<unsigned int> & Qz,
					   std::vector<unsigned int> & Qz_err2,
					   void *temp=NULL);
  
} // AxisManip
