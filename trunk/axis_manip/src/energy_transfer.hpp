/**
 * $Id$
 *
 * \file axis_manip/src/energy_transfer.hpp
 */
#include "conversions.hpp"
#include "constants.hpp"

namespace AxisManip
{
  // 3.30
  template <typename NumT>
  std::string
  energy_transfer(Nessi::Vector<NumT> const & initial_energy,
		    Nessi::Vector<NumT> const & initial_energy_err2,
		    Nessi::Vector<NumT> const & final_energy,
		    Nessi::Vector<NumT> const & final_energy_err2,
		    Nessi::Vector<NumT> & energy_transfer,
		    Nessi::Vector<NumT> & energy_transfer_err2,
		    void *temp=NULL)
  {
    size_t size_initial_energy = initial_energy.size();
    size_t size_final_energy = final_energy.size();

    // FIXME
    // Need a zero length check for all vectors

    NumT h2 = static_cast<NumT>(PhysConst::H) * 
      static_cast<NumT>(PhysConst::H);

    if (size_initial_energy == 1 && size_final_energy != 1)
      {
	for (size_t i = 0; i < size_final_energy ; ++i )
	  {
	    energy_transfer[i] = (initial_energy[0] - final_energy[i])
              / static_cast<NumT>(PhysConst::H);
	    energy_transfer_err2[i]
              = (initial_energy_err2[0] + final_energy_err2[i]) / h2;
	  }
      }
    else if (size_initial_energy != 1 && size_final_energy == 1)
      {
	for (size_t i = 0 ; i < size_initial_energy ; ++i)
	  {
	    energy_transfer[i] = (initial_energy[i] - final_energy[0])
	      / static_cast<NumT>(PhysConst::H);
	    energy_transfer_err2[i]
              = (initial_energy_err2[i] + final_energy_err2[0]) / h2;
	  }
      }
    else if (size_initial_energy == 1 && size_final_energy == 1)
      {
	energy_transfer[0] = (initial_energy[0] - final_energy[0]) / 
	  static_cast<NumT>(PhysConst::H);
	energy_transfer_err2[0]
          = (initial_energy_err2[0] + final_energy_err2[0]) / h2;
      }
    else
      {
	for (size_t i = 0; i < size_initial_energy; ++i)
	  {
	    energy_transfer[i] = (initial_energy[i] - final_energy[i])
	      / static_cast<NumT>(PhysConst::H);
	    energy_transfer_err2[i]
              = (initial_energy_err2[i] + final_energy_err2[i]) / h2;
	  }
      }

    std::string retstr("");
    return retstr;
  }
} // AxisManip
