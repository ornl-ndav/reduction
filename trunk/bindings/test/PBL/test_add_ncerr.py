###############################################################################
#
# Testing script for Swig bindings for add_ncerr functions
#
# $Id$
#
###############################################################################

##
# \file bindings/PBL/test_add_ncerr.py
#

from array_manip_bind import add_ncerr_d
from array_manip_bind import add_ncerr_i
from nessi_vector_bind import *
import test_common_bind

print "###########################################################"
print "# Checking Add_Ncerr Swig Generated Python Binding Layer  #"
print "###########################################################"
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

# Truth values for add_ncerr vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(6.0)
TruthOutput_VV_D.append(6.0)
TruthOutput_VV_D.append(6.0)
TruthOutput_VV_D.append(6.0)
TruthOutput_VV_D.append(6.0)

TruthOutput_VV_I = IntNessiVector()
TruthOutput_VV_I.append(6)
TruthOutput_VV_I.append(6)
TruthOutput_VV_I.append(6)
TruthOutput_VV_I.append(6)
TruthOutput_VV_I.append(6)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(2.0)
TruthOutput_Err2_VV_D.append(2.0)
TruthOutput_Err2_VV_D.append(2.0)
TruthOutput_Err2_VV_D.append(2.0)
TruthOutput_Err2_VV_D.append(2.0)

TruthOutput_Err2_VV_I = IntNessiVector()
TruthOutput_Err2_VV_I.append(2)
TruthOutput_Err2_VV_I.append(2)
TruthOutput_Err2_VV_I.append(2)
TruthOutput_Err2_VV_I.append(2)
TruthOutput_Err2_VV_I.append(2)

# Truth values for add_ncerr vector-scalar version
TruthOutput_VS_D = DoubleNessiVector()
TruthOutput_VS_D.append(10.0)
TruthOutput_VS_D.append(9.0)
TruthOutput_VS_D.append(8.0)
TruthOutput_VS_D.append(7.0)
TruthOutput_VS_D.append(6.0)

TruthOutput_VS_I = IntNessiVector()
TruthOutput_VS_I.append(10)
TruthOutput_VS_I.append(9)
TruthOutput_VS_I.append(8)
TruthOutput_VS_I.append(7)
TruthOutput_VS_I.append(6)

TruthOutput_Err2_VS_D = DoubleNessiVector()
TruthOutput_Err2_VS_D.append(2.0)
TruthOutput_Err2_VS_D.append(2.0)
TruthOutput_Err2_VS_D.append(2.0)
TruthOutput_Err2_VS_D.append(2.0)
TruthOutput_Err2_VS_D.append(2.0)

TruthOutput_Err2_VS_I = IntNessiVector()
TruthOutput_Err2_VS_I.append(2)
TruthOutput_Err2_VS_I.append(2)
TruthOutput_Err2_VS_I.append(2)
TruthOutput_Err2_VS_I.append(2)
TruthOutput_Err2_VS_I.append(2)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for add_ncerr vector-vector version
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_VV_I = IntNessiVector(len(Input1_I))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VV_I = IntNessiVector(len(Input1_Err2_I))

# Output placeholders for add_ncerr vector-scalar version
Output_VS_D = DoubleNessiVector(len(Input1_D))
Output_VS_I = IntNessiVector(len(Input1_I))
Output_Err2_VS_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VS_I = IntNessiVector(len(Input1_Err2_I))

print "Checking Vector-Vector Addition Binding Function"

add_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
            Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("add_ncerr_d", Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess

add_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
            Output_VV_I, Output_Err2_VV_I)

mess = test_common_bind.makeCheck("add_ncerr_i", Output_VV_I,
                                  TruthOutput_VV_I,
                                  Output_Err2_VV_I,
                                  TruthOutput_Err2_VV_I)
print mess
print
print "Checking Vector-Scalar Addition Binding Function"

add_ncerr_d(Input1_D, Input1_Err2_D,
            Input2_D[NUM_VAL-1], Input2_Err2_D[NUM_VAL-1],
            Output_VS_D, Output_Err2_VS_D)

mess = test_common_bind.makeCheck("add_ncerr_d", Output_VS_D,
                                  TruthOutput_VS_D,
                                  Output_Err2_VS_D,
                                  TruthOutput_Err2_VS_D)
print mess

add_ncerr_i(Input1_I, Input1_Err2_I,
            Input2_I[NUM_VAL-1], Input2_Err2_I[NUM_VAL-1],
            Output_VS_I, Output_Err2_VS_I)

mess = test_common_bind.makeCheck("add_ncerr_i", Output_VS_I,
                                  TruthOutput_VS_I,
                                  Output_Err2_VS_I,
                                  TruthOutput_Err2_VS_I)
print mess
