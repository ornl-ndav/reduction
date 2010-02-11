###############################################################################
#
# Testing script for Swig bindings for eval_linear_fit functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_eval_linear_fit.py
#

##
# \defgroup test_eval_linear_fit pbl::test_eval_linear_fit
# \{
#

from nessi_vector_bind import *
from utils_bind import eval_linear_fit_d
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "################################################################"
print "# Checking Eval_Linear_Fit Swig Generated Python Binding Layer #"
print "################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
slope = float(1.99098429157316348)
slope_err2 = float(1.11545306817302532e-02)
intercept = float(1.02731718641181557)
intercept_err2 = float(1.18915886404085791e-01)

# Create input vectors
Axis1_D = DoubleNessiVector()
Axis1_Err2_D = DoubleNessiVector()

Axis1_D.append(float(1.0))
Axis1_D.append(float(2.0))
Axis1_D.append(float(3.0))
Axis1_D.append(float(4.0))
Axis1_D.append(float(5.0))

Axis1_Err2_D.append(float(0.))
Axis1_Err2_D.append(float(0.))
Axis1_Err2_D.append(float(0.))
Axis1_Err2_D.append(float(0.))
Axis1_Err2_D.append(float(0.))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth information for eval_linear_fit
TruthOutput_D = DoubleNessiVector()
TruthOutput_D.append(float(3.01830147798497883))
TruthOutput_D.append(float(5.00928576955814275))
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_D.append(float(7.00027006113130579))
else:
    TruthOutput_D.append(float(7.00027006113130668))
TruthOutput_D.append(float(8.99125435270446971))
TruthOutput_D.append(float(10.9822386442776327))

TruthOutput_Err2_D = DoubleNessiVector()
TruthOutput_Err2_D.append(float(1.30070417085816042e-01))
TruthOutput_Err2_D.append(float(1.63534009131006797e-01))
TruthOutput_Err2_D.append(float(2.19306662539658082e-01))
TruthOutput_Err2_D.append(float(2.97388377311769814e-01))
TruthOutput_Err2_D.append(float(3.97779153447342104e-01))

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for eval_linear_fit
Output_D = DoubleNessiVector(NUM_VAL)
Output_Err2_D = DoubleNessiVector(NUM_VAL)

print "Checking Evaluate Linear Fit Binding Function"

eval_linear_fit_d(Axis1_D, Axis1_Err2_D,
                  slope, slope_err2, intercept, intercept_err2,
                  Output_D, Output_Err2_D)

mess = test_common_bind.makeCheck("eval_linear_fit_d",
                                  Output_D, TruthOutput_D,
                                  Output_Err2_D, TruthOutput_Err2_D)

print mess

##
# \} // end of test_eval_linear_fit group
#

