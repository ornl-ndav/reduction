###############################################################################
#
# Testing script for Swig bindings for wavelength_to_d_spacing functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_wavelength_to_d_spacing.py
#

##
# \defgroup test_wavelength_to_d_spacing pbl::test_wavelength_to_d_spacing
# \{
#

from axis_manip_bind import wavelength_to_d_spacing_d
from axis_manip_bind import wavelength_to_d_spacing_ss_d
from nessi_vector_bind import *
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "#######################################################################"
print "# Checking Wavelength_to_D_Spacing Swig Generated Python Binding Layer #"
print "#######################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
polar_angle = 4.0
polar_angle_err2 = 0.5

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_D.append(float(2*counter+1))
    Input_Err2_D.append(float(counter+0.5))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for wavelength_to_d_spacing vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(0.54987508514730800)
TruthOutput_VV_D.append(1.64962525544192466)
TruthOutput_VV_D.append(2.74937542573654133)
TruthOutput_VV_D.append(3.84912559603115778)
TruthOutput_VV_D.append(4.94887576632577355)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.15909755221565900)
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_Err2_VV_D.append(0.52479014214365233)
else:
    TruthOutput_Err2_VV_D.append(0.52479014214365200)
TruthOutput_Err2_VV_D.append(0.95381271273387956)
TruthOutput_Err2_VV_D.append(1.44616526398634044)
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_Err2_VV_D.append(2.00184779590103600)
else:
    TruthOutput_Err2_VV_D.append(2.00184779590103556)
    
# Truth values for wavelength_to_d_spacing scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 0.54987508514730800
TruthOutput_SS_D.val_err2 = 0.15909755221565900

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for wavelength_to_d_spacing vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for wavelength_to_d_spacing scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Wavelength to D Spacing Binding Function"

wavelength_to_d_spacing_d(Input_D, Input_Err2_D,
                         polar_angle, polar_angle_err2,
                         Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("wavelength_to_d_spacing_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Wavelength to D Spacing Binding Function"

wavelength_to_d_spacing_ss_d(Input_D[0], Input_Err2_D[0],
                            polar_angle, polar_angle_err2,
                            Output_SS_D)

mess = test_common_bind.makeCheck("wavelength_to_d_spacing_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_wavelength_to_d_spacing group
#
