###############################################################################
#
# Testing script for Swig bindings for tof_to_final_velocity_dgs
# functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_tof_to_final_velocity_dgs.py
#

##
# \defgroup test_tof_to_final_velocity_dgs \
# pbl::test_tof_to_final_velocity_dgs
# \{
#

from axis_manip_bind import tof_to_final_velocity_dgs_d
from axis_manip_bind import tof_to_final_velocity_dgs_ss_d
from nessi_vector_bind import *
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "##########################################"
print "# Checking Tof_to_Final_Velocity_Dgs     #"
print "# Swig Generated Python Binding Layer    #"
print "##########################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
initial_velocity = 1.25
initial_velocity_err2 = 0.25
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

# Truth values for tof_to_final_velocity_dgs vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(-0.19391634980988590)
TruthOutput_VV_D.append(-0.31288343558282200)
if(platform=="linux2" and uname()[4]=="x86_64"):
    TruthOutput_VV_D.append(-0.8095238095238096)
    TruthOutput_VV_D.append(1.3783783783783781)
    TruthOutput_VV_D.append(0.37226277372262783)
else:
    TruthOutput_VV_D.append(-0.80952380952380909)
    TruthOutput_VV_D.append(1.37837837837837962)
    TruthOutput_VV_D.append(0.37226277372262784)
    
TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.01838717382611049)
TruthOutput_Err2_VV_D.append(0.13129216784667819)
if(platform=="linux2" and uname()[4]=="x86_64"):
    TruthOutput_Err2_VV_D.append(6.817174587695375)
    TruthOutput_Err2_VV_D.append(70.4852386802180320)
    TruthOutput_Err2_VV_D.append(0.4735235667252817)
else:
    TruthOutput_Err2_VV_D.append(6.81717458769535600)
    TruthOutput_Err2_VV_D.append(70.48523868021837302)
    TruthOutput_Err2_VV_D.append(0.47352356672528229)
    
# Truth values for tof_to_final_velocity_dgs scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = -0.19391634980988590
TruthOutput_SS_D.val_err2 = 0.01838717382611049

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for tof_to_final_velocity_dgs vector-vector
# version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for tof_to_final_velocity_dgs scalar-scalar
# version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector TOF to Final Velocity DGS Binding Function"

tof_to_final_velocity_dgs_d(Input_D, Input_Err2_D,
                            initial_velocity,
                            initial_velocity_err2,
                            time_offset, time_offset_err2,
                            dist_source_sample,
                            dist_source_sample_err2,
                            dist_sample_detector,
                            dist_sample_detector_err2,
                            Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("tof_to_final_velocity_dgs_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar TOF to Final Velocity DGS Binding Function"

tof_to_final_velocity_dgs_ss_d(Input_D[0], Input_Err2_D[0],
                               initial_velocity,
                               initial_velocity_err2,
                               time_offset, time_offset_err2,
                               dist_source_sample,
                               dist_source_sample_err2,
                               dist_sample_detector,
                               dist_sample_detector_err2,
                               Output_SS_D)

mess = test_common_bind.makeCheck("tof_to_final_velocity_dgs_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)
print mess

##
# \} // end of test_tof_to_final_velocity_dgs group
#

