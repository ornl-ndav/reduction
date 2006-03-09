// array_manip.i - SWIG interface
//
// $Id$
//
%module array_manip_bind
%{
#include "arith.hpp"
%}

%include "libexcept.i"

// Need to ignore guard names from header files
%ignore _ARITH_HPP;

// Parse the original header file
%include "arith.hpp"

// Instantiate some templates

%template(add_ncerr_f) ArrayManip::add_ncerr<float>;
%template(add_ncerr_d) ArrayManip::add_ncerr<double>;
%template(add_ncerr_i) ArrayManip::add_ncerr<int>;
%template(add_ncerr_u) ArrayManip::add_ncerr<unsigned>;

%template(sub_ncerr_f) ArrayManip::sub_ncerr<float>;
%template(sub_ncerr_d) ArrayManip::sub_ncerr<double>;
%template(sub_ncerr_i) ArrayManip::sub_ncerr<int>;
%template(sub_ncerr_u) ArrayManip::sub_ncerr<unsigned>;

%template(mult_ncerr_f) ArrayManip::mult_ncerr<float>;
%template(mult_ncerr_d) ArrayManip::mult_ncerr<double>;
%template(mult_ncerr_i) ArrayManip::mult_ncerr<int>;
%template(mult_ncerr_u) ArrayManip::mult_ncerr<unsigned>;

%template(div_ncerr_f) ArrayManip::div_ncerr<float>;
%template(div_ncerr_d) ArrayManip::div_ncerr<double>;
%template(div_ncerr_i) ArrayManip::div_ncerr<int>;
%template(div_ncerr_u) ArrayManip::div_ncerr<unsigned>;

%template(sumw_ncerr_f) ArrayManip::sumw_ncerr<float>;
%template(sumw_ncerr_d) ArrayManip::sumw_ncerr<double>;
%template(sumw_ncerr_i) ArrayManip::sumw_ncerr<int>;
%template(sumw_ncerr_u) ArrayManip::sumw_ncerr<unsigned>;