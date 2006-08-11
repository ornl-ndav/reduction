###############################################################################
#
# Testing script for Swig bindings for velocity_to_scalar_k functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_velocity_to_scalar_k.py
#

##
# \defgroup test_velocity_to_scalar_k pbl::test_velocity_to_scalar_k
# \{
#

from axis_manip_bind import velocity_to_scalar_k_d
from axis_manip_bind import velocity_to_scalar_k_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "#######################################################################"
print "# Checking Velocity_to_Scalar_K Swig Generated Python Binding Layer   #"
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

# Truth values for velocity_to_scalar_k vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(252.778413936786194)
TruthOutput_VV_D.append(505.55682787357237071)
TruthOutput_VV_D.append(758.33524181035866974)
TruthOutput_VV_D.append(1011.11365574714474142)
TruthOutput_VV_D.append(1263.89206968393092678)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(31948.46327619861383145)
TruthOutput_Err2_VV_D.append(95845.38982859584513236)
TruthOutput_Err2_VV_D.append(159742.31638099305096742)
TruthOutput_Err2_VV_D.append(223639.24293339030418503)
TruthOutput_Err2_VV_D.append(287536.16948578749174136)

# Truth values for velocity_to_scalar_k scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 252.778413936786194
TruthOutput_SS_D.val_err2 = 31948.46327619861383145

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for velocity_to_scalar_k vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for velocity_to_scalar_k scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Velocity to Scalar_k Binding Function"

velocity_to_scalar_k_d(Input_D, Input_Err2_D,
                       Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("velocity_to_scalar_k_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Velocity to Scalar_k Binding Function"

velocity_to_scalar_k_ss_d(Input_D[0], Input_Err2_D[0], Output_SS_D)

mess = test_common_bind.makeCheck("velocity_to_scalar_k_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_velocity_to_scalar_k group
#
