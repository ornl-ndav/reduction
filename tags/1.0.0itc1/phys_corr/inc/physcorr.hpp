/**
 * $Id$
 *
 * \file phys_corr/inc/physcorr.hpp
 */
#ifndef _PHYS_CORR_HPP
#define _PHYS_CORR_HPP 1

#include "nessi.hpp"
#include <string>

/**
 * \namespace PhysCorr
 *
 * \brief This sub-library contains the various corrections that
 * require a model of the data.
 *
 * All of these functions are written in reference to SNS
 * 107030214-TD0001-R00, "Data Reduction Library Software Requirements
 * and Specifications."
 */
namespace PhysCorr
{
  /**
   * \defgroup absorption_mult_scatt PhysCorr::absorption_mult_scatt
   * \{
   */

  /**
   * \brief This function is described in section 3.36.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    absorption_mult_scatt(const Nessi::Vector<NumT> & axis_in,
			  const Nessi::Vector<NumT> & input,
			  const Nessi::Vector<NumT> & input_err2,
			  NumT pathlength,
			  NumT polar_angle,
			  Nessi::Vector<NumT> & output,
			  Nessi::Vector<NumT> & output_err2,
			  void *temp=NULL);

  /**
   * \}
   */ // end of absorption_mult_scatt group

  /**
   * \defgroup dead_time_corr PhysCorr::dead_time_corr
   * \{
   */

  /**
   * \brief This function is described in section 3.38.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    dead_time_corr(const Nessi::Vector<NumT> & axis_in,
		   const Nessi::Vector<NumT> & input,
		   const Nessi::Vector<NumT> & input_err2,
		   NumT corr_factor,
		   Nessi::Vector<NumT> & output,
		   Nessi::Vector<NumT> & output_err2,
		   void *temp=NULL);

  /**
   * \}
   */ // end of dead_time_corr group

  /**
   * \defgroup inelastic_scatt_corr PhysCorr::inelastic_scatt_corr
   * \{
   */

  /**
   * \brief This function is described in section 3.40.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    inelastic_scatt_corr(const Nessi::Vector<NumT> & axis_in,
			 const Nessi::Vector<NumT> & input,
			 const Nessi::Vector<NumT> & input_err2,
			 Nessi::Vector<NumT> & output,
			 Nessi::Vector<NumT> & output_err2,
			 void *temp=NULL);

  /**
   * \}
   */ // end of inelastic_scatt_corr group

  /**
   * \defgroup incoherent_scatt_corr PhysCorr::incoherent_scatt_corr
   * \{
   */

  /**
   * \brief This function is described in section 3.41.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    incoherent_scatt_corr(const Nessi::Vector<NumT> & axis_in,
			  const Nessi::Vector<NumT> & input,
			  const Nessi::Vector<NumT> & input_err2,
			  Nessi::Vector<NumT> & output,
			  Nessi::Vector<NumT> & output_err2,
			  void *temp=NULL);

  /**
   * \}
   */ // end of incoherent_scatt_corr group

} // PhysCorr

#endif // _PHYS_CORR_HPP
