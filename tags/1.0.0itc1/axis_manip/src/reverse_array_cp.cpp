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
   * \ingroup reverse_array_cp
   */
  template std::string 
  reverse_array_cp<float>(const Nessi::Vector<float> & input,
                          Nessi::Vector<float> & output,
                          void *temp);
  
  /**
   * This is the double precision float declaration for the function
   * defined in 3.11.
   *
   * \ingroup reverse_array_cp
   */
  template std::string 
  reverse_array_cp<double>(const Nessi::Vector<double> & input,
                           Nessi::Vector<double> & output,
                           void *temp);
  
  /**
   * This is the integer declaration for the function defined in 3.11.
   *
   * \ingroup reverse_array_cp
   */
  template std::string 
  reverse_array_cp<int>(const Nessi::Vector<int> & input,
                        Nessi::Vector<int> & output,
                        void *temp);
  
  /**
   * This is the unsigned integer declaration for the function defined
   * in 3.11.
   *
   * \ingroup reverse_array_cp
   */
  template std::string 
  reverse_array_cp<unsigned int>(const Nessi::Vector<unsigned int> & input,
                                 Nessi::Vector<unsigned int> & output,
                                 void *temp);
  
} // AxisManip
