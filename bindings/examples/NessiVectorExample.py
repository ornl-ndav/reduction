##############################################
#
# Script for checking the functionality
# of the NessiVector class
# (Array Manipulation functions)
#
##############################################

from NessiVector import NessiVector
#from array_manip_bind import *
from array_manip_bind import add_ncerr_f

import sys
import array_manip
from array_manip import add

def print_vect(object):
    for i in range(len(object)):
	print object[i]

    print

print "Checking Array Manipulation Package for float"

#Initialization of vectors a and b
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

c=add(a,b)
print ">>>c=add(a,b)"
print "a\t\tb\t\tc=a+b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t",c[0]
print a[1], "\t\t", b[1],"\t\t",c[1]
print a[2], "\t\t", b[2],"\t\t",c[2],
print "\n"

c,ce2 = add(a,ae2,b,be2)
print ">>>c,ce2=add(a,ae2,b,be2)"
print "a\t\tb\t\tc=a+b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t",c[0]
print a[1], "\t\t", b[1],"\t\t",c[1]
print a[2], "\t\t", b[2],"\t\t",c[2],
print "\n"
print "ae2\t\tbe2\t\tce2=ae2+be2\n",
print "**********************************************"
print "%2.2f" %ae2[0], "\t\t", "%2.2f" %be2[0],"\t\t" "%2.2f" %ce2[0]
print "%2.2f" %ae2[1], "\t\t", "%2.2f" %be2[1],"\t\t","%2.2f" %ce2[1]
print "%2.2f" %ae2[2], "\t\t", "%2.2f" %be2[2],"\t\t","%2.2f" %ce2[2],
print "\n"


