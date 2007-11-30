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
# \file bindings/test/PAL/energy_to_wavelength_test.py
#

import axis_manip
import nessi_list
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup energy_to_wavelength_test energy_to_wavelength_test
# \{
#
# This test compares the output data (\f$output\_vv\f$, and \f$output\_ss\f$)
# calculated by the binding module <i>energy_to_wavelength.py</i> of the
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
# This function initializes the values of arrays, \f$energy\f$,
# and f$energy_err2\f$.
#
# \returns
# - energy is the energy axis in units of meV
# - energy_err2 is the square of the uncertainty in the energy axis
#
def initialize_inputs(key):
    if (key == "double"):
        energy=nessi_list.NessiList(type="double")
        energy_err2=nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            energy.append(float(i+1))
            energy_err2.append(float(i+0.5))
    else:
        raise TypeError

    return energy, energy_err2

##
# Function that sets the true output based on values contained in
# \f$energy\f$ and \f$energy\_err2\f$ for the double case.
#
# For the ss case, the scalar used is the first element of the
# NessiLists \f$energy\f$ and \f$energy_err2\f$
# (\f$energy[0]\f$ and \f$energy\_err2[0]\f$
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
        true_output_vv.append(float(9.04456771216844935))
        true_output_vv_err2.append(float(10.2255256375000005))
        true_output_vv.append(float(6.39547516217520773))
        true_output_vv_err2.append(float(3.83457211406250043))
        true_output_vv.append(float(5.22188360332425106))
        true_output_vv_err2.append(float(1.89361585879629635))
        true_output_vv.append(float(4.52228385608422467))
        true_output_vv_err2.append(float(1.11841686660156259))
        true_output_vv.append(float(4.04485364630168043))
        true_output_vv_err2.append(float(0.736237845899999965))

      # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(9.04456771216844935)
        true_output_ss.val_err2 = float(10.2255256375000005)

    else:

        raise TypeError

    return true_output_vv,\
       true_output_vv_err2,\
           true_output_ss.val, \
       true_output_ss.val_err2

if __name__ == "__main__":

    mess =""

    print "##########################################################"
    print "# Checking energy_to_wavelength Python Abstraction layer #"
    print "##########################################################"
    print

    # generate true_outputs
    true_output_vv_d, true_output_vv_err2_d,\
                      true_output_ss_d, true_output_ss_err2_d = \
                      initialize_true_outputs("double")

    # generate inputs
    energy, energy_err2=initialize_inputs("double")

    # vv case
    output_vv, output_vv_err2 = \
               axis_manip.energy_to_wavelength(energy,\
                                               energy_err2)

    # Check values
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess

    # ss case
    output_ss, output_ss_err2 = \
               axis_manip.energy_to_wavelength(energy[0],\
                                               energy_err2[0])

    mess = test_common.MakeCheck1("ss",\
                                  output_ss,\
                                  true_output_ss_d,\
                                  output_ss_err2,\
                                  true_output_ss_err2_d)

    print mess

