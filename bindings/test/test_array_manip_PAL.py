###############################################################################
#					     				      #
# Script for checking the functionality        				      #
# of the NessiVector class                   				      #
# (Array Manipulation functions)             				      #
# 					     				      #
# >>> Vec_final,Vec_final_err2 = add(Vec1,Vec1_err2,Vec2,Vec2_err2)           #
#					     				      #
###############################################################################

import nessi_vector
import array_manip

print "\n#########################FLOAT#######################################"
#Initialization of vectors Vec1,Vec1_err2, Vec2 and Vec2_err2 for float

Vec1=nessi_vector.NessiVector()
Vec1.append(1,2,3,4,5)

Vec1_err2=nessi_vector.NessiVector()
Vec1_err2.append(0.1,0.2,0.3,0.4,0.5)

Vec2=nessi_vector.NessiVector()
Vec2.append(10,11,12,13,14)

Vec2_err2=nessi_vector.NessiVector()
Vec2_err2.append(1.1,1.2,1.3,1.4,1.5)

Vec_final=nessi_vector.NessiVector(len(Vec1))
Vec_final_err2=nessi_vector.NessiVector(len(Vec1))

###########
#add_ncerr#
###########
print "\n####Test add_ncerr####"
Vec_final,Vec_final_err2=array_manip.add_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#sub_ncerr#
###########
print "\n####Test sub_ncerr####"
Vec_final,Vec_final_err2=array_manip.sub_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#mult_ncerr#
###########
print "\n####Test mult_ncerr####"
Vec_final,Vec_final_err2=array_manip.mult_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#div_ncerr#
###########
print "\n####Test div_ncerr####"
Vec_final,Vec_final_err2=array_manip.div_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#sumw_ncerr#
###########
print "\n####Test sumw_ncerr####"
Vec_final,Vec_final_err2=array_manip.sumw_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

print "\n#########################DOUBLE#######################################"
#Initialization of vectors Vec1,Vec1_err2, Vec2 and Vec2_err2 for double

Vec1=nessi_vector.NessiVector(type="double")
Vec1.append(1,2,3,4,5)

Vec1_err2=nessi_vector.NessiVector(type="double")
Vec1_err2.append(0.1,0.2,0.3,0.4,0.5)

Vec2=nessi_vector.NessiVector(type="double")
Vec2.append(10,11,12,13,14)

Vec2_err2=nessi_vector.NessiVector(type="double")
Vec2_err2.append(1.1,1.2,1.3,1.4,1.5)

Vec_final=nessi_vector.NessiVector(len(Vec1),type="double")
Vec_final_err2=nessi_vector.NessiVector(len(Vec1),type="double")

###########
#add_ncerr#
###########
print "\n####Test add_ncerr####"
Vec_final,Vec_final_err2=array_manip.add_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#sub_ncerr#
###########
print "\n####Test sub_ncerr####"
Vec_final,Vec_final_err2=array_manip.sub_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#mult_ncerr#
###########
print "\n####Test mult_ncerr####"
Vec_final,Vec_final_err2=array_manip.mult_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#div_ncerr#
###########
print "\n####Test div_ncerr####"
Vec_final,Vec_final_err2=array_manip.div_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#sumw_ncerr#
###########
print "\n####Test sumw_ncerr####"
Vec_final,Vec_final_err2=array_manip.sumw_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)


print "\n#########################INT#######################################"
#Initialization of vectors Vec1,Vec1_err2, Vec2 and Vec2_err2 for int

Vec1=nessi_vector.NessiVector(type="int")
Vec1.append(1,2,3,4,5)

Vec1_err2=nessi_vector.NessiVector(type="int")
Vec1_err2.append(1,2,3,4,5)

Vec2=nessi_vector.NessiVector(type="int")
Vec2.append(10,11,12,13,14)

Vec2_err2=nessi_vector.NessiVector(type="int")
Vec2_err2.append(2,3,4,5,6)

Vec_final=nessi_vector.NessiVector(len(Vec1),type="int")
Vec_final_err2=nessi_vector.NessiVector(len(Vec1),type="int")

###########
#add_ncerr#
###########
print "\n####Test add_ncerr####"
Vec_final,Vec_final_err2=array_manip.add_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#sub_ncerr#
###########
print "\n####Test sub_ncerr####"
Vec_final,Vec_final_err2=array_manip.sub_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#mult_ncerr#
###########
print "\n####Test mult_ncerr####"
Vec_final,Vec_final_err2=array_manip.mult_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#div_ncerr#
###########
print "\n####Test div_ncerr####"
Vec_final,Vec_final_err2=array_manip.div_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#sumw_ncerr#
###########
print "\n####Test sumw_ncerr####"
Vec_final,Vec_final_err2=array_manip.sumw_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

print "\n#########################UNSIGNED INT#######################################"
#Initialization of vectors Vec1,Vec1_err2, Vec2 and Vec2_err2 for int

Vec1=nessi_vector.NessiVector(type="uint")
Vec1.append(1,2,3,4,5)

Vec1_err2=nessi_vector.NessiVector(type="uint")
Vec1_err2.append(1,2,3,4,5)

Vec2=nessi_vector.NessiVector(type="uint")
Vec2.append(10,11,12,13,14)

Vec2_err2=nessi_vector.NessiVector(type="uint")
Vec2_err2.append(2,3,4,5,6)

Vec_final=nessi_vector.NessiVector(len(Vec1),type="uint")
Vec_final_err2=nessi_vector.NessiVector(len(Vec1),type="uint")

###########
#add_ncerr#
###########
print "\n####Test add_ncerr####"
Vec_final,Vec_final_err2=array_manip.add_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#sub_ncerr#
###########
print "\n####Test sub_ncerr####"
Vec_final,Vec_final_err2=array_manip.sub_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#mult_ncerr#
###########
print "\n####Test mult_ncerr####"
Vec_final,Vec_final_err2=array_manip.mult_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#div_ncerr#
###########
print "\n####Test div_ncerr####"
Vec_final,Vec_final_err2=array_manip.div_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)

###########
#sumw_ncerr#
###########
print "\n####Test sumw_ncerr####"
Vec_final,Vec_final_err2=array_manip.sumw_ncerr(Vec1,Vec1_err2,Vec2,Vec2_err2)

print "\nVec1, Vec2 and Vec_final"
nessi_vector.compare_vect(5,Vec1,Vec2,Vec_final)

print "\nVec1_err2, Vec2_err2 and Vec_final_err2"
nessi_vector.compare_vect(5,Vec1_err2,Vec2_err2,Vec_final_err2)
