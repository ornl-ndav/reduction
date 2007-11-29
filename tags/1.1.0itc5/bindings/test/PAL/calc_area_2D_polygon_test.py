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
# \file bindings/test/PAL/calc_area_2D_polygon_test.py
#

import utils
import nessi_list
import test_common

##
# \defgroup calc_area_2D_polygon_test calc_area_2D_polygon_test
# \{
# This test compares the output data (\f$output\f$) calculated by the
# binding module <i>calc_area_2D_polygon</i> of the Python Abstraction layer
# (PAL) <i>utils.py</i> with the true output data (\f$true\_output\f$)
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
# - triangle_x is the x coordinate array for a triangle 
# - triangle_y is the y coordinate array for a triangle 
# - square_x is the x coordinate array for a square 
# - square_y is the y coordinate array for a square 
# - parallelogram_x is the x coordinate array for a parallelogram 
# - parallelogram_y is the y coordinate array for a parallelogram 
def initialize_inputs(key):
    if (key == "double"):
        triangle_x = nessi_list.NessiList()
        triangle_y = nessi_list.NessiList()
        square_x = nessi_list.NessiList()
        square_y = nessi_list.NessiList()
        parallelogram_x = nessi_list.NessiList()
        parallelogram_y = nessi_list.NessiList()

        triangle_x.append(float(1))
        triangle_x.append(float(-1))
        triangle_x.append(float(0))
        triangle_x.append(float(1))
        triangle_x.append(float(-1))
        
        triangle_y.append(float(1))
        triangle_y.append(float(1))
        triangle_y.append(float(3))
        triangle_y.append(float(1))
        triangle_y.append(float(1))
        
        square_x.append(float(2.5))
        square_x.append(float(1.5))
        square_x.append(float(1.5))
        square_x.append(float(2.5))
        square_x.append(float(2.5))
        square_x.append(float(1.5))
        
        square_y.append(float(-1))
        square_y.append(float(-1))
        square_y.append(float(0))
        square_y.append(float(0))
        square_y.append(float(-1))
        square_y.append(float(-1))
        
        parallelogram_x.append(float(-2))
        parallelogram_x.append(float(-3))
        parallelogram_x.append(float(-0.5))
        parallelogram_x.append(float(0.5))
        parallelogram_x.append(float(-2))
        parallelogram_x.append(float(-3))
        
        parallelogram_y.append(float(-1))
        parallelogram_y.append(float(-3))
        parallelogram_y.append(float(-3))
        parallelogram_y.append(float(-1))
        parallelogram_y.append(float(-1))
        parallelogram_y.append(float(-3))
    else:
        raise TypeError

    return (triangle_x, triangle_y, square_x, square_y,
            parallelogram_x, parallelogram_y)
            
##
# Function that sets the true outputs based on values contained coordinate 
# arrays for the triangle, square and parallelogram.
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - true_output_triangle (OUTPUT) is the true value of the area of the triangle
# - true_output_square (OUTPUT) is the true value of the area of the square
# - true_output_parallelogram (OUTPUT) is the true value of the area of the
# parallelogram
#
def initialize_true_outputs(key):

    if (key == "double"):
        true_output_triangle = float(2.)
        true_output_square = float(-1.)
        true_output_parallelogram = float(5.)
    else:
        raise TypeError

    return (true_output_triangle, true_output_square,
            true_output_parallelogram)

if __name__ == "__main__":

    mess = ""

    print "##########################################################"
    print "# Checking calc_area_2D_polygon Python Abstraction layer #"
    print "##########################################################"
    print

    # generate true_outputs
    (true_output_triangle, true_output_square,
     true_output_parallelogram) = initialize_true_outputs("double")

    (triangle_x, triangle_y, square_x, square_y,
     parallelogram_x, parallelogram_y) = initialize_inputs("double")

    output_triangle = utils.calc_area_2D_polygon(triangle_x, triangle_y, 3) 

    # Check values
    mess = test_common.MakeCheck1("double", output_triangle,
                                  true_output_triangle)

    print mess

    output_square = utils.calc_area_2D_polygon(square_x, square_y, 4, True) 

    # Check values
    mess = test_common.MakeCheck1("double", output_square, true_output_square)

    print mess

    output_parallelogram = utils.calc_area_2D_polygon(parallelogram_x,
                                                      parallelogram_y, 4,
                                                      True) 

    # Check values
    mess = test_common.MakeCheck1("double", output_parallelogram,
                                  true_output_parallelogram)

    print mess
