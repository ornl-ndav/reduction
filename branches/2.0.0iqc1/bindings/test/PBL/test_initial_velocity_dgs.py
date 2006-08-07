###############################################################################
#
# Testing script for Swig bindings for initial_velocity_dgs
# functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_initial_velocity_dgs.py
#

##
# \defgroup test_initial_velocity_dgs \
# pbl::test_initial_velocity_dgs
# \{
#

from axis_manip_bind import initial_velocity_dgs_ss_d
from nessi_vector_bind import *
import test_common_bind
from vpair_bind import *

print "##############################################"
print "# Checking Initial_Velocity_DGS              #"
print "# Swig Generated Python Binding Layer        #"
print "##############################################"
print

# Set standard size for vectors
NUM_VAL = 5

# Set parameters for function
dist_upsteam_mon = 0.51;
dist_upstream_mon_err2 = 0.05;
time_upstream_mon = 1.25;
time_upstream_mon_err2 = 0.25;
dist_downstream_mon = 1.1;
dist_downstream_mon_err2 = 0.1;
time_downstream_mon = 2.75;
time_downstream_mon_err2 = 0.75;

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth values for initial_velocity_dgs scalar-scalar version
TruthOutput_SS_D = DoubleVPair()
TruthOutput_SS_D.val = 0.39333333333333333;
TruthOutput_SS_D.val_err2 = 0.06666666666666667;

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for initial_velocity_dgs scalar-scalar
# version
Output_SS_D = DoubleVPair()

print
print "Checking Scalar-Scalar Initial Velocity DGS "
print "Binding Function"

initial_velocity_dgs_ss_d(dist_upsteam_mon, 
                          dist_upstream_mon_err2, 
                          time_upstream_mon, 
                          time_upstream_mon_err2, 
                          dist_downstream_mon, 
                          dist_downstream_mon_err2, 
                          time_downstream_mon, 
                          time_downstream_mon_err2, 
                          Output_SS_D)

mess = test_common_bind.makeCheck("initial_velocity_dgs",
                                  Output_SS_D.val,
                                  TruthOutput_SS_D.val,
                                  Output_SS_D.val_err2,
                                  TruthOutput_SS_D.val_err2)

print mess

##
# \} // end of test_initial_velocity_dgs group
#
