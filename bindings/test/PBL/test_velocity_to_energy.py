###############################################################################
#
# Testing script for Swig bindings for velocity_to_energy functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_velocity_to_energy.py
#

##
# \defgroup test_velocity_to_energy pbl::test_velocity_to_energy
# \{
#

from axis_manip_bind import velocity_to_energy_d
from axis_manip_bind import velocity_to_energy_ss_d
from nessi_vector_bind import *
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "#######################################################################"
print "# Checking Velocity_to_Energy Swig Generated Python Binding Layer     #"
print "#######################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_D.append(float(counter*0.001))
    Input_Err2_D.append(float(counter*0.001))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for velocity_to_energy vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(0.00000000000000000)
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_VV_D.append(5.22699330000000001)
    TruthOutput_VV_D.append(20.90797320000000003)
else:
    TruthOutput_VV_D.append(5.22699329999999912)
    TruthOutput_VV_D.append(20.90797319999999645)

TruthOutput_VV_D.append(47.04293970000000000)
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_VV_D.append(83.63189280000000000)
else:
    TruthOutput_VV_D.append(83.63189279999998579)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.00000000000000000)
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_Err2_VV_D.append(109285.83583297956344255)
    TruthOutput_Err2_VV_D.append(874286.68666383646566129)
else:
    TruthOutput_Err2_VV_D.append(109285.83583297954889063)
    TruthOutput_Err2_VV_D.append(874286.68666383634924597)
TruthOutput_Err2_VV_D.append(2950717.56749044767169357)
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_Err2_VV_D.append(6994293.49331069186264514)
else:
    TruthOutput_Err2_VV_D.append(6994293.49331069093132257)

# Truth values for velocity_to_energy scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 0.00000000000000000
TruthOutput_SS_D.val_err2 = 0.00000000000000000

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for velocity_to_energy vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for velocity_to_energy scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Velocity to Energy Binding Function"

velocity_to_energy_d(Input_D, Input_Err2_D,
                     Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("velocity_to_energy_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Velocity to Energy Binding Function"

velocity_to_energy_ss_d(Input_D[0], Input_Err2_D[0], Output_SS_D)

mess = test_common_bind.makeCheck("velocity_to_energy_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_velocity_to_energy group
#
