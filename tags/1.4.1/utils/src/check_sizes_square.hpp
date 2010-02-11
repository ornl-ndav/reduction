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
 * \file utils/src/check_sizes_square.hpp
 */
#ifndef _CHECK_SIZES_SQUARE_HPP
#define _CHECK_SIZES_SQUARE_HPP 1

#include "size_checks.hpp"
#include <stdexcept>

namespace Utils
{
  template <typename NumT>
  void check_sizes_square(const Nessi::Vector<NumT> & array1,
                          const Nessi::Vector<NumT> & array2,
                          const Nessi::Vector<NumT> & array3)
  {
    size_t sz1 = array1.size();
    size_t sz2 = array2.size();
    size_t sz3 = array3.size();

    if (sz1 != sz2)
      {
        std::string errstr = "array1 not the same size as array2";
        throw std::invalid_argument(errstr);
      }

    if (sz1 != sz3)
      {
        std::string errstr = "array1 not the same size as array3";
        throw std::invalid_argument(errstr);
      }

    return;
  }

  template<typename NumT>
  void check_sizes_square(std::string str,
                          const Nessi::Vector<NumT> & array1,
                          const Nessi::Vector<NumT> & array2,
                          const Nessi::Vector<NumT> & array3)
  {
    size_t sz1 = array1.size();
    size_t sz2 = array2.size();
    size_t sz3 = array3.size();

    if (sz1 != sz2)
      {
        std::string errstr = str + " array1 not the same size as array2";
        throw std::invalid_argument(errstr);
      }

    if (sz1 != sz3)
      {
        std::string errstr = str + " array1 not the same size as array3";
        throw std::invalid_argument(errstr);
      }

    return;
  }

  template <typename NumT>
  void check_sizes_square(const Nessi::Vector<NumT> & array1,
                          const Nessi::Vector<NumT> & array2)
  {
    size_t sz1 = array1.size();
    size_t sz2 = array2.size();

    if (sz1 != sz2)
      {
        std::string errstr = "array1 not the same size as array2";
        throw std::invalid_argument(errstr);
      }

    return;
  }

  template <typename NumT>
  void check_sizes_square(std::string str,
                          const Nessi::Vector<NumT> & array1,
                          const Nessi::Vector<NumT> & array2)
  {
    size_t sz1 = array1.size();
    size_t sz2 = array2.size();

    if (sz1 != sz2)
      {
        std::string errstr = str + " array1 not the same size as array2";
        throw std::invalid_argument(errstr);
      }

    return;
  }

} // Utils

#endif // _CHECK_SIZES_SQUARE_HPP
