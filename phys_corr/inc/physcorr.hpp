/**
 * $Id$
 *
 * \file phys_corr/inc/physcorr.hpp
 */
#ifndef _PHYS_CORR_H
#define _PHYS_CORR_H 1

#include <string>
#include <vector>

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
    absorption_mult_scatt(std::vector<NumT> const & axis_in,
			  std::vector<NumT> const & input,
			  std::vector<NumT> const & input_err2,
			  NumT pathlength,
			  NumT polar_angle,
			  std::vector<NumT> & output,
			  std::vector<NumT> & output_err2,
			  void *temp=NULL);

  /**
   * \brief This function is described in section 3.38.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    dead_time_corr(std::vector<NumT> const & axis_in,
		   std::vector<NumT> const & input,
		   std::vector<NumT> const & input_err2,
		   NumT corr_factor,
		   std::vector<NumT> & output,
		   std::vector<NumT> & output_err2,
		   void *temp=NULL);

  /**
   * \brief This function is described in section 3.40.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    inelastic_scatt_corr(std::vector<NumT> const & axis_in,
			 std::vector<NumT> const & input,
			 std::vector<NumT> const & input_err2,
			 std::vector<NumT> & output,
			 std::vector<NumT> & output_err2,
			 void *temp=NULL);

  /**
   * \brief This function is described in section 3.41.
   *
   * THIS FUNCTION IS NOT DEFINED.
   */
  template <typename NumT>
    std::string
    incoherent_scatt_corr(std::vector<NumT> const & axis_in,
			  std::vector<NumT> const & input,
			  std::vector<NumT> const & input_err2,
			  std::vector<NumT> & output,
			  std::vector<NumT> & output_err2,
			  void *temp=NULL);

} // PhysCorr

#endif // _PHYS_CORR_H
