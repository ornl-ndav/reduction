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
# \file bindings/test/PAL/init_scatt_wavevector_to_Q_test.py
#

import axis_manip
import nessi_list
import test_common
from vpair_bind import *

NUM_VAL = 5

##
# \defgroup init_scatt_wavevector_to_Q_test \
# init_scatt_wavevector_to_Q_test
# \{
#
# This test compares the output data (\f$output\_vs\f$, \f$output\_sv\f$,
# \f$output\_vv\f$, and \f$output\_ss\f$) calculated by the binding module
# <i>init_scatt_wavevector_to_Q.py</i> of the Python Abstration Layer
# (PAL) <i>axis_manip.py</i> with the true output data calculated
# (\f$true\_output\_vs\f$, \f$true\_output\_sv\f$, \f$true\_output\_vv\f$,
# and \f$true\_output\_ss\f$) manually calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
#
# <b>Notation used:</b>
# - vv : vector-vector
# - vs : vector-scalar
# - sv : scalar-vector
# - ss : scalar-scalar
# - VV = "v,v"
# - SV = "s,v"
# - VS = "v,s"
# - SV = "s,v"
# - SS = "s,s"
# - ERROR = "error "
# - EMPTY = ""

##
#
# This function initializes the values of arrays, \f$k\_i\f$, \f$k\_f\f$,
# \f$k\_i\_err2\f$, and \f$k\_f\_err2\f$.
#
# \returns
# - K_i is the incident wavevector axis in units of reciprocal Angstroms
# - K_i_err2 is the square of the uncertainty of the incident wavecector axis
# - K_f is the final wavevector axis in units of reciprocal Angstroms
# - K_f_err2 is the square of the uncertainty of the final wavevector axis
#
def initialize_inputs(key):
    if (key == "double"):
        k_i = nessi_list.NessiList(type="double")
        k_i_err2 = nessi_list.NessiList(type="double")
        k_f = nessi_list.NessiList(type="double")
        k_f_err2 = nessi_list.NessiList(type="double")
        for i in range(NUM_VAL):
            k_i.append(float(i+1))
            k_i_err2.append(float(i+0.5))
            k_f.append(float(i+1.25))
            k_f_err2.append(float(i+0.25))
    else:
        raise TypeError

    return k_i, k_i_err2, k_f, k_f_err2

##
# Function that sets the true output based on values contained in
# \f$k\_i\f$, \f$k\_i\_err2\f$, \f$k\_f\f$, and \f$k\_f\_err2\f$.
#
# For the vs, sv, and ss cases, the scalar used is the first element
# of the NessiLists \f$k_i\f$ and \f$k_f\f$ (\f$k_i[0]\f$ and
# \f$k_f[0]\f$
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiList for the vv case for Qx
# - The square of the uncertainty in the true NessiList for the
#   vv case for Qx
# - The true NessiList for the vv case for Qy
# - The square of the uncertainty in the true NessiList for the
#   vv case for Qy
# - The true NessiList for the vv case for Qz
# - The square of the uncertainty in the true NessiList for the
#   vv case for Qz
# - The true NessiList for the vs case for Qx
# - The square of the uncertainty in the true NessiList for the
#   vs case for Qx
# - The true NessiList for the vs case for Qy
# - The square of the uncertainty in the true NessiList for the
#   vs case for Qy
# - The true NessiList for the vs case for Qz
# - The square of the uncertainty in the true NessiList for the
#   vs case for Qz
# - The true NessiList for the sv case for Qx
# - The square of the uncertainty in the true NessiList for the
#   sv case for Qx
# - The true NessiList for the sv case for Qy
# - The square of the uncertainty in the true NessiList for the
#   sv case for Qy
# - The true NessiList for the sv case for Qz
# - The square of the uncertainty in the true NessiList for the
#   sv case for Qz
# - The true value for the ss case for Qx
# - The square of the uncertainty of the true value for the ss
#   case for Qx
# - The true value for the ss case for Qy
# - The square of the uncertainty of the true value for the ss
#   case for Qy
# - The true value for the ss case for Qz
# - The square of the uncertainty of the true value for the ss
#   case for Qz
#
def initialize_true_outputs(key):

    if (key == "double"):

        true_output_vv_Qx = nessi_list.NessiList()
        true_output_vv_Qx_err2 = nessi_list.NessiList()
        true_output_vv_Qy = nessi_list.NessiList()
        true_output_vv_Qy_err2 = nessi_list.NessiList()
        true_output_vv_Qz = nessi_list.NessiList()
        true_output_vv_Qz_err2 = nessi_list.NessiList()
        
        true_output_vs_Qx = nessi_list.NessiList()
        true_output_vs_Qx_err2 = nessi_list.NessiList()
        true_output_vs_Qy = nessi_list.NessiList()
        true_output_vs_Qy_err2 = nessi_list.NessiList()
        true_output_vs_Qz = nessi_list.NessiList()
        true_output_vs_Qz_err2 = nessi_list.NessiList()

        true_output_sv_Qx = nessi_list.NessiList()
        true_output_sv_Qx_err2 = nessi_list.NessiList()
        true_output_sv_Qy = nessi_list.NessiList()
        true_output_sv_Qy_err2 = nessi_list.NessiList()
        true_output_sv_Qz = nessi_list.NessiList()
        true_output_sv_Qz_err2 = nessi_list.NessiList()
        
        true_output_ss_Qx = DoubleVPair()
        true_output_ss_Qy = DoubleVPair()
        true_output_ss_Qz = DoubleVPair()
        
      # initialize the correct outputs for vector vector case
        true_output_vv_Qx.append(float(0.17380656755500100))
        true_output_vv_Qx_err2.append(float(0.09073486048493280))
        true_output_vv_Qy.append(float(0.21024756879486733))
        true_output_vv_Qy_err2.append(float(0.11760239343867500))
        true_output_vv_Qz.append(float(-0.21987181166325700))
        true_output_vv_Qz_err2.append(float(0.74627936184453000))
        
        true_output_vv_Qx.append(float(0.31285182159900200))
        true_output_vv_Qx_err2.append(float(0.30248772434693300))
        true_output_vv_Qy.append(float(0.37844562383076100))
        true_output_vv_Qy_err2.append(float(0.39347961245716444))
        true_output_vv_Qz.append(float(-0.19576926099386238))
        true_output_vv_Qz_err2.append(float(2.71699049828466823))
        
        true_output_vv_Qx.append(float(0.45189707564300253))
        true_output_vv_Qx_err2.append(float(0.62419446317455556))
        true_output_vv_Qy.append(float(0.54664367886665500))
        true_output_vv_Qy_err2.append(float(0.81083490764744300))
        true_output_vv_Qz.append(float(-0.17166671032446800))
        true_output_vv_Qz_err2.append(float(4.69817895177061088))

        true_output_vv_Qx.append(float(0.59094232968700300))
        true_output_vv_Qx_err2.append(float(1.05585507696780088))
        true_output_vv_Qy.append(float(0.71484173390254900))
        true_output_vv_Qy_err2.append(float(1.36966827900951199))
        true_output_vv_Qz.append(float(-0.14756415965507300))
        true_output_vv_Qz_err2.append(float(6.68984472230235823))

        true_output_vv_Qx.append(float(0.72998758373100400))
        true_output_vv_Qx_err2.append(float(1.59746956572666845))
        true_output_vv_Qy.append(float(0.88303978893844267))
        true_output_vv_Qy_err2.append(float(2.06997972654337000))
        true_output_vv_Qz.append(float(-0.12346160898567860))
        true_output_vv_Qz_err2.append(float(8.69198780987991000))
        
      # initialize the correct outputs for vector scalar case
        true_output_vs_Qx.append(float(0.17380656755500100))
        true_output_vs_Qx_err2.append(float(0.09073486048493280))
        true_output_vs_Qy.append(float(0.21024756879486733))
        true_output_vs_Qy_err2.append(float(0.11760239343867500))
        true_output_vs_Qz.append(float(-0.21987181166325700))
        true_output_vs_Qz_err2.append(float(0.74627936184453000))
  
        true_output_vs_Qx.append(float(0.17380656755500100))
        true_output_vs_Qx_err2.append(float(0.09073486048493280))
        true_output_vs_Qy.append(float(0.21024756879486733))
        true_output_vs_Qy_err2.append(float(0.11760239343867500))
        true_output_vs_Qz.append(float(0.78012818833674300))
        true_output_vs_Qz_err2.append(float(1.74627936184453000))
        
        true_output_vs_Qx.append(float(0.17380656755500100))
        true_output_vs_Qx_err2.append(float(0.09073486048493280))
        true_output_vs_Qy.append(float(0.21024756879486733))
        true_output_vs_Qy_err2.append(float(0.11760239343867500))
        true_output_vs_Qz.append(float(1.78012818833674310))
        true_output_vs_Qz_err2.append(float(2.74627936184453000))
        
        true_output_vs_Qx.append(float(0.17380656755500100))
        true_output_vs_Qx_err2.append(float(0.09073486048493280))
        true_output_vs_Qy.append(float(0.21024756879486733))
        true_output_vs_Qy_err2.append(float(0.11760239343867500))
        true_output_vs_Qz.append(float(2.78012818833674310))
        true_output_vs_Qz_err2.append(float(3.74627936184453000))
        
        true_output_vs_Qx.append(float(0.17380656755500100))
        true_output_vs_Qx_err2.append(float(0.09073486048493280))
        true_output_vs_Qy.append(float(0.21024756879486733))
        true_output_vs_Qy_err2.append(float(0.11760239343867500))
        true_output_vs_Qz.append(float(3.78012818833674310))
        true_output_vs_Qz_err2.append(float(4.74627936184453000))

      # initialize the correct outputs for scalar vector case
        true_output_sv_Qx.append(float(0.17380656755500100))
        true_output_sv_Qx_err2.append(float(0.09073486048493280))
        true_output_sv_Qy.append(float(0.21024756879486733))
        true_output_sv_Qy_err2.append(float(0.11760239343867500))
        true_output_sv_Qz.append(float(-0.21987181166325700))
        true_output_sv_Qz_err2.append(float(0.74627936184453000))

        true_output_sv_Qx.append(float(0.31285182159900200))
        true_output_sv_Qx_err2.append(float(0.30248772434693300))
        true_output_sv_Qy.append(float(0.37844562383076100))
        true_output_sv_Qy_err2.append(float(0.39347961245716444))
        true_output_sv_Qz.append(float(-1.19576926099386244))
        true_output_sv_Qz_err2.append(float(1.71699049828466867))
        
        true_output_sv_Qx.append(float(0.45189707564300251))
        true_output_sv_Qx_err2.append(float(0.62419446317455556))
        true_output_sv_Qy.append(float(0.54664367886665500))
        true_output_sv_Qy_err2.append(float(0.81083490764744300))
        true_output_sv_Qz.append(float(-2.17166671032446778))
        true_output_sv_Qz_err2.append(float(2.69817895177061133))
        
        true_output_sv_Qx.append(float(0.59094232968700300))
        true_output_sv_Qx_err2.append(float(1.05585507696780088))
        true_output_sv_Qy.append(float(0.71484173390254900))
        true_output_sv_Qy_err2.append(float(1.36966827900951199))
        true_output_sv_Qz.append(float(-3.14756415965507310))
        true_output_sv_Qz_err2.append(float(3.68984472230235778))

        true_output_sv_Qx.append(float(0.72998758373100400))
        true_output_sv_Qx_err2.append(float(1.59746956572666845))
        true_output_sv_Qy.append(float(0.88303978893844267))
        true_output_sv_Qy_err2.append(float(2.06997972654337000))
        true_output_sv_Qz.append(float(-4.12346160898567823))
        true_output_sv_Qz_err2.append(float(4.69198780987990912))

      # initialize the correct outputs for scalar scalar case
        true_output_ss_Qx.val = float(0.17380656755500100)
        true_output_ss_Qx.val_err2 = float(0.09073486048493280)
        true_output_ss_Qy.val = float(0.21024756879486733)
        true_output_ss_Qy.val_err2 = float(0.11760239343867500)
        true_output_ss_Qz.val = float(-0.21987181166325700)
        true_output_ss_Qz.val_err2 = float(0.74627936184453000)

    else:

        raise TypeError

    return true_output_vv_Qx, true_output_vv_Qx_err2,\
           true_output_vv_Qy, true_output_vv_Qy_err2,\
           true_output_vv_Qz, true_output_vv_Qz_err2,\
           true_output_vs_Qx, true_output_vs_Qx_err2,\
           true_output_vs_Qy, true_output_vs_Qy_err2,\
           true_output_vs_Qz, true_output_vs_Qz_err2,\
           true_output_sv_Qx, true_output_sv_Qx_err2,\
           true_output_sv_Qy, true_output_sv_Qy_err2,\
           true_output_sv_Qz, true_output_sv_Qz_err2,\
           true_output_ss_Qx.val, true_output_ss_Qx.val_err2,\
           true_output_ss_Qy.val, true_output_ss_Qy.val_err2,\
           true_output_ss_Qz.val, true_output_ss_Qz.val_err2

if __name__ == "__main__":

    mess =""

    print "##############################################"
    print "# Checking init_scatt_wavevector_to_Q        #"
    print "#         Python Abstraction layer           #"
    print "##############################################"
    print

    # generate global inputs
    azimuthal = float(0.88)
    azimuthal_err2 = float(0.44)
    polar = float(0.22)
    polar_err2 = float(0.11)

    # generate true_outputs
    true_output_vv_Qx_d, true_output_vv_Qx_err2_d,\
    true_output_vv_Qy_d, true_output_vv_Qy_err2_d,\
    true_output_vv_Qz_d, true_output_vv_Qz_err2_d,\
    true_output_vs_Qx_d, true_output_vs_Qx_err2_d,\
    true_output_vs_Qy_d, true_output_vs_Qy_err2_d,\
    true_output_vs_Qz_d, true_output_vs_Qz_err2_d,\
    true_output_sv_Qx_d, true_output_sv_Qx_err2_d,\
    true_output_sv_Qy_d, true_output_sv_Qy_err2_d,\
    true_output_sv_Qz_d, true_output_sv_Qz_err2_d,\
    true_output_ss_Qx_d, true_output_ss_Qx_err2_d,\
    true_output_ss_Qy_d, true_output_ss_Qy_err2_d,\
    true_output_ss_Qz_d, true_output_ss_Qz_err2_d = \
    initialize_true_outputs("double")

    # vv case
    
    k_i,k_i_err2,k_f,k_f_err2=initialize_inputs("double")
    
    output_vv_Qx, output_vv_Qx_err2,\
    output_vv_Qy, output_vv_Qy_err2,\
    output_vv_Qz, output_vv_Qz_err2 = \
    axis_manip.init_scatt_wavevector_to_Q(k_i,\
                                          k_i_err2,\
                                          k_f,\
                                          k_f_err2,\
                                          azimuthal,\
                                          azimuthal_err2,\
                                          polar,\
                                          polar_err2)

    # Check values
    mess = test_common.MakeCheck("vv",\
                                 output_vv_Qx,\
                                 true_output_vv_Qx_d,\
                                 output_vv_Qx_err2,\
                                 true_output_vv_Qx_err2_d)
    print mess

    mess = test_common.MakeCheck("vv",\
                                 output_vv_Qy,\
                                 true_output_vv_Qy_d,\
                                 output_vv_Qy_err2,\
                                 true_output_vv_Qy_err2_d)
    print mess

    mess = test_common.MakeCheck("vv",\
                                 output_vv_Qz,\
                                 true_output_vv_Qz_d,\
                                 output_vv_Qz_err2,\
                                 true_output_vv_Qz_err2_d)
    print mess

    # vs case
    k_i,k_i_err2,k_f,k_f_err2=initialize_inputs("double")

    output_vs_Qx, output_vs_Qx_err2,\
    output_vs_Qy, output_vs_Qy_err2,\
    output_vs_Qz, output_vs_Qz_err2 = \
                  axis_manip.init_scatt_wavevector_to_Q(k_i,\
                                                        k_i_err2,\
                                                        k_f[0],\
                                                        k_f_err2[0],\
                                                        azimuthal,\
                                                        azimuthal_err2,\
                                                        polar,\
                                                        polar_err2)

    mess = test_common.MakeCheck("vs",\
                                 output_vs_Qx,\
                                 true_output_vs_Qx_d,\
                                 output_vs_Qx_err2,\
                                 true_output_vs_Qx_err2_d)
    print mess


    mess = test_common.MakeCheck("vs",\
                                 output_vs_Qy,\
                                 true_output_vs_Qy_d,\
                                 output_vs_Qy_err2,\
                                 true_output_vs_Qy_err2_d)
    print mess

    mess = test_common.MakeCheck("vs",\
                                 output_vs_Qz,\
                                 true_output_vs_Qz_d,\
                                 output_vs_Qz_err2,\
                                 true_output_vs_Qz_err2_d)
    print mess
    
    # sv case
    k_i,k_i_err2,k_f,k_f_err2=initialize_inputs("double")

    output_sv_Qx, output_sv_Qx_err2,\
    output_sv_Qy, output_sv_Qy_err2,\
    output_sv_Qz, output_sv_Qz_err2 = \
                  axis_manip.init_scatt_wavevector_to_Q(k_i[0],\
                                                        k_i_err2[0],\
                                                        k_f,\
                                                        k_f_err2,\
                                                        azimuthal,\
                                                        azimuthal_err2,\
                                                        polar,\
                                                        polar_err2)

    mess = test_common.MakeCheck("sv",\
                                 output_sv_Qx,\
                                 true_output_sv_Qx_d,\
                                 output_sv_Qx_err2,\
                                 true_output_sv_Qx_err2_d)
    print mess

    mess = test_common.MakeCheck("sv",\
                                 output_sv_Qy,\
                                 true_output_sv_Qy_d,\
                                 output_sv_Qy_err2,\
                                 true_output_sv_Qy_err2_d)
    print mess

    mess = test_common.MakeCheck("sv",\
                                 output_sv_Qz,\
                                 true_output_sv_Qz_d,\
                                 output_sv_Qz_err2,\
                                 true_output_sv_Qz_err2_d)
    print mess

    # ss case
    k_i,k_i_err2,k_f,k_f_err2=initialize_inputs("double")
    
    output_ss_Qx, output_ss_Qx_err2,\
    output_ss_Qy, output_ss_Qy_err2,\
    output_ss_Qz, output_ss_Qz_err2 = \
                  axis_manip.init_scatt_wavevector_to_Q(k_i[0], k_i_err2[0],\
                                                        k_f[0], k_f_err2[0],\
                                                        azimuthal,\
                                                        azimuthal_err2,\
                                                        polar,\
                                                        polar_err2)

    mess = test_common.MakeCheck1("ss",\
                                  output_ss_Qx, true_output_ss_Qx_d,\
                                  output_ss_Qx_err2, true_output_ss_Qx_err2_d)
    print mess

    mess = test_common.MakeCheck1("ss",\
                                  output_ss_Qy, true_output_ss_Qy_d,\
                                  output_ss_Qy_err2, true_output_ss_Qy_err2_d)
    print mess

    mess = test_common.MakeCheck1("ss",\
                                  output_ss_Qz, true_output_ss_Qz_d,\
                                  output_ss_Qz_err2, true_output_ss_Qz_err2_d)
    print mess
