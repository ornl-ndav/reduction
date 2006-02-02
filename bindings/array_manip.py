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
# \file bindings/array_manip.py wrapper of array_manip library
#

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
import sys

##
# This module gives the NessiVector access to the various simple 
# arithmetic operations on arrays provided by the <i>array_manip</i> 
# library. These arithmetic operations are written in references to SNS
# 107030214-TD0001-R00, "Data Reduction Library Software Requirements and
# Specifications". 
#
# Once a function is called, according to the type of the NessiVectors calling it,
# the module redirects the call to the right function.
#
# For example, when calling the function \f$add\f$ with two NessiVector of type 
# <i>float</i>, the module redirects the call to the function \f$add\_f\f$.
#

##
# \defgroup add add
# \{
# This function adds each element of two NessiVector.
#
# This function accepts two or four NessiVector as arguments. The addition of 
# a NessiVector with a scalar is not supported yet.
# 
# With two arguments,
# \f[
# >>>  Vector_0 = add (Vector_1, Vector_2)
# \f]
#
# With four arguments,
# \f[
# >>> Vector_0, \sigma_0 = add (Vector_1, 
# \sigma_1, Vector_2, 
# \sigma_2)
# \f]
# 
# For both cases, this function adds each element, \f$i\f$, of two NessiVector 
# according to the equations
# \f[
# Vector_0[i] = Vector_1[i] + Vector_2[i]
# \f]
# and
# \f[
# \sigma_0[i] = \sigma_1^2[i] + 
# \sigma_2^2[i]
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output 
# NessiVector, \f$Vector_1[i]\f$ is the \f$i^{th}\f$ component of the first
# NessiVector being added, \f$Vector_2[i]\f$ it the \f$i^{th}\f$ component
# of the second NessiVector being added, \f$\sigma_0[i]\f$ is the 
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector, 
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the first NessiVector, and \f$\sigma_2[i]\f$ is the \f$i^{th}\f$ 
# component of the uncertainty in the second NessiVector. 
#
# \param a (INPUT) is the first NessiVector to be added
# \param ae2 (INPUT) is the second NessiVector to be added if there are no more
# arguments present, otherwise it's the square of the uncertainty in the first
# NessiVector to be added
# \param b (INPUT/OPTIONAL) is the second NessiVector to be added
# \param be2 (INPUT/OPTIONAL) required only if b is present, is the square of the 
# uncertainty in the second NessiVector to be added
#

def add(a,ae2,b=NessiVector(),be2=NessiVector()):

	b_length = len(b)

	if (b_length == 0):				#for case: add(a,b)
		b=ae2

	if (a.type__ == a.FLOAT):
		if (b_length ==0): be2=NessiVector(len(a))
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		add_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.DOUBLE):
		if (b_length ==0): be2=NessiVector(len(a),a.DOUBLE)
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		add_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.INT):
		if (b_length ==0): be2=NessiVector(len(a), a.INT)
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		add_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.UINT):
		if (b_length ==0): be2=NessiVector(len(a),a.UINT)
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		add_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)

	if (b_length == 0):				#add(a,b)
		return c
	else:						#add(a,ae2,b,be2)
		return c,ce2
##
# \}

##
# \defgroup sub sub
# \{
# This function substracts each element of two NessiVector.
#
# This function accepts two or four NessiVector as arguments. The substraction of 
# a NessiVector with a scalar is not supported yet.
# 
# With two arguments,
# \f[
# >>>  Vector_0 = sub (Vector_1, Vector_2)
# \f]
#
# With four arguments,
# \f[
# >>> Vector_0, \sigma_0 = sub (Vector_1, 
# \sigma_1, Vector_2, 
# \sigma_2)
# \f]
# 
# For both cases, this function substracts each element, \f$i\f$, of two NessiVector
# according to the equations
# \f[
# Vector_0[i] = Vector_1[i] - Vector_2[i]
# \f]
# and
# \f[
# \sigma_0[i] = \sigma_1^2[i] + 
# \sigma_2^2[i]
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output 
# NessiVector, \f$Vector_1[i]\f$ is the \f$i^{th}\f$ component of the NessiVector
# being subtracted from, \f$Vector_2[i]\f$ it the \f$i^{th}\f$ component
# of the NessiVector subtracting, \f$\sigma_0[i]\f$ is the 
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector, 
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the first NessiVector, and \f$\sigma_2[i]\f$ is the \f$i^{th}\f$ 
# component of the uncertainty in the second NessiVector. 
#
# \param a (INPUT) is the NessiVector to be subtracted from
# \param ae2 (INPUT) is the NessiVector to subtract, if they are no more
# arguments present, otherwise it's the square of the uncertainty in the 
# NessiVector to be subtracted from
# \param b (INPUT/OPTIONAL) is the NessiVector to subtract 
# \param be2 (INPUT/OPTIONAL) required only if b is present, is the square of the 
# uncertainty in the NessiVector to subtract
#

def sub(a,ae2,b=NessiVector(),be2=NessiVector()):

	b_length = len(b)

	if (b_length == 0):				#for case: sub(a,b)
		b=ae2

	if (a.type__ == a.FLOAT):
		if (b_length ==0): be2=NessiVector(len(a))
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		sub_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.DOUBLE):
		if (b_length ==0): be2=NessiVector(len(a),a.DOUBLE)
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		sub_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.INT):
		if (b_length ==0): be2=NessiVector(len(a), a.INT)
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		sub_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.UINT):
		if (b_length ==0): be2=NessiVector(len(a),a.UINT)
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		sub_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)

	if (b_length == 0):				#sub(a,b)
		return c
	else:						#sub(a,ae2,b,be2)
		return c,ce2
##
# \}

##
# \defgroup mult mult
# \{
# This function multiplies each element of two NessiVector.
#
# This function accepts two or four NessiVector as arguments. The multiplication of 
# a NessiVector with a scalar is not supported yet.
# 
# With two arguments,
# \f[
# >>>  Vector_0 = mult (Vector_1, Vector_2)
# \f]
#
# With four arguments,
# \f[
# >>> Vector_0, \sigma_0 = mult (Vector_1, 
# \sigma_1, Vector_2, 
# \sigma_2)
# \f]
# 
# For both cases, this function multiplies each element, \f$i\f$, of two NessiVector
# according to the equations
# \f[
# Vector_0[i] = Vector_1[i] \times Vector_2[i]
# \f]
# and
# \f[
# \sigma_0[i] = (Vector_1[i]\times\sigma_1[i])^2 +(Vector_2[i]\times\sigma_2[i])^2
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output 
# NessiVector, \f$Vector_1[i]\f$ is the \f$i^{th}\f$ component of the first 
# NessiVector to be multiplied, \f$Vector_2[i]\f$ it the \f$i^{th}\f$ component
# of the second NessiVector to be multiplied, \f$\sigma_0[i]\f$ is the 
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector, 
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the first NessiVector, and \f$\sigma_2[i]\f$ is the \f$i^{th}\f$ 
# component of the uncertainty in the second NessiVector. 
#
# \param a (INPUT) is the first NessiVector to be multiplied
# \param ae2 (INPUT) is the second NessiVector to multiplied, if they are no more
# arguments present, otherwise it's the square of the uncertainty in the first 
# NessiVector to be multiplied 
# \param b (INPUT/OPTIONAL) is the second NessiVector to be multiplied
# \param be2 (INPUT/OPTIONAL) required only if b is present, is the square of the 
# uncertainty in the second NessiVector to be multiplied
#

def mult(a,ae2,b=NessiVector(),be2=NessiVector()):

	b_length = len(b)

	if (b_length == 0):				#for case: mult(a,b)
		b=ae2

	if (a.type__ == a.FLOAT):
		if (b_length ==0): be2=NessiVector(len(a))
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		mult_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.DOUBLE):
		if (b_length ==0): be2=NessiVector(len(a),a.DOUBLE)
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		mult_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.INT):
		if (b_length ==0): be2=NessiVector(len(a), a.INT)
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		mult_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.UINT):
		if (b_length ==0): be2=NessiVector(len(a),a.UINT)
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		mult_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)

	if (b_length == 0):				#mult(a,b)
		return c
	else:						#mult(a,ae2,b,be2)
		return c,ce2
##
# \}

##
# \defgroup div div
# \{
# This function divides each element of two NessiVector.
#
# This function accepts two or four NessiVector as arguments. The division of 
# a NessiVector by a scalar, or of a scalar by a NessiVector is not supported yet.
# 
# With two arguments,
# \f[
# >>>  Vector_0 = div (Vector_1, Vector_2)
# \f]
#
# With four arguments,
# \f[
# >>> Vector_0, \sigma_0 = div (Vector_1, 
# \sigma_1, Vector_2, 
# \sigma_2)
# \f]
# 
# For both cases, this function divides each element, \f$i\f$, of two NessiVector
# according to the equations
# \f[
# Vector_0[i] = Vector_1[i] / Vector_2[i]
# \f]
# and
# \f[
# \sigma_0[i] = \left(\frac{Vector_1[i]\times\sigma_2[i]}{Vector_2^2[i]}\right)
# ^2 +\left(\frac{\sigma_1[i]}{Vector_2[i]}\right)^2
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output 
# NessiVector, \f$Vector_1[i]\f$ is the \f$i^{th}\f$ component of the 
# NessiVector being divided, \f$Vector_2[i]\f$ it the \f$i^{th}\f$ component
# of the dividing NessiVector, \f$\sigma_0[i]\f$ is the 
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector, 
# \f$\sigma_1[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the NessiVector being divided, and \f$\sigma_2[i]\f$ is the \f$i^{th}\f$ 
# component of the uncertainty in the divided NessiVector. 
#
# \param a (INPUT) is the NessiVector being divided
# \param ae2 (INPUT) is the dividing NessiVector, if they are no more
# arguments present, otherwise it's the square of the uncertainty in the  
# NessiVector being divided 
# \param b (INPUT/OPTIONAL) is the dividing NessiVector
# \param be2 (INPUT/OPTIONAL) required only if b is present, is the square of the 
# uncertainty in the dividing NessiVector
#

def div(a,ae2,b=NessiVector(),be2=NessiVector()):

	b_length = len(b)

	if (b_length == 0):				#for case: div(a,b)
		b=ae2

	if (a.type__ == a.FLOAT):
		if (b_length ==0): be2=NessiVector(len(a))
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		div_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.DOUBLE):
		if (b_length ==0): be2=NessiVector(len(a),a.DOUBLE)
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		div_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.INT):
		if (b_length ==0): be2=NessiVector(len(a), a.INT)
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		div_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.UINT):
		if (b_length ==0): be2=NessiVector(len(a),a.UINT)
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		div_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)

	if (b_length == 0):				#div(a,b)
		return c
	else:						#div(a,ae2,b,be2)
		return c,ce2

##
# \}

##
# \defgroup sumw sumw
# \{
# This function adds two NessiVector weighted by their uncertainties.
#
# This function adds two NessiVector weighted by their uncertainties according to 
# the equation:
# \f[
# Vector_0[i]=\left( \sum^2_{n=1} \frac{Vector_n[i]}{\sigma_n[i]}\right)
# \times\left( \frac{1}{2} \sum^2_{n=1} \sigma_n[i] \right)
# \f]
# and 
# \f[
# \sigma_0^2[i]=(\sigma_1^2\sigma_2 + \sigma_1\sigma_2^2)(\sigma_1+\sigma_2)
# \f]
# However, if the uncertainty in any of the data is zero, the value of the 
# \f$Vector_0[i]\f$ will be given by
# \f[
# Vector_0[i]=\sum^2_{n=1} Vector_n[i]
# \f]
# where \f$Vector_0[i]\f$ is the \f$i^{th}\f$ component of the output 
# NessiVector, \f$Vector_n[i]\f$ is the \f$i^{th}\f$ component of the \f$n^{th}\f$
# NessiVector being added, \f$\sigma_0[i]\f$ is the 
# \f$i^{th}\f$ component of the uncertainty of the output NessiVector, 
# \f$\sigma_n[i]\f$ is the \f$i^{th}\f$ component of the uncertainty
# in the \f$n^{th}\f$ NessiVector being added.
#
# \param a (INPUT) is the first NessiVector to be added
# \param ae2 (INPUT) is the square of the uncertainty in the first NessiVector to be
# added
# \param b (INPUT) is the second NessiVector to be added
# \param be2 (INPUT) is the square of the uncertainty in the second NessiVector to be
# added
#

def sumw(a,ae2,b,be2):

	if (a.type__ == a.FLOAT):
		c = NessiVector(len(a));		
		ce2 = NessiVector(len(a));		
		sumw_ncerr_f(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.DOUBLE):
		c = NessiVector(len(a),a.DOUBLE)
		ce2 = NessiVector(len(a), a.DOUBLE)
		sumw_ncerr_d(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.INT):
		c = NessiVector(len(a),a.INT)
		ce2 = NessiVector(len(a), a.INT)
		sumw_ncerr_i(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)
	if (a.type__ == a.UINT):
		c = NessiVector(len(a),a.UINT)
		ce2 = NessiVector(len(a), a.UINT)
		sumw_ncerr_u(a.array,ae2.array,b.array,be2.array,c.array,\
		ce2.array)

	return c,ce2

##
# \}
