// utils.i - SWIG interface
//
// $Id$
//
%module utils_bind
%{
#include "utils.hpp"
#include "size_checks.hpp"
%}

%include "libexcept.i"

// Parse the original header file
%include "utils.hpp"
%include "size_checks.hpp"

// Instantiate templates for size checks

%template(check_sizes_square_f) Utils::check_sizes_square<float>;
%template(check_sizes_square_d) Utils::check_sizes_square<double>;
%template(check_sizes_square_i) Utils::check_sizes_square<int>;
%template(check_sizes_square_u) Utils::check_sizes_square<unsigned>;

%template(check_histo_sizes_f) Utils::check_histo_sizes<float>;
%template(check_histo_sizes_d) Utils::check_histo_sizes<double>;
%template(check_histo_sizes_i) Utils::check_histo_sizes<int>;
%template(check_histo_sizes_u) Utils::check_histo_sizes<unsigned>;

// Instantiate templates

%template(peak_integration_f) Utils::peak_integration<float>;
%template(peak_integration_d) Utils::peak_integration<double>;

%template(matrix_multiplication_f) Utils::matrix_multiplication<float>;
%template(matrix_multiplication_d) Utils::matrix_multiplication<double>;
%template(matrix_multiplication_i) Utils::matrix_multiplication<int>;
%template(matrix_multiplication_u) Utils::matrix_multiplication<unsigned>;

%template(fit_reflectometer_background_f) Utils::fit_reflectometer_background<float>;
%template(fit_reflectometer_background_d) Utils::fit_reflectometer_background<double>;

%template(fit_linear_background_f) Utils::fit_linear_background<float>;
%template(fit_linear_background_d) Utils::fit_linear_background<double>;

