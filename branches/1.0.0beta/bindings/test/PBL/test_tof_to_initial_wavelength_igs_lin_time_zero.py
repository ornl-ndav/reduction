###############################################################################
#
# Testing script for Swig bindings for
# tof_to_initial_wavelength_igs_lin_time_zero functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_tof_to_initial_wavelength_igs_lin_time_zero.py
#

##
# \defgroup test_tof_to_initial_wavelength_igs_lin_time_zero \
# pbl::test_tof_to_initial_wavelength_igs_lin_time_zero
# \{
#

from axis_manip_bind import tof_to_initial_wavelength_igs_lin_time_zero_d
from axis_manip_bind import tof_to_initial_wavelength_igs_lin_time_zero_ss_d
from nessi_vector_bind import *
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "########################################################"
print "# Checking Tof_to_Initial_Wavelength_Igs_Lin_Time_Zero #"
print "# Swig Generated Python Binding Layer                  #"
print "########################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
final_wavelength = 1.25
final_wavelength_err2 = 0.25
time_0_slope = 10.0
time_0_slope_err2 = 1.25
time_0_offset = 2.75
time_0_offset_err2 = 0.75
dist_source_sample = 1.1
dist_source_sample_err2 = 0.1
dist_sample_detector = 0.51
dist_sample_detector_err2 = 0.05

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

# Truth values for tof_to_initial_wavelength_igs_lin_time_zero vector-vector
# version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(-1.63892767340579184e+02)
TruthOutput_VV_D.append(-1.63889295796457191e+02)
TruthOutput_VV_D.append(-1.63885824252335169e+02)
TruthOutput_VV_D.append(-1.63882352708213176e+02)
TruthOutput_VV_D.append(-1.63878881164091155e+02)

TruthOutput_Err2_VV_D = DoubleNessiVector()
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_Err2_VV_D.append(2.06885417307452872e+03)
    TruthOutput_Err2_VV_D.append(2.06876654193679860e+03)
    TruthOutput_Err2_VV_D.append(2.06867891265552907e+03)
    TruthOutput_Err2_VV_D.append(2.06859128523072013e+03)
    TruthOutput_Err2_VV_D.append(2.06850365966237086e+03)
else:
    TruthOutput_Err2_VV_D.append(2.06885417307452781e+03)
    TruthOutput_Err2_VV_D.append(2.06876654193679815e+03)
    TruthOutput_Err2_VV_D.append(2.06867891265552862e+03)
    TruthOutput_Err2_VV_D.append(2.06859128523071968e+03)
    TruthOutput_Err2_VV_D.append(2.06850365966237041e+03)

# Truth values for tof_to_initial_wavelength_igs_lin_time_zero scalar-scalar
# version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = -1.63892767340579184e+02
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_SS_D.val_err2 = 2.06885417307452872e+03
else:
    TruthOutput_SS_D.val_err2 = 2.06885417307452781e+03

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for tof_to_initial_wavelength_igs_lin_time_zero
# vector-vector
# version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for tof_to_initial_wavelength_igs_lin_time_zero
# scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector TOF to Initial Wavelength IGS with Linear"\
      +" Time Zero Binding Function"

tof_to_initial_wavelength_igs_lin_time_zero_d(Input_D, Input_Err2_D,
                                              final_wavelength,
                                              final_wavelength_err2,
                                              time_0_slope,
                                              time_0_slope_err2,
                                              time_0_offset,
                                              time_0_offset_err2,
                                              dist_source_sample,
                                              dist_source_sample_err2,
                                              dist_sample_detector,
                                              dist_sample_detector_err2,
                                              Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck(
    "tof_to_initial_wavelength_igs_lin_time_zero_d",
    Output_VV_D,
    TruthOutput_VV_D,
    Output_Err2_VV_D,
    TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar TOF to Initial Wavelength IGS with Linear"\
      +"Time Zero Binding Function"

tof_to_initial_wavelength_igs_lin_time_zero_ss_d(Input_D[0], Input_Err2_D[0],
                                                 final_wavelength,
                                                 final_wavelength_err2,
                                                 time_0_slope,
                                                 time_0_slope_err2,
                                                 time_0_offset,
                                                 time_0_offset_err2,
                                                 dist_source_sample,
                                                 dist_source_sample_err2,
                                                 dist_sample_detector,
                                                 dist_sample_detector_err2,
                                                 Output_SS_D)

mess = test_common_bind.makeCheck(
    "tof_to_initial_wavelength_igs_lin_time_zero_ss_d",
    Output_SS_D.val,
    TruthOutput_SS_D.val,
    Output_SS_D.val_err2,
    TruthOutput_SS_D.val_err2)
print mess

##
# \} // end of test_tof_to_initial_wavelength_igs_lin_time_zero group
#

