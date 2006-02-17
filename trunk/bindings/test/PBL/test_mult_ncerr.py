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
print "# Checking Mult_Ncerr Swig Generated Python Binding Layer  #"
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
TruthOutput_VV_F = FloatNessiVector()
TruthOutput_VV_F.append(0.0)
TruthOutput_VV_F.append(5.0)
TruthOutput_VV_F.append(8.0)
TruthOutput_VV_F.append(9.0)
TruthOutput_VV_F.append(8.0)

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

TruthOutput_VV_U = UnsignedIntNessiVector()
TruthOutput_VV_U.append(0)
TruthOutput_VV_U.append(5)
TruthOutput_VV_U.append(8)
TruthOutput_VV_U.append(9)
TruthOutput_VV_U.append(8)

TruthOutput_Err2_VV_F = FloatNessiVector()
TruthOutput_Err2_VV_F.append(36.0)
TruthOutput_Err2_VV_F.append(26.0)
TruthOutput_Err2_VV_F.append(20.0)
TruthOutput_Err2_VV_F.append(18.0)
TruthOutput_Err2_VV_F.append(20.0)

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

TruthOutput_Err2_VV_U = UnsignedIntNessiVector()
TruthOutput_Err2_VV_U.append(36)
TruthOutput_Err2_VV_U.append(26)
TruthOutput_Err2_VV_U.append(20)
TruthOutput_Err2_VV_U.append(18)
TruthOutput_Err2_VV_U.append(20)

# Truth values for mult_ncerr vector-scalar version
TruthOutput_VS_F = FloatNessiVector()
TruthOutput_VS_F.append(24.0)
TruthOutput_VS_F.append(20.0)
TruthOutput_VS_F.append(16.0)
TruthOutput_VS_F.append(12.0)
TruthOutput_VS_F.append(8.0)

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

TruthOutput_VS_U = UnsignedIntNessiVector()
TruthOutput_VS_U.append(24)
TruthOutput_VS_U.append(20)
TruthOutput_VS_U.append(16)
TruthOutput_VS_U.append(12)
TruthOutput_VS_U.append(8)

TruthOutput_Err2_VS_F = FloatNessiVector()
TruthOutput_Err2_VS_F.append(52.0)
TruthOutput_Err2_VS_F.append(41.0)
TruthOutput_Err2_VS_F.append(32.0)
TruthOutput_Err2_VS_F.append(25.0)
TruthOutput_Err2_VS_F.append(20.0)

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

TruthOutput_Err2_VS_U = UnsignedIntNessiVector()
TruthOutput_Err2_VS_U.append(52)
TruthOutput_Err2_VS_U.append(41)
TruthOutput_Err2_VS_U.append(32)
TruthOutput_Err2_VS_U.append(25)
TruthOutput_Err2_VS_U.append(20)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for mult_ncerr vector-vector version
Output_VV_F = FloatNessiVector(len(Input1_F))
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_VV_I = IntNessiVector(len(Input1_I))
Output_VV_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_VV_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VV_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_VV_U = UnsignedIntNessiVector(len(Input1_Err2_U))

# Output placeholders for mult_ncerr vector-scalar version
Output_VS_F = FloatNessiVector(len(Input1_F))
Output_VS_D = DoubleNessiVector(len(Input1_D))
Output_VS_I = IntNessiVector(len(Input1_I))
Output_VS_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_VS_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_VS_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VS_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_VS_U = UnsignedIntNessiVector(len(Input1_Err2_U))

print "Checking Vector-Vector Multiplication Binding Function"

mult_ncerr_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
            Output_VV_F, Output_Err2_VV_F)

mess = test_common_bind.makeCheck("mult_ncerr_f", Output_VV_F,
                                  TruthOutput_VV_F,
                                  Output_Err2_VV_F,
                                  TruthOutput_Err2_VV_F)
print mess

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

mult_ncerr_u(Input1_U, Input1_Err2_U, Input2_U, Input2_Err2_U,
            Output_VV_U, Output_Err2_VV_U)

mess = test_common_bind.makeCheck("mult_ncerr_u", Output_VV_U,
                                  TruthOutput_VV_U,
                                  Output_Err2_VV_U,
                                  TruthOutput_Err2_VV_U)
print mess
print
print "Checking Vector-Scalar Multiplication Binding Function"

mult_ncerr_f(Input1_F, Input1_Err2_F,
             Input2_F[vec_length-1], Input2_Err2_F[vec_length-1],
             Output_VS_F, Output_Err2_VS_F)

mess = test_common_bind.makeCheck("mult_ncerr_f", Output_VS_F,
                                  TruthOutput_VS_F,
                                  Output_Err2_VS_F,
                                  TruthOutput_Err2_VS_F)
print mess

mult_ncerr_d(Input1_D, Input1_Err2_D,
             Input2_D[vec_length-1], Input2_Err2_D[vec_length-1],
             Output_VS_D, Output_Err2_VS_D)

mess = test_common_bind.makeCheck("mult_ncerr_d", Output_VS_D,
                                  TruthOutput_VS_D,
                                  Output_Err2_VS_D,
                                  TruthOutput_Err2_VS_D)
print mess

mult_ncerr_i(Input1_I, Input1_Err2_I,
             Input2_I[vec_length-1], Input2_Err2_I[vec_length-1],
             Output_VS_I, Output_Err2_VS_I)

mess = test_common_bind.makeCheck("mult_ncerr_i", Output_VS_I,
                                  TruthOutput_VS_I,
                                  Output_Err2_VS_I,
                                  TruthOutput_Err2_VS_I)
print mess

mult_ncerr_u(Input1_U, Input1_Err2_U,
             Input2_U[vec_length-1], Input2_Err2_U[vec_length-1],
             Output_VS_U, Output_Err2_VS_U)

mess = test_common_bind.makeCheck("mult_ncerr_u", Output_VS_U,
                                  TruthOutput_VS_U,
                                  Output_Err2_VS_U,
                                  TruthOutput_Err2_VS_U)
print mess
