/**
 * $Id$
 *
 * \file axis_manip/src/check_histo_sizes.cpp
 */
#include "check_histo_sizes.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<float>(std::string & errstr,
			   std::vector<float> const & input,
			   std::vector<float> const & input_err2,
			   std::vector<float> const & axis);

  /**
   * This is the double declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<double>(std::string & errstr,
			    std::vector<double> const & input,
			    std::vector<double> const & input_err2,
			    std::vector<double> const & axis);

  /**
   * This is the int declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<int>(std::string & errstr,
			 std::vector<int> const & input,
			 std::vector<int> const & input_err2,
			 std::vector<int> const & axis);
  
  /**
   * This is the unsigned declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<unsigned>(std::string & errstr,
			      std::vector<unsigned> const & input,
			      std::vector<unsigned> const & input_err2,
			      std::vector<unsigned> const & axis); 

} // AxisManip
