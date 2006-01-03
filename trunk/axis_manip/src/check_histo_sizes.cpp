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
			   const Nessi::Vector<float> & input,
			   const Nessi::Vector<float> & input_err2,
			   const Nessi::Vector<float> & axis);

  /**
   * This is the double declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<double>(std::string & errstr,
			    const Nessi::Vector<double> & input,
			    const Nessi::Vector<double> & input_err2,
			    const Nessi::Vector<double> & axis);

  /**
   * This is the int declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<int>(std::string & errstr,
			 const Nessi::Vector<int> & input,
			 const Nessi::Vector<int> & input_err2,
			 const Nessi::Vector<int> & axis);
  
  /**
   * This is the unsigned declaration of the check_histo_sizes function
   *
   * \see check_histo_sizes()
   */
  template void 
  check_histo_sizes<unsigned>(std::string & errstr,
			      const Nessi::Vector<unsigned> & input,
			      const Nessi::Vector<unsigned> & input_err2,
			      const Nessi::Vector<unsigned> & axis); 

} // AxisManip
