###############################################################################
#
# Testing script for Swig bindings for sumw_ncerr functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_sumw_ncerr.py
#

##
# \defgroup test_sumw_ncerr pbl::test_sumw_ncerr
# \{
#

from array_manip_bind import sumw_ncerr_d
from array_manip_bind import sumw_ncerr_i
from nessi_vector_bind import *
import test_common_bind

print "###########################################################"
print "# Checking Sumw_Ncerr Swig Generated Python Binding Layer #"
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
    Input1_D.append(float(NUM_VAL+1-counter))
    Input1_Err2_D.append(float(1))
    Input1_I.append(NUM_VAL+1-counter)
    Input1_Err2_I.append(1)
    Input2_D.append(float(counter))
    Input2_Err2_D.append(float(1))
    Input2_I.append(counter)
    Input2_Err2_I.append(1)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for sumw_ncerr vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(6.0)
TruthOutput_VV_D.append(6.0)
TruthOutput_VV_D.append(6.0)
TruthOutput_VV_D.append(6.0)
TruthOutput_VV_D.append(6.0)

TruthOutput_VV_I = IntNessiVector()
TruthOutput_VV_I.append(6)
TruthOutput_VV_I.append(6)
TruthOutput_VV_I.append(6)
TruthOutput_VV_I.append(6)
TruthOutput_VV_I.append(6)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(4.0)
TruthOutput_Err2_VV_D.append(4.0)
TruthOutput_Err2_VV_D.append(4.0)
TruthOutput_Err2_VV_D.append(4.0)
TruthOutput_Err2_VV_D.append(4.0)

TruthOutput_Err2_VV_I = IntNessiVector()
TruthOutput_Err2_VV_I.append(4)
TruthOutput_Err2_VV_I.append(4)
TruthOutput_Err2_VV_I.append(4)
TruthOutput_Err2_VV_I.append(4)
TruthOutput_Err2_VV_I.append(4)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for sumw_ncerr vector-vector version
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_VV_I = IntNessiVector(len(Input1_I))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))
Output_Err2_VV_I = IntNessiVector(len(Input1_Err2_I))

print "Checking Vector-Vector Sum Weighted by Uncertainties Binding Function"

sumw_ncerr_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
            Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("sumw_ncerr_d", Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess

sumw_ncerr_i(Input1_I, Input1_Err2_I, Input2_I, Input2_Err2_I,
            Output_VV_I, Output_Err2_VV_I)

mess = test_common_bind.makeCheck("sumw_ncerr_i", Output_VV_I,
                                  TruthOutput_VV_I,
                                  Output_Err2_VV_I,
                                  TruthOutput_Err2_VV_I)
print mess

##
# \} // end of test_sumw_ncerr group
#
