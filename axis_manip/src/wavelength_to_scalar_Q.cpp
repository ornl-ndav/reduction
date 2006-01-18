/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_Q.cpp
 */
#include "wavelength_to_scalar_Q.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.18.
   *
   * \ingroup wavelength_to_scalar_Q
   */
  template std::string
  wavelength_to_scalar_Q<float>(const Nessi::Vector<float> & wavelength,
                                const Nessi::Vector<float> & wavelength_err2,
                                const float scatt_angle,
                                const float scatt_angle_err2,
                                Nessi::Vector<float> & Q,
                                Nessi::Vector<float> & Q_err2,
                                void *temp);

  /**
   * This is the float declaration of the function defined in 3.18.
   *
   * \ingroup wavelength_to_scalar_Q
   */
  template std::string
  wavelength_to_scalar_Q<float>(const float wavelength,
                                const float wavelength_err2,
                                const float scatt_angle,
                                const float scatt_angle_err2,
                                float & Q,
                                float & Q_err2,
                                void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.18.
   *
   * \ingroup wavelength_to_scalar_Q
   */
  template std::string
  wavelength_to_scalar_Q<double>(const Nessi::Vector<double> & wavelength,
                                 const Nessi::Vector<double> & wavelength_err2,
                                 const double scatt_angle,
                                 const double scatt_angle_err2,
                                 Nessi::Vector<double> & Q,
                                 Nessi::Vector<double> & Q_err2,
                                 void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.18.
   *
   * \ingroup wavelength_to_scalar_Q
   */
  template std::string
  wavelength_to_scalar_Q<double>(const double wavelength,
                                 const double wavelength_err2,
                                 const double scatt_angle,
                                 const double scatt_angle_err2,
                                 double & Q,
                                 double & Q_err2,
                                 void *temp);
} // AxisManip
