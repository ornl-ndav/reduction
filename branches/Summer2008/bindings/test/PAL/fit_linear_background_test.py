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
# \file bindings/test/PAL/fit_linear_background_test.py
#

import utils
import nessi_list
from os import uname
from sys import platform
import test_common

NUM_VAL = 5

##
# \defgroup fit_linear_background_test fit_linear_background_test
# \{
# This test compares the output data (\f$output\f$) calculated by the
# binding module <i>fit_linear_background</i> of the Python Abstraction layer
# (PAL) <i>utils.py</i> with the true output data (\f$true\_output\f$)
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
# This function initializes the values of array \f$axis1\f$, \f$input\f$ and
# \f$input1\_err2\f$.
#
# \param key (INPUT) forces the correct initialization to occur
#
# \returns
# - axis1 is the array of independent axis values
# - input1 is the array to have the linear background fitted
# - input1_err2 is the square of the uncertainty associated with the
#   value array
#
def initialize_inputs(key):
    if (key == "double"):
        axis1 = nessi_list.NessiList()
        input1 = nessi_list.NessiList()
        input1_err2 = nessi_list.NessiList()

        axis1.append(float(1.0));
        axis1.append(float(2.0));
        axis1.append(float(3.0));
        axis1.append(float(4.0));
        axis1.append(float(5.0));
        
        input1.append(float(3.05));
        input1.append(float(4.95));
        input1.append(float(7.02));
        input1.append(float(9.01));
        input1.append(float(10.97));
        
        input1_err2.append(float(0.11));
        input1_err2.append(float(0.1));
        input1_err2.append(float(0.09));
        input1_err2.append(float(0.1));
        input1_err2.append(float(0.12));

    else:
        raise TypeError

    return axis1, input1, input1_err2

##
# Function that sets the true output based on values contained in \f$axis1\f$, 
# \f$input\f$ and \f$input1_err2\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - {"slope" : (true_output_slope, true_output_slope_err2),  "intercept" :
#   (true_output_intercept, true_output_intercept_err2)
#
def initialize_true_outputs(key):

    if (key == "double"):
        if(platform=="linux2" and uname()[4]=="i686"):
            true_output_slope = float(1.99098429157316548)
            true_output_intercept = float(1.02731718641181979)
        else:
            true_output_slope = float(1.99098429157316348)
            true_output_intercept = float(1.02731718641181557)
            
        true_output_slope_err2 = float(1.11545306817302532e-02)
        true_output_intercept_err2 = float(1.18915886404085791e-01)
    else:
        raise TypeError

    return {"slope" : (true_output_slope, true_output_slope_err2),
            "intercept" : (true_output_intercept, true_output_intercept_err2)} 

if __name__ == "__main__":

    mess = ""

    print "###########################################################"
    print "# Checking fit_linear_background Python Abstraction layer #"
    print "###########################################################"
    print

  # generate true_outputs
    true_output = initialize_true_outputs("double")

    axis1, input, input_err2 = initialize_inputs("double")

    output = utils.fit_linear_background(axis1, input, input_err2, 0, 0)

    # Check values
    mess = test_common.MakeCheck1("slope", output["slope"][0],
                                  true_output["slope"][0], output["slope"][1],
                                  true_output["slope"][1])

    print "slope    : " + mess

    # Check values
    mess = test_common.MakeCheck1("intercept", output["intercept"][0],
                                  true_output["intercept"][0], 
                                  output["intercept"][1],
                                  true_output["intercept"][1])

    print "intercept: " + mess

    

