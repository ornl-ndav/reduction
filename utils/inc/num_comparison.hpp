/**
 * $Id$
 *
 * \file utils/inc/num_comparison.hpp
 */
#ifndef _NUM_COMPARISON_HPP
#define _NUM_COMPARISON_HPP 1

#include "nessi.hpp"
#include <iostream>
#include <cmath>

namespace Utils
{
  template <typename NumT> 
    void 
    vector_comparison (const Nessi::Vector<NumT> & value,
                       const Nessi::Vector<NumT> & true_value,
                       int & error,
                       const int add_error,
                       const int n_max);

  /*
  void vector_comparison (const Nessi::Vector<int> & value,
                          const Nessi::Vector<int> & true_value,
                          int & error,
                          const int add_error,
                          const int n_max);

  void vector_comparison (const Nessi::Vector<unsigned int> & value,
                          const Nessi::Vector<unsigned int> & true_value,
                          int & error,
                          const int add_error,
                          const int n_max);
  */

  void vector_comparison (const Nessi::Vector<float> & value,
                          const Nessi::Vector<float> & true_value,
                          int & error,
                          const int add_error,
                          const int n_max);

  void vector_comparison (const Nessi::Vector<double> & value,
                          const Nessi::Vector<double> & true_value,
                          int & error,
                          const int add_error,
                          const int n_max);
}

#endif // _NUM_COMPARISON_HPP
