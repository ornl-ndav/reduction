dnl                     SNS Common Libraries
dnl           A part of the SNS Analysis Software Suite.
dnl
dnl                  Spallation Neutron Source
dnl          Oak Ridge National Laboratory, Oak Ridge TN.
dnl
dnl
dnl                             NOTICE
dnl
dnl For this software and its associated documentation, permission is granted
dnl to reproduce, prepare derivative works, and distribute copies to the
dnl public for any purpose and without fee.
dnl
dnl This material was prepared as an account of work sponsored by an agency of
dnl the United States Government.  Neither the United States Government nor the
dnl United States Department of Energy, nor any of their employees, makes any
dnl warranty, express or implied, or assumes any legal liability or
dnl responsibility for the accuracy, completeness, or usefulness of any
dnl information, apparatus, product, or process disclosed, or represents that
dnl its use would not infringe privately owned rights.

dnl $Id$

AC_PREREQ(2.59)
AC_REVISION($Revision$)
AC_INIT([SNS Common Libraries], [1.0.0itc3], [bilheuxjm@ornl.gov,petersonpf@ornl.gov,reuterma@ornl.gov], [sns_common_libs])
AC_COPYRIGHT([This software is covered by the MIT ACADEMIC LICENSE
see file COPYING for further information])

AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR(array_manip/src/add_ncerr.cpp)
AC_CANONICAL_TARGET

if test ! -z "$srcdir"; then
   . $srcdir/autoversion.sh
else
   . ./autoversion.sh
fi

AM_INIT_AUTOMAKE([1.9])

AM_CONFIG_HEADER(config/snscomlibconfig.h:config/snscomlibconfig_h.in)

AC_ARG_ENABLE(pdfdoc,
[  --enable-pdfdoc    Create a PDF version of the documentation],
[case "${enableval}" in
  yes) pdfdoc=true ;;
  no)  pdfdoc=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-pdfdoc) ;;
esac],[pdfdoc=false])
AM_CONDITIONAL(PDFDOC, test x$pdfdoc = xtrue)

AM_PATH_PYTHON(2.3, :)
AC_CHECK_ROOT([python],[PYTHONROOT],[/usr /usr/local],[include/python$PYTHON_VERSION/Python.h])

DRLIBDOCDIR='${datadir}/$(PACKAGE_TARNAME)/doc'
AC_SUBST(DRLIBDOCDIR)

# Collect all the library version numbers here
LIB_ARRAY_MANIP_VERSION='-version-info 1:0:0'
AC_SUBST(LIB_ARRAY_MANIP_VERSION)
LIB_AXIS_MANIP_VERSION='-version-info 1:0:0'
AC_SUBST(LIB_AXIS_MANIP_VERSION)
LIB_PHYS_CORR_VERSION='-version-info 1:0:0'
AC_SUBST(LIB_PHYS_CORR_VERSION)
LIB_UTILS_VERSION='-version-info 1:0:0'
AC_SUBST(LIB_UTILS_VERSION)
PYLIB_ARRAY_MANIP_VERSION='-version-info 1:0:0'
AC_SUBST(PYLIB_ARRAY_MANIP_VERSION)
PYLIB_AXIS_MANIP_VERSION='-version-info 1:0:0'
AC_SUBST(PYLIB_AXIS_MANIP_VERSION)
PYLIB_NESSI_VECTOR_VERSION='-version-info 1:0:0'
AC_SUBST(PYLIB_NESSI_VECTOR_VERSION)
PYLIB_PHYS_CORR_VERSION='-version-info 1:0:0'
AC_SUBST(PYLIB_PHYS_CORR_VERSION)
PYLIB_UTILS_VERSION='-version-info 1:0:0'
AC_SUBST(PYLIB_UTILS_VERSION)

AC_PROG_CXX
if test $GXX = yes; then
	CXXFLAGS="$CXXFLAGS -Wall"
fi
AC_PROG_LIBTOOL

AC_CHECK_PROGS(SWIG, [swig])
AC_CHECK_PROGS(DOXYGEN, [doxygen])
AC_CHECK_PROGS(DOT, [dot])

AM_CONDITIONAL(HAVE_PYTHON, [test ! -z "$PYTHONROOT"])
AM_CONDITIONAL(HAVE_SWIG, [test ! -z "$SWIG"])
AM_CONDITIONAL(HAVE_DOXYGEN, [test ! -z "$DOXYGEN"])
AM_CONDITIONAL(HAVE_DOT, [test ! -z "$DOT"])

AC_CONFIG_FILES([array_manip/test/Makefile
		array_manip/test/cpp/Makefile
		axis_manip/test/Makefile
		axis_manip/test/cpp/Makefile
		utils/test/Makefile
		utils/test/cpp/Makefile
		])
AM_MISSING_PROG([AUTOM4TE], [autom4te])

AC_CONFIG_FILES([Makefile
		nessi/Makefile
		nessi/inc/Makefile
		array_manip/Makefile
		array_manip/inc/Makefile
		array_manip/src/Makefile
		axis_manip/Makefile
		axis_manip/inc/Makefile
		axis_manip/src/Makefile
		phys_const/Makefile
		phys_const/inc/Makefile
		phys_const/src/Makefile
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

if test -n "$DOT" ; then
    DOTISCOOL="You will have cool UML diagrams available.
                               Aren't you lucky!"
else
    DOTISCOOL="You will have ugly looking UML diagrams.
                               It is recommended to get graphviz!"
fi

if test $pdfdoc == "true" ; then
   MAKEPDF="yes"
else
   MAKEPDF="no"
fi

AC_MSG_RESULT([

Configuration (SNS Common Libraries):

        Source code location:  ${srcdir}
        Version:               ${VERSION}
        Compiler:              ${CXX}

documentation:
	Generator:	       ${DOXYGEN}
	Dot:		       ${DOTISCOOL}
	PDF Version:	       ${MAKEPDF}

build:
        bindings:
                SWIG:          ${SWIGBINDING}

Please check whether the configuration I detected matches what you
would like to have.
])
