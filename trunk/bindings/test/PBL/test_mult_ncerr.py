###############################################################################
#
# Testing script for Swig bindings for mult_ncerr functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_mult_ncerr.py
#

##
# \defgroup test_mult_ncerr pbl::test_mult_ncerr
# \{
#

from array_manip_bind import mult_ncerr_d
from array_manip_bind import mult_ncerr_ss_d
from array_manip_bind import mult_ncerr_i
from array_manip_bind import mult_ncerr_ss_i
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "############################################################"
print "# Checking Mult_Ncerr Swig Generated Python Binding Layer  #"
print "############################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input1_D = DoubleNessiVector()
Input1_Err2_D = DoubleNessiVector()
Input1_I = IntNessiVector()
Input1_Err2_I = IntNessiVector()
Input2_D = DoubleNessiVector()
Input2_Err2_D = DoubleNessiVector()
Input2_I = IntNessiVector()
Input2_Err2_I = IntNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input1_D.append(float(NUM_VAL+1-counter))
    Input1_Err2_D.append(float(1))
    Input1_I.append(NUM_VAL+1-counter)
    Input1_Err2_I.append(1)
    Input2_D.append(float(counter))
    Input2_Err2_D.append(float(1))
    Input2_I.append(counter)
    Input2_Err2_I.append(1)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for mult_ncerr vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(0.0)
TruthOutput_VV_D.append(5.0)
TruthOutput_VV_D.append(8.0)
TruthOutput_VV_D.append(9.0)
TruthOutput_VV_D.append(8.0)

TruthOutput_VV_I = IntNessiVector()
TruthOutput_VV_I.append(0)
TruthOutput_VV_I.append(5)
TruthOutput_VV_I.append(8)
TruthOutput_VV_I.append(9)
TruthOutput_VV_I.append(8)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(36.0)
TruthOutput_Err2_VV_D.append(26.0)
TruthOutput_Err2_VV_D.append(20.0)
TruthOutput_Err2_VV_D.append(18.0)
TruthOutput_Err2_VV_D.append(20.0)

TruthOutput_Err2_VV_I = IntNessiVector()
TruthOutput_Err2_VV_I.append(36)
TruthOutput_Err2_VV_I.append(26)
TruthOutput_Err2_VV_I.append(20)
TruthOutput_Err2_VV_I.append(18)
TruthOutput_Err2_VV_I.append(20)

# Truth values for mult_ncerr vector-scalar version
TruthOutput_VS_D = DoubleNessiVector()
TruthOutput_VS_D.append(24.0)
TruthOutput_VS_D.append(20.0)
TruthOutput_VS_D.append(16.0)
TruthOutput_VS_D.append(12.0)
TruthOutput_VS_D.append(8.0)

TruthOutput_VS_I = IntNessiVector()
TruthOutput_VS_I.append(24)
TruthOutput_VS_I.append(20)
TruthOutput_VS_I.append(16)
TruthOutput_VS_I.append(12)
TruthOutput_VS_I.append(8)

TruthOutput_Err2_VS_D = DoubleNessiVector()
TruthOutput_Err2_VS_D.append(52.0)
TruthOutput_Err2_VS_D.append(41.0)
TruthOutput_Err2_VS_D.append(32.0)
TruthOutput_Err2_VS_D.append(25.0)
TruthOutput_Err2_VS_D.append(20.0)

TruthOutput_Err2_VS_I = IntNessiVector()
TruthOutput_Err2_VS_I.append(52)
TruthOutput_Err2_VS_I.append(41)
TruthOutput_Err2_VS_I.append(32)
TruthOutput_Err2_VS_I.append(25)
TruthOutput_Err2_VS_I.append(20)

#Truth values for mult_ncerr scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 8.0
TruthOutput_SS_D.val_err2 = 6.0

TruthOutput_SS_I = IntVPair()
TruthOutput_SS_I.val = 8
TruthOutput_SS_I.val_err2 = 6

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for mult_ncerr vector-vector version
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_VV_I = IntNessiVector(len(Input1_I))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VV_I = IntNessiVector(len(Input1_Err2_I))

# Output placeholders for mult_ncerr vector-scalar version
Output_VS_D = DoubleNessiVector(len(Input1_D))
Output_VS_I = IntNessiVector(len(Input1_I))
Output_Err2_VS_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VS_I = IntNessiVector(len(Input1_Err2_I))

# Output placeholders for mult_ncerr scalar-scalar version
Output_SS_D = DoubleVPair()
Output_SS_I = IntVPair()

print "Checking Vector-Vector Multiplication Binding Function"

mult_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
             Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("mult_ncerr_d", Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess

mult_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
             Output_VV_I, Output_Err2_VV_I)

mess = test_common_bind.makeCheck("mult_ncerr_i", Output_VV_I,
                                  TruthOutput_VV_I,
                                  Output_Err2_VV_I,
                                  TruthOutput_Err2_VV_I)
print mess
print
print "Checking Vector-Scalar Multiplication Binding Function"

mult_ncerr_d(Input1_D, Input1_Err2_D,
             Input2_D[NUM_VAL-1], Input2_Err2_D[NUM_VAL-1],
             Output_VS_D, Output_Err2_VS_D)

mess = test_common_bind.makeCheck("mult_ncerr_d", Output_VS_D,
                                  TruthOutput_VS_D,
                                  Output_Err2_VS_D,
                                  TruthOutput_Err2_VS_D)
print mess

mult_ncerr_i(Input1_I, Input1_Err2_I,
             Input2_I[NUM_VAL-1], Input2_Err2_I[NUM_VAL-1],
             Output_VS_I, Output_Err2_VS_I)

mess = test_common_bind.makeCheck("mult_ncerr_i", Output_VS_I,
                                  TruthOutput_VS_I,
                                  Output_Err2_VS_I,
                                  TruthOutput_Err2_VS_I)
print mess
print
print "Checking Scalar-Scalar Multiplication Binding Function"

mult_ncerr_ss_d(Input1_D[NUM_VAL-1], Input1_Err2_D[NUM_VAL-1],
                Input2_D[NUM_VAL-1], Input2_Err2_D[NUM_VAL-1],
                Output_SS_D)

mess = test_common_bind.makeCheck("mult_ncerr_ss_d", Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)
print mess

mult_ncerr_ss_i(Input1_I[NUM_VAL-1], Input1_Err2_I[NUM_VAL-1],
                Input2_I[NUM_VAL-1], Input2_Err2_I[NUM_VAL-1],
                Output_SS_I)

mess = test_common_bind.makeCheck("mult_ncerr_ss_i", Output_SS_I.val,
                                  TruthOutput_SS_I.val,
                                  Output_SS_I.val_err2,
                                  TruthOutput_SS_I.val_err2)
print mess

##
# \} // end of test_mult_ncerr group
#
