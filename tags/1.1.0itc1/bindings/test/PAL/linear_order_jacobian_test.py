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
# \file bindings/test/PAL/linear_order_jacobian_test.py
#

import nessi_list
import test_common
import utils
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup linear_order_jacobian_test linear_order_jacobian_test
# \{
#
# This test compares the output data ($output\_vv\f$, and \f$output\_ss\f$)
# calculated by the binding module <i>linear_order_jacobian.py</i> of the
# Python Abstration Layer (PAL) <i>utils.py</i> with the true output data
# calculated (\f$true\_output\_vv\f$, and \f$true\_output\_ss\f$) manually
# calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - ss : scalar-scalar
# - VV = "v,v"
# - SS = "s,s"
# - ERROR = "error "
# - EMPTY = ""

##
#
# This function initializes the values of arrays, \f$input\f$,
# \f$input\_err2\f$, \f$axis\_in\f$, and \f$axis\_out\f$.
#
# \returns
# - input is the counts array
# - input_err2 is the square of the uncertainty of the counts array
# - axis_in is the original axis associated with the counts array
# - axis_out is the transformed axis associated with the counts array
#
def initialize_inputs(key):
    if (key == "double"):
        input=nessi_list.NessiList(type="double")
        input_err2=nessi_list.NessiList(type="double")
        axis_in=nessi_list.NessiList(type="double")
        axis_out=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            input.append(float((i+1)*10))
            input_err2.append(float((i+1)*2))
            axis_in.append(float(i+1))
            axis_out.append(float((i+1)*1.1))

        axis_in.append(float(NUM_VAL+1))
        axis_out.append(float(1.1*(NUM_VAL+1)))
    else:
        raise TypeError

    return input, input_err2, axis_in, axis_out

##
# Function that sets the true output based on values contained in
# \f$input\f$, \f$input\_err2\f$, \f$axis\_in\f$, and \f$axis\_out\f$.
#
# For the ss case, the scalar used is the first element of the NessiList
# \f$input\f$ (\f$input1[0]\f$)
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vv case
# - The square of the uncertainty in the true NessiList for the vv case
# - The true value for the ss case
# - The square of the uncertainty of the true value for the ss case
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv=nessi_list.NessiList()
        true_output_vv_err2=nessi_list.NessiList()
        true_output_ss=DoubleVPair()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(9.09090909090908994))
        true_output_vv_err2.append(float(1.65289256198347090))
        true_output_vv.append(float(18.1818181818181799))
        true_output_vv_err2.append(float(3.30578512396694180))
        true_output_vv.append(float(27.2727272727272728))
        true_output_vv_err2.append(float(4.95867768595041269))
        true_output_vv.append(float(36.3636363636363740))
        true_output_vv_err2.append(float(6.61157024793388892))
        true_output_vv.append(float(45.4545454545454319))
        true_output_vv_err2.append(float(8.26446280991734739))

      # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(9.09090909090908994)
        true_output_ss.val_err2 = float(1.65289256198347090)

    else:

        raise TypeError

    return true_output_vv,\
       true_output_vv_err2,\
       true_output_ss.val, \
       true_output_ss.val_err2

if __name__ == "__main__":

    mess =""

    print "###############################################################"
    print "#   Checking linear_order_jacobian Python Abstraction layer   #"
    print "###############################################################"
    print

    true_output_vv_d, true_output_vv_err2_d,\
                      true_output_ss_d, true_output_ss_err2_d = \
                      initialize_true_outputs("double")

    input,input_err2,axis_in,axis_out=initialize_inputs("double")

    # vv case
    output_vv, output_vv_err2 = utils.linear_order_jacobian(axis_in,\
                                                            axis_out,
                                                            input,\
                                                            input_err2)
    
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess

    # ss case
    output_ss, output_ss_err2 = utils.linear_order_jacobian_s(axis_in[0],
                                                              axis_in[1],
                                                              axis_out[0],
                                                              axis_out[1],
                                                              input[0],\
                                                              input_err2[0])
                                                            
    mess = test_common.MakeCheck1("ss",\
                                  output_ss,\
                                  true_output_ss_d,\
                                  output_ss_err2,\
                                  true_output_ss_err2_d)

    print mess

