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

ARRAYMANIP_SWIG=array_manip.i
AXISMANIP_SWIG=axis_manip.i
NESSIVECTOR_SWIG=nessi_vector.i
PHYSCORR_SWIG=phys_corr.i
UTILS_SWIG=utils.i
VPAIR_SWIG=vpair.i

ARRAYMANIP_BASE=$(subst .i,,$(ARRAYMANIP_SWIG))
AXISMANIP_BASE=$(subst .i,,$(AXISMANIP_SWIG))
NESSIVECTOR_BASE=$(subst .i,,$(NESSIVECTOR_SWIG))
PHYSCORR_BASE=$(subst .i,,$(PHYSCORR_SWIG))
UTILS_BASE=$(subst .i,,$(UTILS_SWIG))
VPAIR_BASE=$(subst .i,,$(VPAIR_SWIG))

ARRAYMANIP_PYTHONWRAP=array_manip_wrap.cpp
AXISMANIP_PYTHONWRAP=axis_manip_wrap.cpp
NESSIVECTOR_PYTHONWRAP=nessi_vector_wrap.cpp
PHYSCORR_PYTHONWRAP=phys_corr_wrap.cpp
UTILS_PYTHONWRAP=utils_wrap.cpp
VPAIR_PYTHONWRAP=vpair_wrap.cpp

ARRAYMANIP_PBL=$(ARRAYMANIP_BASE)_bind.py
AXISMANIP_PBL=$(AXISMANIP_BASE)_bind.py
NESSIVECTOR_PBL=$(NESSIVECTOR_BASE)_bind.py
PHYSCORR_PBL=$(PHYSCORR_BASE)_bind.py
UTILS_PBL=$(UTILS_BASE)_bind.py
VPAIR_PBL=$(VPAIR_BASE)_bind.py

LIBPYARRAYMANIP=libPyArrayManip.la
LIBPYAXISMANIP=libPyAxisManip.la
LIBPYNESSIVECTOR=libPyNessiVector.la
LIBPYPHYSCORR=libPyPhysCorr.la
LIBPYUTILS=libPyUtils.la
LIBPYVPAIR=libPyVPair.la

ARRAY_MANIP_INC=-I$(top_srcdir)/array_manip/inc
AXIS_MANIP_INC=-I$(top_srcdir)/axis_manip/inc
PHYS_CORR_INC=-I$(top_srcdir)/phys_corr/inc
UTILS_INC=-I$(top_srcdir)/utils/inc
NESSI_INC=-I$(top_srcdir)/nessi/inc
VPAIR_INC=-I$(top_srcdir)/bindings

ARRAYMANIP_LIB=$(top_builddir)/array_manip/src/.libs/libArrayManip.la
AXISMANIP_LIB=$(top_builddir)/axis_manip/src/.libs/libAxisManip.la
PHYSCORR_LIB=$(top_builddir)/phys_corr/src/.libs/libPhysCorr.la
UTILS_LIB=$(top_builddir)/utils/src/.libs/libUtils.la

PYARRAYMANIP_INTERFACE=$(subst .la,,$(LIBPYARRAYMANIP))
PYAXISMANIP_INTERFACE=$(subst .la,,$(LIBPYAXISMANIP))
PYNESSIVECTOR_INTERFACE=$(subst .la,,$(LIBPYNESSIVECTOR))
PYPHYSCORR_INTERFACE=$(subst .la,,$(LIBPYPHYSCORR))
PYUTILS_INTERFACE=$(subst .la,,$(LIBPYUTILS))
PYVPAIR_INTERFACE=$(subst .la,,$(LIBPYVPAIR))

ARRAYMANIP_PAL=$(ARRAYMANIP_BASE).py
AXISMANIP_PAL=$(AXISMANIP_BASE).py
PHYSCORR_PAL=$(PHYSCORR_BASE).py
UTILS_PAL=$(UTILS_BASE).py

PYTHON_INC=-I$(PYTHONROOT)/include/python$(PYTHON_VERSION)

pkgpython_LTLIBRARIES=$(LIBPYARRAYMANIP) $(LIBPYAXISMANIP) \
	$(LIBPYNESSIVECTOR) $(LIBPYPHYSCORR) $(LIBPYUTILS) $(LIBPYVPAIR)

SWIG_FILES = \
	$(ARRAYMANIP_SWIG) \
	$(AXISMANIP_SWIG) \
	libexcept.i \
	$(NESSIVECTOR_SWIG) \
	$(PHYSCORR_SWIG) \
	$(UTILS_SWIG) \
	$(VPAIR_SWIG) 

PBL_FILES = \
	$(ARRAYMANIP_PBL) \
	$(AXISMANIP_PBL) \
	$(NESSIVECTOR_PBL) \
	$(PHYSCORR_PBL) \
	$(UTILS_PBL) \
	$(VPAIR_PBL) 

PYTHON_WRAPPERS = \
	$(ARRAYMANIP_PYTHONWRAP) \
	$(AXISMANIP_PYTHONWRAP) \
	$(NESSIVECTOR_PYTHONWRAP) \
	$(PHYSCORR_PYTHONWRAP) \
	$(UTILS_PYTHONWRAP) \
	$(VPAIR_PYTHONWRAP) 

# Files for the Python Abstraction Layer (PAL)
PAL_FILES = \
	$(ARRAYMANIP_PAL) \
	$(AXISMANIP_PAL) \
	scl_defs.py \
	nessi_list.py \
	$(PHYSCORR_PAL) \
	$(UTILS_PAL)

python_PYTHON = sns_common_libs.pth

pkgpython_PYTHON = \
	$(PAL_FILES) \
	$(PBL_FILES)

EXTRA_DIST = $(SWIG_FILES) vpair.hpp scl_defs.py.in

DISTCLEANFILES = scl_defs.py

if OPTSWIG
SWIGOPT= -O
else
SWIGOPT=
endif

if FIXSO
install-exec-hook:
	for file in $$(ls -1 $(pkgpythondir)/*.la); do \
		temp=$$(echo $$file | sed 's/\.[^\.]*$$//'); \
		ln -s $${temp}.dylib $${temp}.so; \
	done
endif

clean-local:
	rm -f $(PBL_FILES) $(PYTHON_WRAPPERS)
	rm -rf .libs _libs

dist-hook:
	rm -f $(distdir)/*_bind.py
	rm -f $(distdir)/scl_defs.py

# python wrappers

if HAVE_SWIG
if HAVE_PYTHON
nodist_libPyArrayManip_la_SOURCES=$(ARRAYMANIP_PYTHONWRAP)
libPyArrayManip_la_CPPFLAGS=$(PYTHON_INC) $(ARRAY_MANIP_INC) $(NESSI_INC) \
			$(CFLAGS)
libPyArrayManip_la_LDFLAGS=$(PYLIB_ARRAY_MANIP_VERSION) \
			$(ARRAYMANIP_LIB) $(UTILS_LIB) $(LDFLAGS) 
$(ARRAYMANIP_PYTHONWRAP) $(ARRAYMANIP_PBL): $(ARRAYMANIP_SWIG)
	$(SWIG) -c++ -o $(ARRAYMANIP_PYTHONWRAP) -python $(SWIGOPT) \
	$(ARRAY_MANIP_INC) -interface $(PYARRAYMANIP_INTERFACE) $<
endif
endif

if HAVE_SWIG
if HAVE_PYTHON
nodist_libPyAxisManip_la_SOURCES=$(AXISMANIP_PYTHONWRAP)
libPyAxisManip_la_CPPFLAGS= $(PYTHON_INC) $(AXIS_MANIP_INC) $(NESSI_INC) \
			$(CFLAGS)
libPyAxisManip_la_LDFLAGS=$(PYLIB_AXIS_MANIP_VERSION) \
			$(AXISMANIP_LIB) $(UTILS_LIB) $(LDFLAGS) 
$(AXISMANIP_PYTHONWRAP) $(AXISMANIP_PBL): $(AXISMANIP_SWIG)
	$(SWIG) -c++ -o $(AXISMANIP_PYTHONWRAP) -python $(SWIGOPT) \
	$(AXIS_MANIP_INC) -interface $(PYAXISMANIP_INTERFACE) $<
endif
endif

if HAVE_SWIG
if HAVE_PYTHON
nodist_libPyNessiVector_la_SOURCES=$(NESSIVECTOR_PYTHONWRAP)
libPyNessiVector_la_CPPFLAGS= $(PYTHON_INC) $(NESSI_INC) $(CFLAGS)
libPyNessiVector_la_LDFLAGS=$(PYLIB_NESSI_VECTOR_VERSION) $(LDFLAGS)
$(NESSIVECTOR_PYTHONWRAP) $(NESSIVECTOR_PBL): $(NESSIVECTOR_SWIG)
	$(SWIG) -c++ -o $(NESSIVECTOR_PYTHONWRAP) -python $(SWIGOPT) \
	$(NESSI_INC) -interface $(PYNESSIVECTOR_INTERFACE) $<
endif
endif

if HAVE_SWIG
if HAVE_PYTHON
nodist_libPyPhysCorr_la_SOURCES=$(PHYSCORR_PYTHONWRAP)
libPyPhysCorr_la_CPPFLAGS= $(PYTHON_INC) $(PHYS_CORR_INC) $(NESSI_INC) \
			$(CFLAGS)
libPyPhysCorr_la_LDFLAGS=$(PYLIB_PHYS_CORR_VERSION) $(PHYSCORR_LIB) \
			$(UTILS_LIB) $(LDFLAGS)
$(PHYSCORR_PYTHONWRAP) $(PHYSCORR_PBL): $(PHYSCORR_SWIG)
	$(SWIG) -c++ -o $(PHYSCORR_PYTHONWRAP) -python $(SWIGOPT) \
	$(PHYS_CORR_INC) -interface $(PYPHYSCORR_INTERFACE) $<
endif
endif

if HAVE_SWIG
if HAVE_PYTHON
nodist_libPyUtils_la_SOURCES=$(UTILS_PYTHONWRAP)
libPyUtils_la_CPPFLAGS= $(PYTHON_INC) $(UTILS_INC) $(NESSI_INC) $(CFLAGS)
libPyUtils_la_LDFLAGS=$(PYLIB_UTILS_VERSION) $(UTILS_LIB) $(LDFLAGS) 
$(UTILS_PYTHONWRAP) $(UTILS_PBL): $(UTILS_SWIG)
	$(SWIG) -c++ -o $(UTILS_PYTHONWRAP) -python $(SWIGOPT) \
	$(UTILS_INC) -interface $(PYUTILS_INTERFACE) $<
endif
endif

if HAVE_SWIG
if HAVE_PYTHON
nodist_libPyVPair_la_SOURCES=$(VPAIR_PYTHONWRAP) 
libPyVPair_la_CPPFLAGS= $(PYTHON_INC) $(VPAIR_INC) $(CFLAGS) 
libPyVPair_la_LDFLAGS=$(PYLIB_VPAIR_VERSION) $(LDFLAGS)
$(VPAIR_PYTHONWRAP) $(VPAIR_PBL): $(VPAIR_SWIG) 
	$(SWIG) -c++ -o $(VPAIR_PYTHONWRAP) -python $(SWIGOPT) \
	$(VPAIR_INC) -interface $(PYVPAIR_INTERFACE) $<
endif
endif
