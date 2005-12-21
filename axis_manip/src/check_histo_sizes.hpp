/**
 * $Id$
 *
 * \file axis_manip/src/check_histo_sizes.hpp
 */
#include "check_histo.hpp"
#include <stdexcept>
#include <string>
#include <vector>

namespace AxisManip
{
  template <typename NumT>
  void 
  check_histo_sizes(std::string & errstr,
		    std::vector<NumT> const & input,
		    std::vector<NumT> const & input_err2,
		    std::vector<NumT> const & axis)
  {
    size_t szi1 = input.size();
    size_t szie1 = input_err2.size();
    size_t szai = axis.size();

    if (szi1 != szie1)
      {
	errstr += "input and input_err2 are not the same size";
	throw std::invalid_argument(errstr);
      }

    if(szai != szi1+1)
      {
	errstr += "axis size is not input size + 1";
	throw std::invalid_argument(errstr);
      }

    if(szai != szie1+1)
      {
	errstr += "axis size is not input_err2 size + 1";
	throw std::invalid_argument(errstr);
      }

    return;
  }
} // AxisManip
