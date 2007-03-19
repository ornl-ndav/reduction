#!/bin/bash

# $Id$

cwd=`pwd`

PBL_MODULES="$cwd/../../../bindings"
PBL_LIBS="$cwd/../../../bindings/.libs"

export PYTHONPATH="$PBL_MODULES:$PBL_LIBS:$PYTHONPATH"

python test_add_ncerr.py
echo
python test_d_spacing_to_tof_focused_det.py
echo
python test_div_ncerr.py
echo
python test_energy_to_wavelength.py
echo
python test_energy_transfer.py
echo
python test_frequency_to_angular_frequency.py
echo
python test_frequency_to_energy.py
echo
python test_init_scatt_wavevector_to_Q.py
echo
python test_init_scatt_wavevector_to_scalar_Q.py
echo
python test_initial_velocity_dgs.py
echo
python test_linear_order_jacobian.py
echo
python test_mult_ncerr.py
echo
python test_rebin_axis_1D.py
echo
python test_rebin_axis_2D.py
echo
python test_reverse_array_cp.py
echo
python test_reverse_array_nc.py
echo
python test_sub_ncerr.py
echo
python test_sumw_ncerr.py
echo
python test_time_offset_dgs.py
echo
python test_tof_to_final_velocity_dgs.py
echo
python test_tof_to_initial_wavelength_igs.py
echo
python test_tof_to_initial_wavelength_igs_lin_time_zero.py
echo
python test_tof_to_scalar_Q.py
echo
python test_tof_to_wavelength.py
echo
python test_tof_to_wavelength_lin_time_zero.py
echo
python test_velocity_to_energy.py
echo
python test_velocity_to_scalar_k.py
echo
python test_wavelength_to_d_spacing.py
echo
python test_wavelength_to_energy.py
echo
python test_wavelength_to_scalar_Q.py
echo
python test_wavelength_to_scalar_k.py
echo
python test_weighted_average.py
