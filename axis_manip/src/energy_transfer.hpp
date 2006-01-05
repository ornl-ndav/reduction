/**
 * $Id$
 *
 * \file axis_manip/src/energy_transfer.hpp
 */
#ifndef _ENERGY_TRANSFER_HPP
#define _ENERGY_TRANSFER_HPP 1

#include "conversions.hpp"
#include "size_checks.hpp"
#include "constants.hpp"
#include <stdexcept>

namespace AxisManip
{
  // 3.30
  template <typename NumT>
  std::string
  energy_transfer(const Nessi::Vector<NumT> & initial_energy,
                  const Nessi::Vector<NumT> & initial_energy_err2,
                  const Nessi::Vector<NumT> & final_energy,
                  const Nessi::Vector<NumT> & final_energy_err2,
                  Nessi::Vector<NumT> & energy_transfer,
                  Nessi::Vector<NumT> & energy_transfer_err2,
                  void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        std::string errstr("AxisManip::energy_transfer: data ");
        Utils::check_sizes_square(errstr, initial_energy, final_energy,
                                  energy_transfer);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    // check that the uncertainties are of proper size
    try
      {
        std::string errstr("AxisManip::energy_transfer: error ");
        Utils::check_sizes_square(errstr, initial_energy_err2,
                                  final_energy_err2, energy_transfer_err2);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT h;
    NumT h2;

    // fill the local variables
    warn=__energy_transfer_static(h,h2);
    if(!(warn.empty()))
      retstr+=warn;

    // do the calculation
    size_t size_energy = initial_energy.size();
    for (size_t i = 0; i < size_energy ; ++i )
      {
        warn=__energy_transfer_dynamic(initial_energy[i],
                                       initial_energy_err2[i],
                                       final_energy[i],
                                       final_energy_err2[i],
                                       h, h2,
                                       energy_transfer[i],
                                       energy_transfer_err2[i]);
        if(!(warn.empty()))
          retstr+=warn;
      }

    return retstr;
  }

  template <typename NumT>
    std::string
    energy_transfer(const Nessi::Vector<NumT> & initial_energy,
		    const Nessi::Vector<NumT> & initial_energy_err2,
		    const NumT final_energy,
		    const NumT final_energy_err2,
		    Nessi::Vector<NumT> & energy_transfer,
		    Nessi::Vector<NumT> & energy_transfer_err2,
		    void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        std::string errstr("AxisManip::energy_transfer: data ");
        Utils::check_sizes_square(errstr, initial_energy, energy_transfer);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    // check that the uncertainties are of proper size
    try
      {
        std::string errstr("AxisManip::energy_transfer: error ");
        Utils::check_sizes_square(errstr, initial_energy_err2,
                                  energy_transfer_err2);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT h;
    NumT h2;

    // fill the local variables
    warn=__energy_transfer_static(h,h2);
    if(!(warn.empty()))
      retstr+=warn;

    // do the calculation
    size_t size_energy = initial_energy.size();
    for (size_t i = 0; i < size_energy ; ++i )
      {
        warn=__energy_transfer_dynamic(initial_energy[i],
                                       initial_energy_err2[i],
                                       final_energy,
                                       final_energy_err2,
                                       h, h2,
                                       energy_transfer[i],
                                       energy_transfer_err2[i]);
        if(!(warn.empty()))
          retstr+=warn;
        // START REMOVE
        energy_transfer[i] = (initial_energy[i] - final_energy)
          / static_cast<NumT>(PhysConst::H);
        energy_transfer_err2[i]
          = (initial_energy_err2[i] + final_energy_err2) / h2;
        // END REMOVE
      }

    return retstr;
  }

  template <typename NumT>
    std::string
    energy_transfer(const NumT initial_energy,
		    const NumT initial_energy_err2,
		    const Nessi::Vector<NumT> & final_energy,
		    const Nessi::Vector<NumT> & final_energy_err2,
		    Nessi::Vector<NumT> & energy_transfer,
		    Nessi::Vector<NumT> & energy_transfer_err2,
		    void *temp=NULL)
  {
    // check that the values are of proper size
    try
      {
        std::string errstr("AxisManip::energy_transfer: data ");
        Utils::check_sizes_square(errstr, final_energy, energy_transfer);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    // check that the uncertainties are of proper size
    try
      {
        std::string errstr("AxisManip::energy_transfer: error ");
        Utils::check_sizes_square(errstr, final_energy_err2,
                                  energy_transfer_err2);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT h;
    NumT h2;

    // fill the local variables
    warn=__energy_transfer_static(h,h2);
    if(!(warn.empty()))
      retstr+=warn;

    // do the calculation
    size_t size_energy = final_energy.size();
    for (size_t i = 0; i < size_energy ; ++i )
      {
        warn=__energy_transfer_dynamic(initial_energy,
                                       initial_energy_err2,
                                       final_energy[i],
                                       final_energy_err2[i],
                                       h, h2,
                                       energy_transfer[i],
                                       energy_transfer_err2[i]);
        if(!(warn.empty()))
          retstr+=warn;
        // START REMOVE
        energy_transfer[i] = (initial_energy - final_energy[i])
          / static_cast<NumT>(PhysConst::H);
        energy_transfer_err2[i]
          = (initial_energy_err2 + final_energy_err2[i]) / h2;
        // END REMOVE
      }

    return retstr;
  }

  template <typename NumT>
    std::string
    energy_transfer(const NumT initial_energy,
		    const NumT initial_energy_err2,
		    const NumT final_energy,
		    const NumT final_energy_err2,
		    NumT & energy_transfer,
		    NumT & energy_transfer_err2,
		    void *temp=NULL)
  {
    std::string retstr(""); // the warning string
    std::string warn;       // the temporary warning string

    // allocate local variables
    NumT h;
    NumT h2;

    // fill the local variables
    warn=__energy_transfer_static(h,h2);
    if(!(warn.empty()))
      retstr+=warn;

    // do the calculation
    warn=__energy_transfer_dynamic(initial_energy, initial_energy_err2,
                                   final_energy, final_energy_err2,
                                   h, h2,
                                   energy_transfer, energy_transfer_err2);
    if(!(warn.empty()))
      retstr+=warn;

    return retstr;
  }

  /**
   * This is a PRIVATE helper function for energy_transfer that
   * calculates parameters invariant across array calculation.
   */
  template <typename NumT>
    std::string
    __energy_transfer_static(NumT & h,
                             NumT & h2)
  {
    h=static_cast<NumT>(PhysConst::H);
    h2=h*h;

    return std::string("");
  }

  /**
   * This is a PRIVATE helper function for energy_transfer that
   * calculates the energy_transfer and its uncertainty
   */
  template <typename NumT>
    std::string
    __energy_transfer_dynamic(const NumT initial_energy,
                              const NumT initial_energy_err2,
                              const NumT final_energy,
                              const NumT final_energy_err2,
                              const NumT h,
                              const NumT h2,
                              NumT & energy_transfer,
                              NumT & energy_transfer_err2)
  {
    // the result
    energy_transfer = (initial_energy - final_energy) / h;

    // the uncertainty in the result
    energy_transfer_err2 = (initial_energy_err2 + final_energy_err2) / h2;

    return std::string("");
  }
} // AxisManip
#endif
