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
  init_scatt_wavevector_to_Q<float>(
                          Nessi::Vector<float> const & initial_wavevector,
                          Nessi::Vector<float> const & initial_wavevector_err2,
                          Nessi::Vector<float> const & final_wavevector,
                          Nessi::Vector<float> const & final_wavevector_err2,
                          const float azimuthal_angle,
                          const float azimuthal_angle_err2,
                          const float polar_angle,
                          const float polar_angle_err2,
                          Nessi::Vector<float> & Qx,
                          Nessi::Vector<float> & Qx_err2,
                          Nessi::Vector<float> & Qy,
                          Nessi::Vector<float> & Qy_err2,
                          Nessi::Vector<float> & Qz,
                          Nessi::Vector<float> & Qz_err2,
                          void *temp=NULL);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.32.
   *
   * \see init_scatt_wavevector_to_Q()
   */
  template std::string
  init_scatt_wavevector_to_Q<double>(
                         Nessi::Vector<double> const & initial_wavevector,
                         Nessi::Vector<double> const & initial_wavevector_err2,
                         Nessi::Vector<double> const & final_wavevector,
                         Nessi::Vector<double> const & final_wavevector_err2,
                         const double azimuthal_angle,
                         const double azimuthal_angle_err2,
                         const double polar_angle,
                         const double polar_angle_err2,
                         Nessi::Vector<double> & Qx,
                         Nessi::Vector<double> & Qx_err2,
                         Nessi::Vector<double> & Qy,
                         Nessi::Vector<double> & Qy_err2,
                         Nessi::Vector<double> & Qz,
                         Nessi::Vector<double> & Qz_err2,
                         void *temp=NULL);
} // AxisManip
