from NessiVector import NessiVector
from array_manip_bind import add_ncerr_f
from array_manip_bind import add_ncerr_d
from array_manip_bind import add_ncerr_i
from array_manip_bind import add_ncerr_u

def add(a,ae2,b=NessiVector(),be2=NessiVector()):

	if (a.type__ != b.type__):
		print "Arrays do not have the same type"
	else:
		b_length = len(b)

		if (b_length == 0):				#for case: add(a,b)
			b=ae2
			be2=NessiVector(len(a))

		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		

		if (a.type__ == a.FLOAT):
			add_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
		if (a.type__ == a.DOUBLE):
			add_ncerr_d(a.array.ae2.array,b.array,be2.array,c.array,ce2.array)
		if (a.type__ == a.INT):
			add_ncerr_i(a.array.ae2.array,b.array,be2.array,c.array,ce2.array)
		if (a.type__ == a.UNSIGNED_INT):
			add_ncerr_u(a.array.ae2.array,b.array,be2.array,c.array,ce2.array)

	if (b_length == 0):					#add(a,b)
		return c
	else:								#add(a,ae2,b,be2)
		return c,ce2


			
