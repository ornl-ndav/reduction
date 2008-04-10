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

"""
   This module gives the NessiList access to the various simple
   arithmetic operations on arrays provided by the C++ array_manip
   library. These arithmetic operations are written in references to SNS
   107030214-TD0001-R00, \"Data Reduction Library Software Requirements and
   Specifications\".

   Once a function is called, according to the type of the NessiLists calling
   it, the module redirects the call to the right function.
"""

import nessi_list
import array_manip_bind
import vpair_bind

from scl_defs import VERSION as __version__

##
# \namespace array_manip
#
# \brief Python abstraction layer access for ArrayManip library functions
#
# This module gives the NessiList access to the various simple
# arithmetic operations on arrays provided by the <i>array_manip</i>
# library. These arithmetic operations are written in references to SNS
# 107030214-TD0001-R00, "Data Reduction Library Software Requirements and
# Specifications".
#
# Once a function is called, according to the type of the NessiLists calling
# it, the module redirects the call to the right function.
#
# For example, when calling the function \f$add\f$ with two NessiList of
# type <i>float</i>, the module redirects the call to the function
# \f$add\_f\f$.
#

##
# \defgroup abs_val array_manip::abs_val
# \{
#

##
# \brief This function applies the absolute value to every element of a
# NessiList
#
# This function takes each element, \f$i\f$, and applies the absolute 
# value to that element 
# \f[
# data_{out}[i] = |data_{in}[i]|
# \f] 
# where \f$data_{out}[i]\f$ is the \f$i^{th}\f$ component of the output
# array, \f$data_{in}[i]\f$ is the \f$i^{th}\f$ component of the input 
# array.
#
# \param input (INPUT) is a NessiList to have its elements absolute valued
#
# \return
# - The resulting NessiList
#
# \exception TypeError is raised if the NessiList type is not double or int

def abs_val(input): 
    """
    This function takes each element, i, and applies the absolute value to
    that element 

    data_{out}[i] = |data_{in}[i]|

    where data_{out}[i] is the i^{th} component of the output array,
    data_{in}[i] is the i^{th} component of the input array.

    Parameters:
    ----------
    -> input is a NessiList to have its elements absolute valued

    Returns:
    -------
    <- The resulting NessiList

    Exceptions:
    ----------
    <- TypeError is raised if the NessiList type is not double or int
    
    """
    output = nessi_list.NessiList(len(input), type=input.__type__)
    if input.__type__ == input.DOUBLE:
        array_manip_bind.abs_val_d(input.__array__, output.__array__)
    elif input.__type__ == input.INT:
        array_manip_bind.abs_val_i(input.__array__, output.__array__)
    else:
        raise TypeError("Do not understand type %s" % input.__type__)

    return output
##
# \}

##
# \defgroup add_ncerr array_manip::add_ncerr
# \{

##
# \brief This function adds each element of two NessiList.
#
# This function accepts four NessiList as arguments or 2 NessiLists and
# 2 scalars.
#
# - With four NessiLists:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Vector_1, Vector_err2_1,
# Vector_2, Vector_err2_2)
# \endcode
#
# - With 2 NessiLists and 2 scalars:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Vector_1, Vector_err2_1,
# Scalar, Scalar_err2)
# \endcode
# or
# \code
# >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Scalar, Scalar_err2,
# Vector_1, Vector_err2_1)
# \endcode
# - With 4 scalars:
# \code
# >>> Scalar_o, Scalar_err2_o = array_manip.add_ncerr (Scalar_1, Scalar_err2_1,
# Scalar_2, Scalar_err2_2)
# \endcode
#
#     ========================================================================
#
# - With 4 NessiLists, this function adds each element, \f$i\f$, of two
# NessiLists according to the equation:
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
# - With 2 NessiLists and 2 scalars, this function adds a scalar to each
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
# - With 4 scalars, this function adds the numbers together and propgates
# the errors according to the equation:
# \f[
# data_o = data_1 + data_2
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2=\sigma_1^2 + \sigma_2^2
# \f]
#
# Multi-Dimensional Case
# ======================
#
# This function adds the \f$i^{th}\f$ element from \f$data_1\f$, which is 
# multi-dimensional vector being treated as a 1D vector, to the 
# \f$j^{th}\f$ element from \f$data_2\f$ and places it in the \f$k^{th}\f$ 
# element of \f$data_o\f$ according to the equation
# \f[
# data_o[k]=data_1[i]+data_2[j]
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2[k]=\sigma_1^2[i]+\sigma_2^2[j]
# \f]
# Where \f$data_o[k]\f$ is the \f$k^{th}\f$ component of the output
# array, \f$data_1[i]\f$ is the \f$i^{th}\f$ component of the first
# array being added, \f$data_2[j]\f$ is the \f$j^{th}\f$ component
# of the second array being added, \f$\sigma_o[k]\f$ is the
# \f$k^{th}\f$ component of the uncertainty of the output array,
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the
# uncertainty in the first array, and \f$\sigma_2[j]\f$ is the
# \f$j^{th}\f$ component of the uncertainty in the second array.
#
# The \f$i^{th}\f$, \f$j^{th}\f$ and \f$k^{th}\f$ elements of the 
# corresponding arrays are calculated according to the following equations
# \f[
# i_{N}^{th}=a\_start+a\_span\times N
# \f]
# \f[
# j_{N}^{th}=b\_start+b\_span\times N
# \f]
# \f[
# k_{N}^{th}=c\_start+c\_span\times N
# \f]
#
# The initial starting elements for all arrays are given by \f$a\_start\f$ 
# (\f$data_1\f$), \f$b\_start\f$ (\f$data_2\f$) and \f$c\_start\f$ 
# (\f$data_o\f$). The function runs until \f$size\f$ is reached.
#
# \param a (INPUT) is the first NessiList or scalar to be added
# \param ae2 (INPUT) is the square of the uncertainty in the first
# NessiList of in the scalar to be added
# \param b (INPUT) is the second NessiList or scalar to be added
# \param be2 (INPUT) is the square of the uncertainty in the second
# NessiList or scalar to be added
# \param kwargs (INPUT) is a list of keyword arguments that the function will
# accept
# \return
# - The result NessiList
# - The square of the uncertainty in the result NessiList
#
# \exception IndexError is thrown if a, ae2, b and be2 are not the same length
# \exception TypeError is thrown if any of the arrays are not recognized types
# \exception RuntimeError is thrown if a and b are not the same type

def add_ncerr(a, ae2, b, be2, **kwargs):

    """
    ---------------------------------------------------------------------------

    This function accepts four arguments:
     - 4 NessiLists
     - 2 NessiLists and 2 scalars
     - 4 scalars

    >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Vector_1,
        Vector_err2_1, Vector_2, Vector_err2_2)

    >>> Vector_o, Vector_err2_o = array_manip.add_ncerr (Vector, Vector_err2,
        Scalar, Scalar_err2)

    >>> Scalar_o, Scalar_err2_o = array_manip.add_ncerr (Scalar_1,
        Scalar_err2_1, Scalar_2, Scalar_err2_2)
        
    where Vector_o is the resulting NessiList and Vector_err2_o is the
    uncertainty in the NessiList o.

    ================================================================
    - With 4 NessiLists, this function adds each element, i, of two
    NessiLists according to the equation:

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

    - With 2 NessiLists and 2 scalars, this function adds each element of the
    NessiLists with a scalar according to the equation:

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

    - With 4 scalars, this function adds the numbers and propgates the errors
    according to the equation:

    Scalar_o = Scalar_1 + Scalar_2

    and the uncorrelated uncertainties will be processed according to the
    equation:

    Scalar_err2_o = Scalar_err2_1 + Scalar_err2_2

    >>> Multi-dimensional use <<<
    -----------------------------

    If kwargs are passed to the function, then the multi-dimensional version
    of add_ncerr will be used. The name and function of those keyword
    parameters are given in the Parameters section.

    This function adds the i^th element from Vector_1, which is
    multi-dimensional vector being treated as a 1D vector, to the j^th element
    from Vector_2 and places it in the k^th element of Vector_o according to
    the equation

    Vector_o[k] = Vector_1[i] + Vector_2[j]

    and the uncorrelated uncertainties will be processed according to
    the equation

    Vector_err2_o^2[k] = Vector_err2_1^2[i] + Vector_err2_2^2[j]

    Where Vector_o[k] is the k^th component of the output array, Vector_1[i]
    is the i^th component of the first array being added, Vector_2[j] is the
    j^th component of the second array being added, Vector_err2_o[k] is the
    k^th component of the uncertainty of the output array, Vector_err2_1[i] is
    the i^th component of the uncertainty in the first array, and
    Vector_err2_2[j] is the j^th component of the uncertainty in the second
    array.

    The i^th, j^th and k^th elements of the corresponding arrays are
    calculated according to the following equations

    i_N^th = a_start + a_span x N

    j_N^th = b_start + b_span x N

    k_N^th = c_start + c_span x N

    The initial starting elements for all arrays are given by a_start
    (Vector_1), b_start (Vector_2) and c_start (Vector_o). The function runs
    until size is reached.


    Parameters:
    __________

    -> a is the first NessiList or scalar to be added
    -> ae2 is the square of the uncertainty in the first NessiList or scalar
       to be added
    -> b is the second NessiList or scalar to be added
    -> be2 is the square of the uncertainty in the second NessiList or scalar
       to be added
    -> kwargs is a list of keyword arguments that the function accepts. This
       list is necessary in order to use the multi-dimensional version of
       add_ncerr
          a_start=<int> is the starting index in NessiList a (ae2) where the
                        values in NessiList b (be2) will be added. Default is
                        0
          a_span=<int> is the number of spots to jump in the array to retrieve
                       the next index for information from a and ae2. Default
                       is 1
          b_start=<int> is the starting index in NessiList b (be2) where the
                        values will be added to NessiList a (ae2). Default is
                        0 
          b_span=<int> is the number of spots to jump in the array to retrieve
                       the next index for information from b and be2. Default
                       is 1
          size=<int> is the number of elements will be added. This
                     may possbily be shorter than length of b. Default is
                     the length of b
          c_start=<int> is the starting index in NessiList c (ce2) where the
                        values in NessiList b (be2) will be added. Default is
                        a_start
          c_span=<int> is the number of spots to jump in the array to retrieve
                       the next index for information from c and ce2. Default
                       is a_span.
          acc=<boolean> is a flag to turn on accumulation mode for add. This
                        will cause the existing arrays (a and ae2) to be used
                        as the add target instead of a new set of arrays.
                        Default is True.

    Returns 2 Nessivectors:
    ______________________

    <- the result NessiList
    <- the square of the uncertainty in the result NessiList

    Exceptions:
    __________

    <- IndexError is thrown if a, ae2, b and be2 are not the same length
    <- TypeError is thrown if any of the arrays are not recognized types
    <- RuntimeError is thrown if a and b are not the same type

    """

    try:
        if a.__type__ != b.__type__:
            raise RuntimeError("Incompatible types passed to add_ncerr")
        else:
            pass

        try:
            a_start = int(kwargs["a_start"])
        except KeyError:
            a_start = 0
            
        try:
            a_span = int(kwargs["a_span"])
        except KeyError:
            a_span = 1
                
        try:
            b_start = int(kwargs["b_start"])
        except KeyError:
            b_start = 0
            
        try:
            b_span = int(kwargs["b_span"])
        except KeyError:
            b_span = 1
            
        try:
            size = int(kwargs["size"])
        except KeyError:
            size = len(b)
            
        try:
            c_start = int(kwargs["c_start"])
        except KeyError:
            c_start = a_start
            
        try:
            c_span = int(kwargs["c_span"])
        except KeyError:
            c_span = a_span

        try:
            acc = int(kwargs["acc"])
        except KeyError:
            acc = True

        if kwargs and acc:
            c = a
            ce2 = ae2
        else:
            c = nessi_list.NessiList(len(a), type=a.__type__)
            ce2 = nessi_list.NessiList(len(a), type=a.__type__)

        if a.__type__ == a.DOUBLE:
            if not kwargs:
                array_manip_bind.add_ncerr_d(a.__array__,
                                             ae2.__array__,
                                             b.__array__,
                                             be2.__array__,
                                             c.__array__,
                                             ce2.__array__)
            else:
                array_manip_bind.add_ncerr_d(a.__array__,
                                             ae2.__array__,
                                             a_start,
                                             a_span,
                                             b.__array__,
                                             be2.__array__,
                                             b_start,
                                             b_span,
                                             size,
                                             c.__array__,
                                             ce2.__array__,
                                             c_start,
                                             c_span)

        elif a.__type__ == a.INT:
            if not kwargs:
                array_manip_bind.add_ncerr_i(a.__array__,
                                             ae2.__array__,
                                             b.__array__,
                                             be2.__array__,
                                             c.__array__,
                                             ce2.__array__)
            else:
                array_manip_bind.add_ncerr_i(a.__array__,
                                             ae2.__array__,
                                             a_start,
                                             a_span,
                                             b.__array__,
                                             be2.__array__,
                                             b_start,
                                             b_span,
                                             size,
                                             c.__array__,
                                             ce2.__array__,
                                             c_start,
                                             c_span)

        else:
            raise TypeError("Unknown primative type %s" % str(a.__type__))

        return (c, ce2)

    except AttributeError:
        try:
            a.__type__
            scalar = b
            scalar_e2 = be2
            array = a
            array_e2 = ae2

            if array.__type__ == array.DOUBLE:
                c = nessi_list.NessiList(len(array), type=array.DOUBLE)
                ce2 = nessi_list.NessiList(len(array), type=array.DOUBLE)
            
                array_manip_bind.add_ncerr_d(array.__array__,
                                             array_e2.__array__,
                                             float(scalar),
                                             float(scalar_e2),
                                             c.__array__,
                                             ce2.__array__)
                
            elif array.__type__ == array.INT:
                c = nessi_list.NessiList(len(array), type=array.INT)
                ce2 = nessi_list.NessiList(len(array), type=array.INT)
                
                array_manip_bind.add_ncerr_i(array.__array__,
                                             array_e2.__array__,
                                             int(scalar),
                                             int(scalar_e2),
                                             c.__array__,
                                             ce2.__array__)
                
            else:
                raise TypeError("Unknown primative type %s" % \
                                str(array.__type__))
        
            return (c, ce2)
            
        except AttributeError:
            try:
                b.__type__
                scalar = a
                scalar_e2 = ae2
                array = b
                array_e2 = be2

                if array.__type__ == array.DOUBLE:
                    c = nessi_list.NessiList(len(array), type=array.DOUBLE)
                    ce2 = nessi_list.NessiList(len(array), type=array.DOUBLE)
            
                    array_manip_bind.add_ncerr_d(array.__array__,
                                                 array_e2.__array__,
                                                 float(scalar),
                                                 float(scalar_e2),
                                                 c.__array__,
                                                 ce2.__array__)
                    
                elif array.__type__ == array.INT:
                    c = nessi_list.NessiList(len(array), type=array.INT)
                    ce2 = nessi_list.NessiList(len(array), type=array.INT)
                    
                    array_manip_bind.add_ncerr_i(array.__array__,
                                                 array_e2.__array__,
                                                 int(scalar),
                                                 int(scalar_e2),
                                                 c.__array__,
                                                 ce2.__array__)
                    
                else:
                    raise TypeError("Unknown primative type %s" % \
                                    str(array.__type__))
        
                return (c, ce2)

            except AttributeError:

                try:
                    a.__float__
                    c = vpair_bind.DoubleVPair()
                    array_manip_bind.add_ncerr_ss_d(float(a), float(ae2),
                                                    float(b), float(be2),
                                                    c)
                except TypeError:
                    try:
                        a.__int__
                        c = vpair_bind.IntVPair()
                        array_manip_bind.add_ncerr_ss_i(int(a), int(ae2),
                                                        int(b), int(be2),
                                                        c)
                    except TypeError:
                        raise TypeError("Unknown primative type %s" % type(a))

                return (c.val, c.val_err2)



##
# \}

##
# \defgroup sub_ncerr array_manip::sub_ncerr
# \{

##
# \brief This function substracts each element of two NessiList.
#
# This function accepts four NessiList as arguments or 2 NessiLists and
# 2 scalars
#
# - With four NessiLists:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Vector_1, Vector_err2_1,
# Vector_2, Vector_err2_2)
# \endcode
#
# - With 2 NessiLists and 2 scalars:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Vector_1, Vector_err2_1,
# Scalar, Scalar_err2)
# \endcode
#
# - With 2 scalars and 2 NessiLists:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Scalar, Scalar_err2,
# Vector_1, Vector_err2_1)
# \endcode
#
# - With 4 scalars:
# \code
# >>> Scalar_o, Scalar_err2_o = array_manip.sub_ncerr (Scalar_1, Scalar_err2_1,
# Scalar_2, Scalar_err2_2)
# \endcode
#
#     ========================================================================
#
# - With 4 NessiLists, This function subtracts each element, \f$i\f$, of two
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
# - With 2 NessiLists and 2 Scalars, this function subtracts each element,
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
# - With 2 scalars and 2 NessiLists, this function subtracts a scalar by each
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
# - With 4 scalars, this function subtracts the numbers together and propgates
# the errors according to the equation:
# \f[
# data_o = data_1 - data_2
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2=\sigma_1^2 + \sigma_2^2
# \f]
#
# \param a (INPUT) is the NessiList or scalar to be subtracted from
# \param ae2 (INPUT) is the square of the uncertainty in the
# NessiList or scalar to be subtracted from
# \param b (INPUT) is the NessiList or scalar to subtract
# \param be2 (INPUT) is the square of the uncertainty in the NessiList or
# scalar to subtract
# \return
# - The result NessiList
# - The square of the uncertainty in the result NessiList
#
# \exception IndexError is thrown if a, ae2, b and be2 are not the same length
# \exception TypeError is thrown if any of the arrays are not recognized types
# \exception RuntimeError is thrown if a and b are not the same type

def sub_ncerr(a, ae2, b, be2):

    """
    ---------------------------------------------------------------------------

    This function accepts four arguments:
     - 4 NessiLists
     - 2 NessiLists and 2 scalars
     - 2 scalars and 2 NessiLists

    >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Vector_1,
        Vector_err2_1, Vector_2, Vector_err2_2)

    >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Vector, Vector_err2,
        Scalar, Scalar_err2)

    >>> Vector_o, Vector_err2_o = array_manip.sub_ncerr (Scalar, Scalar_err2,
        Vector, Vector_err2)

    >>> Scalar_o, Scalar_err2_o = array_manip.sub_ncerr (Scalar_1,
        Scalar_err2_1, Scalar_2, Scalar_err2_2)

    where Vector_o is the resulting NessiList and Vector_err2_o is the
    uncertainty in the NessiList o.

    ================================================================

    - With 4 NessiLists, this function subtracts each element, i, of two
    NessiLists according to the equation:

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

    - With 2 NessiLists and 2 scalars, this function subtracts a scalar
    from each element, i, of a NessiLists according to the equation:

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

    - With 2 scalar and 2 NessiLists, this function subtracts from a
    scalar each element, i, of a NessiLists according to the equation:

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

    - With 4 scalars, this function subtracts the numbers and propgates the
    errors according to the equation:

    Scalar_o = Scalar_1 - Scalar_2

    and the uncorrelated uncertainties will be processed according to the
    equation:

    Scalar_err2_o = Scalar_err2_1 + Scalar_err2_2

    Parameters:
    __________

    -> a is the NessiList or scalar to be subtracted from
    -> ae2 is the square of the uncertainty in the NessiList or scalar to be
       subtracted from
    -> b is the NessiList or scalar to subtract
    -> be2 is the square of the uncertainty in the NessiList or scalar to
       subtract

    Returns 2 NessiLists:
    ______________________

    <- the result NessiList
    <- the square of the uncertainty in the result NessiList

    Exceptions:
    __________

    <- IndexError is thrown if a, ae2, b and be2 are not the same length
    <- TypeError is thrown if any of the arrays are not recognized types
    <- RuntimeError is thrown if a and b are not the same type

    """

    try:
        if a.__type__ != b.__type__:
            raise RuntimeError("Incompatible types passed to sub_ncerr")
        else:
            pass

        if a.__type__ == a.DOUBLE:
            c = nessi_list.NessiList(len(a), type=a.DOUBLE)
            ce2 = nessi_list.NessiList(len(a), type=a.DOUBLE)
            
            array_manip_bind.sub_ncerr_d(a.__array__,
                                         ae2.__array__,
                                         b.__array__,
                                         be2.__array__,
                                         c.__array__,
                                         ce2.__array__)

        elif a.__type__ == a.INT:
            c = nessi_list.NessiList(len(a), type=a.INT)
            ce2 = nessi_list.NessiList(len(a), type=a.INT)
            
            array_manip_bind.sub_ncerr_i(a.__array__,
                                         ae2.__array__,
                                         b.__array__,
                                         be2.__array__,
                                         c.__array__,
                                         ce2.__array__)

        else:
            raise TypeError("Unknown primative type %s" % str(a.__type__))

        return (c, ce2)

    except AttributeError:
        try:
            a.__type__
            scalar = b
            scalar_e2 = be2
            array = a
            array_e2 = ae2
            
            if array.__type__ == array.DOUBLE:
                c = nessi_list.NessiList(len(array), type=array.DOUBLE)
                ce2 = nessi_list.NessiList(len(array), type=array.DOUBLE)
                
                array_manip_bind.sub_ncerr_d(array.__array__,
                                             array_e2.__array__,
                                             float(scalar),
                                             float(scalar_e2),
                                             c.__array__,
                                             ce2.__array__)
                
            elif array.__type__ == array.INT:
                c = nessi_list.NessiList(len(array), type=array.INT)
                ce2 = nessi_list.NessiList(len(array), type=array.INT)
                
                array_manip_bind.sub_ncerr_i(array.__array__,
                                             array_e2.__array__,
                                             int(scalar),
                                             int(scalar_e2),
                                             c.__array__,
                                             ce2.__array__)
                
            else:
                raise TypeError("Unknown primative type %s" \
                                % str(array.__type__))
            
            return (c, ce2)

        except AttributeError:
            try:
                b.__type__
                scalar = a
                scalar_e2 = ae2
                array = b
                array_e2 = be2
            
                if array.__type__ == array.DOUBLE:
                    c = nessi_list.NessiList(len(array), type=array.DOUBLE)
                    ce2 = nessi_list.NessiList(len(array), type=array.DOUBLE)
                    
                    array_manip_bind.sub_ncerr_d(float(scalar),
                                                 float(scalar_e2),
                                                 array.__array__,
                                                 array_e2.__array__,
                                                 c.__array__,
                                                 ce2.__array__)
                    
                elif array.__type__ == array.INT:
                    c = nessi_list.NessiList(len(array), type=array.INT)
                    ce2 = nessi_list.NessiList(len(array), type=array.INT)
                    
                    array_manip_bind.sub_ncerr_i(int(scalar),
                                                 int(scalar_e2),
                                                 array.__array__,
                                                 array_e2.__array__,
                                                 c.__array__,
                                                 ce2.__array__)
                    
                else:
                    raise TypeError("Unknown primative type %s" \
                                    % str(array.__type__))
            
                return (c, ce2)

            except AttributeError:
                try:
                    a.__float__
                    c = vpair_bind.DoubleVPair()
                    array_manip_bind.sub_ncerr_ss_d(float(a), float(ae2),
                                                    float(b), float(be2),
                                                    c)
                except TypeError:
                    try:
                        a.__int__
                        c = vpair_bind.IntVPair()
                        array_manip_bind.sub_ncerr_ss_i(int(a), int(ae2),
                                                        int(b), int(be2),
                                                        c)
                    except TypeError:
                        raise TypeError("Unknown primative type %s" % type(a))

                return (c.val, c.val_err2)
                        
##
# \}

##
# \defgroup mult_ncerr array_manip::mult_ncerr
# \{

##
# \brief This function multiplies each element of two NessiList.
#
# This function accepts four NessiList as arguments or 2 NessiLists and 2
# scalars.
#
# - With four NessiLists:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.mult_ncerr (Vector_1,Vector_err2_1,
# Vector_2,Vector_err2_2)
# \endcode
#
# - With 2 NessiLists and 2 scalars:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.mult_ncerr (Vector,Vector_err2,
# Scalar, Scalar_err2)
# \endcode
# - With 4 scalars:
# \code
# >>> Scalar_o, Scalar_err2_o = array_manip.add_ncerr (Scalar_1, Scalar_err2_1,
# Scalar_2, Scalar_err2_2)
# \endcode
#
#     ========================================================================
#
# - With 4 NessiLists, this function multiply each element, \f$i\f$, of two
# NessiLists according to the equation:
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
# - With 2 NessiLists and 2 scalars, this function multiplies a scalar to
# each element, \f$i\f$, of an NessiList according to the equation
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
# - With 4 scalars, this function adds the numbers together and propgates
# the errors according to the equation:
# \f[
# data_o = data_1 \times data_2
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2=(data_1\times\sigma_2)^2
# +(data_2\times\sigma_1)^2
# \f]
#
# \param a (INPUT) is the first NessiList/scalar to be multiplied
# \param ae2 (INPUT) is the square of the uncertainty in the first
# NessiList/scalar to be multiplied
# \param b (INPUT) is the second NessiList/scalar to be multiplied
# \param be2 (INPUT) is the square of the uncertainty in the second
# NessiList/scalar to be multiplied
#
# \return
# - The result NessiList/scalar
# - The square of the uncertainty in the result NessiList/scalar
#
# \exception IndexError is thrown if a, ae2, b and be2 are not the same length
# \exception TypeError is thrown if any of the arrays are not recognized types
# \exception RuntimeError is thrown if a and b are not the same type

def mult_ncerr(a, ae2, b, be2):

    """
    ---------------------------------------------------------------------------

    This function accepts four arguments:
       - 4 NessiLists
       - 2 NessiLists and 2 scalars

    >>> Vector_o, Vector_err2_o = array_manip.mult_ncerr (Vector_1,
        Vector_err2_1, Vector_2, Vector_err2_2)

    >>> Vector_o, Vector_err2_o = array_manip.mult_ncerr (Vector, Vector_err2,
        Scalar, Scalar_err2)

    >>> Scalar_o, Scalar_err2_o = array_manip.add_ncerr (Scalar_1,
        Scalar_err2_1, Scalar_2, Scalar_err2_2)        

    where Vector_o is the resulting NessiList and Vector_err2_o is the
    uncertainty in the NessiList o.

    =================================================================

    - With 4 NessiLists, this function multiply each element, i, of two
    NessiLists according to the equation:

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

    - With 2 NessiLists and 2 scalars, this function multiply each element
    of the NessiLists with a scalar according to the equations:

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

    - With 4 scalars, this function adds the numbers and propgates the errors
    according to the equation:

    Scalar_o = Scalar_1 * Scalar_2

    and the uncorrelated uncertainties will be processed according to the
    equation:

    Scalar_err2_o = (Scalar_err2_1 * Scalar_2^2) + (Scalar_err2_2 * Scalar_1^2)

    Parameters:
    __________

    -> a is the first NessiList or scalar to be multiplied
    -> ae2 is the square of the uncertainty in the first NessiList or scalar
       to be multiplied
    -> b is the second NessiList or scalar to be multiplied
    -> be2 is the square of the uncertainty in the second NessiList or
       scalar to be multiplied

    Returns 2 NessiLists or 2 scalars:
    ______________________

    <- the result NessiList/scalar
    <- the square of the uncertainty in the result NessiList/scalar

    Exceptions:
    __________

    <- IndexError is thrown if a, ae2, b and be2 are not the same length
    <- TypeError is thrown if any of the arrays are not recognized types
    <- RuntimeError is thrown if a and b are not the same type

    """

    try:
        if a.__type__ != b.__type__:
            raise RuntimeError("Incompatible types passed to mult_ncerr")
        else:
            pass

        if a.__type__ == a.DOUBLE:
            c = nessi_list.NessiList(len(a), type=a.DOUBLE)
            ce2 = nessi_list.NessiList(len(a), type=a.DOUBLE)
            
            array_manip_bind.mult_ncerr_d(a.__array__,
                                          ae2.__array__,
                                          b.__array__,
                                          be2.__array__,
                                          c.__array__,
                                          ce2.__array__)

        elif a.__type__ == a.INT:
            c = nessi_list.NessiList(len(a), type=a.INT)
            ce2 = nessi_list.NessiList(len(a), type=a.INT)
            
            array_manip_bind.mult_ncerr_i(a.__array__,
                                          ae2.__array__,
                                          b.__array__,
                                          be2.__array__,
                                          c.__array__,
                                          ce2.__array__)

        else:
            raise TypeError("Unknown primative type %s" % str(a.__type__))

        return (c, ce2)

    except AttributeError:
        try:
            a.__type__
            scalar = b
            scalar_e2 = be2
            array = a
            array_e2 = ae2

            if array.__type__ == array.DOUBLE:
                c = nessi_list.NessiList(len(array), type=array.DOUBLE)
                ce2 = nessi_list.NessiList(len(array), type=array.DOUBLE)
                
                array_manip_bind.mult_ncerr_d(array.__array__,
                                              array_e2.__array__,
                                              float(scalar),
                                              float(scalar_e2),
                                              c.__array__,
                                              ce2.__array__)
                
            elif array.__type__ == array.INT:
                c = nessi_list.NessiList(len(array), type=array.INT)
                ce2 = nessi_list.NessiList(len(array), type=array.INT)
                
                array_manip_bind.mult_ncerr_i(array.__array__,
                                              array_e2.__array__,
                                              int(scalar),
                                              int(scalar_e2),
                                              c.__array__,
                                              ce2.__array__)
                
            else:
                raise TypeError("Unknown primative type %s" % str(a.__type__))

            return (c, ce2)
        
        except AttributeError:
            try:
                b.__type__
                scalar = a
                scalar_e2 = ae2
                array = b
                array_e2 = be2
            
                if array.__type__ == array.DOUBLE:
                    c = nessi_list.NessiList(len(array), type=array.DOUBLE)
                    ce2 = nessi_list.NessiList(len(array), type=array.DOUBLE)
                    
                    array_manip_bind.mult_ncerr_d(array.__array__,
                                                  array_e2.__array__,
                                                  float(scalar),
                                                  float(scalar_e2),
                                                  c.__array__,
                                                  ce2.__array__)
                    
                elif array.__type__ == array.INT:
                    c = nessi_list.NessiList(len(array), type=array.INT)
                    ce2 = nessi_list.NessiList(len(array), type=array.INT)
                    
                    array_manip_bind.mult_ncerr_i(array.__array__,
                                                  array_e2.__array__,
                                                  int(scalar),
                                                  int(scalar_e2),
                                                  c.__array__,
                                                  ce2.__array__)
                    
                else:
                    raise TypeError("Unknown primative type %s" % \
                                    str(a.__type__))
            
                return (c, ce2)

            except AttributeError:
                if str(type(a)).split('\'')[-2] == "float":
                    c = vpair_bind.DoubleVPair()
                    array_manip_bind.mult_ncerr_ss_d(float(a), float(ae2),
                                                     float(b), float(be2),
                                                     c)
                elif str(type(a)).split('\'')[-2] == "int":
                    c = vpair_bind.IntVPair()
                    array_manip_bind.mult_ncerr_ss_i(int(a), int(ae2),
                                                     int(b), int(be2),
                                                     c)
                else:
                    raise TypeError("Unknown primative type %s" % type(a))
                
                return (c.val, c.val_err2)
        
##
# \}

##
# \defgroup div_ncerr array_manip::div_ncerr
# \{

##
# \brief This function divides each element of two NessiLists.
#
# This function accepts four NessiLists as arguments, 2 NessiLists and 2
# scalars or 2 scalars and 2 NessiLists.
#
# - With 4 NessiLists:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Vector_1,
# Vector_err2_1,\# Vector_2, Vector_err2_2)
# \endcode
#
# - With 2 NessiLists and 2 scalars:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Vector, Vector_err2,
# Scalar, Scalar_err2)
# \endcode
#
# - With 2 scalars and 2 NessiLists:
# \code
# >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Scalar, Scalar_err2,
# Vector, Vector_err2)
# \endcode
#
# - With 4 scalars:
# \code
# >>> Scalar_o, Scalar_err2_o = array_manip.div_ncerr (Scalar_1, Scalar_err2_1,
# Scalar_2, Scalar_err2_2)
# \endcode
#
#     ========================================================================
#
# - With 4 NessiLists, this function divides each element, \f$i\f$, of two
# NessiLists according to the equation
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
# - With 2 NessiLists and 2 scalars, this function divides each element,
# \f$i\f$, of a NessiList by a scalar according to the equation
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
# - With 2 Scalars and 2 NessiLists, this function divides a scalar by each
# element, \f$i\f$, of a NessiList according to the equation
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
# - With 4 Scalars, this function divides a scalar by the other scalar
# according to the equation
# \f[
# data_o=data_1/data_2
# \f]
# and the uncorrelated uncertainties will be processed according to
# the equation
# \f[
# \sigma_o^2=\left(\frac{data_1 \times \sigma_2}{data_2^2}\right)^2
#                 +\left(\frac{\sigma_1}{data_2}\right)^2
# \f]
#
# \param a (INPUT) is the NessiList/scalar being divided
# \param ae2 (INPUT) is the dividing NessiLists/scalar, if they are no more
# arguments present, otherwise it's the square of the uncertainty in the
# NessiList/scalar being divided
# \param b (INPUT) is the dividing NessiList/scalar
# \param be2 (INPUT) is the square of the uncertainty in the dividing
# NessiList/scalar
#
# \return
# - The result NessiList/scalar
# - The square of the uncertainty in the result NessiList/scalar
#
# \exception IndexError is thrown if a, ae2, b and be2 are not the same length
# \exception TypeError is thrown if any of the arrays are not recognized types
# \exception RuntimeError is thrown if a and b are not the same type

def div_ncerr(a, ae2, b, be2):

    """
    ---------------------------------------------------------------------------

    This function accepts four arguments:
       - 4 NessiLists

    >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Vector_1,
        Vector_err2_1, Vector_2, Vector_err2_2)

       - 2 NessiLists and 2 scalars

    >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Vector, Vector_err2,
        Scalar, Scalar_err2)

       - 2 scalars and 2 NessiLists

    >>> Vector_o, Vector_err2_o = array_manip.div_ncerr (Scalar, Scalar_err2,
        Vector, Vector_err2)

       - 4 scalars

    >>> Scalar_o, Scalar_err2_o = array_manip.div_ncerr (Scalar_1,
        Scalar_err2_1, Scalar_2, Scalar_err2_2)        

    where Vector_o is the resulting NessiList and Vector_err2_o is the
    uncertainty in the NessiList o.

    =================================================================

    - With 4 NessiLists, this function divides each element, i, of two
    NessiLists according to the equation:

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

    - With 2 NessiLists and 2 scalars, this function divides each element
    of the NessiLists with a scalar according to the equations:

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

    - With 2 scalar and 2 NessiLists, this function divides each element
    of the NessiLists with a scalar according to the equations:

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

    - With 4 scalars, this function divides the numbers and propgates the
    errors according to the equation:

    Scalar_o = Scalar_1 / Scalar_2

    and the uncorrelated uncertainties will be processed according to the
    equation:

    Scalar_err2_o = {(Scalar_1*Scalar_err2_2)/(Scalar_2^2)}^2
    +{(Scalar_err2_1)/(Scalar_2)}^2

    Parameters:
    __________

    -> a is the NessiList or scalar to be divided from
    -> ae2 is the square of the uncertainty in the NessiList or scalar to
       be divided from
    -> b is the NessiList or scalar to divide by
    -> be2 is the square of the uncertainty in the NessiList or scalar to
       divide by

    Returns 2 NessiLists or 2 scalars:
    ______________________

    <- the result NessiList/scalar
    <- the square of the uncertainty in the result NessiList/scalar

    Exceptions:
    __________

    <- IndexError is thrown if a, ae2, b and be2 are not the same length
    <- TypeError is thrown if any of the arrays are not recognized types
    <- RuntimeError is thrown if a and b are not the same type

    """

    try:
        if a.__type__ != b.__type__:
            raise RuntimeError("Incompatible types passed to div_ncerr")
        else:
            pass

        if a.__type__ == a.DOUBLE:
            c = nessi_list.NessiList(len(a), type=a.DOUBLE)
            ce2 = nessi_list.NessiList(len(a), type=a.DOUBLE)
            
            array_manip_bind.div_ncerr_d(a.__array__,
                                         ae2.__array__,
                                         b.__array__,
                                         be2.__array__,
                                         c.__array__,
                                         ce2.__array__)

        elif a.__type__ == a.INT:
            c = nessi_list.NessiList(len(a), type=a.INT)
            ce2 = nessi_list.NessiList(len(a), type=a.INT)
            
            array_manip_bind.div_ncerr_i(a.__array__,
                                         ae2.__array__,
                                         b.__array__,
                                         be2.__array__,
                                         c.__array__,
                                         ce2.__array__)

        else:
            raise TypeError("Unknown primative type %s" % str(a.__type__))

        return (c, ce2)

    except AttributeError:
        try:
            a.__type__
            scalar = b
            scalar_e2 = be2
            array = a
            array_e2 = ae2
            
            if array.__type__ == array.DOUBLE:
                c = nessi_list.NessiList(len(array), type=array.DOUBLE)
                ce2 = nessi_list.NessiList(len(array), type=array.DOUBLE)
                
                array_manip_bind.div_ncerr_d(array.__array__,
                                             array_e2.__array__,
                                             float(scalar),
                                             float(scalar_e2),
                                             c.__array__,
                                             ce2.__array__)
                
            elif array.__type__ == array.INT:
                c = nessi_list.NessiList(len(array), type=array.INT)
                ce2 = nessi_list.NessiList(len(array), type=array.INT)
                
                array_manip_bind.div_ncerr_i(array.__array__,
                                             array_e2.__array__,
                                             int(scalar),
                                             int(scalar_e2),
                                             c.__array__,
                                             ce2.__array__)
                
            else:
                raise TypeError("Unknown primative type %s" \
                                % str(array.__type__))
            
            return (c, ce2)
        
        except AttributeError:
            try:
                b.__type__
                scalar = a
                scalar_e2 = ae2
                array = b
                array_e2 = be2
            
                if array.__type__ == array.DOUBLE:
                    c = nessi_list.NessiList(len(array), type=array.DOUBLE)
                    ce2 = nessi_list.NessiList(len(array), type=array.DOUBLE)
                    
                    array_manip_bind.div_ncerr_d(float(scalar),
                                                 float(scalar_e2),
                                                 array.__array__,
                                                 array_e2.__array__,
                                                 c.__array__,
                                                 ce2.__array__)
                    
                elif array.__type__ == array.INT:
                    c = nessi_list.NessiList(len(array), type=array.INT)
                    ce2 = nessi_list.NessiList(len(array), type=array.INT)
                    
                    array_manip_bind.div_ncerr_i(int(scalar),
                                                 int(scalar_e2),
                                                 array.__array__,
                                                 array_e2.__array__,
                                                 c.__array__,
                                                 ce2.__array__)
                    
                else:
                    raise TypeError("Unknown primative type %s" \
                                    % str(array.__type__))
                
                return (c, ce2)

            except AttributeError:
                if str(type(a)).split('\'')[-2] == "float":
                    c = vpair_bind.DoubleVPair()
                    array_manip_bind.div_ncerr_ss_d(float(a), float(ae2),
                                                    float(b), float(be2),
                                                    c)
                elif str(type(a)).split('\'')[-2] == "int":
                    c = vpair_bind.IntVPair()
                    array_manip_bind.div_ncerr_ss_i(int(a), int(ae2),
                                                    int(b), int(be2),
                                                    c)
                else:
                    raise TypeError("Unknown primative type %s" % type(a))

                return (c.val, c.val_err2)            

##
# \}

##
# \defgroup sumw_ncerr array_manip::sumw_ncerr
# \{

##
# \brief This function adds two NessiList weighted by their uncertainties.
#
# This function adds two NessiList weighted by their uncertainties according
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
# NessiList, \f$Vector_n[i]\f$ is the \f$i^{th}\f$ component of the
# \f$n^{th}\f$ NessiList being added, \f$\sigma_o[i]\f$ is the
# \f$i^{th}\f$ component of the uncertainty of the output NessiList,
# \f$\sigma_n[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the \f$n^{th}\f$ NessiList being added.
#
# \param a (INPUT) is the first NessiList to be added
# \param ae2 (INPUT) is the square of the uncertainty in the first NessiList
# to be added
# \param b (INPUT) is the second NessiList to be added
# \param be2 (INPUT) is the square of the uncertainty in the second
# NessiList to be added
# \return
# - The result NessiList
# - The square of the uncertainty in the result NessiList
#
# \exception IndexError is thrown if a, ae2, b and be2 are not the same length
# \exception TypeError is thrown if any of the arrays are not recognized types
# \exception RuntimeError is thrown if a and b are not the same type

def sumw_ncerr(a, ae2, b, be2):

    """
    ---------------------------------------------------------------------------

    This function accepts four arguments:
        - 4 NessiLists

    >>> Vector_o, Vector_err2_o = array_manip.sumw_ncerr(Vector_1,
        Vector_1_err2)

    where Vector_o is the resulting NessiList and NessiList_err2_o is the
    uncertainty in the NessiList o.

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

    Parameters:
    __________

    -> a is the first NessiList to be added
    -> ae2 is the square of the uncertainty in the first NessiList to be
       added
    -> b is the second NessiList to be added
    -> be2 is the square of the uncertainty in the second NessiList to be
       added

    Returns 2 NessiLists:
    ______________________

    <- the result NessiList
    <- the square of the uncertainty in the result NessiList

    Exceptions:
    __________

    <- IndexError is thrown if a, ae2, b and be2 are not the same length
    <- TypeError is thrown if any of the arrays are not recognized types
    <- RuntimeError is thrown if a and b are not the same type

    """

    if a.__type__ != b.__type__:
        raise RuntimeError("Incompatible types passed to sumw_ncerr")
    else:
        pass

    if a.__type__ == a.DOUBLE:
        c = nessi_list.NessiList(len(a), type=a.DOUBLE)
        ce2 = nessi_list.NessiList(len(a), type=a.DOUBLE)
        
        array_manip_bind.sumw_ncerr_d(a.__array__,
                                      ae2.__array__,
                                      b.__array__,
                                      be2.__array__,
                                      c.__array__,
                                      ce2.__array__)

    elif a.__type__ == a.INT:
        c = nessi_list.NessiList(len(a), type=a.INT)
        ce2 = nessi_list.NessiList(len(a), type=a.INT)
        
        array_manip_bind.sumw_ncerr_i(a.__array__,
                                      ae2.__array__,
                                      b.__array__,
                                      be2.__array__,
                                      c.__array__,
                                      ce2.__array__)

    else:
        raise TypeError("Unknown primative type %s" % str(a.__type__))

    return (c, ce2)

##
# \}

