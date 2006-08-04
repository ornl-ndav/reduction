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
# \file bindings/test/PAL/frequency_to_angular_frequency_test.py
#

import axis_manip
import nessi_list
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup frequency_to_angular_frequency_test frequency_to_angular_frequency_test
# \{
#
# This test compares the output data (\f$output\_vv\f$, and \f$output\_ss\f$)
# calculated by the binding module <i>frequency_to_angular_frequency.py</i> of the
# Python Abstration Layer (PAL)
# <i>axis_manip.py</i> with the true output data calculated
# (\f$true\_output\_vv\f$, and \f$true\_output\_ss\f$) manually calculated.
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
# This function initializes the values of arrays, \f$frequency\f$,
# and \f$frequency\_err2\f$.
#
# \returns
# - frequency is the frequency axis in units of THz
# - frequency_err2 is the square of the uncertainty of the frequency axis
#
def initialize_inputs(key):
    if (key == "double"):
        frequency=nessi_list.NessiList(type="double")
        frequency_err2=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            frequency.append(float(i*1.0e-12))
            frequency_err2.append(float(i*1.0e-24))
    else:
        raise TypeError

    return frequency, frequency_err2

##
# Function that sets the true output based on values contained in
# \f$frequency\f$ and \f$frequency\_err2\f$.
#
# For the ss case, the scalar used is the first element of the
# NessiLists \f$frequency\f$ and \f$frequency\_err2\f$ (\f$frequency[0]\f$ and
# \f$frequency\_err2[0]\f$
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
        true_output_vv.append(float(0.00000000000000000))
        true_output_vv_err2.append(float(0.00000000000000000))
        true_output_vv.append(float(6.28318530717958645))
        true_output_vv_err2.append(float(39.47841760435742841))
        true_output_vv.append(float(12.56637061435917158))
        true_output_vv_err2.append(float(78.95683520871484316))
        true_output_vv.append(float(18.84955592153875737))
        true_output_vv_err2.append(float(118.43525281307227000))
        true_output_vv.append(float(25.13274122871834618))
        true_output_vv_err2.append(float(157.91367041742968737))

      # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(0.00000000000000000)
        true_output_ss.val_err2 = float(0.00000000000000000)

    else:

        raise TypeError

    return true_output_vv,\
           true_output_vv_err2,\
           true_output_ss.val, \
           true_output_ss.val_err2

if __name__ == "__main__":

    mess =""

    print "####################################################################"
    print "# Checking frequency_to_angular_frequency Python Abstraction layer #"
    print "####################################################################"
    print

    # generate true_outputs
    true_output_vv_d, true_output_vv_err2_d,\
                      true_output_ss_d, true_output_ss_err2_d = \
                      initialize_true_outputs("double")

    # generate inputs
    frequency,frequency_err2=initialize_inputs("double")

    # vv case
    output_vv, output_vv_err2 = axis_manip.frequency_to_angular_frequency(frequency,\
                                                                          frequency_err2)

    # Check values
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess

    # ss case
    output_ss, output_ss_err2 = axis_manip.frequency_to_angular_frequency(frequency[0],\
                                                                          frequency_err2[0])

    mess = test_common.MakeCheck1("ss",\
                                  output_ss,\
                                  true_output_ss_d,\
                                  output_ss_err2,\
                                  true_output_ss_err2_d)

    print mess

##
# \}
#
