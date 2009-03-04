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
# \file bindings/test/PAL/integrate_1D_hist_test.py
#

import utils
import nessi_list
import test_common

NUM_VAL = 5

##
# \defgroup integrate_1D_hist_test integrate_1D_hist_test
# \{
# This test compares the output data (\f$output\f$) calculated by the
# binding module <i>integrate_1D_hist</i> of the Python Abstraction layer (PAL)
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
# \f$input\_err2\f$, \f$axis\f$ and \f$axis\_bw\f$.
#
# \param key (INPUT) forces the correct initialization to occur
#
# \return
# - axis (OUTPUT) is the array of independent values for the data to integrate
# - axis_bw (OUTPUT) is the array of bin widths from the independent axis
# - input (OUTPUT) is the array of values to be integrated
# - input_err2 (OUTPUT) is the square of the uncertainty associated with the
# input array.
def initialize_inputs(key):
    if (key == "double"):
        input = nessi_list.NessiList(type="double")
        input_err2 = nessi_list.NessiList(type="double")
        axis = nessi_list.NessiList(type="double")
        axis_bw = nessi_list.NessiList(type="double")
        
        axis.append(1.0)
        axis.append(1.5)
        axis.append(2.0)
        axis.append(2.5)
        axis.append(3.0)
        axis.append(3.5)
        
        axis_bw.append(0.5)
        axis_bw.append(0.5)
        axis_bw.append(0.5)
        axis_bw.append(0.5)
        axis_bw.append(0.5)
        
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

    return (input, input_err2, axis, axis_bw)

##
# Function that sets the true output based on values contained in
# \f$input\f$, \f$input_err2\f$, \f$axis\f$, and \f$axis\_bc\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - true_output is the true value of the full integration 
# - true_output_err2 is the square of the uncertainty of the
# full integration
# - true_output_w is the true value of the full integration 
# with width removal
# - true_output_w_err2 is the square of the uncertainty of the
# full integration with width removal
# - true_output_r is the true value of the ranged integration 
# - true_output_r_err2 is the square of the uncertainty of the
# ranged integration
# - true_output_rw is the true value of the ranged integration 
# with width removal 
# - true_output_rw_err2 is the square of the uncertainty of the
# ranged integration with width removal
def initialize_true_outputs(key):

    if (key == "double"):
        true_output = float(110.)
        true_output_err2 = float(16.)
        true_output_w = float(55.)
        true_output_w_err2 = float(4.)
        true_output_r = float(50.)
        true_output_r_err2 = float(8.)
        true_output_rw = float(25.)
        true_output_rw_err2 = float(2.)
    else:
        raise TypeError("Do not recognize type %s" % str(key))

    return (true_output, true_output_err2, true_output_w, true_output_w_err2,
            true_output_r, true_output_r_err2,
            true_output_rw, true_output_rw_err2)

if __name__ == "__main__":

    mess = ""

    print "#######################################################"
    print "# Checking integrate_1D_hist Python Abstraction layer #"
    print "#######################################################"
    print

    min_int = float(1.6)
    max_int = float(2.9)

    # generate true_outputs
    (true_output, true_output_err2, true_output_w, true_output_w_err2,
     true_output_r, true_output_r_err2,
     true_output_rw, true_output_rw_err2) = initialize_true_outputs("double")

    (input, input_err2, axis, axis_bw) = initialize_inputs("double")

    # Check full integration
    (output, output_err2) = utils.integrate_1D_hist(input, input_err2, axis)
                                                    
    mess = test_common.MakeCheck1("double", output, true_output,
                                  output_err2, true_output_err2)

    print "full: " + mess

    # Check full integration with width removal
    (output_w, output_w_err2) = utils.integrate_1D_hist(input, input_err2,
                                                        axis, width=True)
                                                    
    mess = test_common.MakeCheck1("double", output_w, true_output_w,
                                  output_w_err2, true_output_w_err2)

    print "full & width: " + mess

    # Check range integration
    (output_r, output_r_err2) = utils.integrate_1D_hist(input, input_err2,
                                                        axis, min_int=min_int,
                                                        max_int=max_int)
                                                    
    mess = test_common.MakeCheck1("double", output_r, true_output_r,
                                  output_r_err2, true_output_r_err2)

    print "range: " + mess

    # Check range integration with width removal
    (output_rw, output_rw_err2) = utils.integrate_1D_hist(input, input_err2,
                                                          axis, width=True,
                                                          min_int=min_int,
                                                          max_int=max_int)
                                                    
    mess = test_common.MakeCheck1("double", output_rw, true_output_rw,
                                  output_rw_err2, true_output_rw_err2)

    print "range & width: " + mess        
