/**
 * $Id$
 *
 * \file phys_corr/src/absorption_mult_scatt.hpp
 */
#ifndef _ABSORPTION_MULT_SCATT_H
#define _ABSORPTION_MULT_SCATT_H 1

#include "physcorr.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace PhysCorr
{
  // 3.36
  template <typename NumT>
  std::string
  absorption_mult_scatt(std::vector<NumT> const & axis_in,
			std::vector<NumT> const & input,
			std::vector<NumT> const & input_err2,
			NumT pathlength,
			NumT polar_angle,
			std::vector<NumT> & output,
			std::vector<NumT> & output_err2,
			void *temp=NULL)
  {
    throw std::runtime_error("Function [absorption_mult_scatt] not implemented");
  }

} // PhysCorr

#endif // _ABSORPTION_MULT_SCATT_H
