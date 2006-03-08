// phys_corr.i - SWIG interface
//
// $Id$
//
%module phys_corr_bind
%{
#include "physcorr.hpp"
%}

%include "libexcept.i"

// Need to ignore guard names from header files
%ignore _PHYS_CORR_HPP;

// Parse the original header file
%include "physcorr.hpp"

// Instantiate templates

%template(absorption_mult_scatt_d) PhysCorr::absorption_mult_scatt<double>;

%template(dead_time_corr_d) PhysCorr::dead_time_corr<double>;
%template(dead_time_corr_i) PhysCorr::dead_time_corr<int>;

%template(inelastic_scatt_corr_d) PhysCorr::inelastic_scatt_corr<double>;

%template(incoherent_scatt_corr_d) PhysCorr::incoherent_scatt_corr<double>;

