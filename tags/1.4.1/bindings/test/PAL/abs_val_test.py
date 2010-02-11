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
# \file bindings/test/PAL/abs_val_test.cpp
#

import array_manip
import nessi_list
import test_common

NUM_VAL = 5

##
# \defgroup abs_val_test abs_val_test
# \{
#
# This test compares the output data (\f$output\f$) calculated by the binding
# module <i>abs_val.py</i> of the Python Abstration Layer (PAL)
# <i>array_manip.py</i> with the true output data calculated
#(\f$true\_output\f$) manually calculated. Any discrepancy between the outputs
#(\f$output\f$ and \f$true\_output\f$) will generate an error message that
#gives details about the location and type of the error
#

##
#
# This function initializes the values of array, \f$input\f$
#
# \returns
# - input is the NessiList to be absolute valued
#
def initialize_inputs(key):
    if (key == "double"):
        input=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            input.append(-1.0*float(i+1))  #-1.,-2.,-3.,-4.,-5.
    else:
        input=nessi_list.NessiList(type="int")
        for i in range(NUM_VAL):
            input.append(-1*int(i+1))    #-1,-2,-3,-4,-5

    return input

##
# Function that sets the true output based on values contained in
# \f$input\f$
#
# Function sets the true output based on values contained in \f$input1\f$
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList 
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output=nessi_list.NessiList()

      # initialize the correct outputs for vector vector case
        true_output.append(float(1.))     # |-1|
        true_output.append(float(2.))     # |-2|
        true_output.append(float(3.))     # |-3|
        true_output.append(float(4.))     # |-4|
        true_output.append(float(5.))     # |-5|

    else:
        true_output=nessi_list.NessiList(type="int")

      # initialize the correct outputs for vector vector case
        true_output.append(int(1))     # |-1|
        true_output.append(int(2))     # |-2|
        true_output.append(int(3))     # |-3|
        true_output.append(int(4))     # |-4|
        true_output.append(int(5))     # |-5|
    

    return true_output

if __name__ == "__main__":

    mess =""

    print "#################################################"
    print "#   Checking abs_val Python Abstraction layer   #"
    print "#################################################"
    print
    
    true_output_d = initialize_true_outputs("double")

    true_output_i = initialize_true_outputs("int")

    # vv case
    print "Checking Vector-Vector Absolute Value Abstraction Layer Function"

    # double case
    input = initialize_inputs("double")

    output = array_manip.abs_val(input)

    mess = test_common.MakeCheck("double", output, true_output_d,
                                 output, true_output_d)

    print mess

    # int case
    input = initialize_inputs("int")

    output = array_manip.abs_val(input)

    mess = test_common.MakeCheck("int", output, true_output_i,
                                 output, true_output_i)

    print mess
