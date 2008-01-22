###############################################################################
#
# Testing script for Swig bindings for convex_polygon_intersect functions
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_convex_polygon_intersect.py
#

##
# \defgroup test_convex_polygon_intersect pbl::test_convex_polygon_intersect
# \{
#

from nessi_vector_bind import *
from utils_bind import convex_polygon_intersect_d
import test_common_bind
from vpair_bind import *

print "#######################################"
print "# Checking Convex_Polygon_Intersect   #"
print "# Swig Generated Python Binding Layer #"
print "#######################################"
print

# Create input vectors
Parallelogram_X_D = DoubleNessiVector()
Parallelogram_Y_D = DoubleNessiVector()
Square1_X_D = DoubleNessiVector()
Square1_Y_D = DoubleNessiVector()
Square2_X_D = DoubleNessiVector()
Square2_Y_D = DoubleNessiVector()
Square3_X_D = DoubleNessiVector()
Square3_Y_D = DoubleNessiVector()
Square4_X_D = DoubleNessiVector()
Square4_Y_D = DoubleNessiVector()
Square5_X_D = DoubleNessiVector()
Square5_Y_D = DoubleNessiVector()
Square6_X_D = DoubleNessiVector()
Square6_Y_D = DoubleNessiVector()
Square7_X_D = DoubleNessiVector()
Square7_Y_D = DoubleNessiVector()
Square8_X_D = DoubleNessiVector()
Square8_Y_D = DoubleNessiVector()

Parallelogram_X_D.append(float(-3))
Parallelogram_X_D.append(float(-2))
Parallelogram_X_D.append(float(0.5))
Parallelogram_X_D.append(float(-0.5))

Parallelogram_Y_D.append(float(-3))
Parallelogram_Y_D.append(float(-1))
Parallelogram_Y_D.append(float(-1))
Parallelogram_Y_D.append(float(-3))

Square1_X_D.append(float(1))
Square1_X_D.append(float(0))
Square1_X_D.append(float(0))
Square1_X_D.append(float(1))

Square1_Y_D.append(float(-2))
Square1_Y_D.append(float(-2))
Square1_Y_D.append(float(-1))
Square1_Y_D.append(float(-1))

Square2_X_D.append(float(0))
Square2_X_D.append(float(-1))
Square2_X_D.append(float(-1))
Square2_X_D.append(float(0))

Square2_Y_D.append(float(-3))
Square2_Y_D.append(float(-3))
Square2_Y_D.append(float(-4))
Square2_Y_D.append(float(-4))

Square3_X_D.append(float(0.5))
Square3_X_D.append(float(-0.5))
Square3_X_D.append(float(-0.5))
Square3_X_D.append(float(0.5))

Square3_Y_D.append(float(-1.5))
Square3_Y_D.append(float(-1.5))
Square3_Y_D.append(float(-0.5))
Square3_Y_D.append(float(-0.5))

Square4_X_D.append(float(-1))
Square4_X_D.append(float(-2))
Square4_X_D.append(float(-2))
Square4_X_D.append(float(-1))

Square4_Y_D.append(float(-2))
Square4_Y_D.append(float(-2))
Square4_Y_D.append(float(-1))
Square4_Y_D.append(float(-1))

Square5_X_D.append(float(-0.5))
Square5_X_D.append(float(-0.5))
Square5_X_D.append(float(-1.5))
Square5_X_D.append(float(-1.5))

Square5_Y_D.append(float(-1.5))
Square5_Y_D.append(float(-2.5))
Square5_Y_D.append(float(-2.5))
Square5_Y_D.append(float(-1.5))

Square6_X_D.append(float(2.5))
Square6_X_D.append(float(1.5))
Square6_X_D.append(float(1.5))
Square6_X_D.append(float(2.5))

Square6_Y_D.append(float(-1))
Square6_Y_D.append(float(-1))
Square6_Y_D.append(float(0))
Square6_Y_D.append(float(0))

Square7_X_D.append(float(1))
Square7_X_D.append(float(-4))
Square7_X_D.append(float(-4))
Square7_X_D.append(float(1))

Square7_Y_D.append(float(-4))
Square7_Y_D.append(float(-4))
Square7_Y_D.append(float(0))
Square7_Y_D.append(float(0))

Square8_X_D.append(float(-2))
Square8_X_D.append(float(-3))
Square8_X_D.append(float(-3))
Square8_X_D.append(float(-2))

Square8_Y_D.append(float(-1))
Square8_Y_D.append(float(-1))
Square8_Y_D.append(float(0))
Square8_Y_D.append(float(0))

###############################################################################
# Create truth vectors and values
###############################################################################

# Truth information for convex_polygon_intersect
# Parallelogram and Square1
TruthOutput1_X_D = DoubleNessiVector()
TruthOutput1_Y_D = DoubleNessiVector()

TruthOutput1_X_D.append(float(0))
TruthOutput1_X_D.append(float(0.5))
TruthOutput1_X_D.append(float(0))

TruthOutput1_Y_D.append(float(-1))
TruthOutput1_Y_D.append(float(-1))
TruthOutput1_Y_D.append(float(-2))

# Parallelogram and Square2
TruthOutput2_X_D = DoubleNessiVector()
TruthOutput2_Y_D = DoubleNessiVector()

TruthOutput2_X_D.append(float(-0.5))
TruthOutput2_X_D.append(float(-1))

TruthOutput2_Y_D.append(float(-3))
TruthOutput2_Y_D.append(float(-3))

# Parallelogram and Square3
TruthOutput3_X_D = DoubleNessiVector()
TruthOutput3_Y_D = DoubleNessiVector()

TruthOutput3_X_D.append(float(-0.5))
TruthOutput3_X_D.append(float(0.5))
TruthOutput3_X_D.append(float(0.25))
TruthOutput3_X_D.append(float(-0.5))

TruthOutput3_Y_D.append(float(-1))
TruthOutput3_Y_D.append(float(-1))
TruthOutput3_Y_D.append(float(-1.5))
TruthOutput3_Y_D.append(float(-1.5))

# Parallelogram and Square4
TruthOutput4_X_D = DoubleNessiVector()
TruthOutput4_Y_D = DoubleNessiVector()

TruthOutput4_X_D.append(float(-2))
TruthOutput4_X_D.append(float(-1))
TruthOutput4_X_D.append(float(-1))
TruthOutput4_X_D.append(float(-2))

TruthOutput4_Y_D.append(float(-1))
TruthOutput4_Y_D.append(float(-1))
TruthOutput4_Y_D.append(float(-2))
TruthOutput4_Y_D.append(float(-2))

# Parallelogram and Square5
TruthOutput5_X_D = DoubleNessiVector()
TruthOutput5_Y_D = DoubleNessiVector()

TruthOutput5_X_D.append(float(-0.5))
TruthOutput5_X_D.append(float(-0.5))
TruthOutput5_X_D.append(float(-1.5))
TruthOutput5_X_D.append(float(-1.5))

TruthOutput5_Y_D.append(float(-1.5))
TruthOutput5_Y_D.append(float(-2.5))
TruthOutput5_Y_D.append(float(-2.5))
TruthOutput5_Y_D.append(float(-1.5))

# Parallelogram and Square6
TruthOutput6_X_D = DoubleNessiVector()
TruthOutput6_Y_D = DoubleNessiVector()
# This should be empty since there is no polygon intersection

# Parallelogram and Square7
TruthOutput7_X_D = DoubleNessiVector()
TruthOutput7_Y_D = DoubleNessiVector()

TruthOutput7_X_D.append(float(-3))
TruthOutput7_X_D.append(float(-2))
TruthOutput7_X_D.append(float(0.5))
TruthOutput7_X_D.append(float(-0.5))

TruthOutput7_Y_D.append(float(-3))
TruthOutput7_Y_D.append(float(-1))
TruthOutput7_Y_D.append(float(-1))
TruthOutput7_Y_D.append(float(-3))

# Parallelogram and Square8
TruthOutput8_X_D = DoubleNessiVector()
TruthOutput8_Y_D = DoubleNessiVector()

TruthOutput8_X_D.append(float(-2))

TruthOutput8_Y_D.append(float(-1))

###############################################################################
# Create output placeholders for vectors
###############################################################################

# Output placeholders for convex_polygon_intersect
Output1_X_D = DoubleNessiVector(len(Parallelogram_X_D)+len(Square1_X_D))
Output1_Y_D = DoubleNessiVector(len(Parallelogram_Y_D)+len(Square1_Y_D))
Output2_X_D = DoubleNessiVector(len(Parallelogram_X_D)+len(Square2_X_D))
Output2_Y_D = DoubleNessiVector(len(Parallelogram_Y_D)+len(Square2_Y_D))
Output3_X_D = DoubleNessiVector(len(Parallelogram_X_D)+len(Square3_X_D))
Output3_Y_D = DoubleNessiVector(len(Parallelogram_Y_D)+len(Square3_Y_D))
Output4_X_D = DoubleNessiVector(len(Parallelogram_X_D)+len(Square4_X_D))
Output4_Y_D = DoubleNessiVector(len(Parallelogram_Y_D)+len(Square4_Y_D))
Output5_X_D = DoubleNessiVector(len(Parallelogram_X_D)+len(Square5_X_D))
Output5_Y_D = DoubleNessiVector(len(Parallelogram_Y_D)+len(Square5_Y_D))
Output6_X_D = DoubleNessiVector(len(Parallelogram_X_D)+len(Square6_X_D))
Output6_Y_D = DoubleNessiVector(len(Parallelogram_Y_D)+len(Square6_Y_D))
Output7_X_D = DoubleNessiVector(len(Parallelogram_X_D)+len(Square7_X_D))
Output7_Y_D = DoubleNessiVector(len(Parallelogram_Y_D)+len(Square7_Y_D))
Output8_X_D = DoubleNessiVector(len(Parallelogram_X_D)+len(Square8_X_D))
Output8_Y_D = DoubleNessiVector(len(Parallelogram_Y_D)+len(Square8_Y_D))

print "Checking Convex Polygon Intersection Binding Function"

convex_polygon_intersect_d(Parallelogram_X_D, Parallelogram_Y_D,
                           Square1_X_D, Square1_Y_D,
                           Output1_X_D, Output1_Y_D)

mess = test_common_bind.makeCheck("(p&s1)x: convex_polygon_intersect_d",
                                  Output1_X_D, TruthOutput1_X_D)

print mess

mess = test_common_bind.makeCheck("(p&s1)y: convex_polygon_intersect_d",
                                  Output1_Y_D, TruthOutput1_Y_D)

print mess

convex_polygon_intersect_d(Parallelogram_X_D, Parallelogram_Y_D,
                           Square2_X_D, Square2_Y_D,
                           Output2_X_D, Output2_Y_D)

mess = test_common_bind.makeCheck("(p&s2)x: convex_polygon_intersect_d",
                                  Output2_X_D, TruthOutput2_X_D)

print mess

mess = test_common_bind.makeCheck("(p&s2)y: convex_polygon_intersect_d",
                                  Output2_Y_D, TruthOutput2_Y_D)

print mess

convex_polygon_intersect_d(Parallelogram_X_D, Parallelogram_Y_D,
                           Square3_X_D, Square3_Y_D,
                           Output3_X_D, Output3_Y_D)

mess = test_common_bind.makeCheck("(p&s3)x: convex_polygon_intersect_d",
                                  Output3_X_D, TruthOutput3_X_D)

print mess

mess = test_common_bind.makeCheck("(p&s3)y: convex_polygon_intersect_d",
                                  Output3_Y_D, TruthOutput3_Y_D)

print mess

convex_polygon_intersect_d(Parallelogram_X_D, Parallelogram_Y_D,
                           Square4_X_D, Square4_Y_D,
                           Output4_X_D, Output4_Y_D)

mess = test_common_bind.makeCheck("(p&s4)x: convex_polygon_intersect_d",
                                  Output4_X_D, TruthOutput4_X_D)

print mess

mess = test_common_bind.makeCheck("(p&s4)y: convex_polygon_intersect_d",
                                  Output4_Y_D, TruthOutput4_Y_D)

print mess

convex_polygon_intersect_d(Parallelogram_X_D, Parallelogram_Y_D,
                           Square5_X_D, Square5_Y_D,
                           Output5_X_D, Output5_Y_D)

mess = test_common_bind.makeCheck("(p&s5)x: convex_polygon_intersect_d",
                                  Output5_X_D, TruthOutput5_X_D)

print mess

mess = test_common_bind.makeCheck("(p&s5)y: convex_polygon_intersect_d",
                                  Output5_Y_D, TruthOutput5_Y_D)

print mess

convex_polygon_intersect_d(Parallelogram_X_D, Parallelogram_Y_D,
                           Square6_X_D, Square6_Y_D,
                           Output6_X_D, Output6_Y_D)

mess = test_common_bind.makeSizeCheck("(p&s6)x: convex_polygon_intersect_d",
                                      Output6_X_D, TruthOutput6_X_D)

print mess

mess = test_common_bind.makeSizeCheck("(p&s6)y: convex_polygon_intersect_d",
                                      Output6_Y_D, TruthOutput6_Y_D)

print mess

convex_polygon_intersect_d(Parallelogram_X_D, Parallelogram_Y_D,
                           Square7_X_D, Square7_Y_D,
                           Output7_X_D, Output7_Y_D)

mess = test_common_bind.makeCheck("(p&s7)x: convex_polygon_intersect_d",
                                  Output7_X_D, TruthOutput7_X_D)

print mess

mess = test_common_bind.makeCheck("(p&s7)y: convex_polygon_intersect_d",
                                  Output7_Y_D, TruthOutput7_Y_D)

print mess

convex_polygon_intersect_d(Parallelogram_X_D, Parallelogram_Y_D,
                           Square8_X_D, Square8_Y_D,
                           Output8_X_D, Output8_Y_D)

mess = test_common_bind.makeCheck("(p&s8)x: convex_polygon_intersect_d",
                                  Output8_X_D, TruthOutput8_X_D)

print mess

mess = test_common_bind.makeCheck("(p&s8)y: convex_polygon_intersect_d",
                                  Output8_Y_D, TruthOutput8_Y_D)

print mess

##
# \} // end of test_convex_polygon_intersect group
#

