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
# \file bindings/test/PAL/energy_transfer_test.py
#

import axis_manip
import nessi_list
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup energy_transfer_test energy_transfer_test
# \{
#
# This test compares the output data (\f$output\_vs\f$, \f$output\_sv\f$,
# \f$output\_vv\f$, and \f$output\_ss\f$) calculated by the binding module
# <i>energy_transfer.py</i> of the Python Abstration Layer (PAL)
# <i>axis_manip.py</i> with the true output data calculated
# (\f$true\_output\_vs\f$, \f$true\_output\_sv\f$, \f$true\_output\_vv\f$,
# and \f$true\_output\_ss\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - vs : vector-scalar
# - sv : scalar-vector
# - ss : scalar-scalar
# - VV = "v,v"
# - SV = "s,v"
# - VS = "v,s"
# - SV = "s,v"
# - SS = "s,s"
# - ERROR = "error "
# - EMPTY = ""

##
#
# This function initializes the values of arrays, \f$E\_i\f$, \f$E\_f\f$,
# \f$E\_i\_err2\f$, and \f$E\_f\_err2\f$.
#
# \returns
# - E_i is the initial energy
# - E_i_err2 is the square of the uncertainty of the initial energy
# - E_f is the final energy
# - E_f_err2 is the square of the uncertainty of the final energy
#
def initialize_inputs(key):
    if (key == "double"):
        E_i=nessi_list.NessiList(type="double")
        E_i_err2=nessi_list.NessiList(type="double")
        E_f=nessi_list.NessiList(type="double")
        E_f_err2=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            E_i.append(float(2*i))
            E_f.append(float(2.5+i))
            E_i_err2.append(float(i+0.5))
            E_f_err2.append(float(1.5+i))
    else:
        raise TypeError

    return E_i, E_i_err2, E_f, E_f_err2

##
# Function that sets the true output based on values contained in
# \f$E\_i\f$, \f$E\_i\_err2\f$, \f$E\_f\f$, and \f$E\_f\_err2\f$.
#
# For the vs, sv, and ss cases, the scalar used is the first element of the
# NessiLists \f$input1\f$ and \f$input2\f$ (\f$input1[0]\f$ and
# \f$input2[0]\f$
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vv case
# - The square of the uncertainty in the true NessiList for the vv case
# - The true NessiList for the vs case
# - The square of the uncertainty in the true NessiList for the vs case
# - The true NessiList for the sv case
# - The square of the uncertainty in the true NessiList for the sv case
# - The true value for the ss case
# - The square of the uncertainty of the true value for the ss case
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv=nessi_list.NessiList()
        true_output_vv_err2=nessi_list.NessiList()
        true_output_vs=nessi_list.NessiList()
        true_output_vs_err2=nessi_list.NessiList()
        true_output_sv=nessi_list.NessiList()
        true_output_sv_err2=nessi_list.NessiList()
        true_output_ss=DoubleVPair()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(-0.60449734953663813))
        true_output_vv_err2.append(float(0.11693345459098256))
        true_output_vv.append(float(-0.36269840972198291))
        true_output_vv_err2.append(float(0.23386690918196512))
        true_output_vv.append(float(-0.12089946990732763))
        true_output_vv_err2.append(float(0.35080036377294770))
        true_output_vv.append(float(0.12089946990732763))
        true_output_vv_err2.append(float(0.46773381836393024))
        true_output_vv.append(float(0.36269840972198291))
        true_output_vv_err2.append(float(0.58466727295491283))

      # initialize the correct outputs for vector scalar case
        true_output_vs.append(float(-0.60449734953663813))
        true_output_vs_err2.append(float(0.11693345459098256))
        true_output_vs.append(float(-0.12089946990732763))
        true_output_vs_err2.append(float(0.17540018188647385))
        true_output_vs.append(float(0.36269840972198291))
        true_output_vs_err2.append(float(0.23386690918196512))
        true_output_vs.append(float(0.84629628935129341))
        true_output_vs_err2.append(float(0.29233363647745641))
        true_output_vs.append(float(1.32989416898060408))
        true_output_vs_err2.append(float(0.35080036377294770))

      # initialize the correct outputs for vector vector case
        true_output_sv.append(float(-0.60449734953663813))
        true_output_sv_err2.append(float(0.11693345459098251))
        true_output_sv.append(float(-0.84629628935129341))
        true_output_sv_err2.append(float(0.17540018188647385))
        true_output_sv.append(float(-1.08809522916594869))
        true_output_sv_err2.append(float(0.23386690918196512))
        true_output_sv.append(float(-1.32989416898060408))
        true_output_sv_err2.append(float(0.29233363647745641))
        true_output_sv.append(float(-1.57169310879525925))
        true_output_sv_err2.append(float(0.35080036377294770))

      # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(-0.60449734953663813)
        true_output_ss.val_err2 = float(0.11693345459098256)

    else:

        raise TypeError

    return true_output_vv,\
       true_output_vv_err2,\
       true_output_vs,\
       true_output_vs_err2, \
       true_output_sv,\
       true_output_sv_err2,\
           true_output_ss.val, \
       true_output_ss.val_err2

if __name__ == "__main__":

    mess =""

    print "#########################################################"
    print "#   Checking energy_transfer Python Abstraction layer   #"
    print "#########################################################"
    print

    true_output_vv_d, true_output_vv_err2_d,\
                      true_output_vs_d, true_output_vs_err2_d,\
                      true_output_sv_d, true_output_sv_err2_d,\
                      true_output_ss_d, true_output_ss_err2_d = \
                      initialize_true_outputs("double")
    
    # vv case
    E_i,E_i_err2,E_f,E_f_err2=initialize_inputs("double")

    output_vv, output_vv_err2 = axis_manip.energy_transfer(E_i,\
                                                           E_i_err2,\
                                                           E_f,\
                                                           E_f_err2)
    
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)
    
    print mess
    
    # vs case
    E_i,E_i_err2,input2,input2_err2=initialize_inputs("double")

    output_vs, output_vs_err2 = axis_manip.energy_transfer(E_i,\
                                                           E_i_err2,\
                                                           input2[0],\
                                                           input2_err2[0])
    
    mess = test_common.MakeCheck("vs",\
                                 output_vs,\
                                 true_output_vs_d,\
                                 output_vs_err2,\
                                 true_output_vs_err2_d)
    
    print mess
    
    # sv case
    E_i,E_i_err2,E_f,E_f_err2=initialize_inputs("double")

    output_sv, output_sv_err2 = axis_manip.energy_transfer(E_i[0],\
                                                           E_i_err2[0],\
                                                           E_f,\
                                                           E_f_err2)
    
    mess = test_common.MakeCheck("sv",\
                                 output_sv,\
                                 true_output_sv_d,\
                                 output_sv_err2,\
                                 true_output_sv_err2_d)
    
    print mess
    
    # ss case
    E_i,E_i_err2,E_f,E_f_err2=initialize_inputs("double")
    output_ss, output_ss_err2 = axis_manip.energy_transfer(E_i[0],\
                                                           E_i_err2[0],\
                                                           E_f[0],\
                                                           E_f_err2[0])
    
    mess = test_common.MakeCheck1("ss",\
                                  output_ss,\
                                  true_output_ss_d,\
                                  output_ss_err2,\
                                  true_output_ss_err2_d)
    
    print mess
    
