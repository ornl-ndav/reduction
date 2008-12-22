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
 * \file phys_corr/src/exp_detector_eff.hpp
 */

#ifndef _EXP_DETECTOR_EFF_HPP
#define _EXP_DETECTOR_EFF_HPP 1

#include "nessi_warn.hpp"
#include "physcorr.hpp"
#include "size_checks.hpp"
#include <cmath>

namespace PhysCorr
{
  /// String for holding the exp_detector_eff function name
  const std::string ede_func_str = "AxisManip::exp_detector_eff";

  // 3.66
  template <typename NumT>
  std::string
  exp_detector_eff(const Nessi::Vector<NumT> & axis_bc,
                   const NumT scale,
                   const NumT scale_err2,
                   const NumT constant,
                   Nessi::Vector<NumT> & eff,
                   Nessi::Vector<NumT> & eff_err2,
                   void *temp=NULL)
  {
    // Check that the axis and efficiency arrays are the same size
    Utils::check_sizes_square(ede_func_str+
                              std::string(" axis and efficiency:"), 
                              axis_bc, eff, eff_err2);

    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // do the calculation
    std::size_t axis_size = axis_bc.size();
    for (std::size_t i = 0; i < axis_size; ++i)
      {
        retstr += __exp_detector_eff_dynamic(axis_bc[i], scale, scale_err2, 
                                             constant, eff[i], eff_err2[i]);

      }
    
    return retstr;
  }

  // 3.66
  template <typename NumT>
  std::string
  exp_detector_eff(const NumT axis_bc,
                   const NumT scale,
                   const NumT scale_err2,
                   const NumT constant,
                   NumT eff,
                   NumT eff_err2,
                   void *temp=NULL)
  {
    std::string retstr(Nessi::EMPTY_WARN); // the warning string

    // do the calculation
    retstr += __exp_detector_eff_dynamic(axis_bc, scale, scale_err2, constant,
                                         eff, eff_err2);

    return retstr;
  }

  /**
   * \ingroup exp_detector_eff
   *
   * This is a PRIVATE helper function for exp_detector_eff that
   * calculates the exponential detector efficiency and its uncertainty
   *
   * \param axis_bc (INPUT) same parameter as in exp_detector_eff()
   * \param scale (INPUT) same parameter as in exp_detector_eff()
   * \param scale_err2 (INPUT) same parameter as in exp_detector_eff()
   * \param constant (INPUT) same parameter as in exp_detector_eff() 
   * \param eff (OUTPUT) same parameter as in exp_detector_eff()
   * \param eff_err2 (OUTPUT) same parameter as in exp_detector_eff()
   */
  template <typename NumT>
  std::string __exp_detector_eff_dynamic(const NumT axis_bc,
                                         const NumT scale,
                                         const NumT scale_err2,
                                         const NumT constant,
                                         NumT eff,
                                         NumT eff_err2)
  {
    // calculate the value
    NumT expon1 = static_cast<NumT>(-1.0) * constant * axis_bc;

    eff = scale * static_cast<NumT>(std::exp(static_cast<double>(expon1)));

    // calculate the uncertainty
    NumT expon2 = static_cast<NumT>(2.0) * expon1;

    eff_err2 = scale_err2 * 
      static_cast<NumT>(std::exp(static_cast<double>(expon2)));

    return Nessi::EMPTY_WARN;
  }

} // PhysCorr

#endif // _EXP_DETECTOR_EFF_HPP
