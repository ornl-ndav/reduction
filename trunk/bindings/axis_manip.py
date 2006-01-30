from NessiVector import NessiVector
from axis_manip_bind import energy_transfer_f
from axis_manip_bind import energy_transfer_d
from axis_manip_bind import init_scatt_wavevector_to_scalar_Q_f
from axis_manip_bind import init_scatt_wavevector_to_scalar_Q_d

import sys

def energy_transfer(initial_energy, initial_energy_err2, final_energy,\
	final_energy_err2):

	if (initial_energy.type__ == initial_energy.FLOAT):
		energy_transfer = NessiVector(len(initial_energy));		
		energy_transfer_err2 = NessiVector(len(initial_energy));	
		energy_transfer_f(initial_energy.array,	\
				initial_energy_err2.array,\
				final_energy.array,\
				final_energy_err2.array,\
				energy_transfer.array,\
				energy_transfer_err2.array)

	if (initial_energy.type__ == initial_energy.DOUBLE):
		energy_transfer = NessiVector(len(initial_energy));		
		energy_transfer_err2 = NessiVector(len(initial_energy));	
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
				polar, polar_err2,\
				Q, Q_err2):

	if (initial_wavevector.type__ == initial_wavevector.FLOAT):
	  	Q = NessiVector(len(initial_wavevector))
		Q_err2 = NessiVector(len(initial_wavevector))
		init_scatt_wavevector_to_scalar_Q_f(initial_wavevector.array,\
					initial_wavevector_err2.array,\
					final_wavevector.array,\
					final_wavevector_err2.array,\
					polar.array, polar_err2.array,\
					Q.array, Q_err2.array)		

	if (initial_wavevector.type__ == initial_wavevector.DOUBLE):
	  	Q = NessiVector(len(initial_wavevector))
		Q_err2 = NessiVector(len(initial_wavevector))
		init_scatt_wavevector_to_scalar_Q_d(initial_wavevector.array,\
					initial_wavevector_err2.array,\
					final_wavevector.array,\
					final_wavevector_err2.array,\
					polar.array, polar_err2.array,\
					Q.array, Q_err2.array)		

	return Q, Q_err2
