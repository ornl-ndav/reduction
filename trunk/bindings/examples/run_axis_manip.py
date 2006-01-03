#!/usr/bin/env python
###############################################################################
# 
# Script that checks the functionality of the Axis Manipulation functions
#
# $Id$
#
###############################################################################
from axis_manip_bind import *

def print_vect(object):
    for i in range(len(object)):
	print object[i],

    print

print "Checking Axis Manipulation Package"

print "Checking Reverse Array Function"
a = FloatNessiVector()
a.append(0)
a.append(1)
a.append(2)

print "Original Array: ",
print_vect(a)

b = FloatNessiVector(len(a))

reverse_array_cp_f(a, b)

print "Reversed Array: ",
print_vect(b)

print "Checking Velocity to Energy Function"

ae2 = FloatNessiVector()
ae2.append(0)
ae2.append(1)
ae2.append(2)

be2 = FloatNessiVector(len(ae2))

velocity_to_energy_f(a, ae2, b, be2)

print "Done Checking Axis Manipulation"