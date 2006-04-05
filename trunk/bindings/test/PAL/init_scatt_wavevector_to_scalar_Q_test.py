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
# \file bindings/test/PAL/init_scatt_wavevector_to_scalar_Q_test.py
#

import axis_manip
import nessi_list
from os import uname
from sys import platform
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup init_scatt_wavevector_to_scalar_Q_test \
# init_scatt_wavevector_to_scalar_Q_test
# \{
#
# This test compares the output data (\f$output\_vs\f$, \f$output\_sv\f$,
# \f$output\_vv\f$, and \f$output\_ss\f$) calculated by the binding module
# <i>init_scatt_wavevector_to_scalar_Q.py</i> of the Python Abstration Layer
# (PAL) <i>axis_manip.py</i> with the true output data calculated
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
# This function initializes the values of arrays, \f$k\_i\f$, \f$k\_f\f$,
# \f$k\_i\_err2\f$, and \f$k\_f\_err2\f$.
#
# \returns
# - K_i is the incident wavevector axis in units of reciprocal Angstroms
# - K_i_err2 is the square of the uncertainty of the incident wavecector axis
# - K_f is the final wavevector axis in units of reciprocal Angstroms
# - K_f_err2 is the square of the uncertainty of the final wavevector axis
#
def initialize_inputs(key):
    if (key == "double"):
        k_i=nessi_list.NessiList(type="double")
        k_i_err2=nessi_list.NessiList(type="double")
        k_f=nessi_list.NessiList(type="double")
        k_f_err2=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            k_i.append(float(i+1))
            k_f.append(float(i+1.25))
            k_i_err2.append(float(i+0.5))
            k_f_err2.append(float(i+0.25))
    else:
        raise TypeError

    return k_i, k_i_err2, k_f, k_f_err2

##
# Function that sets the true output based on values contained in
# \f$k\_i\f$, \f$k\_i\_err2\f$, \f$k\_f\f$, and \f$k\_f\_err2\f$.
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
        true_output_vv.append(float(0.35036606096122696))
        if(platform=="linux2" and uname()[4]=="x86_64"):
            true_output_vv_err2.append(float(0.41659964378851260))
        else:
            true_output_vv_err2.append(float(0.41659964378851194))
        true_output_vv.append(float(0.52860472569260141))

        if(platform=="linux2" and uname()[4]=="x86_64"):
            true_output_vv_err2.append(float(0.98320158587953999))
            true_output_vv.append(float(0.72972579648330460))
        else:
            true_output_vv_err2.append(float(0.98320158587954031))
            true_output_vv.append(float(0.72972579648330349))
        if(platform=="linux2" and uname()[4]=="x86_64"):
            true_output_vv_err2.append(float(1.51250520438526981))
            true_output_vv.append(float(0.93914148175842727))
        else:
            true_output_vv_err2.append(float(1.51250520438527535))
            true_output_vv.append(float(0.93914148175842626))
        if(platform=="linux2" and uname()[4]=="x86_64"):
            true_output_vv_err2.append(float(2.24514211944372999))
        else:
            true_output_vv_err2.append(float(2.24514211944373531))
        true_output_vv.append(float(1.15233845294826764))
        if(platform=="linux2" and uname()[4]=="x86_64"):
            true_output_vv_err2.append(float(3.20946303556517476))
        else:
            true_output_vv_err2.append(float(3.20946303556517609))

      # initialize the correct outputs for vector scalar case
        true_output_vs.append(float(0.35036606096122696))
        if(platform=="linux2" and uname()[4]=="x86_64"):
            true_output_vs_err2.append(float(0.41659964378851260))
        else:
            true_output_vs_err2.append(float(0.41659964378851194))
        true_output_vs.append(float(0.82644585627067690))
        true_output_vs_err2.append(float(1.56478867463881377))
        true_output_vs.append(float(1.80090786272381464))
        true_output_vs_err2.append(float(2.68231593112614863))
        true_output_vs.append(float(2.79347910439543900))
        true_output_vs_err2.append(float(3.70899611257809613))
        true_output_vs.append(float(3.78995803187415658))
        true_output_vs_err2.append(float(4.72021164820286465))

      # initialize the correct outputs for vector vector case
        true_output_sv.append(float(0.35036606096122696))
        if(platform=="linux2" and uname()[4]=="x86_64"):
            true_output_sv_err2.append(float(0.41659964378851260))
        else:
            true_output_sv_err2.append(float(0.41659964378851194))
        true_output_sv.append(float(1.29265675181475581))
        true_output_sv_err2.append(float(1.65810190421910097))
        true_output_sv.append(float(2.28454953532442894))
        true_output_sv_err2.append(float(2.69188033991111108))
        true_output_sv.append(float(3.28136734924480144))
        true_output_sv_err2.append(float(3.70446789959436140))
        true_output_sv.append(float(4.27967017210773370))
        true_output_sv_err2.append(float(4.71099862050503759))

      # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(0.35036606096122696)
        true_output_ss.val_err2 = float(0.41659964378851194)

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

    print "################################################################################"
    print "#Checking init_scatt_wavevector_to_scalar_Q Python Abstraction layer for double#"
    print "################################################################################"

    # generate global inputs
    polar = float(0.22)
    polar_err2 = float(0.11)

  # generate true_outputs
    true_output_vv_d, true_output_vv_err2_d,\
  true_output_vs_d, true_output_vs_err2_d,\
  true_output_sv_d, true_output_sv_err2_d,\
  true_output_ss_d, true_output_ss_err2_d = \
            initialize_true_outputs("double")

    # vv case
    k_i,k_i_err2,k_f,k_f_err2=initialize_inputs("double")
    output_vv=nessi_list.NessiList()
    output_vv_err2=nessi_list.NessiList()
    output_vv, output_vv_err2 = \
         axis_manip.init_scatt_wavevector_to_scalar_Q(k_i,\
                              k_i_err2,\
                              k_f,\
                              k_f_err2,\
                              polar,\
                              polar_err2)
    # Check values
    mess = test_common.MakeCheck("vv",\
                 output_vv,\
                 true_output_vv_d,\
                 output_vv_err2,\
                 true_output_vv_err2_d)

    print mess

    # vs case
    k_i,k_i_err2,input2,input2_err2=initialize_inputs("double")
    output_vs=nessi_list.NessiList()
    output_vs_err2=nessi_list.NessiList()
    output_vs, output_vs_err2 = \
         axis_manip.init_scatt_wavevector_to_scalar_Q(k_i,\
                              k_i_err2,\
                              input2[0],\
                              input2_err2[0],\
                              polar,\
                              polar_err2)

    mess = test_common.MakeCheck("vs",\
                 output_vs,\
                 true_output_vs_d,\
                 output_vs_err2,\
                 true_output_vs_err2_d)

    print mess

    # sv case
    k_i,k_i_err2,k_f,k_f_err2=initialize_inputs("double")
    output_sv=nessi_list.NessiList()
    output_sv_err2=nessi_list.NessiList()
    output_sv, output_sv_err2 = \
         axis_manip.init_scatt_wavevector_to_scalar_Q(k_i[0],\
                              k_i_err2[0],\
                              k_f,\
                              k_f_err2,\
                              polar,\
                              polar_err2)

    mess = test_common.MakeCheck("sv",\
                 output_sv,\
                 true_output_sv_d,\
                 output_sv_err2,\
                 true_output_sv_err2_d)

    print mess

    # ss case
    k_i,k_i_err2,k_f,k_f_err2=initialize_inputs("double")
    output_ss, output_ss_err2 = \
         axis_manip.init_scatt_wavevector_to_scalar_Q(k_i[0],\
                              k_i_err2[0],\
                              k_f[0],\
                              k_f_err2[0],\
                              polar,\
                              polar_err2)

    mess = test_common.MakeCheck1("ss",\
                  output_ss,\
                  true_output_ss_d,\
                  output_ss_err2,\
                  true_output_ss_err2_d)

    print mess
    print
