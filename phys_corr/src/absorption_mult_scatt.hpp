/**
 * $Id$
 *
 * \file phys_corr/src/absorption_mult_scatt.hpp
 */
#ifndef _ABSORPTION_MULT_SCATT_H
#define _ABSORPTION_MULT_SCATT_H 1

#include "physcorr.hpp"
#include <stdexcept>

namespace PhysCorr
{
  // 3.36
  template <typename NumT>
  std::string
  absorption_mult_scatt(Nessi::Vector<NumT> const & axis_in,
			Nessi::Vector<NumT> const & input,
			Nessi::Vector<NumT> const & input_err2,
			NumT pathlength,
			NumT polar_angle,
			Nessi::Vector<NumT> & output,
			Nessi::Vector<NumT> & output_err2,
			void *temp=NULL)
  {
    throw std::runtime_error("Function [absorption_mult_scatt] not implemented");
  }

} // PhysCorr

#endif // _ABSORPTION_MULT_SCATT_H
