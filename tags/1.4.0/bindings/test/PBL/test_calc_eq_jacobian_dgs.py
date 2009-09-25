###############################################################################
#
# Testing script for Swig bindings for calc_eq_jacobian_dgs functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_calc_eq_jacobian_dgs.py
#

##
# \defgroup test_calc_eq_jacobian_dgs pbl::test_calc_eq_jacobian_dgs
# \{
#

from utils_bind import calc_eq_jacobian_dgs_d
from nessi_vector_bind import *
import test_common_bind

print "######################################################################"
print "# Checking Calc_EQ_Jacobian_DGS Swig Generated Python Binding Layer  #"
print "######################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
E1_Axis_D = DoubleNessiVector()
E2_Axis_D = DoubleNessiVector()
E3_Axis_D = DoubleNessiVector()
E4_Axis_D = DoubleNessiVector()
Q1_Axis_D = DoubleNessiVector()
Q2_Axis_D = DoubleNessiVector()
Q3_Axis_D = DoubleNessiVector()
Q4_Axis_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    E1_Axis_D.append(float(counter))
    E2_Axis_D.append(float(counter+1))
    E3_Axis_D.append(float(counter+1.5))
    E4_Axis_D.append(float(counter+0.5))
    Q1_Axis_D.append(float(0.))
    Q2_Axis_D.append(float(0.))
    Q3_Axis_D.append(float(1.))
    Q4_Axis_D.append(float(1.))    

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for calc_eq_jacobian_dgs vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(1.0)
TruthOutput_VV_D.append(1.0)
TruthOutput_VV_D.append(1.0)
TruthOutput_VV_D.append(1.0)
TruthOutput_VV_D.append(1.0)

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for calc_eq_jacobian_dgs vector-vector version
Output_VV_D = DoubleNessiVector(NUM_VAL)

print "Checking Vector-Vector Calculate EQ Jacobian DGS Binding Function"

calc_eq_jacobian_dgs_d(E1_Axis_D, E2_Axis_D, E3_Axis_D, E4_Axis_D,
                       Q1_Axis_D, Q2_Axis_D, Q3_Axis_D, Q4_Axis_D,
                       Output_VV_D)

mess = test_common_bind.makeCheck("calc_eq_jacobian_dgs_d", Output_VV_D,
                                  TruthOutput_VV_D)
print mess

##
# \} // end of test_calc_eq_jacobian_dgs group
#
