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
AC_INIT([SNS Common Libraries], [1.3.3], [bilheuxjm@ornl.gov,petersonpf@ornl.gov,reuterma@ornl.gov], [sns_common_libs])
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

AC_ARG_WITH([cxx], AC_HELP_STRING([--with-cxx=c++ compiler], [Specify name of C++ compiler]), [with_cxx=$withval], [with_cxx=yes])
  if test x"$with_cxx" != x"no" ; then
    if test x"$with_cxx" != x"yes" ; then CXX="$with_cxx"; fi
	  AC_PROG_CXX
    else
	  CXX=
  fi

AC_ARG_ENABLE(pdfdoc,
[  --enable-pdfdoc    Create a PDF version of the documentation],
[case "${enableval}" in
  yes) pdfdoc=true ;;
  no)  pdfdoc=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-pdfdoc) ;;
esac],[pdfdoc=false])
AM_CONDITIONAL(PDFDOC, test x$pdfdoc = xtrue)

AC_ARG_ENABLE(optswig,
[  --enable-optswig   Optimize SWIG bindings],
[case "${enableval}" in
  yes) optswig=true ;;
  no)  optswig=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-optswig) ;;
esac],[optswig=false])
AM_CONDITIONAL(OPTSWIG, test x$optswig = xtrue)

# Our code requires Python 2.3
PYTHON_REQUIRED=2.3
AM_PATH_PYTHON($PYTHON_REQUIRED,, :)
if test x$PYTHON = x:; then
   AC_MSG_ERROR([You need python version $PYTHON_REQUIRED to make bindings])
else
   # Need to back up one more since $PYTHON=/path/to/python/bin/python
   TEMP=`dirname $PYTHON`
   PYTHONROOT=`dirname $TEMP`
fi
AC_SUBST(PYTHONROOT)

DRLIBDOCDIR='${datadir}/$(PACKAGE_TARNAME)/doc'
AC_SUBST(DRLIBDOCDIR)

# Collect all the library version numbers here
LIB_ARRAY_MANIP_VERSION='-version-info 3:0:2'
AC_SUBST(LIB_ARRAY_MANIP_VERSION)
LIB_AXIS_MANIP_VERSION='-version-info 4:2:3'
AC_SUBST(LIB_AXIS_MANIP_VERSION)
LIB_PHYS_CORR_VERSION='-version-info 1:0:0'
AC_SUBST(LIB_PHYS_CORR_VERSION)
LIB_UTILS_VERSION='-version-info 5:0:4'
AC_SUBST(LIB_UTILS_VERSION)
PYLIB_ARRAY_MANIP_VERSION='-version-info 3:0:2'
AC_SUBST(PYLIB_ARRAY_MANIP_VERSION)
PYLIB_AXIS_MANIP_VERSION='-version-info 4:2:3'
AC_SUBST(PYLIB_AXIS_MANIP_VERSION)
PYLIB_NESSI_VECTOR_VERSION='-version-info 1:0:0'
AC_SUBST(PYLIB_NESSI_VECTOR_VERSION)
PYLIB_PHYS_CORR_VERSION='-version-info 1:0:0'
AC_SUBST(PYLIB_PHYS_CORR_VERSION)
PYLIB_UTILS_VERSION='-version-info 5:0:4'
AC_SUBST(PYLIB_UTILS_VERSION)
PYLIB_VPAIR_VERSION='-version-info 1:0:0'
AC_SUBST(PYLIB_VPAIR_VERSION)

# Enable compiler warnings
if test $GXX = yes; then
	CXXFLAGS="$CXXFLAGS -Wall"
fi

# Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([float.h limits.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([floor memset pow sqrt strstr])

dnl Add OS define flags for smoke tests
case "$host" in
     *-*-darwin*) STOSFLAG="-DMAC";;
     x86_64-*-linux*) STOSFLAG="-DLINUX64";;
     *-*-linux*) STOSFLAG="-DLINUX";;
     *) STOSFLAG=;;
esac
AC_SUBST(STOSFLAG)

# Must have Swig version 1.3.31 to make Python 2.5 bindings
if test "$PYTHON_VERSION" = "2.5"; then
   SCL_SWIG_CHECK([1.3.31])
else
   SCL_SWIG_CHECK([1.3.28])	
fi

SCL_DOXYGEN_CHECK([1.4.6])
AC_CHECK_PROGS(DOT, [dot])

AM_CONDITIONAL(HAVE_PYTHON, [test ! -z "$PYTHONROOT"])
AM_CONDITIONAL(HAVE_SWIG, [test ! -z "$SWIG"])
AM_CONDITIONAL(HAVE_DOXYGEN, [test ! -z "$DOXYGEN"])
AM_CONDITIONAL(HAVE_DOT, [test ! -z "$DOT"])

AC_CONFIG_TESTDIR(array_manip/test/cpp)
AC_CONFIG_TESTDIR(axis_manip/test/cpp)
AC_CONFIG_TESTDIR(phys_corr/test/cpp)
AC_CONFIG_TESTDIR(utils/test/cpp)

AC_CONFIG_FILES([array_manip/test/Makefile
		array_manip/test/cpp/Makefile
 		axis_manip/test/Makefile
		axis_manip/test/cpp/Makefile
 		phys_corr/test/Makefile
		phys_corr/test/cpp/Makefile
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
		bindings/scl_defs.py
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

if test $optswig == "true" ; then
   SWIGOPT="on"
else
   SWIGOPT="off"
fi

if test -n "$DOXYGEN_VERSION_REQ" ; then
   DOXYGEN_WARNING="If you wish to remake documentation, you need to get \
$DOXYGEN_VERSION_REQ. Otherwise 
        the documentation you produce may be incomplete and inaccurate. You
        currently have $DOXYGEN_VERSION_HAVE."
else 
   DOXYGEN_WARNING=""
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
	${DOXYGEN_WARNING}
build:
        bindings:
                SWIG:          ${SWIGBINDING}
                Optimize:      ${SWIGOPT}

Please check whether the configuration I detected matches what you
would like to have.
])
