/**
 * $Id$
 *
 * \file utils/src/compare.cpp
 */
#include "compare.hpp"
#include <cmath>
#include <limits>

namespace Utils
{
  // specialized function for float

  /**
   * This is the float declaration of the compare function.
   *
   * \ingroup compare
   */
  int compare(const float & value1,
	      const float & value2)
  {
    if(!(fabs(value1 - value2) > std::numeric_limits<float>::epsilon()))
      return 0;
    else 
      {
	if(value1 > value2)
	  return 1;
	else
	  return -1;
      }
  }

  // specialized function for double

  /**
   * This is the double declaration of the compare function.
   *
   * \ingroup compare
   */
  int compare(const double & value1,
	      const double & value2)
  {
    if(!(fabs(value1 - value2) > std::numeric_limits<double>::epsilon()))
      return 0;
    else 
      {
	if(value1 > value2)
	  return 1;
	else
	  return -1;
      }
  }

  // explicit instantiations

  /**
   * This is the integer declaration of the compare function.
   *
   * \ingroup compare
   */
  template int
  compare<int>(const int & value1,
	       const int & value2);

  /**
   * This is the unsigned integer declaration of the compare function.
   *
   * \ingroup compare
   */
  template int
  compare<unsigned int>(const unsigned int & value1,
			const unsigned int & value2);

} // Utils
