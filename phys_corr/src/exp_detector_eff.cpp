/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 *
 * For this software and its associated documentation, permission is granted
 * to reproduce, prepare derivative works, and distribute copies to the public
 * for any purpose and without fee.
 *
 * This material was prepared as an account of work sponsored by an agency of
 * the United States Government.  Neither the United States Government nor the
 * United States Department of Energy, nor any of their employees, makes any
 * warranty, express or implied, or assumes any legal liability or
 * responsibility for the accuracy, completeness, or usefulness of any
 * information, apparatus, product, or process disclosed, or represents that
 * its use would not infringe privately owned rights.
 *
 */

/**
 * $Id$
 *
 * \file phys_corr/src/exp_detector_eff.cpp
 */

#include "exp_detector_eff.hpp"

namespace PhysCorr
{
  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.66.
   *
   * \ingroup exp_detector_eff
   */
  template std::string
  exp_detector_eff<float>(const Nessi::Vector<float> & axis_bc,
                          const float scale,
                          const float scale_err2,
                          const float constant,
                          Nessi::Vector<float> & eff,
                          Nessi::Vector<float> & eff_err2,
                          void *temp);

  /**
   * This is the float declaration of the function defined in 3.66.
   *
   * \ingroup exp_detector_eff
   */
  template std::string
  exp_detector_eff<float>(const float axis_bc,
                          const float scale,
                          const float scale_err2,
                          const float constant,
                          float eff,
                          float eff_err2,
                          void *temp);

  /**
   * This is the double precision float declaration of the function defined 
   * in 3.66.
   *
   * \ingroup exp_detector_eff
   */
  template std::string
  exp_detector_eff<double>(const Nessi::Vector<double> & axis_bc,
                           const double scale,
                           const double scale_err2,
                           const double constant,
                           Nessi::Vector<double> & eff,
                           Nessi::Vector<double> & eff_err2,
                           void *temp);

  /**
   * This is the double precision float declaration of the function defined 
   * in 3.66.
   *
   * \ingroup exp_detector_eff
   */
  template std::string
  exp_detector_eff<double>(const double axis_bc,
                           const double scale,
                           const double scale_err2,
                           const double constant,
                           double eff,
                           double eff_err2,
                           void *temp);

} // PhysCorr
