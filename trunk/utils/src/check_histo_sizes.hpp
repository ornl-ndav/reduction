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
 */
#ifndef _CHECK_HISTO_SIZES_HPP
#define _CHECK_HISTO_SIZES_HPP 1

#include "size_checks.hpp"
#include <stdexcept>

namespace Utils
{
  template <typename NumT>
  void
  check_histo_sizes(const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const Nessi::Vector<NumT> & axis)
  {
    size_t size = input.size();
    size_t size_err2 = input_err2.size();
    size_t size_axis = axis.size();

    if (size != size_err2)
      {
        std::string errstr = "input and input_err2 are not the same size";
        throw std::invalid_argument(errstr);
      }

    if(size_axis != size+1)
      {
        std::string errstr = "axis size is not input size + 1";
        throw std::invalid_argument(errstr);
      }

    return;
  }

  template <typename NumT>
  void
  check_histo_sizes(std::string str,
                    const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const Nessi::Vector<NumT> & axis)
  {
    size_t size = input.size();
    size_t size_err2 = input_err2.size();
    size_t size_axis = axis.size();

    if (size != size_err2)
      {
        std::string errstr = str + " " + "input and input_err2 are not the same size";
        throw std::invalid_argument(errstr);
      }

    if (size_axis != size+1)
      {
        std::string errstr = str + " " + "axis size is not input size + 1";
        throw std::invalid_argument(errstr);
      }
    
    return;
  }

  template <typename NumT>
  void
  check_histo_sizes(const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const Nessi::Vector<NumT> & axis_1,
                    const Nessi::Vector<NumT> & axis_2)
  {
    size_t size = input.size();
    size_t size_err2 = input_err2.size();
    size_t size_axis_1 = axis_1.size();
    size_t size_axis_2 = axis_2.size();

    if (size != size_err2)
      {
        std::string errstr = "input and input_err2 are not the same size";
        throw std::invalid_argument(errstr);
      }

    if(size_axis_1*size_axis_2 != size+size_axis_1+size_axis_2-1)
      {
        std::string errstr = "size(axis_1)*size(axis_2) is not ";
        errstr += "size(input)+size(axis_1)+size(axis_2)-1";
        throw std::invalid_argument(errstr);
      }

    return;
  }

  template <typename NumT>
  void
  check_histo_sizes(std::string str,
                    const Nessi::Vector<NumT> & input,
                    const Nessi::Vector<NumT> & input_err2,
                    const Nessi::Vector<NumT> & axis_1,
                    const Nessi::Vector<NumT> & axis_2)
  {
    size_t size = input.size();
    size_t size_err2 = input_err2.size();
    size_t size_axis_1 = axis_1.size();
    size_t size_axis_2 = axis_2.size();

    if (size != size_err2)
      {
        std::string errstr = str + " " + "input and input_err2 are not the same size";
        throw std::invalid_argument(errstr);
      }

    if (size_axis_1*size_axis_2 != size+size_axis_1+size_axis_2-1)
      {
        std::string errstr = str + " " + "size(axis_1)*size(axis_2) is not ";
        errstr += "size(input)+size(axis_1)+size(axis_2)-1";
        throw std::invalid_argument(errstr);
      }

    return;
  }
} // Utils

#endif // _CHECK_HISTO_SIZES_HPP
