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
print "# Checking Div_Ncerr Swig Generated Python Binding Layer #"
print "###########################################################"
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

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for div_ncerr vector-vector version
Output_DivNcerr_F = FloatNessiVector(len(Input1_F))
Output_DivNcerr_D = DoubleNessiVector(len(Input1_D))
Output_DivNcerr_I = IntNessiVector(len(Input1_I))
Output_DivNcerr_U = UnsignedIntNessiVector(len(Input1_U))
Output_Err2_DivNcerr_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_DivNcerr_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_DivNcerr_I = IntNessiVector(len(Input1_Err2_I))
Output_Err2_DivNcerr_U = UnsignedIntNessiVector(len(Input1_Err2_U))

print "Checking Vector-Vector Division Binding Function"

div_ncerr_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
            Output_DivNcerr_F, Output_Err2_DivNcerr_F)

mess = test_common_bind.makeCheck("div_ncerr_f", Output_DivNcerr_F,
                                  TruthOutput_DivNcerr_F,
                                  Output_Err2_DivNcerr_F,
                                  TruthOutput_Err2_DivNcerr_F)
print mess

div_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
            Output_DivNcerr_D, Output_Err2_DivNcerr_D)

mess = test_common_bind.makeCheck("div_ncerr_d", Output_DivNcerr_D,
                                  TruthOutput_DivNcerr_D,
                                  Output_Err2_DivNcerr_D,
                                  TruthOutput_Err2_DivNcerr_D)
print mess

div_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
            Output_DivNcerr_I, Output_Err2_DivNcerr_I)

mess = test_common_bind.makeCheck("div_ncerr_i", Output_DivNcerr_I,
                                  TruthOutput_DivNcerr_I,
                                  Output_Err2_DivNcerr_I,
                                  TruthOutput_Err2_DivNcerr_I)
print mess

div_ncerr_u(Input1_U, Input1_Err2_U, Input2_U, Input2_Err2_U,
            Output_DivNcerr_U, Output_Err2_DivNcerr_U)

mess = test_common_bind.makeCheck("div_ncerr_u", Output_DivNcerr_U,
                                  TruthOutput_DivNcerr_U,
                                  Output_Err2_DivNcerr_U,
                                  TruthOutput_Err2_DivNcerr_U)
print mess
