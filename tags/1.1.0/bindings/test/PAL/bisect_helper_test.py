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
# \file bindings/test/PAL/bisect_helper_test.py
#

import utils
import nessi_list
import test_common

NUM_VAL = 5

##
# \defgroup bisect_helper_test bisect_helper_test
# \{
# This test compares the output data (\f$output\f$) calculated by the
# binding module <i>bisect_helper</i> of the Python Abstraction layer (PAL)
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
# This function initializes the values of array \f$input\f$
#
# \param key (INPUT) forces the correct initialization to occur
#
# \returns
# - input is the array to search for values to find a bin index
# - value1 is the first value to search for
# - value2 is the second value to search for
# - value3 is the third value to search for
# - value4 is the fourth value to search for
#
def initialize_inputs(key):
    if (key == "double"):
        input = nessi_list.NessiList()
        value1 = float(-1.3)
        value2 = float(1.4)
        value3 = float(2.0)
        value4 = float(5.7)
        for i in range(NUM_VAL):
            input.append(float(i))
    else:
        raise TypeError

    return (input, value1, value2, value3, value4)

##
# Function that sets the true output based on values contained in \f$input\f$ 
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - true_output1 is the true value of the found index for test 1
# - true_output2 is the true value of the found index for test 2
# - true_output3 is the true value of the found index for test 3
# - true_output4 is the true value of the found index for test 4
#
def initialize_true_outputs(key):

    if (key == "int"):
        true_output1 = 0
        true_output2 = 1
        true_output3 = 2
        true_output4 = 3
    else:
        raise TypeError

    return (true_output1, true_output2, true_output3, true_output4)

if __name__ == "__main__":

    mess = ""
    
    print "###################################################"
    print "# Checking bisect_helper Python Abstraction layer #"
    print "###################################################"
    print
    
    # generate true_outputs
    (true_output1, true_output2, true_output3,
     true_output4) = initialize_true_outputs("int")

    (input, value1, value2, value3, value4) = initialize_inputs("double")

    output1 = utils.bisect_helper(input, value1)

    # Check values
    mess = test_common.MakeCheck1("int", output1, true_output1)

    print mess

    output2 = utils.bisect_helper(input, value2)

    # Check values
    mess = test_common.MakeCheck1("int", output2, true_output2)

    print mess

    output3 = utils.bisect_helper(input, value3)

    # Check values
    mess = test_common.MakeCheck1("int", output3, true_output3)

    print mess

    output4 = utils.bisect_helper(input, value4)

    # Check values
    mess = test_common.MakeCheck1("int", output4, true_output4)

    print mess    

