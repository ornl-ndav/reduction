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
# This function accepts two or four NessiVector as arguments. The addition of
# a NessiVector with a scalar is not supported yet.
#
# With two arguments,
# \code
# >>>  Vector_0 = array_manip.add_ncerr (Vector_1, Vector_2)
# \endcode
# With four arguments,
# \code
# >>> Vector_0, Vector_err2_0 = array_manip.add_ncerr (Vector_1, Vector_err2_1, Vector_2, Vector_err2_2)
# \endcode
# where \f$Vector\_err2\_0\f$ is the square of the uncertainty in the NessiVector 0.
#
# For both cases, this function adds each element, \f$i\f$, of two NessiVector
# according to the equations
# \f[
# Vector_0[i] = Vector_1[i] + Vector_2[i]
# \f]
# and
# \f[
# \sigma_0[i] = \sigma_1^2[i] +
# \sigma_2^2[i]
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output
# NessiVector, \f$Vector_1[i]\f$ is the \f$i^{th}\f$ component of the first
# NessiVector being added, \f$Vector_2[i]\f$ it the \f$i^{th}\f$ component
# of the second NessiVector being added, \f$\sigma_0[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector,
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the first NessiVector, and \f$\sigma_2[i]\f$ is the \f$i^{th}\f$
# component of the uncertainty in the second NessiVector.
#
# \param a (INPUT) is the first NessiVector to be added
# \param ae2 (INPUT) is the second NessiVector to be added if there are no more
# arguments present, otherwise it's the square of the uncertainty in the first
# NessiVector to be added
# \param b (INPUT/OPTIONAL) is the second NessiVector to be added
# \param be2 (INPUT/OPTIONAL) required only if b is present, is the square of
# the uncertainty in the second NessiVector to be added
# \return
# - The result NessiVector
# - The square of the uncertainty in the result NessiVector
#

def add_ncerr(a,ae2,b,be2):

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
# This function accepts two or four NessiVector as arguments. The substraction
# of a NessiVector with a scalar is not supported yet.
#
# With two arguments,
# \code
# >>>  Vector_0 = array_manip.sub_ncerr (Vector_1, Vector_2)
# \endcode
#
# With four arguments,
# \code
# >>> Vector_0, Vector_err2_0 = array_manip.sub_ncerr (Vector_1, Vector_err2_1, Vector_2, Vector_err2_2)
# \endcode
# where \f$Vector\_err2\_0\f$ is the square of the uncertainty in the NessiVector 0.
#
# For both cases, this function substracts each element, \f$i\f$, of two
# NessiVector according to the equations
# \f[
# Vector_0[i] = Vector_1[i] - Vector_2[i]
# \f]
# and
# \f[
# \sigma_0[i] = \sigma_1^2[i] +
# \sigma_2^2[i]
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output
# NessiVector, \f$Vector_1[i]\f$ is the \f$i^{th}\f$ component of the
# NessiVector being subtracted from, \f$Vector_2[i]\f$ it the \f$i^{th}\f$
# component of the NessiVector subtracting, \f$\sigma_0[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector,
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the first NessiVector, and \f$\sigma_2[i]\f$ is the \f$i^{th}\f$
# component of the uncertainty in the second NessiVector.
#
# \param a (INPUT) is the NessiVector to be subtracted from
# \param ae2 (INPUT) is the NessiVector to subtract, if they are no more
# arguments present, otherwise it's the square of the uncertainty in the
# NessiVector to be subtracted from
# \param b (INPUT/OPTIONAL) is the NessiVector to subtract
# \param be2 (INPUT/OPTIONAL) required only if b is present, is the square of
# the uncertainty in the NessiVector to subtract
# \return
# - The result NessiVector
# - The square of the uncertainty in the result NessiVector 
#

def sub_ncerr(a,ae2,b,be2):

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
# This function accepts two or four NessiVector as arguments. The
# multiplication of a NessiVector with a scalar is not supported yet.
#
# With two arguments,
# \code
# >>>  Vector_0 = array_manip.mult_ncerr (Vector_1, Vector_2)
# \endcode
#
# With four arguments,
# \code
# >>> Vector_0, Vector_err2_0 = array_manip.mult_ncerr (Vector_1,Vector_err2_1, Vector_2,Vector_err2_2)
# \endcode
# where \f$Vector\_err2\_0\f$ is the square of the uncertainty in the NessiVector 0.
#
# For both cases, this function multiplies each element, \f$i\f$, of two
# NessiVector according to the equations
# \f[
# Vector_0[i] = Vector_1[i] \times Vector_2[i]
# \f]
# and
# \f[
# \sigma_0[i] = (Vector_1[i]\times\sigma_1[i])^2 +
# (Vector_2[i]\times\sigma_2[i])^2
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output
# NessiVector, \f$Vector_1[i]\f$ is the \f$i^{th}\f$ component of the first
# NessiVector to be multiplied, \f$Vector_2[i]\f$ it the \f$i^{th}\f$ component
# of the second NessiVector to be multiplied, \f$\sigma_0[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector,
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the first NessiVector, and \f$\sigma_2[i]\f$ is the \f$i^{th}\f$
# component of the uncertainty in the second NessiVector.
#
# \param a (INPUT) is the first NessiVector to be multiplied
# \param ae2 (INPUT) is the second NessiVector to multiplied, if they are no
# more arguments present, otherwise it's the square of the uncertainty in the
# first NessiVector to be multiplied
# \param b (INPUT/OPTIONAL) is the second NessiVector to be multiplied
# \param be2 (INPUT/OPTIONAL) required only if b is present, is the square of
# the uncertainty in the second NessiVector to be multiplied
# \return
# - The result NessiVector
# - The square of the uncertainty in the result NessiVector
#

def mult_ncerr(a,ae2,b,be2):

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
# \brief This function divides each element of two NessiVector.
#
# This function accepts two or four NessiVector as arguments. The division of
# a NessiVector by a scalar, or of a scalar by a NessiVector is not supported
# yet.
#
# With two arguments,
# \code
# >>>  Vector_0 = array_manip.div_ncerr (Vector_1, Vector_2)
# \endcode
#
# With four arguments,
# \code
# >>> Vector_0, Vector_err2_0 = array_manip.div_ncerr (Vector_1, Vector_err2_1, Vector_2, Vector_err2_2)
# \endcode
# where \f$Vector\_err2\_0\f$ is the square of the uncertainty in the NessiVector 0.
#
# For both cases, this function divides each element, \f$i\f$, of two
# NessiVector according to the equations
# \f[
# Vector_0[i] = Vector_1[i] / Vector_2[i]
# \f]
# and
# \f[
# \sigma_0[i] = \left(\frac{Vector_1[i]\times\sigma_2[i]}{Vector_2^2[i]}\right)
# ^2 +\left(\frac{\sigma_1[i]}{Vector_2[i]}\right)^2
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output
# NessiVector, \f$Vector_1[i]\f$ is the \f$i^{th}\f$ component of the
# NessiVector being divided, \f$Vector_2[i]\f$ it the \f$i^{th}\f$ component
# of the dividing NessiVector, \f$\sigma_0[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector,
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the NessiVector being divided, and \f$\sigma_2[i]\f$ is the \f$i^{th}\f$
# component of the uncertainty in the divided NessiVector.
#
# \param a (INPUT) is the NessiVector being divided
# \param ae2 (INPUT) is the dividing NessiVector, if they are no more
# arguments present, otherwise it's the square of the uncertainty in the
# NessiVector being divided
# \param b (INPUT/OPTIONAL) is the dividing NessiVector
# \param be2 (INPUT/OPTIONAL) required only if b is present, is the square of
# the uncertainty in the dividing NessiVector
# \return
# - The result NessiVector
# - The square of the uncertainty in the result NessiVector
#

def div_ncerr(a,ae2,b,be2):

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
# Vector_0[i]=\left( \sum^2_{n=1} \frac{Vector_n[i]}{\sigma_n[i]}\right)
# \times\left( \frac{1}{2} \sum^2_{n=1} \sigma_n[i] \right)
# \f]
# and
# \f[
# \sigma_0^2[i]=(\sigma_1^2\sigma_2 + \sigma_1\sigma_2^2)(\sigma_1+\sigma_2)
# \f]
# However, if the uncertainty in any of the data is zero, the value of the
# \f$Vector_0[i]\f$ will be given by
# \f[
# Vector_0[i]=\sum^2_{n=1} Vector_n[i]
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output
# NessiVector, \f$Vector_n[i]\f$ is the \f$i^{th}\f$ component of the
# \f$n^{th}\f$ NessiVector being added, \f$\sigma_0[i]\f$ is the
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
