###############################################################################
#
# Testing script for Swig bindings for time_offset_dgs functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_time_offset_dgs.py
#

##
# \defgroup test_time_offset_dgs \
# pbl::test_time_offset_dgs
# \{
#

from axis_manip_bind import time_offset_dgs_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "##############################################"
print "# Checking Time_Offset_DGS                   #"
print "# Swig Generated Python Binding Layer        #"
print "##############################################"
print

# Set parameters for function

dist_downstream_mon = 1.1;
dist_downstream_mon_err2 = 0.1;
time_downstream_mon = 2.75;
time_downstream_mon_err2 = 0.75;
initial_velocity = 0.51;
initial_velocity_err2 = 0.05;

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for time_offset_dgs scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 0.59313725490196078
TruthOutput_SS_D.val_err2 = 1.27874988488885991

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for time_offset_dgs scalar-scalar
# version
Output_SS_D = DoubleVPair()

print "Checking Scalar-Scalar Time Offset DGS "
print "Binding Function"

time_offset_dgs_ss_d(dist_downstream_mon, 
                     dist_downstream_mon_err2, 
                     time_downstream_mon, 
                     time_downstream_mon_err2,
                     initial_velocity,
                     initial_velocity_err2,
                     Output_SS_D)

mess = test_common_bind.makeCheck("time_offset_dgs",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_time_offset_dgs group
#
