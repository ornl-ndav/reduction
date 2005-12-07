# $Id$

clean:
	rm -f *.py *.o *.lo *_wrap.cpp
	rm -rf .libs _libs
	test -z "libPyArrayManip.la" || rm -f libPyArrayManip.la
	test -z "libPyAxisManip.la" || rm -f libPyAxisManip.la
	test -z "libPyPhysCorr.la" || rm -f libPyPhysCorr.la
	test -z "libPyUtils.la" || rm -f libPyUtils.la

ARRAY_MANIP_INC=-I$(top_srcdir)/array_manip/inc
AXIS_MANIP_INC=-I$(top_srcdir)/axis_manip/inc
PHYS_CORR_INC=-I$(top_srcdir)/phys_corr/inc
UTILS_INC=-I$(top_srcdir)/utils/inc

ARRAY_MANIP_LIB=-L$(top_srcdir)/array_manip/src/.libs
AXIS_MANIP_LIB=-L$(top_srcdir)/axis_manip/src/.libs
PHYS_CORR_LIB=-L$(top_srcdir)/phys_corr/src/.libs
UTILS_LIB=-L$(top_srcdir)/utils/src/.libs

ARRAY_MANIP_SRC=$(top_srcdir)/array_manip/src/*.lo
AXIS_MANIP_SRC=$(top_srcdir)/axis_manip/src/*.lo
PHYS_CORR_SRC=$(top_srcdir)/phys_corr/src/*.lo
UTILS_SRC=$(top_srcdir)/utils/src/*.lo

PYTHON_INC=-I$(PYTHONROOT)/include/python$(PYTHON_VERSION)

lib_LTLIBRARIES=$(LIBPYARRAYMANIP) $(LIBPYAXISMANIP) $(LIBPYPHYSCORR) $(LIBPYUTILS)

# python wrappers

if HAVE_SWIG
if HAVE_PYTHON
LIBPYARRAYMANIP=libPyArrayManip.la
libPyArrayManip_la_SOURCES=$(ARRAYMANIPPYTHONWRAP) 
libPyArrayManip_la_CPPFLAGS= $(PYTHON_INC) $(ARRAY_MANIP_INC) $(CFLAGS) 
libPyArrayManip_la_LDFLAGS=$(LDFLAGS) $(ARRAY_MANIP_SRC)
libPyArrayManip_la_LIBS=$(ARRAY_MANIP_LIB)
ARRAYMANIPPYTHONWRAP=array_manip_wrap.cpp
endif
array_manip_wrap.cpp: array_manip.i 
	$(SWIG) -c++ -o $@ -python $(ARRAY_MANIP_INC) -lvector.i \
	-interface libPyArrayManip array_manip.i 
endif

if HAVE_SWIG
if HAVE_PYTHON
LIBPYAXISMANIP=libPyAxisManip.la
libPyAxisManip_la_SOURCES=$(AXISMANIPPYTHONWRAP) 
libPyAxisManip_la_CPPFLAGS= $(PYTHON_INC) $(AXIS_MANIP_INC) $(CFLAGS) 
libPyAxisManip_la_LDFLAGS=$(LDFLAGS) $(AXIS_MANIP_SRC)
libPyAxisManip_la_LIBS=$(AXIS_MANIP_LIB)
AXISMANIPPYTHONWRAP=axis_manip_wrap.cpp
endif
axis_manip_wrap.cpp: axis_manip.i 
	$(SWIG) -c++ -o $@ -python $(AXIS_MANIP_INC) -lvector.i \
	-interface libPyAxisManip axis_manip.i 
endif

if HAVE_SWIG
if HAVE_PYTHON
LIBPYPHYSCORR=libPyPhysCorr.la
libPyPhysCorr_la_SOURCES=$(PHYSCORRPYTHONWRAP) 
libPyPhysCorr_la_CPPFLAGS= $(PYTHON_INC) $(PHYS_CORR_INC) $(CFLAGS) 
libPyPhysCorr_la_LDFLAGS=$(LDFLAGS) $(PHYS_CORR_SRC)
libPyPhysCorr_la_LIBS=$(PHYS_CORR_LIB)
PHYSCORRPYTHONWRAP=phys_corr_wrap.cpp
endif
phys_corr_wrap.cpp: phys_corr.i 
	$(SWIG) -c++ -o $@ -python $(PHYS_CORR_INC) -lvector.i \
	-interface libPyPhysCorr phys_corr.i 
endif

if HAVE_SWIG
if HAVE_PYTHON
LIBPYUTILS=libPyUtils.la
libPyUtils_la_SOURCES=$(UTILSPYTHONWRAP) 
libPyUtils_la_CPPFLAGS= $(PYTHON_INC) $(UTILS_INC) $(CFLAGS) 
libPyUtils_la_LDFLAGS=$(LDFLAGS) $(UTILS_SRC)
libPyUtils_la_LIBS=$(UTILS_LIB)
UTILSPYTHONWRAP=utils_wrap.cpp
endif
utils_wrap.cpp: utils.i 
	$(SWIG) -c++ -o $@ -python $(UTILS_INC) -lvector.i \
	-interface libPyUtils utils.i
endif

python_HEADERS = \
	array_manip.py \
	axis_manip.py \
	phys_corr.py \
	utils.py

EXTRA_DIST = *.i
nodist_EXTRA_DIST = *_wrap.cpp
