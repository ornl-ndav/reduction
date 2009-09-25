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
# \file bindings/test/PAL/calc_eq_jacobian_dgs_test.py
#

import nessi_list
import test_common
import utils

NUM_VAL = 5

##
# \defgroup calc_eq_jacobian_dgs_test pal::calc_eq_jacobian_dgs_test
# \{
#
# This test compares the output data ($output\_vv\f$)
# calculated by the binding module <i>calc_eq_jacobian_dgs.py</i> of the
# Python Abstration Layer (PAL) <i>utils.py</i> with the true output data
# calculated (\f$true\_output\_vv\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - VV = "v,v"
# - EMPTY = ""

##
#
# This function initializes the values of arrays, \f$e1\_axis\f$,
# \f$e2\_axis\f$, \f$e3\_axis\f$, \f$e4\_axis\f$, \f$q1\_axis\f$,
# \f$q2\_axis\f$, \f$q3\_axis\f$ and \f$q4\_axis\f$.
#
# \returns
# - e1_axis is the first energy transfer vertex coordinate array
# - e2_axis is the second energy transfer vertex coordinate array
# - e3_axis is the third energy transfer vertex coordinate array
# - e4_axis is the fourth energy transfer vertex coordinate array
# - q1_axis is the first momentum transfer vertex coordinate array
# - q2_axis is the second momentum transfer vertex coordinate array
# - q3_axis is the third momentum transfer vertex coordinate array
# - q4_axis is the fourth momentum transfer vertex coordinate array
#
def initialize_inputs(key):
    if (key == "double"):
        e1_axis = nessi_list.NessiList(type="double")
        e2_axis = nessi_list.NessiList(type="double")
        e3_axis = nessi_list.NessiList(type="double")
        e4_axis = nessi_list.NessiList(type="double")
        q1_axis = nessi_list.NessiList(type="double")
        q2_axis = nessi_list.NessiList(type="double")
        q3_axis = nessi_list.NessiList(type="double")
        q4_axis = nessi_list.NessiList(type="double")        

        for i in range(NUM_VAL):
            e1_axis.append(float(i))
            e2_axis.append(float(i+1))
            e3_axis.append(float(i+1.5))
            e4_axis.append(float(i+0.5))
            q1_axis.append(float(0))
            q2_axis.append(float(0))
            q3_axis.append(float(1))
            q4_axis.append(float(1))
    else:
        raise TypeError

    return (e1_axis, e2_axis, e3_axis, e4_axis,
            q1_axis, q2_axis, q3_axis, q4_axis)

##
# Function that sets the true output based on values contained in
# \f$e1\_axis\f$, \f$e2\_axis\f$, \f$e3\_axis\f$, \f$e4\_axis\f$, 
# \f$q1\_axis\f$, \f$q2\_axis\f$, \f$q3\_axis\f$ and \f$q4\_axis\f$
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vv case
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv = nessi_list.NessiList()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(1.0))
        true_output_vv.append(float(1.0))
        true_output_vv.append(float(1.0))
        true_output_vv.append(float(1.0))
        true_output_vv.append(float(1.0))
    else:

        raise TypeError

    return true_output_vv

if __name__ == "__main__":

    mess =""

    print "##############################################################"
    print "#   Checking calc_eq_jacobian_dgs Python Abstraction layer   #"
    print "##############################################################"
    print

    true_output_vv_d = initialize_true_outputs("double")

    (e1_axis, e2_axis, e3_axis, e4_axis,
     q1_axis, q2_axis, q3_axis, q4_axis) = initialize_inputs("double")
    
    # vv case
    (output_vv,
     output_vv_err2) = utils.calc_eq_jacobian_dgs(e1_axis, e2_axis,
                                                  e3_axis, e4_axis,
                                                  q1_axis, q2_axis,
                                                  q3_axis, q4_axis)
    
    mess = test_common.MakeCheck2("vv", output_vv, true_output_vv_d)

    print mess
