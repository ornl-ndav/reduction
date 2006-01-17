from NessiVector import NessiVector
import sys

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
				print "%7.16f" %object1[i], tab , "%7.16f" %object2[i],
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
