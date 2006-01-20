# $Id$

AM_CPPFLAGS = -I. -I$(top_srcdir)/array_manip/inc -I$(top_srcdir)/nessi \
	      -I$(top_srcdir)/utils/inc

lib_LTLIBRARIES = libArrayManip.la

libArrayManip_la_LDFLAGS = $(LIB_ARRAY_MANIP_VERSION) \
			-L$(top_srcdir)/utils/src/.libs -lUtils

libArrayManip_la_SOURCES = \
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
