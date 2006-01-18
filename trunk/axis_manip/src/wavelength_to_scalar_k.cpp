/**
 * $Id$
 *
 * \file axis_manip/src/wavelength_to_scalar_k.cpp
 */
#include "wavelength_to_scalar_k.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.24.
   *
   * \ingroup wavelength_to_scalar_k
   */
  template std::string
  wavelength_to_scalar_k<float>(const Nessi::Vector<float> & wavelength,
                                const Nessi::Vector<float> & wavelength_err2,
                                Nessi::Vector<float> & wavevector,
                                Nessi::Vector<float> & wavevector_err2,
                                void *temp);

  /**
   * This is the float declaration of the function defined in 3.24.
   *
   * \ingroup wavelength_to_scalar_k
   */
  template std::string
  wavelength_to_scalar_k<float>(const float wavelength,
                                const float wavelength_err2,
                                float & wavevector,
                                float & wavevector_err2,
                                void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.24.
   *
   * \ingroup wavelength_to_scalar_k
   */
  template std::string
  wavelength_to_scalar_k<double>(const Nessi::Vector<double> & wavelength,
                                 const Nessi::Vector<double> & wavelength_err2,
                                 Nessi::Vector<double> & wavevector,
                                 Nessi::Vector<double> & wavevector_err2,
                                 void *temp);

  /**
   * This is the double precision float declaration of the function
   * defined in 3.24.
   *
   * \ingroup wavelength_to_scalar_k
   */
  template std::string
  wavelength_to_scalar_k<double>(const double wavelength,
                                 const double wavelength_err2,
                                 double & wavevector,
                                 double & wavevector_err2,
                                 void *temp);
} // AxisManip
