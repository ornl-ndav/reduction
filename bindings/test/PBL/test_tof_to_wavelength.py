###############################################################################
#
# Testing script for Swig bindings for tof_to_wavelength functions
#
# $Id$
#
###############################################################################

from axis_manip_bind import tof_to_wavelength_d
from axis_manip_bind import tof_to_wavelength_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "##################################################################"
print "# Checking Tof_to_Wavelength Swig Generated Python Binding Layer #"
print "##################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
pathlength = 5.0
pathlength_err2 = 2.5

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

# Truth values for tof_to_wavelength vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(0.0007912067999999)
TruthOutput_VV_D.append(0.0015824135999999)
TruthOutput_VV_D.append(0.0023736204000000)
TruthOutput_VV_D.append(0.0031648271999999)
TruthOutput_VV_D.append(0.0039560339999999)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.00000037560492021)
TruthOutput_Err2_VV_D.append(0.00000118941558069)
TruthOutput_Err2_VV_D.append(0.00000212842788124)
TruthOutput_Err2_VV_D.append(0.0000031926418218)
TruthOutput_Err2_VV_D.append(0.00000438205740256)

# Truth values for tof_to_wavelength scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 0.00079120679999999
TruthOutput_SS_D.val_err2 = 0.00000037560492021

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for tof_to_wavelength vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for tof_to_wavelength scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector TOF to Initial Wavelength IGS Binding Function"

tof_to_wavelength_d(Input_D, Input_Err2_D,
                    pathlength, pathlength_err2,
                    Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("tof_to_wavelength_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar TOF to Initial Wavelength IGS Binding Function"

tof_to_wavelength_ss_d(Input_D[0], Input_Err2_D[0],
                       pathlength, pathlength_err2,
                       Output_SS_D)

mess = test_common_bind.makeCheck2("tof_to_wavelength_d",
                                   Output_SS_D.val,
                                   TruthOutput_SS_D.val,
                                   Output_SS_D.val_err2,
                                   TruthOutput_SS_D.val_err2)

print mess
