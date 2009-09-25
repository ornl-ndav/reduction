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
 * \file phys_corr/src/dead_time_corr.hpp
 */
#ifndef _DEAD_TIME_CORR_HPP
#define _DEAD_TIME_CORR_HPP 1

#include "physcorr.hpp"
#include <stdexcept>

namespace PhysCorr
{
  // 3.38
  template <typename NumT>
  std::string
  dead_time_corr(const Nessi::Vector<NumT> & axis_in,
                 const Nessi::Vector<NumT> & input,
                 const Nessi::Vector<NumT> & input_err2,
                 NumT corr_factor,
                 Nessi::Vector<NumT> & output,
                 Nessi::Vector<NumT> & output_err2,
                 void *temp=NULL)
  {
    throw std::runtime_error("Function [dead_time_corr] not implemented");
  }
} // PhysCorr

#endif // _DEAD_TIME_CORR_HPP
