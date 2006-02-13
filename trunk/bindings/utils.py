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
# \file bindings/utils.py wrapper of utils library
#

import nessi_vector
import utils_bind
#import sys

##
# \namespace utils 
#
# \brief This Python abstraction layer module provides various utility
# functions
#
# This module gives the NessiVector access to the various utility functions
# provided by the <i>utils</i> library. These functions are written in
# references to SNS 107030214-TD0001-R00, "Data Reduction Library Software
# Requirements and Specifications". 
#
# Once a function is called, according to the type of the NessiVectors calling 
# it, the module redirects the call to the right function.
#
# For example, when calling the function \f$weighted_ave\f$ with two
# NessiVectors (data and error\f$^2\$) of type <i>float</i>, the module
# redirects the call to the function \f$weighted\_average\_f\f$.
#

##
# \defgroup weighted_ave utils::weighted_ave
# \{

##
# \brief This function takes the weighted average of a slice of a NessiVector.
#
# This function accepts two NessiVectors (data and associated square of
# uncertainties), the starting element number and the ending element number in
# order to calculate the weighted average.
#
# \f[
# \mu = \frac{\sum^{bin_{end}}_{i=bin_{start}} \frac{x_i}{\sigma_i^2}}
# {\sum^{bin_{end}}_{i=bin_{start}} \frac{1}{\sigma_i^2}}
# \f]
#
#  and the square of the uncertainty is calculated according to the 
# following function
#
# \f[
# \sigma_{\mu}^2 = \frac{1}{\sum^{bin_{end}}_{i=bin_{start}} \frac{1}
# {\sigma_i^2}}
# \f]
#
# \param a (INPUT) the NessiVector from which to calculate the weighted average
# \param ae2 (INPUT) the square of the uncertainty in the associated
# NessiVector from which calculate the weighted average
# \param start (INPUT) the bin of the NessiVector from which to start the 
# calculation
# \param fin (INPUT) the bin of the NessiVector at which to end the 
# calculation

def weighted_average(a,ae2,start,fin):

    """ This function takes the weighted average of a slice of a NessiVector.

        Parameters:
        a : the NessiVector from which to calculate the weighted average
        ae2 : the square of the uncertainty in the associated
        NessiVector from which calculate the weighted average
        start : the bin of the NessiVector from which to start the 
        calculation
        fin : the bin of the NessiVector at which to end the calculation

        Returns:
        c : the weighted average of the NessiVector slice
        ce2 : the square of the uncertainty associated with the weighted
        average
    """
    try:
        
        if (a.type__ == a.FLOAT):
            try:
                c = float(0)
                ce2 = float(0)
                utils_bind.weighted_average_f(a.array,ae2.array,\
                                              float(start),float(fin),\
                                              c,ce2)

            except ValueError:
                print "start and/or fin were not entered as numbers"

                
        elif (a.type__ == a.DOUBLE):
            try:
                c = float(0)
                ce2 = float(0)
                utils_bind.weighted_average_d(a.array,ae2.array,\
                                              float(start),float(fin),\
                                              c,ce2)

            except ValueError:
                print "start and/or fin were not entered as numbers"

        else:
            raise AttributeError

    except AttributeError:
        print "Vector type requested, %s, is not supported!" % a.type__
    
    return c,ce2

##
# \}
