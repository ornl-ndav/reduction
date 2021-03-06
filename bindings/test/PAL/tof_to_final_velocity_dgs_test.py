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
# \file bindings/test/PAL/tof_to_final_velocity_dgs_test.py
#

import axis_manip
import nessi_list
from os import uname
from sys import platform
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup tof_to_final_velocity_dgs_test tof_to_final_velocity_dgs_test
# \{
#
# This test compares the output data (\f$output\_vv\f$, and \f$output\_ss\f$)
# calculated by the binding module <i>tof_to_final_velocity_dgs.py</i> of the
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
# This function initializes the values of arrays, \f$tof\f$,
# and \f$tof_err2\f$.
#
# \returns
# - tof is the time-of-fligth axis in units of micro-seconds
# - tof_err2 is the square of the uncertainty in the time-of-flight axis
#
def initialize_inputs(key):
    if (key == "double"):
        tof = nessi_list.NessiList(type="double")
        tof_err2 = nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            tof.append(float(1+i))
            tof_err2.append(float(i+0.5))
    else:
        raise TypeError

    return tof, tof_err2

##
# Function that sets the true output based on values contained in
# \f$tof\f$ and \f$tof\_err2\f$.
#
# For the ss case, the scalar used is the first element of the
# NessiLists \f$tof\f$ and \f$tof_err2\f$ (\f$tof[0]\f$ and
# \f$tof\_err2[0]\f$
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
        true_output_vv.append(float(-0.19391634980988590))
        true_output_vv.append(float(-0.31288343558282200))
        if(platform=="linux2" and uname()[4]=="x86_64"):
            true_output_vv.append(float(-0.8095238095238096))
            true_output_vv.append(float(1.3783783783783781))
            true_output_vv.append(float(0.37226277372262783))
        else:
            true_output_vv.append(float(-0.80952380952380909))
            true_output_vv.append(float(1.37837837837837962))
            true_output_vv.append(float(0.37226277372262784))

        true_output_vv_err2.append(float(0.01838717382611049))
        true_output_vv_err2.append(float(0.13129216784667819))
        if(platform=="linux2" and uname()[4]=="x86_64"):
            true_output_vv_err2.append(float(6.817174587695375))
            true_output_vv_err2.append(float(70.4852386802180320))
            true_output_vv_err2.append(float(0.4735235667252817))
        elif(platform=="linux2" and uname()[4]=="i686"):
            true_output_vv_err2.append(float(6.8171745876953563))
            true_output_vv_err2.append(float(70.4852386802183588))
            true_output_vv_err2.append(float(0.4735235667252823))
        else:
            true_output_vv_err2.append(float(6.81717458769535600))
            true_output_vv_err2.append(float(70.48523868021837302))
            true_output_vv_err2.append(float(0.47352356672528229))
            
      # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(-0.19391634980988590)
        true_output_ss.val_err2 = float(0.01838717382611049)

    else:

        raise TypeError

    return true_output_vv,\
       true_output_vv_err2,\
           true_output_ss.val, \
       true_output_ss.val_err2

if __name__ == "__main__":

    mess =""

    print "###################################################################"
    print "# Checking tof_to_final_velocity_dgs Python Abstraction layer     #"
    print "###################################################################"
    print

    initial_velocity = float(1.25)
    initial_velocity_err2 = float(0.25)
    time_offset = float(2.75)
    time_offset_err2 = float(0.75)
    dist_source_sample = float(1.1)
    dist_source_sample_err2 = float(0.1)
    dist_sample_detector = float(0.51)
    dist_sample_detector_err2 = float(0.05)

    # generate true_outputs
    true_output_vv_d, true_output_vv_err2_d,\
                      true_output_ss_d, true_output_ss_err2_d = \
                      initialize_true_outputs("double")

    # vv case
    tof,tof_err2=initialize_inputs("double")

    output_vv, output_vv_err2 = \
               axis_manip.tof_to_final_velocity_dgs(\
        tof,\
        tof_err2,\
        initial_velocity,\
        initial_velocity_err2,\
        time_offset,\
        time_offset_err2,\
        dist_source_sample,\
        dist_source_sample_err2,\
        dist_sample_detector,\
        dist_sample_detector_err2,\
        )

    # Check values
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess

    # ss case
    tof, tof_err2=initialize_inputs("double")
    output_ss, output_ss_err2 = \
               axis_manip.tof_to_final_velocity_dgs(\
        tof[0],\
        tof_err2[0],\
        initial_velocity,\
        initial_velocity_err2,\
        time_offset,\
        time_offset_err2,\
        dist_source_sample,\
        dist_source_sample_err2,\
        dist_sample_detector,\
        dist_sample_detector_err2,\
        )

    mess = test_common.MakeCheck1("ss",\
                                  output_ss,\
                                  true_output_ss_d,\
                                  output_ss_err2,\
                                  true_output_ss_err2_d)

    print mess
##
# \}
#

