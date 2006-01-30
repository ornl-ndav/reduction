#!/usr/bin/env python
##############################################################################
# 
# Script for checking the functionality of Array Manipulation functions
#
# $Id$
#
##############################################################################
from array_manip_bind import *

import sys

def print_vect(object):
    for i in range(len(object)):
	print object[i],

    print

print "Checking Array Manipulation Package"

a = FloatNessiVector()
a.append(1.5)
a.append(3.5)
a.append(5.5)

ae2 = FloatNessiVector()
ae2.append(0.15)
ae2.append(0.35)
ae2.append(0.55)

b = FloatNessiVector()
b.append(2.5)
b.append(4.5)
b.append(6.5)

be2 = FloatNessiVector()
be2.append(0.25)
be2.append(0.45)
be2.append(0.65)

c = FloatNessiVector(len(a))
ce2 = FloatNessiVector(len(ae2))

print "Array A: ",
print_vect(a)
print "Array A error2: ",
print_vect(ae2)
print "Array B: ",
print_vect(b)
print "Array B error2: ",
print_vect(be2)

add_ncerr_f(a, ae2, b, be2, c, ce2)

print "Added Vector: ",
print_vect(c)
print "Added Vector error2: ",
print_vect(ce2)

d = FloatNessiVector(2)
de2 = FloatNessiVector(2)

print "Checking Add Vector to Vector Function with Invalid Output Vector"

add_ncerr_f(a, ae2, b, be2, d, de2)

print "Done."
