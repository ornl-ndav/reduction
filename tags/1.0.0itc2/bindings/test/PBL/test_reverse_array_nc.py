###############################################################################
#
# Testing script for Swig bindings for reverse_array_nc functions
#
# $Id$
#
###############################################################################

from axis_manip_bind import reverse_array_nc_f
from axis_manip_bind import reverse_array_nc_d
from axis_manip_bind import reverse_array_nc_i
from axis_manip_bind import reverse_array_nc_u
from nessi_vector_bind import *
import test_common_bind

print "##################################################################"
print "# Checking Reverse_Array_Nc Swig Generated Python Binding Layer  #"
print "##################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input_F = FloatNessiVector()
Input_Err2_F = FloatNessiVector()
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()
Input_I = IntNessiVector()
Input_Err2_I = IntNessiVector()
Input_U = UnsignedIntNessiVector()
Input_Err2_U = UnsignedIntNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_F.append(float(counter+1))
    Input_D.append(float(counter+1))
    Input_I.append(counter+1)
    Input_U.append(counter+1)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for reverse_array_nc version
TruthOutput_F = FloatNessiVector()
TruthOutput_F.append(5.0)
TruthOutput_F.append(4.0)
TruthOutput_F.append(3.0)
TruthOutput_F.append(2.0)
TruthOutput_F.append(1.0)

TruthOutput_D = DoubleNessiVector()
TruthOutput_D.append(5.0)
TruthOutput_D.append(4.0)
TruthOutput_D.append(3.0)
TruthOutput_D.append(2.0)
TruthOutput_D.append(1.0)

TruthOutput_I = IntNessiVector()
TruthOutput_I.append(5)
TruthOutput_I.append(4)
TruthOutput_I.append(3)
TruthOutput_I.append(2)
TruthOutput_I.append(1)

TruthOutput_U = UnsignedIntNessiVector()
TruthOutput_U.append(5)
TruthOutput_U.append(4)
TruthOutput_U.append(3)
TruthOutput_U.append(2)
TruthOutput_U.append(1)

print "Checking Reverse Array Non-Copy Binding Function"

reverse_array_nc_f(Input_F)

mess = test_common_bind.makeCheck1("reverse_array_nc_f",
                                   Input_F, TruthOutput_F)

print mess

reverse_array_nc_d(Input_D)

mess = test_common_bind.makeCheck1("reverse_array_nc_d",
                                   Input_D, TruthOutput_D)

print mess

reverse_array_nc_i(Input_I)

mess = test_common_bind.makeCheck1("reverse_array_nc_i",
                                   Input_I, TruthOutput_I)

print mess

reverse_array_nc_u(Input_U)

mess = test_common_bind.makeCheck1("reverse_array_nc_u",
                                   Input_U, TruthOutput_U)

print mess
