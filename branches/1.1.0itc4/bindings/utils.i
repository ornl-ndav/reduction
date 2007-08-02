//                     SNS Common Libraries
//           A part of the SNS Analysis Software Suite.
//
//                  Spallation Neutron Source
//          Oak Ridge National Laboratory, Oak Ridge TN.
//
//
//                             NOTICE
//
// For this software and its associated documentation, permission is granted
// to reproduce, prepare derivative works, and distribute copies to the public
// for any purpose and without fee.
//
// This material was prepared as an account of work sponsored by an agency of
// the United States Government.  Neither the United States Government nor the
// United States Department of Energy, nor any of their employees, makes any
// warranty, express or implied, or assumes any legal liability or
// responsibility for the accuracy, completeness, or usefulness of any
// information, apparatus, product, or process disclosed, or represents that
// its use would not infringe privately owned rights.
//
// utils.i - SWIG interface
//
// $Id$
//
%module utils_bind
%{
#include "num_comparison.hpp"
#include "size_checks.hpp"
#include "utils.hpp"
#include "vpair.hpp"
%}

%include <std_string.i>
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

%template(calc_bin_centers_d) Utils::calc_bin_centers<double>;

%template(calc_bin_widths_d) Utils::calc_bin_widths<double>;

%template(peak_integration_d) Utils::peak_integration<double>;

%template(matrix_multiplication_d) Utils::matrix_multiplication<double>;
%template(matrix_multiplication_i) Utils::matrix_multiplication<int>;

%template(fit_reflectometer_background_d) Utils::fit_reflectometer_background<double>;

%{
std::string fit_linear_background_d(const Nessi::Vector<double> & axis_in, const Nessi::Vector<double> & input, const Nessi::Vector<double> & input_err2, const std::size_t min_bin, const std::size_t max_bin, VPair<double> & slope, VPair<double> & intercept, void *temp=NULL) {
std::string ret = Utils::fit_linear_background(axis_in, input, input_err2, min_bin, max_bin, slope.val, slope.val_err2, intercept.val, intercept.val_err2, temp);
return ret;
}
%}

std::string fit_linear_background_d(const Nessi::Vector<double> & axis_in, const Nessi::Vector<double> & input, const Nessi::Vector<double> & input_err2, const std::size_t min_bin, const std::size_t max_bin, VPair<double> & slope, VPair<double> & intercept);

%template(linear_order_jacobian_d) Utils::linear_order_jacobian<double>;

%{
std::string linear_order_jacobian_ss_d(const double orig_axis_lo, const double orig_axis_hi, const double transform_axis_lo, const double transform_axis_hi, const double input, const double input_err2, VPair<double> & output, void *temp=NULL) {
std::string ret = Utils::linear_order_jacobian(orig_axis_lo, orig_axis_hi, transform_axis_lo, transform_axis_hi, input, input_err2, output.val, output.val_err2, temp);
return ret;
}
%}

std::string linear_order_jacobian_ss_d(const double orig_axis_lo, const double orig_axis_hi, const double transform_axis_lo, const double transform_axis_hi, const double input, const double input_err2, VPair<double> & output);

%{
std::string weighted_average_d(const Nessi::Vector<double> & input, const Nessi::Vector<double> & input_err2, const std::size_t bin_start, const std::size_t bin_end, VPair<double> & value, void *temp=NULL) {
std::string ret = Utils::weighted_average(input, input_err2, bin_start, bin_end, value.val, value.val_err2, temp);
return ret;
}
%}

std::string weighted_average_d(const Nessi::Vector<double> & input, const Nessi::Vector<double> & input_err2, const std::size_t bin_start, const std::size_t bin_end, VPair<double> & value);

