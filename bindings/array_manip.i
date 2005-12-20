// array_manip.i - SWIG interface
//
// $Id$
//
%module array_manip_bind
%{
#include "vec_scalar_arith.hpp"
#include "vec_vec_arith.hpp"
#include "check_inputs.hpp"
%}

%include "libexcept.i"

// Parse the original header file
%include "vec_scalar_arith.hpp"
%include "vec_vec_arith.hpp"
%include "check_inputs.hpp"

//template <typename NumT>
//   void check_sizes_2in1out(std::string & errstr, 
//                            std::vector<NumT> const & input1, 
//                            std::vector<NumT> const & input2, 
//                            std::vector<NumT> const & output);

%template(check_sizes_2in1out_f) ArrayManip::check_sizes_2in1out<float>;
%template(check_sizes_2in1out_d) ArrayManip::check_sizes_2in1out<double>;
%template(check_sizes_2in1out_i) ArrayManip::check_sizes_2in1out<int>;
%template(check_sizes_2in1out_u) ArrayManip::check_sizes_2in1out<unsigned>;

// Instantiate some templates

%template(add_scalar_vec_ncerr_f) ArrayManip::add_scalar_vec_ncerr<float>;
%template(add_scalar_vec_ncerr_d) ArrayManip::add_scalar_vec_ncerr<double>;
%template(add_scalar_vec_ncerr_i) ArrayManip::add_scalar_vec_ncerr<int>;
%template(add_scalar_vec_ncerr_u) ArrayManip::add_scalar_vec_ncerr<unsigned>;

%template(sub_scalar_vec_ncerr_f) ArrayManip::sub_scalar_vec_ncerr<float>;
%template(sub_scalar_vec_ncerr_d) ArrayManip::sub_scalar_vec_ncerr<double>;
%template(sub_scalar_vec_ncerr_i) ArrayManip::sub_scalar_vec_ncerr<int>;
%template(sub_scalar_vec_ncerr_u) ArrayManip::sub_scalar_vec_ncerr<unsigned>;

%template(mult_scalar_vec_ncerr_f) ArrayManip::mult_scalar_vec_ncerr<float>;
%template(mult_scalar_vec_ncerr_d) ArrayManip::mult_scalar_vec_ncerr<double>;
%template(mult_scalar_vec_ncerr_i) ArrayManip::mult_scalar_vec_ncerr<int>;
%template(mult_scalar_vec_ncerr_u) ArrayManip::mult_scalar_vec_ncerr<unsigned>;

%template(div_scalar_vec_ncerr_f) ArrayManip::div_scalar_vec_ncerr<float>;
%template(div_scalar_vec_ncerr_d) ArrayManip::div_scalar_vec_ncerr<double>;
%template(div_scalar_vec_ncerr_i) ArrayManip::div_scalar_vec_ncerr<int>;
%template(div_scalar_vec_ncerr_u) ArrayManip::div_scalar_vec_ncerr<unsigned>;

%template(div_vec_scalar_ncerr_f) ArrayManip::div_vec_scalar_ncerr<float>;
%template(div_vec_scalar_ncerr_d) ArrayManip::div_vec_scalar_ncerr<double>;
%template(div_vec_scalar_ncerr_i) ArrayManip::div_vec_scalar_ncerr<int>;
%template(div_vec_scalar_ncerr_u) ArrayManip::div_vec_scalar_ncerr<unsigned>;

%template(add_vec_vec_ncerr_f) ArrayManip::add_vec_vec_ncerr<float>;
%template(add_vec_vec_ncerr_d) ArrayManip::add_vec_vec_ncerr<double>;
%template(add_vec_vec_ncerr_i) ArrayManip::add_vec_vec_ncerr<int>;
%template(add_vec_vec_ncerr_u) ArrayManip::add_vec_vec_ncerr<unsigned>;

%template(sub_vec_vec_ncerr_f) ArrayManip::sub_vec_vec_ncerr<float>;
%template(sub_vec_vec_ncerr_d) ArrayManip::sub_vec_vec_ncerr<double>;
%template(sub_vec_vec_ncerr_i) ArrayManip::sub_vec_vec_ncerr<int>;
%template(sub_vec_vec_ncerr_u) ArrayManip::sub_vec_vec_ncerr<unsigned>;

%template(mult_vec_vec_ncerr_f) ArrayManip::mult_vec_vec_ncerr<float>;
%template(mult_vec_vec_ncerr_d) ArrayManip::mult_vec_vec_ncerr<double>;
%template(mult_vec_vec_ncerr_i) ArrayManip::mult_vec_vec_ncerr<int>;
%template(mult_vec_vec_ncerr_u) ArrayManip::mult_vec_vec_ncerr<unsigned>;

%template(div_vec_vec_ncerr_f) ArrayManip::div_vec_vec_ncerr<float>;
%template(div_vec_vec_ncerr_d) ArrayManip::div_vec_vec_ncerr<double>;
%template(div_vec_vec_ncerr_i) ArrayManip::div_vec_vec_ncerr<int>;
%template(div_vec_vec_ncerr_u) ArrayManip::div_vec_vec_ncerr<unsigned>;

%template(sumw_vec_vec_ncerr_f) ArrayManip::sumw_vec_vec_ncerr<float>;
%template(sumw_vec_vec_ncerr_d) ArrayManip::sumw_vec_vec_ncerr<double>;
%template(sumw_vec_vec_ncerr_i) ArrayManip::sumw_vec_vec_ncerr<int>;
%template(sumw_vec_vec_ncerr_u) ArrayManip::sumw_vec_vec_ncerr<unsigned>;
