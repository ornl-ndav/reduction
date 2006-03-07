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
 * \file utils/src/peak_integration.hpp
 */
#ifndef _PEAK_INTEGRATION_HPP
#define _PEAK_INTEGRATION_HPP 1

#include "utils.hpp"
#include <stdexcept>

namespace Utils
{
  // 3.35
  template <typename NumT>
  std::string
  peak_integration(const Nessi::Vector<NumT> & input,
                   const Nessi::Vector<NumT> & input_err2,
                   const Nessi::Vector<NumT> & start_bin,
                   NumT & output,
                   NumT & output_err2,
                   unsigned int & tag,
                   NumT & num_bins,
                   void *temp=NULL)
  {
    throw std::runtime_error("Function [peak_integration] not implemented");
  }
} // Utils

#endif // _PEAK_INTEGRATION_HPP
