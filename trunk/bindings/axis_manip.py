#
#                     SNS Common Libraries
#           A part of the SNS Analysis Software Suite.
#
#                  Spallation Neutron Source
#          Oak Ridge National Laboratory, Oak Ridge TN.
#
#
#                             NOTICE
# 
# For this software and its associated documentation, permission is granted 
# to reproduce, prepare derivative works, and distribute copies to the public 
# for any purpose and without fee.
#  
# This material was prepared as an account of work sponsored by an agency of 
# the United States Government.  Neither the United States Government nor the 
# United States Department of Energy, nor any of their employees, makes any 
# warranty, express or implied, or assumes any legal liability or 
# responsibility for the accuracy, completeness, or usefulness of any 
# information, apparatus, product, or process disclosed, or represents that 
# its use would not infringe privately owned rights.
#
#

#
# $Id:$
#
# \file binding/axis_manip.py
#

from NessiVector import NessiVector
from axis_manip_bind import energy_transfer_f
from axis_manip_bind import energy_transfer_d
from axis_manip_bind import init_scatt_wavevector_to_scalar_Q_f
from axis_manip_bind import init_scatt_wavevector_to_scalar_Q_d
from axis_manip_bind import rebin_axis_1D_f
from axis_manip_bind import rebin_axis_1D_d
from axis_manip_bind import reverse_array_cp_f
from axis_manip_bind import reverse_array_cp_d
from axis_manip_bind import reverse_array_nc_f
from axis_manip_bind import reverse_array_nc_d
from axis_manip_bind import tof_to_initial_wavelength_igs_f
from axis_manip_bind import tof_to_initial_wavelength_igs_d
from axis_manip_bind import tof_to_wavelength_f
from axis_manip_bind import tof_to_wavelength_d
from axis_manip_bind import wavelength_to_energy_f
from axis_manip_bind import wavelength_to_energy_d
from axis_manip_bind import wavelength_to_scalar_k_f
from axis_manip_bind import wavelength_to_scalar_k_d

import sys

def energy_transfer(initial_energy, initial_energy_err2,\
			 final_energy, final_energy_err2):
	
	#float
	if (initial_energy.type__ == NessiVector.FLOAT):
		energy_transfer = NessiVector(len(initial_energy));	
		energy_transfer_err2 = NessiVector(len(initial_energy));
		energy_transfer_f(initial_energy.array,	\
				initial_energy_err2.array,\
				final_energy.array,\
				final_energy_err2.array,\
				energy_transfer.array,\
				energy_transfer_err2.array)

	#double
	if (initial_energy.type__ == NessiVector.DOUBLE):
		energy_transfer = NessiVector(len(initial_energy),\
				"double");	
		energy_transfer_err2 = NessiVector(len(initial_energy),\
				"double");
		energy_transfer_d(initial_energy.array,\
				initial_energy_err2.array,\
				final_energy.array,\
				final_energy_err2.array,\
				energy_transfer.array,\
				energy_transfer_err2.array)

	return energy_transfer,energy_transfer_err2


def init_scatt_wavevector_to_scalar_Q(initial_wavevector,\
				initial_wavevector_err2,\
				final_wavevector,\
				final_wavevector_err2,\
				polar, polar_err2):

	#float
	if (initial_wavevector.type__ == NessiVector.FLOAT):
	  	Q = NessiVector(len(initial_wavevector))
		Q_err2 = NessiVector(len(initial_wavevector))
		init_scatt_wavevector_to_scalar_Q_f(initial_wavevector.array,\
					initial_wavevector_err2.array,\
					final_wavevector.array,\
					final_wavevector_err2.array,\
					polar, polar_err2,\
					Q.array, Q_err2.array)		

	#double
	if (initial_wavevector.type__ == NessiVector.DOUBLE):
	  	Q = NessiVector(len(initial_wavevector),"double")
		Q_err2 = NessiVector(len(initial_wavevector),"double")
		init_scatt_wavevector_to_scalar_Q_d(initial_wavevector.array,\
					initial_wavevector_err2.array,\
					final_wavevector.array,\
					final_wavevector_err2.array,\
					polar, polar_err2,\
					Q.array, Q_err2.array)		

	return Q, Q_err2

def rebin_axis_1D(axis_in, input, input_err2, axis_out):
	
	#float
	if (input.type__ == NessiVector.FLOAT):
		output = NessiVector(len(axis_out)-1)
		output_err2 = NessiVector(len(axis_out)-1)
		rebin_axis_1D_f(axis_in.array, input.array,\
				input_err2.array, axis_out.array,\
				output.array, output_err2.array)

	#double
	if (input.type__ == NessiVector.DOUBLE):
		output = NessiVector(len(axis_out))
		output_err2 = NessiVector(len(axis_out))
		rebin_axis_1D_d(axis_in.array, input.array,\
				input_err2.array, axis_out.array,\
				output.array, output_err2.array)

	return output, output_err2

def reverse_array_cp(input):
	
	#float
	if (input.type__ == NessiVector.FLOAT):
		output = NessiVector(len(input))
		reverse_array_cp_f(input.array, output.array)
	
	#double
	if (input.type__ == NessiVector.DOUBLE):
		output = NessiVector(len(input),"double")
		reverse_array_cp_d(input.array, output.array)
	
	return output

def reverse_array_nc(input):
	
	#float
	if (input.type__ == NessiVector.FLOAT):
		reverse_array_nc_f(input.array)
	
	#double
	if (input.type__ == NessiVector.DOUBLE):
		reverse_array_nc_d(input.array)
	
	return

def tof_to_initial_wavelength_igs(tof,tof_err2,\
			final_wavelength, final_wavelength_err2,\
			time_offset, time_offset_err2,\
			dist_source_sample, dist_source_sample_err2,\
			dist_sample_detector, dist_sample_detector_err2):
	
	#float
	if (tof.type__ == NessiVector.FLOAT):
		initial_wavelength = NessiVector(len(tof))
		initial_wavelength_err2 = NessiVector(len(tof))
		tof_to_initial_wavelength_igs_f(tof.array, tof_err2.array,\
			final_wavelength, final_wavelength_err2,\
			time_offset, time_offset_err2,\
			dist_source_sample, dist_source_sample_err2,\
			dist_sample_detector, dist_sample_detector_err2,\
			initial_wavelength.array, initial_wavelength_err2.array)

	#double
	if (tof.type__ == NessiVector.DOUBLE):
		initial_wavelength = NessiVector(len(tof),"double")
		initial_wavelength_err2 = NessiVector(len(tof),"double")
		tof_to_initial_wavelength_igs_d(tof.array, tof_err2.array,\
			final_wavelength, final_wavelength_err2,\
			time_offset, time_offset_err2,\
			dist_source_sample, dist_source_sample_err2,\
			dist_sample_detector, dist_sample_detector_err2,\
			initial_wavelength.array, initial_wavelength_err2.array)
		
	return initial_wavelength, initial_wavelength_err2		

def tof_to_wavelength(tof, tof_err2, pathlength, pathlength_err2):
	
	#float
	if (tof.type__ == NessiVector.FLOAT):
		wavelength = NessiVector(len(tof))
		wavelength_err2 = NessiVector(len(tof))
		tof_to_wavelength_f(tof.array, tof_err2.array,\
			pathlength, pathlength_err2,\
			wavelength.array, wavelength_err2.array)

	#double
	if (tof.type__ == NessiVector.DOUBLE):
		wavelength = NessiVector(len(tof),"double")
		wavelength_err2 = NessiVector(len(tof),"double")
		tof_to_wavelength_d(tof.array, tof_err2.array,\
			pathlength, pathlength_err2,\
			wavelength.array, wavelength_err2.array)

	return wavelength, wavelength_err2

def wavelength_to_energy(wavelength, wavelength_err2):
	
	#float
	if (wavelength.type__ == NessiVector.FLOAT):
		energy = NessiVector(len(wavelength))
		energy_err2 = NessiVector(len(wavelength))
		wavelength_to_energy_f(wavelength.array, \
			wavelength_err2.array, energy.array, energy_err2.array)
	
	#double
	if (wavelength.type__ == NessiVector.DOUBLE):
		energy = NessiVector(len(wavelength),"double")
		energy_err2 = NessiVector(len(wavelength),"double")
		wavelength_to_energy_d(wavelength.array, \
			wavelength_err2.array, energy.array, energy_err2.array)

	return energy, energy_err2

def wavelength_to_scalar_k(wavelength, wavelength_err2):
	
	#float
	if (wavelength.type__ == NessiVector.FLOAT):
		wavevector = NessiVector(len(wavelength))
		wavevector_err2 = NessiVector(len(wavelength))
		wavelength_to_scalar_k_f(wavelength.array, \
			wavelength_err2.array,\
			wavevector.array, wavevector_err2.array)

	#double
	if (wavelength.type__ == NessiVector.DOUBLE):
		wavevector = NessiVector(len(wavelength),"double")
		wavevector_err2 = NessiVector(len(wavelength),"double")
		wavelength_to_scalar_k_d(wavelength.array,\
			wavelength_err2.array,\
			wavevector.array, wavevector_err2.array)

	return wavevector, wavevector_err2