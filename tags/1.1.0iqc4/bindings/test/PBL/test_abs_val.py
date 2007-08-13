###############################################################################
#
# Testing script for Swig bindings for abs_val functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_abs_val.py
#

##
# \defgroup test_abs_val pbl::test_abs_val
# \{
#

from array_manip_bind import abs_val_d
from array_manip_bind import abs_val_i
from nessi_vector_bind import *
import test_common_bind

print "##############################################################"
print "# Checking Abs_Val Swig Generated Python Binding Layer       #"
print "##############################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input_D = DoubleNessiVector()
Input_I = IntNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_D.append(-1.0*float(counter+1))
    Input_I.append(-1*(counter+1))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for abs_val vector-vector version
TruthOutput_D = DoubleNessiVector()
TruthOutput_D.append(1.)
TruthOutput_D.append(2.)
TruthOutput_D.append(3.)
TruthOutput_D.append(4.)
TruthOutput_D.append(5.)

TruthOutput_I = IntNessiVector()
TruthOutput_I.append(1)
TruthOutput_I.append(2)
TruthOutput_I.append(3)
TruthOutput_I.append(4)
TruthOutput_I.append(5)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for abs_val vector-vector version
Output_D = DoubleNessiVector(len(Input_D))
Output_I = IntNessiVector(len(Input_I))

print "Checking Vector-Vector Absolute Value Binding Function"

abs_val_d(Input_D, Output_D)

mess = test_common_bind.makeCheck("abs_val_d", Output_D, TruthOutput_D)

print mess

abs_val_i(Input_I, Output_I)

mess = test_common_bind.makeCheck("abs_val_i", Output_I, TruthOutput_I)

print mess

##
# \} // end of test_abs_val group
#
