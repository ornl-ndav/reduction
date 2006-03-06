###############################################################################
#
# Testing script for Swig bindings for energy_transfer functions
#
# $Id$
#
###############################################################################

from axis_manip_bind import energy_transfer_f
from axis_manip_bind import energy_transfer_d
from nessi_vector_bind import *
import test_common_bind

print "#################################################################"
print "# Checking Energy_Transfer Swig Generated Python Binding Layer  #"
print "#################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Create input vectors
Input1_F = FloatNessiVector()
Input1_Err2_F = FloatNessiVector()
Input1_D = DoubleNessiVector()
Input1_Err2_D = DoubleNessiVector()
Input2_F = FloatNessiVector()
Input2_Err2_F = FloatNessiVector()
Input2_D = DoubleNessiVector()
Input2_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input1_F.append(float(2*counter))
    Input1_Err2_F.append(float(counter+0.5))
    Input1_D.append(float(2*counter))
    Input1_Err2_D.append(float(counter+0.5))
    Input2_F.append(float(counter+2.5))
    Input2_Err2_F.append(float(counter+1.5))
    Input2_D.append(float(counter+2.5))
    Input2_Err2_D.append(float(counter+1.5))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for energy_transfer vector-vector version
TruthOutput_VV_F = FloatNessiVector()
TruthOutput_VV_F.append(-0.6044973731)
TruthOutput_VV_F.append(-0.3626984059)
TruthOutput_VV_F.append(-0.1208994761)
TruthOutput_VV_F.append(0.1208994761)
TruthOutput_VV_F.append(0.3626984059)

TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(-0.60449734953663813)
TruthOutput_VV_D.append(-0.36269840972198291)
TruthOutput_VV_D.append(-0.12089946990732763)
TruthOutput_VV_D.append(0.120899469907327639)
TruthOutput_VV_D.append(0.362698409721982917)

TruthOutput_Err2_VV_F = FloatNessiVector()
TruthOutput_Err2_VV_F.append(0.1169334575)
TruthOutput_Err2_VV_F.append(0.2338669151)
TruthOutput_Err2_VV_F.append(0.3508003652)
TruthOutput_Err2_VV_F.append(0.4677338302)
TruthOutput_Err2_VV_F.append(0.5846672654)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.11693345459098256)
TruthOutput_Err2_VV_D.append(0.23386690918196512)
TruthOutput_Err2_VV_D.append(0.35080036377294770)
TruthOutput_Err2_VV_D.append(0.46773381836393024)
TruthOutput_Err2_VV_D.append(0.58466727295491283)


# Truth values for energy_transfer vector-scalar version
TruthOutput_VS_F = FloatNessiVector()
TruthOutput_VS_F.append(-0.6044973731)
TruthOutput_VS_F.append(-0.1208994761)
TruthOutput_VS_F.append(0.3626984059)
TruthOutput_VS_F.append(0.8462963104)
TruthOutput_VS_F.append(1.3298941850)

TruthOutput_VS_D = DoubleNessiVector()
TruthOutput_VS_D.append(-0.60449734953663813)
TruthOutput_VS_D.append(-0.12089946990732763)
TruthOutput_VS_D.append(0.362698409721982917)
TruthOutput_VS_D.append(0.846296289351293418)
TruthOutput_VS_D.append(1.329894168980604085)

TruthOutput_Err2_VS_F = FloatNessiVector()
TruthOutput_Err2_VS_F.append(0.1169334575)
TruthOutput_Err2_VS_F.append(0.1754001826)
TruthOutput_Err2_VS_F.append(0.2338669151)
TruthOutput_Err2_VS_F.append(0.2923336327)
TruthOutput_Err2_VS_F.append(0.3508003652)

TruthOutput_Err2_VS_D = DoubleNessiVector()
TruthOutput_Err2_VS_D.append(0.11693345459098256)
TruthOutput_Err2_VS_D.append(0.17540018188647385)
TruthOutput_Err2_VS_D.append(0.23386690918196512)
TruthOutput_Err2_VS_D.append(0.29233363647745641)
TruthOutput_Err2_VS_D.append(0.35080036377294770)

# Truth values for energy_transfer scalar-vector version
TruthOutput_SV_F = FloatNessiVector()
TruthOutput_SV_F.append(-0.6044973731)
TruthOutput_SV_F.append(-0.8462963104)
TruthOutput_SV_F.append(-1.0880953073)
TruthOutput_SV_F.append(-1.3298941850)
TruthOutput_SV_F.append(-1.5716931819)

TruthOutput_SV_D = DoubleNessiVector()
TruthOutput_SV_D.append(-0.60449734953663813)
TruthOutput_SV_D.append(-0.84629628935129341)
TruthOutput_SV_D.append(-1.088095229165948696)
TruthOutput_SV_D.append(-1.32989416898060408)
TruthOutput_SV_D.append(-1.57169310879525925)

TruthOutput_Err2_SV_F = FloatNessiVector()
TruthOutput_Err2_SV_F.append(0.1169334575)
TruthOutput_Err2_SV_F.append(0.1754001826)
TruthOutput_Err2_SV_F.append(0.2338669151)
TruthOutput_Err2_SV_F.append(0.2923336327)
TruthOutput_Err2_SV_F.append(0.3508003652)

TruthOutput_Err2_SV_D = DoubleNessiVector()
TruthOutput_Err2_SV_D.append(0.11693345459098256)
TruthOutput_Err2_SV_D.append(0.17540018188647385)
TruthOutput_Err2_SV_D.append(0.23386690918196512)
TruthOutput_Err2_SV_D.append(0.29233363647745641)
TruthOutput_Err2_SV_D.append(0.35080036377294770)

# Truth values for energy_transfer scalar-scalar version
TruthOutput_SS_F = -0.6044973731

TruthOutput_SS_D = -0.60449734953663813

TruthOutput_Err2_SS_F = 0.1169334575

TruthOutput_Err2_SS_D = 0.11693345459098256

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for energy_transfer vector-vector version
Output_VV_F = FloatNessiVector(len(Input1_F))
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_Err2_VV_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for energy_transfer vector-scalar version
Output_VS_F = FloatNessiVector(len(Input1_F))
Output_VS_D = DoubleNessiVector(len(Input1_D))
Output_Err2_VS_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_VS_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for energy_transfer scalar-vector version
Output_SV_F = FloatNessiVector(len(Input1_F))
Output_SV_D = DoubleNessiVector(len(Input1_D))
Output_Err2_SV_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_SV_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for energy_transfer scalar-scalar version
Output_SS_F = 0.0
Output_SS_D = 0.0
Output_Err2_SS_F = 0.0
Output_Err2_SS_D = 0.0

print "Checking Vector-Vector Energy Transfer Binding Function"

energy_transfer_f(Input1_F, Input1_Err2_F, Input2_F, Input2_Err2_F,
                  Output_VV_F, Output_Err2_VV_F)

mess = test_common_bind.makeCheck("energy_transfer_f", Output_VV_F,
                                  TruthOutput_VV_F,
                                  Output_Err2_VV_F,
                                  TruthOutput_Err2_VV_F)
print mess

energy_transfer_d(Input1_D, Input1_Err2_D, Input2_D, Input2_Err2_D,
                  Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("energy_transfer_d", Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Vector-Scalar Energy Transfer Binding Function"

energy_transfer_f(Input1_F, Input1_Err2_F, Input2_F[0], Input2_Err2_F[0],
                  Output_VS_F, Output_Err2_VS_F)

mess = test_common_bind.makeCheck("energy_transfer_f", Output_VS_F,
                                  TruthOutput_VS_F,
                                  Output_Err2_VS_F,
                                  TruthOutput_Err2_VS_F)
print mess

energy_transfer_d(Input1_D, Input1_Err2_D, Input2_D[0], Input2_Err2_D[0],
                  Output_VS_D, Output_Err2_VS_D)

mess = test_common_bind.makeCheck("energy_transfer_d", Output_VS_D,
                                  TruthOutput_VS_D,
                                  Output_Err2_VS_D,
                                  TruthOutput_Err2_VS_D)
print mess
print
print "Checking Scalar-Vector Energy Transfer Binding Function"

energy_transfer_f(Input1_F[0], Input1_Err2_F[0], Input2_F, Input2_Err2_F,
                  Output_SV_F, Output_Err2_SV_F)

mess = test_common_bind.makeCheck("energy_transfer_f", Output_SV_F,
                                  TruthOutput_SV_F,
                                  Output_Err2_SV_F,
                                  TruthOutput_Err2_SV_F)
print mess

energy_transfer_d(Input1_D[0], Input1_Err2_D[0], Input2_D, Input2_Err2_D,
                  Output_SV_D, Output_Err2_SV_D)

mess = test_common_bind.makeCheck("energy_transfer_d", Output_SV_D,
                                  TruthOutput_SV_D,
                                  Output_Err2_SV_D,
                                  TruthOutput_Err2_SV_D)
print mess
print
print "Checking Scalar-Scalar Energy Transfer Binding Function"

energy_transfer_f(Input1_F[0], Input1_Err2_F[0], Input2_F[0], Input2_Err2_F[0],
                  Output_SS_F, Output_Err2_SS_F)

#mess = test_common_bind.makeCheck("energy_transfer_f", Output_SS_F,
#                                  TruthOutput_SS_F,
#                                  Output_Err2_SS_F,
#                                  TruthOutput_Err2_SS_F)
#print mess

energy_transfer_d(Input1_D[0], Input1_Err2_D[0], Input2_D[0], Input2_Err2_D[0],
                  Output_SS_D, Output_Err2_SS_D)

#mess = test_common_bind.makeCheck("energy_transfer_d", Output_SS_D,
#                                  TruthOutput_SS_D,
#                                  Output_Err2_SS_D,
#                                  TruthOutput_Err2_SS_D)
#print mess
