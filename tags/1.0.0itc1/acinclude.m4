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
