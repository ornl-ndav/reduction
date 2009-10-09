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
# \file bindings/test/PAL/eval_linear_fit_test.py
#

import utils
import nessi_list
from os import uname
from sys import platform
import test_common

NUM_VAL = 5

##
# \defgroup eval_linear_fit_test eval_linear_fit_test
# \{
# This test compares the output data (\f$output\f$) calculated by the
# binding module <i>eval_linear_fit</i> of the Python Abstraction layer
# (PAL) <i>utils.py</i> with the true output data (\f$true\_output\f$)
# manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate in the testsuite.log file an error message that gives details
# about the location and type of the error.
#

##
#
# This function initializes the values of array \f$axis\f$ and
# \f$axis\_err2\f$.
#
# \param key (INPUT) forces the correct initialization to occur
#
# \returns
# - axis is the array of independent axis values
# - axis_err2 is the square of the uncertainty associated with the value array
# - slope is the slope of the linear fit
# - slope_err2 is the square of the uncertainty in the slope of the linear fit
# - intercept is the intercept of the linear fit
# - intercept_err2 is the square of the uncertainty in the intercept of the
#   linear fit
#
def initialize_inputs(key):
    if (key == "double"):

        slope = float(1.99098429157316348)
        slope_err2 = float(1.11545306817302532e-02)
        intercept = float(1.02731718641181557)
        intercept_err2 = float(1.18915886404085791e-01)
        
        axis = nessi_list.NessiList()
        axis_err2 = nessi_list.NessiList()

        axis.append(float(1.0));
        axis.append(float(2.0));
        axis.append(float(3.0));
        axis.append(float(4.0));
        axis.append(float(5.0));
        
        axis_err2.append(float(0.));
        axis_err2.append(float(0.));
        axis_err2.append(float(0.));
        axis_err2.append(float(0.));
        axis_err2.append(float(0.));

    else:
        raise TypeError

    return axis, axis_err2, slope, slope_err2, intercept, intercept_err2

##
# Function that sets the true output based on values contained in \f$axis\f$ 
# and \f$axis_err2\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList 
# - The square of the uncertainty in the true NessiList
#
def initialize_true_outputs(key):

    if (key == "double"):
        true_output = nessi_list.NessiList()
        true_output_err2 = nessi_list.NessiList()

        true_output.append(float(3.01830147798497883))
        true_output.append(float(5.00928576955814275))
        if(platform=="linux2" and uname()[4]=="i686"):
            true_output.append(float(7.00027006113130579))
        else:
            true_output.append(float(7.00027006113130668))
        true_output.append(float(8.99125435270446971))
        true_output.append(float(10.9822386442776327))

        true_output_err2.append(float(1.30070417085816042e-01))
        true_output_err2.append(float(1.63534009131006797e-01))
        true_output_err2.append(float(2.19306662539658082e-01))
        true_output_err2.append(float(2.97388377311769814e-01))
        true_output_err2.append(float(3.97779153447342104e-01))
        
    else:
        raise TypeError

    return true_output, true_output_err2

if __name__ == "__main__":

    mess = ""

    print "#####################################################"
    print "# Checking eval_linear_fit Python Abstraction layer #"
    print "#####################################################"
    print

  # generate true_outputs
    true_output, true_output_err2 = initialize_true_outputs("double")

    axis, axis_err2, slope, slope_err2, \
          intercept, intercept_err2 = initialize_inputs("double")

    output, output_err2 = utils.eval_linear_fit(axis, axis_err2,
                                                slope, slope_err2,
                                                intercept, intercept_err2)

    # Check values
    mess = test_common.MakeCheck("double", output, true_output,
                                 output_err2, true_output_err2)

    print mess

    

