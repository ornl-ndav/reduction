##############################################################################
# 
# Script for checking the functionality of Array Manipulation functions
#
# $Id$
#
##############################################################################
import array_manip 
from array_manip import *

import sys

def print_vect(object):
    for i in range(len(object)):
	print object[i],

    print

print "Checking Array Manipulation Package"

a = FloatVector(3)
a[0] = 1.5
a[1] = 3.5
a[2] = 5.5

ae2 = FloatVector(3)
ae2[0] = 0.15
ae2[1] = 0.35
ae2[2] = 0.55

b = FloatVector(3)
b[0] = 2.5
b[1] = 4.5
b[2] = 6.5

be2 = FloatVector(3)
be2[0] = 0.25
be2[1] = 0.45
be2[2] = 0.65

c = FloatVector(3)
ce2 = FloatVector(3)

print "Array A: ",
print_vect(a)
print "Array A error2: ",
print_vect(ae2)
print "Array B: ",
print_vect(b)
print "Array B error2: ",
print_vect(be2)

array_manip.add_vec_vec_ncerr_f(a, ae2, b, be2, c, ce2)

print "Added Vector: ",
print_vect(c)
print "Added Vector error2: ",
print_vect(ce2)
