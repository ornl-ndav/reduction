###############################################################################
#
# Testing script for Swig bindings for init_scatt_wavevector_to_scalar_Q
# functions
#
# $Id$
#
###############################################################################

##
# \file bindings/PBL/test_init_scatt_wavevector_to_scalar_Q.py
#

from axis_manip_bind import init_scatt_wavevector_to_scalar_Q_d
from axis_manip_bind import init_scatt_wavevector_to_scalar_Q_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "##############################################"
print "# Checking Init_Scatt_Wavevector_to_Scalar_Q #"
print "# Swig Generated Python Binding Layer        #"
print "##############################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
polar_angle = 0.22
polar_angle_err2 = 0.11

# Create input vectors
Input1_D = DoubleNessiVector()
Input1_Err2_D = DoubleNessiVector()
Input2_D = DoubleNessiVector()
Input2_Err2_D = DoubleNessiVector()

# Place values in the input vectors
for counter in range(NUM_VAL):
    Input1_D.append(float(counter+1))
    Input1_Err2_D.append(float(counter+0.5))
    Input2_D.append(float(counter+1.25))
    Input2_Err2_D.append(float(counter+0.25))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for init_scatt_wavevector_to_scalar_Q vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(0.35036606096122696)
TruthOutput_VV_D.append(0.52860472569260141)
TruthOutput_VV_D.append(0.72972579648330349)
TruthOutput_VV_D.append(0.93914148175842626)
TruthOutput_VV_D.append(1.15233845294826764)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.41659964378851194)
TruthOutput_Err2_VV_D.append(0.98320158587954031)
TruthOutput_Err2_VV_D.append(1.51250520438527535)
TruthOutput_Err2_VV_D.append(2.24514211944373531)
TruthOutput_Err2_VV_D.append(3.20946303556517609)

# Truth values for init_scatt_wavevector_to_scalar_Q vector-scalar version
TruthOutput_VS_D = DoubleNessiVector()
TruthOutput_VS_D.append(0.35036606096122696)
TruthOutput_VS_D.append(0.82644585627067690)
TruthOutput_VS_D.append(1.80090786272381464)
TruthOutput_VS_D.append(2.79347910439543900)
TruthOutput_VS_D.append(3.78995803187415658)

TruthOutput_Err2_VS_D = DoubleNessiVector()
TruthOutput_Err2_VS_D.append(0.41659964378851194)
TruthOutput_Err2_VS_D.append(1.56478867463881377)
TruthOutput_Err2_VS_D.append(2.68231593112614863)
TruthOutput_Err2_VS_D.append(3.70899611257809613)
TruthOutput_Err2_VS_D.append(4.72021164820286465)

# Truth values for init_scatt_wavevector_to_scalar_Q scalar-vector version
TruthOutput_SV_D = DoubleNessiVector()
TruthOutput_SV_D.append(0.35036606096122696)
TruthOutput_SV_D.append(1.29265675181475581)
TruthOutput_SV_D.append(2.28454953532442894)
TruthOutput_SV_D.append(3.28136734924480144)
TruthOutput_SV_D.append(4.27967017210773370)

TruthOutput_Err2_SV_D = DoubleNessiVector()
TruthOutput_Err2_SV_D.append(0.41659964378851194)
TruthOutput_Err2_SV_D.append(1.65810190421910097)
TruthOutput_Err2_SV_D.append(2.69188033991111108)
TruthOutput_Err2_SV_D.append(3.70446789959436140)
TruthOutput_Err2_SV_D.append(4.71099862050503759)

# Truth values for init_scatt_wavevector_to_scalar_Q scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 0.35036606096122696
TruthOutput_SS_D.val_err2 = 0.41659964378851194

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for init_scatt_wavevector_to_scalar_Q vector-vector
# version
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for init_scatt_wavevector_to_scalar_Q vector-scalar
# version
Output_VS_D = DoubleNessiVector(len(Input1_D))
Output_Err2_VS_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for init_scatt_wavevector_to_scalar_Q scalar-vector
# version
Output_SV_D = DoubleNessiVector(len(Input1_D))
Output_Err2_SV_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for init_scatt_wavevector_to_scalar_Q scalar-scalar
# version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Initial and Scattering Wavevector to Scalar Q"
print "Binding Function"

init_scatt_wavevector_to_scalar_Q_d(Input1_D, Input1_Err2_D,
                                    Input2_D, Input2_Err2_D,
                                    polar_angle, polar_angle_err2,
                                    Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_scalar_Q_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Vector-Scalar Initial and Scattering Wavevector to Scalar Q"
print "Binding Function"

init_scatt_wavevector_to_scalar_Q_d(Input1_D, Input1_Err2_D,
                                    Input2_D[0], Input2_Err2_D[0],
                                    polar_angle, polar_angle_err2,
                                    Output_VS_D, Output_Err2_VS_D)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_scalar_Q_d",
                                  Output_VS_D,
                                  TruthOutput_VS_D,
                                  Output_Err2_VS_D,
                                  TruthOutput_Err2_VS_D)
print mess
print
print "Checking Scalar-Vector Initial and Scattering Wavevector to Scalar Q"
print "Binding Function"

init_scatt_wavevector_to_scalar_Q_d(Input1_D[0], Input1_Err2_D[0],
                                    Input2_D, Input2_Err2_D,
                                    polar_angle, polar_angle_err2,
                                    Output_SV_D, Output_Err2_SV_D)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_scalar_Q_d",
                                  Output_SV_D,
                                  TruthOutput_SV_D,
                                  Output_Err2_SV_D,
                                  TruthOutput_Err2_SV_D)
print mess
print
print "Checking Scalar-Scalar Initial and Scattering Wavevector to Scalar Q"
print "Binding Function"

init_scatt_wavevector_to_scalar_Q_ss_d(Input1_D[0], Input1_Err2_D[0],
                                       Input2_D[0], Input2_Err2_D[0],
                                       polar_angle, polar_angle_err2,
                                       Output_SS_D)

mess = test_common_bind.makeCheck2("init_scatt_wavevector_to_scalar_Q_ss_d",
                                   Output_SS_D.val,
                                   TruthOutput_SS_D.val,
                                   Output_SS_D.val_err2,
                                   TruthOutput_SS_D.val_err2)
print mess

