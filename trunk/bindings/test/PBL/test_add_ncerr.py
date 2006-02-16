###############################################################################
#
# Testing script for Swig bindings for add_ncerr functions
#
# $Id$
#
###############################################################################

from array_manip_bind import add_ncerr_f
from array_manip_bind import add_ncerr_d
from array_manip_bind import add_ncerr_i
from array_manip_bind import add_ncerr_u
from nessi_vector_bind import *
import test_common_bind

print "###########################################################"
print "# Checking Add_Ncerr Swig Generated Python Binding Layer #"
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
