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
// phys_corr.i - SWIG interface
//
// $Id$
//
%module phys_corr_bind
%{
#include "physcorr.hpp"
%}

%include <std_string.i>
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

