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
 * \file utils/src/pt_length.hpp
 */

#ifndef _PT_LENGTH_HPP
#define _PT_LENGTH_HPP 1

#include "geometry.hpp"
#include <cmath>

namespace Utils
{
  template <typename NumT>
  NumT
  __pt_length(NumT x, NumT y)
  {
    return static_cast<NumT>(std::sqrt(static_cast<double>((x * x) + 
                                                           (y * y))));
  }

} // Utils

#endif // _PT_LENGTH_HPP
