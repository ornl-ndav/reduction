##############################################
#
# Script for checking the functionality
# of the NessiVector class
# (Array Manipulation functions)
#
##############################################

import NessiVector
from NessiVector import *

import sys

def print_vect(object):
    for i in range(len(object)):
	print object[i]

    print


print "Checking Array Manipulation Package for float"

a = NessiVector()
a.append(1.5)
a.append(3.5)
a.append(5.5)

ae2 = NessiVector()
ae2.append(0.15)
ae2.append(0.35)
ae2.append(0.55)

b = NessiVector()
b.append(2.5)
b.append(4.5)
b.append(6.5)

be2 = NessiVector()
be2.append(0.25)
be2.append(0.45)
be2.append(0.65)

c = NessiVector(len(a))
ce2 = NessiVector(len(ae2))

print "Array A: "
print_vect(a)
print "Array A error2: "
print_vect(ae2)
print "Array B: "
print_vect(b)
print "Array B error2: "
print_vect(be2)

add_vec_vec_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
print "Added NessiVector: "
print_vect(c)
print "Added NessiVector error2: "
print_vect(ce2)
