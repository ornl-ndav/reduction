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
// array_manip.i - SWIG interface
//
// $Id$
//
%module array_manip_bind
%{
#include "arith.hpp"
#include "vpair.hpp"
%}

%include <std_string.i>
%include "libexcept.i"

// Need to ignore guard names from header files
%ignore _ARITH_HPP;

// Parse the original header file
%include "arith.hpp"

// Instantiate some templates

%template(abs_val_d) ArrayManip::abs_val<double>;
%template(abs_val_i) ArrayManip::abs_val<int>;

%template(add_ncerr_d) ArrayManip::add_ncerr<double>;

%{
std::string add_ncerr_ss_d(const double input1, const double input1_err2, const double input2, const double input2_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = ArrayManip::add_ncerr(input1, input1_err2, input2, input2_err2, value.val, value.val_err2,temp);
  return ret;
}
%}

std::string add_ncerr_ss_d(const double input1, const double input1_err2, const double input2, const double input2_err2, VPair<double> & value, void *temp=NULL);

%template(add_ncerr_i) ArrayManip::add_ncerr<int>;

%{
std::string add_ncerr_ss_i(const int input1, const int input1_err2, const int input2, const int input2_err2, VPair<int> & value, void *temp=NULL) {
  std::string ret = ArrayManip::add_ncerr(input1, input1_err2, input2, input2_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string add_ncerr_ss_i(const int input1, const int input1_err2, const int input2, const int input2_err2, VPair<int> & value, void *temp=NULL);

%template(sub_ncerr_d) ArrayManip::sub_ncerr<double>;
%template(sub_ncerr_i) ArrayManip::sub_ncerr<int>;

%template(mult_ncerr_d) ArrayManip::mult_ncerr<double>;
%template(mult_ncerr_i) ArrayManip::mult_ncerr<int>;

%template(div_ncerr_d) ArrayManip::div_ncerr<double>;
%template(div_ncerr_i) ArrayManip::div_ncerr<int>;

%template(sumw_ncerr_d) ArrayManip::sumw_ncerr<double>;
%template(sumw_ncerr_i) ArrayManip::sumw_ncerr<int>;
