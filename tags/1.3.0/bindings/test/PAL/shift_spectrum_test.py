##
#                     SNS Common Libraries
#            A part of the SNS Analysis Software Suite.
#
#                   Spallation Neutron Source
#           Oak Ridge National Laboratory, Oak Ridge TN.
#
#
#                              NOTICE
#
#  For this software and its associated documentation, permission is granted
#  to reproduce, prepare derivative works, and distribute copies to the public
#  for any purpose and without fee.
#
#  This material was prepared as an account of work sponsored by an agency of
#  the United States Government.  Neither the United States Government nor the
#  United States Department of Energy, nor any of their employees, makes any
#  warranty, express or implied, or assumes any legal liability or
#  responsibility for the accuracy, completeness, or usefulness of any
#  information, apparatus, product, or process disclosed, or represents that
#  its use would not infringe privately owned rights.
#
#

##
# $Id$
#
# \file bindings/test/PAL/shift_spectrum_test.py
#

import nessi_list
import test_common
import utils

NUM_VAL = 5

##
# \defgroup shift_spectrum_test pal::shift_spectrum_test
# \{
#
# This test compares the output data ($output\_vv\f$)
# calculated by the binding module <i>shift_spectrum.py</i> of the
# Python Abstration Layer (PAL) <i>utils.py</i> with the true output data
# calculated (\f$true\_output\_vv\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - VV = "v,v"
# - ERROR = "error "
# - EMPTY = ""

##
#
# This function initializes the values of arrays \f$input\f$,
# \f$input\_err2\f$, \f$axis\f$ and \f$axis\_bc\f$.
#
# \returns
# - input is the data to be shifted
# - input_err2 is the square uncertainties associated with the data to be
# shifted
# - axis is the independent axis
# - axis_err2 is the bin centers of the independent axis
#
def initialize_inputs(key):
    if (key == "double"):
        input = nessi_list.NessiList(type="double")
        input_err2 = nessi_list.NessiList(type="double")
        axis = nessi_list.NessiList(type="double")
        axis_bc = nessi_list.NessiList(type="double")
        
        axis.append(1.0)
        axis.append(2.0)
        axis.append(3.0)
        axis.append(4.0)
        axis.append(5.0)
        axis.append(6.0)
        
        axis_bc.append(1.5)
        axis_bc.append(2.5)
        axis_bc.append(3.5)
        axis_bc.append(4.5)
        axis_bc.append(5.5)
        
        input.append(30.0)
        input.append(20.0)
        input.append(10.0)
        input.append(20.0)
        input.append(30.0)
        
        input_err2.append(4.0)
        input_err2.append(3.0)
        input_err2.append(2.0)
        input_err2.append(3.0)
        input_err2.append(4.0)

    else:
        raise TypeError("Do not recognize type %s" % str(key))

    return input, input_err2, axis, axis_bc

##
# Function that sets the true output based on values contained in
# \f$input\f$, \f$input_err2\f$, \f$axis\f$, and \f$axis\_bc\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vv case
# - The square of the uncertainty in the true NessiList for the vv case
#
def initialize_true_outputs(key):

    if (key == "double"):
        true_output_vv = nessi_list.NessiList()
        true_output_vv_err2 = nessi_list.NessiList()
        
        # initialize the correct outputs for vector vector case
        true_output_vv.append(float(20.0))
        true_output_vv_err2.append(float(3.0))
        true_output_vv.append(float(30.0))
        true_output_vv_err2.append(float(4.0))
        true_output_vv.append(float(30.0))
        true_output_vv_err2.append(float(4.0))
        true_output_vv.append(float(20.0))
        true_output_vv_err2.append(float(3.0))
        true_output_vv.append(float(10.0))
        true_output_vv_err2.append(float(2.0))

    else:
        raise TypeError("Do not recognize type %s" % str(key))

    return true_output_vv, true_output_vv_err2

if __name__ == "__main__":

    mess =""

    print "########################################################"
    print "#   Checking shift_spectrum Python Abstraction layer   #"
    print "########################################################"
    print

    xshift = float(3.5)
    xmin = float(1.0)
    xmax = float(6.0)

    true_output_vv_d, true_output_vv_err2_d = initialize_true_outputs("double")

    input, input_err2, axis, axis_bc = initialize_inputs("double")

    # vv case
    output_vv, output_vv_err2 = utils.shift_spectrum(input, input_err2,
                                                     axis, axis_bc,
                                                     xshift, xmin, xmax)
    
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess
