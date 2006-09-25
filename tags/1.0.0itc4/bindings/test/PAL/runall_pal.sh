#!/bin/bash

# $Id$

cwd=`pwd`

PAL_MODULES="$cwd/../../../bindings"
PBL_LIBS="$cwd/../../../bindings/.libs"

export PYTHONPATH="$PAL_MODULES:$PBL_LIBS:$PYTHONPATH"

python add_ncerr_test.py
echo
python div_ncerr_test.py
echo
python energy_transfer_test.py
echo
python frequency_to_energy_test.py
echo
python init_scatt_wavevector_to_scalar_Q_test.py
echo
python mult_ncerr_test.py
echo
python rebin_axis_1D_test.py
echo
python rebin_axis_2D_test.py
echo
python reverse_array_cp_test.py
echo
python reverse_array_nc_test.py
echo
python sub_ncerr_test.py
echo
python sumw_ncerr_test.py
echo
python tof_to_initial_wavelength_igs_test.py
echo
python tof_to_wavelength_test.py
echo
python wavelength_to_energy_test.py
echo
python wavelength_to_scalar_Q_test.py
echo
python wavelength_to_scalar_k_test.py
echo
python weighted_average_test.py
