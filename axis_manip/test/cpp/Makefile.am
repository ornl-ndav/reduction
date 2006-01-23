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

AM_CPPFLAGS = -I. -I$(top_srcdir)/axis_manip/inc -I$(top_srcdir)/utils/inc \
	      -I$(top_srcdir)/nessi -I$(top_srcdir)/phys_const/inc
AM_LDFLAGS  = -static \
              -L$(top_srcdir)/axis_manip/src/.libs -lAxisManip \
              -L$(top_srcdir)/utils/src/.libs -lUtils

EXTRA_DIST=testsuite.at

AXIS_MANIP_TARGETS = \
	energy_transfer_test \
	init_scatt_wavevector_to_scalar_Q_test \
	tof_to_initial_wavelength_igs_test \
	tof_to_wavelength_test \
	wavelength_to_energy_test \
	wavelength_to_scalar_k_test 


TESTSUITE	= $(srcdir)/testsuite
TESTSUITE_AT	= ## dbase.at devices.at starter.at
AUTOTEST	= $(AUTOM4TE) --language=autotest
check_PROGRAMS = $(AXIS_MANIP_TARGETS)

energy_transfer_test_SOURCES = energy_transfer_test.cpp

init_scatt_wavevector_to_scalar_Q_test_SOURCES = init_scatt_wavevector_to_scalar_Q_test.cpp

tof_to_wavelength_test_SOURCES = tof_to_wavelength_test.cpp

tof_to_initial_wavelength_igs_test_SOURCES = tof_to_initial_wavelength_igs_test.cpp

wavelength_to_energy_test_SOURCES = wavelength_to_energy_test.cpp

wavelength_to_scalar_k_test_SOURCES = wavelength_to_scalar_k_test.cpp

DISTCLEANFILES = atconfig

test: check

$(srcdir)/package.m4:   $(top_srcdir)/configure.ac
	{\
                echo '# Signature of the current package.'; \
                echo 'm4_define([AT_PACKAGE_NAME],      [@PACKAGE_NAME@])'; \
                echo 'm4_define([AT_PACKAGE_TARNAME],   [@PACKAGE_TARNAME@])'; \
                echo 'm4_define([AT_PACKAGE_VERSION],   [@PACKAGE_VERSION@])'; \
                echo 'm4_define([AT_PACKAGE_STRING],    [@PACKAGE_STRING@])'; \
                echo 'm4_define([AT_PACKAGE_BUGREPORT], [@PACKAGE_BUGREPORT@])'; \
	} > $(srcdir)/package.m4

check-local:    $(TESTSUITE) 
	$(SHELL) $(TESTSUITE)

$(TESTSUITE):   $(srcdir)/testsuite.at $(TESTSUITE_AT) $(srcdir)/package.m4
	$(AUTOTEST) -I $(srcdir) $@.at -o $@.tmp
	mv $@.tmp $@

atconfig:       $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@

clean-local:
	-$(SHELL) $(TESTSUITE) --clean
