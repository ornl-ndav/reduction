/**
 * $Id$
 *
 * \file phys_corr/inc/physcorr.hpp
 */
#ifndef _PHYS_CORR_H
#define _PHYS_CORR_H 1

#include "nessi.hpp"
#include <string>

/**
 * This sub-library contains the various corrections that require a
 * model of the data.
 *
 * All of these functions are written in reference to SNS
 * 107030214-TD0001-R00, "Data Reduction Library Software Requirements
 * and Specifications."
 */
namespace PhysCorr
{
  /**
   * \brief This function is described in section 3.36.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    absorption_mult_scatt(Nessi::Vector<NumT> const & axis_in,
			  Nessi::Vector<NumT> const & input,
			  Nessi::Vector<NumT> const & input_err2,
			  NumT pathlength,
			  NumT polar_angle,
			  Nessi::Vector<NumT> & output,
			  Nessi::Vector<NumT> & output_err2,
			  void *temp=NULL);

  /**
   * \brief This function is described in section 3.38.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    dead_time_corr(Nessi::Vector<NumT> const & axis_in,
		   Nessi::Vector<NumT> const & input,
		   Nessi::Vector<NumT> const & input_err2,
		   NumT corr_factor,
		   Nessi::Vector<NumT> & output,
		   Nessi::Vector<NumT> & output_err2,
		   void *temp=NULL);

  /**
   * \brief This function is described in section 3.40.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    inelastic_scatt_corr(Nessi::Vector<NumT> const & axis_in,
			 Nessi::Vector<NumT> const & input,
			 Nessi::Vector<NumT> const & input_err2,
			 Nessi::Vector<NumT> & output,
			 Nessi::Vector<NumT> & output_err2,
			 void *temp=NULL);

  /**
   * \brief This function is described in section 3.41.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    incoherent_scatt_corr(Nessi::Vector<NumT> const & axis_in,
			  Nessi::Vector<NumT> const & input,
			  Nessi::Vector<NumT> const & input_err2,
			  Nessi::Vector<NumT> & output,
			  Nessi::Vector<NumT> & output_err2,
			  void *temp=NULL);

} // PhysCorr

#endif // _PHYS_CORR_H
