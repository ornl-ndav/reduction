/**
 * $Id$
 *
 * \file axis_manip/src/reverse_array_cp.cpp
 */
#include "reverse_array_cp.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration for the function defined in 3.11.
   *
   * \see reverse_array_cp()
   */
  template std::string 
  reverse_array_cp<float>(Nessi::Vector<float> const & input,
                          Nessi::Vector<float> & output,
                          void *temp);
  
  /**
   * This is the double precision float declaration for the function
   * defined in 3.11.
   *
   * \see reverse_array_cp()
   */
  template std::string 
  reverse_array_cp<double>(Nessi::Vector<double> const & input,
                           Nessi::Vector<double> & output,
                           void *temp);
  
  /**
   * This is the integer declaration for the function defined in 3.11.
   *
   * \see reverse_array_cp()
   */
  template std::string 
  reverse_array_cp<int>(Nessi::Vector<int> const & input,
                        Nessi::Vector<int> & output,
                        void *temp);
  
  /**
   * This is the unsigned integer declaration for the function defined
   * in 3.11.
   *
   * \see reverse_array_cp()
   */
  template std::string 
  reverse_array_cp<unsigned int>(Nessi::Vector<unsigned int> const & input,
                                 Nessi::Vector<unsigned int> & output,
                                 void *temp);
  
} // AxisManip
