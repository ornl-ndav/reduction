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

# AC_CHECK_ROOT
#
# $1 = name of arg
# $2 = root variable name to set
# $3 = list of root paths to try
# $4 = file in path to locate
#
# e.g. AC_CHECK_ROOT([tcl],[TCLROOT],[/usr /usr/local],[include/tcl.h])
#
AC_DEFUN(
  [AC_CHECK_ROOT],
  [ $2=""
    AC_SUBST([$2])
    AC_ARG_WITH([$1],
	AC_HELP_STRING([--with-$1=/path/to/$1/directory],
                       [Specify location of $1 install directory]),
	[if test x$withval != xno; then $2=$withval; fi],
        [])
    if test x$withval != xno -a x[$]$2 = x; then
        AC_MSG_CHECKING(for $1 root installation directory)
        for i in $3; do
	    if test x[$]$2 = x -a -r $i/$4; then $2=$i; fi
        done
        if test x[$]$2 = x; then
	    AC_MSG_RESULT(unknown)
        else
	    AC_MSG_RESULT([$]$2)
        fi
    fi
  ])

# SCL_SWIG_CHECK
#
# Adds an Autotools check on the version of Swig for the SNS Common Libraries
#
# $1 = required version of swig
#
# e.g. SCL_SWIG_CHECK(1.3.28)
#
AC_DEFUN(
  [SCL_SWIG_CHECK],
  [AC_CHECK_PROGS([SWIG], [swig])
    AC_SUBST(SWIG)
    if test -z "$SWIG" ; then
	AC_MSG_ERROR([Cannot find SWIG. This is vital to the library build, so please obtain SWIG. See http://www.swig.org])
    elif test -n "$1" ; then
	AC_MSG_CHECKING([for SWIG version])
	[swig_version=`$SWIG -version 2>&1 | grep 'SWIG Version' | cut -d" " -f3`]
        AC_MSG_RESULT([$swig_version])
	if test -n "$swig_version" ; then
          [required=$1]
          [required_major=`echo $required | sed 's/[^0-9].*//'`]
          if test -z "$required_major" ; then
            [required_major=0]
          fi
          [required=`echo $required | sed 's/[0-9]*[^0-9]//'`]
          [required_minor=`echo $required | sed 's/[^0-9].*//'`]
          if test -z "$required_minor" ; then
             [required_minor=0]
          fi
          [required=`echo $required | sed 's/[0-9]*[^0-9]//'`]
          [required_patch=`echo $required | sed 's/[^0-9].*//'`]
          if test -z "$required_patch" ; then
             [required_patch=0]
          fi
          # Calculate the available version number components
          [available=`echo $swig_version | sed 's/[^0-9]*//'`]
          [available_major=`echo $available | sed 's/[^0-9].*//'`]
          if test -z "$available_major" ; then
             [available_major=0]
          fi
          [available=`echo $available | sed 's/[0-9]*[^0-9]//'`]
          [available_minor=`echo $available | sed 's/[^0-9].*//'`]
          if test -z "$available_minor" ; then
             [available_minor=0]
          fi
          [available=`echo $available | sed 's/[0-9]*[^0-9]//'`]
          [available_patch=`echo $available | sed -e 's/.*Patch[^0-9]*//' -e 's/[^0-9]*//g' `]
          if test -z "$available_patch" ; then
             [available_patch=0]
          fi

	  if test $available_major -ne $required_major \
               -o $available_minor -ne $required_minor \
               -o $available_patch -lt $required_patch ; then
	    AC_MSG_ERROR([You need SWIG version $1 and have SWIG version $swig_version])
	  fi
       fi
    fi
  ])

# SCL_DOXYGEN_CHECK
#
# Adds an Autotools check on the version of Doxygen for the SNS Common 
# Libraries
#
# $1 = required version of doxygen
#
# e.g. SCL_DOXYGEN_CHECK(1.4.6)
#
AC_DEFUN(
  [SCL_DOXYGEN_CHECK],
  [AC_CHECK_PROGS([DOXYGEN], [doxygen])
    AC_SUBST(HAVE_DOXYGEN_TRUE)
    AC_SUBST(HAVE_DOXYGEN_FALSE)
    if test -z "$DOXYGEN" ; then
	HAVE_DOXYGEN_TRUE=
	HAVE_DOXYGEN_FALSE='#'
	AC_MSG_WARN([Cannot find doxygen. See http://www.doxygen.org])
    elif test -n "$1" ; then
	HAVE_DOXYGEN_TRUE='#'
	HAVE_DOXYGEN_FALSE=
	AC_MSG_CHECKING([for DOXYGEN version])
	[doxygen_version=`$DOXYGEN --version 2>&1`]
        AC_MSG_RESULT([$doxygen_version])
	if test -n "$doxygen_version" ; then
          [required=$1]
          [required_major=`echo $required | sed 's/[^0-9].*//'`]
          if test -z "$required_major" ; then
            [required_major=0]
          fi
          [required=`echo $required | sed 's/[0-9]*[^0-9]//'`]
          [required_minor=`echo $required | sed 's/[^0-9].*//'`]
          if test -z "$required_minor" ; then
             [required_minor=0]
          fi
          [required=`echo $required | sed 's/[0-9]*[^0-9]//'`]
          [required_patch=`echo $required | sed 's/[^0-9].*//'`]
          if test -z "$required_patch" ; then
             [required_patch=0]
          fi
          # Calculate the available version number components
          [available=`echo $doxygen_version | sed 's/[^0-9]*//'`]
          [available_major=`echo $available | sed 's/[^0-9].*//'`]
          if test -z "$available_major" ; then
             [available_major=0]
          fi
          [available=`echo $available | sed 's/[0-9]*[^0-9]//'`]
          [available_minor=`echo $available | sed 's/[^0-9].*//'`]
          if test -z "$available_minor" ; then
             [available_minor=0]
          fi
          [available=`echo $available | sed 's/[0-9]*[^0-9]//'`]
          [available_patch=`echo $available | sed -e 's/.*Patch[^0-9]*//' -e 's/[^0-9]*//g' `]
          if test -z "$available_patch" ; then
             [available_patch=0]
          fi

	  if test $available_major -ne $required_major \
               -o $available_minor -ne $required_minor \
               -o $available_patch -lt $required_patch ; then
	    AC_MSG_WARN([You need $DOXYGEN version $1 and have $DOXYGEN version $doxygen_version])
	    DOXYGEN_VERSION_REQ='$1'
	    AC_SUBST(DOXYGEN_VERSION_REQ)	
	  fi
       fi
    fi
  ])
