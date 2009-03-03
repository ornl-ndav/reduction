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
# \file bindings/test/PAL/rebin_2D_quad_to_rectlin_test.py
#

import axis_manip
import nessi_list
import test_common

NUM_VAL = 5

##
# \defgroup rebin_2D_quad_to_rectlin_test rebin_2D_quad_to_rectlin_test
# \{
#
# This test compares the output data (\f$output\_vv\f$) calculated by the
# binding module <i>rebin_2D_quad_to_rectlin.py</i> of the Python Abstration
# Layer (PAL) <i>axis_manip.py</i> with the true output data calculated
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
# This function initializes the values of arrays, \f$axis\_in\_x1\f$,
# \f$axis\_in\_y1\f$, \f$axis\_in\_x2\f$, \f$axis\_in\_y2\f$,
# \f$axis\_in\_x3\f$, \f$axis\_in\_y3\f$, \f$axis\_in\_x4\f$,
# \f$axis\_in\_y4\f$, \f$axis\_out\_1\f$, \f$axis\_out\_2\f$, \f$input\f$,
# and \f$input\_err2\f$.
#
# \returns
# - axis_in_x1 is the x-coordinate of the 1st corner of the initial data axis
# - axis_in_y1 is the y-coordinate of the 1st corner of the initial data axis
# - axis_in_x2 is the x-coordinate of the 2nd corner of the initial data axis
# - axis_in_y2 is the y-coordinate of the 2nd corner of the initial data axis
# - axis_in_x3 is the x-coordinate of the 3rd corner of the initial data axis
# - axis_in_y3 is the y-coordinate of the 3rd corner of the initial data axis
# - axis_in_x4 is the x-coordinate of the 4th corner of the initial data axis
# - axis_in_y4 is the y-coordinate of the 4th corner of the initial data axis
# - axis_out_1 is the 1st target axis for rebinning
# - axis_out_2 is the 2nd target axis for rebinning
# - input is the data associated with the initial axis
# - input_err2 is the square of the uncertainty associated with the data
#
def initialize_inputs(key):
    if (key == "double"):
        axis_in_x1 = nessi_list.NessiList(type="double")
        axis_in_y1 = nessi_list.NessiList(type="double")
        axis_in_x2 = nessi_list.NessiList(type="double")
        axis_in_y2 = nessi_list.NessiList(type="double")
        axis_in_x3 = nessi_list.NessiList(type="double")
        axis_in_y3 = nessi_list.NessiList(type="double")
        axis_in_x4 = nessi_list.NessiList(type="double")
        axis_in_y4 = nessi_list.NessiList(type="double")        
        axis_out_1 = nessi_list.NessiList(type="double")
        axis_out_2 = nessi_list.NessiList(type="double")
        input = nessi_list.NessiList(type="double")
        input_err2 = nessi_list.NessiList(type="double")

        for counter in range(NUM_VAL):
            input.append(10.)
            input_err2.append(1.)
            axis_out_1.append(float(counter))
            axis_out_2.append(float(counter))
            
        axis_in_x1.append(0.75)
        axis_in_x1.append(1.25)
        axis_in_x1.append(1.75)
        axis_in_x1.append(2.25)
        axis_in_x1.append(2.75)
        
        axis_in_y1.append(0.75)
        axis_in_y1.append(1.25)
        axis_in_y1.append(1.75)
        axis_in_y1.append(2.25)
        axis_in_y1.append(2.75)
        
        axis_in_x2.append(0.75)
        axis_in_x2.append(1.25)
        axis_in_x2.append(1.75)
        axis_in_x2.append(2.25)
        axis_in_x2.append(2.75)
        
        axis_in_y2.append(1.25)
        axis_in_y2.append(1.75)
        axis_in_y2.append(2.25)
        axis_in_y2.append(2.75)
        axis_in_y2.append(3.25)
        
        axis_in_x3.append(1.25)
        axis_in_x3.append(1.75)
        axis_in_x3.append(2.25)
        axis_in_x3.append(2.75)
        axis_in_x3.append(3.25)
        
        axis_in_y3.append(1.75)
        axis_in_y3.append(2.25)
        axis_in_y3.append(2.75)
        axis_in_y3.append(3.25)
        axis_in_y3.append(3.75)
        
        axis_in_x4.append(1.25)
        axis_in_x4.append(1.75)
        axis_in_x4.append(2.25)
        axis_in_x4.append(2.75)
        axis_in_x4.append(3.25)
        
        axis_in_y4.append(1.25)
        axis_in_y4.append(1.75)
        axis_in_y4.append(2.25)
        axis_in_y4.append(2.75)
        axis_in_y4.append(3.25)

    else:
        raise TypeError

    return (axis_in_x1, axis_in_y1, axis_in_x2, axis_in_y2,
            axis_in_x3, axis_in_y3, axis_in_x4, axis_in_y4,
            axis_out_1, axis_out_2, input, input_err2)

##
# Function that sets the true output based on values contained in
# \f$axis\_in\_x1\f$, \f$axis\_in\_y1\f$, \f$axis\_in\_x2\f$,
# \f$axis\_in\_y2\f$, \f$axis\_in\_x3\f$, \f$axis\_in\_y3\f$,
# \f$axis\_in\_x4\f$, \f$axis\_in\_y4\f$, \f$axis\_out\_1\f$,
# \f$axis\_out\_2\f$, \f$input\f$, and \f$input\_err2\f$.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList
# - The square of the uncertainty in the true NessiList
# - The fractional area true NessiList
# - The bin contribution tracking true NessiList
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output = nessi_list.NessiList()
        true_output_err2 = nessi_list.NessiList()
        true_frac_area = nessi_list.NessiList()
        true_bin_count = nessi_list.NessiList()
        
      # initialize the correct outputs for vector vector case
        true_output.append(float(0.3125))
        true_output.append(float(0.9375))
        true_output.append(float(0.0))
        true_output.append(float(0.0))
        true_output.append(float(0.0))
        true_output.append(float(3.75))
        true_output.append(float(1.25))
        true_output.append(float(0.0))
        true_output.append(float(0.0))
        true_output.append(float(0.0))
        true_output.append(float(3.75))
        true_output.append(float(1.25))
        true_output.append(float(0.0))
        true_output.append(float(0.0))
        true_output.append(float(0.0))
        true_output.append(float(1.25))
        
        true_output_err2.append(float(0.0009765625))
        true_output_err2.append(float(0.0087890625))
        true_output_err2.append(float(0.0))
        true_output_err2.append(float(0.0))
        true_output_err2.append(float(0.0))
        true_output_err2.append(float(0.064453125))
        true_output_err2.append(float(0.009765625))
        true_output_err2.append(float(0.0))
        true_output_err2.append(float(0.0))
        true_output_err2.append(float(0.0))
        true_output_err2.append(float(0.064453125))
        true_output_err2.append(float(0.009765625))
        true_output_err2.append(float(0.0))
        true_output_err2.append(float(0.0))
        true_output_err2.append(float(0.0))
        true_output_err2.append(float(0.015625))        

        true_frac_area.append(float(0.03125))
        true_frac_area.append(float(0.09375))
        true_frac_area.append(float(0.0))
        true_frac_area.append(float(0.0))
        true_frac_area.append(float(0.0))
        true_frac_area.append(float(0.375))
        true_frac_area.append(float(0.125))
        true_frac_area.append(float(0.0))
        true_frac_area.append(float(0.0))
        true_frac_area.append(float(0.0))
        true_frac_area.append(float(0.375))
        true_frac_area.append(float(0.125))
        true_frac_area.append(float(0.0))
        true_frac_area.append(float(0.0))
        true_frac_area.append(float(0.0))
        true_frac_area.append(float(0.125))

        true_bin_count.append(float(1.0))
        true_bin_count.append(float(1.0))
        true_bin_count.append(float(0.0))
        true_bin_count.append(float(0.0))
        true_bin_count.append(float(0.0))
        true_bin_count.append(float(1.0))
        true_bin_count.append(float(1.0))
        true_bin_count.append(float(0.0))
        true_bin_count.append(float(0.0))
        true_bin_count.append(float(0.0))
        true_bin_count.append(float(1.0))
        true_bin_count.append(float(1.0))
        true_bin_count.append(float(0.0))
        true_bin_count.append(float(0.0))
        true_bin_count.append(float(0.0))
        true_bin_count.append(float(1.0))
    else:

        raise TypeError

    return (true_output, true_output_err2, true_frac_area, true_bin_count)

if __name__ == "__main__":

    mess =""

    print "##############################################################"
    print "# Checking rebin_2D_quad_to_rectlin Python Abstraction layer #"
    print "##############################################################"
    print

    # generate true_outputs
    (true_output_d, true_output_err2_d,
     true_frac_area_d, true_bin_count_d) = initialize_true_outputs("double")

    # vv case
    (axis_in_x1, axis_in_y1, axis_in_x2, axis_in_y2,
     axis_in_x3, axis_in_y3, axis_in_x4, axis_in_y4,
     axis_out_1, axis_out_2, input, input_err2) = initialize_inputs("double")

    (output, output_err2,
     frac_area, bin_count) = axis_manip.rebin_2D_quad_to_rectlin(axis_in_x1,
                                                                 axis_in_y1,
                                                                 axis_in_x2,
                                                                 axis_in_y2,
                                                                 axis_in_x3,
                                                                 axis_in_y3,
                                                                 axis_in_x4,
                                                                 axis_in_y4,
                                                                 input,
                                                                 input_err2,
                                                                 axis_out_1,
                                                                 axis_out_2)

    # Check values
    mess = test_common.MakeCheck("vv", output, true_output_d,
                                 output_err2, true_output_err2_d)

    print mess

    # Check values
    mess = test_common.MakeCheck2("vv", frac_area, true_frac_area_d)

    print "(area): " + mess

    # Check values
    mess = test_common.MakeCheck2("vv", bin_count, true_bin_count_d)

    print "(bc): " + mess    
