###############################################################################
#
# Testing script for Swig bindings for wavelength_to_energy functions
#
# $Id$
#
###############################################################################

##
# \file bindings/PBL/test_wavelength_to_energy.py
#

from axis_manip_bind import wavelength_to_energy_d
from axis_manip_bind import wavelength_to_energy_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "#####################################################################"
print "# Checking Wavelength_to_Energy Swig Generated Python Binding Layer #"
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

# Truth values for wavelength_to_energy vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(81.80420510000000433)
TruthOutput_VV_D.append(20.45105127500000108)
TruthOutput_VV_D.append(9.089356122222222111)
TruthOutput_VV_D.append(5.112762818750000270)
TruthOutput_VV_D.append(3.272168204000000191)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(13383.85594408573342661)
TruthOutput_Err2_VV_D.append(627.3682473790187259510)
TruthOutput_Err2_VV_D.append(91.79599412953177761664)
TruthOutput_Err2_VV_D.append(22.87280068569339164241)
TruthOutput_Err2_VV_D.append(7.709101023793382800874)

# Truth values for wavelength_to_energy scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 81.8042051000000043
TruthOutput_SS_D.val_err2 = 13383.8559440857334266

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for wavelength_to_energy vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for wavelength_to_energy scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Wavelength to Energy Binding Function"

wavelength_to_energy_d(Input_D, Input_Err2_D,
                       Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("wavelength_to_energy_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Wavelength to Energy Binding Function"

wavelength_to_energy_ss_d(Input_D[0], Input_Err2_D[0], Output_SS_D)

mess = test_common_bind.makeCheck("wavelength_to_energy_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess
