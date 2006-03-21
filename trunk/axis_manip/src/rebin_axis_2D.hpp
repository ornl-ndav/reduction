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
 * \file axis_manip/src/rebin_axis_2D.hpp
 */
#ifndef _REBIN_AXIS_2D_HPP
#define _REBIN_AXIS_2D_HPP 1

#include "nessi_warn.hpp"
#include "rebinning.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the rebin_axis_1D function name
  const std::string ra2_func_str = "AxisManip::rebin_axis_2D";

  // 3.13
  template <typename NumT>
  std::string
  rebin_axis_2D(const Nessi::Vector<NumT> & axis_in_1,
                const Nessi::Vector<NumT> & axis_in_2,
                const Nessi::Vector<NumT> & input,
                const Nessi::Vector<NumT> & input_err2,
                const Nessi::Vector<NumT> & axis_out_1,
                const Nessi::Vector<NumT> & axis_out_2,
                Nessi::Vector<NumT> & output,
                Nessi::Vector<NumT> & output_err2,
                void *temp=NULL)
  {
    // check that the input axes are the same length
    try
      {
        Utils::check_sizes_square(axis_in_1, axis_in_2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ra2_func_str+": original histogram axes "
                                    +e.what());
      }

    // check that the original histogram is of the proper size
    try
      {
        Utils::check_histo_sizes(input, input_err2, axis_in_1, axis_in_2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ra2_func_str+": original histogram "
                                    +e.what());
      }
    // check that the output axes are the same length
    try
      {
        Utils::check_sizes_square(axis_out_1, axis_out_2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ra2_func_str+": rebinned histogram axes "
                                    +e.what());
      }
    // check that the rebinned histogram is of the proper size
    try
      {
        Utils::check_histo_sizes(output, output_err2, axis_out_1, axis_out_2);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ra2_func_str+": rebinned histogram "
                                    +e.what());
      }

    std::string retstr(Nessi::EMPTY_WARN);
    std::string warn;

    size_t nold_input1 = axis_in_1.size() - 1;
    size_t nold_input2 = axis_in_2.size() - 1;
    size_t nnew_input1 = axis_out_1.size() - 1;
    size_t nnew_input2 = axis_out_2.size() - 1;


    // Create space for series of rebinned 2nd axes
    Nessi::Vector<NumT> stage1;
    stage1.reserve(nnew_input2 * nold_input1);

    Nessi::Vector<NumT> stage1_err2;
    stage1_err2.reserve(nnew_input2 * nold_input1);

    for(size_t i = 0; i < nold_input1; ++i)
      {
        // Create space and fill a 2nd axis for data and err2 for both
        // input and output

        Nessi::Vector<NumT> tmp_in;
        tmp_in.reserve(nold_input2);
        tmp_in.insert(tmp_in.begin(), input.begin()+(i * nold_input2),
                      input.begin()+((i+1) * nold_input2));

        Nessi::Vector<NumT> tmp_in_err2;
        tmp_in_err2.reserve(nold_input2);
        tmp_in_err2.insert(tmp_in_err2.begin(),
                           input_err2.begin()+(i * nold_input2),
                           input_err2.begin()+((i+1) * nold_input2));

        Nessi::Vector<NumT> tmp_out(nnew_input2);
        Nessi::Vector<NumT> tmp_out_err2(nnew_input2);

        try
          {
            warn = rebin_axis_1D(axis_in_2, tmp_in, tmp_in_err2, axis_out_2,
                                 tmp_out, tmp_out_err2);
          }
        catch(std::invalid_argument &e)
          {
            throw std::invalid_argument(ra2_func_str+" rebin axis 1: "
                                        +e.what());
          }

        if(!warn.empty())
          {
            retstr += warn;
          }

        // Fill returned information into temporary storage

        stage1.insert(stage1.begin()+(i*nnew_input2), tmp_out.begin(),
                      tmp_out.end());

        stage1_err2.insert(stage1_err2.begin()+(i*nnew_input2),
                           tmp_out_err2.begin(),
                           tmp_out_err2.end());

      }

    typename Nessi::Vector<NumT>::iterator iter;
    typename Nessi::Vector<NumT>::iterator iter_err2;

    typename Nessi::Vector<NumT>::iterator t_iter;
    typename Nessi::Vector<NumT>::iterator t_iter_err2;

    for(size_t j = 0; j < nnew_input2; ++j)
      {
        Nessi::Vector<NumT> tmp_in(nold_input1);
        tmp_in.reserve(nold_input1);

        Nessi::Vector<NumT> tmp_in_err2(nold_input1);
        tmp_in_err2.reserve(nold_input1);

        iter = stage1.begin()+j;
        iter_err2 = stage1_err2.begin()+j;

        t_iter = tmp_in.begin();
        t_iter_err2 = tmp_in_err2.begin();

        while(iter <= stage1.end() && iter_err2 <= stage1_err2.end())
          {
            *t_iter = *iter;
            *t_iter_err2 = *iter_err2;

            advance(iter, nnew_input2);
            advance(iter_err2, nnew_input2);

            ++t_iter;
            ++t_iter_err2;
          }

        Nessi::Vector<NumT> tmp_out(nnew_input1);
        Nessi::Vector<NumT> tmp_out_err2(nnew_input1);

        try
          {
            warn = rebin_axis_1D(axis_in_1, tmp_in, tmp_in_err2, axis_out_1,
                                 tmp_out, tmp_out_err2);
          }
        catch(std::invalid_argument &e)
          {
            throw std::invalid_argument(ra2_func_str+" "+e.what());
          }

        if(!warn.empty())
          {
            retstr += warn;
          }

        iter = output.begin()+j;
        iter_err2 = output_err2.begin()+j;

        t_iter = tmp_out.begin();
        t_iter_err2 = tmp_out_err2.begin();

        while(iter <= output.end() && iter_err2 <= output_err2.end())
          {
            *iter = *t_iter;
            *iter_err2 = *t_iter_err2;

            advance(iter, nnew_input2);
            advance(iter_err2, nnew_input2);

            ++t_iter;
            ++t_iter_err2;
          }
      }

    return retstr;
  }
} // AxisManip

#endif // _REBIN_AXIS_2D_HPP
