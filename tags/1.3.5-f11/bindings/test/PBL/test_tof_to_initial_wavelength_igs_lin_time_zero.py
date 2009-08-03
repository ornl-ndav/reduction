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
TruthOutput_VV_D.append(-0.565501480597332962)
TruthOutput_VV_D.append(-0.562029936475325287)
TruthOutput_VV_D.append(-0.558558392353317723)
TruthOutput_VV_D.append(-0.555086848231310048)
TruthOutput_VV_D.append(-0.551615304109302484)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.134880111049097390)
TruthOutput_Err2_VV_D.append(0.134590680492193304)
TruthOutput_Err2_VV_D.append(0.134303106395620875)
TruthOutput_Err2_VV_D.append(0.134017388759380074)
TruthOutput_Err2_VV_D.append(0.133733527583470901)

# Truth values for tof_to_initial_wavelength_igs_lin_time_zero scalar-scalar
# version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = -0.565501480597332962
TruthOutput_SS_D.val_err2 = 0.134880111049097390

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

