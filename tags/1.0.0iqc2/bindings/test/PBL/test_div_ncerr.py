###############################################################################
#
# Testing script for Swig bindings for div_ncerr functions
#
# $Id$
#
###############################################################################

from array_manip_bind import div_ncerr_f
from array_manip_bind import div_ncerr_d
from array_manip_bind import div_ncerr_i
from array_manip_bind import div_ncerr_u
from nessi_vector_bind import *
import test_common_bind

print "###########################################################"
print "# Checking Div_Ncerr Swig Generated Python Binding Layer  #"
print "###########################################################"
print

# Set standard size for vectors
NUM_VAL = 5

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
for counter in range(NUM_VAL):
    Input1_F.append(float(10-counter))
    Input1_Err2_F.append(float(1))
    Input1_D.append(float(10-counter))
    Input1_Err2_D.append(float(1))
    Input1_I.append(10-counter)
    Input1_Err2_I.append(1)
    Input1_U.append(10-counter)
    Input1_Err2_U.append(1)
    Input2_F.append(float(2+counter))
    Input2_Err2_F.append(float(1))
    Input2_D.append(float(2+counter))
    Input2_Err2_D.append(float(1))
    Input2_I.append(2+counter)
    Input2_Err2_I.append(1)
    Input2_U.append(2+counter)
    Input2_Err2_U.append(1)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for div_ncerr vector-vector version
TruthOutput_VV_F = FloatNessiVector()
TruthOutput_VV_F.append(5.0)
TruthOutput_VV_F.append(3.0)
TruthOutput_VV_F.append(2.0)
TruthOutput_VV_F.append(1.4)
TruthOutput_VV_F.append(1.0)

TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(5.0)
TruthOutput_VV_D.append(3.0)
TruthOutput_VV_D.append(2.0)
TruthOutput_VV_D.append(1.4)
TruthOutput_VV_D.append(1.0)

TruthOutput_VV_I = IntNessiVector()
TruthOutput_VV_I.append(5)
TruthOutput_VV_I.append(3)
TruthOutput_VV_I.append(2)
TruthOutput_VV_I.append(1)
TruthOutput_VV_I.append(1)

TruthOutput_VV_U = UnsignedIntNessiVector()
TruthOutput_VV_U.append(5)
TruthOutput_VV_U.append(3)
TruthOutput_VV_U.append(2)
TruthOutput_VV_U.append(1)
TruthOutput_VV_U.append(1)

TruthOutput_Err2_VV_F = FloatNessiVector()
TruthOutput_Err2_VV_F.append(6.5)
TruthOutput_Err2_VV_F.append(1.111111111111111111111111111111111111)
TruthOutput_Err2_VV_F.append(0.3125)
TruthOutput_Err2_VV_F.append(0.1184)
TruthOutput_Err2_VV_F.append(0.055555555555555555555555555555555555)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(6.5)
TruthOutput_Err2_VV_D.append(1.111111111111111111111111111111111111)
TruthOutput_Err2_VV_D.append(0.3125)
TruthOutput_Err2_VV_D.append(0.1184)
TruthOutput_Err2_VV_D.append(0.055555555555555555555555555555555555)

TruthOutput_Err2_VV_I = IntNessiVector()
TruthOutput_Err2_VV_I.append(6)
TruthOutput_Err2_VV_I.append(1)
TruthOutput_Err2_VV_I.append(0)
TruthOutput_Err2_VV_I.append(0)
TruthOutput_Err2_VV_I.append(0)

TruthOutput_Err2_VV_U = UnsignedIntNessiVector()
TruthOutput_Err2_VV_U.append(6)
TruthOutput_Err2_VV_U.append(1)
TruthOutput_Err2_VV_U.append(0)
TruthOutput_Err2_VV_U.append(0)
TruthOutput_Err2_VV_U.append(0)

# Truth values for div_ncerr vector-scalar version
TruthOutput_VS_F = FloatNessiVector()
TruthOutput_VS_F.append(5.0)
TruthOutput_VS_F.append(4.5)
TruthOutput_VS_F.append(4.0)
TruthOutput_VS_F.append(3.5)
TruthOutput_VS_F.append(3.0)

TruthOutput_VS_D = DoubleNessiVector()
TruthOutput_VS_D.append(5.0)
TruthOutput_VS_D.append(4.5)
TruthOutput_VS_D.append(4.0)
TruthOutput_VS_D.append(3.5)
TruthOutput_VS_D.append(3.0)

TruthOutput_VS_I = IntNessiVector()
TruthOutput_VS_I.append(5)
TruthOutput_VS_I.append(4)
TruthOutput_VS_I.append(4)
TruthOutput_VS_I.append(3)
TruthOutput_VS_I.append(3)

TruthOutput_VS_U = UnsignedIntNessiVector()
TruthOutput_VS_U.append(5)
TruthOutput_VS_U.append(4)
TruthOutput_VS_U.append(4)
TruthOutput_VS_U.append(3)
TruthOutput_VS_U.append(3)

TruthOutput_Err2_VS_F = FloatNessiVector()
TruthOutput_Err2_VS_F.append(6.5)
TruthOutput_Err2_VS_F.append(5.3125)
TruthOutput_Err2_VS_F.append(4.25)
TruthOutput_Err2_VS_F.append(3.3125)
TruthOutput_Err2_VS_F.append(2.5)

TruthOutput_Err2_VS_D = DoubleNessiVector()
TruthOutput_Err2_VS_D.append(6.5)
TruthOutput_Err2_VS_D.append(5.3125)
TruthOutput_Err2_VS_D.append(4.25)
TruthOutput_Err2_VS_D.append(3.3125)
TruthOutput_Err2_VS_D.append(2.5)

TruthOutput_Err2_VS_I = IntNessiVector()
TruthOutput_Err2_VS_I.append(6)
TruthOutput_Err2_VS_I.append(5)
TruthOutput_Err2_VS_I.append(4)
TruthOutput_Err2_VS_I.append(3)
TruthOutput_Err2_VS_I.append(2)

TruthOutput_Err2_VS_U = UnsignedIntNessiVector()
TruthOutput_Err2_VS_U.append(6)
TruthOutput_Err2_VS_U.append(5)
TruthOutput_Err2_VS_U.append(4)
TruthOutput_Err2_VS_U.append(3)
TruthOutput_Err2_VS_U.append(2)

# Truth values for div_ncerr scalar-vector version
TruthOutput_SV_F = FloatNessiVector()
TruthOutput_SV_F.append(5.0)
TruthOutput_SV_F.append(3.33333333333333333333333333333333333333333333333333)
TruthOutput_SV_F.append(2.5)
TruthOutput_SV_F.append(2.0)
TruthOutput_SV_F.append(1.66666666666666666666666666666666666666666666666666)

TruthOutput_SV_D = DoubleNessiVector()
TruthOutput_SV_D.append(5.0)
TruthOutput_SV_D.append(3.33333333333333333333333333333333333333333333333333)
TruthOutput_SV_D.append(2.5)
TruthOutput_SV_D.append(2.0)
TruthOutput_SV_D.append(1.66666666666666666666666666666666666666666666666666)

TruthOutput_SV_I = IntNessiVector()
TruthOutput_SV_I.append(5)
TruthOutput_SV_I.append(3)
TruthOutput_SV_I.append(2)
TruthOutput_SV_I.append(2)
TruthOutput_SV_I.append(1)

TruthOutput_SV_U = UnsignedIntNessiVector()
TruthOutput_SV_U.append(5)
TruthOutput_SV_U.append(3)
TruthOutput_SV_U.append(2)
TruthOutput_SV_U.append(2)
TruthOutput_SV_U.append(1)

TruthOutput_Err2_SV_F = FloatNessiVector()
TruthOutput_Err2_SV_F.append(6.5)
TruthOutput_Err2_SV_F.append(1.34567901234567899)
TruthOutput_Err2_SV_F.append(0.453125)
TruthOutput_Err2_SV_F.append(0.2)
TruthOutput_Err2_SV_F.append(0.1049382716049382662)

TruthOutput_Err2_SV_D = DoubleNessiVector()
TruthOutput_Err2_SV_D.append(6.5)
TruthOutput_Err2_SV_D.append(1.34567901234567899)
TruthOutput_Err2_SV_D.append(0.453125)
TruthOutput_Err2_SV_D.append(0.2)
TruthOutput_Err2_SV_D.append(0.1049382716049382662)

TruthOutput_Err2_SV_I = IntNessiVector()
TruthOutput_Err2_SV_I.append(6)
TruthOutput_Err2_SV_I.append(1)
TruthOutput_Err2_SV_I.append(0)
TruthOutput_Err2_SV_I.append(0)
TruthOutput_Err2_SV_I.append(0)

TruthOutput_Err2_SV_U = UnsignedIntNessiVector()
TruthOutput_Err2_SV_U.append(6)
TruthOutput_Err2_SV_U.append(1)
TruthOutput_Err2_SV_U.append(0)
TruthOutput_Err2_SV_U.append(0)
TruthOutput_Err2_SV_U.append(0)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for div_ncerr vector-vector version
Output_VV_F = FloatNessiVector(len(Input1_F))
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_VV_I = IntNessiVector(len(Input1_I))
Output_VV_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_VV_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VV_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_VV_U = UnsignedIntNessiVector(len(Input1_Err2_U))

# Output placeholders for div_ncerr vector-scalar version
Output_VS_F = FloatNessiVector(len(Input1_F))
Output_VS_D = DoubleNessiVector(len(Input1_D))
Output_VS_I = IntNessiVector(len(Input1_I))
Output_VS_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_VS_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_VS_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VS_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_VS_U = UnsignedIntNessiVector(len(Input1_Err2_U))

# Output placeholders for div_ncerr vector-scalar version
Output_SV_F = FloatNessiVector(len(Input1_F))
Output_SV_D = DoubleNessiVector(len(Input1_D))
Output_SV_I = IntNessiVector(len(Input1_I))
Output_SV_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_SV_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_SV_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_SV_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_SV_U = UnsignedIntNessiVector(len(Input1_Err2_U))

print "Checking Vector-Vector Division Binding Function"

div_ncerr_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
            Output_VV_F, Output_Err2_VV_F)

mess = test_common_bind.makeCheck("div_ncerr_f", Output_VV_F,
                                  TruthOutput_VV_F,
                                  Output_Err2_VV_F,
                                  TruthOutput_Err2_VV_F)
print mess

div_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
            Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("div_ncerr_d", Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess

div_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
            Output_VV_I, Output_Err2_VV_I)

mess = test_common_bind.makeCheck("div_ncerr_i", Output_VV_I,
                                  TruthOutput_VV_I,
                                  Output_Err2_VV_I,
                                  TruthOutput_Err2_VV_I)
print mess

div_ncerr_u(Input1_U, Input1_Err2_U, Input2_U, Input2_Err2_U,
            Output_VV_U, Output_Err2_VV_U)

mess = test_common_bind.makeCheck("div_ncerr_u", Output_VV_U,
                                  TruthOutput_VV_U,
                                  Output_Err2_VV_U,
                                  TruthOutput_Err2_VV_U)
print mess
print
print "Checking Vector-Scalar Division Binding Function"

div_ncerr_f(Input1_F, Input1_Err2_F, Input2_F[0], Input2_Err2_F[0],
            Output_VS_F, Output_Err2_VS_F)

mess = test_common_bind.makeCheck("div_ncerr_f", Output_VS_F,
                                  TruthOutput_VS_F,
                                  Output_Err2_VS_F,
                                  TruthOutput_Err2_VS_F)
print mess

div_ncerr_d(Input1_D, Input1_Err2_D, Input2_D[0], Input2_Err2_D[0],
            Output_VS_D, Output_Err2_VS_D)

mess = test_common_bind.makeCheck("div_ncerr_d", Output_VS_D,
                                  TruthOutput_VS_D,
                                  Output_Err2_VS_D,
                                  TruthOutput_Err2_VS_D)
print mess

div_ncerr_i(Input1_I, Input1_Err2_I, Input2_I[0], Input2_Err2_I[0],
            Output_VS_I, Output_Err2_VS_I)

mess = test_common_bind.makeCheck("div_ncerr_i", Output_VS_I,
                                  TruthOutput_VS_I,
                                  Output_Err2_VS_I,
                                  TruthOutput_Err2_VS_I)
print mess

div_ncerr_u(Input1_U, Input1_Err2_U, Input2_U[0], Input2_Err2_U[0],
            Output_VS_U, Output_Err2_VS_U)

mess = test_common_bind.makeCheck("div_ncerr_u", Output_VS_U,
                                  TruthOutput_VS_U,
                                  Output_Err2_VS_U,
                                  TruthOutput_Err2_VS_U)
print mess
print
print "Checking Scalar-Vector Division Binding Function"

div_ncerr_f(Input1_F[0], Input1_Err2_F[0], Input2_F, Input2_Err2_F,
            Output_SV_F, Output_Err2_SV_F)

mess = test_common_bind.makeCheck("div_ncerr_f", Output_SV_F,
                                  TruthOutput_SV_F,
                                  Output_Err2_SV_F,
                                  TruthOutput_Err2_SV_F)
print mess

div_ncerr_d(Input1_D[0], Input1_Err2_D[0], Input2_D, Input2_Err2_D,
            Output_SV_D, Output_Err2_SV_D)

mess = test_common_bind.makeCheck("div_ncerr_d", Output_SV_D,
                                  TruthOutput_SV_D,
                                  Output_Err2_SV_D,
                                  TruthOutput_Err2_SV_D)
print mess

div_ncerr_i(Input1_I[0], Input1_Err2_I[0], Input2_I, Input2_Err2_I,
            Output_SV_I, Output_Err2_SV_I)

mess = test_common_bind.makeCheck("div_ncerr_i", Output_SV_I,
                                  TruthOutput_SV_I,
                                  Output_Err2_SV_I,
                                  TruthOutput_Err2_SV_I)
print mess

div_ncerr_u(Input1_U[0], Input1_Err2_U[0], Input2_U, Input2_Err2_U,
            Output_SV_U, Output_Err2_SV_U)

mess = test_common_bind.makeCheck("div_ncerr_u", Output_SV_U,
                                  TruthOutput_SV_U,
                                  Output_Err2_SV_U,
                                  TruthOutput_Err2_SV_U)
print mess
