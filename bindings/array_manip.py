#
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
#

# $Id$

##
# \file bindings/array_manip.py 
#

import nessi_vector
import array_manip_bind

##
# \namespace array_manip
#
# \brief Python abstraction layer access for ArrayManip library functions
#
# This module gives the NessiVector access to the various simple
# arithmetic operations on arrays provided by the <i>array_manip</i>
# library. These arithmetic operations are written in references to SNS
# 107030214-TD0001-R00, "Data Reduction Library Software Requirements and
# Specifications".
#
# Once a function is called, according to the type of the NessiVectors calling
# it, the module redirects the call to the right function.
#
# For example, when calling the function \f$add\f$ with two NessiVector of
# type <i>float</i>, the module redirects the call to the function
# \f$add\_f\f$.
#

##
# \defgroup py_add_ncerr array_manip::add_ncerr
# \{

##
# \brief This function adds each element of two NessiVector.
#
# This function accepts four NessiVector as arguments or 2 NessiVectors and
# 2 scalars.
#
# - With four NessiVectors:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Vector_1, Vector_err2_1, Vector_2, Vector_err2_2)
# \endcode
#
# - With 2 NessiVectors and 2 scalars:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Vector_1, Vector_err2_1, Scalar, Scalar_err2)
# \endcode
# or
# \code
# >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Scalar, Scalar_err2, Vector_1, Vector_err2_1)
# \endcode
#
#     ========================================================================
#
# - With 4 NessiVectors, this function adds each element, \f$i\f$, of two
# NessiVectors according to the equation:
# \f[
# data_o[i]=data_1[i]+data_2[i]
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2[i]=\sigma_1^2[i]+\sigma_2^2[i]
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$data_1[i]\f$ is the \f$i^{th}\f$ component of the first
# array being added, \f$data_2[i]\f$ is the \f$i^{th}\f$ component
# of the second array being added, \f$\sigma_o[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty of the output array,
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty in the first array, and \f$\sigma_2[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty in the second array.
#
# - With 2 NessiVectors and 2 scalars, this function adds a scalar to each
# element, \f$i\f$, of an array according to the equation:
# \f[
# data_o[i]=a+data_i[i]
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2[i]=\sigma_a^2+\sigma_i^2[i]
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$a\f$ is the scalar being added to each element,
# \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
# \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty of the output array, \f$\sigma_a\f$ is the
# uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty in the input array.
#
# \param a (INPUT) is the first NessiVector or scalar to be added
# \param ae2 (INPUT) is the square of the uncertainty in the first
# NessiVector of in the scalar to be added
# \param b (INPUT) is the second NessiVector or scalar to be added
# \param be2 (INPUT) is the square of the uncertainty in the second
# NessiVector or scalar to be added
# \return
# - The result NessiVector
# - The square of the uncertainty in the result NessiVector
#
def add_ncerr(a,ae2,b,be2):

    """

    This function accepts four arguments:
	   - 4 NessiVectors
	   - 2 NessiVectors and 2 scalars
	
    >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Vector_1,
        Vector_err2_1, Vector_2, Vector_err2_2)

    >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Vector, Vector_err2,
        Scalar, Scalar_err2)

    where Vector_o is the resulting NessiVector and Vector_err2_o is the
    uncertainty in the NessiVector o.

    ================================================================	
    - With 4 NessiVectors, this function adds each element, i, of two
    NessiVectors according to the equation:

    Vector_o[i] = Vector_1[i] + Vector_2[i]

    and the uncorrelated uncertainties will be present according to the
    equation:
	
    Vector_err2_o[i] = Vector_err2_1^2[i] + Vector_err2_2^2[i]

    Where Vector_o[i] is the i^th component of the output
    array, Vector_1[i] is the i^th component of the first
    array, Vector_2[i] is the i^th component of the
    second array, Vector_err2_o[i] is the i^th component of
    the uncertainty of the output array, Vector_err2_1[i] is the
    i^th component of the uncertainty in the first array, and
    Vector_err2_2[i] is the i^th component of the
    uncertainty in the second array.

    - With 2 NessiVectors and 2 scalars, this function adds each element of the
    NessiVectors with a scalar according to the equation:

    Vector_o[i] = Vector[i] + Scalar

    and the uncorrelated uncertainties will be processed according to the
    equation:
	
    Vector_err2_o[i] = Vector_err2[i] + Scalar_err2
	
    Where Vector_o[i] is the i^th component of the output
    array, Scalar is the scalar being added to each element,
    Vector_1[i] is the i^th component of the input array,
    Vector_err2_o[i] is the i^th component of the
    uncertainty of the output array, Scalar_err2 is the
    uncertainty in the scalar, and Vector_err2_1[i] is the
    i^th component of the uncertainty in the input array.

    """

    run_ok = False

    try:
        a.__type__
    except:            #run if exception is raised
        try:
            b.__type__
        except:
            raise TypeError,"Types not supported by NessiVector"
        else:
            if (b.__type__ == b.FLOAT or b.type == b.DOUBLE):
                a=float(a)
            else:
                a=int(a)
            run_ok = True
    else:
        try:
            b.__type__
        except:
            if (a.__type__ == a.FLOAT or a.type == a.DOUBLE):
                b=float(b)
            else:
                b=int(b)
            run_ok = True
        else:
            if (a.__type__ != b.__type__):
                raise TypeError,"Parameters types are different"
            else:
                run_ok = True

    if (run_ok):

        if (a.__type__ == a.FLOAT):
            c = nessi_vector.NessiVector(len(a))
            ce2 = nessi_vector.NessiVector(len(a))
            array_manip_bind.add_ncerr_f(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        if (a.__type__ == a.DOUBLE):
            c = nessi_vector.NessiVector(len(a),a.DOUBLE)
            ce2 = nessi_vector.NessiVector(len(a), a.DOUBLE)
            array_manip_bind.add_ncerr_d(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        if (a.__type__ == a.INT):
            c = nessi_vector.NessiVector(len(a),a.INT)
            ce2 = nessi_vector.NessiVector(len(a), a.INT)
            array_manip_bind.add_ncerr_i(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        if (a.__type__ == a.UINT):
            c = nessi_vector.NessiVector(len(a),a.UINT)
            ce2 = nessi_vector.NessiVector(len(a), a.UINT)
            array_manip_bind.add_ncerr_u(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)

        return c,ce2

    else:

        return

##
# \}

##
# \defgroup py_sub_ncerr array_manip::sub_ncerr
# \{

##
# \brief This function substracts each element of two NessiVector.
#
# This function accepts four NessiVector as arguments or 2 NessiVectors and
# 2 scalars
#
# - With four NessiVectors:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Vector_1, Vector_err2_1, Vector_2, Vector_err2_2)
# \endcode
#
# - With 2 NessiVectors and 2 scalars:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Vector_1, Vector_err2_1, Scalar, Scalar_err2)
# \endcode
#
# - With 2 scalars and 2 NessiVectors:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Scalar, Scalar_err2, Vector_1, Vector_err2_1)
# \endcode
#
#     ========================================================================
#
# - With 4 NessiVectors, This function subtracts each element, \f$i\f$, of two
# arrays according to the equation:
# \f[
# data_o[i]=data_1[i]/data_2[i]
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation:
# \f[
# \sigma_o^2[i]=\left(\frac{data_1[i]\times \sigma_2[i]}{data_2^2[i]}
# \right)^2+\left(\frac{\sigma_1[i]}{data_2[i]}\right)^2
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$data_1[i]\f$ is the \f$i^{th}\f$ component of the array
# being subtracted from each element, \f$data_2[i]\f$ is the \f$i^{th}\f$
# component of the array subtracting, \f$\sigma_o[i]\f$ is the \f$i^{th}\f$
# component of the uncertainty of the output array,
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty in the array being subtracting, and \f$\sigma_i[i]\f$ is
# the \f$i^{th}\f$ component of the uncertainty in the array subtracting.
# array.
#
# - With 2 NessiVectors and 2 Scalars, this function subtracts each element,
# \f$i\f$, of an array by a scalar according to the equation:
# \f[
# data_o[i]=data_i[i]/a
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation:
# \f[
# \sigma_o^2[i]=\left(\frac{\sigma_i[i]}{a}\right)^2
#                 +\left(\frac{data_i[i]\times\sigma_a}{a^2}\right)^2
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$a\f$ is the scalar subtracting each element,
# \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
# \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty of the output array, \f$\sigma_a\f$ is the
# uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty in the input array.
#
# - With 2 scalars and 2 NessiVectors, this function subtracts a scalar by each
# element, \f$i\f$, of an array according to the equation:
# \f[
# data_o[i]=a/data_i[i]
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation:
# \f[
# \sigma_o^2[i]=\left(\frac{a \times \sigma_i[i]}{data_i^2[i]}\right)^2
#                 +\left(\frac{\sigma_a}{data_i[i]}\right)^2
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$a\f$ is the scalar each element is subtracting,
# \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
# \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty of the output array, \f$\sigma_a\f$ is the
# uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty in the input array.
#
# \param a (INPUT) is the NessiVector or scalar to be subtracted from 
# \param ae2 (INPUT) is the square of the uncertainty in the
# NessiVector or scalar to be subtracted from
# \param b (INPUT) is the NessiVector or scalar to subtract
# \param be2 (INPUT) is the square of the uncertainty in the NessiVector or
# scalar to subtract
# \return
# - The result NessiVector
# - The square of the uncertainty in the result NessiVector 
#
def sub_ncerr(a,ae2,b,be2):

    """

    This function accepts four arguments:
	   - 4 NessiVectors
	   - 2 NessiVectors and 2 scalars
	   - 2 scalars and 2 NessiVectors
	
    >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Vector_1,
        Vector_err2_1, Vector_2, Vector_err2_2)

    >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Vector, Vector_err2,
        Scalar, Scalar_err2)

    >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Scalar, Scalar_err2,
        Vector, Vector_err2)

    where Vector_o is the resulting NessiVector and Vector_err2_o is the
    uncertainty in the NessiVector o.

    ================================================================

    - With 4 NessiVectors, this function subtracts each element, i, of two
    NessiVectors according to the equation:

    Vector_o[i] = Vector_1[i] - Vector_2[i]

    and the uncorrelated uncertainties will be present according to the
    equation

    Vector_err2_o^2[i] = Vector_err2_1^2[i] + Vector_err2_2^2[i]

    Where Vector_o[i] is the i^th component of the output
    array, Vector_1[i] is the i^th component being subtracted from
    each element, Vector_2[i] is the i^th component of
    the array subtracting, Vector_err2_o[i] is the i^th
    component of the uncertainty of the output array,
    Vector_err2_1[i] is the i^th component of the
    uncertainty in the array begin subtracted from and
    Vector_err2_2[i] is the i^th component of the
    uncertainty in the array subtracting.
    
    - With 2 NessiVectors and 2 scalars, this function subtracts a scalar
    from each element, i, of a NessiVectors according to the equation:

    Vector_o[i] = Vector_1[i] - Scalar

    and the uncorrelated uncertainties will be present according to the
    equation

    Vector_err2_o^2[i] = Vector_err2_1^2[i] + Scalar_err2^2

    Where Vector_o[i] is the i^th component of the output
    array, Vector_1[i] is the i^th component being subtracted from
    each element, Scalar is the being subtracted from each element,
    Vector_err2_o[i] is the i^th component of the uncertainty of the
    output array, Vector_err2_1[i] is the i^th component of the
    uncertainty in the array begin subtracted from and
    Scalar_err2 is the uncertainty in the scalar.

    - With 2 scalar and 2 NessiVectors, this function subtracts from a
    scalar each element, i, of a NessiVectors according to the equation:

    Vector_o[i] = Scalar - Vector_1[i]

    and the uncorrelated uncertainties will be present according to the
    equation

    Vector_err2_o^2[i] = Scalar_err2^2 + Vector_err2_1^2[i]

    Where Vector_o[i] is the i^th component of the output
    array, Vector_1[i] is the i^th component of the input array
    being subtracted from the scalar, Scalar is the scalar,
    Vector_err2_o[i] is the i^th component of the
    uncertainty of the output array, Scalar_err2 is the
    uncertainty in the scalar, and Vector_err2_1[i] is the
    i^th component of the uncertainty in the input array.

    """

    run_ok = False

    try:
        a.__type__
    except:            #run if exception is raised
        try:
            b.__type__
        except:
            raise TypeError,"Types not supported by NessiVector"
        else:
            if (b.__type__ == b.FLOAT or b.type == b.DOUBLE):
                a=float(a)
            else:
                a=int(a)
            run_ok = True
    else:
        try:
            b.__type__
        except:
            if (a.__type__ == a.FLOAT or a.type == a.DOUBLE):
                b=float(b)
            else:
                b=int(b)
            run_ok = True
        else:
            if (a.__type__ != b.__type__):
                raise TypeError,"Parameters types are different"
            else:
                run_ok = True

    if (run_ok):

        if (a.__type__ == a.FLOAT):
            c = nessi_vector.NessiVector(len(a));
            ce2 = nessi_vector.NessiVector(len(a));
            array_manip_bind.sub_ncerr_f(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        if (a.__type__ == a.DOUBLE):
            c = nessi_vector.NessiVector(len(a),a.DOUBLE)
            ce2 = nessi_vector.NessiVector(len(a), a.DOUBLE)
            array_manip_bind.sub_ncerr_d(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        if (a.__type__ == a.INT):
            c = nessi_vector.NessiVector(len(a),a.INT)
            ce2 = nessi_vector.NessiVector(len(a), a.INT)
            array_manip_bind.sub_ncerr_i(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        if (a.__type__ == a.UINT):
            c = nessi_vector.NessiVector(len(a),a.UINT)
            ce2 = nessi_vector.NessiVector(len(a), a.UINT)
            array_manip_bind.sub_ncerr_u(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)

        return c,ce2

    else:

        return 

##
# \}

##
# \defgroup py_mult_ncerr array_manip::mult_ncerr
# \{

##
# \brief This function multiplies each element of two NessiVector.
#
# This function accepts four NessiVector as arguments or 2 NessiVectors and 2
# scalars.
#
# - With four NessiVectors:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.mult_ncerr (Vector_1,Vector_err2_1, Vector_2,Vector_err2_2)
# \endcode
#
# - With 2 NessiVectors and 2 scalars:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.mult_ncerr (Vector,Vector_err2, Scalar, Scalar_err2)
# \endcode
#
#     ========================================================================
#
# - With 4 NessiVectors, this function multiply each element, \f$i\f$, of two
# NessiVectors according to the equation:
# \f[
# data_o[i]=data_1[i]\times data_2[i]
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2[i]=(data_1[i]\times\sigma_2[i])^2
# +(data_2[i]\times\sigma_1[i])^2
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$data_1[i]\f$ is the \f$i^{th}\f$ component of the first
# array, \f$data_2[i]\f$ is the \f$i^{th}\f$ component of the
# second array, \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of
# the uncertainty of the output array, \f$\sigma_1[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty in the first array, and
# \f$\sigma_2[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty in the second array.
#
# - With 2 NessiVectors and 2 scalars, this function multiplies a scalar to
# each element, \f$i\f$, of an NessiVector according to the equation
# \f[
# data_o[i]=data_i[i]\times a
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2[i]=(a\times\sigma_i[i])^2+(data_i[i]\times\sigma_a)^2
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$a\f$ is the scalar being multiplied to each element,
# \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
# \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty of the output array, \f$\sigma_a\f$ is the
# uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty in the input array.
#
# \param a (INPUT) is the first NessiVector to be multiplied
# \param ae2 (INPUT) is the second NessiVector to multiplied
# \param b (INPUT) is the second NessiVector/scalar to be multiplied
# \param be2 (INPUT) is the square of the uncertainty in the second
# NessiVector/scalar to be multiplied
#
# \return
# - The result NessiVector
# - The square of the uncertainty in the result NessiVector
#
def mult_ncerr(a,ae2,b,be2):

    """

    This function accepts four arguments:
       - 4 NessiVectors
       - 2 NessiVectors and 2 scalars
	
    >>> Vector_o, Vector_err2_o = array_manip.mult_ncerr (Vector_1,
        Vector_err2_1, Vector_2, Vector_err2_2)

    >>> Vector_o, Vector_err2_o = array_manip.mult_ncerr (Vector, Vector_err2,
        Scalar, Scalar_err2)

    where Vector_o is the resulting NessiVector and Vector_err2_o is the
    uncertainty in the NessiVector o.

	=================================================================	

    - With 4 NessiVectors, this function multiply each element, i, of two
    NessiVectors according to the equation:

    Vector_o[i] = Vector_1[i] * Vector_2[i]

    and the uncorrelated uncertainties will be present according to the
    equation
	
    Vector_err2_o^2[i] = Vector_err2_1^2[i] * Vector_err2_2^2[i]

    Where Vector_o[i] is the i^th component of the output
    array, Vector_1[i] is the i^th component of the first
    array, Vector_2[i] is the i^th component of the
    second array, Vector_err2_o[i] is the i^th component of
    the uncertainty of the output array, Vector_err2_1[i] is the
    i^th component of the uncertainty in the first array, and
    Vector_err2_2[i] is the i^th component of the
    uncertainty in the second array.

    - With 2 NessiVectors and 2 scalars, this function multiply each element
    of the NessiVectors with a scalar according to the equations:

    Vector_o[i] = Vector[i] * Scalar

    and the uncorrelated uncertainties will be processed according to the
    equation
	
    Vector_err2_o^2[i] = Vector_err2[i] * Scalar_err2
	
    Where Vector_o[i] is the i^th component of the output
    array, Scalar is the scalar being multiplied to each element,
    Vector_1[i] is the i^th component of the input array,
    Vector_err2_o[i] is the i^th component of the
    uncertainty of the output array, Scalar_err2 is the
    uncertainty in the scalar, and Vector_err2_1[i] is the
    i^th component of the uncertainty in the input array.

    """

    run_ok = False

    try:
        a.__type__
    except:            #run if exception is raised
        try:
            b.__type__
        except:
            raise TypeError,"Types not supported by NessiVector"
        else:
            if (b.__type__ == b.FLOAT or b.type == b.DOUBLE):
                a=float(a)
            else:
                a=int(a)
            run_ok = True
    else:
        try:
            b.__type__
        except:
            if (a.__type__ == a.FLOAT or a.type == a.DOUBLE):
                b=float(b)
            else:
                b=int(b)
            run_ok = True
        else:
            if (a.__type__ != b.__type__):
                raise TypeError,"Parameters types are different"
            else:
                run_ok = True

    if (run_ok):

        if (a.__type__ == a.FLOAT):
            c = nessi_vector.NessiVector(len(a));
            ce2 = nessi_vector.NessiVector(len(a));
            array_manip_bind.mult_ncerr_f(a.__array__,\
										  ae2.__array__,\
										  b.__array__,\
										  be2.__array__,\
										  c.__array__,\
										  ce2.__array__)
        if (a.__type__ == a.DOUBLE):
            c = nessi_vector.NessiVector(len(a),a.DOUBLE)
            ce2 = nessi_vector.NessiVector(len(a), a.DOUBLE)
            array_manip_bind.mult_ncerr_d(a.__array__,\
										  ae2.__array__,\
										  b.__array__,\
										  be2.__array__,\
										  c.__array__,\
										  ce2.__array__)
        if (a.__type__ == a.INT):
            c = nessi_vector.NessiVector(len(a),a.INT)
            ce2 = nessi_vector.NessiVector(len(a), a.INT)
            array_manip_bind.mult_ncerr_i(a.__array__,\
										  ae2.__array__,\
										  b.__array__,\
										  be2.__array__,\
										  c.__array__,\
										  ce2.__array__)
        if (a.__type__ == a.UINT):
            c = nessi_vector.NessiVector(len(a),a.UINT)
            ce2 = nessi_vector.NessiVector(len(a), a.UINT)
            array_manip_bind.mult_ncerr_u(a.__array__,\
										  ae2.__array__,\
										  b.__array__,\
										  be2.__array__,\
										  c.__array__,\
										  ce2.__array__)
        return c,ce2
    else:
        return 
##
# \}

##
# \defgroup py_div_ncerr array_manip::div_ncerr
# \{

##
# \brief This function divides each element of two NessiVectors.
#
# This function accepts four NessiVectors as arguments, 2 NessiVectors and 2
# scalars or 2 scalars and 2 NessiVectors.
#
# - With 4 NessiVectors:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Vector_1, Vector_err2_1, Vector_2, Vector_err2_2)
# \endcode
#
# - With 2 NessiVectors and 2 scalars:
# \code 
# >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Vector, Vector_err2, Scalar, Scalar_err2)
# \endcode
#
# - With 2 scalars and 2 NessiVectors:
# \code 
# >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Scalar, Scalar_err2, Vector, Vector_err2)
# \endcode
#
#     ========================================================================
# 
# - With 4 NessiVectors, this function divides each element, \f$i\f$, of two
# NessiVectors according to the equation
# \f[
# Vector_o[i] = Vector_1[i] / Vector_2[i]
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o[i] = \left(\frac{Vector_1[i]\times\sigma_2[i]}{Vector_2^2[i]}\right)
# ^2 +\left(\frac{\sigma_1[i]}{Vector_2[i]}\right)^2
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$data_1[i]\f$ is the \f$i^{th}\f$ component of the array
# being divided, \f$data_2[i]\f$ is the \f$i^{th}\f$ component of
# the dividing array, \f$\sigma_o[i]\f$ is the \f$i^{th}\f$
# component of the uncertainty of the output array,
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty in the array being divided, and \f$\sigma_i[i]\f$ is
# the \f$i^{th}\f$ component of the uncertainty in the dividing
# array.
#
# - With 2 NessiVectors and 2 scalars, this function divides each element,
# \f$i\f$, of a NessiVector by a scalar according to the equation
# \f[
# data_o[i]=data_i[i]/a
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2[i]=\left(\frac{\sigma_i[i]}{a}\right)^2
#                 +\left(\frac{data_i[i]\times\sigma_a}{a^2}\right)^2
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$a\f$ is the scalar dividing each element,
# \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
# \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty of the output array, \f$\sigma_a\f$ is the
# uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty in the input array.
#
# - With 2 Scalars and 2 NessiVectors, this function divides a scalar by each
# element, \f$i\f$, of a NessiVector according to the equation
# \f[
# data_o[i]=a/data_i[i]
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2[i]=\left(\frac{a \times \sigma_i[i]}{data_i^2[i]}\right)^2
#                 +\left(\frac{\sigma_a}{data_i[i]}\right)^2
# \f]
# Where \f$data_o[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$a\f$ is the scalar each element is dividing,
# \f$data_i[i]\f$ is the \f$i^{th}\f$ component of the input array,
# \f$\sigma_o[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty of the output array, \f$\sigma_a\f$ is the
# uncertainty in the scalar, and \f$\sigma_i[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty in the input array.
#
# \param a (INPUT) is the NessiVector being divided
# \param ae2 (INPUT) is the dividing NessiVector, if they are no more
# arguments present, otherwise it's the square of the uncertainty in the
# NessiVector being divided
# \param b (INPUT) is the dividing NessiVector
# \param be2 (INPUT) is the square of
# the uncertainty in the dividing NessiVector
# \return
# - The result NessiVector
# - The square of the uncertainty in the result NessiVector
#

def div_ncerr(a,ae2,b,be2):

    """

    This function accepts four arguments:
       - 4 NessiVectors

    >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Vector_1,
        Vector_err2_1, Vector_2, Vector_err2_2)

       - 2 NessiVectors and 2 scalars

    >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Vector, Vector_err2,
        Scalar, Scalar_err2)

       - 2 scalars and 2 NessiVectors
	
    >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Scalar, Scalar_err2,
        Vector, Vector_err2)

    where Vector_o is the resulting NessiVector and Vector_err2_o is the
    uncertainty in the NessiVector o.

	=================================================================

    - With 4 NessiVectors, this function divides each element, i, of two
    NessiVectors according to the equation:

    Vector_o[i] = Vector_1[i] / Vector_2[i]

    and the uncorrelated uncertainties will be processed according to the
    equation
	
    Vector_err2_o[i] = {(Vector_1[i]*Vector_err2_[i])/(Vector_2^2[i])}^2
    +{(Vector_err2_1[i])/(Vector_2[i])}^2

    Where Vector_o[i] is the i^th component of the output
    array, Vector_1[i] is the i^th component of the array
    being divided, Vector_2[i] is the i^th component of
    the dividing array, Vector_err2_o[i] is the i^th
    component of the uncertainty of the output array,
    Vector_err2_1[i] is the i^th component of the
    uncertainty in the array being divided, and Vector_err2_2[i] is
    the i^th component of the uncertainty in the dividing
    array.

    - With 2 NessiVectors and 2 scalars, this function divides each element
    of the NessiVectors with a scalar according to the equations:

    Vector_o[i] = Vector[i] / Scalar

    and the uncorrelated uncertainties will be processed according to the
    equation

    Vector_err2_o[i] = (Vector_err2[i]/Scalar)^2 +
    {(Vector[i]*Scalar_err2)/(Scalar^2)}^2
	
    Where Vector_o[i] is the i^th component of the output
    array, Scalar is the scalar dividing each element,
    Vector[i] is the i^th component of the input array,
    Vector_err2_o[i] is the i^th component of the
    uncertainty of the output array, Scalar_err2 is the
    uncertainty in the scalar, and Vector_err2[i] is the
    i^th component of the uncertainty in the input array.

    - With 2 scalar and 2 NessiVectors, this function divides each element
    of the NessiVectors with a scalar according to the equations:

    Vector_o[i] = Scalar / Vector[i]

    and the uncorrelated uncertainties will be processed according to the
    equation

    Vector_err2_o[i] = {(Scalar*Vector_err2[i])/(Vector[i]^2)}^2
    + (Scalar_err2/Vector[i])^2

    Where Vector_o[i] is the i^th component of the output
    array, Scalar is the scalar each element is dividing,
    Vector[i] is the i^th component of the input array,
    Vector_err2_o[i] is the i^th component of the
    uncertainty of the output array, Scalar_err2 is the
    uncertainty in the scalar, and Vector_err2[i] is the
    i^th component of the uncertainty in the input array.

    """

    run_ok = False

    try:
        a.__type__
    except:            #run if exception is raised
        try:
            b.__type__
        except:
            raise TypeError,"Types not supported by NessiVector"
        else:
            if (b.__type__ == b.FLOAT or b.type == b.DOUBLE):
                a=float(a)
            else:
                a=int(a)
            run_ok = True
    else:
        try:
            b.__type__
        except:
            if (a.__type__ == a.FLOAT or a.type == a.DOUBLE):
                b=float(b)
            else:
                b=int(b)
            run_ok = True
        else:
            if (a.__type__ != b.__type__):
                raise TypeError,"Parameters types are different"
            else:
                run_ok = True

    if (run_ok):

        if (a.__type__ == a.FLOAT):
            c = nessi_vector.NessiVector(len(a));
            ce2 = nessi_vector.NessiVector(len(a));
            array_manip_bind.div_ncerr_f(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        if (a.__type__ == a.DOUBLE):
            c = nessi_vector.NessiVector(len(a),a.DOUBLE)
            ce2 = nessi_vector.NessiVector(len(a), a.DOUBLE)
            array_manip_bind.div_ncerr_d(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        if (a.__type__ == a.INT):
            c = nessi_vector.NessiVector(len(a),a.INT)
            ce2 = nessi_vector.NessiVector(len(a), a.INT)
            array_manip_bind.div_ncerr_i(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        if (a.__type__ == a.UINT):
            c = nessi_vector.NessiVector(len(a),a.UINT)
            ce2 = nessi_vector.NessiVector(len(a), a.UINT)
            array_manip_bind.div_ncerr_u(a.__array__,\
										 ae2.__array__,\
										 b.__array__,\
										 be2.__array__,\
										 c.__array__,\
										 ce2.__array__)
        return c,ce2
    else:
        return 

##
# \}

##
# \defgroup py_sumw_ncerr array_manip::sumw_ncerr
# \{

##
# \brief This function adds two NessiVector weighted by their uncertainties.
#
# This function adds two NessiVector weighted by their uncertainties according
# to the equation:
# \f[
# Vector_o[i]=\left( \sum^2_{n=1} \frac{Vector_n[i]}{\sigma_n[i]}\right)
# \times\left( \frac{1}{2} \sum^2_{n=1} \sigma_n[i] \right)
# \f]
# and
# \f[
# \sigma_o^2[i]=(\sigma_1^2\sigma_2 + \sigma_1\sigma_2^2)(\sigma_1+\sigma_2)
# \f]
# However, if the uncertainty in any of the data is zero, the value of the
# \f$Vector_o[i]\f$ will be given by
# \f[
# Vector_o[i]=\sum^2_{n=1} Vector_n[i]
# \f]
# where \f$Vector_o[i]\f$ is the \f$i^{th}\f$ component of the output
# NessiVector, \f$Vector_n[i]\f$ is the \f$i^{th}\f$ component of the
# \f$n^{th}\f$ NessiVector being added, \f$\sigma_o[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector,
# \f$\sigma_n[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the \f$n^{th}\f$ NessiVector being added.
#
# \param a (INPUT) is the first NessiVector to be added
# \param ae2 (INPUT) is the square of the uncertainty in the first NessiVector
# to be added
# \param b (INPUT) is the second NessiVector to be added
# \param be2 (INPUT) is the square of the uncertainty in the second
# NessiVector to be added
# \return
# - The result NessiVector
# - The square of the uncertainty in the result NessiVector
#

def sumw_ncerr(a,ae2,b,be2):

    """

    This function accepts four arguments:
        - 4 NessiVectors

    >>> Vector_o, Vector_err2_o = array_manip.sumw_ncerr(Vector_1,
        Vector_1_err2)

    where Vector_o is the resulting NessiVector and NessiVector_err2_o is the
    uncertainty in the NessiVector o.

	===================================================================

    This function adds two arrays weighted by their uncertainties
    according to the equation

    Vector_o[i]= sum^N_(n=1) {(Vector_n[i])/(Vector_err2_n[i])}
    * 1/N  sum^N_(n=1) {Vector_err2_n[i]}

    where N=2 and the uncorrelated uncertainties will be processed
    according to the equation

    Vector_err2_o[i] = (Vector_err2_1^2*Vector_err2_2+
    Vector_err2_1*Vector_err2_2^2)*(Vector_err1_1+Vector_err2_2)

    However, if the uncertainty in any of the data is not specified,
    or is zero, the value of the Vector_o[i] will be given by

    Vector_o[i] = sum^N_{n=1} {Vector_n[i]}

    Where Vector_o[i] is the i^th$ component of the output
    array, Vector_n[i] is the i^th component of the
    n^th array being added, Vector_err2_o[i] is the
    i^th component of the uncertainty of the output array,
    and Vector_err2_n[i] is the i^th component of the
    uncertainty in the n^th array being added.
	
	"""

    run_ok = False

    try:
        a.__type__
    except:            #run if exception is raised
        try:
            b.__type__
        except:
            raise TypeError,"Types not supported by NessiVector"
        else:
            if (b.__type__ == b.FLOAT or b.type == b.DOUBLE):
                a=float(a)
            else:
                a=int(a)
            run_ok = True
    else:
        try:
            b.__type__
        except:
            if (a.__type__ == a.FLOAT or a.type == a.DOUBLE):
                b=float(b)
            else:
                b=int(b)
            run_ok = True
        else:
            if (a.__type__ != b.__type__):
                raise TypeError,"Parameters types are different"
            else:
                run_ok = True

    if (run_ok):

        if (a.__type__ == a.FLOAT):
            c = nessi_vector.NessiVector(len(a));
            ce2 = nessi_vector.NessiVector(len(a));
            array_manip_bind.sumw_ncerr_f(a.__array__,\
										  ae2.__array__,\
										  b.__array__,\
										  be2.__array__,\
										  c.__array__,\
										  ce2.__array__)
        if (a.__type__ == a.DOUBLE):
            c = nessi_vector.NessiVector(len(a),a.DOUBLE)
            ce2 = nessi_vector.NessiVector(len(a), a.DOUBLE)
            array_manip_bind.sumw_ncerr_d(a.__array__,\
										  ae2.__array__,\
										  b.__array__,\
										  be2.__array__,\
										  c.__array__,\
										  ce2.__array__)
        if (a.__type__ == a.INT):
            c = nessi_vector.NessiVector(len(a),a.INT)
            ce2 = nessi_vector.NessiVector(len(a), a.INT)
            array_manip_bind.sumw_ncerr_i(a.__array__,\
										  ae2.__array__,\
										  b.__array__,\
										  be2.__array__,\
										  c.__array__,\
										  ce2.__array__)
        if (a.__type__ == a.UINT):
            c = nessi_vector.NessiVector(len(a),a.UINT)
            ce2 = nessi_vector.NessiVector(len(a), a.UINT)
            array_manip_bind.sumw_ncerr_u(a.__array__,\
										  ae2.__array__,\
										  b.__array__,\
										  be2.__array__,\
										  c.__array__,\
										  ce2.__array__)
        return c,ce2
    else:
        return 

##
# \}

