/**
 * $Id$
 *
 * \file axis_manip/src/check_histo_sizes.hpp
 */
#ifndef _CHECK_HISTO_SIZES_HPP
#define _CHECK_HISTO_SIZES_HPP 1

#include "check_histo.hpp"
#include <stdexcept>

namespace AxisManip
{
  template <typename NumT>
  void 
  check_histo_sizes(std::string & errstr,
		    Nessi::Vector<NumT> const & input,
		    Nessi::Vector<NumT> const & input_err2,
		    Nessi::Vector<NumT> const & axis)
  {
    size_t size = input.size();
    size_t size_err2 = input_err2.size();
    size_t size_axis = axis.size();

    if (size != size_err2)
      {
	errstr += "input and input_err2 are not the same size";
	throw std::invalid_argument(errstr);
      }

    if(size_axis != size+1)
      {
	errstr += "axis size is not input size + 1";
	throw std::invalid_argument(errstr);
      }

    if(size_axis != size_err2+1)
      {
	errstr += "axis size is not input_err2 size + 1";
	throw std::invalid_argument(errstr);
      }

    return;
  }
} // AxisManip
#endif
