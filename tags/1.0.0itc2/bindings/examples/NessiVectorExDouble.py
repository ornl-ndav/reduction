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
print "####Checking Array Manipulation Package for double####"

#Initialization of vectors a and b
a = NessiVector(0,"double")
a.append(1.5)
a.append(4.5)
a.append(6.5)

ae2 = NessiVector(0,"double")
ae2.append(0.15)
ae2.append(1.25)
ae2.append(2.35)

b = NessiVector(0,"double")
b.append(1.5)
b.append(4.5)
b.append(7.5)

be2 = NessiVector(0,"double")
be2.append(0.55)
be2.append(1.65)
be2.append(2.75)  

c = NessiVector(len(a),"double")
ce2 = NessiVector(len(ae2),"double")

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
print "%2.2f" %ae2[0], "\t\t", "%2.2f" %be2[0],"\t\t","%2.2f" %ce2[0]
print "%2.2f" %ae2[1], "\t\t", "%2.2f" %be2[1],"\t\t","%2.2f" %ce2[1]
print "%2.2f" %ae2[2], "\t\t", "%2.2f" %be2[2],"\t\t","%2.2f" %ce2[2],
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
print "%2.2f" %ae2[0], "\t\t", "%2.2f" %be2[0],"\t\t","%2.2f" %ce2[0]
print "%2.2f" %ae2[1], "\t\t", "%2.2f" %be2[1],"\t\t","%2.2f" %ce2[1]
print "%2.2f" %ae2[2], "\t\t", "%2.2f" %be2[2],"\t\t","%2.2f" %ce2[2],
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
print "%2.2f" %ae2[0], "\t\t", "%2.2f" %be2[0],"\t\t","%2.2f" %ce2[0]
print "%2.2f" %ae2[1], "\t\t", "%2.2f" %be2[1],"\t\t","%2.2f" %ce2[1]
print "%2.2f" %ae2[2], "\t\t", "%2.2f" %be2[2],"\t\t","%2.2f" %ce2[2],
print "\n"

c=div(a,b)
print ">>>c=div(a,b)"
print "a\t\tb\t\tc=a/b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t%2.2f"%c[0]
print a[1], "\t\t", b[1],"\t\t%2.2f"%c[1]
print a[2], "\t\t", b[2],"\t\t%2.2f"%c[2],
print "\n"

c,ce2 = div(a,ae2,b,be2)
print ">>>c,ce2=div(a,ae2,b,be2)"
print "a\t\tb\t\tc=a/b\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t%2.2f"%c[0]
print a[1], "\t\t", b[1],"\t\t%2.2f"%c[1]
print a[2], "\t\t", b[2],"\t\t%2.2f"%c[2],
print "\n"
print "ae2\t\tbe2\t\tce2\n",
print "**********************************************"
print "%2.2f" %ae2[0], "\t\t", "%2.2f" %be2[0],"\t\t","%2.2f" %ce2[0]
print "%2.2f" %ae2[1], "\t\t", "%2.2f" %be2[1],"\t\t","%2.2f" %ce2[1]
print "%2.2f" %ae2[2], "\t\t", "%2.2f" %be2[2],"\t\t","%2.2f" %ce2[2],
print "\n"

c=sumw(a,b)
print ">>>c=sumw(a,b)"
print "a\t\tb\t\tc\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t%2.2f"%c[0]
print a[1], "\t\t", b[1],"\t\t%2.2f"%c[1]
print a[2], "\t\t", b[2],"\t\t%2.2f"%c[2],
print "\n"

c,ce2 = sumw(a,ae2,b,be2)
print ">>>c,ce2=sumw(a,ae2,b,be2)"
print "a\t\tb\t\tc\t\n",
print "**********************************************"
print a[0], "\t\t", b[0],"\t\t%2.2f"%c[0]
print a[1], "\t\t", b[1],"\t\t%2.2f"%c[1]
print a[2], "\t\t", b[2],"\t\t%2.2f"%c[2],
print "\n"
print "ae2\t\tbe2\t\tce2\n",
print "**********************************************"
print "%2.2f" %ae2[0], "\t\t", "%2.2f" %be2[0],"\t\t","%2.2f" %ce2[0]
print "%2.2f" %ae2[1], "\t\t", "%2.2f" %be2[1],"\t\t","%2.2f" %ce2[1]
print "%2.2f" %ae2[2], "\t\t", "%2.2f" %be2[2],"\t\t","%2.2f" %ce2[2],
print "\n"
