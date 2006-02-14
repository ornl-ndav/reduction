###############################################################################
#
# Testing script for Swig bindings for functions in the utils directory
#
# $Id$
#
###############################################################################

from nessi_vector_bind import *
import utils_bind

print "##########################"
print "# Checking Utils Package #"
print "##########################"
print

# Set standard size for vectors
vec_length = 5

# Create input vectors
Input1_F = FloatNessiVector()
Input1_Err2_F = FloatNessiVector()
Input1_D = DoubleNessiVector()
Input1_Err2_D = DoubleNessiVector()

for counter in range(vec_length):
    Input1_F.append(float(counter+1))
    Input1_D.append(float(counter+1))
    Input1_Err2_F.append(float(1))
    Input1_Err2_D.append(float(1))

# Create truth vectors and values

# Truth information for weighted_average
truth_output_wa = float(3)
truth_output_err2_wa = 0.2

# Create output placeholders

# Output placeholders for weighted_average
output_wa = 0.0
output_err2_wa = 0.0

print "Testing Weighted Average Binding Functions"
print "weighted_average_f..........."

utils_bind.weighted_average_f(Input1_F, Input1_Err2_F,
                              float(0), float(vec_length-1),
                              output_wa, output_err2_wa)

print "weighted_average_d..........."

utils_bind.weighted_average_f(Input1_D, Input1_Err2_D,
                              float(0), float(vec_length-1),
                              output_wa, output_err2_wa)


