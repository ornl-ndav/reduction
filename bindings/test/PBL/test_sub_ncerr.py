###############################################################################
#
# Testing script for Swig bindings for sub_ncerr functions
#
# $Id$
#
###############################################################################

from array_manip_bind import sub_ncerr_f
from array_manip_bind import sub_ncerr_d
from array_manip_bind import sub_ncerr_i
from array_manip_bind import sub_ncerr_u
from nessi_vector_bind import *
import test_common_bind

print "##########################################################"
print "# Checking Sub_Ncerr Swig Generated Python Binding Layer #"
print "##########################################################"
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

# Place values in the input vectors
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

# Output placeholders for sub_ncerr vector-vector version
Output_SubNcerr_F = FloatNessiVector(len(Input1_F))
Output_SubNcerr_D = DoubleNessiVector(len(Input1_D))
Output_SubNcerr_I = IntNessiVector(len(Input1_I))
Output_SubNcerr_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_SubNcerr_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_SubNcerr_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_SubNcerr_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_SubNcerr_U = UnsignedIntNessiVector(len(Input1_Err2_U))

print "Checking Vector-Vector Subtraction Binding Function"

sub_ncerr_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
            Output_SubNcerr_F, Output_Err2_SubNcerr_F)

mess = test_common_bind.makeCheck("sub_ncerr_f", Output_SubNcerr_F,
                                  TruthOutput_SubNcerr_F,
                                  Output_Err2_SubNcerr_F,
                                  TruthOutput_Err2_SubNcerr_F)
print mess

sub_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
            Output_SubNcerr_D, Output_Err2_SubNcerr_D)

mess = test_common_bind.makeCheck("sub_ncerr_d", Output_SubNcerr_D,
                                  TruthOutput_SubNcerr_D,
                                  Output_Err2_SubNcerr_D,
                                  TruthOutput_Err2_SubNcerr_D)
print mess

sub_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
            Output_SubNcerr_I, Output_Err2_SubNcerr_I)

mess = test_common_bind.makeCheck("sub_ncerr_i", Output_SubNcerr_I,
                                  TruthOutput_SubNcerr_I,
                                  Output_Err2_SubNcerr_I,
                                  TruthOutput_Err2_SubNcerr_I)
print mess

sub_ncerr_u(Input1_U, Input1_Err2_U, Input2_U, Input2_Err2_U,
            Output_SubNcerr_U, Output_Err2_SubNcerr_U)

mess = test_common_bind.makeCheck("sub_ncerr_u", Output_SubNcerr_U,
                                  TruthOutput_SubNcerr_U,
                                  Output_Err2_SubNcerr_U,
                                  TruthOutput_Err2_SubNcerr_U)
print mess