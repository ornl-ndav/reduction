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
// axis_manip.i - SWIG interface
//
// $Id$
//
%module axis_manip_bind
%{
#include "conversions.hpp"
#include "rebinning.hpp"
#include "reverse_array.hpp"
#include "vpair.hpp"
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

%template(rebin_2D_quad_to_rectlin_d) AxisManip::rebin_2D_quad_to_rectlin<double>;

%template(rebin_axis_1D_d) AxisManip::rebin_axis_1D<double>;

%template(rebin_axis_1D_frac_d) AxisManip::rebin_axis_1D_frac<double>;

%template(rebin_axis_2D_d) AxisManip::rebin_axis_2D<double>;

%template(rebin_axis_4D_d) AxisManip::rebin_axis_4D<double>;

%template(rebin_diagonal_d) AxisManip::rebin_diagonal<double>;

// Instantiate conversion templates

%template(d_spacing_to_tof_focused_det_d) AxisManip::d_spacing_to_tof_focused_det<double>;

%{
std::string d_spacing_to_tof_focused_det_ss_d(const double d_spacing, const double d_spacing_err2, const double pathlength_focused, const double pathlength_focused_err2, const double polar_angle_focused, const double polar_angle_focused_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::d_spacing_to_tof_focused_det(d_spacing, d_spacing_err2, pathlength_focused, pathlength_focused_err2, polar_angle_focused, polar_angle_focused_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string d_spacing_to_tof_focused_det_ss_d(const double d_spacing, const double d_spacing_err2, const double pathlength_focused, const double pathlength_focused_err2, const double polar_angle_focused, const double polar_angle_focused_err2, VPair<double> & value, void *temp=NULL);

%template(energy_to_wavelength_d) AxisManip::energy_to_wavelength<double>;

%{
std::string energy_to_wavelength_ss_d(const double energy, const double energy_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::energy_to_wavelength(energy, energy_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string energy_to_wavelength_ss_d(const double energy, const double energy_err2, VPair<double> & value, void *temp=NULL);

%template(energy_transfer_d) AxisManip::energy_transfer<double>;

%{
std::string energy_transfer_ss_d(const double initial_energy, const double initial_energy_err2, const double final_energy, double final_energy_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::energy_transfer(initial_energy, initial_energy_err2, final_energy, final_energy_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string energy_transfer_ss_d(const double initial_energy, const double initial_energy_err2, const double final_energy, double final_energy_err2, VPair<double> & value, void *temp=NULL);

%template(frequency_to_angular_frequency_d) AxisManip::frequency_to_angular_frequency<double>;

%{
std::string frequency_to_angular_frequency_ss_d(const double frequency, const double frequency_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::frequency_to_angular_frequency(frequency, frequency_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string frequency_to_angular_frequency_ss_d(const double frequency, const double frequency_err2, VPair<double> & value, void *temp=NULL);

%template(frequency_to_energy_d) AxisManip::frequency_to_energy<double>;

%{
std::string frequency_to_energy_ss_d(const double frequency, const double frequency_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::frequency_to_energy(frequency, frequency_err2, value.val, value.val_err2, temp);
  return ret;
}
%}	

std::string frequency_to_energy_ss_d(const double frequency, const double frequency_err2, VPair<double> & value, void *temp=NULL);

%template(init_scatt_wavevector_to_Q_d) AxisManip::init_scatt_wavevector_to_Q<double>;

%{
std::string init_scatt_wavevector_to_Q_ss_d(const double initial_wavevector, const double initial_wavevector_err2, const double final_wavevector, const double final_wavevector_err2, const double azimuthal_angle, const double azimuthal_angle_err2, const double polar_angle, const double polar_angle_err2, VPair<double> & value_Qx, VPair<double> & value_Qy, VPair<double> & value_Qz, void *temp=NULL) {
  std::string ret = AxisManip::init_scatt_wavevector_to_Q(initial_wavevector, initial_wavevector_err2, final_wavevector, final_wavevector_err2, azimuthal_angle, azimuthal_angle_err2, polar_angle, polar_angle_err2, value_Qx.val, value_Qx.val_err2, value_Qy.val, value_Qy.val_err2, value_Qz.val, value_Qz.val_err2, temp);
  return ret;
}
%}

std::string init_scatt_wavevector_to_Q_ss_d(const double initial_wavevector, const double initial_wavevector_err2, const double final_wavevector, const double final_wavevector_err2, const double azimuthal_angle, const double azimuthal_angle_err2, const double polar_angle, const double polar_angle_err2, VPair<double> & value_Qx, VPair<double> & value_Qy, VPair<double> & value_Qz, void *temp=NULL);

%template(init_scatt_wavevector_to_scalar_Q_d) AxisManip::init_scatt_wavevector_to_scalar_Q<double>;

%{
std::string init_scatt_wavevector_to_scalar_Q_ss_d(const double initial_wavevector, const double initial_wavevector_err2, const double final_wavevector, const double final_wavevector_err2, const double polar_angle, const double polar_angle_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::init_scatt_wavevector_to_scalar_Q(initial_wavevector, initial_wavevector_err2, final_wavevector, final_wavevector_err2, polar_angle, polar_angle_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string init_scatt_wavevector_to_scalar_Q_ss_d(const double initial_wavevector, const double initial_wavevector_err2, const double final_wavevector, const double final_wavevector_err2, const double polar_angle, const double polar_angle_err2, VPair<double> & value, void *temp=NULL);

%{
std::string initial_velocity_dgs_ss_d(const double dist_upsteam_mon, const double dist_upstream_mon_err2, const double time_upstream_mon, const double time_upstream_mon_err2, const double dist_downstream_mon, const double dist_downstream_mon_err2, const double time_downstream_mon, const double time_downstream_mon_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::initial_velocity_dgs(dist_upsteam_mon, dist_upstream_mon_err2, time_upstream_mon, time_upstream_mon_err2, dist_downstream_mon, dist_downstream_mon_err2, time_downstream_mon, time_downstream_mon_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string initial_velocity_dgs_ss_d(const double dist_upsteam_mon, const double dist_upstream_mon_err2, const double time_upstream_mon, const double time_upstream_mon_err2, const double dist_downstream_mon, const double dist_downstream_mon_err2, const double time_downstream_mon, const double time_downstream_mon_err2, VPair<double> & value, void *temp=NULL);

%{
std::string time_offset_dgs_ss_d(const double dist_downstream_monitor, const double dist_downstream_monitor_err2, const double time_downstream_monitor, const double time_downstream_monitor_err2, const double initial_velocity, const double initial_velocity_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::time_offset_dgs(dist_downstream_monitor, dist_downstream_monitor_err2, time_downstream_monitor, time_downstream_monitor_err2, initial_velocity, initial_velocity_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string time_offset_dgs_ss_d(const double dist_downstream_monitor, const double dist_downstream_monitor_err2, const double time_downstream_monitor, const double time_downstream_monitor_err2, const double initial_velocity, const double initial_velocity_err2, VPair<double> & value, void *temp=NULL);

%template(tof_to_final_velocity_dgs_d) AxisManip::tof_to_final_velocity_dgs<double>;

%{
std::string tof_to_final_velocity_dgs_ss_d(const double tof, const double tof_err2, const double initial_velocity, const double initial_velocity_err2, const double time_offset, const double time_offset_err2,const double dist_source_sample, const double dist_source_sample_err2, const double dist_sample_detector, const double dist_sample_detector_err2, VPair<double> & value, void *temp=NULL) { 
  std::string ret = AxisManip::tof_to_final_velocity_dgs(tof, tof_err2, initial_velocity, initial_velocity_err2, time_offset, time_offset_err2, dist_source_sample, dist_source_sample_err2, dist_sample_detector, dist_sample_detector_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string tof_to_final_velocity_dgs_ss_d(const double tof, const double tof_err2, const double initial_velocity, const double initial_velocity_err2, const double time_offset, const double time_offset_err2,const double dist_source_sample, const double dist_source_sample_err2, const double dist_sample_detector, const double dist_sample_detector_err2, VPair<double> & value, void *temp=NULL);


%template(tof_to_initial_velocity_igs_d) AxisManip::tof_to_initial_velocity_igs<double>;

%template(tof_to_initial_wavelength_igs_d) AxisManip::tof_to_initial_wavelength_igs<double>;

%{
std::string tof_to_initial_wavelength_igs_ss_d(const double tof, const double tof_err2, const double final_wavelength, const double final_wavelength_err2, const double time_offset, const double time_offset_err2, const double dist_source_sample, const double dist_source_sample_err2, const double dist_sample_detector, const double dist_sample_detector_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::tof_to_initial_wavelength_igs(tof, tof_err2, final_wavelength, final_wavelength_err2, time_offset, time_offset_err2, dist_source_sample, dist_source_sample_err2, dist_sample_detector, dist_sample_detector_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string tof_to_initial_wavelength_igs_ss_d(const double tof, const double tof_err2, const double final_wavelength, const double final_wavelength_err2, const double time_offset, const double time_offset_err2, const double dist_source_sample, const double dist_source_sample_err2, const double dist_sample_detector, const double dist_sample_detector_err2, VPair<double> & value, void *temp=NULL);

%template(tof_to_initial_wavelength_igs_lin_time_zero_d) AxisManip::tof_to_initial_wavelength_igs_lin_time_zero<double>;

%{
std::string tof_to_initial_wavelength_igs_lin_time_zero_ss_d(const double tof, const double tof_err2, const double final_wavelength, const double final_wavelength_err2, const double time_0_slope, const double time_0_slope_err2, const double time_0_offset, const double time_0_offset_err2, const double dist_source_sample, const double dist_source_sample_err2, const double dist_sample_detector, const double dist_sample_detector_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::tof_to_initial_wavelength_igs_lin_time_zero(tof, tof_err2, final_wavelength, final_wavelength_err2, time_0_slope, time_0_slope_err2, time_0_offset, time_0_offset_err2, dist_source_sample, dist_source_sample_err2, dist_sample_detector, dist_sample_detector_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string tof_to_initial_wavelength_igs_lin_time_zero_ss_d(const double tof, const double tof_err2, const double final_wavelength, const double final_wavelength_err2, const double time_0_slope, const double time_0_slope_err2, const double time_0_offset, const double time_0_offset_err2, const double dist_source_sample, const double dist_source_sample_err2, const double dist_sample_detector, const double dist_sample_detector_err2, VPair<double> & value, void *temp=NULL);

%template(tof_to_Q_d) AxisManip::tof_to_Q<double>;

%template(tof_to_scalar_Q_d) AxisManip::tof_to_scalar_Q<double>;

%{
std::string tof_to_scalar_Q_ss_d(const double tof, const double tof_err2, const double pathlength, const double pathlength_err2, const double polar, const double polar_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::tof_to_scalar_Q(tof, tof_err2, pathlength, pathlength_err2, polar, polar_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string tof_to_scalar_Q_ss_d(const double tof, const double tof_err2, const double pathlength, const double pathlength_err2, const double polar, const double polar_err2, VPair<double> & value, void *temp=NULL);

%template(tof_to_wavelength_d) AxisManip::tof_to_wavelength<double>;

%{
std::string tof_to_wavelength_ss_d(const double tof, const double tof_err2, const double pathlength, const double pathlength_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::tof_to_wavelength(tof, tof_err2, pathlength, pathlength_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string tof_to_wavelength_ss_d(const double tof, const double tof_err2, const double pathlength, const double pathlength_err2, VPair<double> & value, void *temp=NULL);

%template(tof_to_wavelength_lin_time_zero_d) AxisManip::tof_to_wavelength_lin_time_zero<double>;

%{
std::string tof_to_wavelength_lin_time_zero_ss_d(const double tof, const double tof_err2, const double pathlength, const double pathlength_err2, const double time_0_slope, const double time_0_slope_err2, const double time_0_offset, const double time_0_offset_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::tof_to_wavelength_lin_time_zero(tof, tof_err2, pathlength, pathlength_err2, time_0_slope, time_0_slope_err2, time_0_offset, time_0_offset_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string tof_to_wavelength_lin_time_zero_ss_d(const double tof, const double tof_err2, const double pathlength, const double pathlength_err2, const double time_0_slope, const double time_0_slope_err2, const double time_0_offset, const double time_0_offset_err2, VPair<double> & value, void *temp=NULL);

%template(velocity_to_energy_d) AxisManip::velocity_to_energy<double>;

%{
std::string velocity_to_energy_ss_d(const double velocity, const double velocity_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::velocity_to_energy(velocity, velocity_err2,value.val, value.val_err2, temp);
  return ret;
}
%}

std::string velocity_to_energy_ss_d(const double velocity, const double velocity_err2, VPair<double> & value, void *temp=NULL);  

%template(velocity_to_scalar_k_d) AxisManip::velocity_to_scalar_k<double>;

%{
std::string velocity_to_scalar_k_ss_d(const double velocity, const double velocity_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::velocity_to_scalar_k(velocity, velocity_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string velocity_to_scalar_k_ss_d(const double velocity, const double velocity_err2, VPair<double> & value, void *temp=NULL);

%template(velocity_to_wavelength_d) AxisManip::velocity_to_wavelength<double>;

%{
std::string velocity_to_wavelength_ss_d(const double velocity, const double velocity_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::velocity_to_wavelength(velocity, velocity_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string velocity_to_wavelength_ss_d(const double velocity, const double velocity_err2, VPair<double> & value, void *temp=NULL);

%template(wavelength_to_d_spacing_d) AxisManip::wavelength_to_d_spacing<double>;

%{
std::string wavelength_to_d_spacing_ss_d(const double wavelength, const double wavelength_err2,const double scatt_angle, const double scatt_angle_err2, VPair<double> & value, void *temp=NULL) { 
  std::string ret = AxisManip::wavelength_to_d_spacing(wavelength, wavelength_err2, scatt_angle, scatt_angle_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string wavelength_to_d_spacing_ss_d(const double wavelength, const double wavelength_err2,const double scatt_angle, const double scatt_angle_err2, VPair<double> & value, void *temp=NULL);

%template(wavelength_to_energy_d) AxisManip::wavelength_to_energy<double>;

%{
std::string wavelength_to_energy_ss_d(const double wavelength, const double wavelength_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::wavelength_to_energy(wavelength, wavelength_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string wavelength_to_energy_ss_d(const double wavelength, const double wavelength_err2, VPair<double> & value, void *temp=NULL);


%template(wavelength_to_scalar_k_d) AxisManip::wavelength_to_scalar_k<double>;

%{
std::string wavelength_to_scalar_k_ss_d(const double wavelength, const double wavelength_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::wavelength_to_scalar_k(wavelength, wavelength_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string wavelength_to_scalar_k_ss_d(const double wavelength, const double wavelength_err2, VPair<double> & value, void *temp=NULL);


%template(wavelength_to_scalar_Q_d) AxisManip::wavelength_to_scalar_Q<double>;

%{
std::string wavelength_to_scalar_Q_ss_d(const double wavelength, const double wavelength_err2, const double scatt_angle, const double scatt_angle_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::wavelength_to_scalar_Q(wavelength, wavelength_err2, scatt_angle, scatt_angle_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string wavelength_to_scalar_Q_ss_d(const double wavelength, const double wavelength_err2, const double scatt_angle, const double scatt_angle_err2, VPair<double> & value, void *temp=NULL);


%template(wavelength_to_tof_d) AxisManip::wavelength_to_tof<double>;

%{
std::string wavelength_to_tof_ss_d(const double wavelength, const double wavelength_err2, const double pathlength, const double pathlength_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::wavelength_to_tof(wavelength, wavelength_err2, pathlength, pathlength_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string wavelength_to_tof_ss_d(const double wavelength, const double wavelength_err2, const double pathlength, const double pathlength_err2, VPair<double> & value, void *temp=NULL);

%template(wavelength_to_velocity_d) AxisManip::wavelength_to_velocity<double>;

%{
std::string wavelength_to_velocity_ss_d(const double wavelength, const double wavelength_err2, VPair<double> & value, void *temp=NULL) {
  std::string ret = AxisManip::wavelength_to_velocity(wavelength, wavelength_err2, value.val, value.val_err2, temp);
  return ret;
}
%}

std::string wavelength_to_velocity_ss_d(const double wavelength, const double wavelength_err2, VPair<double> & value, void *temp=NULL);
