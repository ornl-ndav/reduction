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

# Create input vector for div_ncerr test since C++ tests altered the input
# values compared to all the other tests. The error arrays are the same as
# all the other tests.
Input1_Div_F = FloatNessiVector()
Input1_Div_D = DoubleNessiVector()
Input1_Div_I = IntNessiVector()
Input1_Div_U = UnsignedIntNessiVector()
Input2_Div_F = FloatNessiVector()
Input2_Div_D = DoubleNessiVector()
Input2_Div_I = IntNessiVector()
Input2_Div_U = UnsignedIntNessiVector()

# Place values in the input vectors
for counter in range(vec_length):
    Input1_F.append(float(vec_length+1-counter))
    Input1_Div_F.append(float(10-counter))
    Input1_Err2_F.append(float(1))
    Input1_D.append(float(vec_length+1-counter))
    Input1_Div_D.append(float(10-counter))
    Input1_Err2_D.append(float(1))
    Input1_I.append(vec_length+1-counter)
    Input1_Div_I.append(10-counter)
    Input1_Err2_I.append(1)
    Input1_U.append(vec_length+1-counter)
    Input1_Div_U.append(10-counter)
    Input1_Err2_U.append(1)
    Input2_F.append(float(counter))
    Input2_Div_F.append(float(2+counter))
    Input2_Err2_F.append(float(1))
    Input2_D.append(float(counter))
    Input2_Div_D.append(float(2+counter))
    Input2_Err2_D.append(float(1))
    Input2_I.append(counter)
    Input2_Div_I.append(2+counter)
    Input2_Err2_I.append(1)
    Input2_U.append(counter)
    Input2_Div_U.append(2+counter)
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

# Truth values for div_ncerr vector-vector version
TruthOutput_DivNcerr_F = FloatNessiVector()
TruthOutput_DivNcerr_F.append(5.0)
TruthOutput_DivNcerr_F.append(3.0)
TruthOutput_DivNcerr_F.append(2.0)
TruthOutput_DivNcerr_F.append(1.4)
TruthOutput_DivNcerr_F.append(1.0)

TruthOutput_DivNcerr_D = DoubleNessiVector()
TruthOutput_DivNcerr_D.append(5.0)
TruthOutput_DivNcerr_D.append(3.0)
TruthOutput_DivNcerr_D.append(2.0)
TruthOutput_DivNcerr_D.append(1.4)
TruthOutput_DivNcerr_D.append(1.0)

TruthOutput_DivNcerr_I = IntNessiVector()
TruthOutput_DivNcerr_I.append(5)
TruthOutput_DivNcerr_I.append(3)
TruthOutput_DivNcerr_I.append(2)
TruthOutput_DivNcerr_I.append(1)
TruthOutput_DivNcerr_I.append(1)

TruthOutput_DivNcerr_U = UnsignedIntNessiVector()
TruthOutput_DivNcerr_U.append(5)
TruthOutput_DivNcerr_U.append(3)
TruthOutput_DivNcerr_U.append(2)
TruthOutput_DivNcerr_U.append(1)
TruthOutput_DivNcerr_U.append(1)

TruthOutput_Err2_DivNcerr_F = FloatNessiVector()
TruthOutput_Err2_DivNcerr_F.append(6.5)
TruthOutput_Err2_DivNcerr_F.append(1.111111111111111111111111111111111111)
TruthOutput_Err2_DivNcerr_F.append(0.3125)
TruthOutput_Err2_DivNcerr_F.append(0.1184)
TruthOutput_Err2_DivNcerr_F.append(0.055555555555555555555555555555555555)

TruthOutput_Err2_DivNcerr_D = DoubleNessiVector()
TruthOutput_Err2_DivNcerr_D.append(6.5)
TruthOutput_Err2_DivNcerr_D.append(1.111111111111111111111111111111111111)
TruthOutput_Err2_DivNcerr_D.append(0.3125)
TruthOutput_Err2_DivNcerr_D.append(0.1184)
TruthOutput_Err2_DivNcerr_D.append(0.055555555555555555555555555555555555)

TruthOutput_Err2_DivNcerr_I = IntNessiVector()
TruthOutput_Err2_DivNcerr_I.append(6)
TruthOutput_Err2_DivNcerr_I.append(1)
TruthOutput_Err2_DivNcerr_I.append(0)
TruthOutput_Err2_DivNcerr_I.append(0)
TruthOutput_Err2_DivNcerr_I.append(0)

TruthOutput_Err2_DivNcerr_U = UnsignedIntNessiVector()
TruthOutput_Err2_DivNcerr_U.append(6)
TruthOutput_Err2_DivNcerr_U.append(1)
TruthOutput_Err2_DivNcerr_U.append(0)
TruthOutput_Err2_DivNcerr_U.append(0)
TruthOutput_Err2_DivNcerr_U.append(0)

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

# Truth values for sumw_ncerr vector-vector version
TruthOutput_SumwNcerr_F = FloatNessiVector()
TruthOutput_SumwNcerr_F.append(6.0)
TruthOutput_SumwNcerr_F.append(6.0)
TruthOutput_SumwNcerr_F.append(6.0)
TruthOutput_SumwNcerr_F.append(6.0)
TruthOutput_SumwNcerr_F.append(6.0)

TruthOutput_SumwNcerr_D = DoubleNessiVector()
TruthOutput_SumwNcerr_D.append(6.0)
TruthOutput_SumwNcerr_D.append(6.0)
TruthOutput_SumwNcerr_D.append(6.0)
TruthOutput_SumwNcerr_D.append(6.0)
TruthOutput_SumwNcerr_D.append(6.0)

TruthOutput_SumwNcerr_I = IntNessiVector()
TruthOutput_SumwNcerr_I.append(6)
TruthOutput_SumwNcerr_I.append(6)
TruthOutput_SumwNcerr_I.append(6)
TruthOutput_SumwNcerr_I.append(6)
TruthOutput_SumwNcerr_I.append(6)

TruthOutput_SumwNcerr_U = UnsignedIntNessiVector()
TruthOutput_SumwNcerr_U.append(6)
TruthOutput_SumwNcerr_U.append(6)
TruthOutput_SumwNcerr_U.append(6)
TruthOutput_SumwNcerr_U.append(6)
TruthOutput_SumwNcerr_U.append(6)

TruthOutput_Err2_SumwNcerr_F = FloatNessiVector()
TruthOutput_Err2_SumwNcerr_F.append(4.0)
TruthOutput_Err2_SumwNcerr_F.append(4.0)
TruthOutput_Err2_SumwNcerr_F.append(4.0)
TruthOutput_Err2_SumwNcerr_F.append(4.0)
TruthOutput_Err2_SumwNcerr_F.append(4.0)

TruthOutput_Err2_SumwNcerr_D = DoubleNessiVector()
TruthOutput_Err2_SumwNcerr_D.append(4.0)
TruthOutput_Err2_SumwNcerr_D.append(4.0)
TruthOutput_Err2_SumwNcerr_D.append(4.0)
TruthOutput_Err2_SumwNcerr_D.append(4.0)
TruthOutput_Err2_SumwNcerr_D.append(4.0)

TruthOutput_Err2_SumwNcerr_I = IntNessiVector()
TruthOutput_Err2_SumwNcerr_I.append(4)
TruthOutput_Err2_SumwNcerr_I.append(4)
TruthOutput_Err2_SumwNcerr_I.append(4)
TruthOutput_Err2_SumwNcerr_I.append(4)
TruthOutput_Err2_SumwNcerr_I.append(4)

TruthOutput_Err2_SumwNcerr_U = UnsignedIntNessiVector()
TruthOutput_Err2_SumwNcerr_U.append(4)
TruthOutput_Err2_SumwNcerr_U.append(4)
TruthOutput_Err2_SumwNcerr_U.append(4)
TruthOutput_Err2_SumwNcerr_U.append(4)
TruthOutput_Err2_SumwNcerr_U.append(4)

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

# Output placeholders for div_ncerr vector-vector version
Output_DivNcerr_F = FloatNessiVector(len(Input1_F))
Output_DivNcerr_D = DoubleNessiVector(len(Input1_D))
Output_DivNcerr_I = IntNessiVector(len(Input1_I))
Output_DivNcerr_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_DivNcerr_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_DivNcerr_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_DivNcerr_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_DivNcerr_U = UnsignedIntNessiVector(len(Input1_Err2_U))

# Output placeholders for sub_ncerr vector-vector version
Output_SubNcerr_F = FloatNessiVector(len(Input1_F))
Output_SubNcerr_D = DoubleNessiVector(len(Input1_D))
Output_SubNcerr_I = IntNessiVector(len(Input1_I))
Output_SubNcerr_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_SubNcerr_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_SubNcerr_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_SubNcerr_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_SubNcerr_U = UnsignedIntNessiVector(len(Input1_Err2_U))

# Output placeholders for mult_ncerr vector-vector version
Output_MultNcerr_F = FloatNessiVector(len(Input1_F))
Output_MultNcerr_D = DoubleNessiVector(len(Input1_D))
Output_MultNcerr_I = IntNessiVector(len(Input1_I))
Output_MultNcerr_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_MultNcerr_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_MultNcerr_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_MultNcerr_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_MultNcerr_U = UnsignedIntNessiVector(len(Input1_Err2_U))

# Output placeholders for sumw_ncerr vector-vector version
Output_SumwNcerr_F = FloatNessiVector(len(Input1_F))
Output_SumwNcerr_D = DoubleNessiVector(len(Input1_D))
Output_SumwNcerr_I = IntNessiVector(len(Input1_I))
Output_SumwNcerr_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_SumwNcerr_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_SumwNcerr_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_SumwNcerr_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_SumwNcerr_U = UnsignedIntNessiVector(len(Input1_Err2_U))

print "Checking Vector-Vector Addition Binding Function"

add_ncerr_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
            Output_AddNcerr_F, Output_Err2_AddNcerr_F)

mess = test_common_bind.makeCheck("add_ncerr_f", Output_AddNcerr_F,
                                  TruthOutput_AddNcerr_F,
                                  Output_Err2_AddNcerr_F,
                                  TruthOutput_Err2_AddNcerr_F)
print mess

add_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
            Output_AddNcerr_D, Output_Err2_AddNcerr_D)

mess = test_common_bind.makeCheck("add_ncerr_d", Output_AddNcerr_D,
                                  TruthOutput_AddNcerr_D,
                                  Output_Err2_AddNcerr_D,
                                  TruthOutput_Err2_AddNcerr_D)
print mess

add_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
            Output_AddNcerr_I, Output_Err2_AddNcerr_I)

mess = test_common_bind.makeCheck("add_ncerr_i", Output_AddNcerr_I,
                                  TruthOutput_AddNcerr_I,
                                  Output_Err2_AddNcerr_I,
                                  TruthOutput_Err2_AddNcerr_I)
print mess

add_ncerr_u(Input1_U, Input1_Err2_U, Input2_U, Input2_Err2_U,
            Output_AddNcerr_U, Output_Err2_AddNcerr_U)

mess = test_common_bind.makeCheck("add_ncerr_u", Output_AddNcerr_U,
                                  TruthOutput_AddNcerr_U,
                                  Output_Err2_AddNcerr_U,
                                  TruthOutput_Err2_AddNcerr_U)
print mess

print
print "Checking Vector-Vector Division Binding Function"

div_ncerr_f(Input1_Div_F, Input1_Err2_F, Input2_Div_F, Input2_Err2_F,
            Output_DivNcerr_F, Output_Err2_DivNcerr_F)

mess = test_common_bind.makeCheck("div_ncerr_f", Output_DivNcerr_F,
                                  TruthOutput_DivNcerr_F,
                                  Output_Err2_DivNcerr_F,
                                  TruthOutput_Err2_DivNcerr_F)
print mess

div_ncerr_d(Input1_Div_D, Input1_Err2_D, Input2_Div_D, Input2_Err2_D,
            Output_DivNcerr_D, Output_Err2_DivNcerr_D)

mess = test_common_bind.makeCheck("div_ncerr_d", Output_DivNcerr_D,
                                  TruthOutput_DivNcerr_D,
                                  Output_Err2_DivNcerr_D,
                                  TruthOutput_Err2_DivNcerr_D)
print mess

div_ncerr_i(Input1_Div_I, Input1_Err2_I, Input2_Div_I, Input2_Err2_I,
            Output_DivNcerr_I, Output_Err2_DivNcerr_I)

mess = test_common_bind.makeCheck("div_ncerr_i", Output_DivNcerr_I,
                                  TruthOutput_DivNcerr_I,
                                  Output_Err2_DivNcerr_I,
                                  TruthOutput_Err2_DivNcerr_I)
print mess

div_ncerr_u(Input1_Div_U, Input1_Err2_U, Input2_Div_U, Input2_Err2_U,
            Output_DivNcerr_U, Output_Err2_DivNcerr_U)

mess = test_common_bind.makeCheck("div_ncerr_u", Output_DivNcerr_U,
                                  TruthOutput_DivNcerr_U,
                                  Output_Err2_DivNcerr_U,
                                  TruthOutput_Err2_DivNcerr_U)
print mess

print
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

print
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

print
print "Checking Vector-Vector Sum Weighted by Uncertainties Binding Function"

sumw_ncerr_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
            Output_SumwNcerr_F, Output_Err2_SumwNcerr_F)

mess = test_common_bind.makeCheck("sumw_ncerr_f", Output_SumwNcerr_F,
                                  TruthOutput_SumwNcerr_F,
                                  Output_Err2_SumwNcerr_F,
                                  TruthOutput_Err2_SumwNcerr_F)
print mess

sumw_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
            Output_SumwNcerr_D, Output_Err2_SumwNcerr_D)

mess = test_common_bind.makeCheck("sumw_ncerr_d", Output_SumwNcerr_D,
                                  TruthOutput_SumwNcerr_D,
                                  Output_Err2_SumwNcerr_D,
                                  TruthOutput_Err2_SumwNcerr_D)
print mess

sumw_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
            Output_SumwNcerr_I, Output_Err2_SumwNcerr_I)

mess = test_common_bind.makeCheck("sumw_ncerr_i", Output_SumwNcerr_I,
                                  TruthOutput_SumwNcerr_I,
                                  Output_Err2_SumwNcerr_I,
                                  TruthOutput_Err2_SumwNcerr_I)
print mess

sumw_ncerr_u(Input1_U, Input1_Err2_U, Input2_U, Input2_Err2_U,
            Output_SumwNcerr_U, Output_Err2_SumwNcerr_U)

mess = test_common_bind.makeCheck("sumw_ncerr_u", Output_SumwNcerr_U,
                                  TruthOutput_SumwNcerr_U,
                                  Output_Err2_SumwNcerr_U,
                                  TruthOutput_Err2_SumwNcerr_U)
print mess


