###############################################################################
#
# Testing script for Swig bindings for weighted_average functions
#
# $Id$
#
###############################################################################

from nessi_vector_bind import *
from utils_bind import weighted_average_d

print "#################################################################"
print "# Checking Weighted_Average Swig Generated Python Binding Layer #"
print "#################################################################"
print

# Set standard size for vectors
vec_length = 5

# Create input vectors
Input1_D = DoubleNessiVector()
Input1_Err2_D = DoubleNessiVector()

for counter in range(vec_length):
    Input1_D.append(float(counter+1))
    Input1_Err2_D.append(float(1))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth information for weighted_average
truth_output_wa = float(3)
truth_output_err2_wa = 0.2

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for weighted_average
output_wa = 0.0
output_err2_wa = 0.0

print "Checking Weighted Average Binding Function"

print "weighted_average_d..........."

weighted_average_d(Input1_D, Input1_Err2_D, 0, vec_length-1,
                   output_wa, output_err2_wa)


