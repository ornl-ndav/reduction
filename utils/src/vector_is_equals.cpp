/**
 * $Id$
 *
 * \file utils/src/vector_is_equals.cpp
 */
#include "vector_is_equals.hpp"

namespace Utils
{
  // explicit instantiations

  /**
   * This is the float declaration of the vector_is_equals function.
   *
   * \ingroup vector_is_equals
   */
  template bool
  vector_is_equals<float>(const Nessi::Vector<float> & value,
                          const Nessi::Vector<float> & true_value);

  /**
   * This is the double declaration of the vector_is_equals function.
   *
   * \ingroup vector_is_equals
   */
  template bool
  vector_is_equals<double>(const Nessi::Vector<double> & value,
                           const Nessi::Vector<double> & true_value);

  /**
   * This is the integer declaration of the vector_is_equals function.
   *
   * \ingroup vector_is_equals
   */
  template bool
  vector_is_equals<int>(const Nessi::Vector<int> & value,
                        const Nessi::Vector<int> & true_value);

  /**
   * This is the unsigned integer declaration of the vector_is_equals
   * function.
   *
   * \ingroup vector_is_equals
   */
  template bool
  vector_is_equals<unsigned int>(
                               const Nessi::Vector<unsigned int> & value,
                               const Nessi::Vector<unsigned int> & true_value);

} // Utils
