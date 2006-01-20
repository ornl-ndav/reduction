# $Id$

AM_CPPFLAGS = -I. -I$(top_srcdir)/phys_corr/inc -I$(top_srcdir)/nessi

lib_LTLIBRARIES = libPhysCorr.la

libPhysCorr_la_LDFLAGS = $(LIB_PHYS_CORR_VERSION)

libPhysCorr_la_SOURCES = \
	absorption_mult_scatt.hpp \
	absorption_mult_scatt.cpp \
	dead_time_corr.hpp \
	dead_time_corr.cpp \
	incoherent_scatt_corr.hpp \
	incoherent_scatt_corr.cpp \
	inelastic_scatt_corr.hpp \
	inelastic_scatt_corr.cpp
