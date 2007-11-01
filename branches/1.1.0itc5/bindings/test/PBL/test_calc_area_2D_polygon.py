###############################################################################
#
# Testing script for Swig bindings for calc_area_2D_polygon functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_calc_area_2D_polygon.py
#

##
# \defgroup test_calc_area_2D_polygon pbl::test_calc_area_2D_polygon
# \{
#

from nessi_vector_bind import *
from utils_bind import calc_area_2D_polygon_d
import test_common_bind
from vpair_bind import *

print "#####################################################################"
print "# Checking Calc_area_2D_polygon Swig Generated Python Binding Layer #"
print "#####################################################################"
print


# Create input vectors
Triangle_X_D = DoubleNessiVector()
Triangle_Y_D = DoubleNessiVector()
Square_X_D = DoubleNessiVector()
Square_Y_D = DoubleNessiVector()
Parallelogram_X_D = DoubleNessiVector()
Parallelogram_Y_D = DoubleNessiVector()

Triangle_X_D.append(float(1))
Triangle_X_D.append(float(-1))
Triangle_X_D.append(float(0))
Triangle_X_D.append(float(1))
Triangle_X_D.append(float(-1))

Triangle_Y_D.append(float(1))
Triangle_Y_D.append(float(1))
Triangle_Y_D.append(float(3))
Triangle_Y_D.append(float(1))
Triangle_Y_D.append(float(1))

Square_X_D.append(float(2.5))
Square_X_D.append(float(1.5))
Square_X_D.append(float(1.5))
Square_X_D.append(float(2.5))
Square_X_D.append(float(2.5))
Square_X_D.append(float(1.5))

Square_Y_D.append(float(-1))
Square_Y_D.append(float(-1))
Square_Y_D.append(float(0))
Square_Y_D.append(float(0))
Square_Y_D.append(float(-1))
Square_Y_D.append(float(-1))

Parallelogram_X_D.append(float(-2))
Parallelogram_X_D.append(float(-3))
Parallelogram_X_D.append(float(-0.5))
Parallelogram_X_D.append(float(0.5))
Parallelogram_X_D.append(float(-2))
Parallelogram_X_D.append(float(-3))

Parallelogram_Y_D.append(float(-1))
Parallelogram_Y_D.append(float(-3))
Parallelogram_Y_D.append(float(-3))
Parallelogram_Y_D.append(float(-1))
Parallelogram_Y_D.append(float(-1))
Parallelogram_Y_D.append(float(-3))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth information for calc_area_2D_polygon
# Triangle
TruthOutput_Triangle_D = DoubleVPair()
TruthOutput_Triangle_D.val=float(2)
# Square
TruthOutput_Square_D = DoubleVPair()
TruthOutput_Square_D.val=float(1)
# Parallelogram
TruthOutput_Parallelogram_D = DoubleVPair()
TruthOutput_Parallelogram_D.val=float(-5)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for calc_area_2D_polygon
Output_Triangle_D = DoubleVPair()
Output_Square_D = DoubleVPair()
Output_Parallelogram_D = DoubleVPair()

print "Checking Weighted Average Binding Function"

calc_area_2D_polygon_d(Triangle_X_D, Triangle_Y_D, 3, False, Output_Triangle_D)

mess = test_common_bind.makeCheck("calc_area_2D_polygon_d (triangle)",
                                  Output_Triangle_D.val,
                                  TruthOutput_Triangle_D.val)

print mess

calc_area_2D_polygon_d(Square_X_D, Square_Y_D, 4, True, Output_Square_D)

mess = test_common_bind.makeCheck("calc_area_2D_polygon_d (square)",
                                  Output_Square_D.val,
                                  TruthOutput_Square_D.val)

print mess

calc_area_2D_polygon_d(Parallelogram_X_D, Parallelogram_Y_D, 4, True,
                       Output_Parallelogram_D)

mess = test_common_bind.makeCheck("calc_area_2D_polygon_d (parallelogram)",
                                  Output_Parallelogram_D.val,
                                  TruthOutput_Parallelogram_D.val)

print mess

##
# \} // end of test_calc_area_2D_polygon group
#

