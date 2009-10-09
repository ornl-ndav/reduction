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
# \file bindings/test/PAL/wavelength_to_tof_test.py
#

import axis_manip
import nessi_list
from os import uname
from sys import platform
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup wavelength_to_tof_test wavelength_to_tof_test
# \{
#
# This test compares the output data (\f$output\_vv\f$, and \f$output\_ss\f$)
# calculated by the binding module <i>wavelength_to_tof.py</i> of the
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
# This function initializes the values of arrays, \f$wavelength\f$, and
# \f$wavelength_err2\f$.
#
# \returns
# - wavelength is the wavelength axis in units of Angstroms
# - wavelength_err2 is the square of the uncertainty in the wavelength axis
#
def initialize_inputs(key):
    if (key == "double"):
        wavelength=nessi_list.NessiList(type="double")
        wavelength_err2=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            wavelength.append(float(1+i))
            wavelength_err2.append(float(i+0.5))
    else:
        raise TypeError

    return wavelength, wavelength_err2

##
# Function that sets the true output based on values contained in
# \f$wavelength\f$ and \f$wavelength\_err2\f$.
#
# For the ss case, the scalar used is the first element of the
# NessiLists \f$wavelength\f$ and \f$wavelength_err2\f$ (\f$wavelength[0]\f$
# and \f$wavelength\_err2[0]\f$
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
        true_output_vv.append(float(1.26389206968393091e+03))
        if(platform=="linux2" and uname()[4]=="i686"):
            true_output_vv_err2.append(float(9.58453898285958450e+05))
        else:
            true_output_vv_err2.append(float(9.58453898285958217e+05))
        true_output_vv.append(float(2.52778413936786183e+03))
        if(platform=="linux2" and uname()[4]=="i686"):            
            true_output_vv_err2.append(float(3.03510401123886835e+06))
        else:
            true_output_vv_err2.append(float(3.03510401123886742e+06))
        true_output_vv.append(float(3.79167620905179274e+03))
        true_output_vv_err2.append(float(5.43123875695376378e+06))
        true_output_vv.append(float(5.05556827873572365e+03))
        if(platform=="linux2" and uname()[4]=="i686"):
            true_output_vv_err2.append(float(8.14685813543064613e+06))
        else:
            true_output_vv_err2.append(float(8.14685813543064520e+06))
        true_output_vv.append(float(6.31946034841965411e+03))
        true_output_vv_err2.append(float(1.11819621466695145e+07))

      # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(1.26389206968393091e+03)
        if(platform=="linux2" and uname()[4]=="i686"):
            true_output_ss.val_err2 = float(9.58453898285958450e+05)
        else:
            true_output_ss.val_err2 = float(9.58453898285958217e+05)
        
    else:

        raise TypeError

    return true_output_vv, true_output_vv_err2, true_output_ss.val, \
           true_output_ss.val_err2

if __name__ == "__main__":

    mess =""

    print "#######################################################"
    print "# Checking wavelength_to_tof Python Abstraction layer #"
    print "#######################################################"
    print

    pathlength = float(5.)
    pathlength_err2 = float(2.5)

    # generate true_outputs
    true_output_vv_d, true_output_vv_err2_d,\
                      true_output_ss_d, true_output_ss_err2_d = \
                      initialize_true_outputs("double")

    # generate inputs
    wavelength, wavelength_err2 = initialize_inputs("double")

    # vv case
    output_vv, output_vv_err2 = axis_manip.wavelength_to_tof(wavelength,\
                                                             wavelength_err2,\
                                                             pathlength,\
                                                             pathlength_err2)



    # Check values
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess


    # ss case
    output_ss, output_ss_err2 = axis_manip.wavelength_to_tof(wavelength[0],\
                                                           wavelength_err2[0],\
                                                           pathlength,\
                                                           pathlength_err2)

    mess = test_common.MakeCheck1("ss",\
                                  output_ss,\
                                  true_output_ss_d,\
                                  output_ss_err2,\
                                  true_output_ss_err2_d)

    print mess

