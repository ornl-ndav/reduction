###############################################################################
#
# Testing script for Swig bindings for frequency_to_energy functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_frequency_to_energy.py
#

##
# \defgroup test_frequency_to_energy pbl::test_frequency_to_energy
# \{
#

from axis_manip_bind import frequency_to_energy_d
from axis_manip_bind import frequency_to_energy_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "####################################################################"
print "# Checking Frequency_to_Energy Swig Generated Python Binding Layer #"
print "####################################################################"
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

# Truth values for frequency_to_energy vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(4.13566742999999980)
TruthOutput_VV_D.append(8.27133485999999960)
TruthOutput_VV_D.append(12.4070022899999994)
TruthOutput_VV_D.append(16.5426697199999992)
TruthOutput_VV_D.append(20.6783371499999972)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(8.55187254578140177)
TruthOutput_Err2_VV_D.append(25.65561763734420708)
TruthOutput_Err2_VV_D.append(42.75936272890700707)
TruthOutput_Err2_VV_D.append(59.86310782046981416)
TruthOutput_Err2_VV_D.append(76.96685291203262125)

# Truth values for frequency_to_energy scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 4.13566742999999980
TruthOutput_SS_D.val_err2 = 8.55187254578140177

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for frequency_to_energy vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for frequency_to_energy scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Frequency to Energy Binding Function"

frequency_to_energy_d(Input_D, Input_Err2_D,
                      Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("frequency_to_energy_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Frequency to Energy Binding Function"

frequency_to_energy_ss_d(Input_D[0], Input_Err2_D[0], Output_SS_D)

mess = test_common_bind.makeCheck("frequency_to_energy_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_frequency_to_energy group
#
