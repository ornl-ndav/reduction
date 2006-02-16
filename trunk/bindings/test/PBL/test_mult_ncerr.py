###############################################################################
#
# Testing script for Swig bindings for mult_ncerr functions
#
# $Id$
#
###############################################################################

from array_manip_bind import mult_ncerr_f
from array_manip_bind import mult_ncerr_d
from array_manip_bind import mult_ncerr_i
from array_manip_bind import mult_ncerr_u
from nessi_vector_bind import *
import test_common_bind

print "############################################################"
print "# Checking Mult_Ncerr Swig Generated Python Binding Layer #"
print "############################################################"
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

# Truth values for mult_ncerr vector-vector version
TruthOutput_MultNcerr_F = FloatNessiVector()
TruthOutput_MultNcerr_F.append(0.0)
TruthOutput_MultNcerr_F.append(5.0)
TruthOutput_MultNcerr_F.append(8.0)
TruthOutput_MultNcerr_F.append(9.0)
TruthOutput_MultNcerr_F.append(8.0)

TruthOutput_MultNcerr_D = DoubleNessiVector()
TruthOutput_MultNcerr_D.append(0.0)
TruthOutput_MultNcerr_D.append(5.0)
TruthOutput_MultNcerr_D.append(8.0)
TruthOutput_MultNcerr_D.append(9.0)
TruthOutput_MultNcerr_D.append(8.0)

TruthOutput_MultNcerr_I = IntNessiVector()
TruthOutput_MultNcerr_I.append(0)
TruthOutput_MultNcerr_I.append(5)
TruthOutput_MultNcerr_I.append(8)
TruthOutput_MultNcerr_I.append(9)
TruthOutput_MultNcerr_I.append(8)

TruthOutput_MultNcerr_U = UnsignedIntNessiVector()
TruthOutput_MultNcerr_U.append(0)
TruthOutput_MultNcerr_U.append(5)
TruthOutput_MultNcerr_U.append(8)
TruthOutput_MultNcerr_U.append(9)
TruthOutput_MultNcerr_U.append(8)

TruthOutput_Err2_MultNcerr_F = FloatNessiVector()
TruthOutput_Err2_MultNcerr_F.append(36.0)
TruthOutput_Err2_MultNcerr_F.append(26.0)
TruthOutput_Err2_MultNcerr_F.append(20.0)
TruthOutput_Err2_MultNcerr_F.append(18.0)
TruthOutput_Err2_MultNcerr_F.append(20.0)

TruthOutput_Err2_MultNcerr_D = DoubleNessiVector()
TruthOutput_Err2_MultNcerr_D.append(36.0)
TruthOutput_Err2_MultNcerr_D.append(26.0)
TruthOutput_Err2_MultNcerr_D.append(20.0)
TruthOutput_Err2_MultNcerr_D.append(18.0)
TruthOutput_Err2_MultNcerr_D.append(20.0)

TruthOutput_Err2_MultNcerr_I = IntNessiVector()
TruthOutput_Err2_MultNcerr_I.append(36)
TruthOutput_Err2_MultNcerr_I.append(26)
TruthOutput_Err2_MultNcerr_I.append(20)
TruthOutput_Err2_MultNcerr_I.append(18)
TruthOutput_Err2_MultNcerr_I.append(20)

TruthOutput_Err2_MultNcerr_U = UnsignedIntNessiVector()
TruthOutput_Err2_MultNcerr_U.append(36)
TruthOutput_Err2_MultNcerr_U.append(26)
TruthOutput_Err2_MultNcerr_U.append(20)
TruthOutput_Err2_MultNcerr_U.append(18)
TruthOutput_Err2_MultNcerr_U.append(20)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for mult_ncerr vector-vector version
Output_MultNcerr_F = FloatNessiVector(len(Input1_F))
Output_MultNcerr_D = DoubleNessiVector(len(Input1_D))
Output_MultNcerr_I = IntNessiVector(len(Input1_I))
Output_MultNcerr_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_MultNcerr_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_MultNcerr_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_MultNcerr_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_MultNcerr_U = UnsignedIntNessiVector(len(Input1_Err2_U))

print "Checking Vector-Vector Multiplication Binding Function"

mult_ncerr_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
            Output_MultNcerr_F, Output_Err2_MultNcerr_F)

mess = test_common_bind.makeCheck("mult_ncerr_f", Output_MultNcerr_F,
                                  TruthOutput_MultNcerr_F,
                                  Output_Err2_MultNcerr_F,
                                  TruthOutput_Err2_MultNcerr_F)
print mess

mult_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
            Output_MultNcerr_D, Output_Err2_MultNcerr_D)

mess = test_common_bind.makeCheck("mult_ncerr_d", Output_MultNcerr_D,
                                  TruthOutput_MultNcerr_D,
                                  Output_Err2_MultNcerr_D,
                                  TruthOutput_Err2_MultNcerr_D)
print mess

mult_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
            Output_MultNcerr_I, Output_Err2_MultNcerr_I)

mess = test_common_bind.makeCheck("mult_ncerr_i", Output_MultNcerr_I,
                                  TruthOutput_MultNcerr_I,
                                  Output_Err2_MultNcerr_I,
                                  TruthOutput_Err2_MultNcerr_I)
print mess

mult_ncerr_u(Input1_U, Input1_Err2_U, Input2_U, Input2_Err2_U,
            Output_MultNcerr_U, Output_Err2_MultNcerr_U)

mess = test_common_bind.makeCheck("mult_ncerr_u", Output_MultNcerr_U,
                                  TruthOutput_MultNcerr_U,
                                  Output_Err2_MultNcerr_U,
                                  TruthOutput_Err2_MultNcerr_U)
print mess
