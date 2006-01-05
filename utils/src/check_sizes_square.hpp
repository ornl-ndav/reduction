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
  void check_sizes_square(std::string & errstr, 
			  const Nessi::Vector<NumT> & input1, 
			  const Nessi::Vector<NumT> & input2, 
			  const Nessi::Vector<NumT> & output)
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

  template <typename NumT>
  void check_sizes_square(std::string & errstr, 
			  const Nessi::Vector<NumT> & input,
			  const Nessi::Vector<NumT> & output)
  {
    size_t szi = input.size();
    size_t szo = output.size();

    if (szi != szo)
      {
        errstr += "output not the same size as input";
        throw std::invalid_argument(errstr);
      }

    return;
  }

} // Utils

#endif // _CHECK_SIZES_SQUARE_HPP
