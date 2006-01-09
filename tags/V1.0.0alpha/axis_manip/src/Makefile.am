# $Id$

AM_CPPFLAGS = -I. -I$(top_srcdir)/axis_manip/inc -I$(top_srcdir)/nessi \
              -I$(top_srcdir)/utils/inc

lib_LTLIBRARIES = libAxisManip.la

libAxisManip_la_LDFLAGS = -version-info 1:0:0 \
              -L$(top_srcdir)/utils/src/.libs -lUtils

libAxisManip_la_SOURCES = \
	d_spacing_to_tof_focused_det.hpp \
	d_spacing_to_tof_focused_det.cpp \
	energy_transfer.hpp \
	energy_transfer.cpp \
	final_velocity_igs.hpp \
	final_velocity_igs.cpp \
	frequency_to_angular_frequency.hpp \
	frequency_to_angular_frequency.cpp \
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
