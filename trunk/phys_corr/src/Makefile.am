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

AM_CPPFLAGS = -I. -I$(top_srcdir)/phys_corr/inc -I$(top_srcdir)/nessi/inc

pkglib_LTLIBRARIES = libPhysCorr.la

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
