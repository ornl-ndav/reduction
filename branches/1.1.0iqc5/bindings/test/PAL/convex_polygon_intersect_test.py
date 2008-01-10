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
# \file bindings/test/PAL/convex_polygon_intersect_test.py
#

import utils
import nessi_list
import test_common

##
# \defgroup convex_polygon_intersect_test convex_polygon_intersect_test
# \{
# This test compares the output data (\f$output\f$) calculated by the
# binding module <i>convex_polygon_intersect</i> of the Python Abstraction
# layer (PAL) <i>utils.py</i> with the true output data (\f$true\_output\f$)
# manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message
#

##
#
# This function initializes the values of the coordinate arrays for the 
# different polygons
#
# \param key (INPUT) forces the correct initialization to occur
#
# \returns
# - parallelogram_x is the x coordinate array for a parallelogram 
# - parallelogram_y is the y coordinate array for a parallelogram 
# - square1_x is the x coordinate array for square1
# - square1_y is the y coordinate array for square1
# - square2_x is the x coordinate array for square2
# - square2_y is the y coordinate array for square2
# - square3_x is the x coordinate array for square3
# - square3_y is the y coordinate array for square3
# - square4_x is the x coordinate array for square4
# - square4_y is the y coordinate array for square4
# - square5_x is the x coordinate array for square5
# - square5_y is the y coordinate array for square5
# - square6_x is the x coordinate array for square6
# - square6_y is the y coordinate array for square6
# - square7_x is the x coordinate array for square7
# - square7_y is the y coordinate array for square7
# - square8_x is the x coordinate array for square8
# - square8_y is the y coordinate array for square8

def initialize_inputs(key):
    if (key == "double"):
        parallelogram_x = nessi_list.NessiList()
        parallelogram_y = nessi_list.NessiList()
        square1_x = nessi_list.NessiList()
        square1_y = nessi_list.NessiList()
        square2_x = nessi_list.NessiList()
        square2_y = nessi_list.NessiList()
        square3_x = nessi_list.NessiList()
        square3_y = nessi_list.NessiList()
        square4_x = nessi_list.NessiList()
        square4_y = nessi_list.NessiList()
        square5_x = nessi_list.NessiList()
        square5_y = nessi_list.NessiList()
        square6_x = nessi_list.NessiList()
        square6_y = nessi_list.NessiList()
        square7_x = nessi_list.NessiList()
        square7_y = nessi_list.NessiList()
        square8_x = nessi_list.NessiList()
        square8_y = nessi_list.NessiList()        

        parallelogram_x.append(float(-3))
        parallelogram_x.append(float(-2))
        parallelogram_x.append(float(0.5))
        parallelogram_x.append(float(-0.5))

        parallelogram_y.append(float(-3))        
        parallelogram_y.append(float(-1))
        parallelogram_y.append(float(-1))
        parallelogram_y.append(float(-3))
        
        square1_x.append(float(1))
        square1_x.append(float(0))
        square1_x.append(float(0))
        square1_x.append(float(1))
        
        square1_y.append(float(-2))
        square1_y.append(float(-2))
        square1_y.append(float(-1))
        square1_y.append(float(-1))
        
        square2_x.append(float(0))
        square2_x.append(float(-1))
        square2_x.append(float(-1))
        square2_x.append(float(0))
        
        square2_y.append(float(-3))
        square2_y.append(float(-3))
        square2_y.append(float(-4))
        square2_y.append(float(-4))
        
        square3_x.append(float(0.5))
        square3_x.append(float(-0.5))
        square3_x.append(float(-0.5))
        square3_x.append(float(0.5))
        
        square3_y.append(float(-1.5))
        square3_y.append(float(-1.5))
        square3_y.append(float(-0.5))
        square3_y.append(float(-0.5))
        
        square4_x.append(float(-1))
        square4_x.append(float(-2))
        square4_x.append(float(-2))
        square4_x.append(float(-1))
        
        square4_y.append(float(-2))
        square4_y.append(float(-2))
        square4_y.append(float(-1))
        square4_y.append(float(-1))
        
        square5_x.append(float(-0.5))
        square5_x.append(float(-0.5))
        square5_x.append(float(-1.5))
        square5_x.append(float(-1.5))
        
        square5_y.append(float(-1.5))
        square5_y.append(float(-2.5))
        square5_y.append(float(-2.5))
        square5_y.append(float(-1.5))
        
        square6_x.append(float(2.5))
        square6_x.append(float(1.5))
        square6_x.append(float(1.5))
        square6_x.append(float(2.5))
        
        square6_y.append(float(-1))
        square6_y.append(float(-1))
        square6_y.append(float(0))
        square6_y.append(float(0))
        
        square7_x.append(float(1))
        square7_x.append(float(-4))
        square7_x.append(float(-4))
        square7_x.append(float(1))
        
        square7_y.append(float(-4))
        square7_y.append(float(-4))
        square7_y.append(float(0))
        square7_y.append(float(0))

        square8_x.append(float(-2))
        square8_x.append(float(-3))
        square8_x.append(float(-3))
        square8_x.append(float(-3))
        
        square8_y.append(float(-1))
        square8_y.append(float(-1))
        square8_y.append(float(0))
        square8_y.append(float(0))
        
    else:
        raise TypeError

    return (parallelogram_x, parallelogram_y, square1_x, square1_y,
            square2_x, square2_y, square3_x, square3_y, square4_x, square4_y,
            square5_x, square5_y, square6_x, square6_y, square7_x, square7_y,
            square8_x, square8_y)
            
##
# Function that sets the true outputs based on values contained coordinate 
# arrays for the triangle, square and parallelogram.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - true_output1_x (OUTPUT) is the x-coordinates of the true 
# intersection polygon of the parallelogram with square1
# - true_output1_y (OUTPUT) is the y-coordinates of the true 
# intersection polygon of the parallelogram with square1
# - true_output2_x (OUTPUT) is the x-coordinates of the true 
# intersection polygon of the parallelogram with square2
# - true_output2_y (OUTPUT) is the y-coordinates of the true 
# intersection polygon of the parallelogram with square2
# - true_output3_x (OUTPUT) is the x-coordinates of the true 
# intersection polygon of the parallelogram with square3
# - true_output3_y (OUTPUT) is the y-coordinates of the true 
# intersection polygon of the parallelogram with square3
# - true_output4_x (OUTPUT) is the x-coordinates of the true 
# intersection polygon of the parallelogram with square4
# - true_output4_y (OUTPUT) is the y-coordinates of the true 
# intersection polygon of the parallelogram with square4
# - true_output5_x (OUTPUT) is the x-coordinates of the true 
# intersection polygon of the parallelogram with square5
# - true_output5_y (OUTPUT) is the y-coordinates of the true 
# intersection polygon of the parallelogram with square5
# - true_output6_x (OUTPUT) is the x-coordinates of the true 
# intersection polygon of the parallelogram with square6
# - true_output6_y (OUTPUT) is the y-coordinates of the true 
# intersection polygon of the parallelogram with square6
# - true_output7_x (OUTPUT) is the x-coordinates of the true 
# intersection polygon of the parallelogram with square7
# - true_output7_y (OUTPUT) is the y-coordinates of the true 
# intersection polygon of the parallelogram with square7
# - true_output8_x (OUTPUT) is the x-coordinates of the true 
# intersection polygon of the parallelogram with square8
# - true_output8_y (OUTPUT) is the y-coordinates of the true 
# intersection polygon of the parallelogram with square8
#
def initialize_true_outputs(key):

    if (key == "double"):
        # Parallelogram and Square1
        true_output1_x = nessi_list.NessiList()
        true_output1_y = nessi_list.NessiList()
        
        true_output1_x.append(float(0))
        true_output1_x.append(float(0.5))
        true_output1_x.append(float(0))
        
        true_output1_y.append(float(-1))
        true_output1_y.append(float(-1))
        true_output1_y.append(float(-2))
        
        # Parallelogram and Square2
        true_output2_x = nessi_list.NessiList()
        true_output2_y = nessi_list.NessiList()
        
        true_output2_x.append(float(-0.5))
        true_output2_x.append(float(-1))
        
        true_output2_y.append(float(-3))
        true_output2_y.append(float(-3))
        
        # Parallelogram and Square3
        true_output3_x = nessi_list.NessiList()
        true_output3_y = nessi_list.NessiList()
        
        true_output3_x.append(float(-0.5))
        true_output3_x.append(float(0.5))
        true_output3_x.append(float(0.25))
        true_output3_x.append(float(-0.5))
        
        true_output3_y.append(float(-1))
        true_output3_y.append(float(-1))
        true_output3_y.append(float(-1.5))
        true_output3_y.append(float(-1.5))
        
        # Parallelogram and Square4
        true_output4_x = nessi_list.NessiList()
        true_output4_y = nessi_list.NessiList()
        
        true_output4_x.append(float(-2))
        true_output4_x.append(float(-1))
        true_output4_x.append(float(-1))
        true_output4_x.append(float(-2))
        
        true_output4_y.append(float(-1))
        true_output4_y.append(float(-1))
        true_output4_y.append(float(-2))
        true_output4_y.append(float(-2))
        
        # Parallelogram and Square5
        true_output5_x = nessi_list.NessiList()
        true_output5_y = nessi_list.NessiList()
        
        true_output5_x.append(float(-0.5))
        true_output5_x.append(float(-0.5))
        true_output5_x.append(float(-1.5))
        true_output5_x.append(float(-1.5))
        
        true_output5_y.append(float(-1.5))
        true_output5_y.append(float(-2.5))
        true_output5_y.append(float(-2.5))
        true_output5_y.append(float(-1.5))
        
        # Parallelogram and Square6
        true_output6_x = nessi_list.NessiList()
        true_output6_y = nessi_list.NessiList()
        
        # Parallelogram and Square7
        true_output7_x = nessi_list.NessiList()
        true_output7_y = nessi_list.NessiList()
        
        true_output7_x.append(float(-3))
        true_output7_x.append(float(-2))
        true_output7_x.append(float(0.5))
        true_output7_x.append(float(-0.5))
        
        true_output7_y.append(float(-3))
        true_output7_y.append(float(-1))
        true_output7_y.append(float(-1))
        true_output7_y.append(float(-3))

        # Parallelogram and Square8
        true_output8_x = nessi_list.NessiList()
        true_output8_y = nessi_list.NessiList()
        
        true_output8_x.append(float(-2))
        
        true_output8_y.append(float(-1))        
        
    else:
        raise TypeError

    return (true_output1_x, true_output1_y, true_output2_x, true_output2_y,
            true_output3_x, true_output3_y, true_output4_x, true_output4_y,
            true_output5_x, true_output5_y, true_output6_x, true_output6_y,
            true_output7_x, true_output7_y, true_output8_x, true_output8_y)

if __name__ == "__main__":

    mess = ""

    print "##############################################################"
    print "# Checking convex_polygon_intersect Python Abstraction layer #"
    print "##############################################################"
    print

    # generate true_outputs
    (true_output1_x, true_output1_y, true_output2_x, true_output2_y,
     true_output3_x, true_output3_y, true_output4_x, true_output4_y,
     true_output5_x, true_output5_y, true_output6_x, true_output6_y,
     true_output7_x, true_output7_y,
     true_output8_x, true_output8_y) = initialize_true_outputs("double")

    (parallelogram_x, parallelogram_y, square1_x, square1_y,
     square2_x, square2_y, square3_x, square3_y, square4_x, square4_y,
     square5_x, square5_y, square6_x, square6_y,
     square7_x, square7_y, square8_x, square8_y) = initialize_inputs("double")

    (output1_x, output1_y) = utils.convex_polygon_intersect(parallelogram_x,
                                                            parallelogram_y,
                                                            square1_x,
                                                            square1_y)
    # Check values
    mess = test_common.MakeCheck2("double", output1_x, true_output1_x)

    print "(p&s1)x: " + mess

    mess = test_common.MakeCheck2("double", output1_y, true_output1_y)

    print "(p&s1)y: " + mess

    (output2_x, output2_y) = utils.convex_polygon_intersect(parallelogram_x,
                                                            parallelogram_y,
                                                            square2_x,
                                                            square2_y)
    # Check values
    mess = test_common.MakeCheck2("double", output2_x, true_output2_x)

    print "(p&s2)x: " + mess

    mess = test_common.MakeCheck2("double", output2_y, true_output2_y)

    print "(p&s2)y: " + mess

    (output3_x, output3_y) = utils.convex_polygon_intersect(parallelogram_x,
                                                            parallelogram_y,
                                                            square3_x,
                                                            square3_y)
    # Check values
    mess = test_common.MakeCheck2("double", output3_x, true_output3_x)

    print "(p&s3)x: " + mess

    mess = test_common.MakeCheck2("double", output3_y, true_output3_y)

    print "(p&s3)y: " + mess

    (output4_x, output4_y) = utils.convex_polygon_intersect(parallelogram_x,
                                                            parallelogram_y,
                                                            square4_x,
                                                            square4_y)
    # Check values
    mess = test_common.MakeCheck2("double", output4_x, true_output4_x)

    print "(p&s4)x: " + mess

    mess = test_common.MakeCheck2("double", output4_y, true_output4_y)

    print "(p&s4)y: " + mess

    (output5_x, output5_y) = utils.convex_polygon_intersect(parallelogram_x,
                                                            parallelogram_y,
                                                            square5_x,
                                                            square5_y)
    # Check values
    mess = test_common.MakeCheck2("double", output5_x, true_output5_x)

    print "(p&s5)x: " + mess

    mess = test_common.MakeCheck2("double", output5_y, true_output5_y)

    print "(p&s5)y: " + mess

    (output6_x, output6_y) = utils.convex_polygon_intersect(parallelogram_x,
                                                            parallelogram_y,
                                                            square6_x,
                                                            square6_y)
    # Check values
    mess = test_common.MakeSizeCheck("double", output6_x, true_output6_x)

    print "(p&s6)x: " + mess

    mess = test_common.MakeSizeCheck("double", output6_y, true_output6_y)

    print "(p&s6)y: " + mess

    (output7_x, output7_y) = utils.convex_polygon_intersect(parallelogram_x,
                                                            parallelogram_y,
                                                            square7_x,
                                                            square7_y)
    # Check values
    mess = test_common.MakeCheck2("double", output7_x, true_output7_x)

    print "(p&s7)x: " + mess

    mess = test_common.MakeCheck2("double", output7_y, true_output7_y)

    print "(p&s7)y: " + mess

    (output8_x, output8_y) = utils.convex_polygon_intersect(parallelogram_x,
                                                            parallelogram_y,
                                                            square8_x,
                                                            square8_y)
    # Check values
    mess = test_common.MakeCheck2("double", output8_x, true_output8_x)

    print "(p&s8)x: " + mess

    mess = test_common.MakeCheck2("double", output8_y, true_output8_y)

    print "(p&s8)y: " + mess    
    

