// utils.i - SWIG interface
//
// $Id$
//
%module utils
%{
#include "utils.hpp"
%}

%include "libexcept.i"

// Parse the original header file
%include "utils.hpp"

// Instantiate templates

%template(peak_integration_f) Utils::peak_integration<float>;
%template(peak_integration_d) Utils::peak_integration<double>;
%template(peak_integration_i) Utils::peak_integration<int>;
%template(peak_integration_u) Utils::peak_integration<unsigned>;

%template(matrix_multiplication_f) Utils::matrix_multiplication<float>;
%template(matrix_multiplication_d) Utils::matrix_multiplication<double>;
%template(matrix_multiplication_i) Utils::matrix_multiplication<int>;
%template(matrix_multiplication_u) Utils::matrix_multiplication<unsigned>;

%template(fit_reflectometer_background_f) Utils::fit_reflectometer_background<float>;
%template(fit_reflectometer_background_d) Utils::fit_reflectometer_background<double>;
%template(fit_reflectometer_background_i) Utils::fit_reflectometer_background<int>;
%template(fit_reflectometer_background_u) Utils::fit_reflectometer_background<unsigned>;

%template(fit_linear_background_f) Utils::fit_linear_background<float>;
%template(fit_linear_background_d) Utils::fit_linear_background<double>;
%template(fit_linear_background_i) Utils::fit_linear_background<int>;
%template(fit_linear_background_u) Utils::fit_linear_background<unsigned>;

