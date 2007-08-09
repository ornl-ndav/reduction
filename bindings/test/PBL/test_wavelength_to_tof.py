###############################################################################
#
# Testing script for Swig bindings for wavelength_to_tof functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_wavelength_to_tof.py
#

##
# \defgroup test_wavelength_to_tof pbl::test_wavelength_to_tof
# \{
#

from axis_manip_bind import wavelength_to_tof_d
from axis_manip_bind import wavelength_to_tof_ss_d
from nessi_vector_bind import *
from os import uname
from sys import platform
import test_common_bind
from vpair_bind import *

print "##################################################################"
print "# Checking Wavelength_to_Tof Swig Generated Python Binding Layer #"
print "##################################################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
pathlength = 5.0
pathlength_err2 = 2.5

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

# Truth values for wavelength_to_tof vector-vector version
TruthOutput_VV_D = DoubleNessiVector()
TruthOutput_VV_D.append(1.26389206968393091e+03)
TruthOutput_VV_D.append(2.52778413936786183e+03)
TruthOutput_VV_D.append(3.79167620905179274e+03)
TruthOutput_VV_D.append(5.05556827873572365e+03)
TruthOutput_VV_D.append(6.31946034841965411e+03)

TruthOutput_Err2_VV_D = DoubleNessiVector()
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_Err2_VV_D.append(9.58453898285958450e+05)
    TruthOutput_Err2_VV_D.append(3.03510401123886835e+06)
else:
    TruthOutput_Err2_VV_D.append(9.58453898285958217e+05)
    TruthOutput_Err2_VV_D.append(3.03510401123886742e+06)
TruthOutput_Err2_VV_D.append(5.43123875695376378e+06)
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_Err2_VV_D.append(8.14685813543064613e+06)
else:
    TruthOutput_Err2_VV_D.append(8.14685813543064520e+06)
TruthOutput_Err2_VV_D.append(1.11819621466695145e+07)

# Truth values for wavelength_to_tof scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 1.26389206968393091e+03
if(platform=="linux2" and uname()[4]=="i686"):
    TruthOutput_SS_D.val_err2 = 9.58453898285958450e+05
else:
    TruthOutput_SS_D.val_err2 = 9.58453898285958217e+05

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for wavelength_to_tof vector-vector version
Output_VV_D = DoubleNessiVector(len(Input_D))
Output_Err2_VV_D = DoubleNessiVector(len(Input_Err2_D))

# Output placeholders for wavelength_to_tof scalar-scalar version
Output_SS_D = DoubleVPair()

print "Checking Vector-Vector Wavelength to TOF Binding Function"

wavelength_to_tof_d(Input_D, Input_Err2_D,
                    pathlength, pathlength_err2,
                    Output_VV_D, Output_Err2_VV_D)

mess = test_common_bind.makeCheck("wavelength_to_tof_d",
                                  Output_VV_D,
                                  TruthOutput_VV_D,
                                  Output_Err2_VV_D,
                                  TruthOutput_Err2_VV_D)
print mess
print
print "Checking Scalar-Scalar Wavelength to TOF Binding Function"

wavelength_to_tof_ss_d(Input_D[0], Input_Err2_D[0],
                       pathlength, pathlength_err2,
                       Output_SS_D)

mess = test_common_bind.makeCheck("wavelength_to_tof_ss_d",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_wavelength_to_tof group
#
