###############################################################################
#
# Testing script for Swig bindings for div_ncerr functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_div_ncerr.py
#

##
# \defgroup test_div_ncerr pbl::test_div_ncerr
# \{
#

from array_manip_bind import div_ncerr_d
from array_manip_bind import div_ncerr_ss_d
from array_manip_bind import div_ncerr_i
from array_manip_bind import div_ncerr_ss_i
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "###########################################################"
print "# Checking Div_Ncerr Swig Generated Python Binding Layer  #"
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
    Input1_D.append(float(10-counter))
    Input1_Err2_D.append(float(1))
    Input1_I.append(10-counter)
    Input1_Err2_I.append(1)
    Input2_D.append(float(2+counter))
    Input2_Err2_D.append(float(1))
    Input2_I.append(2+counter)
    Input2_Err2_I.append(1)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for div_ncerr vector-vector version
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

# Truth values for div_ncerr vector-scalar version
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

# Truth values for div_ncerr scalar-vector version
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

# Truth values for div_ncerr scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 5.0
TruthOutput_SS_D.val_err2 = 6.5

TruthOutput_SS_I = IntVPair()
TruthOutput_SS_I.val = 5
TruthOutput_SS_I.val_err2 = 6

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for div_ncerr vector-vector version
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_VV_I = IntNessiVector(len(Input1_I))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VV_I = IntNessiVector(len(Input1_Err2_I))

# Output placeholders for div_ncerr vector-scalar version
Output_VS_D = DoubleNessiVector(len(Input1_D))
Output_VS_I = IntNessiVector(len(Input1_I))
Output_Err2_VS_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VS_I = IntNessiVector(len(Input1_Err2_I))

# Output placeholders for div_ncerr vector-scalar version
Output_SV_D = DoubleNessiVector(len(Input1_D))
Output_SV_I = IntNessiVector(len(Input1_I))
Output_Err2_SV_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_SV_I = IntNessiVector(len(Input1_Err2_I))

# Output placeholders for div_ncerr scalar-scalar version
Output_SS_D = DoubleVPair()
Output_SS_I = IntVPair()
 
print "Checking Vector-Vector Division Binding Function"

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
print
print "Checking Vector-Scalar Division Binding Function"

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
print
print "Checking Scalar-Vector Division Binding Function"

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
print
print "Checking Scalar-Scalar Division Binding Fuction"

div_ncerr_ss_d(Input1_D[0], Input1_Err2_D[0], 
               Input2_D[0], Input2_Err2_D[0],
               Output_SS_D)

mess = test_common_bind.makeCheck("div_ncerr_ss_d", Output_SS_D.val,
                                 TruthOutput_SS_D.val,
                                 Output_SS_D.val_err2,
                                 TruthOutput_SS_D.val_err2)
print mess
div_ncerr_ss_i(Input1_I[0], Input1_Err2_I[0],
               Input2_I[0], Input2_Err2_I[0],
               Output_SS_I)

mess = test_common_bind.makeCheck("div_ncerr_ss_i", Output_SS_I.val,
                                 TruthOutput_SS_I.val,
                                 Output_SS_I.val_err2,
                                 TruthOutput_SS_I.val_err2)
print mess

##
# \} // end of test_div_ncerr group
#
