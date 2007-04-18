###############################################################################
#
# Testing script for Swig bindings for rebin_diagonal functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_rebin_diagonal.py
#

##
# \defgroup test_rebin_diagonal pbl::test_rebin_diagonal
# \{
#

from axis_manip_bind import rebin_diagonal_d
from nessi_vector_bind import *
import test_common_bind

print "################################################################"
print "# Checking Rebin_Diagonal Swig Generated Python Binding Layer  #"
print "################################################################"
print

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()
Axis_In_1_D = DoubleNessiVector()
Axis_In_2_D = DoubleNessiVector()
Axis_Out_1_D = DoubleNessiVector()
Axis_Out_2_D = DoubleNessiVector()

# Place values in the input vectors and input axes
Input_D.append(10.)
Input_D.append(10.)
Input_D.append(10.)
Input_D.append(10.)

Input_Err2_D.append(1.)
Input_Err2_D.append(1.)
Input_Err2_D.append(1.)
Input_Err2_D.append(1.)

Axis_In_1_D.append(0.)
Axis_In_1_D.append(1.)
Axis_In_1_D.append(2.)
Axis_In_1_D.append(3.)
Axis_In_1_D.append(4.)

Axis_In_2_D.append(0.)
Axis_In_2_D.append(1.)
Axis_In_2_D.append(2.)
Axis_In_2_D.append(3.)
Axis_In_2_D.append(4.)

Axis_Out_1_D.append(0.)
Axis_Out_1_D.append(1.33333)
Axis_Out_1_D.append(2.66666)
Axis_Out_1_D.append(4.)

Axis_Out_2_D.append(0.)
Axis_Out_2_D.append(2.)
Axis_Out_2_D.append(4.)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for rebin_diagonal version
TruthOutput_D = DoubleNessiVector()
TruthOutput_D.append(13.3333)
TruthOutput_D.append(0.0)
TruthOutput_D.append(6.66670000000000051)
TruthOutput_D.append(6.66659999999999808)
TruthOutput_D.append(0.0)
TruthOutput_D.append(13.3334000000000010)

TruthOutput_Err2_D = DoubleNessiVector()
TruthOutput_Err2_D.append(1.1111088889)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(0.4444488889000001)
TruthOutput_Err2_D.append(0.4444355555999998)
TruthOutput_Err2_D.append(0.0)
TruthOutput_Err2_D.append(1.1111155556)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for reverse_array_cp
Output_D = DoubleNessiVector((len(Axis_Out_1_D) - 1) * (len(Axis_Out_2_D) - 1))
Output_Err2_D = DoubleNessiVector((len(Axis_Out_1_D) - 1) *
                                  (len(Axis_Out_2_D) - 1))

print "Checking Rebin Diagonal Binding Function"

rebin_diagonal_d(Axis_In_1_D, Axis_In_2_D, Input_D, Input_Err2_D,
                Axis_Out_1_D, Axis_Out_2_D,
                Output_D, Output_Err2_D)

mess = test_common_bind.makeCheck("rebin_diagonal_d",
                                  Output_D, TruthOutput_D,
                                  Output_Err2_D, TruthOutput_Err2_D)

print mess

##
# \} // end of test_rebin_diagonal group
#
