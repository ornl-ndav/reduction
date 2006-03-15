###############################################################################
#
# Testing script for Swig bindings for tof_to_initial_wavelength_igs
# functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_tof_to_initial_wavelength_igs.py
#

from axis_manip_bind import tof_to_initial_wavelength_igs_d
from axis_manip_bind import tof_to_initial_wavelength_igs_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "##########################################"
print "# Checking Tof_to_Initial_Wavelength_Igs #"
print "# Swig Generated Python Binding Layer    #"
print "##########################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
final_wavelength = 1.25
final_wavelength_err2 = 0.25
time_offset = 2.75
time_offset_err2 = 0.75
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

# Truth values for tof_to_initial_wavelength_igs vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(-0.58583914499999989)
TruthOutput_VV_D.append(-0.58224275045454543)
TruthOutput_VV_D.append(-0.57864635590909085)
TruthOutput_VV_D.append(-0.57504996136363628)
TruthOutput_VV_D.append(-0.57145356681818171)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.14668620920470620)
TruthOutput_Err2_VV_D.append(0.14635196281566775)
TruthOutput_Err2_VV_D.append(0.14601985428674937)
TruthOutput_Err2_VV_D.append(0.14568988361795109)
TruthOutput_Err2_VV_D.append(0.14536205080927291)

# Truth values for tof_to_initial_wavelength_igs scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = -0.58583914499999989
TruthOutput_SS_D.val_err2 = 0.14668620920470620

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for tof_to_initial_wavelength_igs vector-vector
# version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for tof_to_initial_wavelength_igs scalar-scalar
# version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector TOF to Initial Wavelength IGS Binding Function"

tof_to_initial_wavelength_igs_d(Input_D, Input_Err2_D,
                                final_wavelength,
                                final_wavelength_err2,
                                time_offset, time_offset_err2,
                                dist_source_sample,
                                dist_source_sample_err2,
                                dist_sample_detector,
                                dist_sample_detector_err2,
                                Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("tof_to_initial_wavelength_igs_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar TOF to Initial Wavelength IGS Binding Function"

tof_to_initial_wavelength_igs_ss_d(Input_D[0], Input_Err2_D[0],
                                   final_wavelength,
                                   final_wavelength_err2,
                                   time_offset, time_offset_err2,
                                   dist_source_sample,
                                   dist_source_sample_err2,
                                   dist_sample_detector,
                                   dist_sample_detector_err2,
                                   Output_SS_D)

mess = test_common_bind.makeCheck("tof_to_initial_wavelength_igs_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)
print mess

