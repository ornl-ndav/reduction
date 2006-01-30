from NessiVector import NessiVector
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
from array_manip_bind import sumw_ncerr_f
from array_manip_bind import sumw_ncerr_d
from array_manip_bind import sumw_ncerr_i
from array_manip_bind import sumw_ncerr_u

def add(a,ae2,b=NessiVector(),be2=NessiVector()):

	b_length = len(b)

	if (b_length == 0):				#for case: add(a,b)
		b=ae2

	if (a.type__ == a.FLOAT):
		if (b_length ==0): be2=NessiVector(len(a))
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		add_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.DOUBLE):
		if (b_length ==0): be2=NessiVector(len(a),a.DOUBLE)
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		add_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.INT):
		if (b_length ==0): be2=NessiVector(len(a), a.INT)
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		add_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.UINT):
		if (b_length ==0): be2=NessiVector(len(a),a.UINT)
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		add_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)

	if (b_length == 0):					#add(a,b)
		return c
	else:								#add(a,ae2,b,be2)
		return c,ce2


def sub(a,ae2,b=NessiVector(),be2=NessiVector()):

	b_length = len(b)

	if (b_length == 0):				#for case: sub(a,b)
		b=ae2

	if (a.type__ == a.FLOAT):
		if (b_length ==0): be2=NessiVector(len(a))
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		sub_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.DOUBLE):
		if (b_length ==0): be2=NessiVector(len(a),a.DOUBLE)
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		sub_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.INT):
		if (b_length ==0): be2=NessiVector(len(a), a.INT)
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		sub_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.UINT):
		if (b_length ==0): be2=NessiVector(len(a),a.UINT)
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		sub_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)

	if (b_length == 0):					#sub(a,b)
		return c
	else:								#sub(a,ae2,b,be2)
		return c,ce2

			

def mult(a,ae2,b=NessiVector(),be2=NessiVector()):

	b_length = len(b)

	if (b_length == 0):				#for case: mult(a,b)
		b=ae2

	if (a.type__ == a.FLOAT):
		if (b_length ==0): be2=NessiVector(len(a))
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		mult_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.DOUBLE):
		if (b_length ==0): be2=NessiVector(len(a),a.DOUBLE)
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		mult_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.INT):
		if (b_length ==0): be2=NessiVector(len(a), a.INT)
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		mult_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.UINT):
		if (b_length ==0): be2=NessiVector(len(a),a.UINT)
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		mult_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)

	if (b_length == 0):					#mult(a,b)
		return c
	else:								#mult(a,ae2,b,be2)
		return c,ce2


def div(a,ae2,b=NessiVector(),be2=NessiVector()):

	b_length = len(b)

	if (b_length == 0):				#for case: div(a,b)
		b=ae2

	if (a.type__ == a.FLOAT):
		if (b_length ==0): be2=NessiVector(len(a))
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		div_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.DOUBLE):
		if (b_length ==0): be2=NessiVector(len(a),a.DOUBLE)
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		div_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.INT):
		if (b_length ==0): be2=NessiVector(len(a), a.INT)
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		div_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.UINT):
		if (b_length ==0): be2=NessiVector(len(a),a.UINT)
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		div_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)

	if (b_length == 0):					#div(a,b)
		return c
	else:								#div(a,ae2,b,be2)
		return c,ce2

def sumw(a,ae2,b=NessiVector(),be2=NessiVector()):

	b_length = len(b)

	if (b_length == 0):				#for case: sumw(a,b)
		b=ae2

	if (a.type__ == a.FLOAT):
		if (b_length ==0): be2=NessiVector(len(a))
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		sumw_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.DOUBLE):
		if (b_length ==0): be2=NessiVector(len(a),a.DOUBLE)
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		sumw_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.INT):
		if (b_length ==0): be2=NessiVector(len(a), a.INT)
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		sumw_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)
	if (a.type__ == a.UINT):
		if (b_length ==0): be2=NessiVector(len(a),a.UINT)
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		sumw_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,ce2.array)

	if (b_length == 0):					#sumw(a,b)
		return c
	else:								#sumw(a,ae2,b,be2)
		return c,ce2
