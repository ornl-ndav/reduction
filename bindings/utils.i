// utils.i - SWIG interface
//
// $Id$
//
%module utils_bind
%{
#include "num_comparison.hpp"
#include "size_checks.hpp"
#include "utils.hpp"
%}

%include "libexcept.i"

// Need to ignore guard names from header files
%ignore _NUM_COMPARISON_HPP;
%ignore _SIZE_CHECKS_HPP;
%ignore _UTILS_HPP;

// Parse the original header file
%include "num_comparison.hpp"
%include "size_checks.hpp"
%include "utils.hpp"

// Instantiate templates for number comparisons
%template(vector_is_equals_d) Utils::vector_is_equals<double>;
%template(vector_is_equals_i) Utils::vector_is_equals<int>;

// Instantiate templates for size checks

%template(check_sizes_square_d) Utils::check_sizes_square<double>;
%template(check_sizes_square_i) Utils::check_sizes_square<int>;

%template(check_histo_sizes_d) Utils::check_histo_sizes<double>;
%template(check_histo_sizes_i) Utils::check_histo_sizes<int>;

// Instantiate templates for utils

%template(peak_integration_d) Utils::peak_integration<double>;

%template(matrix_multiplication_d) Utils::matrix_multiplication<double>;
%template(matrix_multiplication_i) Utils::matrix_multiplication<int>;

%template(fit_reflectometer_background_d) Utils::fit_reflectometer_background<double>;

%template(fit_linear_background_d) Utils::fit_linear_background<double>;

%template(weighted_average_d) Utils::weighted_average<double>;

