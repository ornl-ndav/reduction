/**
 * $Id$
 *
 * \file axis_manip/src/energy_transfer.hpp
 */
#ifndef _ENERGY_TRANSFER_HPP
#define _ENERGY_TRANSFER_HPP 1

#include "conversions.hpp"
#include "check_inputs.hpp"
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
    // SNS-FIXME: move to using helper function

    // check that the values are of proper size
    try
      {
        std::string errstr("AxisManip::energy_transfer: data ");
        ArrayManip::check_sizes_2in1out(errstr, initial_energy,
                                        final_energy, energy_transfer);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    // check that the uncertainties are of proper size
    try
      {
        std::string errstr("AxisManip::energy_transfer: error ");
        ArrayManip::check_sizes_2in1out(errstr, initial_energy_err2,
                                        final_energy_err2,
                                        energy_transfer_err2);
      }
    catch(std::invalid_argument e)
      {
        throw e;
      }

    std::string retstr(""); // the warning strings

    // do the calculation
    size_t size_energy = initial_energy.size();
    for (size_t i = 0; i < size_energy ; ++i )
      {
        energy_transfer[i] = (initial_energy[i] - final_energy[i])
          / static_cast<NumT>(PhysConst::H);
        energy_transfer_err2[i]
          = (initial_energy_err2[i] + final_energy_err2[i]) / h2;
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
    // SNS-FIXME: check for vector sizes
    // SNS-FIXME: move to using helper function

    std::string retstr(""); // the warning strings

    // do the calculation
    size_t size_energy = initial_energy.size();
    for (size_t i = 0; i < size_energy ; ++i )
      {
        energy_transfer[i] = (initial_energy[i] - final_energy)
          / static_cast<NumT>(PhysConst::H);
        energy_transfer_err2[i]
          = (initial_energy_err2[i] + final_energy_err2) / h2;
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
    // SNS-FIXME: check for vector sizes
    // SNS-FIXME: move to using helper function

    std::string retstr(""); // the warning strings

    // do the calculation
    size_t size_energy = final_energy.size();
    for (size_t i = 0; i < size_energy ; ++i )
      {
        energy_transfer[i] = (initial_energy - final_energy[i])
          / static_cast<NumT>(PhysConst::H);
        energy_transfer_err2[i]
          = (initial_energy_err2 + final_energy_err2[i]) / h2;
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
    // SNS-FIXME: check for vector sizes
    // SNS-FIXME: move to using helper function

    std::string retstr(""); // the warning strings

    // do the calculation
    size_t size_energy = final_energy.size();
    for (size_t i = 0; i < size_energy ; ++i )
      {
        energy_transfer[i] = (initial_energy - final_energy[i])
          / static_cast<NumT>(PhysConst::H);
        energy_transfer_err2[i]
          = (initial_energy_err2 + final_energy_err2[i]) / h2;
      }

    return retstr;
  }
} // AxisManip
#endif
