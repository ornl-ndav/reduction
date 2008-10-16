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
 * \file utils/src/integrate_1D_hist.hpp
 */
#ifndef _INTEGRATE_1D_HIST
#define _INTEGRATE_1D_HIST 1

#include "size_checks.hpp"
#include "utils.hpp"

namespace Utils
{
  // String for holding integrate_1D_hist function name
  const std::string i1h_func_str = "Utils::integrate_1D_hist";

  // 3.65
  template <typename NumT>
  std::string
  integrate_1D_hist(const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const bool width,
                    const Nessi::Vector<NumT> & axis_bw_in,
                    NumT & output,
                    NumT & output_err2,
                    void *temp=NULL)
  {
    std::string warn = "";

    return warn;
  }

  // 3.65
  template <typename NumT>
  std::string
  integrate_1D_hist(const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const Nessi::Vector<NumT> & axis_in,
                    const NumT min_int,
                    const NumT max_int, 
                    const bool width,
                    const Nessi::Vector<NumT> & axis_bw_in,
                    NumT & output,
                    NumT & output_err2,
                    void *temp=NULL)
  {
    std::string warn = "";

    return warn;
  }
} // Utils

#endif // _INTEGRATE_1D_HIST
