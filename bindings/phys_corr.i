// phys_corr.i - SWIG interface
//
// $Id$
//
%module phys_corr
%{
#include "physcorr.hpp"
%}

%include "libexcept.i"

// Parse the original header file
%include "physcorr.hpp"

// Instantiate templates

%template(absorption_mult_scatt_f) PhysCorr::absorption_mult_scatt<float>;
%template(absorption_mult_scatt_d) PhysCorr::absorption_mult_scatt<double>;

%template(dead_time_corr_f) PhysCorr::dead_time_corr<float>;
%template(dead_time_corr_d) PhysCorr::dead_time_corr<double>;
%template(dead_time_corr_i) PhysCorr::dead_time_corr<int>;
%template(dead_time_corr_u) PhysCorr::dead_time_corr<unsigned>;

%template(inelastic_scatt_corr_f) PhysCorr::inelastic_scatt_corr<float>;
%template(inelastic_scatt_corr_d) PhysCorr::inelastic_scatt_corr<double>;

%template(incoherent_scatt_corr_f) PhysCorr::incoherent_scatt_corr<float>;
%template(incoherent_scatt_corr_d) PhysCorr::incoherent_scatt_corr<double>;

