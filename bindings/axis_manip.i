// axis_manip.i - SWIG interface
//
// $Id$
//
%module axis_manip
%{
#include "check_histo.hpp"
#include "conversions.hpp"
#include "rebinning.hpp"
#include "reverse_array.hpp"
%}

%include "libexcept.i"

// Parse the original header file
%include "check_histo.hpp"
%include "conversions.hpp"
%include "rebinning.hpp"
%include "reverse_array.hpp"

// Instantiate reverse array templates
//template <typename NumT> std::string 
//    reverse_array(std::vector<NumT> const & input,
//                  std::vector<NumT> & output,
//                  void *temp=NULL);

%template(reverse_array_cp_f) AxisManip::reverse_array_cp<float>;
%template(reverse_array_cp_d) AxisManip::reverse_array_cp<double>;
%template(reverse_array_cp_i) AxisManip::reverse_array_cp<int>;
%template(reverse_array_cp_u) AxisManip::reverse_array_cp<unsigned>;

%template(reverse_array_nc_f) AxisManip::reverse_array_nc<float>;
%template(reverse_array_nc_d) AxisManip::reverse_array_nc<double>;
%template(reverse_array_nc_i) AxisManip::reverse_array_nc<int>;
%template(reverse_array_nc_u) AxisManip::reverse_array_nc<unsigned>;

// Instantiate check histo templates
%template(check_histo_sizes_f) AxisManip::check_histo_sizes<float>;
%template(check_histo_sizes_d) AxisManip::check_histo_sizes<double>;
%template(check_histo_sizes_i) AxisManip::check_histo_sizes<int>;
%template(check_histo_sizes_u) AxisManip::check_histo_sizes<unsigned>;

// Instantiate rebinning templates
template <typename NumT> std::string 
    rebin_axis_1D(std::vector<NumT> const & axis_in,
		  std::vector<NumT> const & input,
		  std::vector<NumT> const & input_err,
		  std::vector<NumT> const & axis_out,
		  std::vector<NumT> & output,
		  std::vector<NumT> & output_err,
		  void *temp=NULL);

%template(rebin_axis_1D_f) AxisManip::rebin_axis_1D<float>;
%template(rebin_axis_1D_d) AxisManip::rebin_axis_1D<double>;

template <typename NumT> std::string 
    rebin_axis_2D(std::vector<NumT> const & axis_in_1,
		  std::vector<NumT> const & axis_in_2,
		  std::vector<NumT> const & input,
		  std::vector<NumT> const & input_err,
		  std::vector<NumT> const & axis_out_1,
		  std::vector<NumT> const & axis_out_2,
		  std::vector<NumT> & output,
		  std::vector<NumT> & output_err,
		  void *temp=NULL);

%template(rebin_axis_2D_f) AxisManip::rebin_axis_2D<float>;
%template(rebin_axis_2D_d) AxisManip::rebin_axis_2D<double>;

 template <typename NumT> std::string 
    rebin_axis_4D(std::vector<NumT> const & axis_in_1,
		  std::vector<NumT> const & axis_in_2,
		  std::vector<NumT> const & axis_in_3,
		  std::vector<NumT> const & axis_in_4,
		  std::vector<NumT> const & input,
		  std::vector<NumT> const & input_err,
		  std::vector<NumT> const & axis_out_1,
		  std::vector<NumT> const & axis_out_2,
		  std::vector<NumT> const & axis_out_3,
		  std::vector<NumT> const & axis_out_4,
		  std::vector<NumT> & output,
		  std::vector<NumT> & output_err,
		  void *temp=NULL);

%template(rebin_axis_4D_f) AxisManip::rebin_axis_4D<float>;
%template(rebin_axis_4D_d) AxisManip::rebin_axis_4D<double>;

// Instantiate conversion templates

%template(tof_to_wavelength_f) AxisManip::tof_to_wavelength<float>;
%template(tof_to_wavelength_d) AxisManip::tof_to_wavelength<double>;

%template(wavelength_to_tof_f) AxisManip::wavelength_to_tof<float>;
%template(wavelength_to_tof_d) AxisManip::wavelength_to_tof<double>;

%template(tof_to_scalar_Q_f) AxisManip::tof_to_scalar_Q<float>;
%template(tof_to_scalar_Q_d) AxisManip::tof_to_scalar_Q<double>;

%template(wavelength_to_scalar_Q_f) AxisManip::wavelength_to_scalar_Q<float>;
%template(wavelength_to_scalar_Q_d) AxisManip::wavelength_to_scalar_Q<double>;

%template(initial_velocity_dgs_f) AxisManip::initial_velocity_dgs<float>;
%template(initial_velocity_dgs_d) AxisManip::initial_velocity_dgs<double>;

%template(final_velocity_igs_f) AxisManip::final_velocity_igs<float>;
%template(final_velocity_igs_d) AxisManip::final_velocity_igs<double>;

%template(velocity_to_energy_f) AxisManip::velocity_to_energy<float>;
%template(velocity_to_energy_d) AxisManip::velocity_to_energy<double>;

%template(wavelength_to_energy_f) AxisManip::wavelength_to_energy<float>;
%template(wavelength_to_energy_d) AxisManip::wavelength_to_energy<double>;

%template(velocity_to_scalar_k_f) AxisManip::velocity_to_scalar_k<float>;
%template(velocity_to_scalar_k_d) AxisManip::velocity_to_scalar_k<double>;

%template(wavelength_to_scalar_k_f) AxisManip::wavelength_to_scalar_k<float>;
%template(wavelength_to_scalar_k_d) AxisManip::wavelength_to_scalar_k<double>;

%template(wavelength_to_d_spacing_f) AxisManip::wavelength_to_d_spacing<float>;
%template(wavelength_to_d_spacing_d) AxisManip::wavelength_to_d_spacing<double>;

%template(time_offset_dgs_f) AxisManip::time_offset_dgs<float>;
%template(time_offset_dgs_d) AxisManip::time_offset_dgs<double>;

%template(tof_to_final_velocity_dgs_f) AxisManip::tof_to_final_velocity_dgs<float>;
%template(tof_to_final_velocity_dgs_d) AxisManip::tof_to_final_velocity_dgs<double>;

%template(tof_to_initial_velocity_igs_f) AxisManip::tof_to_initial_velocity_igs<float>;
%template(tof_to_initial_velocity_igs_d) AxisManip::tof_to_initial_velocity_igs<double>;

%template(tof_to_initial_wavelength_igs_f) AxisManip::tof_to_initial_wavelength_igs<float>;
%template(tof_to_initial_wavelength_igs_d) AxisManip::tof_to_initial_wavelength_igs<double>;

%template(energy_transfer_f) AxisManip::energy_transfer<float>;
%template(energy_transfer_d) AxisManip::energy_transfer<double>;

%template(frequency_to_angular_frequency_f) AxisManip::frequency_to_angular_frequency<float>;
%template(frequency_to_angular_frequency_d) AxisManip::frequency_to_angular_frequency<double>;

%template(init_scatt_wavevector_to_Q_f) AxisManip::init_scatt_wavevector_to_Q<float>;
%template(init_scatt_wavevector_to_Q_d) AxisManip::init_scatt_wavevector_to_Q<double>;

%template(init_scatt_wavevector_to_scalar_Q_f) AxisManip::init_scatt_wavevector_to_scalar_Q<float>;
%template(init_scatt_wavevector_to_scalar_Q_d) AxisManip::init_scatt_wavevector_to_scalar_Q<double>;

%template(tof_to_Q_f) AxisManip::tof_to_Q<float>;
%template(tof_to_Q_d) AxisManip::tof_to_Q<double>;

%template(d_spacing_to_tof_focused_det_f) AxisManip::d_spacing_to_tof_focused_det<float>;
%template(d_spacing_to_tof_focused_det_d) AxisManip::d_spacing_to_tof_focused_det<double>;
