###############################################################################
#
# Testing script for Swig bindings for d_spacing_to_tof_focused_det functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_d_spacing_to_tof_focused_det.py
#

##
# \defgroup test_d_spacing_to_tof_focused_det pbl::test_d_spacing_to_tof_focused_det
# \{
#

from axis_manip_bind import d_spacing_to_tof_focused_det_d
from axis_manip_bind import d_spacing_to_tof_focused_det_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "##################################################################"
print "# Checking D_Spacing_to_Tof_Focused_Det Swig Generated Python    #"
print "# Binding Layer                                                  #"
print "##################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
pathlength_focused = 2.75;
pathlength_focused_err2 = 0.75;
polar_angle_focused = 4.0;
polar_angle_focused_err2 = 0.5;

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

# Truth values for d_spacing_to_tof_focused_det vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(1264.17918742388204636)
TruthOutput_VV_D.append(2528.35837484776409272)
TruthOutput_VV_D.append(3792.53756227164590728)
TruthOutput_VV_D.append(5056.71674969552818102)
TruthOutput_VV_D.append(6320.8959371194108650)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(999410.25272388576716936)
TruthOutput_Err2_VV_D.append(3198566.5019376895343388)
TruthOutput_Err2_VV_D.append(5798394.23868355906867743)
TruthOutput_Err2_VV_D.append(8798893.46296149186264514)
TruthOutput_Err2_VV_D.append(12200064.17477148882412910)

# Truth values for d_spacing_to_tof_focused_det scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 1264.17918742388204636
TruthOutput_SS_D.val_err2 = 999410.25272388576716936

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for d_spacing_to_tof_focused_det vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for d_spacing_to_tof_focused_det scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector D-Spacing to TOF Focused Detector Binding "\
      +"Function"

d_spacing_to_tof_focused_det_d(Input_D, Input_Err2_D,
                               pathlength_focused, pathlength_focused_err2,
                               polar_angle_focused, polar_angle_focused_err2,
                               Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("d_spacing_to_tof_focused_det_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar D-Spacing to TOF Focused Detector Binding "\
      +"Function"

d_spacing_to_tof_focused_det_ss_d(Input_D[0], Input_Err2_D[0],
                                  pathlength_focused, pathlength_focused_err2,
                                  polar_angle_focused,
                                  polar_angle_focused_err2,
                                  Output_SS_D)

mess = test_common_bind.makeCheck("d_spacing_to_tof_focused_det_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_d_spacing_to_tof_focused_det group
#
