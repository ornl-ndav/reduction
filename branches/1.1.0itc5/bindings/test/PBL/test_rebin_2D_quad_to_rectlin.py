###############################################################################
#
# Testing script for Swig bindings for rebin_2D_quad_to_rectlin functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_rebin_2D_quad_to_rectlin.py
#

##
# \defgroup test_rebin_2D_quad_to_rectlin pbl::test_rebin_2D_quad_to_rectlin
# \{
#

from axis_manip_bind import rebin_2D_quad_to_rectlin_d
from nessi_vector_bind import *
import test_common_bind

print "#####################################################"
print "# Checking Rebin_2D_Quad_To_Rectlin Swig Generated  #"
print "# Python Binding Layer                              #"
print "#####################################################"
print

# Set standard size for vectors
NUM_VAL = 5
SIZE_QUAD = 4
SIZE_TWO_QUADS = 2 * SIZE_QUAD

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()
Axis_In_X1_D = DoubleNessiVector()
Axis_In_Y1_D = DoubleNessiVector()
Axis_In_X2_D = DoubleNessiVector()
Axis_In_Y2_D = DoubleNessiVector()
Axis_In_X3_D = DoubleNessiVector()
Axis_In_Y3_D = DoubleNessiVector()
Axis_In_X4_D = DoubleNessiVector()
Axis_In_Y4_D = DoubleNessiVector()
Axis_Out_1_D = DoubleNessiVector()
Axis_Out_2_D = DoubleNessiVector()

# Place values in the input vectors and input axes
for counter in range(NUM_VAL):
    Input_D.append(10.)
    Input_Err2_D.append(1.)
    Axis_Out_1_D.append(float(counter))
    Axis_Out_2_D.append(float(counter))

Axis_In_X1_D.append(0.75)
Axis_In_X1_D.append(1.25)
Axis_In_X1_D.append(1.75)
Axis_In_X1_D.append(2.25)
Axis_In_X1_D.append(2.75)

Axis_In_Y1_D.append(0.75)
Axis_In_Y1_D.append(1.25)
Axis_In_Y1_D.append(1.75)
Axis_In_Y1_D.append(2.25)
Axis_In_Y1_D.append(2.75)

Axis_In_X2_D.append(0.75)
Axis_In_X2_D.append(1.25)
Axis_In_X2_D.append(1.75)
Axis_In_X2_D.append(2.25)
Axis_In_X2_D.append(2.75)

Axis_In_Y2_D.append(1.25)
Axis_In_Y2_D.append(1.75)
Axis_In_Y2_D.append(2.25)
Axis_In_Y2_D.append(2.75)
Axis_In_Y2_D.append(3.25)

Axis_In_X3_D.append(1.25)
Axis_In_X3_D.append(1.75)
Axis_In_X3_D.append(2.25)
Axis_In_X3_D.append(2.75)
Axis_In_X3_D.append(3.25)

Axis_In_Y3_D.append(1.75)
Axis_In_Y3_D.append(2.25)
Axis_In_Y3_D.append(2.75)
Axis_In_Y3_D.append(3.25)
Axis_In_Y3_D.append(3.75)

Axis_In_X4_D.append(1.25)
Axis_In_X4_D.append(1.75)
Axis_In_X4_D.append(2.25)
Axis_In_X4_D.append(2.75)
Axis_In_X4_D.append(3.25)

Axis_In_Y4_D.append(1.25)
Axis_In_Y4_D.append(1.75)
Axis_In_Y4_D.append(2.25)
Axis_In_Y4_D.append(2.75)
Axis_In_Y4_D.append(3.25)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for rebin_2D_quad_to_rectlin version
TruthOutput_D = DoubleNessiVector()
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)
TruthOutput_D.append(0.0)

TruthOutput_Err2_D = DoubleNessiVector()
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.0)

TruthFracArea_D = DoubleNessiVector()
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)
TruthFracArea_D.append(0.0)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for rebin_2D_quad_to_rectlin
OrigBin_X_D = DoubleNessiVector(SIZE_QUAD)
OrigBin_Y_D = DoubleNessiVector(SIZE_QUAD)
RebinBin_X_D = DoubleNessiVector(SIZE_QUAD)
RebinBin_Y_D = DoubleNessiVector(SIZE_QUAD)
FracBin_X_D = DoubleNessiVector(SIZE_TWO_QUADS)
FracBin_Y_D = DoubleNessiVector(SIZE_TWO_QUADS)

Output_D = DoubleNessiVector((len(Axis_Out_1_D) - 1) * (len(Axis_Out_2_D) - 1))
Output_Err2_D = DoubleNessiVector((len(Axis_Out_1_D) - 1) *
                                  (len(Axis_Out_2_D) - 1))
FracArea_D = DoubleNessiVector((len(Axis_Out_1_D) - 1) *
                               (len(Axis_Out_2_D) - 1))

print "Checking Rebin 2D Quadrilateral to Rectilinear Binding Function"

rebin_2D_quad_to_rectlin_d(Axis_In_X1_D, Axis_In_Y1_D,
                           Axis_In_X2_D, Axis_In_Y2_D,
                           Axis_In_X3_D, Axis_In_Y3_D,
                           Axis_In_X4_D, Axis_In_Y4_D,
                           Input_D, Input_Err2_D,
                           Axis_Out_1_D, Axis_Out_2_D,
                           OrigBin_X_D, OrigBin_Y_D,
                           RebinBin_X_D, RebinBin_Y_D,
                           FracBin_X_D, FracBin_Y_D,
                           Output_D, Output_Err2_D,
                           FracArea_D)

mess = test_common_bind.makeCheck("rebin_2D_quad_to_rectlin_d",
                                  Output_D, TruthOutput_D,
                                  Output_Err2_D, TruthOutput_Err2_D)

print mess


mess = test_common_bind.makeCheck("rebin_2D_quad_to_rectlin_d",
                                  FracArea_D, TruthFracArea_D)

print mess

##
# \} // end of test_rebin_2D_quad_to_rectlin group
#
