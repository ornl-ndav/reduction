#!/bin/bash

# $Id$

cwd=`pwd`

PAL_MODULES="$cwd/../../../bindings"
PBL_LIBS="$cwd/../../../bindings/.libs"

export PYTHONPATH="$PAL_MODULES:$PBL_LIBS:$PYTHONPATH"

python abs_val_test.py
echo
python add_ncerr_test.py
echo
python bisect_helper_test.py
echo
python calc_area_2D_polygon_test.py
echo
python calc_bin_centers_test.py
echo
python calc_bin_widths_test.py
echo
python convex_polygon_intersect_test.py
echo
python d_spacing_to_tof_focused_det_test.py
echo
python div_ncerr_test.py
echo
python energy_to_wavelength_test.py
echo
python energy_transfer_test.py
echo
python eval_linear_fit_test.py
echo
python fit_linear_background_test.py
echo
python frequency_to_angular_frequency_test.py
echo
python frequency_to_energy_test.py
echo
python init_scatt_wavevector_to_Q_test.py
echo
python init_scatt_wavevector_to_scalar_Q_test.py
echo
python initial_velocity_dgs_test.py
echo
python linear_order_jacobian_test.py
echo
python mult_ncerr_test.py
echo
python rebin_2D_quad_to_rectlin_test.py
echo
python rebin_axis_1D_test.py
echo
python rebin_axis_1D_frac_test.py
echo
python rebin_axis_2D_test.py
echo
python rebin_diagonal_test.py
echo
python reverse_array_cp_test.py
echo
python reverse_array_nc_test.py
echo
python shift_spectrum_test.py
echo
python sub_ncerr_test.py
echo
python sumw_ncerr_test.py
echo
python time_offset_dgs_test.py
echo
python tof_to_final_velocity_dgs_test.py
echo
python tof_to_initial_wavelength_igs_test.py
echo
python tof_to_initial_wavelength_igs_lin_time_zero_test.py
echo
python tof_to_scalar_Q_test.py
echo
python tof_to_wavelength_test.py
echo
python tof_to_wavelength_lin_time_zero_test.py
echo
python velocity_to_energy_test.py
echo
python velocity_to_scalar_k_test.py
echo
python wavelength_to_d_spacing_test.py
echo
python wavelength_to_energy_test.py
echo
python wavelength_to_scalar_Q_test.py
echo
python wavelength_to_scalar_k_test.py
echo
python wavelength_to_tof_test.py
echo
python wavelength_to_velocity_test.py
echo
python weighted_average_test.py

