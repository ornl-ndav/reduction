# $Id$

test: check

AM_CPPFLAGS = -I. -I$(top_srcdir)/array_manip/inc -I$(top_srcdir)/nessi
AM_LDFLAGS  = -static \
              -L$(top_srcdir)/array_manip/src/.libs -lArrayManip

EXTRA_DIST=testsuite.at

ARRAY_MANIP_TARGETS = \
	add_scalar_vec_ncerr_test \
	sub_scalar_vec_ncerr_test \
	mult_scalar_vec_ncerr_test \
	div_scalar_vec_ncerr_test \
	div_vec_scalar_ncerr_test \
	add_vec_vec_ncerr_test \
	sub_vec_vec_ncerr_test \
	mult_vec_vec_ncerr_test \
	div_vec_vec_ncerr_test \
	sumw_vec_vec_ncerr_test

TESTSUITE	= $(srcdir)/testsuite
TESTSUITE_AT	= ## dbase.at devices.at starter.at
AUTOTEST	= $(AUTOM4TE) --language=autotest
check_PROGRAMS = $(ARRAY_MANIP_TARGETS)

add_scalar_vec_ncerr_test_SOURCES = add_scalar_vec_ncerr_test.cpp

sub_scalar_vec_ncerr_test_SOURCES = sub_scalar_vec_ncerr_test.cpp

mult_scalar_vec_ncerr_test_SOURCES = mult_scalar_vec_ncerr_test.cpp

div_scalar_vec_ncerr_test_SOURCES = div_scalar_vec_ncerr_test.cpp

div_vec_scalar_ncerr_test_SOURCES = div_vec_scalar_ncerr_test.cpp

add_vec_vec_ncerr_test_SOURCES = add_vec_vec_ncerr_test.cpp

sub_vec_vec_ncerr_test_SOURCES = sub_vec_vec_ncerr_test.cpp

mult_vec_vec_ncerr_test_SOURCES = mult_vec_vec_ncerr_test.cpp

div_vec_vec_ncerr_test_SOURCES = div_vec_vec_ncerr_test.cpp

sumw_vec_vec_ncerr_test_SOURCES = sumw_vec_vec_ncerr_test.cpp

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
