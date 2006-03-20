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
# \file bindings/test/PAL/weighted_average_test.py
#

import utils
import nessi_list
import test_common

NUM_VAL = 5

##
# \defgroup weighted_average_test weighted_average_test
# \{
# This test compares the output data (\f$output\f$) calculated by the
# binding module <i>weighted_average</i> of the Python Abstraction layer (PAL)
# <i>utils.py</i> with the true output data (\f$true\_output\f$)
# manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate in the testsuite.log file an error message that gives details
# about the location and type of the error.
#
# <b>Notations used:</b>
# - ss : scalar-scalar
# - SS : "s,s"
# - ERROR = "error "
#

##
#
# This function initializes the values of array \f$input\f$ and
# \f$input1\_err2\f$.
#
# \param key (INPUT) forces the correct initialization to occur
#
# \returns
# - input1 is the array to have the weighted average calculated from
# - input1_err2 is the square of the uncertainty associated with the value array
#
def initialize_inputs(key):
    if (key == "double"):
        input1=nessi_list.NessiList()
        input1_err2=nessi_list.NessiList()
        for i in range(NUM_VAL):
            input1.append(float(i+1.))
            input1_err2.append(float(1.))
    else:
        raise TypeError

    return input1, input1_err2

##
# Function that sets the true output based on values contained in
# \f$input\f$ and \f$input1_err2\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - true_output is the true value of the weighted average
# - true_output_err2 is the square of the uncertainty of the weighted average
#
def initialize_true_outputs(key):

    if (key == "double"):
        true_output = float(3.)
        true_output_err2 = float(0.2)
    else:
        raise TypeError

    return true_output, true_output_err2

if __name__ == "__main__":

    mess = ""

    print "###############################################################"
    print "#Checking weighted_average Python Abstraction layer for double#"
    print "###############################################################"
 
	# generate true_outputs
    true_output, true_output_err2 = initialize_true_outputs("double")

    input, input_err2 = initialize_inputs("double")

    output, output_err2 = utils.weighted_average(input, input_err2, 0, NUM_VAL-1)

    # Check values
    mess = test_common.MakeCheck1("double",output, true_output, output_err2, true_output_err2)

    print mess

