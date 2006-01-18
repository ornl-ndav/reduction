/**
 * $Id$
 *
 * \file axis_manip/src/energy_transfer.cpp
 */
#include "energy_transfer.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<float>(const Nessi::Vector<float> & initial_energy,
                         const Nessi::Vector<float> & initial_energy_err2,
                         const Nessi::Vector<float> & final_energy,
                         const Nessi::Vector<float> & final_energy_err2,
                         Nessi::Vector<float> & energy_transfer,
                         Nessi::Vector<float> & energy_transfer_err2,
                         void *temp);

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<float>(const Nessi::Vector<float> & initial_energy,
                         const Nessi::Vector<float> & initial_energy_err2,
                         const float final_energy,
                         const float final_energy_err2,
                         Nessi::Vector<float> & energy_transfer,
                         Nessi::Vector<float> & energy_transfer_err2,
                         void *temp);

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<float>(const float initial_energy,
                         const float initial_energy_err2,
                         const Nessi::Vector<float> & final_energy,
                         const Nessi::Vector<float> & final_energy_err2,
                         Nessi::Vector<float> & energy_transfer,
                         Nessi::Vector<float> & energy_transfer_err2,
                         void *temp);

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<float>(const float initial_energy,
                         const float initial_energy_err2,
                         const float final_energy,
                         float final_energy_err2,
                         float & energy_transfer,
                         float & energy_transfer_err2,
                         void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<double>(const Nessi::Vector<double> & initial_energy,
                          const Nessi::Vector<double> & initial_energy_err2,
                          const Nessi::Vector<double> & final_energy,
                          const Nessi::Vector<double> & final_energy_err2,
                          Nessi::Vector<double> & energy_transfer,
                          Nessi::Vector<double> & energy_transfer_err2,
                          void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<double>(const Nessi::Vector<double> & initial_energy,
                          const Nessi::Vector<double> & initial_energy_err2,
                          const double final_energy,
                          const double final_energy_err2,
                          Nessi::Vector<double> & energy_transfer,
                          Nessi::Vector<double> & energy_transfer_err2,
                          void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<double>(const double initial_energy,
                          const double initial_energy_err2,
                          const Nessi::Vector<double> & final_energy,
                          const Nessi::Vector<double> & final_energy_err2,
                          Nessi::Vector<double> & energy_transfer,
                          Nessi::Vector<double> & energy_transfer_err2,
                          void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \ingroup energy_transfer
   */
  template std::string
  energy_transfer<double>(const double initial_energy,
                          const double initial_energy_err2,
                          const double final_energy,
                          const double final_energy_err2,
                          double & energy_transfer,
                          double & energy_transfer_err2,
                          void *temp);
} // AxisManip
