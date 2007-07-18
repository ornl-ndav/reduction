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
# \file bindings/utils.py
#

"""
   This module gives the NessiList access to the various utility functions
   provided by the C++ utils library. These functions are written in
   references to SNS 107030214-TD0001-R00, \"Data Reduction Library Software
   Requirements and Specifications\".

   Once a function is called, according to the type of the NessiLists calling
   it, the module redirects the call to the right function.
"""

import nessi_list
import utils_bind
import vpair_bind

##
# \namespace utils
#
# \brief This Python abstraction layer module provides various utility
# functions
#
# This module gives the NessiList access to the various utility functions
# provided by the <i>utils</i> library. These functions are written in
# references to SNS 107030214-TD0001-R00, "Data Reduction Library Software
# Requirements and Specifications".
#
# Once a function is called, according to the type of the NessiLists calling
# it, the module redirects the call to the right function.
#
# For example, when calling the function \f$weighted\_average\f$ with two
# NessiLists (data and error\f${}^2\f$) of type <i>double</i>, the module
# redirects the call to the function \f$weighted\_average\_d\f$.
#

##
# \defgroup calib_refl_areadet \
# utils::calib_refl_areadet
# \{
#

##
# \brief This function calibrates a reflectometer 2D detector array for
#        pixel variations
#
# This function is described in section 3.45 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def calib_refl_areadet():
    """
    ---------------------------------------------------------------------------
    This function calibrates a reflectometer 2D detector array for pixel
    variations

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError("This function is not implemented.")

##
# \}

##
# \defgroup compare utils::compare
# \{

##
# \brief This function compares two numbers and returns 0 (eq), 1 (gt) or
# -1 (lt).
#
# This function takes two numbers on compares them. The function returns
# 0 is the two numbers are equal, 1 if the first number is larger than the
# second number, and -1 if the first number is smaller than the second
# number.
#
# \param value1 (INPUT) is the first number to be compared
# \param value2 (INPUT) is the second number to be compared
#
# \return 0 (eq), 1 (gt) or -1 (lt)
#

def compare(value1, value2):

    """
    ---------------------------------------------------------------------------
    This function takes two numbers on compares them. The function returns 0
    is the two numbers are equal, 1 if the first number is larger than the
    second number, and -1 if the first number is smaller than the second
    number.

    Parameters:
    ----------
    -> value1 is the first number to be compared
    -> value2 is the second number to be compared

    Return:
    ------
    <- 0 (eq), 1 (gt) or -1 (lt)

    """

    result = utils_bind.compare(value1, value2)
    return result

##
# \}

##
# \defgroup fit_linear_background utils::fit_linear_background
# \{

##
# \brief This function fits a line to an array
#
# This function is described in section 3.43 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def fit_linear_background():
    """
    ---------------------------------------------------------------------------
    This function fits a line to an array

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError("This function is not implemented.")

##
# \}

##
# \defgroup fit_reflectometer_background utils::fit_reflectometer_background
# \{

##
# \brief This function fits a plane to reflectometer 2D detector array data
#
# This function is described in section 3.42 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def fit_reflectometer_background():
    """
    ---------------------------------------------------------------------------
    This function fits a plane to reflectometer 2D detector array data

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError("This function is not implemented.")

##
# \}

##
# \defgroup linear_order_jacobian utils::linear_order_jacobian
# \{

##
# \brief This function calculates the linear order jacobian
#
# This function is described in section 3.49 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function corrects the input based on the ratio of differences 
# between bin boundaries from the associated orignal and transformed axes.
# This correction only applies to <b>histogram</b> data. <b>The incoming axes
# and counts arrays should be in their original form (no reversing), otherwise 
# the calculation of the Jacobians will be done incorrectly</b>. The 
# calculation of the linear order Jacobian is accomplished by:
#
# \f[
# I'[k] = I[k] \times \left|\frac{x[k+1] - x[k]}{x'[k+1] - x'[k]}\right|
# \f]
#
# where \f$I'[k]\f$ is the \f$k^{th}\f$ element of the corrected counts, 
# \f$I[k]\f$ is the \f$k^{th}\f$ element of the counts associated with a 
# particular histogram bin \f$k\f$, \f$x[k+1]\f$ is the high bin boundary 
# and \f$x[k]\f$ is the low bin boundary from the original axis and 
# \f$x'[k+1]\f$ is the high bin boundary and \f$x'[k]\f$ is the low bin 
# boundary from the transformed axis. 
#
# The square of the uncertainty is calculated via:
# 
# \f[
# \sigma^2_{I'}[k] = \sigma^2_I[k] \times \left(\frac{x[k+1] - x[k]}
# {x'[k+1] - x'[k]}\right)^2
# \f]
#
# where \f$\sigma^2_{I'}[k]\f$ is the \f$k^{th}\f$ element of the square of 
# the uncertainty of the corrected counts, \f$\sigma^2_I[k]\f$ is the 
# \f$k^{th}\f$ element of the square of the uncertainty in the counts 
# associated with a particular histogram bin \f$k\f$, \f$x[k+1]\f$ is the 
# high bin boundary and \f$x[k]\f$ is the low bin boundary from the 
# original axis and \f$x'[k+1]\f$ is the high bin boundary and \f$x'[k]\f$ 
# is the low bin boundary from the transformed axis.
#
# \param orig_axis (INPUT) is the original histogram axis associated with 
# the data
# \param transform_axis (INPUT) is the transformed histogram axis 
# associated with the data
# \param input (INPUT) is the counts data
# \param input_err2 (INPUT) is the square of the uncertainty in the counts 
# data
# \return
# - the corrected counts array
# - the corrected square of the uncertainty in the counts array
#

def linear_order_jacobian(orig_axis, transform_axis, input, input_err2):
    """
    This function corrects the input based on the ratio of differences 
    between bin boundaries from the associated orignal and transformed axes.
    This correction only applies to HISTOGRAM data. THE INCOMING AXES AND
    COUNTS ARRAYS SHOULD BE IN THEIR ORIGINAL FORM (NO REVERSING), OTHERWISE
    THE CALCULATION OF THE JACOBIANS WILL BE DONE INCORRECTLY. The calculation
    of the linear order Jacobian is accomplished by:

    I'[k] = I[k] * |(x[k+1] - x[k])/(x'[k+1] - x'[k])|

    where I'[k] is the k^{th} element of the corrected counts, I[k] is the
    k^{th} element of the counts associated with a particular histogram bin k,
    x[k+1] is the high bin boundary and x[k] is the low bin boundary from the
    original axis and x'[k+1] is the high bin boundary and x'[k] is the low
    bin boundary from the transformed axis. 

    The square of the uncertainty is calculated via:

    sigma^2_{I'}[k] = sigma^2_I[k] * ((x[k+1] - x[k])/(x'[k+1] - x'[k]))^2

    where sigma^2_{I'}[k] is the k^{th} element of the square of the
    uncertainty of the corrected counts, sigma^2_I[k] is the k^{th} element of
    the square of the uncertainty in the counts associated with a particular
    histogram bin k, x[k+1] is the high bin boundary and x[k] is the low bin
    boundary from the original axis and x'[k+1] is the high bin boundary and
    x'[k] is the low bin boundary from the transformed axis.

    Parameters:
    ----------
    -> orig_axis (INPUT) is the original histogram axis associated with the
    data
    -> transform_axis (INPUT) is the transformed histogram axis associated
    with the data
    -> input (INPUT) is the counts data
    -> input_err2 (INPUT) is the square of the uncertainty in the counts data

    Returns:
    -------
    <- The corrected counts array
    <- The corrected uncertainty squared in the counts array
    """

    if orig_axis.__type__ != input.__type__:
        raise TypeError("Original Axis and Input Data are not the same type.")

    if orig_axis.__type__ != transform_axis.__type__:
        raise TypeError("Original Axis and Transform Axis are not the same"\
                        +"type.")

    if input.__type__ != input_err2.__type__:
        raise TypeError("Input and Input Err2 arrays are not the same type")

    if input.__type__ == nessi_list.NessiList.DOUBLE:
        output = nessi_list.NessiList(len(input))
        output_err2 = nessi_list.NessiList(len(input_err2))
        utils_bind.linear_order_jacobian_d(orig_axis.__array__,
                                           transform_axis.__array__,
                                           input.__array__,
                                           input_err2.__array__,
                                           output.__array__,
                                           output_err2.__array__)

        return (output, output_err2)

    else:
        raise TyperError("Unknown primative type %s" % str(input.__type__))

##
# \}

##
# \defgroup linear_order_jacobian_s utils::linear_order_jacobian_s
# \{

##
# \brief This function calculates the linear order jacobian
#
# This function is described in section 3.49 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function corrects the input based on the ratio of differences 
# between bin boundaries from the associated orignal and transformed axes.
# This correction only applies to <b>histogram</b> data. <b>The bin boundaries
# should be in their original order (no reversing) with respect to the counts, 
# otherwise the calculation of the Jacobian will be incorrect</b>. The 
# calculation of the linear order Jacobian is accomplished by:
#
# \f[
# I' = I \times \left|\frac{x_{hi} - x_{lo}}{x'_{hi} - x'_{lo}}\right|
# \f]
#
# where \f$I'\f$ is the corrected counts, \f$I\f$ is the counts associated 
# with a particular histogram bin, \f$x_{hi}\f$ is the high bin boundary 
# and \f$x_{lo}\f$ is the low bin boundary from the original axis and 
# \f$x'_{hi}\f$ is the high bin boundary and \f$x'_{lo}\f$ is the low bin 
# boundary from the transformed axis.
#
# The square of the uncertainty is calculated via:
# 
# \f[
# \sigma^2_{I'} = \sigma^2_I \times \left(\frac{x_{hi} - x_{lo}}
# {x'_{hi} - x'_{lo}}\right)^2
# \f]
#
# where \f$\sigma^2_{I'}\f$ is the square of the uncertainty of the 
# corrected counts, \f$\sigma^2_I\f$ is the square of the uncertainty in 
# the counts associated with a particular histogram bin, \f$x_{hi}\f$ is 
# the high bin boundary and \f$x_{lo}\f$ is the low bin boundary from the 
# original axis and \f$x'_{hi}\f$ is the high bin boundary and 
# \f$x'_{lo}\f$ is the low bin boundary from the transformed axis.
#
# \param orig_axis_lo (INPUT) is the low bin boundary of the original 
# histogram axis associated with the data
# \param orig_axis_hi (INPUT) is the high bin boundary of the original 
# histogram axis associated with the data
# \param transform_axis_lo (INPUT) is the low bin boundary of the 
# transformed histogram axis associated with the data
# \param transform_axis_hi (INPUT) is the high bin boundary of the 
# transformed histogram axis associated with the data
# \param input (INPUT) is the counts data
# \param input_err2 (INPUT) is the square of the uncertainty in the counts 
# data
# \return 
# - the corrected counts
# - the corrected square of the uncertainty in the counts
#
   
def linear_order_jacobian_s(orig_axis_lo, orig_axis_hi, transform_axis_lo,
                            transform_axis_hi, input, input_err2):
   """
   This function corrects the input based on the ratio of differences 
   between bin boundaries from the associated orignal and transformed axes.
   This correction only applies to HISTOGRAM data. THE BIN BOUNDARIES SHOULD
   BE IN THEIR ORIGINAL ORDER (NO REVERSING) WITH RESPECT TO THE COUNTS,
   OTHERWISE THE CALCULATION OF THE JACOBIAN WILL BE INCORRECT. The
   calculation of the linear order Jacobian is accomplished by:

   I' = I * |(x_{hi} - x_{lo})/(x'_{hi} - x'_{lo})|

   where I' is the corrected counts, I is the counts associated with a
   particular histogram bin, x_{hi} is the high bin boundary and x_{lo} is the
   low bin boundary from the original axis and x'_{hi} is the high bin
   boundary and x'_{lo} is the low bin boundary from the transformed axis.

   The square of the uncertainty is calculated via:
 
   sigma^2_{I'} = sigma^2_I * ((x_{hi} - x_{lo})/(x'_{hi} - x'_{lo}))^2

   where sigma^2_{I'} is the square of the uncertainty of the corrected
   counts, sigma^2_I is the square of the uncertainty in the counts
   associated with a particular histogram bin, x_{hi} is the high bin boundary
   and x_{lo} is the low bin boundary from the original axis and x'_{hi} is
   the high bin boundary and x'_{lo} is the low bin boundary from the
   transformed axis.

   Parameters:
   ----------
   -> orig_axis_lo (INPUT) is the low bin boundary of the original histogram
   axis associated with the data
   -> orig_axis_hi (INPUT) is the high bin boundary of the original histogram
   axis associated with the data
   -> transform_axis_lo (INPUT) is the low bin boundary of the transformed
   histogram axis associated with the data
   -> transform_axis_hi (INPUT) is the high bin boundary of the transformed
   histogram axis associated with the data
   -> input (INPUT) is the counts data
   -> input_err2 (INPUT) is the square of the uncertainty in the counts data

   Returns:
   -------
   <- the corrected counts
   <- the corrected square of the uncertainty in the counts
   """

   try:
       output = vpair_bind.DoubleVPair()
       utils_bind.linear_order_jacobian_ss_d(float(orig_axis_lo),
                                             float(orig_axis_hi),
                                             float(transform_axis_lo),
                                             float(transform_axis_hi),
                                             float(input),
                                             float(input_err2),
                                             output)
       return (output.val, output.val_err2)       
   except TypeError:
       import sys
       import traceback
       tb = str(traceback.extract_tb(sys.exc_info()[2])[0]).split(',')
       func_name = str(tb[2]).strip().strip('\'')
       par_name = str(tb[3])
       open_paren_index = par_name.rfind('(')
       close_paren_index = par_name.rfind(')')
       par_name = par_name[open_paren_index+1:close_paren_index]
       raise TypeError("Argument %s:%s must be a string or a number" \
                       % (func_name, par_name))

##
# \}

##
# \defgroup matrix_multiplication utils::matrix_multiplication
# \{

##
# \brief This function multiplies data by a matrix
#
# This function is described in section 3.37 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def matrix_multiplication():
    """
    ---------------------------------------------------------------------------
    This function multiplies data by a matrix

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError("This function is not implemented.")

##
# \}

##
# \defgroup peak_integration utils::peak_integration
# \{

##
# \brief This function integrates intensity around Bragg peaks
#
# This function is described in section 3.35 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def peak_integration():
    """
    ---------------------------------------------------------------------------
    This function integrates intensity around Bragg peaks

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError("This function is not implemented.")

##
# \}

##
# \defgroup vector_is_equals utils::vector_is_equals
# \{

##
# \brief This function compares to vectors for equality.
#
# This function takes two vectors and checks equality on an
# element-by-element basis. One of the vectors contains the truth values
# from a given calculation.
#
# \param value (INPUT) is a calculated vector
# \param true_value (INPUT) is a truth vector corresponding to the
# calculated vector
#
# \return A boolean that is true if the vector is equal element-by-element
#

def vector_is_equals(value, true_value):

    """
    ---------------------------------------------------------------------------
    This function takes two vectors and checks equality on an
    element-by-element basis. One of the vectors contains the truth values
    from a given calculation.

    Parameters:
    ----------
    -> value is a calculated vector
    -> true_value  is a truth vector corresponding to the calculated vector

    Return:
    ------
    <- A boolean that is True if the vector is equal element-by-element,
       if not, it returns False

    """
    if (value.__type__ == true_value.__type__ ):
        if (value.__type__ == nessi_list.NessiList.DOUBLE):
            return utils_bind.vector_is_equals_d(value.__array__,
                                                 true_value.__array__)
        elif (value.__type__ == nessi_list.NessiList.INT):
            return utils_bind.vector_is_equals_i(value.__array__,
                                                 true_value.__array__)
        else:
            raise TypeError("Unknown type %s" % value.__type__)
            

    if (value.__type__ == nessi_list.NessiList.DOUBLE):
        value_d = nessi_list.NessiList(0, type=nessi_list.NessiList.DOUBLE)
        true_value_d = nessi_list.NessiList(0,
                                            type=nessi_list.NessiList.DOUBLE)
        for i in range(len(value)):
            value_d.append(value[i])
            true_value_d.append(true_value[i])

        result = utils_bind.vector_is_equals_d(value_d.__array__,
                                               true_value_d.__array__)
    else:
        value_i = nessi_list.NessiList(0, type=nessi_list.NessiList.INT)
        true_value_i = nessi_list.NessiList(0, type=nessi_list.NessiList.INT)
        for i in range(len(value)):
            value_i.append(value[i])
            true_value_i.append(true_value[i])
        result = utils_bind.vector_is_equals_i(value_i.__array__,
                                               true_value_i.__array__)

    return result

##
# \}

##
# \defgroup weighted_average utils::weighted_average
# \{

##
# \brief This function takes the weighted average of a slice of a NessiList.
#
# This function accepts two NessiLists (data and associated square of
# uncertainties), the starting element number and the ending element number in
# order to calculate the weighted average.
#
# \f[
# \mu = \frac{\sum^{bin_{end}}_{i=bin_{start}} \frac{x_i}{\sigma_i^2}}
# {\sum^{bin_{end}}_{i=bin_{start}} \frac{1}{\sigma_i^2}}
# \f]
#
# and the square of the uncertainty is calculated according to the
# following function
#
# \f[
# \sigma_{\mu}^2 = \frac{1}{\sum^{bin_{end}}_{i=bin_{start}} \frac{1}
# {\sigma_i^2}}
# \f]
#
# \param a (INPUT) the NessiList from which to calculate the weighted average
# \param ae2 (INPUT) the square of the uncertainty in the associated
# NessiList from which calculate the weighted average
# \param start (INPUT) the bin of the NessiList from which to start the
# calculation
# \param fin (INPUT) the bin of the NessiList at which to end the
# calculation
#
# \return
# - The weighted average
# - The square of the uncertainty in the weighted average
#
# \exception IndexError is raised if a and ae2 are not the same length
# \exception TypeError is raised if a is not of type double
# \exception TypeError is raised if a and ae2 are not the same type

def weighted_average(a, ae2, start, fin):

    """
    ---------------------------------------------------------------------------
    This function takes the weighted average of a slice of a NessiList.

    Parameters:
    __________

    -> a is the NessiList from which to calculate the weighted average
    -> ae2 is the square of the uncertainty in the associated NessiList
       from which calculate the weighted average
    -> start is the bin of the NessiList from which to start the calculation
    -> fin the bin of the NessiList at which to end the calculation

    Returns 2 doubles
    ______________________

    <- the weighted average of the NessiList slice
    <- the square of the uncertainty associated with the weighted
       average

    Exceptions:
    __________

    <- IndexError is raised if a and ae2 are not the same length
    <- TypeError is raised if a is found not to be of type double
    <- TypeError is raised if a and ae2 are not the same type

    """

    if (a.__type__ != a.DOUBLE):
        raise TypeError("Function only useable for doubles")

    if (a.__type__ != ae2.__type__):
        raise TypeError("Incompatible types passed to weighted_average")

    import vpair_bind

    weighted_ave = vpair_bind.DoubleVPair()
    utils_bind.weighted_average_d(a.__array__, ae2.__array__,
                                  start, fin, weighted_ave)

    return (weighted_ave.val, weighted_ave.val_err2)

##
# \}
