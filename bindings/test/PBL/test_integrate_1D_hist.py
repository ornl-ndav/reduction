###############################################################################
#
# Testing script for Swig bindings for integrate_1D_hist functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_integrate_1D_hist.py
#

##
# \defgroup test_integrate_1D_hist pbl::test_integrate_1D_hist
# \{
#

from utils_bind import integrate_1D_hist_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "###################################################################"
print "# Checking Integrate_1D_Hist Swig Generated Python Binding Layer  #"
print "###################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
min_int = 1.6
max_int = 2.9

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()
Axis_D = DoubleNessiVector()
Axis_BW_D = DoubleNessiVector()

Axis_D.append(1.0)
Axis_D.append(1.5)
Axis_D.append(2.0)
Axis_D.append(2.5)
Axis_D.append(3.0)
Axis_D.append(3.5)

Axis_BW_D.append(0.5)
Axis_BW_D.append(0.5)
Axis_BW_D.append(0.5)
Axis_BW_D.append(0.5)
Axis_BW_D.append(0.5)

Input_D.append(30.0)
Input_D.append(20.0)
Input_D.append(10.0)
Input_D.append(20.0)
Input_D.append(30.0)

Input_Err2_D.append(4.0)
Input_Err2_D.append(3.0)
Input_Err2_D.append(2.0)
Input_Err2_D.append(3.0)
Input_Err2_D.append(4.0)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth information for integrate_1D_hist full integration
TruthOutput_D = DoubleVPair()
TruthOutput_D.val = 110.0
TruthOutput_D.val_err2 = 16.0

# Truth information for integrate_1D_hist full integration with width removal
TruthOutput_W_D = DoubleVPair()
TruthOutput_W_D.val = 55.0
TruthOutput_W_D.val_err2 = 4.0

# Truth information for integrate_1D_hist range integration
TruthOutput_R_D = DoubleVPair()
TruthOutput_R_D.val = 50.0
TruthOutput_R_D.val_err2 = 8.0

# Truth information for integrate_1D_hist range integration with width removal
TruthOutput_RW_D = DoubleVPair()
TruthOutput_RW_D.val = 25.0
TruthOutput_RW_D.val_err2 = 2.0

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for integrate_1D_hist full integration
Output_D = DoubleVPair()

# Output placeholders for integrate_1D_hist full integration with width removal
Output_W_D = DoubleVPair()

# Output placeholders for integrate_1D_hist range integration
Output_R_D = DoubleVPair()

# Output placeholders for integrate_1D_hist range integration with width
# removal
Output_RW_D = DoubleVPair()

print "Checking Integration of 1D Histogram (Full) Function"

integrate_1D_hist_d(Input_D, Input_Err2_D, Axis_D,
                    float('inf'), float('inf'), False,
                    Axis_BW_D, Output_D)

mess = test_common_bind.makeCheck("integrate_1D_hist_d",
                                  Output_D.val,
                                  TruthOutput_D.val,
                                  Output_D.val_err2,
                                  TruthOutput_D.val_err2)

print mess

print "Checking Integrate of 1D Histogram (Full & Width) Function"

integrate_1D_hist_d(Input_D, Input_Err2_D, Axis_D,
                    float('inf'), float('inf'), True,
                    Axis_BW_D, Output_W_D)

mess = test_common_bind.makeCheck("integrate_1D_hist_d",
                                  Output_W_D.val,
                                  TruthOutput_W_D.val,
                                  Output_W_D.val_err2,
                                  TruthOutput_W_D.val_err2)

print mess

print "Checking Integrate of 1D Histogram (Range) Function"

integrate_1D_hist_d(Input_D, Input_Err2_D, Axis_D, min_int, max_int, False,
                    Axis_BW_D, Output_R_D)

mess = test_common_bind.makeCheck("integrate_1D_hist_d",
                                  Output_R_D.val,
                                  TruthOutput_R_D.val,
                                  Output_R_D.val_err2,
                                  TruthOutput_R_D.val_err2)

print mess

print "Checking Integrate of 1D Histogram (Range & Width) Function"

integrate_1D_hist_d(Input_D, Input_Err2_D, Axis_D, min_int, max_int, True,
                    Axis_BW_D, Output_RW_D)

mess = test_common_bind.makeCheck("integrate_1D_hist_d",
                                  Output_RW_D.val,
                                  TruthOutput_RW_D.val,
                                  Output_RW_D.val_err2,
                                  TruthOutput_RW_D.val_err2)

print mess

##
# \} // end of test_integrate_1D_hist group
#

