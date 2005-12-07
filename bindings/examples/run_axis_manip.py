###############################################################################
# 
# Script that checks the functionality of the Axis Manipulation functions
#
# $Id$
#
###############################################################################
import axis_manip 
from axis_manip import *

import sys

def print_vect(object):
    for i in range(len(object)):
	print object[i],

    print

print "Checking Axis Manipulation Package"

print "Checking Reverse Array Function"
a = IntVector(3)
a[0] = 0
a[1] = 1
a[2] = 2

print "Original Array: ",
print_vect(a)

b = IntVector(3)

axis_manip.reverse_array_i(a, b)

print "Reversed Array: ",
print_vect(b)

print "Checking Velocity to Energy Function"

ae2 = IntVector(3)
ae2[0] = 0
ae2[1] = 1
ae2[1] = 2

be2 = IntVector(3)

axis_manip.velocity_to_energy_i(a, ae2, b, be2)

print "Done Checking Axis Manipulation"