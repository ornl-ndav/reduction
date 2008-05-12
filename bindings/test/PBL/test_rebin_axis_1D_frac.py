###############################################################################
#
# Testing script for Swig bindings for rebin_axis_1D_frac functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_rebin_axis_1D_frac.py
#

##
# \defgroup test_rebin_axis_1D_frac pbl::test_rebin_axis_1D_frac
# \{
#

from axis_manip_bind import rebin_axis_1D_frac_d
from nessi_vector_bind import *
import test_common_bind

print "###################################################################"
print "# Checking Rebin_Axis_1D_Frac Swig Generated Python Binding Layer #"
print "###################################################################"
print

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()
Axis_In_D = DoubleNessiVector()
Axis_Out_D = DoubleNessiVector()

# Place values in the input vectors
Input_D.append(10.)
Input_D.append(10.)
Input_D.append(10.)
Input_D.append(10.)
Input_D.append(10.)
Input_Err2_D.append(1.)
Input_Err2_D.append(1.)
Input_Err2_D.append(1.)
Input_Err2_D.append(1.)
Input_Err2_D.append(1.)
Axis_In_D.append(0.)
Axis_In_D.append(2.)
Axis_In_D.append(4.)
Axis_In_D.append(6.)
Axis_In_D.append(8.)
Axis_In_D.append(10.)
Axis_Out_D.append(0.)
Axis_Out_D.append(3.)
Axis_Out_D.append(6.5)
Axis_Out_D.append(10.)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for rebin_axis_1D_frac version
TruthOutput_D = DoubleNessiVector()
TruthOutput_D.append(15.)
TruthOutput_D.append(17.5)
TruthOutput_D.append(17.5)

TruthOutput_Err2_D = DoubleNessiVector()
TruthOutput_Err2_D.append(1.25)
TruthOutput_Err2_D.append(1.3125)
TruthOutput_Err2_D.append(1.5625)

TruthFracArea_D = DoubleNessiVector()
TruthFracArea_D.append(1.5)
TruthFracArea_D.append(1.75)
TruthFracArea_D.append(1.75)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for reverse_array_cp
Output_D = DoubleNessiVector(3)
Output_Err2_D = DoubleNessiVector(3)
FracArea_D = DoubleNessiVector(3)

print "Checking Rebin Axis 1D Fraction Binding Function"

rebin_axis_1D_frac_d(Axis_In_D, Input_D, Input_Err2_D, Axis_Out_D,
                     Output_D, Output_Err2_D, FracArea_D)

mess = test_common_bind.makeCheck("rebin_axis_1D_frac_d",
                                  Output_D, TruthOutput_D,
                                  Output_Err2_D, TruthOutput_Err2_D)

print mess

mess = test_common_bind.makeCheck("rebin_axis_1D_frac_d",
                                  FracArea_D, TruthFracArea_D)

print mess

##
# \} // end of test_rebin_axis_1D_frac group
#
