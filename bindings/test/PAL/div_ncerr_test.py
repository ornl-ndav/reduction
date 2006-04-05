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
# \file bindings/test/PAL/div_ncerr_test.cpp
#

import array_manip
import nessi_list
import test_common

NUM_VAL = 5

##
# \defgroup div_ncerr_test div_ncerr_test
# \{
#
# This test compares the output data (\f$output\_vs\f$, \f$output\_sv\f$,
# and \f$output\_vv\f$) calculated by the binding module <i>div_ncerr.py</i>
# of the Python Abstration Layer (PAL) <i>array_manip.py</i> with the true
# output data calculated (\f$true\_output\_vs\f$, \f$true\_output\_sv\f$  and
# \f$true\_output\_vv\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - vs : vector-scalar
# - sv : scalar-vector
# - VV = "v,v"
# - SV = "s,v"
# - VS = "v,s"
# - SV = "s,v"
# - ERROR = "error "
# - EMPTY = ""
#

##
#
# This function initializes the values of arrays, \f$input1\f$, \f$input2\f$,
# \f$input1\_err2\f$, and \f$input2\_err2\f$.
#
# \returns
# - input1 is the NessiList to be divided from
# - input1_err2 is the square of the uncertainty in the
# NessiList to be divided from
# - input2 is the NessiList to divide by
# -input2_err2 is the square of the uncertainty in the
# NessiList to divide by
#
def initialize_inputs(key):
    if (key == "double"):
        input1=nessi_list.NessiList(type="double")
        input1_err2=nessi_list.NessiList(type="double")
        input2=nessi_list.NessiList(type="double")
        input2_err2=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            input1.append(float(10-i))         #10.,9.,8.,7.,6.
            input2.append(float(2+i))          #2.,3.,4.,5.,6.
            input1_err2.append(float(1.))      #1.,1.,1.,1.,1.
            input2_err2.append(float(1.))      #1.,1.,1.,1.,1.
    else:
        input1=nessi_list.NessiList(type="int")
        input1_err2=nessi_list.NessiList(type="int")
        input2=nessi_list.NessiList(type="int")
        input2_err2=nessi_list.NessiList(type="int")
        for i in range(NUM_VAL):
            input1.append(int(10-i))          #10,9,8,7,6.
            input2.append(int(2+i))           #2,3,4,5,6
            input1_err2.append(int(1))        #1,1,1,1,1
            input2_err2.append(int(1))        #1,1,1,1,1

    return input1, input1_err2, input2, input2_err2

##
# Function that sets the true output based on values contained in
# \f$input1\f$, \f$input1\_err2\f$, \f$input2\f$, and \f$input2\_err2\f$.
#
# For the vs and sv cases, the scalar used is the first element of the
# NessiList \f$input2\f$, \f$input2[0]\f$
#
# For the sv and sv cases, the scalar used is the first element of the
# NessiList \f$input1\f$, \f$input1[0]\f$

# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vv case
# - The square of the uncertainty in the true NessiList for the vv case
# - The true NessiList for the vs he
# - The square of the uncertainty in the true NessiList for the vs case
# - The true NessiList for the sv he
# - The square of the uncertainty in the true NessiList for the sv case
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv=nessi_list.NessiList()
        true_output_vv_err2=nessi_list.NessiList()
        true_output_vs=nessi_list.NessiList()
        true_output_vs_err2=nessi_list.NessiList()
        true_output_sv=nessi_list.NessiList()
        true_output_sv_err2=nessi_list.NessiList()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(5.))       # 10/2
        true_output_vv_err2.append(float(6.5))
        true_output_vv.append(float(3.))     # 9/3
        true_output_vv_err2.append(float(1.11111111111111111111111111))
        true_output_vv.append(float(2.))     # 8/4
        true_output_vv_err2.append(float(0.3125))
        true_output_vv.append(float(1.4))     # 7/5
        true_output_vv_err2.append(float(0.1184))
        true_output_vv.append(float(1.))     # 6/6
        true_output_vv_err2.append(float(0.05555555555555555555555555))

      # initialize the correct outputs for vector scalar case
        true_output_vs.append(float(5.))       # 10/2
        true_output_vs_err2.append(float(6.5))
        true_output_vs.append(float(4.5))     # 9/2
        true_output_vs_err2.append(float(5.3125))
        true_output_vs.append(float(4.))     # 8/2
        true_output_vs_err2.append(float(4.25))
        true_output_vs.append(float(3.5))     # 7/2
        true_output_vs_err2.append(float(3.3125))
        true_output_vs.append(float(3.))     # 6/2
        true_output_vs_err2.append(float(2.5))

      # initialize the correct outputs for scalar vector case
        true_output_sv.append(float(5.))       # 10/2
        true_output_sv_err2.append(float(6.5))
        true_output_sv.append(float(3.3333333333333333333333333))  # 10/3
        true_output_sv_err2.append(float(1.34567901234567899))
        true_output_sv.append(float(2.5))     # 10/4
        true_output_sv_err2.append(float(0.453125))
        true_output_sv.append(float(2.))     # 10/5
        true_output_sv_err2.append(float(0.2))
        true_output_sv.append(float(1.66666666666666666666666667)) #10/6
        true_output_sv_err2.append(float(0.104938271604938266))

    else:

        true_output_vv=nessi_list.NessiList(type="int")
        true_output_vv_err2=nessi_list.NessiList(type="int")
        true_output_vs=nessi_list.NessiList(type="int")
        true_output_vs_err2=nessi_list.NessiList(type="int")
        true_output_sv=nessi_list.NessiList(type="int")
        true_output_sv_err2=nessi_list.NessiList(type="int")

      # initialize the correct outputs for vector vector case
        true_output_vv.append(int(5.))       # 10/2
        true_output_vv_err2.append(int(6.5))
        true_output_vv.append(int(3.))     # 9/3
        true_output_vv_err2.append(int(1.11111111111111111111111111))
        true_output_vv.append(int(2.))     # 8/4
        true_output_vv_err2.append(int(0.3125))
        true_output_vv.append(int(1.4))     # 7/5
        true_output_vv_err2.append(int(0.1184))
        true_output_vv.append(int(1.))     # 6/6
        true_output_vv_err2.append(int(0.05555555555555555555555555))

      # initialize the correct outputs for vector scalar case
        true_output_vs.append(int(5.))       # 10/2
        true_output_vs_err2.append(int(6.5))
        true_output_vs.append(int(4.5))     # 9/2
        true_output_vs_err2.append(int(5.3125))
        true_output_vs.append(int(4.))     # 8/2
        true_output_vs_err2.append(int(4.25))
        true_output_vs.append(int(3.5))     # 7/2
        true_output_vs_err2.append(int(3.3125))
        true_output_vs.append(int(3.))     # 6/2
        true_output_vs_err2.append(int(2.5))

      # initialize the correct outputs for scalar vector case
        true_output_sv.append(int(5.))       # 10/2
        true_output_sv_err2.append(int(6.5))
        true_output_sv.append(int(3.3333333333333333333333333))  # 10/3
        true_output_sv_err2.append(int(1.34567901234567899))
        true_output_sv.append(int(2.5))     # 10/4
        true_output_sv_err2.append(int(0.453125))
        true_output_sv.append(int(2.))     # 10/5
        true_output_sv_err2.append(int(0.2))
        true_output_sv.append(int(1.66666666666666666666666667)) #10/6
        true_output_sv_err2.append(int(0.104938271604938266))

    return true_output_vv,\
       true_output_vv_err2,\
       true_output_vs,\
       true_output_vs_err2, \
       true_output_sv,\
       true_output_sv_err2

if __name__ == "__main__":

    mess =""

    print "###################################################"
    print "#   Checking div_ncerr Python Abstraction layer   #"
    print "###################################################"
    print

    true_output_vv_d, true_output_vv_err2_d,\
  true_output_vs_d, true_output_vs_err2_d,\
  true_output_sv_d, true_output_sv_err2_d = \
            initialize_true_outputs("double")

    true_output_vv_i, true_output_vv_err2_i,\
  true_output_vs_i, true_output_vs_err2_i,\
  true_output_sv_i, true_output_sv_err2_i =\
            initialize_true_outputs("int")

    # vv case
    print "Checking Vector-Vector Division Abstraction Layer Function"

  # double case
    input1,input1_err2,input2,input2_err2=initialize_inputs("double")
    output_vv=nessi_list.NessiList()
    output_vv_err2=nessi_list.NessiList()
    output_vv, output_vv_err2 = array_manip.div_ncerr(input1,\
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
    output_vv=nessi_list.NessiList(type="int")
    output_vv_err2=nessi_list.NessiList(type="int")
    output_vv, output_vv_err2 = array_manip.div_ncerr(input1,\
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
    print "Checking Vector-Scalar Division Abstraction Layer Function"

  # double case
    input1,input1_err2,input2,input2_err2=initialize_inputs("double")
    output_vs=nessi_list.NessiList()
    output_vs_err2=nessi_list.NessiList()
    output_vs, output_vs_err2 = array_manip.div_ncerr(input1,\
                            input1_err2,\
                            input2[0],\
                            input2_err2[0])

    mess = test_common.MakeCheck("double",\
                 output_vs,\
                 true_output_vs_d,\
                 output_vs_err2,\
                 true_output_vs_err2_d)

    print mess

  # int case
    input1,input1_err2,input2,input2_err2=initialize_inputs("int")
    output_vs=nessi_list.NessiList(type="int")
    output_vs_err2=nessi_list.NessiList(type="int")
    output_vs, output_vs_err2 = array_manip.div_ncerr(input1,\
                            input1_err2,\
                            input2[0],\
                            input2_err2[0])

    mess = test_common.MakeCheck("int",\
                 output_vs,\
                 true_output_vs_i,\
                 output_vs_err2,\
                 true_output_vs_err2_i)

    print mess

    # sv case
    print
    print "Checking Scalar-Vector Division Abstraction Layer Function"

  # double case
    input1,input1_err2,input2,input2_err2=initialize_inputs("double")
    output_sv=nessi_list.NessiList()
    output_sv_err2=nessi_list.NessiList()
    output_sv, output_sv_err2 = array_manip.div_ncerr(input1[0],\
                            input1_err2[0],\
                            input2,\
                            input2_err2)

    mess = test_common.MakeCheck("double",\
                 output_sv,\
                 true_output_sv_d,\
                 output_sv_err2,\
                 true_output_sv_err2_d)

    print mess

  # int case
    input1,input1_err2,input2,input2_err2=initialize_inputs("int")
    output_sv=nessi_list.NessiList(type="int")
    output_sv_err2=nessi_list.NessiList(type="int")
    output_sv, output_sv_err2 = array_manip.div_ncerr(input1[0],\
                            input1_err2[0],\
                            input2,\
                            input2_err2)

    mess = test_common.MakeCheck("int",\
                 output_sv,\
                 true_output_sv_i,\
                 output_sv_err2,\
                 true_output_sv_err2_i)

    print mess
