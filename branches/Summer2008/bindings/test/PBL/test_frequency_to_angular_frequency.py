###############################################################################
#
# Testing script for Swig bindings for frequency_to_angular_frequency functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_frequency_to_angular_frequency.py
#

##
# \defgroup test_frequency_to_angular_frequency pbl::test_frequency_to_angular_frequency
# \{
#

from axis_manip_bind import frequency_to_angular_frequency_d
from axis_manip_bind import frequency_to_angular_frequency_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "####################################################################"
print "# Checking Frequency_to_Angular_Frequency Swig Generated Python    #"
print "# Binding Layer                                                    #"
print "####################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_D.append(float(counter*1.0e-12))
    Input_Err2_D.append(float(counter*1.0e-24))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for frequency_to_angular_frequency vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(0.00000000000000000)
TruthOutput_VV_D.append(6.28318530717958645)
TruthOutput_VV_D.append(12.56637061435917158)
TruthOutput_VV_D.append(18.84955592153875737)
TruthOutput_VV_D.append(25.13274122871834618)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.00000000000000000)
TruthOutput_Err2_VV_D.append(39.47841760435742841)
TruthOutput_Err2_VV_D.append(78.95683520871484316)
TruthOutput_Err2_VV_D.append(118.43525281307227000)
TruthOutput_Err2_VV_D.append(157.91367041742968737)

# Truth values for frequency_to_angular_frequency scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 0.00000000000000000
TruthOutput_SS_D.val_err2 = 0.00000000000000000

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for frequency_to_angular_frequency vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for frequency_to_angular_frequency scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Frequency to Angular_Frequency Binding Function"

frequency_to_angular_frequency_d(Input_D, Input_Err2_D,
                                 Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("frequency_to_angular_frequency_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Frequency to Angular_Frequency Binding Function"

frequency_to_angular_frequency_ss_d(Input_D[0], Input_Err2_D[0], Output_SS_D)

mess = test_common_bind.makeCheck("frequency_to_angular_frequency_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_frequency_to_angular_frequency group
#
