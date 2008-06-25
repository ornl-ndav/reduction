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

AM_CPPFLAGS = $(OPENMP_CXX) $(OPENMP_LD) -I. -I$(top_srcdir)/utils/inc \
			-I$(top_srcdir)/nessi/inc 

pkglib_LTLIBRARIES = libUtils.la

libUtils_la_LDFLAGS = $(LIB_UTILS_VERSION)

libUtils_la_SOURCES = \
	advance_edge.hpp \
	advance_edge.cpp \
	aims_at.hpp \
	aims_at.cpp \
	bisect_helper.hpp \
	bisect_helper.cpp \
	calc_area_2D_polygon.hpp \
	calc_area_2D_polygon.cpp \
	calc_bin_centers.hpp \
	calc_bin_centers.cpp \
	calc_bin_widths.hpp \
	calc_bin_widths.cpp \
	check_convex_polygon.hpp \
	check_convex_polygon.cpp \
	check_histo_sizes.hpp \
	check_histo_sizes.cpp \
	check_sizes_square.hpp \
	check_sizes_square.cpp \
	classify_pt_to_edge.hpp \
	classify_pt_to_edge.cpp \
	compare.hpp \
	compare.cpp \
	convex_polygon_intersect.hpp \
	convex_polygon_intersect.cpp \
	crossing_pt.hpp \
	crossing_pt.cpp \
	dot_product.hpp \
	dot_product.cpp \
	edge_pt.hpp \
	edge_pt.cpp \
	edge_intersect.hpp \
	edge_intersect.cpp \
	eval_linear_fit.hpp \
	eval_linear_fit.cpp \
	fit_linear_background.hpp \
	fit_linear_background.cpp \
	fit_reflectometer_background.hpp \
	fit_reflectometer_background.cpp \
	fix_index.cpp \
	fix_index2.cpp \
	linear_order_jacobian.hpp \
	linear_order_jacobian.cpp \
	matrix_multiplication.hpp \
	matrix_multiplication.cpp \
	peak_integration.hpp \
	peak_integration.cpp \
	pt_in_convex_polygon.hpp \
	pt_in_convex_polygon.cpp \
	pt_length.hpp \
	pt_length.cpp \
	vector_is_equals.hpp \
	vector_is_equals.cpp \
	weighted_average.hpp \
	weighted_average.cpp \
	wrap_indicies.cpp
