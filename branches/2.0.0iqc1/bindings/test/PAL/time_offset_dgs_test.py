##
#                     SNS Common Libraries
#            A part of the SNS Analysis Software Suite.
#
#                   Spallation Neutron Source
#           Oak Ridge National Laboratory, Oak Ridge TN.
#
#
#                              NOTICE
#
#  For this software and its associated documentation, permission is granted
#  to reproduce, prepare derivative works, and distribute copies to the public
#  for any purpose and without fee.
#
#  This material was prepared as an account of work sponsored by an agency of
#  the United States Government.  Neither the United States Government nor the
#  United States Department of Energy, nor any of their employees, makes any
#  warranty, express or implied, or assumes any legal liability or
#  responsibility for the accuracy, completeness, or usefulness of any
#  information, apparatus, product, or process disclosed, or represents that
#  its use would not infringe privately owned rights.
#
#

##
# $Id$
#
# \file bindings/test/PAL/time_offset_dgs_test.py
#

import axis_manip
import nessi_list
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup time_offset_dgs_test time_offset_dgs_test
# \{
#
# This test compares the output data (\f$output\_vv\f$, and \f$output\_ss\f$)
# calculated by the binding module <i>time_offset_dgs.py</i> of the
# Python Abstration Layer (PAL)
# <i>axis_manip.py</i> with the true output data calculated
# (\f$true\_output\_vv\f$, and \f$true\_output\_ss\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - ss : scalar-scalar
# - VV = "v,v"
# - SS = "s,s"
# - ERROR = "error "
# - EMPTY = ""


##
# Function that sets the true output based on values contained in
# \f$dist\_downstream\_monitor\f$, \f$dist\_downstream\_monitor\_err2\f$,
# \f$time\_downstream\_monitor\f$, \f$time\_downstream\_monitor\_err2\f$,
# \f$initial\_velocity\f$, \f$initial\_velocity\_err2\f$
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true value for the ss case
# - The square of the uncertainty of the true value for the ss case
#
def initialize_true_outputs(key):
    
    if (key == "double"):
        
        true_output_ss=DoubleVPair()
        
        # initialize the correct outputs for scalar scalar case
        true_output_ss.val = float(0.59313725490196078)
        true_output_ss.val_err2 = float(1.27874988488885991)
        
    else:
        
        raise TypeError
    
    return true_output_ss.val, true_output_ss.val_err2

if __name__ == "__main__":
    
    mess =""
    
    print "###################################################################"
    print "# Checking time_offset_dgs Python Abstraction layer               #"
    print "###################################################################"
    print
    
    dist_downstream_monitor = 1.1
    dist_downstream_monitor_err2 = 0.1
    time_downstream_monitor = 2.75
    time_downstream_monitor_err2 = 0.75
    initial_velocity = 0.51
    initial_velocity_err2 = 0.05
    
    # generate true_outputs
    true_output_ss_d, true_output_ss_err2_d = \
                      initialize_true_outputs("double")
    
    # ss case
    output_ss, output_ss_err2 = \
               axis_manip.time_offset_dgs(\
         dist_downstream_monitor,\
         dist_downstream_monitor_err2,\
         time_downstream_monitor,\
         time_downstream_monitor_err2,\
         initial_velocity,\
         initial_velocity_err2)
    
    mess = test_common.MakeCheck1("ss",\
                                  output_ss,\
                                  true_output_ss_d,\
                                  output_ss_err2,\
                                  true_output_ss_err2_d)
    
    print mess
    
##
# \}
#

    

