###############################################################################
#
# Testing script for Swig bindings for init_scatt_wavevector_to_Q
# functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_init_scatt_wavevector_to_Q.py
#

##
# \defgroup test_init_scatt_wavevector_to_Q \
# pbl::test_init_scatt_wavevector_to_Q
# \{
#

from axis_manip_bind import init_scatt_wavevector_to_Q_d
from axis_manip_bind import init_scatt_wavevector_to_Q_ss_d
from nessi_vector_bind import *
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "##############################################"
print "# Checking Init_Scatt_Wavevector_to_Q        #"
print "# Swig Generated Python Binding Layer        #"
print "##############################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
azimuthal_angle = 0.88
azimuthal_angle_err2 = 0.44
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

# Truth values for init_scatt_wavevector_to_Q vector-vector version
TruthOutput_VV_D_Qx = DoubleNessiVector()
TruthOutput_VV_D_Qx.append(-0.17380656755500100)
TruthOutput_VV_D_Qx.append(-0.31285182159900200)
TruthOutput_VV_D_Qx.append(-0.45189707564300253)
TruthOutput_VV_D_Qx.append(-0.59094232968700300)
TruthOutput_VV_D_Qx.append(-0.72998758373100400)

TruthOutput_Err2_VV_D_Qx = DoubleNessiVector()
TruthOutput_Err2_VV_D_Qx.append(0.09073486048493280)
TruthOutput_Err2_VV_D_Qx.append(0.30248772434693300)
TruthOutput_Err2_VV_D_Qx.append(0.62419446317455556)
TruthOutput_Err2_VV_D_Qx.append(1.05585507696780088)
TruthOutput_Err2_VV_D_Qx.append(1.59746956572666845)

TruthOutput_VV_D_Qy = DoubleNessiVector()
TruthOutput_VV_D_Qy.append(-0.21024756879486733)
TruthOutput_VV_D_Qy.append(-0.37844562383076100)
TruthOutput_VV_D_Qy.append(-0.54664367886665500)
TruthOutput_VV_D_Qy.append(-0.71484173390254900)
TruthOutput_VV_D_Qy.append(-0.88303978893844267)

TruthOutput_Err2_VV_D_Qy = DoubleNessiVector()
TruthOutput_Err2_VV_D_Qy.append(0.11760239343867500)
TruthOutput_Err2_VV_D_Qy.append(0.39347961245716444)
TruthOutput_Err2_VV_D_Qy.append(0.81083490764744300)
TruthOutput_Err2_VV_D_Qy.append(1.36966827900951199)
TruthOutput_Err2_VV_D_Qy.append(2.06997972654337000)

TruthOutput_VV_D_Qz = DoubleNessiVector()
TruthOutput_VV_D_Qz.append(-0.21987181166325700)
TruthOutput_VV_D_Qz.append(-0.19576926099386238)
TruthOutput_VV_D_Qz.append(-0.17166671032446800)
if(platform=="linux2" and uname()[4]=="x86_64"):
	TruthOutput_VV_D_Qz.append(-0.14756415965507300)
	TruthOutput_VV_D_Qz.append(-0.12346160898567860)
else:
	TruthOutput_VV_D_Qz.append(-0.1475641596550734)
	TruthOutput_VV_D_Qz.append(-0.1234616089856790)

TruthOutput_Err2_VV_D_Qz = DoubleNessiVector()
TruthOutput_Err2_VV_D_Qz.append(0.74627936184453000)
TruthOutput_Err2_VV_D_Qz.append(2.71699049828466823)
TruthOutput_Err2_VV_D_Qz.append(4.69817895177061088)
TruthOutput_Err2_VV_D_Qz.append(6.68984472230235823)
TruthOutput_Err2_VV_D_Qz.append(8.69198780987991000)

# Truth values for init_scatt_wavevector_to_Q vector-scalar version
TruthOutput_VS_D_Qx = DoubleNessiVector()
TruthOutput_VS_D_Qx.append(-0.17380656755500100)
TruthOutput_VS_D_Qx.append(-0.17380656755500100)
TruthOutput_VS_D_Qx.append(-0.17380656755500100)
TruthOutput_VS_D_Qx.append(-0.17380656755500100)
TruthOutput_VS_D_Qx.append(-0.17380656755500100)

TruthOutput_Err2_VS_D_Qx = DoubleNessiVector()
TruthOutput_Err2_VS_D_Qx.append(0.09073486048493280)
TruthOutput_Err2_VS_D_Qx.append(0.09073486048493280)
TruthOutput_Err2_VS_D_Qx.append(0.09073486048493280)
TruthOutput_Err2_VS_D_Qx.append(0.09073486048493280)
TruthOutput_Err2_VS_D_Qx.append(0.09073486048493280)

TruthOutput_VS_D_Qy = DoubleNessiVector()
TruthOutput_VS_D_Qy.append(-0.21024756879486733)
TruthOutput_VS_D_Qy.append(-0.21024756879486733)
TruthOutput_VS_D_Qy.append(-0.21024756879486733)
TruthOutput_VS_D_Qy.append(-0.21024756879486733)
TruthOutput_VS_D_Qy.append(-0.21024756879486733)

TruthOutput_Err2_VS_D_Qy = DoubleNessiVector()
TruthOutput_Err2_VS_D_Qy.append(0.11760239343867500)
TruthOutput_Err2_VS_D_Qy.append(0.11760239343867500)
TruthOutput_Err2_VS_D_Qy.append(0.11760239343867500)
TruthOutput_Err2_VS_D_Qy.append(0.11760239343867500)
TruthOutput_Err2_VS_D_Qy.append(0.11760239343867500)

TruthOutput_VS_D_Qz = DoubleNessiVector()
TruthOutput_VS_D_Qz.append(-0.21987181166325700)
TruthOutput_VS_D_Qz.append(0.78012818833674300)
TruthOutput_VS_D_Qz.append(1.78012818833674310)
TruthOutput_VS_D_Qz.append(2.78012818833674310)
TruthOutput_VS_D_Qz.append(3.78012818833674310)

TruthOutput_Err2_VS_D_Qz = DoubleNessiVector()
TruthOutput_Err2_VS_D_Qz.append(0.74627936184453000)
TruthOutput_Err2_VS_D_Qz.append(1.74627936184453000)
TruthOutput_Err2_VS_D_Qz.append(2.74627936184453000)
TruthOutput_Err2_VS_D_Qz.append(3.74627936184453000)
TruthOutput_Err2_VS_D_Qz.append(4.74627936184453000)

# Truth values for init_scatt_wavevector_to_Q scalar-vector version
TruthOutput_SV_D_Qx = DoubleNessiVector()
TruthOutput_SV_D_Qx.append(-0.17380656755500100)
TruthOutput_SV_D_Qx.append(-0.31285182159900200)
TruthOutput_SV_D_Qx.append(-0.45189707564300251)
TruthOutput_SV_D_Qx.append(-0.59094232968700300)
TruthOutput_SV_D_Qx.append(-0.72998758373100400)

TruthOutput_Err2_SV_D_Qx = DoubleNessiVector()
TruthOutput_Err2_SV_D_Qx.append(0.09073486048493280)
TruthOutput_Err2_SV_D_Qx.append(0.30248772434693300)
TruthOutput_Err2_SV_D_Qx.append(0.62419446317455556)
TruthOutput_Err2_SV_D_Qx.append(1.05585507696780088)
TruthOutput_Err2_SV_D_Qx.append(1.59746956572666845)

TruthOutput_SV_D_Qy = DoubleNessiVector()
TruthOutput_SV_D_Qy.append(-0.21024756879486733)
TruthOutput_SV_D_Qy.append(-0.37844562383076100)
TruthOutput_SV_D_Qy.append(-0.54664367886665500)
TruthOutput_SV_D_Qy.append(-0.71484173390254900)
TruthOutput_SV_D_Qy.append(-0.88303978893844267)

TruthOutput_Err2_SV_D_Qy = DoubleNessiVector()
TruthOutput_Err2_SV_D_Qy.append(0.11760239343867500)
TruthOutput_Err2_SV_D_Qy.append(0.39347961245716444)
TruthOutput_Err2_SV_D_Qy.append(0.81083490764744300)
TruthOutput_Err2_SV_D_Qy.append(1.36966827900951199)
TruthOutput_Err2_SV_D_Qy.append(2.06997972654337000)

TruthOutput_SV_D_Qz = DoubleNessiVector()
TruthOutput_SV_D_Qz.append(-0.21987181166325700)
TruthOutput_SV_D_Qz.append(-1.19576926099386244)
TruthOutput_SV_D_Qz.append(-2.17166671032446778)
if(platform=="linux2" and uname()[4]=="x86_64"):
	TruthOutput_SV_D_Qz.append(-3.14756415965507310)
else:
	TruthOutput_SV_D_Qz.append(-3.1475641596550736)
		
TruthOutput_SV_D_Qz.append(-4.12346160898567823)

TruthOutput_Err2_SV_D_Qz = DoubleNessiVector()
TruthOutput_Err2_SV_D_Qz.append(0.74627936184453000)
TruthOutput_Err2_SV_D_Qz.append(1.71699049828466867)
TruthOutput_Err2_SV_D_Qz.append(2.69817895177061133)
TruthOutput_Err2_SV_D_Qz.append(3.68984472230235778)
TruthOutput_Err2_SV_D_Qz.append(4.69198780987990912)

# Truth values for init_scatt_wavevector_to_Q scalar-scalar version
TruthOutput_SS_D_Qx = DoubleVPair()
TruthOutput_SS_D_Qx.val = -0.17380656755500100
TruthOutput_SS_D_Qx.val_err2 = 0.09073486048493280

TruthOutput_SS_D_Qy = DoubleVPair()
TruthOutput_SS_D_Qy.val = -0.21024756879486733
TruthOutput_SS_D_Qy.val_err2 = 0.11760239343867500

TruthOutput_SS_D_Qz = DoubleVPair()
TruthOutput_SS_D_Qz.val = -0.21987181166325700
TruthOutput_SS_D_Qz.val_err2 = 0.74627936184453000

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for init_scatt_wavevector_to_Q vector-vector
# version
Output_VV_D_Qx = DoubleNessiVector(len(Input1_D))
Output_Err2_VV_D_Qx = DoubleNessiVector(len(Input1_Err2_D))

Output_VV_D_Qy = DoubleNessiVector(len(Input1_D))
Output_Err2_VV_D_Qy = DoubleNessiVector(len(Input1_Err2_D))

Output_VV_D_Qz = DoubleNessiVector(len(Input1_D))
Output_Err2_VV_D_Qz = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for init_scatt_wavevector_to_Q vector-scalar
# version
Output_VS_D_Qx = DoubleNessiVector(len(Input1_D))
Output_Err2_VS_D_Qx = DoubleNessiVector(len(Input1_Err2_D))

Output_VS_D_Qy = DoubleNessiVector(len(Input1_D))
Output_Err2_VS_D_Qy = DoubleNessiVector(len(Input1_Err2_D))

Output_VS_D_Qz = DoubleNessiVector(len(Input1_D))
Output_Err2_VS_D_Qz = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for init_scatt_wavevector_to_Q scalar-vector
# version
Output_SV_D_Qx = DoubleNessiVector(len(Input1_D))
Output_Err2_SV_D_Qx = DoubleNessiVector(len(Input1_Err2_D))

Output_SV_D_Qy = DoubleNessiVector(len(Input1_D))
Output_Err2_SV_D_Qy = DoubleNessiVector(len(Input1_Err2_D))

Output_SV_D_Qz = DoubleNessiVector(len(Input1_D))
Output_Err2_SV_D_Qz = DoubleNessiVector(len(Input1_Err2_D))

# Output placeholders for init_scatt_wavevector_to_Q scalar-scalar
# version
Output_SS_D_Qx = DoubleVPair()
Output_SS_D_Qy = DoubleVPair()
Output_SS_D_Qz = DoubleVPair()

print "Checking Vector-Vector Initial and Scattering Wavevector to Q"
print "Binding Function"

init_scatt_wavevector_to_Q_d(Input1_D, Input1_Err2_D,
                             Input2_D, Input2_Err2_D,
                             azimuthal_angle, azimuthal_angle_err2,
                             polar_angle, polar_angle_err2,
                             Output_VV_D_Qx, Output_Err2_VV_D_Qx,
                             Output_VV_D_Qy, Output_Err2_VV_D_Qy,
                             Output_VV_D_Qz, Output_Err2_VV_D_Qz)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_d",
                                  Output_VV_D_Qx,
                                  TruthOutput_VV_D_Qx,
                                  Output_Err2_VV_D_Qx,
                                  TruthOutput_Err2_VV_D_Qx)

print mess
mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_d",
                                  Output_VV_D_Qy,
                                  TruthOutput_VV_D_Qy,
                                  Output_Err2_VV_D_Qy,
                                  TruthOutput_Err2_VV_D_Qy)

print mess
mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_d",
                                  Output_VV_D_Qz,
                                  TruthOutput_VV_D_Qz,
                                  Output_Err2_VV_D_Qz,
                                  TruthOutput_Err2_VV_D_Qz)

print mess
print
print "Checking Vector-Scalar Initial and Scattering Wavevector to Q"
print "Binding Function"

init_scatt_wavevector_to_Q_d(Input1_D, Input1_Err2_D,
                             Input2_D[0], Input2_Err2_D[0],
                             azimuthal_angle, azimuthal_angle_err2,
                             polar_angle, polar_angle_err2,
                             Output_VS_D_Qx, Output_Err2_VS_D_Qx,
                             Output_VS_D_Qy, Output_Err2_VS_D_Qy,
                             Output_VS_D_Qz, Output_Err2_VS_D_Qz)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_d",
                                  Output_VS_D_Qx,
                                  TruthOutput_VS_D_Qx,
                                  Output_Err2_VS_D_Qx,
                                  TruthOutput_Err2_VS_D_Qx)
print mess
mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_d",
                                  Output_VS_D_Qy,
                                  TruthOutput_VS_D_Qy,
                                  Output_Err2_VS_D_Qy,
                                  TruthOutput_Err2_VS_D_Qy)
print mess
mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_d",
                                  Output_VS_D_Qz,
                                  TruthOutput_VS_D_Qz,
                                  Output_Err2_VS_D_Qz,
                                  TruthOutput_Err2_VS_D_Qz)                                  
print mess
print
print "Checking Scalar-Vector Initial and Scattering Wavevector to Q"
print "Binding Function"

init_scatt_wavevector_to_Q_d(Input1_D[0], Input1_Err2_D[0],
                             Input2_D, Input2_Err2_D,
                             azimuthal_angle, azimuthal_angle_err2,
                             polar_angle, polar_angle_err2,
                             Output_SV_D_Qx, Output_Err2_SV_D_Qx,
                             Output_SV_D_Qy, Output_Err2_SV_D_Qy,
                             Output_SV_D_Qz, Output_Err2_SV_D_Qz)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_d",
                                  Output_SV_D_Qx,
                                  TruthOutput_SV_D_Qx,
                                  Output_Err2_SV_D_Qx,
                                  TruthOutput_Err2_SV_D_Qx)
print mess
mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_d",
                                  Output_SV_D_Qy,
                                  TruthOutput_SV_D_Qy,
                                  Output_Err2_SV_D_Qy,
                                  TruthOutput_Err2_SV_D_Qy)
print mess
mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_d",
                                  Output_SV_D_Qz,
                                  TruthOutput_SV_D_Qz,
                                  Output_Err2_SV_D_Qz,
                                  TruthOutput_Err2_SV_D_Qz)           
                                
print mess
print
print "Checking Scalar-Scalar Initial and Scattering Wavevector to Q"
print "Binding Function"

init_scatt_wavevector_to_Q_ss_d(Input1_D[0], Input1_Err2_D[0],
                                Input2_D[0], Input2_Err2_D[0],
                                azimuthal_angle, azimuthal_angle_err2,
                                polar_angle, polar_angle_err2,
                                Output_SS_D_Qx,
                                Output_SS_D_Qy,
                                Output_SS_D_Qz)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_ss_d",
                                  Output_SS_D_Qx.val,
                                  TruthOutput_SS_D_Qx.val,
                                  Output_SS_D_Qx.val_err2,
                                  TruthOutput_SS_D_Qx.val_err2)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_ss_d",
                                  Output_SS_D_Qy.val,
                                  TruthOutput_SS_D_Qy.val,
                                  Output_SS_D_Qy.val_err2,
                                  TruthOutput_SS_D_Qy.val_err2)

mess = test_common_bind.makeCheck("init_scatt_wavevector_to_Q_ss_d",
                                  Output_SS_D_Qz.val,
                                  TruthOutput_SS_D_Qz.val,
                                  Output_SS_D_Qz.val_err2,
                                  TruthOutput_SS_D_Qz.val_err2)

print mess

##
# \} // end of test_init_scatt_wavevector_to_Q group
#
