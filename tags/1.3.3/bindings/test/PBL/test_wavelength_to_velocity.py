###############################################################################
#
# Testing script for Swig bindings for wavelength_to_velocity functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_wavelength_to_velocity.py
#

##
# \defgroup test_wavelength_to_velocity pbl::test_wavelength_to_velocity
# \{
#

from axis_manip_bind import wavelength_to_velocity_d
from axis_manip_bind import wavelength_to_velocity_ss_d
from nessi_vector_bind import *
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "#######################################################################"
print "# Checking Wavelength_to_Velocity Swig Generated Python Binding Layer #"
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

# Truth values for wavelength_to_velocity vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(3.95603399999999977e-03)
TruthOutput_VV_D.append(1.97801699999999988e-03)
TruthOutput_VV_D.append(1.31867799999999999e-03)
TruthOutput_VV_D.append(9.89008499999999941e-04)
TruthOutput_VV_D.append(7.91206799999999975e-04)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(7.82510250457799879e-06)
TruthOutput_Err2_VV_D.append(1.46720671960837467e-06)
TruthOutput_Err2_VV_D.append(4.83031018801111101e-07)
TruthOutput_Err2_VV_D.append(2.13967646609554648e-07)
TruthOutput_Err2_VV_D.append(1.12681476065923179e-07)

# Truth values for wavelength_to_velocity scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 3.95603399999999977e-03
TruthOutput_SS_D.val_err2 = 7.82510250457799879e-06

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for wavelength_to_velocity vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for wavelength_to_velocity scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Wavelength to Velocity Binding Function"

wavelength_to_velocity_d(Input_D, Input_Err2_D, Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("wavelength_to_velocity_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Wavelength to Velocity Binding Function"

wavelength_to_velocity_ss_d(Input_D[0], Input_Err2_D[0], Output_SS_D)

mess = test_common_bind.makeCheck("wavelength_to_velocity_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_wavelength_to_velocity group
#
