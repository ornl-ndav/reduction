dnl $Id$

AC_INIT([SNS Common Libraries], [0.1.0], [bilheuxjm@ornl.gov,petersonpf@ornl.gov,reuterma@ornl.gov], [sns_common_lib])
AC_COPYRIGHT([Copyright (C) 2005 SNS Analysis Software Group 
This software is covered by the MIT ACADEMIC LICENSE
see file COPYING for further information])

AC_CONFIG_AUX_DIR(config)
AM_CONFIG_HEADER(config/snsdrlibconfig.h:config/snsdrlibconfig_h.in)
AC_CONFIG_SRCDIR(array_manip/src/add_vec_vec_ncerr.cpp)
AC_CANONICAL_TARGET

if test ! -z "$srcdir"; then
   . $srcdir/autoversion.sh
else
   . ./autoversion.sh
fi

AM_INIT_AUTOMAKE([1.9])

AM_PATH_PYTHON(,, :)
AC_CHECK_ROOT([python],[PYTHONROOT],[/usr /usr/local],[include/python$PYTHON_VE\RSION/Python.h])

DRLIBDOCDIR='${datadir}/$(PACKAGE_TARNAME)/doc'
AC_SUBST(DRLIBDOCDIR)

AC_PROG_CXX
if test $GXX = yes; then
	CXXFLAGS="$CXXFLAGS -Wall"
fi
AC_PROG_LIBTOOL

AC_CHECK_PROGS(SWIG, [swig])
AC_CHECK_PROGS(DOXYGEN, [doxygen])

AM_CONDITIONAL(HAVE_PYTHON, [test ! -z "$PYTHONROOT"])
AM_CONDITIONAL(HAVE_SWIG, [test ! -z "$SWIG"])
AM_CONDITIONAL(HAVE_DOXYGEN, [test ! -z "$DOXYGEN"])

dnl AC_CONFIG_TESTDIR([array_manip/test
dnl	axis_manip/test
dnl	])

AC_CONFIG_FILES([array_manip/test/Makefile 
		array_manip/test/cpp/Makefile
		axis_manip/test/Makefile
		axis_manip/test/cpp/Makefile
		])
AM_MISSING_PROG([AUTOM4TE], [autom4te])

AC_CONFIG_FILES([Makefile
		array_manip/Makefile
		array_manip/inc/Makefile
		array_manip/src/Makefile
		axis_manip/Makefile
		axis_manip/inc/Makefile
		axis_manip/src/Makefile		
		phys_corr/Makefile
		phys_corr/inc/Makefile
		phys_corr/src/Makefile
		utils/Makefile
		utils/inc/Makefile
		utils/src/Makefile
		bindings/Makefile
		doc/Makefile
		])
AC_OUTPUT

if test -n "$SWIG" ; then 
    SWIGBINDING="yes ("
    test -n "$PYTHONROOT" && SWIGBINDING="$SWIGBINDING python"
    SWIGBINDING="$SWIGBINDING )"
else
    SWIGBINDING=no
fi
AC_MSG_RESULT([

Configuration (SNS Data Reduction Library):

        Source code location:  ${srcdir}
        Version:               ${VERSION}
        Compiler:              ${CXX}
	Documentation:	       ${DOXYGEN}

build:
        bindings:
                SWIG:          ${SWIGBINDING}

Please check whether the configuration I detected matches what you
would like to have.
])