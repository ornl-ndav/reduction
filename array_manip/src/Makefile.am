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

AM_CPPFLAGS = $(OPENMP_CXX) $(OPENMP_LD) -I. -I$(top_srcdir)/array_manip/inc \
			-I$(top_srcdir)/nessi/inc -I$(top_srcdir)/utils/inc 

pkglib_LTLIBRARIES = libArrayManip.la

libArrayManip_la_LDFLAGS = $(LIB_ARRAY_MANIP_VERSION) \
			-L$(top_builddir)/utils/src/.libs -lUtils

libArrayManip_la_SOURCES = \
	abs_val.cpp \
	abs_val.hpp \
	add_ncerr.cpp \
	add_ncerr.hpp \
        div_ncerr.cpp \
        div_ncerr.hpp \
        mult_ncerr.cpp \
        mult_ncerr.hpp \
        sub_ncerr.cpp \
        sub_ncerr.hpp \
        sumw_ncerr.cpp \
        sumw_ncerr.hpp

EXTRA_libArrayManip_la_SOURCES = \
	$(top_srcdir)/utils/src/check_sizes_square.hpp \
	$(top_srcdir)/utils/src/check_sizes_square.cpp
