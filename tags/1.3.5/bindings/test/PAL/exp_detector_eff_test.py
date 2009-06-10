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
# \file bindings/test/PAL/exp_detector_eff_test.py
#

import phys_corr
import nessi_list
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup exp_detector_eff_test exp_detector_eff_test
# \{
#
# This test compares the output data (\f$output\_vv\f$, and \f$output\_ss\f$)
# calculated by the binding module <i>exp_detector_eff.py</i> of the
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
# This function initializes the values of array \f$axis\_bc\f$.
#
# \returns
# - axis_bc is the wavelength axis in units of Angstroms
#
def initialize_inputs(key):
    if (key == "double"):
        axis_bc = nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            axis_bc.append(float(1 + i))
    else:
        raise TypeError

    return axis_bc

##
# Function that sets the true output based on values contained in
# \f$axis\_bc\f$.
#
# For the ss case, the scalar used is the first element of the
# NessiList \f$axis\_bc\f$ (\f$axis\_bc[0]\f$).
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

        true_output_vv = nessi_list.NessiList()
        true_output_vv_err2 = nessi_list.NessiList()
        true_output_ss = DoubleVPair()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(1.35335283236612702))
        true_output_vv_err2.append(float(1.83156388887341804e-03))
        true_output_vv.append(float(1.83156388887341787e-01))
        true_output_vv_err2.append(float(3.35462627902511894e-05))
        true_output_vv.append(float(2.47875217666635866e-02))
        true_output_vv_err2.append(float(6.14421235332821002e-07))
        true_output_vv.append(float(3.35462627902511842e-03))
        true_output_vv_err2.append(float(1.12535174719259130e-08))
        true_output_vv.append(float(4.53999297624848555e-04))
        true_output_vv_err2.append(float(2.06115362243855797e-10))

      # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(1.35335283236612702)
        true_output_ss.val_err2 = float(1.83156388887341804e-03)
    else:
        raise TypeError

    return (true_output_vv, true_output_vv_err2,
            true_output_ss.val, true_output_ss.val_err2)

if __name__ == "__main__":

    mess =""

    print "######################################################"
    print "# Checking exp_detector_eff Python Abstraction layer #"
    print "######################################################"
    print

    scale = float(10.0)
    scale_err2 = float(0.1)
    constant = float(2.0)

    # generate true_outputs
    (true_output_vv_d,
     true_output_vv_err2_d,
     true_output_ss_d,
     true_output_ss_err2_d) = initialize_true_outputs("double")

    # generate inputs
    axis_bc = initialize_inputs("double")

    # vv case
    (output_vv, output_vv_err2) = phys_corr.exp_detector_eff(axis_bc,
                                                             scale,
                                                             scale_err2,
                                                             constant)

    # Check values
    mess = test_common.MakeCheck("vv", output_vv, true_output_vv_d,
                                 output_vv_err2, true_output_vv_err2_d)

    print mess

    # ss case
    (output_ss, output_ss_err2) = phys_corr.exp_detector_eff(axis_bc[0],
                                                             scale,
                                                             scale_err2,
                                                             constant)

    mess = test_common.MakeCheck1("ss", output_ss, true_output_ss_d,
                                  output_ss_err2, true_output_ss_err2_d)

    print mess
