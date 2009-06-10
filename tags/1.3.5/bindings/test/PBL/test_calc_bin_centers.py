###############################################################################
#
# Testing script for Swig bindings for calc_bin_centers functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_calc_bin_centers.py
#

##
# \defgroup test_calc_bin_centers pbl::test_calc_bin_centers
# \{
#

from utils_bind import calc_bin_centers_d
from nessi_vector_bind import *
import test_common_bind

print "#######################################################################"
print "# Checking Calc_Bin_Centers Swig Generated Python Binding Layer       #"
print "#######################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Axis_D = DoubleNessiVector()
Axis_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Axis_D.append(float(counter+1))
    Axis_Err2_D.append(float((counter+1) * 1.1))

Axis_D.append(float(NUM_VAL+1))
Axis_Err2_D.append(float((NUM_VAL+1) * 1.1))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for calc_bin_centers vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(1.5)
TruthOutput_VV_D.append(2.5)
TruthOutput_VV_D.append(3.5)
TruthOutput_VV_D.append(4.5)
TruthOutput_VV_D.append(5.5)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.825)
TruthOutput_Err2_VV_D.append(1.375)
TruthOutput_Err2_VV_D.append(1.925)
TruthOutput_Err2_VV_D.append(2.475)
TruthOutput_Err2_VV_D.append(3.0250000000000004)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for calc_bin_centers vector-vector version
Output_VV_D = DoubleNessiVector(NUM_VAL)
Output_Err2_VV_D = DoubleNessiVector(NUM_VAL)

print "Checking Vector-Vector Calculate Bin Centers Binding Function"

calc_bin_centers_d(Axis_D, Axis_Err2_D,
                   Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("calc_bin_centers_d", Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess

##
# \} // end of test_calc_bin_centers group
#
