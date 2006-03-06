###############################################################################
#
# Testing script for Swig bindings for init_scatt_wavevector_to_scalar_Q
# functions
#
# $Id$
#
###############################################################################

from axis_manip_bind import init_scatt_wavevector_to_scalar_Q_f
from axis_manip_bind import init_scatt_wavevector_to_scalar_Q_d
from nessi_vector_bind import *
import test_common_bind

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
    Input1_F.append(float(counter+1))
    Input1_Err2_F.append(float(counter+0.5))
    Input1_D.append(float(counter+1))
    Input1_Err2_D.append(float(counter+0.5))
    Input2_F.append(float(counter+1.25))
    Input2_Err2_F.append(float(counter+0.25))
    Input2_D.append(float(counter+1.25))
    Input2_Err2_D.append(float(counter+0.25))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for init_scatt_wavevector_to_scalar_Q vector-vector version
TruthOutput_VV_F = FloatNessiVector()
TruthOutput_VV_F.append(0.3503661155)
TruthOutput_VV_F.append(0.5286048650)
TruthOutput_VV_F.append(0.7297254800)
TruthOutput_VV_F.append(0.9391418099)
TruthOutput_VV_F.append(1.1523394584)

TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(0.35036606096122696)
TruthOutput_VV_D.append(0.52860472569260141)
TruthOutput_VV_D.append(0.72972579648330349)
TruthOutput_VV_D.append(0.93914148175842626)
TruthOutput_VV_D.append(1.15233845294826764)

TruthOutput_Err2_VV_F = FloatNessiVector()
TruthOutput_Err2_VV_F.append(0.4165994822)
TruthOutput_Err2_VV_F.append(0.9832010269)
TruthOutput_Err2_VV_F.append(1.512506723)
TruthOutput_Err2_VV_F.append(2.2451405525)
TruthOutput_Err2_VV_F.append(3.2094576355)

TruthOutput_Err2_VV_D = DoubleNessiVector()
TruthOutput_Err2_VV_D.append(0.41659964378851194)
TruthOutput_Err2_VV_D.append(0.98320158587954031)
TruthOutput_Err2_VV_D.append(1.51250520438527535)
TruthOutput_Err2_VV_D.append(2.24514211944373531)
TruthOutput_Err2_VV_D.append(3.20946303556517609)

# Truth values for init_scatt_wavevector_to_scalar_Q vector-scalar version
TruthOutput_VS_F = FloatNessiVector()
TruthOutput_VS_F.append(0.3503661155)
TruthOutput_VS_F.append(0.8264459371)
TruthOutput_VS_F.append(1.8009078502)
TruthOutput_VS_F.append(2.7934792041)
TruthOutput_VS_F.append(3.7899582386)

TruthOutput_VS_D = DoubleNessiVector()
TruthOutput_VS_D.append(0.35036606096122696)
TruthOutput_VS_D.append(0.82644585627067690)
TruthOutput_VS_D.append(1.80090786272381464)
TruthOutput_VS_D.append(2.79347910439543900)
TruthOutput_VS_D.append(3.78995803187415658)

TruthOutput_Err2_VS_F = FloatNessiVector()
TruthOutput_Err2_VS_F.append(0.4165994822)
TruthOutput_Err2_VS_F.append(1.5647885799)
TruthOutput_Err2_VS_F.append(2.6823163032)
TruthOutput_Err2_VS_F.append(3.7089958190)
TruthOutput_Err2_VS_F.append(4.7202110290)

TruthOutput_Err2_VS_D = DoubleNessiVector()
TruthOutput_Err2_VS_D.append(0.41659964378851194)
TruthOutput_Err2_VS_D.append(1.56478867463881377)
TruthOutput_Err2_VS_D.append(2.68231593112614863)
TruthOutput_Err2_VS_D.append(3.70899611257809613)
TruthOutput_Err2_VS_D.append(4.72021164820286465)

# Truth values for init_scatt_wavevector_to_scalar_Q scalar-vector version
TruthOutput_SV_F = FloatNessiVector()
TruthOutput_SV_F.append(0.3503661155)
TruthOutput_SV_F.append(1.2926567518)
TruthOutput_SV_F.append(2.2845494747)
TruthOutput_SV_F.append(3.2813673019)
TruthOutput_SV_F.append(4.2796702384)

TruthOutput_SV_D = DoubleNessiVector()
TruthOutput_SV_D.append(0.35036606096122696)
TruthOutput_SV_D.append(1.29265675181475581)
TruthOutput_SV_D.append(2.28454953532442894)
TruthOutput_SV_D.append(3.28136734924480144)
TruthOutput_SV_D.append(4.27967017210773370)

TruthOutput_Err2_SV_F = FloatNessiVector()
TruthOutput_Err2_SV_F.append(0.4165994822)
TruthOutput_Err2_SV_F.append(1.6581019042)
TruthOutput_Err2_SV_F.append(2.6918807029)
TruthOutput_Err2_SV_F.append(3.7044682502)
TruthOutput_Err2_SV_F.append(4.7109990119)

TruthOutput_Err2_SV_D = DoubleNessiVector()
TruthOutput_Err2_SV_D.append(0.41659964378851194)
TruthOutput_Err2_SV_D.append(1.65810190421910097)
TruthOutput_Err2_SV_D.append(2.69188033991111108)
TruthOutput_Err2_SV_D.append(3.70446789959436140)
TruthOutput_Err2_SV_D.append(4.71099862050503759)

# Truth values for init_scatt_wavevector_to_scalar_Q scalar-scalar version
TruthOutput_SS_F = 0.3503661155

TruthOutput_SS_D = 0.35036606096122696

TruthOutput_Err2_SS_F = 0.4165994822

TruthOutput_Err2_SS_D = 0.41659964378851194

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for init_scatt_wavevector_to_scalar_Q vector-vector
# version
Output_VV_F = FloatNessiVector(len(Input1_F))
Output_VV_D = DoubleNessiVector(len(Input1_D))
Output_Err2_VV_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_VV_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for init_scatt_wavevector_to_scalar_Q vector-scalar
# version
Output_VS_F = FloatNessiVector(len(Input1_F))
Output_VS_D = DoubleNessiVector(len(Input1_D))
Output_Err2_VS_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_VS_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for init_scatt_wavevector_to_scalar_Q scalar-vector
# version
Output_SV_F = FloatNessiVector(len(Input1_F))
Output_SV_D = DoubleNessiVector(len(Input1_D))
Output_Err2_SV_F = FloatNessiVector(len(Input1_Err2_F))
Output_Err2_SV_D = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for init_scatt_wavevector_to_scalar_Q scalar-scalar
# version
Output_SS_F = 0.0
Output_SS_D = 0.0
Output_Err2_SS_F = 0.0
Output_Err2_SS_D = 0.0

print "Checking Vector-Vector Initial and Scattering Wavevector to Scalar Q"
print "Binding Function"

init_scatt_wavevector_to_scalar_Q_f(Input1_F, Input1_Err2_F,
                                    Input2_F, Input2_Err2_F,
                                    polar_angle, polar_angle_err2,
                                    Output_VV_F, Output_Err2_VV_F)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_scalar_Q_f",
                                  Output_VV_F,
                                  TruthOutput_VV_F,
                                  Output_Err2_VV_F,
                                  TruthOutput_Err2_VV_F)
print mess

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

init_scatt_wavevector_to_scalar_Q_f(Input1_F, Input1_Err2_F,
                                    Input2_F[0], Input2_Err2_F[0],
                                    polar_angle, polar_angle_err2,
                                    Output_VS_F, Output_Err2_VS_F)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_scalar_Q_f",
                                  Output_VS_F,
                                  TruthOutput_VS_F,
                                  Output_Err2_VS_F,
                                  TruthOutput_Err2_VS_F)
print mess

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

init_scatt_wavevector_to_scalar_Q_f(Input1_F[0], Input1_Err2_F[0],
                                    Input2_F, Input2_Err2_F,
                                    polar_angle, polar_angle_err2,
                                    Output_SV_F, Output_Err2_SV_F)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_scalar_Q_f",
                                  Output_SV_F,
                                  TruthOutput_SV_F,
                                  Output_Err2_SV_F,
                                  TruthOutput_Err2_SV_F)
print mess

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

init_scatt_wavevector_to_scalar_Q_f(Input1_F[0], Input1_Err2_F[0],
                                    Input2_F[0], Input2_Err2_F[0],
                                    polar_angle, polar_angle_err2,
                                    Output_SS_F, Output_Err2_SS_F)

#mess = test_common_bind.makeCheck("init_scatt_wavevector_to_scalar_Q_f",
#Output_SS_F,
#                                  TruthOutput_SS_F,
#                                  Output_Err2_SS_F,
#                                  TruthOutput_Err2_SS_F)
#print mess

init_scatt_wavevector_to_scalar_Q_d(Input1_D[0], Input1_Err2_D[0],
                                    Input2_D[0], Input2_Err2_D[0],
                                    polar_angle, polar_angle_err2,
                                    Output_SS_D, Output_Err2_SS_D)

#mess = test_common_bind.makeCheck("init_scatt_wavevector_to_scalar_Q_d",
#Output_SS_D,
#                                  TruthOutput_SS_D,
#                                  Output_Err2_SS_D,
#                                  TruthOutput_Err2_SS_D)
#print mess
