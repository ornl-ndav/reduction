/**
 * $Id$
 *
 * \file utils/src/is_equals.cpp
 */
#include "is_equals.hpp"
#include <cmath>
#include <limits>

namespace Utils
{
  // specialized function for float
  bool is_equals(const float & value1,
		 const float & value2)
  {
    if(fabs(value1 - value2) > std::numeric_limits<float>::epsilon())
      return false;
    else
      return true;
  }

  // specialized function for double
  bool is_equals(const double & value1,
		 const double & value2)
  {
    if(fabs(value1 - value2) > std::numeric_limits<double>::epsilon())
      return false;
    else
      return true;
  }

  // explicit instantiations

  /**
   * \ingroup is_equals
   */
  template bool
  is_equals<int>(const int & value1,
		 const int & value2);

  /**
   * \ingroup is_equals
   */
  template bool
  is_equals<unsigned int>(const unsigned int & value1,
			  const unsigned int & value2);

} // Utils
