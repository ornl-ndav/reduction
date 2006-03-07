###############################################################################
#
# Testing script for Swig bindings for rebin_axis_1D functions
#
# $Id$
#
###############################################################################

from axis_manip_bind import rebin_axis_1D_f
from axis_manip_bind import rebin_axis_1D_d
from nessi_vector_bind import *
import test_common_bind

print "###############################################################"
print "# Checking Rbein_Axis_1D Swig Generated Python Binding Layer  #"
print "###############################################################"
print

# Create input vectors
Input_F = FloatNessiVector()
Input_Err2_F = FloatNessiVector()
Axis_In_F = FloatNessiVector()
Axis_Out_F = FloatNessiVector()
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()
Axis_In_D = DoubleNessiVector()
Axis_Out_D = DoubleNessiVector()

# Place values in the input vectors
Input_F.append(10.)
Input_F.append(20.)
Input_F.append(30.)
Input_Err2_F.append(1.)
Input_Err2_F.append(4.)
Input_Err2_F.append(9.)
Axis_In_F.append(0.)
Axis_In_F.append(1.)
Axis_In_F.append(2.)
Axis_In_F.append(3.)
Axis_Out_F.append(0.)
Axis_Out_F.append(1.5)
Axis_Out_F.append(3.)
Input_D.append(10.)
Input_D.append(20.)
Input_D.append(30.)
Input_Err2_D.append(1.)
Input_Err2_D.append(4.)
Input_Err2_D.append(9.)
Axis_In_D.append(0.)
Axis_In_D.append(1.)
Axis_In_D.append(2.)
Axis_In_D.append(3.)
Axis_Out_D.append(0.)
Axis_Out_D.append(1.5)
Axis_Out_D.append(3.)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for rebin_axis_1D version
TruthOutput_F = FloatNessiVector()
TruthOutput_F.append(20.)
TruthOutput_F.append(40.)

TruthOutput_D = DoubleNessiVector()
TruthOutput_D.append(20.)
TruthOutput_D.append(40.)

TruthOutput_Err2_F = FloatNessiVector()
TruthOutput_Err2_F.append(2.)
TruthOutput_Err2_F.append(10.)

TruthOutput_Err2_D = DoubleNessiVector()
TruthOutput_Err2_D.append(2.)
TruthOutput_Err2_D.append(10.)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for reverse_array_cp
Output_F = FloatNessiVector(2)
Output_D = DoubleNessiVector(2)
Output_Err2_F = FloatNessiVector(2)
Output_Err2_D = DoubleNessiVector(2)

print "Checking Rebin Axis 1D Binding Function"

rebin_axis_1D_f(Axis_In_F, Input_F, Input_Err2_F, Axis_Out_F,
                Output_F, Output_Err2_F)

mess = test_common_bind.makeCheck("rebin_axis_1D_f",
                                  Output_F, TruthOutput_F,
                                  Output_Err2_F, TruthOutput_Err2_F)

print mess

rebin_axis_1D_d(Axis_In_D, Input_D, Input_Err2_D, Axis_Out_D,
                Output_D, Output_Err2_D)

mess = test_common_bind.makeCheck("rebin_axis_1D_d",
                                  Output_D, TruthOutput_D,
                                  Output_Err2_D, TruthOutput_Err2_D)

print mess
