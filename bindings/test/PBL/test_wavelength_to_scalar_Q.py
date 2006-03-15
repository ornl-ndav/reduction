###############################################################################
#
# Testing script for Swig bindings for wavelength_to_scalar_Q functions
#
# $Id$
#
###############################################################################

##
# \file bindings/PBL/test_wavelength_to_scalar_Q.py
#

from axis_manip_bind import wavelength_to_scalar_Q_d
from axis_manip_bind import wavelength_to_scalar_Q_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "#######################################################################"
print "# Checking Wavelength_to_Scalar_Q Swig Generated Python Binding Layer #"
print "#######################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
polar_angle = 2.0
polar_angle_err2 = 0.5

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_D.append(float(2*counter+1))
    Input_Err2_D.append(float(counter+0.5))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for wavelength_to_scalar_Q vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(11.42656846417465566)
TruthOutput_VV_D.append(3.80885615472488537)
TruthOutput_VV_D.append(2.28531369283493113)
TruthOutput_VV_D.append(1.63236692345352230)
TruthOutput_VV_D.append(1.26961871824162853)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(32.42559623735466801)
TruthOutput_Err2_VV_D.append(-1.23295104275580614)
TruthOutput_Err2_VV_D.append(-0.79203962036934561)
TruthOutput_Err2_VV_D.append(-0.48023389777822056)
TruthOutput_Err2_VV_D.append(-0.31609808138503581)

# Truth values for wavelength_to_scalar_Q scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 11.42656846417465566
TruthOutput_SS_D.val_err2 = 32.42559623735466801

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for wavelength_to_scalar_Q vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for wavelength_to_scalar_Q scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Wavelength to Scalar Q Binding Function"

wavelength_to_scalar_Q_d(Input_D, Input_Err2_D,
                         polar_angle, polar_angle_err2,
                         Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("wavelength_to_scalar_Q_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Wavelength to Scalar Q Binding Function"

wavelength_to_scalar_Q_ss_d(Input_D[0], Input_Err2_D[0],
                            polar_angle, polar_angle_err2,
                            Output_SS_D)

mess = test_common_bind.makeCheck("wavelength_to_scalar_Q_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess
