/**
 * $Id$
 *
 * \file axis_manip/src/tof_to_wavelength.hpp
 */
#ifndef _TOF_TO_WAVELENGTH_HPP
#define _TOF_TO_WAVELENGTH_HPP 1

#include "conversions.hpp"
#include "constants.hpp"
#include "size_checks.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.15
  template <typename NumT>
  std::string
  tof_to_wavelength(const Nessi::Vector<NumT> & tof,
		    const Nessi::Vector<NumT> & tof_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    Nessi::Vector<NumT> & wavelength,
		    Nessi::Vector<NumT> & wavelength_err2,
		    void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        std::string errstr("AxisManip::tof_to_wavelength: data ");
        Utils::check_sizes_square(errstr, tof, wavelength);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    // check that the uncertainties are of proper size
    try
      {
        std::string errstr("AxisManip::tof_to_wavelength: error ");
        Utils::check_sizes_square(errstr, tof_err2, wavelength_err2);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT a_err2;

    // fill the local variables
    __tof_to_wavelength_static(pathlength, pathlength_err2, a, a2, a_err2);
    if(warn.size()>0)
      retstr+=warn;

    // do the calculation
    size_t size_tof = tof.size();
    for (size_t i = 0; i < size_tof; ++i)
      {
        warn=__tof_to_wavelength_dynamic(tof[i], tof_err2[i], a, a2, a_err2,
                                         wavelength[i], wavelength_err2[i]);
        if(warn.size()>0)
          retstr+=warn;
      }

    return retstr;
  }

  // 3.15
  template <typename NumT>
  std::string
  tof_to_wavelength(const NumT tof,
		    const NumT tof_err2,
		    const NumT pathlength,
		    const NumT pathlength_err2,
		    NumT & wavelength,
		    NumT & wavelength_err2,
		    void *temp=NULL)
  {
    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT a;
    NumT a2;
    NumT a_err2;

    // fill the local variables
    __tof_to_wavelength_static(pathlength, pathlength_err2, a, a2, a_err2);
    if(warn.size()>0)
      retstr+=warn;

    // do the calculation
    warn=__tof_to_wavelength_dynamic(tof, tof_err2, a, a2, a_err2,
                                     wavelength, wavelength_err2);
    if(warn.size()>0)
      retstr+=warn;

    return retstr;
  }

  /**
   * This is a PRIVATE helper function for tof_to_wavelength that
   * calculates parameters invariant across array calculation.
   */
  template <typename NumT>
  std::string
  __tof_to_wavelength_static(const NumT pathlength,
                             const NumT pathlength_err2,
                             NumT & a,
                             NumT & a2,
                             NumT & a_err2)
  {
    // calculate the factor to multiply each element by
    a = static_cast<NumT>(PhysConst::H_OVER_MNEUT) / pathlength;
    a2 = a*a;

    // the result of these two lines is the uncertainty in the
    // multiplicative factor
    a_err2 = static_cast<NumT>(PhysConst::H_OVER_MNEUT)/pathlength;
    a_err2=a_err2*a_err2*pathlength_err2;

    return std::string("");
  }

  /**
   * This is a PRIVATE helper function for tof_to_wavelength that
   * calculates the wavelength and its uncertainty
   */
  template <typename NumT>
  std::string
  __tof_to_wavelength_dynamic(const NumT tof,
                              const NumT tof_err2,
                              const NumT a,
                              const NumT a2,
                              const NumT a_err2,
                              NumT & wavelength,
                              NumT & wavelength_err2)
  {
    // calculate the value
    wavelength = a * tof;

    // calculate the uncertainty
    wavelength_err2 = (a2*tof_err2) + ((tof*tof)*a_err2);

    return std::string("");
  }
} // AxisManip
#endif
