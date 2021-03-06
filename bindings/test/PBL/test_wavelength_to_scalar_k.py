###############################################################################
#
# Testing script for Swig bindings for wavelength_to_scalar_k functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_wavelength_to_scalar_k.py
#

##
# \defgroup test_wavelength_to_scalar_k pbl::test_wavelength_to_scalar_k
# \{
#

from axis_manip_bind import wavelength_to_scalar_k_d
from axis_manip_bind import wavelength_to_scalar_k_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "#######################################################################"
print "# Checking Wavelength_to_Scalar_K Swig Generated Python Binding Layer #"
print "#######################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_D.append(float(counter+1))
    Input_Err2_D.append(float(counter+0.5))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for wavelength_to_scalar_k vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(6.28318530717958623)
TruthOutput_VV_D.append(3.14159265358979311)
TruthOutput_VV_D.append(2.09439510239319526)
TruthOutput_VV_D.append(1.57079632679489655)
TruthOutput_VV_D.append(1.25663706143591724)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(19.73920880217871598)
TruthOutput_Err2_VV_D.append(3.701101650408509247)
TruthOutput_Err2_VV_D.append(1.218469679146834350)
TruthOutput_Err2_VV_D.append(0.539743990684574237)
TruthOutput_Err2_VV_D.append(0.284244606751373529)

# Truth values for wavelength_to_scalar_k scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 6.28318530717958623
TruthOutput_SS_D.val_err2 = 19.73920880217871598

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for wavelength_to_scalar_k vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for wavelength_to_scalar_k scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Wavelength to Scalar K Binding Function"

wavelength_to_scalar_k_d(Input_D, Input_Err2_D,
                         Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("wavelength_to_scalar_k_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Wavelength to Scalar K Binding Function"

wavelength_to_scalar_k_ss_d(Input_D[0], Input_Err2_D[0], Output_SS_D)

mess = test_common_bind.makeCheck("wavelength_to_scalar_k_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                   Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_wavelength_to_scalar_k group
#
