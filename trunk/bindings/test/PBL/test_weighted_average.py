###############################################################################
#
# Testing script for Swig bindings for weighted_average functions
#
# $Id$
#
###############################################################################

##
# \file bindings/PBL/test_weighted_average.py
#

from nessi_vector_bind import *
from utils_bind import weighted_average_d
import test_common_bind
from vpair_bind import *

print "#################################################################"
print "# Checking Weighted_Average Swig Generated Python Binding Layer #"
print "#################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input1_D = DoubleNessiVector()
Input1_Err2_D = DoubleNessiVector()

for counter in range(NUM_VAL):
    Input1_D.append(float(counter+1))
    Input1_Err2_D.append(float(1))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth information for weighted_average
TruthOutput_D = DoubleVPair()
TruthOutput_D.val=float(3)
TruthOutput_D.val_err2=0.2

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for weighted_average
Output_D = DoubleVPair()

print "Checking Weighted Average Binding Function"

weighted_average_d(Input1_D, Input1_Err2_D, 0, NUM_VAL-1, Output_D)

mess = test_common_bind.makeCheck("weighted_average_d",
                                  Output_D.val,
                                  TruthOutput_D.val,
                                  Output_D.val_err2,
                                  TruthOutput_D.val_err2)

print mess



