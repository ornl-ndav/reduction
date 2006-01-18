/**
 * $Id$
 *
 * \file axis_manip/src/velocity_to_energy.cpp
 */
#include "velocity_to_energy.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.21.
   *
   * \ingroup velocity_to_energy
   */
  template std::string
  velocity_to_energy<float>(const Nessi::Vector<float> & velocity,
                            const Nessi::Vector<float> & velocity_err2,
                            Nessi::Vector<float> & energy,
                            Nessi::Vector<float> & energy_err2,
                            void *temp);

  /**
   * This is the float declaration of the function defined in 3.21.
   *
   * \ingroup velocity_to_energy
   */
  template std::string
  velocity_to_energy<float>(const float velocity,
                            const float velocity_err2,
                            float & energy,
                            float & energy_err2,
                            void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.21.
   *
   * \ingroup velocity_to_energy
   */
  template std::string
  velocity_to_energy<double>(const Nessi::Vector<double> & velocity,
                             const Nessi::Vector<double> & velocity_err2,
                             Nessi::Vector<double> & energy,
                             Nessi::Vector<double> & energy_err2,
                             void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.21.
   *
   * \ingroup velocity_to_energy
   */
  template std::string
  velocity_to_energy<double>(const double velocity,
                             const double velocity_err2,
                             double & energy,
                             double & energy_err2,
                             void *temp);
} // AxisManip
