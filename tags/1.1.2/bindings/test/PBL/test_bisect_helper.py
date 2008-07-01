###############################################################################
#
# Testing script for Swig bindings for bisect_helper functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_bisect_helper.py
#

##
# \defgroup test_bisect_helper pbl::test_bisect_helper
# \{
#

from nessi_vector_bind import *
from utils_bind import bisect_helper_d
import test_common_bind
from vpair_bind import *

print "##############################################################"
print "# Checking Bisect_Helper Swig Generated Python Binding Layer #"
print "##############################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input_D = DoubleNessiVector()

for counter in range(NUM_VAL):
    Input_D.append(float(counter))

# Set search values
Value1_D = float(-1.3)
Value2_D = float(1.4)
Value3_D = float(2.0)
Value4_D = float(5.7)

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth information for bisect_helper
TruthOutput1_S = SizetVPair()
TruthOutput1_S.val = 0

TruthOutput2_S = SizetVPair()
TruthOutput2_S.val = 1

TruthOutput3_S = SizetVPair()
TruthOutput3_S.val = 2

TruthOutput4_S = SizetVPair()
TruthOutput4_S.val = 3

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for bisect_helper
Output1_S = SizetVPair()
Output2_S = SizetVPair()
Output3_S = SizetVPair()
Output4_S = SizetVPair()

print "Checking Bisection Helper Binding Function"

bisect_helper_d(Input_D, Value1_D, Output1_S)

mess = test_common_bind.makeCheck("bisect_helper_d",
                                  Output1_S.val,
                                  TruthOutput1_S.val)

print mess

bisect_helper_d(Input_D, Value2_D, Output2_S)

mess = test_common_bind.makeCheck("bisect_helper_d",
                                  Output2_S.val,
                                  TruthOutput2_S.val)

print mess

bisect_helper_d(Input_D, Value3_D, Output3_S)

mess = test_common_bind.makeCheck("bisect_helper_d",
                                  Output3_S.val,
                                  TruthOutput3_S.val)

print mess

bisect_helper_d(Input_D, Value4_D, Output4_S)

mess = test_common_bind.makeCheck("bisect_helper_d",
                                  Output4_S.val,
                                  TruthOutput4_S.val)

print mess

##
# \} // end of test_bisect_helper group
#

