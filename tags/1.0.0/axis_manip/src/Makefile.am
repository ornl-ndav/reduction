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

# $Id$

AM_CPPFLAGS = -I. -I$(top_srcdir)/axis_manip/inc -I$(top_srcdir)/nessi/inc \
              -I$(top_srcdir)/utils/inc -I$(top_srcdir)/phys_const/inc

pkglib_LTLIBRARIES = libAxisManip.la

libAxisManip_la_LDFLAGS = $(LIB_AXIS_MANIP_VERSION) \
              -L$(top_builddir)/utils/src/.libs -lUtils

libAxisManip_la_SOURCES = \
	d_spacing_to_tof_focused_det.hpp \
	d_spacing_to_tof_focused_det.cpp \
	energy_transfer.hpp \
	energy_transfer.cpp \
	final_velocity_igs.hpp \
	final_velocity_igs.cpp \
	frequency_to_angular_frequency.hpp \
	frequency_to_angular_frequency.cpp \
	frequency_to_energy.hpp \
	frequency_to_energy.cpp \
	init_scatt_wavevector_to_Q.hpp \
	init_scatt_wavevector_to_Q.cpp \
	init_scatt_wavevector_to_scalar_Q.hpp \
	init_scatt_wavevector_to_scalar_Q.cpp \
	initial_velocity_dgs.hpp \
	initial_velocity_dgs.cpp \
	rebin_axis_1D.hpp \
	rebin_axis_1D.cpp \
	rebin_axis_2D.hpp \
	rebin_axis_2D.cpp \
	rebin_axis_4D.hpp \
	rebin_axis_4D.cpp \
	reverse_array_cp.hpp \
	reverse_array_cp.cpp \
	reverse_array_nc.hpp \
	reverse_array_nc.cpp \
	time_offset_dgs.hpp \
	time_offset_dgs.cpp \
	tof_to_Q.hpp \
	tof_to_Q.cpp \
	tof_to_final_velocity_dgs.hpp \
	tof_to_final_velocity_dgs.cpp \
	tof_to_initial_velocity_igs.hpp \
	tof_to_initial_velocity_igs.cpp \
	tof_to_initial_wavelength_igs.hpp \
	tof_to_initial_wavelength_igs.cpp \
	tof_to_initial_wavelength_igs_lin_time_zero.hpp \
	tof_to_initial_wavelength_igs_lin_time_zero.cpp \
	tof_to_scalar_Q.hpp \
	tof_to_scalar_Q.cpp \
	tof_to_wavelength.hpp \
	tof_to_wavelength.cpp \
	velocity_to_energy.hpp \
	velocity_to_energy.cpp \
	velocity_to_scalar_k.hpp \
	velocity_to_scalar_k.cpp \
	wavelength_to_d_spacing.hpp \
	wavelength_to_d_spacing.cpp \
	wavelength_to_energy.hpp \
	wavelength_to_energy.cpp \
	wavelength_to_scalar_Q.hpp \
	wavelength_to_scalar_Q.cpp \
	wavelength_to_scalar_k.hpp \
	wavelength_to_scalar_k.cpp \
	wavelength_to_tof.hpp \
	wavelength_to_tof.cpp
