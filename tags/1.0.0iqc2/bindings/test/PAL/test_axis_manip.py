from nessi_vector import *
from axis_manip import energy_transfer

v1_f=NessiVector(type="float")
v1_d=NessiVector()
v1_err2_f=NessiVector(type="float")
v1_err2_d=NessiVector()

v2_f=NessiVector(type="float")
v2_d=NessiVector()
v2_err2_f=NessiVector(type="float")
v2_err2_d=NessiVector()

s1= 10
s1_err2= 5

s2= 20
s2_err2 = 5.8

v1_f.append(1,2,3,4,5)
v1_err2_f.append(0.1,0.2,0.3,0.4,0.5)

v2_f.append(11,12,13,14,15)
v2_err2_f.append(0.15,0.25,0.35,0.45,0.55)

v1_d.append(1,2,3,4,5)
v1_err2_d.append(0.1,0.2,0.3,0.4,0.5)

v2_d.append(11,12,13,14,15)
v2_err2_d.append(0.15,0.25,0.35,0.45,0.55)

#v(float)-v(float)
c,ce2=energy_transfer(v1_f,v1_err2_f,v2_f,v2_err2_f)

print "**********v(float)-v(float)**********"
print "c:"
print(c)
print "ce2"
print(ce2)

#v(double)-v(double)"
c,ce2=energy_transfer(v1_d,v1_err2_d,v2_d,v2_err2_d)

print "**********v(double)-v(double)**********"
print "c:"
print(c)
print "ce2"
print(ce2)

#v(float)-S(forced float))"
c,ce2=energy_transfer(v1_f,v1_err2_f,s2,s2_err2)

print "**********v(float)-v(forced float)**********"
print "c:"
print(c)
print "ce2"
print(ce2)

#v(double)-S(forced float))"
c,ce2=energy_transfer(v1_d,v1_err2_d,s2,s2_err2)

print "**********v(double)-v(forced float)**********"
print "c:"
print(c)
print "ce2"
print(ce2)

#S(forced float)-V(float)"
c,ce2=energy_transfer(s1,s1_err2,v2_f,v2_err2_f)

print "**********s(forced float)-v(float)**********"
print "c:"
print(c)
print "ce2"
print(ce2)

#S(forced float)-V(double)"
c,ce2=energy_transfer(s1,s1_err2,v2_d,v2_err2_d)

print "**********s(forced float)-v(double)**********"
print "c:"
print(c)
print "ce2"
print(ce2)

#S(float)-S(float)"
#c,ce2=energy_transfer(s1,s1_err2,s2,s2_err2)

#print "**********s(float)-s(float))**********"
#print "c:"
#print(c)
#print "ce2"
#print(ce2)
