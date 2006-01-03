/**
 * $Id$
 *
 * \file axis_manip/src/init_scatt_wavevector_to_scalar_Q.cpp
 */
#include "init_scatt_wavevector_to_scalar_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaraion of the function defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<float>(
			  const Nessi::Vector<float> & initial_wavevector,
                          const Nessi::Vector<float> & initial_wavevector_err2,
                          const Nessi::Vector<float> & final_wavevector,
                          const Nessi::Vector<float> & final_wavevector_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Q,
                          Nessi::Vector<float> & Q_err2,
                          void *temp);
  
  /**
   * This is the float declaraion of the function defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<float>(
			  const float initial_wavevector,
                          const float initial_wavevector_err2,
                          const Nessi::Vector<float> & final_wavevector,
                          const Nessi::Vector<float> & final_wavevector_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Q,
                          Nessi::Vector<float> & Q_err2,
                          void *temp);
  
  /**
   * This is the float declaraion of the function defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<float>(
			  const Nessi::Vector<float> & initial_wavevector,
                          const Nessi::Vector<float> & initial_wavevector_err2,
                          const float final_wavevector,
                          const float final_wavevector_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Q,
                          Nessi::Vector<float> & Q_err2,
                          void *temp);
  
  /**
   * This is the float declaraion of the function defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<float>(
			  const float initial_wavevector,
                          const float initial_wavevector_err2,
                          const float final_wavevector,
                          const float final_wavevector_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          float & Q,
                          float & Q_err2,
                          void *temp);
  
  /**
   * This is the double precision float declaraion of the function
   * defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<double>(
                         const Nessi::Vector<double> & initial_wavevector,
			 const Nessi::Vector<double> & initial_wavevector_err2,
                         const Nessi::Vector<double> & final_wavevector,
                         const Nessi::Vector<double> & final_wavevector_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Q,
                         Nessi::Vector<double> & Q_err2,
                         void *temp);

  /**
   * This is the double precision float declaraion of the function
   * defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<double>(
                         const double initial_wavevector,
			 const double initial_wavevector_err2,
                         const Nessi::Vector<double> & final_wavevector,
                         const Nessi::Vector<double> & final_wavevector_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Q,
                         Nessi::Vector<double> & Q_err2,
                         void *temp);

  /**
   * This is the double precision float declaraion of the function
   * defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<double>(
                         const Nessi::Vector<double> & initial_wavevector,
			 const Nessi::Vector<double> & initial_wavevector_err2,
                         const double final_wavevector,
                         const double final_wavevector_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Q,
                         Nessi::Vector<double> & Q_err2,
                         void *temp);

  /**
   * This is the double precision float declaraion of the function
   * defined in 3.33.
   *
   * \see init_scatt_wavevector_to_scalarQ()
   */
  template std::string
  init_scatt_wavevector_to_scalar_Q<double>(
                         const double initial_wavevector,
			 const double initial_wavevector_err2,
                         const double final_wavevector,
                         const double final_wavevector_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         double & Q,
                         double & Q_err2,
                         void *temp);
} // AxisManip
