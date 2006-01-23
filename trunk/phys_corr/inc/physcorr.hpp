/*
 *                     SNS Common Libraries
 *           A part of the SNS Analysis Software Suite.
 *
 *                  Spallation Neutron Source
 *          Oak Ridge National Laboratory, Oak Ridge TN.
 *
 *
 *                             NOTICE
 * 
 * For this software and its associated documentation, permission is granted 
 * to reproduce, prepare derivative works, and distribute copies to the public 
 * for any purpose and without fee.
 *  
 * This material was prepared as an account of work sponsored by an agency of 
 * the United States Government.  Neither the United States Government nor the 
 * United States Department of Energy, nor any of their employees, makes any 
 * warranty, express or implied, or assumes any legal liability or 
 * responsibility for the accuracy, completeness, or usefulness of any 
 * information, apparatus, product, or process disclosed, or represents that 
 * its use would not infringe privately owned rights.
 *
 */

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
  /// Empty string for no warning to return
  static const std::string EMPTY_WARN("");

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
