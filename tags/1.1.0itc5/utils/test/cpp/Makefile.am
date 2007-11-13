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

AM_CPPFLAGS = -I. -I$(top_srcdir)/utils/inc -I$(top_srcdir)/nessi/inc

AM_CXXFLAGS = $(STOSFLAG)

AM_LDFLAGS  = -static \
              -L$(top_builddir)/utils/src/.libs -lUtils

EXTRA_DIST=testsuite.at testsuite

UTILS_TARGETS = \
	calc_area_2D_polygon_test \
	calc_bin_centers_test \
	calc_bin_widths_test \
	convex_polygon_intersect_test \
	eval_linear_fit_test \
	fit_linear_background_test \
	linear_order_jacobian_test \
	weighted_average_test

TESTSUITE	= $(srcdir)/testsuite
TESTSUITE_AT	= ## dbase.at devices.at starter.at
AUTOTEST	= $(AUTOM4TE) --language=autotest
check_PROGRAMS = $(UTILS_TARGETS)

calc_area_2D_polygon_test_SOURCES = calc_area_2D_polygon_test.cpp \
	test_common.hpp

calc_bin_centers_test_SOURCES = calc_bin_centers_test.cpp test_common.hpp

calc_bin_widths_test_SOURCES = calc_bin_widths_test.cpp test_common.hpp

convex_polygon_intersect_test_SOURCES = convex_polygon_intersect_test.cpp \
	test_common.hpp

eval_linear_fit_test_SOURCES = eval_linear_fit_test.cpp test_common.hpp

fit_linear_background_test_SOURCES = fit_linear_background_test.cpp \
	test_common.hpp

linear_order_jacobian_test_SOURCES = linear_order_jacobian_test.cpp \
	test_common.hpp

weighted_average_test_SOURCES = weighted_average_test.cpp test_common.hpp

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
