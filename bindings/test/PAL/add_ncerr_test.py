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
# \file bindings/test/PAL/add_ncerr_test.cpp
#

import array_manip
import nessi_vector
import test_common_bind

NUM_VAL = 5

##
# \defgroup add_ncerr_test add_ncerr_test
# \{
#
# This test compares the output data (\f$output\_vs\f$ and \f$output\_vv\f$)
# calculated by the binding module <i>add_ncerr.py</i> of the Python
# Abstration Layer (PAL) <i>array_manip.py</i> with the true output
# data calculated (\f$true\_output\_vs\f$ and \f$true\_output\_vv\f$) manually
# calculated.
# Any discrepancy between the outputs (\f$output\f$ and \f$true\_output\f$)
# will generate an error message that give details about the location and type
# of the error
# 
# <b>Notation used:</b>
# - vv : vector-vector
# - vs : vector-scalar
# - VV = "v,v"
# - SV = "s,v"
# - VS = "v,s"
# - ERROR = "error "
# - EMPTY = ""
#

##
#
# This function initializes the values of arrays, \f$input1\f$, \f$input2\f$,
# \f$input1\_err2\f$, and \f$input2\_err2\f$.
#
# \returns
# - input1 is the first NessiVector to be added
# - input1_err2 is the square of the uncertainty in the first
# NessiVector to be added
# - input2 is the second NessiVector to be added
# -input2_err2 is the square of the uncertainty in the second
# NessiVector to be added
#
def initialize_inputs(key):
    if (key == nessi_vector.NessiVector.DOUBLE):
        input1=nessi_vector.NessiVector()
        input1_err2=nessi_vector.NessiVector()
        input2=nessi_vector.NessiVector()
        input2_err2=nessi_vector.NessiVector()
        for i in range(NUM_VAL):
            input1.append(float(NUM_VAL+1-i))  #6.,5.,4.,3.,2.
            input2.append(float(i))            #0.,1.,2.,3.,4.
            input1_err2.append(float(1.))      #1.,1.,1.,1.,1.
            input2_err2.append(float(1.))      #1.,1.,1.,1.,1.
    else:
        input1=nessi_vector.NessiVector(type="int")
        input1_err2=nessi_vector.NessiVector(type="int")
        input2=nessi_vector.NessiVector(type="int")
        input2_err2=nessi_vector.NessiVector(type="int")
        for i in range(NUM_VAL):
            input1.append(int(NUM_VAL+1+i))    #6,5,4,3,2
            input2.append(int(i))              #0,1,2,3,4
            input1_err2.append(int(1.))        #1,1,1,1,1
            input2_err2.append(int(1.))        #1,1,1,1,1

    return input1, input1_err2, input2, input2_err2

##
# Function that sets the true output based on values contained in
# \f$input1\f$, \f$input1\_err2\f$, \f$input2\f$, and \f$input2\_err2\f$.
#
# For the vs case, the scalar used is the last element of the
# NessiVector \f$input2\f$, \f$input2[NUM\_VAL - 1]\f$
#
# \param key (INPUT) forces correct test to happen
#
# \return
# - The true NessiVector for the vs he
# - The square of the uncertainty in the true NessiVector for the vs case
# - The true NessiVector for the vv case
# - The square of the uncertainty in the true NessiVector for the vv case
#
def initialize_true_outputs(key):
    if (key == nessi_vector.NessiVector.DOUBLE):

        true_output_vv=nessi_vector.NessiVector()
        true_output_vv_err2=nessi_vector.NessiVector()
        true_output_vs=nessi_vector.NessiVector()
        true_output_vs_err2=nessi_vector.NessiVector()

	    # initialize the correct outputs for vector vector case
        true_output_vv.append(float(6.))       # 0+6
        true_output_vv_err2.append(float(2.))		
        true_output_vv.append(float(6.))	   # 1+5	
        true_output_vv_err2.append(float(2.))
        true_output_vv.append(float(6.))	   # 2+4
        true_output_vv_err2.append(float(2.))
        true_output_vv.append(float(6.))	   # 3+3
        true_output_vv_err2.append(float(2.))
        true_output_vv.append(float(6.))	   # 4+2
        true_output_vv_err2.append(float(2.))
		
	    # initialize the correct outputs for vector scalar case
        true_output_vs.append(float(10.))      # 4+6
        true_output_vs_err2.append(float(2.))		
        true_output_vs.append(float(9.))	   # 4+5
        true_output_vs_err2.append(float(2.))
        true_output_vs.append(float(8.))	   # 4+4
        true_output_vs_err2.append(float(2.))
        true_output_vs.append(float(7.))	   # 4+3
        true_output_vs_err2.append(float(2.))
        true_output_vs.append(float(6.))	   # 4+2
        true_output_vs_err2.append(float(2.))

    else:

        true_output_vv=nessi_vector.NessiVector(type="int")
        true_output_vv_err2=nessi_vector.NessiVector(type="int")
        true_output_vs=nessi_vector.NessiVector(type="int")
        true_output_vs_err2=nessi_vector.NessiVector(type="int")

	    # initialize the correct outputs for vector vector case
        true_output_vv.append(int(6))      # 0+6
        true_output_vv_err2.append(int(2))		
        true_output_vv.append(int(6))	   # 1+5	
        true_output_vv_err2.append(int(2))
        true_output_vv.append(int(6))	   # 2+4
        true_output_vv_err2.append(int(2))
        true_output_vv.append(int(6))	   # 3+3
        true_output_vv_err2.append(int(2))
        true_output_vv.append(int(6))	   # 4+2
        true_output_vv_err2.append(int(2))
		
	    # initialize the correct outputs for vector scalar case
        true_output_vs.append(int(10))     # 4+6
        true_output_vs_err2.append(int(2))		
        true_output_vs.append(int(9))	   # 4+5
        true_output_vs_err2.append(int(2))
        true_output_vs.append(int(8))	   # 4+4
        true_output_vs_err2.append(int(2))
        true_output_vs.append(int(7))	   # 4+3
        true_output_vs_err2.append(int(2))
        true_output_vs.append(int(6))	   # 4+2
        true_output_vs_err2.append(int(2))

    return true_output_vv,\
		   true_output_vv_err2,\
		   true_output_vs,\
		   true_output_vs_err2


def test_func(key):

	# fill in values as appropriate
    input1,input1_err2, input2, input2_err2 = initialize_inputs(key)
    true_output_vv, true_output_vv_err2, true_output_vs, true_output_vs_err2 =initialize_true_outputs(key)

    output_vv, output_vv_err2 = array_manip.add_ncerr(input1,\
													  input2_err2,\
													  input2,\
													  input2_err2)

    output_vs, output_vs_err2 = array_manip.add_ncerr(input1,\
													  input1_err2,\
													  input2[NUM_VAL-1],\
													  input2_err2[NUM_VAL-1])

	# run test
    mess = test_common_bind.makecheck("vv",\
									  output_vv,\
									  true_output_vv,\
									  output_vv_err2,\
									  true_output_vv_err2)
	
    mess = test_common_bind.makecheck("vs",\
									  output_vs,\
									  true_output_vs,\
									  output_vs_err2,\
									  true_output_vs_err2)


						  
if __name__ == "__main__":

    print "###############################################"
    print "# Checking add_ncerr Python Abstraction layer #"
    print "###############################################"

    status = True

    key_range = ["double","int"]
    
    for key in key_range:
        string = "Checking " + key + " Addition Abstraction Function"
        print string
        test_func(key)


			
	
						  
