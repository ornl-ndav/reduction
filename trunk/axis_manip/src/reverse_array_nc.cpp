/**
 * $Id$
 *
 * \file axis_manip/src/reverse_array_nc.cpp
 */
#include "reverse_array_nc.hpp"

namespace AxisManip
{
  // explicit instantiations

  /**
   * This is the float declaration for the function defined in 3.11.
   *
   * \ingroup reverse_array_nc
   */
  template std::string
  reverse_array_nc<float>(Nessi::Vector<float> & inout,
                          void *temp);

  /**
   * This is the double precision float declaration for the function
   * defined in 3.11.
   *
   * \ingroup reverse_array_nc
   */
  template std::string
  reverse_array_nc<double>(Nessi::Vector<double> & inout,
                           void *temp);

  /**
   * This is the integer declaration for the function defined in 3.11.
   *
   * \ingroup reverse_array_nc
   */
  template std::string
  reverse_array_nc<int>(Nessi::Vector<int> & inout,
                        void *temp);

  /**
   * This is the unsigned integer declaration for the function defined
   * in 3.11.
   *
   * \ingroup reverse_array_nc
   */
  template std::string
  reverse_array_nc<unsigned int>(Nessi::Vector<unsigned int> & inout,
                                 void *temp);

} // AxisManip
