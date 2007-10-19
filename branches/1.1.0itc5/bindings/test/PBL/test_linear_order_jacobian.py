###############################################################################
#
# Testing script for Swig bindings for linear_order_jacobian functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_linear_order_jacobian.py
#

##
# \defgroup test_linear_order_jacobian pbl::test_linear_order_jacobian
# \{
#

from utils_bind import linear_order_jacobian_d
from utils_bind import linear_order_jacobian_ss_d
from nessi_vector_bind import *
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "#######################################################################"
print "# Checking Linear_Order_Jacobian Swig Generated Python Binding Layer  #"
print "#######################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input1_D = DoubleNessiVector()
Input1_Err2_D = DoubleNessiVector()
AxisIn_D = DoubleNessiVector()
AxisOut_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input1_D.append(float((counter+1) * 10))
    Input1_Err2_D.append(float((counter+1) * 2))
    AxisIn_D.append(float(counter+1))
    AxisOut_D.append(float((counter+1) * 1.1))

AxisIn_D.append(float(NUM_VAL+1))
AxisOut_D.append(float((NUM_VAL+1) * 1.1))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for linear_order_jacobian vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(9.09090909090908994)
TruthOutput_VV_D.append(18.1818181818181799)
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_VV_D.append(27.2727272727272698)
else:
    TruthOutput_VV_D.append(27.2727272727272728)
TruthOutput_VV_D.append(36.3636363636363740)
TruthOutput_VV_D.append(45.4545454545454319)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(1.65289256198347090)
TruthOutput_Err2_VV_D.append(3.30578512396694180)
TruthOutput_Err2_VV_D.append(4.95867768595041269)
TruthOutput_Err2_VV_D.append(6.61157024793388892)
TruthOutput_Err2_VV_D.append(8.26446280991734739)

# Truth values for linear_order_jacobian scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 9.09090909090908994
TruthOutput_SS_D.val_err2 = 1.65289256198347090

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for linear_order_jacobian vector-vector version
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for linear_order_jacobian scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Linear Order Jacobian Binding Function"

linear_order_jacobian_d(AxisIn_D, AxisOut_D,
                        Input1_D, Input1_Err2_D,
                        Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("linear_order_jacobian_d", Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Linear Order Jacobian Binding Function"

linear_order_jacobian_ss_d(AxisIn_D[0], AxisIn_D[1],
                           AxisOut_D[0], AxisOut_D[1],
                           Input1_D[0], Input1_Err2_D[0],
                           Output_SS_D)

mess = test_common_bind.makeCheck("linear_order_jacobian_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)
print mess

##
# \} // end of test_linear_order_jacobian group
#
