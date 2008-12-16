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

    return retstr;
  }

} // PhysCorr

#endif // _EXP_DETECTOR_EFF_HPP
