// axis_manip.i - SWIG interface
//
// $Id$
//
%module axis_manip
%{
#include "conversions.hpp"
#include "rebinning.hpp"
#include "reverse_array.hpp"
%}

%include "libexcept.i"

// Parse the original header file
%include "conversions.hpp"
%include "rebinning.hpp"
%include "reverse_array.hpp"

// Instantiate reverse array templates
//template <typename NumT> std::string 
//    reverse_array(std::vector<NumT> const & input,
//                  std::vector<NumT> & output,
//                  void *temp=NULL);

%template(reverse_array_f) AxisManip::reverse_array<float>;
%template(reverse_array_d) AxisManip::reverse_array<double>;
%template(reverse_array_i) AxisManip::reverse_array<int>;
%template(reverse_array_u) AxisManip::reverse_array<unsigned>;

%template(reverse_array_nc_f) AxisManip::reverse_array_nc<float>;
%template(reverse_array_nc_d) AxisManip::reverse_array_nc<double>;
%template(reverse_array_nc_i) AxisManip::reverse_array_nc<int>;
%template(reverse_array_nc_u) AxisManip::reverse_array_nc<unsigned>;

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
%template(rebin_axis_1D_i) AxisManip::rebin_axis_1D<int>;
%template(rebin_axis_1D_u) AxisManip::rebin_axis_1D<unsigned>;

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
%template(rebin_axis_2D_i) AxisManip::rebin_axis_2D<int>;
%template(rebin_axis_2D_u) AxisManip::rebin_axis_2D<unsigned>;

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
%template(rebin_axis_4D_i) AxisManip::rebin_axis_4D<int>;
%template(rebin_axis_4D_u) AxisManip::rebin_axis_4D<unsigned>;

// Instantiate conversion templates

%template(tof_to_wavelength_f) AxisManip::tof_to_wavelength<float>;
%template(tof_to_wavelength_d) AxisManip::tof_to_wavelength<double>;
%template(tof_to_wavelength_i) AxisManip::tof_to_wavelength<int>;
%template(tof_to_wavelength_u) AxisManip::tof_to_wavelength<unsigned>;

%template(wavelength_to_tof_f) AxisManip::wavelength_to_tof<float>;
%template(wavelength_to_tof_d) AxisManip::wavelength_to_tof<double>;
%template(wavelength_to_tof_i) AxisManip::wavelength_to_tof<int>;
%template(wavelength_to_tof_u) AxisManip::wavelength_to_tof<unsigned>;

%template(tof_to_scalar_Q_f) AxisManip::tof_to_scalar_Q<float>;
%template(tof_to_scalar_Q_d) AxisManip::tof_to_scalar_Q<double>;
%template(tof_to_scalar_Q_i) AxisManip::tof_to_scalar_Q<int>;
%template(tof_to_scalar_Q_u) AxisManip::tof_to_scalar_Q<unsigned>;

%template(wavelength_to_scalar_Q_f) AxisManip::wavelength_to_scalar_Q<float>;
%template(wavelength_to_scalar_Q_d) AxisManip::wavelength_to_scalar_Q<double>;
%template(wavelength_to_scalar_Q_i) AxisManip::wavelength_to_scalar_Q<int>;
%template(wavelength_to_scalar_Q_u) AxisManip::wavelength_to_scalar_Q<unsigned>;

%template(initial_velocity_dgs_f) AxisManip::initial_velocity_dgs<float>;
%template(initial_velocity_dgs_d) AxisManip::initial_velocity_dgs<double>;
%template(initial_velocity_dgs_i) AxisManip::initial_velocity_dgs<int>;
%template(initial_velocity_dgs_u) AxisManip::initial_velocity_dgs<unsigned>;

%template(final_velocity_igs_f) AxisManip::final_velocity_igs<float>;
%template(final_velocity_igs_d) AxisManip::final_velocity_igs<double>;
%template(final_velocity_igs_i) AxisManip::final_velocity_igs<int>;
%template(final_velocity_igs_u) AxisManip::final_velocity_igs<unsigned>;

%template(velocity_to_energy_f) AxisManip::velocity_to_energy<float>;
%template(velocity_to_energy_d) AxisManip::velocity_to_energy<double>;
%template(velocity_to_energy_i) AxisManip::velocity_to_energy<int>;
%template(velocity_to_energy_u) AxisManip::velocity_to_energy<unsigned>;

%template(wavelength_to_energy_f) AxisManip::wavelength_to_energy<float>;
%template(wavelength_to_energy_d) AxisManip::wavelength_to_energy<double>;
%template(wavelength_to_energy_i) AxisManip::wavelength_to_energy<int>;
%template(wavelength_to_energy_u) AxisManip::wavelength_to_energy<unsigned>;

%template(velocity_to_scalar_k_f) AxisManip::velocity_to_scalar_k<float>;
%template(velocity_to_scalar_k_d) AxisManip::velocity_to_scalar_k<double>;
%template(velocity_to_scalar_k_i) AxisManip::velocity_to_scalar_k<int>;
%template(velocity_to_scalar_k_u) AxisManip::velocity_to_scalar_k<unsigned>;

%template(wavelength_to_scalar_k_f) AxisManip::wavelength_to_scalar_k<float>;
%template(wavelength_to_scalar_k_d) AxisManip::wavelength_to_scalar_k<double>;
%template(wavelength_to_scalar_k_i) AxisManip::wavelength_to_scalar_k<int>;
%template(wavelength_to_scalar_k_u) AxisManip::wavelength_to_scalar_k<unsigned>;

%template(wavelength_to_d_spacing_f) AxisManip::wavelength_to_d_spacing<float>;
%template(wavelength_to_d_spacing_d) AxisManip::wavelength_to_d_spacing<double>;
%template(wavelength_to_d_spacing_i) AxisManip::wavelength_to_d_spacing<int>;
%template(wavelength_to_d_spacing_u) AxisManip::wavelength_to_d_spacing<unsigned>;

%template(time_offset_dgs_f) AxisManip::time_offset_dgs<float>;
%template(time_offset_dgs_d) AxisManip::time_offset_dgs<double>;
%template(time_offset_dgs_i) AxisManip::time_offset_dgs<int>;
%template(time_offset_dgs_u) AxisManip::time_offset_dgs<unsigned>;

%template(tof_to_final_velocity_dgs_f) AxisManip::tof_to_final_velocity_dgs<float>;
%template(tof_to_final_velocity_dgs_d) AxisManip::tof_to_final_velocity_dgs<double>;
%template(tof_to_final_velocity_dgs_i) AxisManip::tof_to_final_velocity_dgs<int>;
%template(tof_to_final_velocity_dgs_u) AxisManip::tof_to_final_velocity_dgs<unsigned>;

%template(tof_to_initial_velocity_igs_f) AxisManip::tof_to_initial_velocity_igs<float>;
%template(tof_to_initial_velocity_igs_d) AxisManip::tof_to_initial_velocity_igs<double>;
%template(tof_to_initial_velocity_igs_i) AxisManip::tof_to_initial_velocity_igs<int>;
%template(tof_to_initial_velocity_igs_u) AxisManip::tof_to_initial_velocity_igs<unsigned>;

%template(tof_to_initial_wavelength_igs_f) AxisManip::tof_to_initial_wavelength_igs<float>;
%template(tof_to_initial_wavelength_igs_d) AxisManip::tof_to_initial_wavelength_igs<double>;
%template(tof_to_initial_wavelength_igs_i) AxisManip::tof_to_initial_wavelength_igs<int>;
%template(tof_to_initial_wavelength_igs_u) AxisManip::tof_to_initial_wavelength_igs<unsigned>;

%template(energy_transfer_f) AxisManip::energy_transfer<float>;
%template(energy_transfer_d) AxisManip::energy_transfer<double>;
%template(energy_transfer_i) AxisManip::energy_transfer<int>;
%template(energy_transfer_u) AxisManip::energy_transfer<unsigned>;

%template(frequency_to_angular_frequency_f) AxisManip::frequency_to_angular_frequency<float>;
%template(frequency_to_angular_frequency_d) AxisManip::frequency_to_angular_frequency<double>;
%template(frequency_to_angular_frequency_i) AxisManip::frequency_to_angular_frequency<int>;
%template(frequency_to_angular_frequency_u) AxisManip::frequency_to_angular_frequency<unsigned>;

%template(init_scatt_wavevector_to_Q_f) AxisManip::init_scatt_wavevector_to_Q<float>;
%template(init_scatt_wavevector_to_Q_d) AxisManip::init_scatt_wavevector_to_Q<double>;
%template(init_scatt_wavevector_to_Q_i) AxisManip::init_scatt_wavevector_to_Q<int>;
%template(init_scatt_wavevector_to_Q_u) AxisManip::init_scatt_wavevector_to_Q<unsigned>;

%template(init_scatt_wavevector_to_scalar_Q_f) AxisManip::init_scatt_wavevector_to_scalar_Q<float>;
%template(init_scatt_wavevector_to_scalar_Q_d) AxisManip::init_scatt_wavevector_to_scalar_Q<double>;
%template(init_scatt_wavevector_to_scalar_Q_i) AxisManip::init_scatt_wavevector_to_scalar_Q<int>;
%template(init_scatt_wavevector_to_scalar_Q_u) AxisManip::init_scatt_wavevector_to_scalar_Q<unsigned>;

%template(tof_to_Q_f) AxisManip::tof_to_Q<float>;
%template(tof_to_Q_d) AxisManip::tof_to_Q<double>;
%template(tof_to_Q_i) AxisManip::tof_to_Q<int>;
%template(tof_to_Q_u) AxisManip::tof_to_Q<unsigned>;

template <typename NumT> std::string
    wavelength_to_tof_focused_det(std::vector<NumT> const & d_spacing,
                                  std::vector<NumT> const & d_spacing_err2,
                                  NumT pathlength_focused,
                                  NumT polar_focused,
                                  std::vector<NumT> & tof,
                                  std::vector<NumT> & tof_err2,
                                  void *temp=NULL);

//%template(wavelength_to_tof_focused_det_f) AxisManip::wavelength_to_tof_focused_det<float>;
//%template(wavelength_to_tof_focused_det_d) AxisManip::wavelength_to_tof_focused_det<double>;
//%template(wavelength_to_tof_focused_det_i) AxisManip::wavelength_to_tof_focused_det<int>;
//%template(wavelength_to_tof_focused_det_u) AxisManip::wavelength_to_tof_focused_det<unsigned>;
