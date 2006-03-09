// array_manip.i - SWIG interface
//
// $Id$
//
%module array_manip_bind
%{
#include "arith.hpp"
%}

%include <std_string.i>
%include "libexcept.i"

// Need to ignore guard names from header files
%ignore _ARITH_HPP;

// Parse the original header file
%include "arith.hpp"

// Instantiate some templates

%template(add_ncerr_d) ArrayManip::add_ncerr<double>;
%template(add_ncerr_i) ArrayManip::add_ncerr<int>;

%template(sub_ncerr_d) ArrayManip::sub_ncerr<double>;
%template(sub_ncerr_i) ArrayManip::sub_ncerr<int>;

%template(mult_ncerr_d) ArrayManip::mult_ncerr<double>;
%template(mult_ncerr_i) ArrayManip::mult_ncerr<int>;

%template(div_ncerr_d) ArrayManip::div_ncerr<double>;
%template(div_ncerr_i) ArrayManip::div_ncerr<int>;

%template(sumw_ncerr_d) ArrayManip::sumw_ncerr<double>;
%template(sumw_ncerr_i) ArrayManip::sumw_ncerr<int>;
