/**
 * $Id$
 *
 * \file axis_manip/src/energy_transfer.cpp
 */
#include "conversions.hpp"
#include "constants.hpp"
#include <string>
#include <vector>

namespace AxisManip
{
  // 3.30
  template <typename NumT>
  std::string
  energy_transfer(std::vector<NumT> const & initial_energy,
		    std::vector<NumT> const & initial_energy_err2,
		    std::vector<NumT> const & final_energy,
		    std::vector<NumT> const & final_energy_err2,
		    std::vector<NumT> & energy_transfer,
		    std::vector<NumT> & energy_transfer_err2,
		    void *temp=NULL)
  {
    std::string retstr("");

    size_t sz1 = initial_energy.size();
    size_t sz2 = final_energy.size();

    // FIXME
    // Need a zero length check for all vectors

    NumT h2 = static_cast<NumT>(PhysConst::H) * 
      static_cast<NumT>(PhysConst::H);

    if (sz1 == 1 && sz2 != 1)
      {
	for (size_t i = 0; i < sz2; ++i)
	  {
	    energy_transfer[i] = (initial_energy[0] - final_energy[i]) / 
	      static_cast<NumT>(PhysConst::H);
	    energy_transfer_err2[i] = (initial_energy_err2[0] + final_energy_err2[i]) / h2;
	  }
      }
    else if (sz1 != 1 && sz2 == 1)
      {
	for (size_t i = 0; i < sz1; ++i)
	  {
	    energy_transfer[i] = (initial_energy[i] - final_energy[0]) / 
	      static_cast<NumT>(PhysConst::H);
	    energy_transfer_err2[i] = (initial_energy_err2[i] + final_energy_err2[0]) / h2;
	  }
      }
    else if (sz1 == 1 && sz2 == 1)
      {
	energy_transfer[0] = (initial_energy[0] - final_energy[0]) / 
	  static_cast<NumT>(PhysConst::H);
	energy_transfer_err2[0] = (initial_energy_err2[0] + final_energy_err2[0]) / h2;
      }
    else
      {
	for (size_t i = 0; i < sz1; ++i)
	  {
	    energy_transfer[i] = (initial_energy[i] - final_energy[i]) / 
	      static_cast<NumT>(PhysConst::H);
	    energy_transfer_err2[i] = (initial_energy_err2[i] + final_energy_err2[i]) / h2;
	  }
      }

    return retstr;
  }

  // explicit instantiations

  /**
   * This is the float declaration of the function defined in 3.30.
   *
   * \see energy_transfer()
   */
  template std::string
  energy_transfer<float>(std::vector<float> const & initial_energy,
			 std::vector<float> const & initial_energy_err2,
			 std::vector<float> const & final_energy,
			 std::vector<float> const & final_energy_err2,
			 std::vector<float> & energy_transfer,
			 std::vector<float> & energy_transfer_err2,
			 void *temp);
  
  /**
   * This is the double precision float declaration of the function
   * defined in 3.30.
   *
   * \see energy_transfer()
   */
  template std::string
  energy_transfer<double>(std::vector<double> const & initial_energy,
			  std::vector<double> const & initial_energy_err2,
			  std::vector<double> const & final_energy,
			  std::vector<double> const & final_energy_err2,
			  std::vector<double> & energy_transfer,
			  std::vector<double> & energy_transfer_err2,
			  void *temp);
  
  /**
   * This is the integer declaration of the function defined in 3.30.
   *
   * \see energy_transfer()
   */
  template std::string
  energy_transfer<int>(std::vector<int> const & initial_energy,
		       std::vector<int> const & initial_energy_err2,
		       std::vector<int> const & final_energy,
		       std::vector<int> const & final_energy_err2,
		       std::vector<int> & energy_transfer,
		       std::vector<int> & energy_transfer_err2,
		       void *temp);
  
  /**
   * This is the unsigned integer declaration of the function defined
   * in 3.30.
   *
   * \see energy_transfer()
   */
  template std::string
  energy_transfer<unsigned int>(
                         std::vector<unsigned int> const & initial_energy,
                         std::vector<unsigned int> const & initial_energy_err2,
                         std::vector<unsigned int> const & final_energy,
                         std::vector<unsigned int> const & final_energy_err2,
                         std::vector<unsigned int> & energy_transfer,
                         std::vector<unsigned int> & energy_transfer_err2,
                         void *temp);
  
} // AxisManip
