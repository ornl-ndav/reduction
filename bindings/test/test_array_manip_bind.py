###############################################################################
#
# Testing script for Swig bindings for functions in the array_manip directory
#
# $Id$
#
###############################################################################

from array_manip_bind import *
from nessi_vector_bind import *
import test_common_bind
from utils_bind import vector_is_equals_f
from utils_bind import vector_is_equals_d
from utils_bind import vector_is_equals_i
from utils_bind import vector_is_equals_u

print "######################################################"
print "# Checking Array_Manip Swing Generated Binding Layer #"
print "######################################################"
print

# Set standard size for vectors
vec_length = 5

# Create input vectors
Input1_F = FloatNessiVector()
Input1_Err2_F = FloatNessiVector()
Input1_D = DoubleNessiVector()
Input1_Err2_D = DoubleNessiVector()
Input1_I = IntNessiVector()
Input1_Err2_I = IntNessiVector()
Input1_U = UnsignedIntNessiVector()
Input1_Err2_U = UnsignedIntNessiVector()
Input2_F = FloatNessiVector()
Input2_Err2_F = FloatNessiVector()
Input2_D = DoubleNessiVector()
Input2_Err2_D = DoubleNessiVector()
Input2_I = IntNessiVector()
Input2_Err2_I = IntNessiVector()
Input2_U = UnsignedIntNessiVector()
Input2_Err2_U = UnsignedIntNessiVector()

for counter in range(vec_length):
    Input1_F.append(float(vec_length+1-counter))
    Input1_Err2_F.append(float(1))
    Input1_D.append(float(vec_length+1-counter))
    Input1_Err2_D.append(float(1))
    Input1_I.append(vec_length+1-counter)
    Input1_Err2_I.append(1)
    Input1_U.append(vec_length+1-counter)
    Input1_Err2_U.append(1)
    Input2_F.append(float(counter))
    Input2_Err2_F.append(float(1))
    Input2_D.append(float(counter))
    Input2_Err2_D.append(float(1))
    Input2_I.append(counter)
    Input2_Err2_I.append(1)
    Input2_U.append(counter)
    Input2_Err2_U.append(1)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for add_ncerr vector-vector version
TruthOutput_AddNcerr_F = FloatNessiVector()
TruthOutput_AddNcerr_F.append(6.0)
TruthOutput_AddNcerr_F.append(6.0)
TruthOutput_AddNcerr_F.append(6.0)
TruthOutput_AddNcerr_F.append(6.0)
TruthOutput_AddNcerr_F.append(6.0)

TruthOutput_AddNcerr_D = DoubleNessiVector()
TruthOutput_AddNcerr_D.append(6.0)
TruthOutput_AddNcerr_D.append(6.0)
TruthOutput_AddNcerr_D.append(6.0)
TruthOutput_AddNcerr_D.append(6.0)
TruthOutput_AddNcerr_D.append(6.0)

TruthOutput_AddNcerr_I = IntNessiVector()
TruthOutput_AddNcerr_I.append(6)
TruthOutput_AddNcerr_I.append(6)
TruthOutput_AddNcerr_I.append(6)
TruthOutput_AddNcerr_I.append(6)
TruthOutput_AddNcerr_I.append(6)

TruthOutput_AddNcerr_U = UnsignedIntNessiVector()
TruthOutput_AddNcerr_U.append(6)
TruthOutput_AddNcerr_U.append(6)
TruthOutput_AddNcerr_U.append(6)
TruthOutput_AddNcerr_U.append(6)
TruthOutput_AddNcerr_U.append(6)

TruthOutput_Err2_AddNcerr_F = FloatNessiVector()
TruthOutput_Err2_AddNcerr_F.append(2.0)
TruthOutput_Err2_AddNcerr_F.append(2.0)
TruthOutput_Err2_AddNcerr_F.append(2.0)
TruthOutput_Err2_AddNcerr_F.append(2.0)
TruthOutput_Err2_AddNcerr_F.append(2.0)

TruthOutput_Err2_AddNcerr_D = DoubleNessiVector()
TruthOutput_Err2_AddNcerr_D.append(2.0)
TruthOutput_Err2_AddNcerr_D.append(2.0)
TruthOutput_Err2_AddNcerr_D.append(2.0)
TruthOutput_Err2_AddNcerr_D.append(2.0)
TruthOutput_Err2_AddNcerr_D.append(2.0)

TruthOutput_Err2_AddNcerr_I = IntNessiVector()
TruthOutput_Err2_AddNcerr_I.append(2)
TruthOutput_Err2_AddNcerr_I.append(2)
TruthOutput_Err2_AddNcerr_I.append(2)
TruthOutput_Err2_AddNcerr_I.append(2)
TruthOutput_Err2_AddNcerr_I.append(2)

TruthOutput_Err2_AddNcerr_U = UnsignedIntNessiVector()
TruthOutput_Err2_AddNcerr_U.append(2)
TruthOutput_Err2_AddNcerr_U.append(2)
TruthOutput_Err2_AddNcerr_U.append(2)
TruthOutput_Err2_AddNcerr_U.append(2)
TruthOutput_Err2_AddNcerr_U.append(2)

# Truth values for sub_ncerr vector-vector version
TruthOutput_SubNcerr_F= FloatNessiVector()
TruthOutput_SubNcerr_F.append(6.0)
TruthOutput_SubNcerr_F.append(4.0)
TruthOutput_SubNcerr_F.append(2.0)
TruthOutput_SubNcerr_F.append(0.0)
TruthOutput_SubNcerr_F.append(-2.0)

TruthOutput_SubNcerr_D = DoubleNessiVector()
TruthOutput_SubNcerr_D.append(6.0)
TruthOutput_SubNcerr_D.append(4.0)
TruthOutput_SubNcerr_D.append(2.0)
TruthOutput_SubNcerr_D.append(0.0)
TruthOutput_SubNcerr_D.append(-2.0)

TruthOutput_SubNcerr_I = IntNessiVector()
TruthOutput_SubNcerr_I.append(6)
TruthOutput_SubNcerr_I.append(4)
TruthOutput_SubNcerr_I.append(2)
TruthOutput_SubNcerr_I.append(0)
TruthOutput_SubNcerr_I.append(-2)

TruthOutput_SubNcerr_U = UnsignedIntNessiVector()
TruthOutput_SubNcerr_U.append(6)
TruthOutput_SubNcerr_U.append(4)
TruthOutput_SubNcerr_U.append(2)
TruthOutput_SubNcerr_U.append(0)
# Script throws a TypeError exception if -2 is sent, so sent the correct
# unsigned interger value for -2
TruthOutput_SubNcerr_U.append(4294967294)

TruthOutput_Err2_SubNcerr_F = FloatNessiVector()
TruthOutput_Err2_SubNcerr_F.append(2.0)
TruthOutput_Err2_SubNcerr_F.append(2.0)
TruthOutput_Err2_SubNcerr_F.append(2.0)
TruthOutput_Err2_SubNcerr_F.append(2.0)
TruthOutput_Err2_SubNcerr_F.append(2.0)

TruthOutput_Err2_SubNcerr_D = DoubleNessiVector()
TruthOutput_Err2_SubNcerr_D.append(2.0)
TruthOutput_Err2_SubNcerr_D.append(2.0)
TruthOutput_Err2_SubNcerr_D.append(2.0)
TruthOutput_Err2_SubNcerr_D.append(2.0)
TruthOutput_Err2_SubNcerr_D.append(2.0)

TruthOutput_Err2_SubNcerr_I = IntNessiVector()
TruthOutput_Err2_SubNcerr_I.append(2)
TruthOutput_Err2_SubNcerr_I.append(2)
TruthOutput_Err2_SubNcerr_I.append(2)
TruthOutput_Err2_SubNcerr_I.append(2)
TruthOutput_Err2_SubNcerr_I.append(2)

TruthOutput_Err2_SubNcerr_U = UnsignedIntNessiVector()
TruthOutput_Err2_SubNcerr_U.append(2)
TruthOutput_Err2_SubNcerr_U.append(2)
TruthOutput_Err2_SubNcerr_U.append(2)
TruthOutput_Err2_SubNcerr_U.append(2)
TruthOutput_Err2_SubNcerr_U.append(2)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for add_ncerr vector-vector version
Output_AddNcerr_F = FloatNessiVector(len(Input1_F))
Output_AddNcerr_D = DoubleNessiVector(len(Input1_D))
Output_AddNcerr_I = IntNessiVector(len(Input1_I))
Output_AddNcerr_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_AddNcerr_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_AddNcerr_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_AddNcerr_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_AddNcerr_U = UnsignedIntNessiVector(len(Input1_Err2_U))

# Output placeholders for add_ncerr vector-vector version
Output_SubNcerr_F = FloatNessiVector(len(Input1_F))
Output_SubNcerr_D = DoubleNessiVector(len(Input1_D))
Output_SubNcerr_I = IntNessiVector(len(Input1_I))
Output_SubNcerr_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_SubNcerr_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_SubNcerr_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_SubNcerr_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_SubNcerr_U = UnsignedIntNessiVector(len(Input1_Err2_U))

print "Checking Vector-Vector Addition Binding Function"

mess = "add_ncerr_f............................."
add_ncerr_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
            Output_AddNcerr_F, Output_Err2_AddNcerr_F)
print mess

mess = "add_ncerr_d............................."
add_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
            Output_AddNcerr_D, Output_Err2_AddNcerr_D)
print mess

mess = "add_ncerr_i............................."
add_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
            Output_AddNcerr_I, Output_Err2_AddNcerr_I)

dval = vector_is_equals_i(Output_AddNcerr_I, TruthOutput_AddNcerr_I)
eval = vector_is_equals_i(Output_Err2_AddNcerr_I,
                          TruthOutput_Err2_AddNcerr_I)

mess += test_common.makeCheck(dval, eval)
print mess

mess = "add_ncerr_u............................."
add_ncerr_u(Input1_U, Input1_Err2_U, Input2_U, Input2_Err2_U,
            Output_AddNcerr_U, Output_Err2_AddNcerr_U)

dval = vector_is_equals_u(Output_AddNcerr_U, TruthOutput_AddNcerr_U)
eval = vector_is_equals_u(Output_Err2_AddNcerr_U,
                          TruthOutput_Err2_AddNcerr_U)

mess += test_common.makeCheck(dval, eval)
print mess

print "Checking Vector-Vector Subtraction Binding Function"

print "sub_ncerr_f............................."
sub_ncerr_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
            Output_SubNcerr_F, Output_Err2_SubNcerr_F)


