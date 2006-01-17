/**
 * $Id$
 *
 * \file utils/src/check_histo_sizes.cpp
 */
#include "check_histo_sizes.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void 
  check_histo_sizes<float>(const Nessi::Vector<float> & input,
			   const Nessi::Vector<float> & input_err2,
			   const Nessi::Vector<float> & axis);

  /**
   * This is the double declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void 
  check_histo_sizes<double>(const Nessi::Vector<double> & input,
			    const Nessi::Vector<double> & input_err2,
			    const Nessi::Vector<double> & axis);

  /**
   * This is the integer declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void 
  check_histo_sizes<int>(const Nessi::Vector<int> & input,
			 const Nessi::Vector<int> & input_err2,
			 const Nessi::Vector<int> & axis);
  
  /**
   * This is the unsigned integer declaration of the check_histo_sizes function
   *
   * \ingroup check_histo_sizes
   */
  template void 
  check_histo_sizes<unsigned int>(const Nessi::Vector<unsigned int> & input,
				  const Nessi::Vector<unsigned int> & input_err2,
				  const Nessi::Vector<unsigned int> & axis); 

} // Utils
