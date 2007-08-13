###############################################################################
#
# Testing script for Swig bindings for fit_linear_background functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_fit_linear_background.py
#

##
# \defgroup test_fit_linear_background pbl::test_fit_linear_background
# \{
#

from nessi_vector_bind import *
from utils_bind import fit_linear_background_d
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "######################################################################"
print "# Checking Fit_Linear_Background Swig Generated Python Binding Layer #"
print "######################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Axis1_D = DoubleNessiVector()
Input1_D = DoubleNessiVector()
Input1_Err2_D = DoubleNessiVector()

Axis1_D.append(float(1.0));
Axis1_D.append(float(2.0));
Axis1_D.append(float(3.0));
Axis1_D.append(float(4.0));
Axis1_D.append(float(5.0));

Input1_D.append(float(3.05));
Input1_D.append(float(4.95));
Input1_D.append(float(7.02));
Input1_D.append(float(9.01));
Input1_D.append(float(10.97));

Input1_Err2_D.append(float(0.11));
Input1_Err2_D.append(float(0.1));
Input1_Err2_D.append(float(0.09));
Input1_Err2_D.append(float(0.1));
Input1_Err2_D.append(float(0.12));

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth information for fit_linear_background
TruthOutput_Slope_D = DoubleVPair()
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_Slope_D.val = float(1.99098429157316548)
else:
    TruthOutput_Slope_D.val = float(1.99098429157316348)
TruthOutput_Slope_D.val_err2 = float(1.11545306817302532e-02)

TruthOutput_Intercept_D = DoubleVPair()
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_Intercept_D.val = float(1.02731718641181979)
else:
    TruthOutput_Intercept_D.val = float(1.02731718641181557)
TruthOutput_Intercept_D.val_err2 = float(1.18915886404085791e-01)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for fit_linear_background
Output_Slope_D = DoubleVPair()
Output_Intercept_D = DoubleVPair()

print "Checking Fit Linear Background Binding Function"

fit_linear_background_d(Axis1_D, Input1_D, Input1_Err2_D, 0, 0,
                        Output_Slope_D, Output_Intercept_D)

mess = test_common_bind.makeCheck("fit_linear_background_d (slope)",
                                  Output_Slope_D.val,
                                  TruthOutput_Slope_D.val,
                                  Output_Slope_D.val_err2,
                                  TruthOutput_Slope_D.val_err2)

print mess

mess = test_common_bind.makeCheck("fit_linear_background_d (intercept)",
                                  Output_Intercept_D.val,
                                  TruthOutput_Intercept_D.val,
                                  Output_Intercept_D.val_err2,
                                  TruthOutput_Intercept_D.val_err2)

print mess

##
# \} // end of test_fit_linear_background group
#

