# $Id$

test: check

AM_CPPFLAGS = -I. -I$(top_srcdir)/axis_manip/inc

AXIS_MANIP_TARGETS = \
	tof_to_initial_wavelength_igs_test \
	tof_to_wavelength_test \
	wavelength_to_energy_test \
	wavelength_to_scalar_k_test \
	init_scatt_wavevector_to_scalar_Q_test 

TESTSUITE	= $(srcdir)/testsuite
TESTSUITE_AT	= ## dbase.at devices.at starter.at
AUTOTEST	= $(AUTOM4TE) --language=autotest
check_PROGRAMS = $(AXIS_MANIP_TARGETS)

init_scatt_wavevector_to_scalar_Q_test_SOURCES = init_scatt_wavevector_to_scalar_Q_test.cpp
init_scatt_wavevector_to_scalar_Q_test_CPPFLAGS = @CPPFLAGS@ -I$(top_srcdir)/axis_manip/inc -I$(top_srcdir)/utils/inc
init_scatt_wavevector_to_scalar_Q_test_LDADD = $(top_srcdir)/axis_manip/src/init_scatt_wavevector_to_scalar_Q.o $(top_srcdir)/utils/src/fd_comparison.o $(top_srcdir)/utils/src/iu_comparison.o

tof_to_wavelength_test_SOURCES = tof_to_wavelength_test.cpp
tof_to_wavelength_test_CPPFLAGS = @CPPFLAGS@ -I$(top_srcdir)/axis_manip/inc
tof_to_wavelength_test_LDADD = $(top_srcdir)/axis_manip/src/tof_to_wavelength.o

tof_to_initial_wavelength_igs_test_SOURCES = tof_to_initial_wavelength_igs_test.cpp
tof_to_initial_wavelength_igs_test_CPPFLAGS = @CPPFLAGS@ -I$(top_srcdir)/axis_manip/inc
tof_to_initial_wavelength_igs_test_LDADD = $(top_srcdir)/axis_manip/src/tof_to_initial_wavelength_igs.o

wavelength_to_energy_test_SOURCES = wavelength_to_energy_test.cpp
wavelength_to_energy_test_CPPFLAGS = @CPPFLAGS@ -I$(top_srcdir)/axis_manip/inc
wavelength_to_energy_test_LDADD = $(top_srcdir)/axis_manip/src/wavelength_to_energy.o

wavelength_to_scalar_k_test_SOURCES = wavelength_to_scalar_k_test.cpp
wavelength_to_scalar_k_test_CPPFLAGS = @CPPFLAGS@ -I$(top_srcdir)/axis_manip/inc
wavelength_to_scalar_k_test_LDADD = $(top_srcdir)/axis_manip/src/wavelength_to_scalar_k.o

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


DISTCLEANFILES = atconfig
