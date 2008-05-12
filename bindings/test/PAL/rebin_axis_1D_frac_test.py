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
# \file bindings/test/PAL/rebin_axis_1D_frac_test.py
#

import axis_manip
import nessi_list
import test_common

NUM_VAL = 5

##
# \defgroup rebin_axis_1D_frac_test rebin_axis_1D_frac_test
# \{
#
# This test compares the output data (\f$output\_vv\f$) calculated by the
# binding module <i>rebin_axis_1D_frac.py</i> of the Python Abstration Layer
# (PAL) <i>axis_manip.py</i> with the true output data calculated
# (\f$true\_output\_vv\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - VV = "v,v"
# - ERROR = "error "
# - EMPTY = ""

##
#
# This function initializes the values of arrays, \f$axis\_in\f$,
# \f$axis\_out\f$, \f$input\f$, and \f$input\_err2\f$.
#
# \returns
# - axis_in is the initial data axis
# - axis_out is the target axis for rebinning
# - input is the data associated with the initial axis
# - input_err2 is the square of the uncertainty associated with the data
#
def initialize_inputs(key):
    if (key == "double"):
        axis_in = nessi_list.NessiList(type="double")
        axis_out = nessi_list.NessiList(type="double")
        input = nessi_list.NessiList(type="double")
        input_err2 = nessi_list.NessiList(type="double")
        
        for i in range(NUM_VAL+1):
            axis_in.append(float(2.*i))
        for i in range(NUM_VAL):
            input.append(float(10))
            input_err2.append(float(1))

        axis_out.append(float(0.))
        axis_out.append(float(3.))
        axis_out.append(float(6.5))
        axis_out.append(float(10.))
    else:
        raise TypeError

    return axis_in, axis_out, input, input_err2

##
# Function that sets the true output based on values contained in
# \f$axis\_in\f$, \f$axis\_out\f$, \f$input\f$, and \f$input\_err2\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vv case
# - The square of the uncertainty in the true NessiList for the vv case
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv = nessi_list.NessiList()
        true_output_vv_err2 = nessi_list.NessiList()
        true_frac_area_vv = nessi_list.NessiList()

      # initialize the correct outputs for vector vector case
        true_output_vv.append(float(15))
        true_output_vv_err2.append(float(1.25))
        true_frac_area_vv.append(float(1.5))
        true_output_vv.append(float(17.5))
        true_output_vv_err2.append(float(1.3125))
        true_frac_area_vv.append(float(1.75))
        true_output_vv.append(float(17.5))
        true_output_vv_err2.append(float(1.5625))
        true_frac_area_vv.append(float(1.75))

    else:
        raise TypeError

    return true_output_vv,\
           true_output_vv_err2,\
           true_frac_area_vv

if __name__ == "__main__":

    mess =""

    print "########################################################"
    print "# Checking rebin_axis_1D_frac Python Abstraction layer #"
    print "########################################################"
    print

    # generate true_outputs
    true_output_vv_d, true_output_vv_err2_d, \
                      true_frac_area_vv_d = initialize_true_outputs("double")

    # vv case
    axis_in, axis_out, input, input_err2 = initialize_inputs("double")

    output_vv, output_vv_err2, \
               frac_area_vv = axis_manip.rebin_axis_1D_frac(axis_in,\
                                                            input,\
                                                            input_err2,\
                                                            axis_out)
    # Check values
    mess = test_common.MakeCheck("vv",\
                                 output_vv,\
                                 true_output_vv_d,\
                                 output_vv_err2,\
                                 true_output_vv_err2_d)

    print mess

    mess = test_common.MakeCheck2("frac_area",\
                                  frac_area_vv,\
                                  true_frac_area_vv_d)

    print mess

