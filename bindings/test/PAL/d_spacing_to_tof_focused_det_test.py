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
# \file bindings/test/PAL/d_spacing_to_tof_focused_det_test.py
#

import axis_manip
import nessi_list
from os import uname
from sys import platform
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup d_spacing_to_tof_focused_det_test d_spacing_to_tof_focused_det_test
# \{
#
# This test compares the output data (\f$output\_vv\f$, and \f$output\_ss\f$)
# calculated by the binding module <i>d_spacing_to_tof_focused_det.py</i> of the
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
# This function initializes the values of arrays, \f$d\_spacing\f$, and
# \f$d\_spacing\_err2\f$.
#
# \returns
# - d_spacing is the d_spacing axis in units of Angstrom
# - d_spacing_err2 is the square of the uncertainty of the d_spacing axis
#
def initialize_inputs(key):
    if (key == "double"):
        d_spacing=nessi_list.NessiList(type="double")
        d_spacing_err2=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            d_spacing.append(float(1+i))
            d_spacing_err2.append(float(i+0.5))
    else:
        raise TypeError

    return d_spacing, d_spacing_err2

##
# Function that sets the true output based on values contained in
# \f$d\_spacing\f$ and \f$d\_spacing\_err2\f$.
#
# For the ss case, the scalar used is the first element of the
# NessiLists \f$d\_spacing\f$ and \f$d\_spacing\_err2\f$ (\f$d\_spacing[0]\f$ and
# \f$d\_spacing\_err2[0]\f$
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
        if(platform=="linux2" and uname()[4]=="x86_64"):
             true_output_vv.append(float(1264.17918742388204636))
             true_output_vv_err2.append(float(999410.25272388576716936))
        else:
             true_output_vv.append(float(1264.17918742388204636))
             true_output_vv_err2.append(float(999410.2527238857001066))

        true_output_vv.append(float(2528.35837484776409272))
        true_output_vv_err2.append(float(3198566.5019376895343388))

        if(platform=="linux2" and uname()[4]=="x86_64"):
             true_output_vv.append(float(3792.53756227164590728))
             true_output_vv_err2.append(float(5798394.23868355906867743))
        else:
             true_output_vv.append(float(3792.53756227164590728))
             true_output_vv_err2.append(float(5798394.2386835580691695))
            
        true_output_vv.append(float(5056.71674969552818102))
        true_output_vv_err2.append(float(8798893.46296149186264514))
        true_output_vv.append(float(6320.8959371194108650))
        true_output_vv_err2.append(float(12200064.17477148882412910))

      # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(1264.17918742388204636)
        true_output_ss.val_err2 = float(999410.25272388576716936)

    else:

        raise TypeError

    return true_output_vv,\
           true_output_vv_err2,\
           true_output_ss.val, \
           true_output_ss.val_err2

if __name__ == "__main__":

    mess =""

    print "##################################################################"
    print "# Checking d_spacing_to_tof_focused_det Python Abstraction layer #"
    print "##################################################################"
    print
    
    pathlength_focused = float(2.75);
    pathlength_focused_err2 = float(0.75);
    polar_angle_focused = float(4.0);
    polar_angle_focused_err2 = float(0.5);
  
    # generate true_outputs
    true_output_vv_d, true_output_vv_err2_d,\
                      true_output_ss_d, true_output_ss_err2_d = \
                      initialize_true_outputs("double")

    # generate inputs
    d_spacing,d_spacing_err2=initialize_inputs("double")

    # vv case
    output_vv, output_vv_err2 = \
               axis_manip.d_spacing_to_tof_focused_det(d_spacing,
                                                       d_spacing_err2,
                                                       pathlength_focused,
                                                       pathlength_focused_err2,
                                                       polar_angle_focused,
                                                       polar_angle_focused_err2)
    # Check values
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess

    # ss case
    output_ss, output_ss_err2 = \
               axis_manip.d_spacing_to_tof_focused_det(d_spacing[0],
                                                       d_spacing_err2[0],
                                                       pathlength_focused,
                                                       pathlength_focused_err2,
                                                       polar_angle_focused,
                                                       polar_angle_focused_err2)
    mess = test_common.MakeCheck1("ss",\
                                  output_ss,\
                                  true_output_ss_d,\
                                  output_ss_err2,\
                                  true_output_ss_err2_d)

    print mess

##
# \}
#
