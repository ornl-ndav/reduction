/**
 * $Id$
 *
 * \file phys_corr/src/inelastic_scatt_corr.hpp
 */
#ifndef _INELASTIC_SCATT_CORR_H
#define _INELASTIC_SCATT_CORR_H 1

#include "physcorr.hpp"
#include <stdexcept>

namespace PhysCorr
{
  // 3.40
  template <typename NumT>
  std::string
  inelastic_scatt_corr(Nessi::Vector<NumT> const & axis_in,
		       Nessi::Vector<NumT> const & input,
		       Nessi::Vector<NumT> const & input_err2,
		       Nessi::Vector<NumT> & output,
		       Nessi::Vector<NumT> & output_err2,
		       void *temp=NULL)
  {
    throw std::runtime_error("Function [incoherent_scatt_corr] not implemented");
  }
} // PhysCorr

#endif // _INELASTIC_SCATT_CORR_H
