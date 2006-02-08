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

# $Id$

## 
#\file bindings/NessiVector.py Python binding of SNS Common Libraries
#

from array_manip_bind import UnsignedIntNessiVector
from array_manip_bind import FloatNessiVector
from array_manip_bind import IntNessiVector
from array_manip_bind import DoubleNessiVector

from array_manip_bind import add_ncerr_f
from array_manip_bind import add_ncerr_d
from array_manip_bind import add_ncerr_i
from array_manip_bind import add_ncerr_u

from array_manip_bind import sub_ncerr_f
from array_manip_bind import sub_ncerr_d
from array_manip_bind import sub_ncerr_i
from array_manip_bind import sub_ncerr_u

from array_manip_bind import mult_ncerr_f
from array_manip_bind import mult_ncerr_d
from array_manip_bind import mult_ncerr_i
from array_manip_bind import mult_ncerr_u

from array_manip_bind import div_ncerr_f
from array_manip_bind import div_ncerr_d
from array_manip_bind import div_ncerr_i
from array_manip_bind import div_ncerr_u

##
# \brief The purpose of this class is to provide an abstraction layer that
# hide the call to the functions according to the type of the instance.
#
# This class plays the role of a template for the function called
#
# For example: let us add together two NessiVectors of type float.
# Once the two NessiVector have been defined and fill with data, using the
# function <i>add</i> is like using the function <i>add_f</i>
# \f[
# >>> NessiVector_result = add(NessiVector_1, NessiVector_2)
# \f]
class NessiVector (list):

	version = 0.1	
	FLOAT = "float"	
	DOUBLE = "double"	
	UINT = "uint"	
	UNSIGNED = "unsigned"
	UNSIGNED_INT = "unsigned int"
	INT = "int"

##
# \defgroup __init__ NessiVector::__init__
# \{

##
# Initialization of an instance.
# A NessiVector can be defined in 4 ways. 
#
# - Without any argument:
# \f[
# >>> MyVector1 = NessiVector()
# \f]
# in such case, the NessiVector is empty and of type <i>float</i> by default.
#
# - By declaring its size:
# \f[
# >>> MyVector2 = NessiVector(2)
# \f]
# MyVector2 contains 2 elements, set to 0, of type <i>float</i> (by default)
#
# - By declaring its type:
# \f[
# >>> MyVector3 = NessiVector(type="double")
# \f]
# MyVector3 is an empty NessiVector of type <i>double</i>
#
# - By declaring its size and type:
# \f[
# >>> MyVector4 = NessiVector(4,"int")
# \f]
# \f$MyVector4\f$ is a 4 elements long, initialized to 0, NessiVector of type 
# <i>int</i>
#
# \param self (INPUT) is the name of the NessiVector
# \param length (INPUT/OPTIONAL) is the length of the instance (0 by default)
# \param type (INPUT/OPTIONAL) is the type of the instance (<i>float</i> by 
# default)
#
	def __init__(self, length=0, type="float"):
	
		if type.lower()==NessiVector.UNSIGNED_INT or \
		type.lower()==NessiVector.UNSIGNED or \
		type.lower()==NessiVector.UINT:
			self.type__=self.UINT
		
			if length >= 0:
				self.__array = 	UnsignedIntNessiVector(length)
			else:
				raise Exception, "Cannot instantiate Vector \
						with negative length" 
	
		elif type.lower()==NessiVector.INT:
			self.type__=self.INT

			if length >= 0:
				self.__array = IntNessiVector(length)
			else:
				raise Exception, "Cannot instantiate Vector \
				with negative length"

		elif type.lower() == NessiVector.FLOAT:
			self.type__=self.FLOAT

			if length >= 0:
				self.__array = FloatNessiVector(length)
			else:
				raise Exception, "Cannot instantiate Vector \
				with  negative length"

		elif type.lower() == NessiVector.DOUBLE:
			self.type__ = self.DOUBLE

			if length >= 0:
				self.__array = DoubleNessiVector(length)
			else:
				raise Exception, "Cannot instantiate Vector \
				with negative length"
		else:
			raise Exception,"type not supported by NessiVector"
##
# \}

##
# \defgroup __append__ NessiVector::__append__
# \{

##
# \brief Function used to append elements to a NessiVector
#
# This function is used to append a value to an instance of the NessiVector,
# <i>MyNessiVector</i>:
# \f[
# >>> MyNessiVector.append(10.5)
# \f]
# The size of the instance increases of 1 unit and the new element appended is
# the new last element of the instance. That can be a confusion in the case the
# size of the instance has already been declared during the initialization
# process. For example, if a NessiVector has been defined has a 5 elements 
# long of type <i>float</i>
# \f[
# >>> MyVector = NessiVector(5)
# \f]
# the <i>append</i> method will add the new element after the 5 first "0". 
# elements
# \f[
# >>> MyVector.append(10.5)
# \f]
# \f[
# >>> MyVector[5]
# \f]
# \f[
# 10.5
# \f]
# It is also possible to append several values in the same time as illustrated
# here:
# \f[
# >>> MyNessiVector.append(1,2,3,4,5,6,7,8)
# \f]
# This is the same as appending 1, then 2, then 3, and so on.... one after
# the other.
# \f[
# >>> MyVector.append(1)
# \f]
# \f[
# >>> MyVector.append(2)
# \f]
# \f[
# >>> MyVector.append(3)
# \f]
# \f[
# >>> MyVector.append(4)
# \f]
# \f[
# ...
# \f]
#
# \param self (INPUT) is the name of the NessiVector
# \param number (INPUT) is the number to append
#
	def append(self,*number):
		for i in range(len(number)):
			self.__array.append(number[i])

##
# \}

##
# \defgroup __getitem__ NessiVector::__getitem__
# \{

##
# \brief Function used to get an element of a NessiVector.
# To get the \f$i^{th}\f$ value of the NessiVector \f$MyVectorA\f$, 
#\f[
# >>> MyVectorA[i]
#\f]
# The last index of the NessiVector is displayed if one ask for an element
# of the NessiVector outside its range
#

	def __getitem__(self,m):     # need to throw exception when m>len(self)
		if (m<len(self)):
			return self.__array[m]
		else:
			print "Last index of this  NessiVector is ",len(self)-1
##			
# \}

##
# \defgroup __getslice__ NessiVector::__getslice__
# \{

##
# Function used to get a range of value from a NessiVector.
# \f[
# >>> MyVector[0:5]
# \f]
# displays the 5 first elements of \f$MyVector\f$
#
# \param self (INPUT) is the name of the NessiVector
# \param i (INPUT/OPTIONAL) is the index of the first element to get (0 by
# default, i.e., first element of the NessiVector)
# \param j (INPUT/OPTIONAL) is the index + 1 of the last element to get (-1 by 
# default, i.e., last element of the NessiVector)

	def __getslice__(self,i=0,j=-1):
		print self.__array[i:j]
##
# \}
    
##
# \defgroup __len__ NessiVector::__len__
# \{

##
# Function used to get the length of a NessiVector
#
# \f[
# >>> len(MyVectorA)
# \f]
#
# \param self (INPUT) is the name of the NessiVector
#

	def __len__(self):
		return len(self.__array)	
##
# \}

##
# \defgroup __getattr__ NessiVector::__getattr__
# \{

##
# Function that called the __array attribute of the NessiVector.
# 
# When asking for a value of the NessiVector \f$MyVector\f$, Python translates
# the operation into a call to \f$MyVector.\_\_getattr\_\_\f$. 
# \param self (INPUT) is the name of the NessiVector
# \param name (INPUT) is the name of the attribute to be called
#
	def __getattr__(self,name):      
		if(name=="array"):
			return self.__array
##
# \}

##
# \defgroup __add__ NessiVector::__add__
# \{

## 
# \brief The operator \f$+\f$ allows to add two NessiVector together.
#
# To add two NessiVectors together, instead of using the function <i>add</i>
# provided by the NessiVectorUtils module, you can simply use the following
# technique:
# \f[
# <<< NessiVector_{result} = NessiVector_1 + NessiVector_2
# \f]
#
	def __add__(self,right):
		if (self.type__ == NessiVector.FLOAT):
			c = NessiVector(len(self))
			add_ncerr_f(self.array, self.array, right.array,\
			right.array,c.array, c.array)
		if (self.type__ == NessiVector.DOUBLE):
			c = NessiVector(len(self),type="double")
			add_ncerr_d(self.array, self.array, right.array,\
			right.array,c.array, c.array)
		if (self.type__ == NessiVector.INT):
			c = NessiVector(len(self),type="int")
			add_ncerr_i(self.array, self.array, right.array,\
			right.array,c.array, c.array)
		if (self.type__ == NessiVector.UINT):
			c = NessiVector(len(self),type="uint")
			add_ncerr_u(self.array, self.array, right.array,\
			right.array,c.array, c.array)
		return c
##
# \}

##
# \defgroup __sub__ NessiVector::__sub__
# \{

##
# \brief The operator \f$-\f$ allows to substract two NessiVectors.
#
# To substract one NessiVector from another, instead of using the function
# <i>sub</i> provided by the NessiVectorUtils module, you can simply use the 
# following technique:
# \f[
# <<< NessiVector_{result} = NessiVector_1 - NessiVector_2
# \f]
#
	def __sub__(self,right):
		if (self.type__ == NessiVector.FLOAT):
			c = NessiVector(len(self))
			ce2 = NessiVector(len(self))
			sub_ncerr_f(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		if (self.type__ == NessiVector.DOUBLE):
			c = NessiVector(len(self),type="double")
			ce2 = NessiVector(len(self),type="double")
			sub_ncerr_d(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		if (self.type__ == NessiVector.INT):
			c = NessiVector(len(self),type="int")
			ce2 = NessiVector(len(self),type="int")
			sub_ncerr_i(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		if (self.type__ == NessiVector.UINT):
			c = NessiVector(len(self),type="uint")
			ce2 = NessiVector(len(self),type="uint")
			sub_ncerr_u(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		return c
		
##
# \}

##
# \defgroup __mul__ NessiVector::__mul__
# \{

## 
# \brief The operator \f$\times\f$ allows to multiply two NessiVectors.
#
# To multiply two NessiVectors, instead of using the function <i>mult</i> 
# provided by the NessiVectorUtils module, you can simply use the following
# technique:
# \f[
# <<< NessiVector_{result} = NessiVector_1 \times NessiVector_2
# \f]
#
	def __mul__(self,right):
		if (self.type__ == NessiVector.FLOAT):
			c = NessiVector(len(self))
			ce2 = NessiVector(len(self))
			mult_ncerr_f(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		if (self.type__ == NessiVector.DOUBLE):
			c = NessiVector(len(self),type="double")
			ce2 = NessiVector(len(self),type="double")
			mult_ncerr_d(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		if (self.type__ == NessiVector.INT):
			c = NessiVector(len(self),type="int")
			ce2 = NessiVector(len(self),type="int")
			mult_ncerr_i(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		if (self.type__ == NessiVector.UINT):
			c = NessiVector(len(self),type="uint")
			ce2 = NessiVector(len(self),type="uint")
			mult_ncerr_u(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		return c

##
# \}
		
##
# \defgroup __div__ NessiVector::__div__
# \{

## 
# \brief The operator \f$/\f$ allows to divide two NessiVectors.
#
# To divide two NessiVectors, instead of using the function <i>div</i> 
# provided by the NessiVectorUtils module, you can simply use the following
# technique:
# \f[
# <<< NessiVector_{result} = NessiVector_1 / NessiVector_2
# \f]
#
	def __div__(self,right):
		if (self.type__ == NessiVector.FLOAT):
			c = NessiVector(len(self))
			ce2 = NessiVector(len(self))
			div_ncerr_f(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		if (self.type__ == NessiVector.DOUBLE):
			c = NessiVector(len(self),type="double")
			ce2 = NessiVector(len(self),type="double")
			div_ncerr_d(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		if (self.type__ == NessiVector.INT):
			c = NessiVector(len(self),type="int")
			ce2 = NessiVector(len(self),type="int")
			div_ncerr_i(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		if (self.type__ == NessiVector.UINT):
			c = NessiVector(len(self),type="uint")
			ce2 = NessiVector(len(self),type="uint")
			div_ncerr_u(self.array, self.array, right.array,\
			right.array,c.array, ce2.array)
		return c

##
# \}

##
# \defgroup __contains__ NessiVector::__contains__
# \{

##
# Function "__contains__" not implemented yet
#
	def __contains__(self):
		print  "Not implemented yet"
##
# \}

##
# \defgroup __eq__ NessiVector::__eq__
# \{

##
# Function "__eq__" not implemented yet
#

	def __eq__(self):
	    raise exception, "Not implemented yet"
##
# \}

##
# \defgroup __ge__ NessiVector::__ge__
# \{

##
# Function "__ge__" not implemented yet
#
	def __ge__(self):
		raise exception, "Not implemented yet"
##
# \}	
	
##
# \defgroup __gt__ NessiVector::__gt__
# \{

##
# Function "__gt__" not implemented yet
#
	def __gt__(self):
		raise exception, "Not implemented yet"
##
# \}
	
##
# \defgroup __ne__ NessiVector::__ne__
# \{

##
# Function "__ne__" not implemented yet
#
	def __ne__(self):
		raise exception, "Not implemented yet"
##
# \}
	
##
# \defgroup __lt__ NessiVector::__lt__
# \{

##
# Function "__lt__" not implemented yet
#
	def __lt__(self):
		raise exception, "Not implemented yet"
##
# \}

##
# \defgroup __pop__ NessiVector::__pop__
# \{

##
# Function "pop" not implemented yet"
#
	def pop(self):
		if len(self.__array)<=0:
			raise IndexError,"pop from empty Vector"
#		return self.__array.pop()

##
# \}

