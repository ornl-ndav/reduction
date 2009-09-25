#
# Testing script for Swig bindings for exp_detector_eff functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_exp_detector_eff.py
#

##
# \defgroup test_exp_detector_eff pbl::test_exp_detector_eff
# \{
#

from phys_corr_bind import exp_detector_eff_d
from phys_corr_bind import exp_detector_eff_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "#################################################################"
print "# Checking Exp_Detector_Eff Swig Generated Python Binding Layer #"
print "#################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
scale = 10.0
scale_err2 = 0.1
constant = 2.0

# Create input vectors
Axis_BC_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Axis_BC_D.append(float(counter+1))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for exp_detector_eff vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(1.35335283236612702)
TruthOutput_VV_D.append(1.83156388887341787e-01)
TruthOutput_VV_D.append(2.47875217666635866e-02)
TruthOutput_VV_D.append(3.35462627902511842e-03)
TruthOutput_VV_D.append(4.53999297624848555e-04)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(1.83156388887341804e-03)
TruthOutput_Err2_VV_D.append(3.35462627902511894e-05)
TruthOutput_Err2_VV_D.append(6.14421235332821002e-07)
TruthOutput_Err2_VV_D.append(1.12535174719259130e-08)
TruthOutput_Err2_VV_D.append(2.06115362243855797e-10)

# Truth values for exp_detector_eff scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 1.35335283236612702
TruthOutput_SS_D.val_err2 = 1.83156388887341804e-03

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for exp_detector_eff vector-vector version
Output_VV_D = DoubleNessiVector(len(Axis_BC_D))
Output_Err2_VV_D = DoubleNessiVector(len(Axis_BC_D))

# Output placeholders for exp_detector_eff scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Exponential Detector Efficiency Binding Function"

exp_detector_eff_d(Axis_BC_D, scale, scale_err2, constant,
                   Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("exp_detector_eff_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Exponential Detector Efficiency Binding Function"

exp_detector_eff_ss_d(Axis_BC_D[0], scale, scale_err2, constant,
                      Output_SS_D)

mess = test_common_bind.makeCheck("exp_detector_eff_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_exp_detector_eff group
#
