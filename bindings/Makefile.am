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

LIBPYARRAYMANIP=libPyArrayManip.la
LIBPYAXISMANIP=libPyAxisManip.la
LIBPYPHYSCORR=libPyPhysCorr.la
LIBPYUTILS=libPyUtils.la

ARRAYMANIP_SWIG=array_manip.i
AXISMANIP_SWIG=axis_manip.i
PHYSCORR_SWIG=phys_corr.i
UTILS_SWIG=utils.i

ARRAYMANIP_PYTHONWRAP=array_manip_wrap.cpp
AXISMANIP_PYTHONWRAP=axis_manip_wrap.cpp
PHYSCORR_PYTHONWRAP=phys_corr_wrap.cpp
UTILS_PYTHONWRAP=utils_wrap.cpp

ARRAY_MANIP_INC=-I$(top_srcdir)/array_manip/inc
AXIS_MANIP_INC=-I$(top_srcdir)/axis_manip/inc
PHYS_CORR_INC=-I$(top_srcdir)/phys_corr/inc
UTILS_INC=-I$(top_srcdir)/utils/inc
NESSI_INC=-I$(top_srcdir)/nessi/inc

ARRAY_MANIP_LIB=-L$(top_srcdir)/array_manip/src/.libs
AXIS_MANIP_LIB=-L$(top_srcdir)/axis_manip/src/.libs
PHYS_CORR_LIB=-L$(top_srcdir)/phys_corr/src/.libs
UTILS_LIB=-L$(top_srcdir)/utils/src/.libs

ARRAY_MANIP_SRC=$(top_srcdir)/array_manip/src/*.lo
AXIS_MANIP_SRC=$(top_srcdir)/axis_manip/src/*.lo
PHYS_CORR_SRC=$(top_srcdir)/phys_corr/src/*.lo
UTILS_SRC=$(top_srcdir)/utils/src/*.lo

PYARRAYMANIP_INTERFACE=$(subst .la,,$(LIBPYARRAYMANIP))
PYAXISMANIP_INTERFACE=$(subst .la,,$(LIBPYAXISMANIP))
PYPHYSCORR_INTERFACE=$(subst .la,,$(LIBPYPHYSCORR))
PYUTILS_INTERFACE=$(subst .la,,$(LIBPYUTILS))

EXTRA_SWIG=-lvector.i

PYTHON_INC=-I$(PYTHONROOT)/include/python$(PYTHON_VERSION)

pkglib_LTLIBRARIES=$(LIBPYARRAYMANIP) $(LIBPYAXISMANIP) $(LIBPYPHYSCORR) \
		$(LIBPYUTILS)

pkgpython_HEADERS = \
	array_manip_bind.py \
	axis_manip_bind.py \
	phys_corr_bind.py \
	utils_bind.py

EXTRA_DIST = *.i

BUILT_SOURCES = $(ARRAYMANIPPYTHONWRAP) $(AXISMANIPPYTHONWRAP) \
		$(PHYSCORRPYTHONWRAP) $(UTILSPYTHONWRAP)

clean:
	rm -f *bind.py *.o *.lo *_wrap.cpp
	rm -rf .libs _libs
	test -z "libPyArrayManip.la" || rm -f libPyArrayManip.la
	test -z "libPyAxisManip.la" || rm -f libPyAxisManip.la
	test -z "libPyPhysCorr.la" || rm -f libPyPhysCorr.la
	test -z "libPyUtils.la" || rm -f libPyUtils.la

# python wrappers

if HAVE_SWIG
if HAVE_PYTHON
nodist_libPyArrayManip_la_SOURCES=$(ARRAYMANIP_PYTHONWRAP) 
libPyArrayManip_la_CPPFLAGS= $(PYTHON_INC) $(ARRAY_MANIP_INC) $(NESSI_INC) \
			$(CFLAGS) 
libPyArrayManip_la_LDFLAGS=$(LDFLAGS) $(PYLIB_ARRAY_MANIP_VERSION) \
			$(ARRAY_MANIP_SRC) $(UTILS_SRC)
libPyArrayManip_la_LIBS=$(ARRAY_MANIP_LIB) $(UTILS_LIBS)
$(ARRAYMANIP_PYTHONWRAP): $(ARRAYMANIP_SWIG)
	$(SWIG) -c++ -o $@ -python $(ARRAY_MANIP_INC) $(NESSI_INC) \
	$(EXTRA_SWIG) -interface $(PYARRAYMANIP_INTERFACE) $<
endif
endif

if HAVE_SWIG
if HAVE_PYTHON
nodist_libPyAxisManip_la_SOURCES=$(AXISMANIP_PYTHONWRAP) 
libPyAxisManip_la_CPPFLAGS= $(PYTHON_INC) $(AXIS_MANIP_INC) $(NESSI_INC) \
			$(CFLAGS) 
libPyAxisManip_la_LDFLAGS=$(LDFLAGS) $(PYLIB_AXIS_MANIP_VERSION) \
			$(AXIS_MANIP_SRC) $(UTILS_SRC)
libPyAxisManip_la_LIBS=$(AXIS_MANIP_LIB) $(UTILS_LIB)
$(AXISMANIP_PYTHONWRAP): $(AXISMANIP_SWIG) 
	$(SWIG) -c++ -o $@ -python $(AXIS_MANIP_INC) $(NESSI_INC) \
	$(EXTRA_SWIG) -interface $(PYAXISMANIP_INTERFACE) $<
endif
endif

if HAVE_SWIG
if HAVE_PYTHON
nodist_libPyPhysCorr_la_SOURCES=$(PHYSCORR_PYTHONWRAP) 
libPyPhysCorr_la_CPPFLAGS= $(PYTHON_INC) $(PHYS_CORR_INC) $(NESSI_INC) \
			$(CFLAGS) 
libPyPhysCorr_la_LDFLAGS=$(LDFLAGS) $(PYLIB_PHYS_CORR_VERSION) $(PHYS_CORR_SRC)
libPyPhysCorr_la_LIBS=$(PHYS_CORR_LIB)
$(PHYSCORR_PYTHONWRAP): $(PHYSCORR_SWIG) 
	$(SWIG) -c++ -o $@ -python $(PHYS_CORR_INC) $(NESSI_INC) \
	$(EXTRA_SWIG) -interface $(PYPHYSCORR_INTERFACE) $<
endif
endif

if HAVE_SWIG
if HAVE_PYTHON

nodist_libPyUtils_la_SOURCES=$(UTILS_PYTHONWRAP) 
libPyUtils_la_CPPFLAGS= $(PYTHON_INC) $(UTILS_INC) $(NESSI_INC) $(CFLAGS) 
libPyUtils_la_LDFLAGS=$(LDFLAGS) $(PYLIB_UTILS_VERSION) $(UTILS_SRC)
libPyUtils_la_LIBS=$(UTILS_LIB)
$(UTILS_PYTHONWRAP): $(UTILS_SWIG) 
	$(SWIG) -c++ -o $@ -python $(UTILS_INC) $(NESSI_INC) $(EXTRA_SWIG) \
	-interface $(PYUTILS_INTERFACE) $<
endif
endif
