/**
 * $Id$
 *
 * \file axis_manip/src/final_velocity_igs.cpp
 */
#include "final_velocity_igs.hpp"

namespace AxisManip
{
  // explicit instantiations
  /**
   * This is the float declaration of the function defined in 3.20.
   *
   * \ingroup final_velocity_igs
   */
  template std::string
  final_velocity_igs<float>(const float analyzer_wavelength,
                            const float analyzer_wavelength_err2,
                            float & final_velocity,
                            float & final_velocity_err2,
                            void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.20.
   *
   * \ingroup final_velocity_igs
   */
  template std::string
  final_velocity_igs<double>(const double analyzer_wavelength,
                             const double analyzer_wavelength_err2,
                             double & final_velocity,
                             double & final_velocity_err2,
                             void *temp);
} // AxisManip
