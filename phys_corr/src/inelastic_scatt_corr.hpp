/**
 * $Id$
 *
 * \file phys_corr/src/inelastic_scatt_corr.hpp
 */
#ifndef _INELASTIC_SCATT_CORR_H
#define _INELASTIC_SCATT_CORR_H 1

#include "physcorr.hpp"
#include <string>
#include <vector>
#include <stdexcept>

namespace PhysCorr
{
  // 3.40
  template <typename NumT>
  std::string
  inelastic_scatt_corr(std::vector<NumT> const & axis_in,
		       std::vector<NumT> const & input,
		       std::vector<NumT> const & input_err2,
		       std::vector<NumT> & output,
		       std::vector<NumT> & output_err2,
		       void *temp=NULL)
  {
    throw std::runtime_error("Function [incoherent_scatt_corr] not implemented");
  }
} // PhysCorr

#endif // _INELASTIC_SCATT_CORR_H
