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
# \exception NotImplementedError is raised since the PBL function signature is
# not available
# \exception TypeError is raised if a and ae2 are not the same type


def weighted_average(a,ae2,start,fin):

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

    Returns 2 NessiLists:
    ______________________

    <- the weighted average of the NessiList slice
    <- the square of the uncertainty associated with the weighted
       average

    Exceptions:
    __________

    <- IndexError is raised if a and ae2 are not the same length
    <- NotImplementedError is raised since the PBL function signature is
       not available
    <- TypeError is raised if a and ae2 are not the same type

    """

    if (a.__type__ != ae2.__type__):
        raise TypeError, "Incompatible types passed to weighted_average"

    if (a.__type__ == a.FLOAT):
        raise NotImplementedError, "This function is not implemented yet."

    elif (a.__type__ == a.DOUBLE):
        raise NotImplementedError, "This function is not implemented yet."

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
   
def vector_is_equals(output,true_output):

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
    
    if (output.__type__ == nessi_list.NessiList.DOUBLE):
        output_d = nessi_list.NessiList(0,type=nessi_list.NessiList.DOUBLE)
        true_output_d = nessi_list.NessiList(0,type=nessi_list.NessiList.DOUBLE)
        for i in range(len(output)):
            output_d.append(output[i])
            true_output_d.append(true_output[i])

        result = utils_bind.vector_is_equals_d(output_d.__array__, true_output_d.__array__)
    else:
        output_i = nessi_list.NessiList(0,type=nessi_list.NessiList.INT)
        true_output_i = nessi_list.NessiList(0,type=nessi_list.NessiList.INT)
        for i in range(len(output)):
            output_i.append(output[i])
            true_output_i.append(true_output[i])
        result = utils_bind.vector_is_equals_i(output_i.__array__, true_output_i.__array__)

	return result

##
# \}  // end of vector_is_equals group

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

def compare(output,true_output):

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
    
    result = utils_bind.compare(output,true_output)
    return result
   
##
# \}  // end of compare group
