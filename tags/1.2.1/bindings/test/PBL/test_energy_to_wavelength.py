###############################################################################
#
# Testing script for Swig bindings for wavelength_to_energy functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_energy_to_wavelength.py
#

##
# \defgroup test_energy_to_wavelength pbl::test_energy_to_wavelength
# \{
#

from axis_manip_bind import energy_to_wavelength_d
from axis_manip_bind import energy_to_wavelength_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "#####################################################################"
print "# Checking Energy_to_Wavelength Swig Generated Python Binding Layer #"
print "#####################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_D.append(float(counter+1))
    Input_Err2_D.append(float(counter+0.5))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for energy_to_wavelength vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(9.04456771216844935)
TruthOutput_VV_D.append(6.39547516217520773)
TruthOutput_VV_D.append(5.22188360332425106)
TruthOutput_VV_D.append(4.52228385608422467)
TruthOutput_VV_D.append(4.04485364630168043)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(10.2255256375000005)
TruthOutput_Err2_VV_D.append(3.83457211406250043)
TruthOutput_Err2_VV_D.append(1.89361585879629635)
TruthOutput_Err2_VV_D.append(1.11841686660156259)
TruthOutput_Err2_VV_D.append(0.736237845899999965)

# Truth values for energy_to_wavelength scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 9.04456771216844935
TruthOutput_SS_D.val_err2 = 10.2255256375000005

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for energy_to_wavelength vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for energy_to_wavelength scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Energy to Wavelength Binding Function"

energy_to_wavelength_d(Input_D, Input_Err2_D,
                       Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("energy_to_wavelength_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Energy to Wavelength Binding Function"

energy_to_wavelength_ss_d(Input_D[0], Input_Err2_D[0], Output_SS_D)

mess = test_common_bind.makeCheck("energy_to_wavelength_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_energy_to_wavelength group
#
