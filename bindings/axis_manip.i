// axis_manip.i - SWIG interface
//
// $Id$
//
%module axis_manip_bind
%{
#include "conversions.hpp"
#include "rebinning.hpp"
#include "reverse_array.hpp"
%}

%include <std_string.i>
%include "libexcept.i"

// Need to ignore guard names from header files
%ignore _CONVERSIONS_HPP;
%ignore _REBINNING_HPP;
%ignore _REVERSE_ARRAY_HPP;

// Parse the original header file
%include "conversions.hpp"
%include "rebinning.hpp"
%include "reverse_array.hpp"

// Instantiate reverse array templates

%template(reverse_array_cp_d) AxisManip::reverse_array_cp<double>;
%template(reverse_array_cp_i) AxisManip::reverse_array_cp<int>;

%template(reverse_array_nc_d) AxisManip::reverse_array_nc<double>;
%template(reverse_array_nc_i) AxisManip::reverse_array_nc<int>;

// Instantiate rebinning templates

%template(rebin_axis_1D_d) AxisManip::rebin_axis_1D<double>;

%template(rebin_axis_2D_d) AxisManip::rebin_axis_2D<double>;

%template(rebin_axis_4D_d) AxisManip::rebin_axis_4D<double>;

// Instantiate conversion templates

%template(tof_to_wavelength_d) AxisManip::tof_to_wavelength<double>;

%template(wavelength_to_tof_d) AxisManip::wavelength_to_tof<double>;

%template(tof_to_scalar_Q_d) AxisManip::tof_to_scalar_Q<double>;

%template(wavelength_to_scalar_Q_d) AxisManip::wavelength_to_scalar_Q<double>;

%template(initial_velocity_dgs_d) AxisManip::initial_velocity_dgs<double>;

%template(final_velocity_igs_d) AxisManip::final_velocity_igs<double>;

%template(velocity_to_energy_d) AxisManip::velocity_to_energy<double>;

%template(wavelength_to_energy_d) AxisManip::wavelength_to_energy<double>;

%template(velocity_to_scalar_k_d) AxisManip::velocity_to_scalar_k<double>;

%template(wavelength_to_scalar_k_d) AxisManip::wavelength_to_scalar_k<double>;

%template(wavelength_to_d_spacing_d) AxisManip::wavelength_to_d_spacing<double>;

%template(time_offset_dgs_d) AxisManip::time_offset_dgs<double>;

%template(tof_to_final_velocity_dgs_d) AxisManip::tof_to_final_velocity_dgs<double>;

%template(tof_to_initial_velocity_igs_d) AxisManip::tof_to_initial_velocity_igs<double>;

%template(tof_to_initial_wavelength_igs_d) AxisManip::tof_to_initial_wavelength_igs<double>;

%template(energy_transfer_d) AxisManip::energy_transfer<double>;

%template(frequency_to_angular_frequency_d) AxisManip::frequency_to_angular_frequency<double>;

%template(init_scatt_wavevector_to_Q_d) AxisManip::init_scatt_wavevector_to_Q<double>;

%template(init_scatt_wavevector_to_scalar_Q_d) AxisManip::init_scatt_wavevector_to_scalar_Q<double>;

%template(tof_to_Q_d) AxisManip::tof_to_Q<double>;

%template(d_spacing_to_tof_focused_det_d) AxisManip::d_spacing_to_tof_focused_det<double>;
