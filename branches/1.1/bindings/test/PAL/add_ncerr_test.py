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
# \file bindings/test/PAL/add_ncerr_test.cpp
#

import array_manip
import nessi_list
import test_common
from vpair_bind import *

NUM_VAL = 5
SCALE = 2

##
# \defgroup add_ncerr_test add_ncerr_test
# \{
#
# This test compares the output data (\f$output\_ss\f$, \f$output\_vs\f$,
# \f$output\_vv\f$ and \f$output\_mul\_vv\f$)
# calculated by the binding module <i>add_ncerr.py</i> of the Python
# Abstration Layer (PAL) <i>array_manip.py</i> with the true output
# data calculated (\f$true\_output\_ss\f$, \f$true\_output\_vs\f$,
# \f$true\_output\_vv\f$ and \f$true\_output\_mul\_vv\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - vs : vector-scalar
# - ss : scalar-scalar
# - VV = "v,v"
# - VS = "v,s"
# - SS = "s,s"
# - ERROR = "error "
# - EMPTY = ""
#

##
#
# This function initializes the values of arrays, \f$input1\f$, \f$input2\f$,
# \f$input3\f$, \f$input1\_err2\f$, \f$input2\_err2\f$ and \f$input3\_err2\f$.
#
# \returns
# - input1 is the first NessiList to be added
# - input1_err2 is the square of the uncertainty in the first
# NessiList to be added
# - input2 is the second NessiList to be added
# - input2_err2 is the square of the uncertainty in the second
# NessiList to be added
# - input3 is the multi-dimensional NessiList to be added
# - input3_err2 is the square of the uncertainty in the multi-dimensional
# NessiList to be added
#
def initialize_inputs(key):
    if (key == "double"):
        input1=nessi_list.NessiList(type="double")
        input1_err2=nessi_list.NessiList(type="double")
        input2=nessi_list.NessiList(type="double")
        input2_err2=nessi_list.NessiList(type="double")
        input3=nessi_list.NessiList(type="double")
        input3_err2=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            input1.append(float(NUM_VAL+1-i))  #6.,5.,4.,3.,2.
            input2.append(float(i))            #0.,1.,2.,3.,4.
            input3.append(float(i))            #0.,1.,2.,3.,4.
            input1_err2.append(float(1.))      #1.,1.,1.,1.,1.
            input2_err2.append(float(1.))      #1.,1.,1.,1.,1.
            input3_err2.append(float(1.))      #1.,1.,1.,1.,1.

        for i in range(NUM_VAL, NUM_VAL*SCALE):
            input3.append(float(i))            #5.,6.,7.,8.,9.
            input3_err2.append(float(1.))      #1.,1.,1.,1.,1.
            
    else:
        input1=nessi_list.NessiList(type="int")
        input1_err2=nessi_list.NessiList(type="int")
        input2=nessi_list.NessiList(type="int")
        input2_err2=nessi_list.NessiList(type="int")
        input3=nessi_list.NessiList(type="int")
        input3_err2=nessi_list.NessiList(type="int")        
        for i in range(NUM_VAL):
            input1.append(int(NUM_VAL+1-i))    #6,5,4,3,2
            input2.append(int(i))              #0,1,2,3,4
            input3.append(int(i))              #0,1,2,3,4
            input1_err2.append(int(1))        #1,1,1,1,1
            input2_err2.append(int(1))        #1,1,1,1,1
            input3_err2.append(int(1))        #1,1,1,1,1

        for i in range(NUM_VAL, NUM_VAL*SCALE):
            input3.append(int(i))            #5,6,7,8,9
            input3_err2.append(int(1.))      #1,1,1,1,1

    return input1, input1_err2, input2, input2_err2, input3, input3_err2

##
# Function that sets the true output based on values contained in
# \f$input1\f$, \f$input1\_err2\f$, \f$input2\f$, and \f$input2\_err2\f$.
#
# For the vs case, the scalar used is the last element of the
# NessiList \f$input2\f$, \f$input2[NUM\_VAL - 1]\f$
#
# Function sets the true output based on values contained in
# \f$input3\f$, \f$input3\_err2\f$, \f$input1\f$, and \f$input1\_err2\f$ for
# mul files.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vs he
# - The square of the uncertainty in the true NessiList for the vs case
# - The true NessiList for the vv case
# - The square of the uncertainty in the true NessiList for the vv case
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv=nessi_list.NessiList()
        true_output_vv_err2=nessi_list.NessiList()
        true_output_vs=nessi_list.NessiList()
        true_output_vs_err2=nessi_list.NessiList()
        true_output_ss=DoubleVPair()

        true_output_mul_vv=nessi_list.NessiList()
        true_output_mul_vv_err2=nessi_list.NessiList()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(6.))       # 0+6
        true_output_vv_err2.append(float(2.))
        true_output_vv.append(float(6.))     # 1+5
        true_output_vv_err2.append(float(2.))
        true_output_vv.append(float(6.))     # 2+4
        true_output_vv_err2.append(float(2.))
        true_output_vv.append(float(6.))     # 3+3
        true_output_vv_err2.append(float(2.))
        true_output_vv.append(float(6.))     # 4+2
        true_output_vv_err2.append(float(2.))

      # initialize the correct outputs for vector scalar case
        true_output_vs.append(float(10.))      # 4+6
        true_output_vs_err2.append(float(2.))
        true_output_vs.append(float(9.))     # 4+5
        true_output_vs_err2.append(float(2.))
        true_output_vs.append(float(8.))     # 4+4
        true_output_vs_err2.append(float(2.))
        true_output_vs.append(float(7.))     # 4+3
        true_output_vs_err2.append(float(2.))
        true_output_vs.append(float(6.))     # 4+2
        true_output_vs_err2.append(float(2.))

        # initialize the correct outputs for scalar scalar case        
        true_output_ss.val = float(6.)
        true_output_ss.val_err2 = float(2.)

      # initialize the correct outputs for multi-dimensonal vector vector case
        true_output_mul_vv.append(float(0.))     # 0+0
        true_output_mul_vv_err2.append(float(1.))
        true_output_mul_vv.append(float(1.))     # 1+0
        true_output_mul_vv_err2.append(float(1.))
        true_output_mul_vv.append(float(2.))     # 2+0
        true_output_mul_vv_err2.append(float(1.))
        true_output_mul_vv.append(float(3.))     # 3+0
        true_output_mul_vv_err2.append(float(1.))
        true_output_mul_vv.append(float(4.))     # 4+0
        true_output_mul_vv_err2.append(float(1.))
        true_output_mul_vv.append(float(11.))     # 5+6
        true_output_mul_vv_err2.append(float(2.))
        true_output_mul_vv.append(float(11.))     # 6+5
        true_output_mul_vv_err2.append(float(2.))
        true_output_mul_vv.append(float(11.))     # 7+4
        true_output_mul_vv_err2.append(float(2.))
        true_output_mul_vv.append(float(11.))     # 8+3
        true_output_mul_vv_err2.append(float(2.))
        true_output_mul_vv.append(float(11.))     # 9+2
        true_output_mul_vv_err2.append(float(2.))

    else:

        true_output_vv=nessi_list.NessiList(type="int")
        true_output_vv_err2=nessi_list.NessiList(type="int")
        true_output_vs=nessi_list.NessiList(type="int")
        true_output_vs_err2=nessi_list.NessiList(type="int")
        true_output_ss=IntVPair()

        true_output_mul_vv=nessi_list.NessiList(type="int")
        true_output_mul_vv_err2=nessi_list.NessiList(type="int")        

      # initialize the correct outputs for vector vector case
        true_output_vv.append(int(6))      # 0+6
        true_output_vv_err2.append(int(2))
        true_output_vv.append(int(6))     # 1+5
        true_output_vv_err2.append(int(2))
        true_output_vv.append(int(6))     # 2+4
        true_output_vv_err2.append(int(2))
        true_output_vv.append(int(6))     # 3+3
        true_output_vv_err2.append(int(2))
        true_output_vv.append(int(6))     # 4+2
        true_output_vv_err2.append(int(2))

      # initialize the correct outputs for vector scalar case
        true_output_vs.append(int(10))     # 4+6
        true_output_vs_err2.append(int(2))
        true_output_vs.append(int(9))     # 4+5
        true_output_vs_err2.append(int(2))
        true_output_vs.append(int(8))     # 4+4
        true_output_vs_err2.append(int(2))
        true_output_vs.append(int(7))     # 4+3
        true_output_vs_err2.append(int(2))
        true_output_vs.append(int(6))     # 4+2
        true_output_vs_err2.append(int(2))

        # initialize the correct outputs for scalar scalar case        
        true_output_ss.val = int(6)
        true_output_ss.val_err2 = int(2)

      # initialize the correct outputs for multi-dimensonal vector vector case
        true_output_mul_vv.append(int(0))     # 0+0
        true_output_mul_vv_err2.append(int(1))
        true_output_mul_vv.append(int(1))     # 1+0
        true_output_mul_vv_err2.append(int(1))
        true_output_mul_vv.append(int(2))     # 2+0
        true_output_mul_vv_err2.append(int(1))
        true_output_mul_vv.append(int(3))     # 3+0
        true_output_mul_vv_err2.append(int(1))
        true_output_mul_vv.append(int(4))     # 4+0
        true_output_mul_vv_err2.append(int(1))
        true_output_mul_vv.append(int(11))     # 5+6
        true_output_mul_vv_err2.append(int(2))
        true_output_mul_vv.append(int(11))     # 6+5
        true_output_mul_vv_err2.append(int(2))
        true_output_mul_vv.append(int(11))     # 7+4
        true_output_mul_vv_err2.append(int(2))
        true_output_mul_vv.append(int(11))     # 8+3
        true_output_mul_vv_err2.append(int(2))
        true_output_mul_vv.append(int(11))     # 9+2
        true_output_mul_vv_err2.append(int(2))


    return true_output_vv,\
       true_output_vv_err2,\
       true_output_vs,\
       true_output_vs_err2,\
       true_output_ss.val, \
       true_output_ss.val_err2,\
       true_output_mul_vv,\
       true_output_mul_vv_err2


if __name__ == "__main__":

    mess =""

    print "###################################################"
    print "#   Checking add_ncerr Python Abstraction layer   #"
    print "###################################################"
    print
    
    true_output_vv_d, true_output_vv_err2_d, true_output_vs_d,\
                      true_output_vs_err2_d, true_output_ss_d,\
                      true_output_ss_err2_d, true_output_mul_vv_d,\
                      true_output_mul_vv_err2_d = \
                      initialize_true_outputs("double")

    true_output_vv_i, true_output_vv_err2_i, true_output_vs_i,\
                      true_output_vs_err2_i, true_output_ss_i,\
                      true_output_ss_err2_i, true_output_mul_vv_i,\
                      true_output_mul_vv_err2_i = \
                      initialize_true_outputs("int")

    # vv case
    print "Checking Vector-Vector Addition Abstraction Layer Function"

    # double case
    input1, input1_err2, input2, input2_err2,\
            input3, input3_err2 = initialize_inputs("double")

    output_vv, output_vv_err2 = array_manip.add_ncerr(input1,\
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
    input1, input1_err2, input2, input2_err2, input3, input3_err2 \
            = initialize_inputs("int")

    output_vv, output_vv_err2 = array_manip.add_ncerr(input1,\
                                                      input1_err2,\
                                                      input2,\
                                                      input2_err2)

    mess = test_common.MakeCheck("int",\
                                 output_vv,\
                                 true_output_vv_i,\
                                 output_vv_err2,\
                                 true_output_vv_err2_i)

    print mess


    # vs case
    print
    print "Checking Vector-Scalar Addition Abstraction Layer Function"

    # double case
    input1, input1_err2, input2, input2_err2, input3, input3_err2 \
            = initialize_inputs("double")

    output_vs, output_vs_err2 = array_manip.add_ncerr(input1,\
                                                      input1_err2,\
                                                      input2[4],\
                                                      input2_err2[4])

    mess = test_common.MakeCheck("double",\
                                 output_vs,\
                                 true_output_vs_d,\
                                 output_vs_err2,\
                                 true_output_vs_err2_d)

    print mess

    # int case
    input1, input1_err2, input2, input2_err2, input3, input3_err2 \
                = initialize_inputs("int")

    output_vs, output_vs_err2 = array_manip.add_ncerr(input1,\
                                                      input1_err2,\
                                                      input2[4],\
                                                      input2_err2[4])

    mess = test_common.MakeCheck("int",\
                                 output_vs,\
                                 true_output_vs_i,\
                                 output_vs_err2,\
                                 true_output_vs_err2_i)

    print mess

    # ss case
    print
    print "Checking Scalar-Scalar Addition Abstraction Layer Function"

    # double case
    input1, input1_err2, input2, input2_err2, input3, input3_err2 \
            = initialize_inputs("double")

    output_ss, output_ss_err2 = array_manip.add_ncerr(input1[4],\
                                                      input1_err2[4],\
                                                      input2[4],\
                                                      input2_err2[4])

    mess = test_common.MakeCheck1("double",\
                                  output_ss,\
                                  true_output_ss_d,\
                                  output_ss_err2,\
                                  true_output_ss_err2_d)

    print mess

    # int case
    input1, input1_err2, input2, input2_err2, input3, input3_err2 \
                = initialize_inputs("int")

    output_ss, output_ss_err2 = array_manip.add_ncerr(input1[4],\
                                                      input1_err2[4],\
                                                      input2[4],\
                                                      input2_err2[4])

    mess = test_common.MakeCheck1("int",\
                                  output_ss,\
                                  true_output_ss_i,\
                                  output_ss_err2,\
                                  true_output_ss_err2_i)

    print mess

    # multi-dimensional vv case
    print 
    print "Checking Multi-Dimensional Vector-Vector Addition Abstraction "\
          +"Layer Function"

    # double case
    input1, input1_err2, input2, input2_err2,\
            input3, input3_err2 = initialize_inputs("double")

    output_mul_vv, output_mul_vv_err2 = \
                   array_manip.add_ncerr(input3,\
                                         input3_err2,\
                                         input1,\
                                         input1_err2,
                                         a_start=5,
                                         a_span=1,
                                         b_start=0,
                                         b_span=1,
                                         b_size=len(input1))

    mess = test_common.MakeCheck("double",\
                                 output_mul_vv,\
                                 true_output_mul_vv_d,\
                                 output_mul_vv_err2,\
                                 true_output_mul_vv_err2_d)

    print mess


    # int case
    input1, input1_err2, input2, input2_err2,\
            input3, input3_err2 = initialize_inputs("int")

    output_mul_vv, output_mul_vv_err2 = \
                   array_manip.add_ncerr(input3,\
                                         input3_err2,\
                                         input1,\
                                         input1_err2,
                                         a_start=5,
                                         a_span=1,
                                         b_start=0,
                                         b_span=1,
                                         b_size=len(input1))

    mess = test_common.MakeCheck("int",\
                                 output_mul_vv,\
                                 true_output_mul_vv_i,\
                                 output_mul_vv_err2,\
                                 true_output_mul_vv_err2_i)

    print mess
