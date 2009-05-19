###############################################################################
#
# Testing script for Swig bindings for shift_spectrum functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_shift_spectrum.py
#

##
# \defgroup test_shift_spectrum pbl::test_shift_spectrum
# \{
#

from utils_bind import shift_spectrum_d
from nessi_vector_bind import *
import test_common_bind

print "################################################################"
print "# Checking Shift_Spectrum Swig Generated Python Binding Layer  #"
print "################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
xshift = 3.5
xmin = 1.0
xmax = 6.0

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()
Axis_D = DoubleNessiVector()
Axis_BC_D = DoubleNessiVector()

Axis_D.append(1.0)
Axis_D.append(2.0)
Axis_D.append(3.0)
Axis_D.append(4.0)
Axis_D.append(5.0)
Axis_D.append(6.0)

Axis_BC_D.append(1.5)
Axis_BC_D.append(2.5)
Axis_BC_D.append(3.5)
Axis_BC_D.append(4.5)
Axis_BC_D.append(5.5)

Input_D.append(30.0)
Input_D.append(20.0)
Input_D.append(10.0)
Input_D.append(20.0)
Input_D.append(30.0)

Input_Err2_D.append(4.0)
Input_Err2_D.append(3.0)
Input_Err2_D.append(2.0)
Input_Err2_D.append(3.0)
Input_Err2_D.append(4.0)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for shift_spectrum vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(20.0)
TruthOutput_VV_D.append(30.0)
TruthOutput_VV_D.append(30.0)
TruthOutput_VV_D.append(20.0)
TruthOutput_VV_D.append(10.0)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(3.0)
TruthOutput_Err2_VV_D.append(4.0)
TruthOutput_Err2_VV_D.append(4.0)
TruthOutput_Err2_VV_D.append(3.0)
TruthOutput_Err2_VV_D.append(2.0)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for shift_spectrum vector-vector version
Output_VV_D = DoubleNessiVector(NUM_VAL)
Output_Err2_VV_D = DoubleNessiVector(NUM_VAL)

print "Checking Shift Spectrum Binding Function"

shift_spectrum_d(Input_D, Input_Err2_D, Axis_D, Axis_BC_D, xshift, xmin, xmax,
                 Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("shift_spectrum_d", Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess

##
# \} // end of test_shift_spectrum group
#
