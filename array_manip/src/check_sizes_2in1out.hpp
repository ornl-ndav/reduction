/**
 * $Id$
 *
 * \file array_manip/src/check_sizes_2in1out.hpp
 */
#ifndef _CHECK_SIZES_2IN1OUT_HPP
#define _CHECK_SIZES_2IN1OUT_HPP 1

#include "check_inputs.hpp"
#include <stdexcept>

namespace ArrayManip
{
  template <typename NumT>
  void check_sizes_2in1out(std::string & errstr, 
			   Nessi::Vector<NumT> const & input1, 
			   Nessi::Vector<NumT> const & input2, 
			   Nessi::Vector<NumT> const & output)
  {
    size_t szi1 = input1.size();
    size_t szi2 = input2.size();
    size_t szo = output.size();

    if (szi1 != szi2)
      {
	errstr += "input1 and input2 are not the same size";
	throw std::invalid_argument(errstr);
      }

    if (szi1 != szo)
      {
	errstr += "output not the same size as input1";
	throw std::invalid_argument(errstr);
      }

    if (szi2 != szo)
      {
	errstr += "output not the same size as input2";
	throw std::invalid_argument(errstr);
      }

    return;
  }
} // ArrayManip

#endif // _CHECK_SIZES_2IN1OUT_HPP
