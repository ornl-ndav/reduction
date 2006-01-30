import array_manip_bind
from array_manip_bind import *
import string

class NessiVector (list):
    'Nessi class Vector that will allow to launch the right' \
    'add_vec_vec_ncerr function according to the instance type'
	
    version = 0.1
    FLOAT = "float"
    DOUBLE = "double"

    def __init__(self, length=0, type="float"):

	if type.lower() == NessiVector.FLOAT:
	    __type=self.__class__.FLOAT

            if length >= 0:
		self.__array = FloatVector(length)
	    else:
		raise Exception, "Cannot instantiate Vector with negative length"
	    
	elif type.lower() == NessiVector.DOUBLE:

	    if length > 0:
		self.__array = DoubleVector(length)
	    else:
		self.__array = DoubleVector()

	    self.__type = "double"

	else:
            raise Exception,"type not supported by MyClass"

    def append(self,number):
	self.__array.append(number)

    def pop(self):
	if len(self.__array)<=0:
            raise IndexError,"pop from empty Vector"

        return self.__array.pop()

    def __getitem__(self,m):
	return self.__array[m]

    def __getslice__(self,i=0,j=-1):
	print self.__array[i:j]

    def __len__(self):
	return len(self.__array)	
	
    def __getattr__(self,name):      # for print instance
        if(name=="array"):
            return self.__array

        return self.__getattr__(self,name)
