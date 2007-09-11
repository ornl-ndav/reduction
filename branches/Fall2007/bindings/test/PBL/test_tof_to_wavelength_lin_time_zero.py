###############################################################################
#
# Testing script for Swig bindings for tof_to_wavelength_lin_time_zero
# functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_tof_to_wavelength_lin_time_zero.py
#

##
# \defgroup test_tof_to_wavelength_lin_time_zero pbl::test_tof_to_wavelength_lin_time_zero
# \{
#

from axis_manip_bind import tof_to_wavelength_lin_time_zero_d
from axis_manip_bind import tof_to_wavelength_lin_time_zero_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "##################################################################"
print "# Checking Tof_to_Wavelength_Lin_Time_Zero Swig Generated Python #"
print "# Binding Layer                                                  #"
print "##################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
pathlength = 5.0
pathlength_err2 = 2.5
time_0_slope = 10.0
time_0_slope_err2 = 1.25
time_0_offset = 2.75
time_0_offset_err2 = 0.75

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

# Truth values for tof_to_wavelength_lin_time_zero vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(-1.37374275391650524e-03)
TruthOutput_VV_D.append(-5.88746894535645011e-04)
TruthOutput_VV_D.append(1.96248964845215437e-04)
TruthOutput_VV_D.append(9.81244824226075452e-04)
TruthOutput_VV_D.append(1.76624068360693547e-03)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(9.56040282227712784e-07)
TruthOutput_Err2_VV_D.append(1.42061212174109880e-06)
TruthOutput_Err2_VV_D.append(2.00650128903985257e-06)
TruthOutput_Err2_VV_D.append(2.71370778412397325e-06)
TruthOutput_Err2_VV_D.append(3.54223160699346147e-06)

# Truth values for tof_to_wavelength_lin_time_zero scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = -1.37374275391650524e-03
TruthOutput_SS_D.val_err2 = 9.56040282227712784e-07

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for tof_to_wavelength_lin_time_zero vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for tof_to_wavelength_lin_time_zero scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector TOF to Wavelength with Linear Time Zero "\
      +"Binding Function"

tof_to_wavelength_lin_time_zero_d(Input_D, Input_Err2_D,
                                  pathlength, pathlength_err2,
                                  time_0_slope, time_0_slope_err2,
                                  time_0_offset, time_0_offset_err2,
                                  Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("tof_to_wavelength_lin_time_zero_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar TOF to Wavelength with Linear Time Zero "\
      +"Binding Function"

tof_to_wavelength_lin_time_zero_ss_d(Input_D[0], Input_Err2_D[0],
                                     pathlength, pathlength_err2,
                                     time_0_slope, time_0_slope_err2,
                                     time_0_offset, time_0_offset_err2,
                                     Output_SS_D)

mess = test_common_bind.makeCheck("tof_to_wavelength_lin_time_zero_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_tof_to_wavelength_lin_time_zero group
#
