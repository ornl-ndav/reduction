###############################################################################
#
# Testing script for Swig bindings for tof_to_scalar_Q functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_tof_to_scalar_Q.py
#

##
# \defgroup test_tof_to_scalar_Q pbl::test_tof_to_scalar_Q
# \{
#

from axis_manip_bind import tof_to_scalar_Q_d
from axis_manip_bind import tof_to_scalar_Q_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "##################################################################"
print "# Checking Tof_to_Scalar_Q Swig Generated Python Binding Layer #"
print "##################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
pathlength = 5.0
pathlength_err2 = 2.5
polar = .5
polar_err2 = .25 

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

# Truth values for tof_to_scalar_Q vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(13938.23677629315170634)
TruthOutput_VV_D.append(6969.11838814657585317)
TruthOutput_VV_D.append(4646.07892543105026561)
TruthOutput_VV_D.append(3484.55919407328792658)
TruthOutput_VV_D.append(2787.64735525863034127)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(109279374.99300612509250640)
TruthOutput_Err2_VV_D.append(42497534.71950238198041915)
TruthOutput_Err2_VV_D.append(21735952.50203825533390045)
TruthOutput_Err2_VV_D.append(13090758.46270385757088661)
TruthOutput_Err2_VV_D.append(8722922.55499728955328465)

# Truth values for tof_to_scalar_Q scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 13938.23677629315170634
TruthOutput_SS_D.val_err2 = 109279374.99300612509250640

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for tof_to_scalar_Q vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for tof_to_scalar_Q scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector TOF to Scalar Q Binding Function"

tof_to_scalar_Q_d(Input_D, Input_Err2_D,
				  pathlength, pathlength_err2,
				  polar, polar_err2,
				  Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("tof_to_scalar_Q_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar TOF to Scalar Q Binding Function"

tof_to_scalar_Q_ss_d(Input_D[0], Input_Err2_D[0],
                       pathlength, pathlength_err2,
					   polar, polar_err2,
                       Output_SS_D)

mess = test_common_bind.makeCheck("tof_to_scalar_Q_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_tof_to_scalar_Q group
#
