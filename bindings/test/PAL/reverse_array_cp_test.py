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
# \file bindings/test/PAL/reverse_array_cp_test.py
#

import axis_manip
import nessi_list
import test_common

NUM_VAL = 5

##
# \defgroup reverse_array_cp_test reverse_array_cp_test
# \{
#
# This test compares the output data (\f$output\f$) calculated by the
# binding module <i>reverse_array_cp.py</i> of the Python Abstration Layer
# (PAL) <i>axis_manip.py</i> with the true output data calculated
# (\f$true\_output\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - ERROR = "error "
# - EMPTY = ""

##
#
# This function initializes the values of array \f$input\f$.
#
# \returns
# - input is the NessiList to be reversed
#
def initialize_inputs(key):
    if (key == "double"):
        input=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            input.append(float(1+i))
    elif (key == "int"):
        input=nessi_list.NessiList(type="int")
        for i in range(NUM_VAL):
            input.append(int(1+i))
    else:
        raise TypeError

    return input

##
# Function that sets the true output based on values contained in
# \f$input\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true output
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output = nessi_list.NessiList()

        # initialize the correct outputs for vector vector case
        true_output.append(float(5))
        true_output.append(float(4))
        true_output.append(float(3))
        true_output.append(float(2))
        true_output.append(float(1))

    elif (key == "int"):

        true_output = nessi_list.NessiList(type="int")

        # initialize the correct outputs for vector vector case
        true_output.append(int(5))
        true_output.append(int(4))
        true_output.append(int(3))
        true_output.append(int(2))
        true_output.append(int(1))

    else:

        raise TypeError

    return true_output

if __name__ == "__main__":

    mess = ""

    print "###############################################################"
    print "#Checking reverse_array_cp Python Abstraction layer for double#"
    print "###############################################################"

    # generate true_outputs
    true_output = initialize_true_outputs("double")

    input = initialize_inputs("double")

    output = axis_manip.reverse_array_cp(input)

    # Check values
    mess = test_common.MakeCheck2("double",output, true_output)

    print mess

    print "###############################################################"
    print "#  Checking reverse_array_cp Python Abstraction layer for int #"
    print "###############################################################"

    # generate true_outputs
    true_output = initialize_true_outputs("int")

    input = initialize_inputs("int")

    output = axis_manip.reverse_array_cp(input)

    # Check values
    mess = test_common.MakeCheck2("int",output, true_output)

    print mess
