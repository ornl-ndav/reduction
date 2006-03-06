###############################################################################
#
# Testing script for Swig bindings for wavelength_to_scalar_k functions
#
# $Id$
#
###############################################################################

from axis_manip_bind import wavelength_to_scalar_k_f
from axis_manip_bind import wavelength_to_scalar_k_d
from nessi_vector_bind import *
import test_common_bind

print "#######################################################################"
print "# Checking Wavelength_to_Scalar_K Swig Generated Python Binding Layer #"
print "#######################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input_F = FloatNessiVector()
Input_Err2_F = FloatNessiVector()
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_F.append(float(counter+1))
    Input_Err2_F.append(float(counter+0.5))
    Input_D.append(float(counter+1))
    Input_Err2_D.append(float(counter+0.5))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for wavelength_to_scalar_k vector-vector version
TruthOutput_VV_F = FloatNessiVector()
TruthOutput_VV_F.append(6.283185482)
TruthOutput_VV_F.append(3.1415927410)
TruthOutput_VV_F.append(2.0943951606)
TruthOutput_VV_F.append(1.5707963705)
TruthOutput_VV_F.append(1.2566370964)

TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(6.28318530717958623)
TruthOutput_VV_D.append(3.14159265358979311)
TruthOutput_VV_D.append(2.09439510239319526)
TruthOutput_VV_D.append(1.57079632679489655)
TruthOutput_VV_D.append(1.25663706143591724)

TruthOutput_Err2_VV_F = FloatNessiVector()
TruthOutput_Err2_VV_F.append(19.7392101287)
TruthOutput_Err2_VV_F.append(3.70110177993)
TruthOutput_Err2_VV_F.append(1.21846973896)
TruthOutput_Err2_VV_F.append(0.53974401950)
TruthOutput_Err2_VV_F.append(0.28424462676)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(19.73920880217871598)
TruthOutput_Err2_VV_D.append(3.701101650408509247)
TruthOutput_Err2_VV_D.append(1.218469679146834350)
TruthOutput_Err2_VV_D.append(0.539743990684574237)
TruthOutput_Err2_VV_D.append(0.284244606751373529)

# Truth values for wavelength_to_scalar_k scalar-scalar version
TruthOutput_SS_F = 6.2831854820

TruthOutput_SS_D = 6.28318530717958623

TruthOutput_Err2_SS_F = 19.7392101287

TruthOutput_Err2_SS_D = 19.73920880217871598

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for wavelength_to_scalar_k vector-vector version
Output_VV_F = FloatNessiVector(len(Input_F))
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_F = FloatNessiVector(len(Input_Err2_F))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for wavelength_to_scalar_k scalar-scalar version
Output_SS_F = 0.0
Output_SS_D = 0.0
Output_Err2_SS_F = 0.0
Output_Err2_SS_D = 0.0

print "Checking Vector-Vector Wavelength to Scalar K Binding Function"

wavelength_to_scalar_k_f(Input_F, Input_Err2_F,
                         Output_VV_F, Output_Err2_VV_F)

mess = test_common_bind.makeCheck("wavelength_to_scalar_k_f",
                                  Output_VV_F,
                                  TruthOutput_VV_F,
                                  Output_Err2_VV_F,
                                  TruthOutput_Err2_VV_F)
print mess

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

wavelength_to_scalar_k_f(Input_F[0], Input_Err2_F[0],
                         Output_SS_F, Output_Err2_SS_F)

#mess = test_common_bind.makeCheck("wavelength_to_scalar_k_f",
#Output_SS_F,
#                                  TruthOutput_SS_F,
#                                  Output_Err2_SS_F,
#                                  TruthOutput_Err2_SS_F)
#print mess

wavelength_to_scalar_k_d(Input_D[0], Input_Err2_D[0],
                         Output_SS_D, Output_Err2_SS_D)

#mess = test_common_bind.makeCheck("wavelength_to_scalar_k_d",
#Output_SS_D,
#                                  TruthOutput_SS_D,
#                                  Output_Err2_SS_D,
#                                  TruthOutput_Err2_SS_D)
#print mess
