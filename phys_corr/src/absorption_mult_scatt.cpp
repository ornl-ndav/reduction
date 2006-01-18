/**
 * $Id$
 *
 * \file phys_corr/src/absorption_mult_scatt.cpp
 */
#include "absorption_mult_scatt.hpp"

namespace PhysCorr
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.36.
   *
   * \ingroup absorption_mult_scatt
   */
  template std::string
  absorption_mult_scatt<float>(const Nessi::Vector<float> & axis_in,
                               const Nessi::Vector<float> & input,
                               const Nessi::Vector<float> & input_err2,
                               float pathlength,
                               float polar_angle,
                               Nessi::Vector<float> & output,
                               Nessi::Vector<float> & output_err2,
                               void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.36.
   *
   * \ingroup absorption_mult_scatt
   */
  template std::string
  absorption_mult_scatt<double>(const Nessi::Vector<double> & axis_in,
                                const Nessi::Vector<double> & input,
                                const Nessi::Vector<double> & input_err2,
                                double pathlength,
                                double polar_angle,
                                Nessi::Vector<double> & output,
                                Nessi::Vector<double> & output_err2,
                                void *temp);

} // PhysCorr
