#
#                     SNS Common Libraries
#           A part of the SNS Analysis Software Suite.
#
#                  Spallation Neutron Source
#          Oak Ridge National Laboratory, Oak Ridge TN.
#
#
#                             NOTICE
#
# For this software and its associated documentation, permission is granted
# to reproduce, prepare derivative works, and distribute copies to the public
# for any purpose and without fee.
#
# This material was prepared as an account of work sponsored by an agency of
# the United States Government.  Neither the United States Government nor the
# United States Department of Energy, nor any of their employees, makes any
# warranty, express or implied, or assumes any legal liability or
# responsibility for the accuracy, completeness, or usefulness of any
# information, apparatus, product, or process disclosed, or represents that
# its use would not infringe privately owned rights.
#
#

# $Id $

##
# \file bindings/NessiVectorUtils.py Various functions used by the NessiVector

from NessiVector import NessiVector
import sys

##
# \defgroup print_vect print_vect
# \{

## 
# \brief This method displays elements of a NessiVector.
#
#  If the NessiVector contains more than 10 elements, the 10 first elements, 
# follow by 3 dots ". . ." and the last element of the NessiVector are displayed.
# The default number of elements displayed can be changed by giving this number
# as second variable to the <i>print_vect</i> method.
# 
# \param object (INPUT) is the name of the NessiVector
# \param last (INPUT/OPTIONAL) is the number of element to display, 10 by default
# 
# \return 
# - n first elements, 3 dots and last element of the NessiVector, 
# if the NessiVector contains more than n elements
# - all the elements of the NessiVector, if the NessiVector is smaller than n. 
#
# The number are displayed with 16 digits after the decimal separator.
#

def print_vect(object,last=10):
	
	if len(object)<last:
		last=len(object)	

	if (object.type__ == NessiVector.FLOAT or 
		object.type__ == NessiVector.DOUBLE):
		for i in range(0,last):
			print "%7.16f" %object[i],
	else:	
		for i in range(0,last):
			print object[i],

	if (object.type__ == NessiVector.FLOAT or  
		object.type__ == NessiVector.DOUBLE):
		if len(object) > last:
			print "...",
			print "%7.16f" %object[len(object)-1]
		else:
			print
	else:
		if len(object) > last:
			print "...",
			print object[len(object)-1]
		else:
			print
##
#\}

##
# \defgroup compare_vect compare_vect
# \{
#

##
# \brief Display side by side the first n elements of two, or three NessiVectors.
#
# \param n (INPUT) is number of element to display
# \param object1 (INPUT) is the name of the first NessiVector
# \param object2 (INPUT) is the name of the second NessiVector
# \param object3 (INPUT/OPTIONAL) is the name of the third NessiVector
#
# \return display of the first n elements of the two, or three NessiVectors.

def compare_vect(n,object1,object2,object3=NessiVector()):
	
	tab="\t\t"

	#find maximum value and then set the tab
	max_value = max_vect(object1) 

	if (max_value <= 9999):
		pass
	else:
		tab = tab + "\t"

	for i in range(0,n):	

		if (object1.type__ == NessiVector.FLOAT or
			object1.type__ == NessiVector.DOUBLE):
				print "%7.16f" %object1[i], tab , \
				"%7.16f" %object2[i],
				if len(object3) !=0:
					print tab,"%7.16f" %object3[i]
				else:
					print
		else:
			for i in range(0,n):
				print object1[i], tab, object2[i],
				if len(object3) !=0:
					print tab, object3[i]
				else:
					print
	print	
	
##
# \}
#

##
# \defgroup max_vect max_vect
# \{
#	

##
# \brief Give the maximum value of the NessiVector's elements
#
# \param object (INPUT) is the name of the NessiVector
#
# \return The maximum value of the NessiVector <i>object</i>
#
def max_vect(object):
	max_value = -sys.maxint
	for i in range(len(object)):
		if object[i]> max_value:
			max_value = object[i]
	if (object.type__ == NessiVector.FLOAT or
		object.type__ == NessiVector.DOUBLE):
		print "%7.16f" %max_value
	else:
		print max_value
	print		

##
# \}

##
# \defgroup min_vect min_vect
# \{
#

##
# \brief Give the minimum value of the NessiVector's elements
#
# \param object (INPUT) is the name of the NessiVector
#
# \return The minimum value of the NessiVector <i>object</i>.
#
def min_vect(object):
	min_value = sys.maxint
	for i in range(len(object)):
		if object[i] < min_value:
			min_value = object[i]
	if (object.type__ == NessiVector.FLOAT or
		object.type__ == NessiVector.DOUBLE):
		print "%7.16f" %min_value
	else:
		print min_value
	print		

##
# \}