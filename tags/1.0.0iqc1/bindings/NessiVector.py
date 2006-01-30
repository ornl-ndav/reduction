from array_manip_bind import UnsignedIntNessiVector
from array_manip_bind import FloatNessiVector
from array_manip_bind import IntNessiVector
from array_manip_bind import DoubleNessiVector

class NessiVector (list):
	' class that allows to launch the right' 
	' function according to the type'
	' of the instance'

	version = 0.1	
	FLOAT = "float"	
	DOUBLE = "double"	
	UINT = "uint"	
	UNSIGNED = "unsigned"
	UNSIGNED_INT = "unsigned int"
	INT = "int"

	def __init__(self, length=0, type="float"):
	
		if type.lower()==NessiVector.UNSIGNED_INT or \
		type.lower()==NessiVector.UNSIGNED or \
		type.lower()==NessiVector.UINT:
			self.type__=self.UINT
		
			if length >= 0:
				self.__array = 	UnsignedIntNessiVector(length)
			else:
				raise Exception, "Cannot instantiate Vector with negative length" 
	
		elif type.lower()==NessiVector.INT:
			self.type__=self.INT

			if length >= 0:
				self.__array = IntNessiVector(length)
			else:
				raise Exception, "Cannot instantiate Vector with negative length"

		elif type.lower() == NessiVector.FLOAT:
			self.type__=self.FLOAT

			if length >= 0:
				self.__array = FloatNessiVector(length)
			else:
				raise Exception, "Cannot instantiate Vector with negative length"

		elif type.lower() == NessiVector.DOUBLE:
			self.type__ = self.DOUBLE

			if length >= 0:
				self.__array = DoubleNessiVector(length)
			else:
				raise Exception, "Cannot instantiate Vector with negative length"
		else:
			raise Exception,"type not supported by NessiVector"

	def append(self,number):
		self.__array.append(number)

	def __getitem__(self,m):			# need to throw exception when m>len(self)
		return self.__array[m]

	def __getslice__(self,i=0,j=-1):
		print self.__array[i:j]
    
	def __len__(self):
		return len(self.__array)	

	def __getattr__(self,name):      # for print instance
		if(name=="array"):
			return self.__array

	def __add__(self,right):
#		for i in range(len(self.__array)):
#			print self.__array[i] + right.__array[i]
		print "Not implemented yet"

	def __contains__(self):
		print  "Not implemented yet"

	def __eq__(self):
	    raise exception, "Not implemented yet"


	def __ge__(self):
		raise exception, "Not implemented yet"
	
	
	def __gt__(self):
		raise exception, "Not implemented yet"

	
	def __ne__(self):
		raise exception, "Not implemented yet"

	
	def __lt__(self):
		raise exception, "Not implemented yet"


	def pop(self):
		if len(self.__array)<=0:
			raise IndexError,"pop from empty Vector"
		return self.__array.pop()



	