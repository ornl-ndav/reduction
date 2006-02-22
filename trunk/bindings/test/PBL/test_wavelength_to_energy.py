###############################################################################
#
# Testing script for Swig bindings for wavelength_to_energy functions
#
# $Id$
#
###############################################################################

from axis_manip_bind import wavelength_to_energy_f
from axis_manip_bind import wavelength_to_energy_d
from nessi_vector_bind import *
import test_common_bind

print "#####################################################################"
print "# Checking Wavelength_to_Energy Swig Generated Python Binding Layer #"
print "#####################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input_F = FloatNessiVector()
Input_Err2_F = FloatNessiVector()
Input_D = DoubleNessiVector()
Input_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input_F.append(float(counter+1))
    Input_Err2_F.append(float(counter+0.5))
    Input_D.append(float(counter+1))
    Input_Err2_D.append(float(counter+0.5))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for wavelength_to_energy vector-vector version
TruthOutput_VV_F = FloatNessiVector()
TruthOutput_VV_F.append(81.8042068481)
TruthOutput_VV_F.append(20.4510517120)
TruthOutput_VV_F.append(9.08935642242)
TruthOutput_VV_F.append(5.11276292800)
TruthOutput_VV_F.append(3.27216815948)

TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(81.80420510000000433)
TruthOutput_VV_D.append(20.45105127500000108)
TruthOutput_VV_D.append(9.089356122222222111)
TruthOutput_VV_D.append(5.112762818750000270)
TruthOutput_VV_D.append(3.272168204000000191)

TruthOutput_Err2_VV_F = FloatNessiVector()
TruthOutput_Err2_VV_F.append(13383.8564453125)
TruthOutput_Err2_VV_F.append(627.3682861328125)
TruthOutput_Err2_VV_F.append(91.79599761962890)
TruthOutput_Err2_VV_F.append(22.87280082702636)
TruthOutput_Err2_VV_F.append(7.709101676940917)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(13383.85594408573342661)
TruthOutput_Err2_VV_D.append(627.3682473790187259510)
TruthOutput_Err2_VV_D.append(91.79599412953177761664)
TruthOutput_Err2_VV_D.append(22.87280068569339164241)
TruthOutput_Err2_VV_D.append(7.709101023793382800874)

# Truth values for wavelength_to_energy scalar-scalar version
TruthOutput_SS_F = 81.8042068481

TruthOutput_SS_D = 81.8042051000000043

TruthOutput_Err2_SS_F = 13383.8564453125

TruthOutput_Err2_SS_D = 13383.8559440857334266

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for wavelength_to_energy vector-vector version
Output_VV_F = FloatNessiVector(len(Input_F))
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_F = FloatNessiVector(len(Input_Err2_F))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for wavelength_to_energy scalar-scalar version
Output_SS_F = 0.0
Output_SS_D = 0.0
Output_Err2_SS_F = 0.0
Output_Err2_SS_D = 0.0

print "Checking Vector-Vector Wavelength to Energy Binding Function"

wavelength_to_energy_f(Input_F, Input_Err2_F,
                       Output_VV_F, Output_Err2_VV_F)

mess = test_common_bind.makeCheck("wavelength_to_energy_f",
                                  Output_VV_F,
                                  TruthOutput_VV_F,
                                  Output_Err2_VV_F,
                                  TruthOutput_Err2_VV_F)
print mess

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

wavelength_to_energy_f(Input_F[0], Input_Err2_F[0],
                       Output_SS_F, Output_Err2_SS_F)

#mess = test_common_bind.makeCheck("wavelength_to_energy_f",
#Output_SS_F,
#                                  TruthOutput_SS_F,
#                                  Output_Err2_SS_F,
#                                  TruthOutput_Err2_SS_F)
#print mess

wavelength_to_energy_d(Input_D[0], Input_Err2_D[0],
                       Output_SS_D, Output_Err2_SS_D)

#mess = test_common_bind.makeCheck("wavelength_to_energy_d",
#Output_SS_D,
#                                  TruthOutput_SS_D,
#                                  Output_Err2_SS_D,
#                                  TruthOutput_Err2_SS_D)
#print mess
