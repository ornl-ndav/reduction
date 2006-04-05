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
# \file bindings/test/PAL/sumw_ncerr_test.cpp
#

import array_manip
import nessi_vector
import test_common

NUM_VAL = 5

##
# \defgroup sumw_ncerr_test sumw_ncerr_test
# \{
#
# This test compares the output data (\f$output\_vv\f$)
# calculated by the binding module <i>sumw_ncerr.py</i> of the Python
# Abstration Layer (PAL) <i>array_manip.py</i> with the true output
# data calculated (\f$true\_output\_vv\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - VV = "v,v"
# - ERROR = "error "
# - EMPTY = ""
#

##
# This function initializes the values of arrays, \f$input1\f$, \f$input2\f$,
# \f$input1\_err2\f$, and \f$input2\_err2\f$.
#
# \returns
# - input1 is the first NessiVector to be added
# - input1_err2 is the square of the uncertainty in the first
# NessiVector to be added
# - input2 is the second NessiVector to be added
# -input2_err2 is the square of the uncertainty in the second
# NessiVector to be added
#
def initialize_inputs(key):
    if (key == "double"):
        input1=nessi_vector.NessiVector(type="double")
        input1_err2=nessi_vector.NessiVector(type="double")
        input2=nessi_vector.NessiVector(type="double")
        input2_err2=nessi_vector.NessiVector(type="double")
        for i in range(NUM_VAL):
            input1.append(float(NUM_VAL+1-i))  #6.,5.,4.,3.,2.
            input2.append(float(i))            #0.,1.,2.,3.,4.
            input1_err2.append(float(1.))      #1.,1.,1.,1.,1.
            input2_err2.append(float(1.))      #1.,1.,1.,1.,1.
    else:
        input1=nessi_vector.NessiVector(type="int")
        input1_err2=nessi_vector.NessiVector(type="int")
        input2=nessi_vector.NessiVector(type="int")
        input2_err2=nessi_vector.NessiVector(type="int")
        for i in range(NUM_VAL):
            input1.append(int(NUM_VAL+1-i))    #6,5,4,3,2
            input2.append(int(i))              #0,1,2,3,4
            input1_err2.append(int(1))        #1,1,1,1,1
            input2_err2.append(int(1))        #1,1,1,1,1

    return input1, input1_err2, input2, input2_err2

##
# Function that sets the true output based on values contained in
# \f$input1\f$, \f$input1\_err2\f$, \f$input2\f$, and \f$input2\_err2\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiVector for the vv case
# - The square of the uncertainty in the true NessiVector for the vv case
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv=nessi_vector.NessiVector()
        true_output_vv_err2=nessi_vector.NessiVector()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(6.))       # =(0/1+6/1)*(1+1)/2
        true_output_vv_err2.append(float(4.))
        true_output_vv.append(float(6.))     # =(1/1+5/1)*(1+1)/2
        true_output_vv_err2.append(float(4.))
        true_output_vv.append(float(6.))     # =(2/1+4/1)*(1+1)/2
        true_output_vv_err2.append(float(4.))
        true_output_vv.append(float(6.))     # =(3/1+3/1)*(1+1)/2
        true_output_vv_err2.append(float(4.))
        true_output_vv.append(float(6.))     # =(4/1+2/1)*(1+1)/2
        true_output_vv_err2.append(float(4.))

    else:

        true_output_vv=nessi_vector.NessiVector(type="int")
        true_output_vv_err2=nessi_vector.NessiVector(type="int")

      # initialize the correct outputs for vector vector case
        true_output_vv.append(int(6))      # =(0/1+6/1)*(1+1)/2
        true_output_vv_err2.append(int(4))
        true_output_vv.append(int(6))     # =(1/1+5/1)*(1+1)/2
        true_output_vv_err2.append(int(4))
        true_output_vv.append(int(6))     # =(2/1+4/1)*(1+1)/2
        true_output_vv_err2.append(int(4))
        true_output_vv.append(int(6))     # =(3/1+3/1)*(1+1)/2
        true_output_vv_err2.append(int(4))
        true_output_vv.append(int(6))     # =(4/1+2/1)*(1+1)/2
        true_output_vv_err2.append(int(4))

    return true_output_vv,\
       true_output_vv_err2,\


if __name__ == "__main__":

    mess =""

    print "####################################################"
    print "#   Checking sumw_ncerr Python Abstraction layer   #"
    print "####################################################"
    print

    true_output_vv_d, true_output_vv_err2_d = \
            initialize_true_outputs("double")

    true_output_vv_i, true_output_vv_err2_i = \
            initialize_true_outputs("int")

    # vv case
    print "Checking Vector-Vector Addition Abstraction Layer Function"

  # double case
    input1,input1_err2,input2,input2_err2=initialize_inputs("double")
    output_vv=nessi_vector.NessiVector()
    output_vv_err2=nessi_vector.NessiVector()
    output_vv, output_vv_err2 = array_manip.sumw_ncerr(input1,\
                            input1_err2,\
                            input2,\
                            input2_err2)

    mess = test_common.MakeCheck("double",\
                 output_vv,\
                 true_output_vv_d,\
                 output_vv_err2,\
                 true_output_vv_err2_d)

    print mess

  # int case
    input1,input1_err2,input2,input2_err2=initialize_inputs("int")
    output_vv=nessi_vector.NessiVector(type="int")
    output_vv_err2=nessi_vector.NessiVector(type="int")
    output_vv, output_vv_err2 = array_manip.sumw_ncerr(input1,\
                            input1_err2,\
                            input2,\
                            input2_err2)

    mess = test_common.MakeCheck("int",\
                 output_vv,\
                 true_output_vv_i,\
                 output_vv_err2,\
                 true_output_vv_err2_i)

    print mess


