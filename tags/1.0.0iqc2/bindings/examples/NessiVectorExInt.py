##############################################
#
# Script for checking the functionality
# of the NessiVector class
# (Array Manipulation functions)
#
# >>> c = add(a,b)
# >>> c,ce2 = add(a,ae2,b,be2)
#
##############################################

from NessiVector import NessiVector

#import sys
import array_manip
from array_manip import add
from array_manip import sub
from array_manip import mult
from array_manip import div
from array_manip import sumw

def print_vect(object):
    for i in range(len(object)):
	print object[i]

    print

print
print "####Checking Array Manipulation Package for int####"

#Initialization of vectors a and b
a = NessiVector(0,"int")
a.append(2)
a.append(4)
a.append(6)

ae2 = NessiVector(0,"int")
ae2.append(0)
ae2.append(1)
ae2.append(2)

b = NessiVector(0,"int")
b.append(1)
b.append(4)
b.append(7)

be2 = NessiVector(0,"int")
be2.append(0)
be2.append(1)
be2.append(2)  

c = NessiVector(len(a),"int")
ce2 = NessiVector(len(ae2),"int")

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
print "ae2\t\tbe2\t\tce2\n",
print "**********************************************"
print ae2[0], "\t\t", be2[0],"\t\t", ce2[0]
print ae2[1], "\t\t", be2[1],"\t\t", ce2[1]
print ae2[2], "\t\t", be2[2],"\t\t", ce2[2],
print "\n"

c=sub(a,b)
print ">>>c=sub(a,b)"
print "a\t\tb\t\tc=a-b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t",c[0]
print a[1], "\t\t", b[1],"\t\t",c[1]
print a[2], "\t\t", b[2],"\t\t",c[2],
print "\n"

c,ce2 = sub(a,ae2,b,be2)
print ">>>c,ce2=sub(a,ae2,b,be2)"
print "a\t\tb\t\tc=a-b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t",c[0]
print a[1], "\t\t", b[1],"\t\t",c[1]
print a[2], "\t\t", b[2],"\t\t",c[2],
print "\n"
print "ae2\t\tbe2\t\tce2\n",
print "**********************************************"
print ae2[0], "\t\t", be2[0],"\t\t", ce2[0]
print ae2[1], "\t\t", be2[1],"\t\t", ce2[1]
print ae2[2], "\t\t", be2[2],"\t\t", ce2[2],
print "\n"

c=mult(a,b)
print ">>>c=mult(a,b)"
print "a\t\tb\t\tc=a*b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t",c[0]
print a[1], "\t\t", b[1],"\t\t",c[1]
print a[2], "\t\t", b[2],"\t\t",c[2],
print "\n"

c,ce2 = mult(a,ae2,b,be2)
print ">>>c,ce2=mult(a,ae2,b,be2)"
print "a\t\tb\t\tc=a*b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t",c[0]
print a[1], "\t\t", b[1],"\t\t",c[1]
print a[2], "\t\t", b[2],"\t\t",c[2],
print "\n"
print "ae2\t\tbe2\t\tce2\n",
print "**********************************************"
print ae2[0], "\t\t", be2[0],"\t\t", ce2[0]
print ae2[1], "\t\t", be2[1],"\t\t", ce2[1]
print ae2[2], "\t\t", be2[2],"\t\t", ce2[2],
print "\n"

c=div(a,b)
print ">>>c=div(a,b)"
print "a\t\tb\t\tc=a/b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t", c[0]
print a[1], "\t\t", b[1],"\t\t", c[1]
print a[2], "\t\t", b[2],"\t\t", c[2],
print "\n"

c,ce2 = div(a,ae2,b,be2)
print ">>>c,ce2=div(a,ae2,b,be2)"
print "a\t\tb\t\tc=a/b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t", c[0]
print a[1], "\t\t", b[1],"\t\t", c[1]
print a[2], "\t\t", b[2],"\t\t", c[2],
print "\n"
print "ae2\t\tbe2\t\tce2\n",
print "**********************************************"
print ae2[0], "\t\t", be2[0],"\t\t", ce2[0]
print ae2[1], "\t\t", be2[1],"\t\t", ce2[1]
print ae2[2], "\t\t", be2[2],"\t\t", ce2[2],
print "\n"

c=sumw(a,b)
print ">>>c=sumw(a,b)"
print "a\t\tb\t\tc\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t", c[0]
print a[1], "\t\t", b[1],"\t\t", c[1]
print a[2], "\t\t", b[2],"\t\t", c[2],
print "\n"

c,ce2 = sumw(a,ae2,b,be2)
print ">>>c,ce2=sumw(a,ae2,b,be2)"
print "a\t\tb\t\tc\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t", c[0]
print a[1], "\t\t", b[1],"\t\t", c[1]
print a[2], "\t\t", b[2],"\t\t", c[2],
print "\n"
print "ae2\t\tbe2\t\tce2\n",
print "**********************************************"
print ae2[0], "\t\t", be2[0],"\t\t", ce2[0]
print ae2[1], "\t\t", be2[1],"\t\t",ce2[1]
print ae2[2], "\t\t", be2[2],"\t\t",ce2[2],
print "\n"
