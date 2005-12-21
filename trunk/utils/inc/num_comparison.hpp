#ifndef _NUM_COMPARISON_H
#define _NUM_COMPARISON_H

#include "nessi.hpp"
#include <iostream>
#include <cmath>

namespace Utils
{
  template <typename NumT>
  void
  fd_comparison (Nessi::Vector<NumT> const & value,
		 Nessi::Vector<NumT> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);

  template <typename NumT>
  void
  iu_comparison (Nessi::Vector<NumT> const & value,
		 Nessi::Vector<NumT> const & true_value,
		 int & error,
		 const int add_error,
		 const int n_max);
  
}

#endif    //_NUM_COMPARISON_H
