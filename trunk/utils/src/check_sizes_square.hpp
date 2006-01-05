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
			  const Nessi::Vector<NumT> & array1, 
			  const Nessi::Vector<NumT> & array2, 
			  const Nessi::Vector<NumT> & array3)
  {
    size_t sz1 = array1.size();
    size_t sz2 = array2.size();
    size_t sz3 = array3.size();

    if (sz1 != sz2)
      {
        errstr += "array1 not the same size as array2";
        throw std::invalid_argument(errstr);
      }

    if (sz1 != sz3)
      {
        errstr += "array1 not the same size as array3";
        throw std::invalid_argument(errstr);
      }

    if (sz2 != sz3)
      {
        errstr += "array2 not the same size as array3";
        throw std::invalid_argument(errstr);
      }

    return;
  }

  template <typename NumT>
  void check_sizes_square(std::string & errstr, 
			  const Nessi::Vector<NumT> & array1,
			  const Nessi::Vector<NumT> & array2)
  {
    size_t sz1 = array1.size();
    size_t sz2 = array2.size();

    if (sz1 != sz2)
      {
        errstr += "array1 not the same size as array2";
        throw std::invalid_argument(errstr);
      }

    return;
  }

} // Utils

#endif // _CHECK_SIZES_SQUARE_HPP
