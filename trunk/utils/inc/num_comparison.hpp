#ifndef _NUM_COMPARISON_H
#define _NUM_COMPARISON_H

#include "nessi.hpp"
#include <iostream>
#include <cmath>

namespace Utils
{
  void vector_comparison (Nessi::Vector<int> const & value,
                          Nessi::Vector<int> const & true_value,
                          int & error,
                          const int add_error,
                          const int n_max);

  void vector_comparison (Nessi::Vector<unsigned int> const & value,
                          Nessi::Vector<unsigned int> const & true_value,
                          int & error,
                          const int add_error,
                          const int n_max);

  void vector_comparison (Nessi::Vector<float> const & value,
                          Nessi::Vector<float> const & true_value,
                          int & error,
                          const int add_error,
                          const int n_max);

  void vector_comparison (Nessi::Vector<double> const & value,
                          Nessi::Vector<double> const & true_value,
                          int & error,
                          const int add_error,
                          const int n_max);
}

#endif    //_NUM_COMPARISON_H
