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
			   Nessi::Vector<float> const & input,
			   Nessi::Vector<float> const & input_err2,
			   Nessi::Vector<float> const & axis);

  /**
   * This is the double declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<double>(std::string & errstr,
			    Nessi::Vector<double> const & input,
			    Nessi::Vector<double> const & input_err2,
			    Nessi::Vector<double> const & axis);

  /**
   * This is the int declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<int>(std::string & errstr,
			 Nessi::Vector<int> const & input,
			 Nessi::Vector<int> const & input_err2,
			 Nessi::Vector<int> const & axis);
  
  /**
   * This is the unsigned declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<unsigned>(std::string & errstr,
			      Nessi::Vector<unsigned> const & input,
			      Nessi::Vector<unsigned> const & input_err2,
			      Nessi::Vector<unsigned> const & axis); 

} // AxisManip
