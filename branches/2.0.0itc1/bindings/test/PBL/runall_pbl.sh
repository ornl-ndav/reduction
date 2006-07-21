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
python test_energy_transfer.py
echo
python test_frequency_to_energy.py
echo
python test_init_scatt_wavevector_to_scalar_Q.py
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
python test_tof_to_final_velocity_dgs.py
echo
python test_tof_to_initial_wavelength_igs.py
echo
python test_tof_to_wavelength.py
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
