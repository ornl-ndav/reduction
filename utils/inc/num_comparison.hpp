/**
 * $Id$
 *
 * \file utils/inc/num_comparison.hpp
 */
#ifndef _NUM_COMPARISON_HPP
#define _NUM_COMPARISON_HPP 1

#include "nessi.hpp"

namespace Utils
{
  template <typename NumT> 
    void 
    vector_comparison (const Nessi::Vector<NumT> & value,
		     const Nessi::Vector<NumT> & true_value,
		     int & error,
		     const int add_error);
  
  void vector_comparison (const Nessi::Vector<float> & value,
                          const Nessi::Vector<float> & true_value,
                          int & error,
                          const int add_error);
  
  void vector_comparison (const Nessi::Vector<double> & value,
                          const Nessi::Vector<double> & true_value,
                          int & error,
                          const int add_error);
  
  template <typename NumT>
    bool
    is_equals(const NumT & value1,
	      const NumT & value2);

  bool is_equals (const float & value1,
		  const float & value2);

  bool is_equals (const double & value1,
		  const double & value2);
}

#endif // _NUM_COMPARISON_HPP
