/**
 * $Id$
 *
 * \file axis_manip/src/rebin_axis_1D.hpp
 */
#ifndef _REBIN_AXIS_1D_HPP
#define _REBIN_AXIS_1D_HPP 1

#include "rebinning.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  /// String for holding the rebin_axis_1D function name
  const std::string ra1_func_str = "AxisManip::rebin_axis_1D";

  // 3.12
  template <typename NumT>
  std::string
  rebin_axis_1D(const Nessi::Vector<NumT> & axis_in,
                const Nessi::Vector<NumT> & input,
                const Nessi::Vector<NumT> & input_err2,
                const Nessi::Vector<NumT> & axis_out,
                Nessi::Vector<NumT> & output,
                Nessi::Vector<NumT> & output_err2,
                void *temp=NULL)
  {
    // check that the original histogram is of the proper size
    try
      {
        Utils::check_histo_sizes(input, input_err2, axis_in);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ra1_func_str+": original histogram "
                                    +e.what());
      }
    // check that the rebinned histogram is of the proper size
    try
      {
        Utils::check_histo_sizes(output, output_err2, axis_out);
      }
    catch(std::invalid_argument &e)
      {
        throw std::invalid_argument(ra1_func_str+": rebinned histogram "
                                    +e.what());
      }

    size_t iold = 0;
    size_t inew = 0;

    size_t nold = input.size();
    size_t nnew = output.size();

    // Traverse both sets of bin edges, and if there is an overlap, add the
    // portion of the overlapping old bin to the new bin.
    while (inew < nnew && iold < nold)
      {
        const NumT axis_in_lo = axis_in[iold];
        const NumT axis_in_hi = axis_in[iold + 1];
        const NumT axis_out_lo = axis_out[inew];
        const NumT axis_out_hi = axis_out[inew + 1];

        // SNS-FIXME These comparison statements don't make any sense for
        // floating point numbers
        if (axis_out_hi <= axis_in_lo)
          {
            inew++;
          }
        else if (axis_in_hi <= axis_out_lo)
          {
            iold++;
          }
        else
          {
            // delta is the overlap of the bins on the axis
            const NumT delta = std::min(axis_in_hi, axis_out_hi) -
              std::max(axis_in_lo, axis_out_lo);
            const NumT width = axis_in_hi - axis_in_lo;
            const NumT portion = delta / width;

            output[inew] += input[iold] * portion;
            output_err2[inew] += input_err2[iold] * portion * portion;
            if (axis_out_hi > axis_in_hi)
              {
                iold++;
              }
            else
              {
                inew++;
              }
          }
      }

    std::string retstr("");
    return retstr;
  }
} // AxisManip

#endif // _REBIN_AXIS_1D_HPP
