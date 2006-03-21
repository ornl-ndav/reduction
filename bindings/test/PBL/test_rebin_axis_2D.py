###############################################################################
#
# Testing script for Swig bindings for rebin_axis_2D functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_rebin_axis_2D.py
#

##
# \defgroup test_rebin_axis_2D pbl::test_rebin_axis_2D
# \{
#

from axis_manip_bind import rebin_axis_2D_d
from nessi_vector_bind import *
import test_common_bind

print "###############################################################"
print "# Checking Rebin_Axis_2D Swig Generated Python Binding Layer  #"
print "###############################################################"
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
Input_D.append(20.)
Input_D.append(30.)
Input_D.append(10.)
Input_D.append(20.)
Input_D.append(30.)
Input_D.append(10.)
Input_D.append(20.)
Input_D.append(30.)

Input_Err2_D.append(1.)
Input_Err2_D.append(4.)
Input_Err2_D.append(9.)
Input_Err2_D.append(1.)
Input_Err2_D.append(4.)
Input_Err2_D.append(9.)
Input_Err2_D.append(1.)
Input_Err2_D.append(4.)
Input_Err2_D.append(9.)

Axis_In_1_D.append(0.)
Axis_In_1_D.append(1.)
Axis_In_1_D.append(2.)
Axis_In_1_D.append(3.)

Axis_In_2_D.append(0.)
Axis_In_2_D.append(1.)
Axis_In_2_D.append(2.)
Axis_In_2_D.append(3.)

Axis_Out_1_D.append(0.)
Axis_Out_1_D.append(1.5)
Axis_Out_1_D.append(3.)

Axis_Out_2_D.append(0.)
Axis_Out_2_D.append(1.5)
Axis_Out_2_D.append(3.)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for rebin_axis_2D version
TruthOutput_D = DoubleNessiVector()
TruthOutput_D.append(30.)
TruthOutput_D.append(60.)
TruthOutput_D.append(30.)
TruthOutput_D.append(60.)

TruthOutput_Err2_D = DoubleNessiVector()
TruthOutput_Err2_D.append(2.5)
TruthOutput_Err2_D.append(12.5)
TruthOutput_Err2_D.append(2.5)
TruthOutput_Err2_D.append(12.5)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for reverse_array_cp
Output_D = DoubleNessiVector((len(Axis_Out_1_D) - 1) * (len(Axis_Out_2_D) - 1))
Output_Err2_D = DoubleNessiVector((len(Axis_Out_1_D) - 1) *
                                  (len(Axis_Out_2_D) - 1))

print "Checking Rebin Axis 2D Binding Function"

rebin_axis_2D_d(Axis_In_1_D, Axis_In_2_D, Input_D, Input_Err2_D,
                Axis_Out_1_D, Axis_Out_2_D,
                Output_D, Output_Err2_D)

mess = test_common_bind.makeCheck("rebin_axis_2D_d",
                                  Output_D, TruthOutput_D,
                                  Output_Err2_D, TruthOutput_Err2_D)

print mess

##
# \} // end of test_rebin_axis_2D group
#
