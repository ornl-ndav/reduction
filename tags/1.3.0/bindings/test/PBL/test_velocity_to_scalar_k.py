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
TruthOutput_VV_D.append(1588.25361641977462574)
TruthOutput_VV_D.append(3176.50723283954914285)
TruthOutput_VV_D.append(4764.76084925932351903)
TruthOutput_VV_D.append(6353.01446567909828570)
TruthOutput_VV_D.append(7941.26808209887285716)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(1261274.77503524611986224)
TruthOutput_Err2_VV_D.append(3783824.32510573780471771)
TruthOutput_Err2_VV_D.append(6306373.87517623011403620)
TruthOutput_Err2_VV_D.append(8828923.42524672289695893)
TruthOutput_Err2_VV_D.append(11351472.9753172140190008)

# Truth values for velocity_to_scalar_k scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 1588.25361641977462574
TruthOutput_SS_D.val_err2 = 1261274.77503524611986224

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
