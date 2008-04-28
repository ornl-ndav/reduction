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
# \file bindings/utils.py
#

"""
   This module gives the NessiList access to the various utility functions
   provided by the C++ utils library. These functions are written in
   references to SNS 107030214-TD0001-R00, \"Data Reduction Library Software
   Requirements and Specifications\".

   Once a function is called, according to the type of the NessiLists calling
   it, the module redirects the call to the right function.
"""

import nessi_list
import utils_bind
import vpair_bind

from scl_defs import VERSION as __version__

##
# \namespace utils
#
# \brief This Python abstraction layer module provides various utility
# functions
#
# This module gives the NessiList access to the various utility functions
# provided by the <i>utils</i> library. These functions are written in
# references to SNS 107030214-TD0001-R00, "Data Reduction Library Software
# Requirements and Specifications".
#
# Once a function is called, according to the type of the NessiLists calling
# it, the module redirects the call to the right function.
#
# For example, when calling the function \f$weighted\_average\f$ with two
# NessiLists (data and error\f${}^2\f$) of type <i>double</i>, the module
# redirects the call to the function \f$weighted\_average\_d\f$.
#

##
# \defgroup bisect_helper utils::bisect_helper
# \{
#

##
# \brief This function finds a bin index within an axis array
# 
# This function takes an axis array and a given value and searches that 
# axis for the corresponding bin location. However, this helper is used in 
# the context of locating a bin index within an associated data array 
# (which is always one less than the axis array) based on the axis array 
# value. The found index may need to be adjusted based on its value with 
# respect to the size of the data array. <b>NOTE:</b> If the search value 
# is outside the axis range, the result of the function will be to return 
# the closest edge bin. This means for a search value smaller than the 
# smallest axis value, the index returned will be 0. If the search value is 
# greater than the largest axis value, the index returned will be the last 
# bin in the data array (axis size minus 1).
#
# \param axis (INPUT) is an array of independent axis values to search
# \param value (INPUT) is the value to search axis for
#
# \return
# - the corresponding index for the value 
#
# \exception TypeError is raised if axis is not of type double
#
def bisect_helper(axis, value):
    """
    This function takes an axis array and a given value and searches that axis
    for the corresponding bin location. However, this helper is used in the
    context of locating a bin index within an associated data array (which is
    always one less than the axis array) based on the axis array value. The
    found index may need to be adjusted based on its value with respect to the
    size of the data array. NOTE: If the search value is outside the axis
    range, the result of the function will be to return the closest edge bin.
    This means for a search value smaller than the smallest axis value, the
    index returned will be 0. If the search value is greater than the largest
    axis value, the index returned will be the last bin in the data array
    (axis size minus 1).

    Parameters:
    ----------
    -> axis is an array of independent axis values to search
    -> value is the value to search axis for

    Returns:
    -------
    <- The corresponding index for the value 

    Exceptions:
    ----------
    <- TypeError is raised if axis is not of type double
    """
    if axis.__type__ == nessi_list.NessiList.DOUBLE:
        index = vpair_bind.SizetVPair()
        utils_bind.bisect_helper_d(axis.__array__,
                                   float(value),
                                   index)
        return index.val

    else:
        raise TyperError("Unknown primative type %s" % str(axis.__type__))
##
# \}

##
# \defgroup calc_area_2D_polygon utils::calc_area_2D_polygon
# \{
#

##
# \brief This function calculates the 2D polygon area
#
# This function is described in section 3.59 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function takes two arrays of coordinates of a 2D polygon and 
# calculates the area for that polygon. The coordinates of the polygon can 
# be in any two-dimensional space. The area is calculated according to 
# the function
#
# \f[
# A = \frac{1}{2}\sum^{n}_{i=1} \left(x_i \left(y_{i+1} - 
# y_{i-1}\right)\right)
# \f]
#
# where \f$n\f$ is the size of the polygon, \f$x_i\f$ is the \f$i^{th}\f$ 
# element in the x coordinate array, \f$y_{i-1}\f$ is the \f$i^{th}-1\f$ 
# element in the y coordinate array and \f$y_{i+1}\f$ is the \f$i^{th}+1\f$ 
# element in the y coordinate array. The value of \f$A\f$ is a signed area. 
# In order to get \f$|A|\f$, the signed_area boolean flag should be set to 
# false.
# 
# <b>The implementation of this formula requires that the coordinate arrays
# must have the first ([0]) and second ([1]) elements repeated making the
# array sizes size_poly + 2.</b> 
#
# \param x_coord (INPUT) the array of x coordinates for the polygon
# \param y_coord (INPUT) the array of y coordinates for the polygon
# \param size_poly (INPUT) the size of the polygon (i.e. square: 
# size_poly=4)
# \param signed_area (INPUT) flag to pass back the resulting area as a 
# signed or unsigned quantity. The default value is False (unsigned area).
#
# \return
# - The area of the 2D polygon
#
# \exception TypeError is raised if x_coord and y_coord are not the same type
# \exception IndexError is raised if x_coord and y_coord are not the same
# length
# \exception TypeError is raised if an empty, point or a line is passed to the
# function.
# \exception TypeError is raised if the size of x_coord is not identical to
# size_poly+2.
#
def calc_area_2D_polygon(x_coord, y_coord, size_poly, signed_area=False):
    """
    This function takes two arrays of coordinates of a 2D polygon and 
    calculates the area for that polygon. The coordinates of the polygon can 
    be in any two-dimensional space. The area is calculated according to 
    the function

    A = (1/2) sum^n_{i=1} (x_i * (y_{i+1} - y_{i-1}))

    where n is the size of the polygon, x_i is the i^{th} element in the x
    coordinate array, y_{i-1} is the i^{th}-1 element in the y coordinate
    array and y_{i+1} is the i^{th}+1 element in the y coordinate array. The
    value of A is a signed area. In order to get |A|, the signed_area boolean
    flag should be set to False.
    
    THE IMPLEMENTATION OF THIS FORMULA REQUIRES THAT THE COORDINATE
    ARRAYS MUST HAVE THE FIRST ([0]) AND SECOND ([1]) ELEMENTS REPEATED MAKING
    THE ARRAY SIZES SIZE_POLY + 2. 

    Parameters:
    ----------
    -> x_coord the array of x coordinates for the polygon
    -> y_coord the array of y coordinates for the polygon
    -> size_poly the size of the polygon (i.e. square: size_poly=4)
    -> signed_area flag to pass back the resulting area as a signed or
       unsigned quantity. The default value is False (unsigned area).

    Returns:
    -------
    <- The area of the 2D polygon

    Exceptions:
    ----------
    <- TypeError is raised if x_coord and y_coord are not the same type
    <- TypeError is raised if x_coord is not of type double    
    <- IndexError is raised if x_coord and y_coord are not the same length
    <- TypeError is raised if an empty, point or a line is passed to the
        function.
    <- TypeError is raised if the size of x_coord is not identical to
       size_poly+2.
    """
    if x_coord.__type__ != y_coord.__type__:
        raise TypeError("X and Y Coordinate arrays are not the same type")

    if x_coord.__type__ == nessi_list.NessiList.DOUBLE:
        area = vpair_bind.DoubleVPair()
        utils_bind.calc_area_2D_polygon_d(x_coord.__array__,
                                          y_coord.__array__,
                                          size_poly,
                                          signed_area,
                                          area)
        
        return area.val

    else:
        raise TyperError("Unknown primative type %s" % str(x_coord.__type__))
##
# \}

##
# \defgroup calc_bin_centers utils::calc_bin_centers
# \{
#

##
# \brief This function calculates bin centers
#
# This function is described in section 3.52 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
# 
# This function takes in an axis array and its associated squared 
# uncertainties and calculates the bin centers via the following formula:
#
# \f[
# bin\_center[i] = \frac{1}{2}\left(axis[i] + axis[i+1]\right)
# \f]
#
# where \f$bin\_center[i]\f$ is the \f$i^{th}\f$ bin center, \f$axis[i]\f$ 
# is the \f$i^{th}\f$ axis element and \f$axis[i+1]\f$ is the 
# \f$(i+1)^{th}\f$ axis element. The resulting array for the bin centers 
# will be one element shorter than the incoming axis. 
#
# Assuming that the uncertainties are uncorrelated, the squared uncertainties
# are calculated by:
#
# \f[
# \sigma^2_{bin\_center}[i] = \frac{1}{4}\left(\sigma^2_{axis}[i] + 
# \sigma^2_{axis}[i+1]\right)
# \f]
#
# where \f$\sigma^2_{bin\_center}[i]\f$ is the \f$i^{th}\f$ squared 
# uncertainty of the bin center, \f$\sigma^2_{axis}[i]\f$ is the 
# \f$i^{th}\f$ squared uncertainty of the axis and 
# \f$\sigma^2_{axis}[i+1]\f$ is the \f$(i+1)^{th}\f$ squared uncertainty of 
# the axis.
#
# \param axis (INPUT) is an array of independent axis values
# \param axis_err2 (INPUT) is an array of the squares of the uncertainties 
# associated with the independent axis
#
# \return
# - an array of bin centers of the independent axis
# - an array of the squares of the uncertainties associated with the bin
#   centers
#
# \exception TypeError is raised if axis and axis_err2 are not the same type
# \exception TypeError is raised if axis is not of type double
#

def calc_bin_centers(axis, axis_err2=None):
    """
    This function takes in an axis array and its associated squared 
    uncertainties and calculates the bin centers via the following formula:

    bin_center[i] = 1/2 x (axis[i] + axis[i+1])

    where bin_center[i] is the i^{th} bin center, axis[i] is the i^{th} axis
    element and axis[i+1] is the (i+1)^{th} axis element. The resulting array
    for the bin centers will be one element shorter than the incoming axis. 

    Assuming that the uncertainties are uncorrelated, the squared
    uncertainties are calculated by:

    sigma^2_{bin_center}[i] = 1/4 x (sigma^2_{axis}[i] + sigma^2_{axis}[i+1])

    where sigma^2_{bin_center}[i] is the i^{th} squared uncertainty of the bin
    center, sigma^2_{axis}[i] is the i^{th} squared uncertainty of the axis
    and sigma^2_{axis}[i+1] is the (i+1)^{th} squared uncertainty of the axis.

    Parameters:
    ----------
    -> axis is an array of independent axis values
    -> axis_err2 is an array of the squares of the uncertainties associated
       with the independent axis

    Returns:
    -------
    <- an array of bin centers of the independent axis
    <- an array of the squares of the uncertainties associated with the bin
       centers

    Exceptions:
    ----------
    <- TypeError is raised if axis and axis_err2 are not the same type
    <- TypeError is raised if axis is not of type double

    """
    if axis_err2 is not None:
        if axis.__type__ != axis_err2.__type__:
            raise TypeError("Axis and Axis Err2 arrays are not the same type")

    if axis.__type__ == nessi_list.NessiList.DOUBLE:
        bin_centers = nessi_list.NessiList(len(axis) - 1)

        if axis_err2 is None:
            bin_centers_err2 = nessi_list.NessiList(len(axis) - 1)
            axis_err2 = nessi_list.NessiList(len(axis))
        else:
            bin_centers_err2 = nessi_list.NessiList(len(axis_err2) - 1)
            
        utils_bind.calc_bin_centers_d(axis.__array__,
                                      axis_err2.__array__,
                                      bin_centers.__array__,
                                      bin_centers_err2.__array__)
        
        return (bin_centers, bin_centers_err2)

    else:
        raise TyperError("Unknown primative type %s" % str(axis.__type__))
    
##
# \}

##
# \defgroup calc_bin_widths utils::calc_bin_widths
# \{
#

##
# \brief This function calculates bin widths
#
# This function is described in section 3.54 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
# 
# This function takes in an axis array and its associated squared 
# uncertainties and calculates the bin widths via the following formula:
#
# \f[
# bin\_width[i] = axis[i+1] - axis[i]
# \f]
#
# where \f$bin\_width[i]\f$ is the \f$i^{th}\f$ bin width, \f$axis[i]\f$ 
# is the \f$i^{th}\f$ axis element and \f$axis[i+1]\f$ is the 
# \f$(i+1)^{th}\f$ axis element. The resulting array for the bin widths 
# will be one element shorter than the incoming axis. 
#
# Assuming that the uncertainties are uncorrelated, the squared uncertainties
# are calculated by:
#
# \f[
# \sigma^2_{bin\_width}[i] = \sigma^2_{axis}[i+1] + \sigma^2_{axis}[i]
# \f]
#
# where \f$\sigma^2_{bin\_width}[i]\f$ is the \f$i^{th}\f$ squared 
# uncertainty of the bin width, \f$\sigma^2_{axis}[i]\f$ is the 
# \f$i^{th}\f$ squared uncertainty of the axis and 
# \f$\sigma^2_{axis}[i+1]\f$ is the \f$(i+1)^{th}\f$ squared uncertainty of 
# the axis.
#
# \param axis (INPUT) is an array of independent axis values
# \param axis_err2 (INPUT) is an array of the squares of the uncertainties 
# associated with the independent axis
#
# \return
# - an array of bin widths of the independent axis
# - an array of the squares of the uncertainties associated with the bin
#   widths
#
# \exception TypeError is raised if axis and axis_err2 are not the same type
# \exception TypeError is raised if axis is not of type double
#

def calc_bin_widths(axis, axis_err2=None):
    """
    This function takes in an axis array and its associated squared 
    uncertainties and calculates the bin widths via the following formula:

    bin_width[i] = axis[i+1] - axis[i]

    where bin_width[i] is the i^{th} bin width, axis[i] is the i^{th} axis
    element and axis[i+1] is the (i+1)^{th} axis element. The resulting array
    for the bin widths will be one element shorter than the incoming axis. 

    Assuming that the uncertainties are uncorrelated, the squared
    uncertainties are calculated by:

    sigma^2_{bin_width}[i] = sigma^2_{axis}[i+1] + sigma^2_{axis}[i]

    where sigma^2_{bin_width}[i] is the i^{th} squared uncertainty of the bin
    width, sigma^2_{axis}[i] is the i^{th} squared uncertainty of the axis
    and sigma^2_{axis}[i+1] is the (i+1)^{th} squared uncertainty of the axis.

    Parameters:
    ----------
    -> axis is an array of independent axis values
    -> axis_err2 is an array of the squares of the uncertainties associated
       with the independent axis

    Returns:
    -------
    <- an array of bin widths of the independent axis
    <- an array of the squares of the uncertainties associated with the bin
       widths

    Exceptions:
    ----------
    <- TypeError is raised if axis and axis_err2 are not the same type
    <- TypeError is raised if axis is not of type double

    """
    if axis_err2 is not None:
        if axis.__type__ != axis_err2.__type__:
            raise TypeError("Axis and Axis Err2 arrays are not the same type")

    if axis.__type__ == nessi_list.NessiList.DOUBLE:
        bin_widths = nessi_list.NessiList(len(axis) - 1)
        if axis_err2 is None:
            bin_widths_err2 = nessi_list.NessiList(len(axis) - 1)
            axis_err2 = nessi_list.NessiList(len(axis))
        else:
            bin_widths_err2 = nessi_list.NessiList(len(axis_err2) - 1)
        utils_bind.calc_bin_widths_d(axis.__array__,
                                     axis_err2.__array__,
                                     bin_widths.__array__,
                                     bin_widths_err2.__array__)
        
        return (bin_widths, bin_widths_err2)

    else:
        raise TypeError("Unknown primative type %s" % str(axis.__type__))
    
##
# \}

##
# \defgroup calib_refl_areadet \
# utils::calib_refl_areadet
# \{
#

##
# \brief This function calibrates a reflectometer 2D detector array for
#        pixel variations
#
# This function is described in section 3.45 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def calib_refl_areadet():
    """
    ---------------------------------------------------------------------------
    This function calibrates a reflectometer 2D detector array for pixel
    variations

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError("This function is not implemented.")

##
# \}

##
# \defgroup compare utils::compare
# \{

##
# \brief This function compares two numbers and returns 0 (eq), 1 (gt) or
# -1 (lt).
#
# This function takes two numbers on compares them. The function returns
# 0 is the two numbers are equal, 1 if the first number is larger than the
# second number, and -1 if the first number is smaller than the second
# number.
#
# \param value1 (INPUT) is the first number to be compared
# \param value2 (INPUT) is the second number to be compared
#
# \return 0 (eq), 1 (gt) or -1 (lt)
#

def compare(value1, value2):

    """
    ---------------------------------------------------------------------------
    This function takes two numbers on compares them. The function returns 0
    is the two numbers are equal, 1 if the first number is larger than the
    second number, and -1 if the first number is smaller than the second
    number.

    Parameters:
    ----------
    -> value1 is the first number to be compared
    -> value2 is the second number to be compared

    Return:
    ------
    <- 0 (eq), 1 (gt) or -1 (lt)

    """

    result = utils_bind.compare(value1, value2)
    return result

##
# \}

##
# \defgroup convex_polygon_intersect utils::convex_polygon_intersect
# \{
   
##
# \brief This function finds the intersection of two convex polygons
#
# This function calculates the intersection of two convex polygons (labeled 
# A and B for identification purposes) and returns the overlap polygon 
# (labeled C). <b>NOTE</b>: The coordinates of the polygons must be specified
# in <em>clockwise</em> order.
#
# The prescription for this function is taken from section 6.5 of
# <em>Computational Geometry and Computer Graphics in C++</em> by Michael
# Laszlo. It has been modified to fit to the data model (Nessi::Vectors) of
# the SNS Common Libraries. The porting of method names to library functions
# is not one-to-one and have been modified to fit the library naming
# conventions. The methodology presented in the book is used as is and is
# summarized below. 
#
# Local Vocabulary Definitions
# \li \em Sickle - Regions that encircling the intersection polygon that 
# consist of a set of points (chains) from both polygon A and B and 
# terminates at the intersection points. These are the grey regions in the 
# figure below.
# \li <em>Inner chain</em> - The set of points of a sickle that lies on the 
# intersection polygon
# \li \em Edge - A set of two points with an origin and a destination point
# \li <em>Origin point</em> - The current coordinate point based on the 
# iteration through the coordinate lists
# \li <em>Destination point</em> - The i+1 point from the origin point
#
# <IMG SRC="../images/PolygonOverlap.png">
#
# <em>Phase 1:</em> Search for edge intersection
# <OL>
# <LI>Create windows (a, b) based on edges of A and B respectively</LI>
# <LI>Move a and b until both edges on the same sickle</LI>
# </OL>
# <em>Phase 2:</em> Search for intersection points
# <OL>
# <LI>Advance a or b based on the following rules (note: edge a is 
# considered outside edge b if the destination edge point of a lies to the 
# left of b).
# <UL>
# <LI>a and b aim at each other: advance the edge which is outside</LI>
# <LI>a aims at b, but b does not aim at a: insert a's destination point 
# into intersection polygon and advance a</LI>
# <LI>b aims at a, but a does not aim at b: insert b's destination point 
# into intersection polygon and advance b</LI>
# <LI>a and b do not aim at each other: advance the edge which is 
# outside</LI>
# </UL>
# <LI>If the edge end point of a or b belong to the inner chain, insert the 
# point into the intersection polygon</LI>
# <LI>When a and b cross, that point is inserted into intersection 
# polygon</LI>
# <LI>Continue until the first intersection point is found again</LI>
# </OL>
# 
# If 2*(size(A)+size(B)) iterations are performed without an intersection 
# point being found, then the polygon boundaries do not cross. The 
# coordinate pairs of the polygons are compared to each other to determine 
# the \f$A \subset B\f$, \f$A \supset B\f$ or \f$A \cap B = 0\f$ cases.
# 
# \param ax_coord (INPUT) the x coordinates for polygon A
# \param ay_coord (INPUT) the y coordinates for polygon A
# \param bx_coord (INPUT) the x coordinates for polygon B
# \param by_coord (INPUT) the y coordinates for polygon B
#
# \return
# - A NessiList of the x coordinates of the intersection polygon
# - A NessiList of the y coordinates of the intersection polygon
#
# \exception TypeError is raised if any of the lists are not the same type
# \exception IndexError is raised if the size of ax_coord is not identical to
# the size of ay_coord
# \exception IndexError is raised if the size of bx_coord is not identical to
# the size of by_coord
#
   
def convex_polygon_intersect(ax_coord, ay_coord, bx_coord, by_coord):
    """
    This function calculates the intersection of two convex polygons (labeled 
    A and B for identification purposes) and returns the overlap polygon 
    (labeled C). NOTE: The coordinates of the polygons must be specified in
    CLOCKWISE order.

    The prescription for this function is taken from section 6.5 of
    Computational Geometry and Computer Graphics in C++ by Michael Laszlo. It
    has been modified to fit to the data model (Nessi::Vectors) of the SNS
    Common Libraries. The porting of method names to library functions is not
    one-to-one and have been modified to fit the library naming conventions.
    The methodology presented in the book is used as is and is summarized
    below. 
   
    * Local Vocabulary Definitions *
    Sickle - Regions that encircling the intersection polygon that 
    consist of a set of points (chains) from both polygon A and B and 
    terminates at the intersection points. 
    Inner chain - The set of points of a sickle that lies on the intersection
    polygon
    Edge - A set of two points with an origin and a destination point
    Origin point - The current coordinate point based on the iteration through
    the coordinate lists
    Destination point - The i+1 point from the origin point
   
    Phase 1: Search for edge intersection

      1. Create windows (a, b) based on edges of A and B respectively
      2. Move a and b until both edges on the same sickle
  
    Phase 2: Search for intersection points

      1. Advance a or b based on the following rules (note: edge a is
         considered outside edge b if the destination edge point of a lies to
         the left of b).
         - a and b aim at each other: advance the edge which is outside
         - a aims at b, but b does not aim at a: insert a's destination point 
           into intersection polygon and advance a
         - b aims at a, but a does not aim at b: insert b's destination point 
           into intersection polygon and advance b
         - a and b do not aim at each other: advance the edge which is 
           outside
      2. If the edge end point of a or b belong to the inner chain, insert the 
         point into the intersection polygon
      3. When a and b cross, that point is inserted into intersection polygon
      4. Continue until the first intersection point is found again
    
    If 2*(size(A)+size(B)) iterations are performed without an intersection 
    point being found, then the polygon boundaries do not cross. The 
    coordinate pairs of the polygons are compared to each other to determine 
    the A within B, A contains B or A separate from B cases.
    
    Parameters:
    ----------
    -> ax_coord the x coordinates for polygon A
    -> ay_coord the y coordinates for polygon A
    -> bx_coord the x coordinates for polygon B
    -> by_coord the y coordinates for polygon B
    
    Returns:
    -------
    <- A NessiList of the x coordinates of the intersection polygon
    <- A NessiList of the y coordinates of the intersection polygon
    
    Exceptions:
    ----------
    <- TypeError is raised if any of the lists are not the same type
    <- IndexError is raised if the size of ax_coord is not identical to
    the size of ay_coord
    <- IndexError is raised if the size of bx_coord is not identical to
    the size of by_coord
    """
    
    if ax_coord.__type__ != ay_coord.__type__:
        raise TypeError("X and Y coordinate arrays for polygon A are not "\
                        +"the same type")

    if bx_coord.__type__ != by_coord.__type__:
        raise TypeError("X and Y coordinate arrays for polygon B are not "\
                        +"the same type")

    if ax_coord.__type__ != bx_coord.__type__:
        raise TypeError("The coordinate arrays for polygon A and B are not "\
                        +"the same type")    

    if ax_coord.__type__ == nessi_list.NessiList.DOUBLE:
        output_x = nessi_list.NessiList(len(ax_coord)+len(bx_coord))
        output_y = nessi_list.NessiList(len(ay_coord)+len(by_coord))

        utils_bind.convex_polygon_intersect_d(ax_coord.__array__,
                                              ay_coord.__array__,
                                              bx_coord.__array__,
                                              by_coord.__array__,
                                              output_x.__array__,
                                              output_y.__array__)
        return (output_x, output_y)
        
    else:
        raise TypeError("convex_polygon_intersect: Unknown primitive type %s" \
                        % str(ax_coord.__type__))
    
##
# \}

##
# \defgroup eval_linear_fit utils::eval_linear_fit
# \{

##
# \brief This function evaluates a linear fit function
#
# This function is described in section 3.56 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function takes an independent axis and the associated uncertainties 
# and the fit parameters of a line (slope and intercept) and calculates the 
# values associated with the independent axis based on the fit parameters.
#
# The calculation of the new values from the input independent axis should 
# be done by the following
#
# \f[
# data_o[i] = slope \times axis_i[i] + intercept
# \f]
# 
# where \f$axis_i[i]\f$ is the \f$i^{th}\f$ element of the independent 
# axis, \f$slope\f$ is the slope of the linear fit, \f$intercept\f$ is the 
# intercept of the linear fit and \f$data_o[i]\f$ is the \f$i^{th}\f$ 
# element of the calculated linear equation.
#
# Assuming that the uncertainties are uncorrelated, the uncertainty on a 
# given element of the calculated linear equation is
#
# \f[
# \sigma^2_o[i] = axis^2_i[i] \sigma^2_{slope} + 
# slope^2 \sigma^2_{axis_i}[i] + \sigma^2_{intercept}
# \f]
#
# where \f$\sigma^2_{axis_i}[i]\f$ is the \f$i^{th}\f$ element of the 
# square uncertainty of the independent axis, \f$\sigma^2_{slope}\f$ is the 
# square uncertainty of the slope of the linear fit, 
# \f$\sigma^2_{intercept}\f$ is the square uncertainty of the intercept of 
# the linear fit and \f$\sigma^2_o[i]\f$ is the \f$i^{th}\f$ element of the 
# square uncertainty of the calculated linear equation value.
#
# \param axis (INPUT) is an array of independent axis values
# \param axis_err2 (INPUT) is an array of the squares of the uncertainties
#        associated with the independent axis values
# \param slope (INPUT) is the slope of the line from the fit
# \param slope_err2 (INPUT) is the square of the uncertainties associated 
# with the slope
# \param intercept (INPUT) is the intercept of the line from the fit
# \param intercept_err2 (INPUT) is the square of the uncertainties associated
#        with the intercept
#
# \return
# - NessiList of values calculated from the independent axis with the fit
#   parameters
# - NessiList of the squares of the uncertainties associated with the values
#   calculated from the independent axis with the fit parameters
#
# \exception IndexError is raised if any of the lists are not the same length
# \exception TypeError is raised if any of the lists are not the same type
# \exception TypeError is raised if any of the lists are not recognized types
#

def eval_linear_fit(axis, axis_err2, slope, slope_err2,
                    intercept, intercept_err2):
    """
    This function takes an independent axis and the associated uncertainties 
    and the fit parameters of a line (slope and intercept) and calculates the 
    values associated with the independent axis based on the fit parameters.

    The calculation of the new values from the input independent axis should 
    be done by the following

    data_o[i] = slope x axis_i[i] + intercept
 
    where axis_i[i] is the i^th element of the independent 
    axis, slope is the slope of the linear fit, intercept is the 
    intercept of the linear fit and data_o[i] is the i^th 
    element of the calculated linear equation.
    
    Assuming that the uncertainties are uncorrelated, the uncertainty on a 
    given element of the calculated linear equation is
    
    sigma^2_o[i] = axis^2_i[i] sigma^2_slope + slope^2 sigma^2_axis_i[i] +
                   sigma^2_intercept

    where sigma^2_axis_i[i] is the i^th element of the 
    square uncertainty of the independent axis, sigma^2_slope is the 
    square uncertainty of the slope of the linear fit, 
    sigma^2_intercept is the square uncertainty of the intercept of 
    the linear fit and sigma^2_o[i] is the i^th element of the 
    square uncertainty of the calculated linear equation value.

    Parameters:
    ----------
    -> axis is an array of independent axis values
    -> axis_err2 is an array of the squares of the uncertainties associated
       with the independent axis values
    -> slope is the slope of the line from the fit
    -> slope_err2 is the square of the uncertainties associated with the slope
    -> intercept is the intercept of the line from the fit
    -> intercept_err2 is the square of the uncertainties associated with the
       intercept
    
    Returns:
    -------
    <- NessiList of values calculated from the independent axis with the fit
       parameters
    <- NessiList of the squares of the uncertainties associated with the
       values calculated from the independent axis with the fit parameters

    Exceptions:
    ----------
    <- IndexError is raised if any of the lists are not the same length
    <- TypeError is raised if any of the lists are not the same type
    <- TypeError is raised if any of the lists are not recognized types
    """
    
    if axis.__type__ != axis_err2.__type__:
        raise TypeError("Axis and Axis Err2 arrays are not the same type")

    if axis.__type__ == nessi_list.NessiList.DOUBLE:
        output = nessi_list.NessiList(len(axis))
        output_err2 = nessi_list.NessiList(len(axis_err2))

        utils_bind.eval_linear_fit_d(axis.__array__, axis_err2.__array__,
                                     slope, slope_err2,
                                     intercept, intercept_err2,
                                     output.__array__, output_err2.__array__)
        return (output, output_err2)
        
    else:
        raise TypeError("eval_linear_fit: Unknown primitive type %s" \
                        % str(axis.__type__))
    
##
# \}

##
# \defgroup fit_linear_background utils::fit_linear_background
# \{

##
# \brief This function fits a line to an array
#
# This function is described in section 3.43 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function takes an independent axis and the associated values and 
# errors and fits a linear function to those points. An optional range 
# can be specified that will restrict the fit region. That range is 
# specified via array elements (bins). If the maximum range bin is set to 
# zero then the ending bin is assumed to be the full length of the array 
# (length-1). The function uses the method of determinants which is described
# in detail in Chapter 6 of <em>Data Reduction and Error Analysis for the
# Physical Sciences</em> by Bevington and Robinson. 
# 
# The necessary formulas for the parameters from the method of determinants 
# are given by the following.
#
# \f[
# \Delta = \left(\sum\frac{1}{\sigma^2_i[i]}\right) 
# \left(\sum\frac{axis^2_i[i]}{\sigma^2_i[i]}\right)
# - \left(\sum\frac{axis_i[i]}{\sigma^2_i[i]} \right)^2
# \f]
# \f[
# slope = \frac{1}{\Delta} \left(\left(\sum\frac{1}{\sigma^2_i[i]}\right)
# \left(\sum\frac{axis_i[i]\:data_i[i]}{\sigma^2_i[i]}\right) - 
# \left(\sum\frac{axis_i[i]}{\sigma^2_i[i]}\right) 
# \left(\sum\frac{data_i[i]}{\sigma^2_i[i]}\right)\right)
# \f]
# \f[
# intercept = \frac{1}{\Delta} 
# \left(\left(\sum\frac{axis^2_i[i]}{\sigma^2_i[i]}\right)
# \left(\sum\frac{data_i[i]}{\sigma^2_i[i]}\right) - 
# \left(\sum\frac{axis_i[i]}{\sigma^2_i[i]}\right)
# \left(\sum\frac{axis_i[i]\:data_i[i]}{\sigma^2_i[i]}\right)\right)
# \f]
# \f[
# \sigma^2_{slope} = \frac{1}{\Delta} \sum\frac{1}{\sigma^2_i[i]}
# \f]
# \f[
# \sigma^2_{intercept} = \frac{1}{\Delta} 
# \sum\frac{axis^2_i[i]}{\sigma^2_i[i]}
# \f]
#
# where \f$axis_i[i]\f$ is the \f$i^{th}\f$ element of the independent 
# axis, \f$data_i[i]\f$ is the \f$i^{th}\f$ element of the input data array
# and \f$\sigma^2_i[i]\f$ is the \f$i^{th}\f$ element of the square 
# uncertainty in the input data array.
#
# \param axis (INPUT) is an array of independent axis values
# \param input (INTPUT) is an array of values associated with the 
# independent axis
# \param input_err2 (INPUT) is an array of the squares of the uncertainties 
# associated with the values
# \param min_bin (INPUT) is the minimum axis bin for the fit range
# \param max_bin (INPUT) is the maximum axis bin for the fit range
#
# \return
# - {"slope" : (slope, slope_err2), "intercept" : (intercept, intercept_err2)}
#
# \exception IndexError is raised if any of the lists are not the same length
# \exception TypeError is raised if any of the lists are not the same type
# \exception TypeError is raised if any of the lists are not recognized types
# \exception IndexError is raised if min_bin > max_bin

def fit_linear_background(axis, input, input_err2, min_bin, max_bin):
    """
    ---------------------------------------------------------------------------
    This function takes an independent axis and the associated values and 
    errors and fits a linear function to those points. An optional range 
    can be specified that will restrict the fit region. That range is 
    specified via array elements (bins). If the maximum range bin is set to 
    zero then the ending bin is assumed to be the full length of the array 
    (length-1).The function uses the method of determinants which is described
    in detail in Chapter 6 of Data Reduction and Error Analysis for the
    Physical Sciences by Bevington and Robinson. 
 
    The necessary formulas for the parameters from the method of determinants 
    are given by the following.

    Delta = Sum(1 / sigma^2_i[i]) * Sum(axis^2_i[i] / sigma^2_i[i]) 
            - (Sum(axis_i[i] / sigma^2_i[i])^2

    slope = (1 / Delta) * (Sum(1 / sigma^2_i[i]) *
            Sum((axis_i[i] * data_i[i]) / sigma^2_i[i]) - 
            Sum(axis_i[i] / sigma^2_i[i]) * Sum(data_i[i] / \sigma^2_i[i]))

    intercept = (1 / Delta) * (Sum(axis^2_i[i] / sigma^2_i[i]) * 
                Sum(data_i[i] / sigma^2_i[i]) - Sum(axis_i[i] / sigma^2_i[i]) *
                Sum((axis_i[i] * data_i[i]) / sigma^2_i[i]))

    sigma^2_slope = (1 / Delta) * Sum(1 / sigma^2_i[i])

    sigma^2_intercept = (1 / Delta) * Sum(axis^2_i[i] / sigma^2_i[i])

    where axis_i[i] is the i^th element of the independent axis, data_i[i]
    is the i^th element of the input data array and sigma^2_i[i] is the
    i^th element of the square uncertainty in the input data array.

    Inputs:
    ------
    -> axis_in is an array of independent axis values
    -> input is an array of values associated with the independent axis
    -> input_err2 is an array of the squares of the uncertainties associated
                  with the values
    -> min_bin is the minimum axis bin for the fit range
    -> max_bin is the maximum axis bin for the fit range

    Returns:
    -------
    <- Dictionary of {\"slope\" : (slope, slope_err2), \"intercept\" :
                     (intercept, intercept_err2))

    Exceptions:
    ----------
    <- IndexError is raised if any of the lists are not the same length
    <- TypeError is raised if any of the lists are not the same type
    <- TypeError is raised if any of the lists are not recognized types
    <- IndexError is raised if min_bin > max_bin
    """

    if input.__type__ != input_err2.__type__:
        raise TypeError("Input and Input Err2 arrays are not the same type")

    if input.__type__ != axis.__type__:
        raise TypeError("Input and Axis arrays are not the same type")

    if input.__type__ == nessi_list.NessiList.DOUBLE:
        slope = vpair_bind.DoubleVPair()
        intercept = vpair_bind.DoubleVPair()
        
        utils_bind.fit_linear_background_d(axis.__array__, input.__array__,
                                           input_err2.__array__,
                                           min_bin, max_bin,
                                           slope, intercept)
        
        return {"slope" : (slope.val, slope.val_err2),
                "intercept": (intercept.val, intercept.val_err2)}
    else:
        raise TypeError("fit_linear_background: Unknown primitive type %s" \
                        % str(input.__type__))

##
# \}

##
# \defgroup fit_reflectometer_background utils::fit_reflectometer_background
# \{

##
# \brief This function fits a plane to reflectometer 2D detector array data
#
# This function is described in section 3.42 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def fit_reflectometer_background():
    """
    ---------------------------------------------------------------------------
    This function fits a plane to reflectometer 2D detector array data

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError("This function is not implemented.")

##
# \}

##
# \defgroup linear_order_jacobian utils::linear_order_jacobian
# \{

##
# \brief This function calculates the linear order jacobian
#
# This function is described in section 3.49 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function corrects the input based on the ratio of differences 
# between bin boundaries from the associated orignal and transformed axes.
# This correction only applies to <b>histogram</b> data. <b>The incoming axes
# and counts arrays should be in their original form (no reversing), otherwise 
# the calculation of the Jacobians will be done incorrectly</b>. The 
# calculation of the linear order Jacobian is accomplished by:
#
# \f[
# I'[k] = I[k] \times \left|\frac{x[k+1] - x[k]}{x'[k+1] - x'[k]}\right|
# \f]
#
# where \f$I'[k]\f$ is the \f$k^{th}\f$ element of the corrected counts, 
# \f$I[k]\f$ is the \f$k^{th}\f$ element of the counts associated with a 
# particular histogram bin \f$k\f$, \f$x[k+1]\f$ is the high bin boundary 
# and \f$x[k]\f$ is the low bin boundary from the original axis and 
# \f$x'[k+1]\f$ is the high bin boundary and \f$x'[k]\f$ is the low bin 
# boundary from the transformed axis. 
#
# The square of the uncertainty is calculated via:
# 
# \f[
# \sigma^2_{I'}[k] = \sigma^2_I[k] \times \left(\frac{x[k+1] - x[k]}
# {x'[k+1] - x'[k]}\right)^2
# \f]
#
# where \f$\sigma^2_{I'}[k]\f$ is the \f$k^{th}\f$ element of the square of 
# the uncertainty of the corrected counts, \f$\sigma^2_I[k]\f$ is the 
# \f$k^{th}\f$ element of the square of the uncertainty in the counts 
# associated with a particular histogram bin \f$k\f$, \f$x[k+1]\f$ is the 
# high bin boundary and \f$x[k]\f$ is the low bin boundary from the 
# original axis and \f$x'[k+1]\f$ is the high bin boundary and \f$x'[k]\f$ 
# is the low bin boundary from the transformed axis.
#
# \param orig_axis (INPUT) is the original histogram axis associated with 
# the data
# \param transform_axis (INPUT) is the transformed histogram axis 
# associated with the data
# \param input (INPUT) is the counts data
# \param input_err2 (INPUT) is the square of the uncertainty in the counts 
# data
# \return
# - the corrected counts array
# - the corrected square of the uncertainty in the counts array
#

def linear_order_jacobian(orig_axis, transform_axis, input, input_err2):
    """
    This function corrects the input based on the ratio of differences 
    between bin boundaries from the associated orignal and transformed axes.
    This correction only applies to HISTOGRAM data. THE INCOMING AXES AND
    COUNTS ARRAYS SHOULD BE IN THEIR ORIGINAL FORM (NO REVERSING), OTHERWISE
    THE CALCULATION OF THE JACOBIANS WILL BE DONE INCORRECTLY. The calculation
    of the linear order Jacobian is accomplished by:

    I'[k] = I[k] * |(x[k+1] - x[k])/(x'[k+1] - x'[k])|

    where I'[k] is the k^{th} element of the corrected counts, I[k] is the
    k^{th} element of the counts associated with a particular histogram bin k,
    x[k+1] is the high bin boundary and x[k] is the low bin boundary from the
    original axis and x'[k+1] is the high bin boundary and x'[k] is the low
    bin boundary from the transformed axis. 

    The square of the uncertainty is calculated via:

    sigma^2_{I'}[k] = sigma^2_I[k] * ((x[k+1] - x[k])/(x'[k+1] - x'[k]))^2

    where sigma^2_{I'}[k] is the k^{th} element of the square of the
    uncertainty of the corrected counts, sigma^2_I[k] is the k^{th} element of
    the square of the uncertainty in the counts associated with a particular
    histogram bin k, x[k+1] is the high bin boundary and x[k] is the low bin
    boundary from the original axis and x'[k+1] is the high bin boundary and
    x'[k] is the low bin boundary from the transformed axis.

    Parameters:
    ----------
    -> orig_axis (INPUT) is the original histogram axis associated with the
    data
    -> transform_axis (INPUT) is the transformed histogram axis associated
    with the data
    -> input (INPUT) is the counts data
    -> input_err2 (INPUT) is the square of the uncertainty in the counts data

    Returns:
    -------
    <- The corrected counts array
    <- The corrected uncertainty squared in the counts array
    """

    if orig_axis.__type__ != input.__type__:
        raise TypeError("Original Axis and Input Data are not the same type.")

    if orig_axis.__type__ != transform_axis.__type__:
        raise TypeError("Original Axis and Transform Axis are not the same"\
                        +"type.")

    if input.__type__ != input_err2.__type__:
        raise TypeError("Input and Input Err2 arrays are not the same type")

    if input.__type__ == nessi_list.NessiList.DOUBLE:
        output = nessi_list.NessiList(len(input))
        output_err2 = nessi_list.NessiList(len(input_err2))
        utils_bind.linear_order_jacobian_d(orig_axis.__array__,
                                           transform_axis.__array__,
                                           input.__array__,
                                           input_err2.__array__,
                                           output.__array__,
                                           output_err2.__array__)

        return (output, output_err2)

    else:
        raise TyperError("Unknown primative type %s" % str(input.__type__))

##
# \}

##
# \defgroup linear_order_jacobian_s utils::linear_order_jacobian_s
# \{

##
# \brief This function calculates the linear order jacobian
#
# This function is described in section 3.49 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# This function corrects the input based on the ratio of differences 
# between bin boundaries from the associated orignal and transformed axes.
# This correction only applies to <b>histogram</b> data. <b>The bin boundaries
# should be in their original order (no reversing) with respect to the counts, 
# otherwise the calculation of the Jacobian will be incorrect</b>. The 
# calculation of the linear order Jacobian is accomplished by:
#
# \f[
# I' = I \times \left|\frac{x_{hi} - x_{lo}}{x'_{hi} - x'_{lo}}\right|
# \f]
#
# where \f$I'\f$ is the corrected counts, \f$I\f$ is the counts associated 
# with a particular histogram bin, \f$x_{hi}\f$ is the high bin boundary 
# and \f$x_{lo}\f$ is the low bin boundary from the original axis and 
# \f$x'_{hi}\f$ is the high bin boundary and \f$x'_{lo}\f$ is the low bin 
# boundary from the transformed axis.
#
# The square of the uncertainty is calculated via:
# 
# \f[
# \sigma^2_{I'} = \sigma^2_I \times \left(\frac{x_{hi} - x_{lo}}
# {x'_{hi} - x'_{lo}}\right)^2
# \f]
#
# where \f$\sigma^2_{I'}\f$ is the square of the uncertainty of the 
# corrected counts, \f$\sigma^2_I\f$ is the square of the uncertainty in 
# the counts associated with a particular histogram bin, \f$x_{hi}\f$ is 
# the high bin boundary and \f$x_{lo}\f$ is the low bin boundary from the 
# original axis and \f$x'_{hi}\f$ is the high bin boundary and 
# \f$x'_{lo}\f$ is the low bin boundary from the transformed axis.
#
# \param orig_axis_lo (INPUT) is the low bin boundary of the original 
# histogram axis associated with the data
# \param orig_axis_hi (INPUT) is the high bin boundary of the original 
# histogram axis associated with the data
# \param transform_axis_lo (INPUT) is the low bin boundary of the 
# transformed histogram axis associated with the data
# \param transform_axis_hi (INPUT) is the high bin boundary of the 
# transformed histogram axis associated with the data
# \param input (INPUT) is the counts data
# \param input_err2 (INPUT) is the square of the uncertainty in the counts 
# data
# \return 
# - the corrected counts
# - the corrected square of the uncertainty in the counts
#
   
def linear_order_jacobian_s(orig_axis_lo, orig_axis_hi, transform_axis_lo,
                            transform_axis_hi, input, input_err2):
   """
   This function corrects the input based on the ratio of differences 
   between bin boundaries from the associated orignal and transformed axes.
   This correction only applies to HISTOGRAM data. THE BIN BOUNDARIES SHOULD
   BE IN THEIR ORIGINAL ORDER (NO REVERSING) WITH RESPECT TO THE COUNTS,
   OTHERWISE THE CALCULATION OF THE JACOBIAN WILL BE INCORRECT. The
   calculation of the linear order Jacobian is accomplished by:

   I' = I * |(x_{hi} - x_{lo})/(x'_{hi} - x'_{lo})|

   where I' is the corrected counts, I is the counts associated with a
   particular histogram bin, x_{hi} is the high bin boundary and x_{lo} is the
   low bin boundary from the original axis and x'_{hi} is the high bin
   boundary and x'_{lo} is the low bin boundary from the transformed axis.

   The square of the uncertainty is calculated via:
 
   sigma^2_{I'} = sigma^2_I * ((x_{hi} - x_{lo})/(x'_{hi} - x'_{lo}))^2

   where sigma^2_{I'} is the square of the uncertainty of the corrected
   counts, sigma^2_I is the square of the uncertainty in the counts
   associated with a particular histogram bin, x_{hi} is the high bin boundary
   and x_{lo} is the low bin boundary from the original axis and x'_{hi} is
   the high bin boundary and x'_{lo} is the low bin boundary from the
   transformed axis.

   Parameters:
   ----------
   -> orig_axis_lo (INPUT) is the low bin boundary of the original histogram
   axis associated with the data
   -> orig_axis_hi (INPUT) is the high bin boundary of the original histogram
   axis associated with the data
   -> transform_axis_lo (INPUT) is the low bin boundary of the transformed
   histogram axis associated with the data
   -> transform_axis_hi (INPUT) is the high bin boundary of the transformed
   histogram axis associated with the data
   -> input (INPUT) is the counts data
   -> input_err2 (INPUT) is the square of the uncertainty in the counts data

   Returns:
   -------
   <- the corrected counts
   <- the corrected square of the uncertainty in the counts
   """

   try:
       output = vpair_bind.DoubleVPair()
       utils_bind.linear_order_jacobian_ss_d(float(orig_axis_lo),
                                             float(orig_axis_hi),
                                             float(transform_axis_lo),
                                             float(transform_axis_hi),
                                             float(input),
                                             float(input_err2),
                                             output)
       return (output.val, output.val_err2)       
   except TypeError:
       import sys
       import traceback
       tb = str(traceback.extract_tb(sys.exc_info()[2])[0]).split(',')
       func_name = str(tb[2]).strip().strip('\'')
       par_name = str(tb[3])
       open_paren_index = par_name.rfind('(')
       close_paren_index = par_name.rfind(')')
       par_name = par_name[open_paren_index+1:close_paren_index]
       raise TypeError("Argument %s:%s must be a string or a number" \
                       % (func_name, par_name))

##
# \}

##
# \defgroup matrix_multiplication utils::matrix_multiplication
# \{

##
# \brief This function multiplies data by a matrix
#
# This function is described in section 3.37 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def matrix_multiplication():
    """
    ---------------------------------------------------------------------------
    This function multiplies data by a matrix

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError("This function is not implemented.")

##
# \}

##
# \defgroup peak_integration utils::peak_integration
# \{

##
# \brief This function integrates intensity around Bragg peaks
#
# This function is described in section 3.35 of the SNS 107030214-TD0001-R00,
# "Data Reduction Library Software Requirements and Specifications".
#
# THIS FUNCTION HAS NOT BEEN DEFINED AND IS NOT IMPLEMENTED.
#
# \exception NotImplementedError is raised when the function is called since
#            it is not implemented.

def peak_integration():
    """
    ---------------------------------------------------------------------------
    This function integrates intensity around Bragg peaks

    Exceptions:
    ----------
    <- NotImplementedError is raised when the function is called since it is
       not implemented.

    """

    raise NotImplementedError("This function is not implemented.")

##
# \}

##
# \defgroup vector_is_equals utils::vector_is_equals
# \{

##
# \brief This function compares to vectors for equality.
#
# This function takes two vectors and checks equality on an
# element-by-element basis. One of the vectors contains the truth values
# from a given calculation.
#
# \param value (INPUT) is a calculated vector
# \param true_value (INPUT) is a truth vector corresponding to the
# calculated vector
#
# \return A boolean that is true if the vector is equal element-by-element
#

def vector_is_equals(value, true_value):

    """
    ---------------------------------------------------------------------------
    This function takes two vectors and checks equality on an
    element-by-element basis. One of the vectors contains the truth values
    from a given calculation.

    Parameters:
    ----------
    -> value is a calculated vector
    -> true_value  is a truth vector corresponding to the calculated vector

    Return:
    ------
    <- A boolean that is True if the vector is equal element-by-element,
       if not, it returns False

    """
    if (value.__type__ == true_value.__type__ ):
        if (value.__type__ == nessi_list.NessiList.DOUBLE):
            return utils_bind.vector_is_equals_d(value.__array__,
                                                 true_value.__array__)
        elif (value.__type__ == nessi_list.NessiList.INT):
            return utils_bind.vector_is_equals_i(value.__array__,
                                                 true_value.__array__)
        else:
            raise TypeError("Unknown type %s" % value.__type__)
            

    if (value.__type__ == nessi_list.NessiList.DOUBLE):
        value_d = nessi_list.NessiList(0, type=nessi_list.NessiList.DOUBLE)
        true_value_d = nessi_list.NessiList(0,
                                            type=nessi_list.NessiList.DOUBLE)
        for i in range(len(value)):
            value_d.append(value[i])
            true_value_d.append(true_value[i])

        result = utils_bind.vector_is_equals_d(value_d.__array__,
                                               true_value_d.__array__)
    else:
        value_i = nessi_list.NessiList(0, type=nessi_list.NessiList.INT)
        true_value_i = nessi_list.NessiList(0, type=nessi_list.NessiList.INT)
        for i in range(len(value)):
            value_i.append(value[i])
            true_value_i.append(true_value[i])
        result = utils_bind.vector_is_equals_i(value_i.__array__,
                                               true_value_i.__array__)

    return result

##
# \}

##
# \defgroup weighted_average utils::weighted_average
# \{

##
# \brief This function takes the weighted average of a slice of a NessiList.
#
# This function accepts two NessiLists (data and associated square of
# uncertainties), the starting element number and the ending element number in
# order to calculate the weighted average.
#
# \f[
# \mu = \frac{\sum^{bin_{end}}_{i=bin_{start}} \frac{x_i}{\sigma_i^2}}
# {\sum^{bin_{end}}_{i=bin_{start}} \frac{1}{\sigma_i^2}}
# \f]
#
# and the square of the uncertainty is calculated according to the
# following function
#
# \f[
# \sigma_{\mu}^2 = \frac{1}{\sum^{bin_{end}}_{i=bin_{start}} \frac{1}
# {\sigma_i^2}}
# \f]
#
# \param a (INPUT) the NessiList from which to calculate the weighted average
# \param ae2 (INPUT) the square of the uncertainty in the associated
# NessiList from which calculate the weighted average
# \param start (INPUT) the bin of the NessiList from which to start the
# calculation
# \param fin (INPUT) the bin of the NessiList at which to end the
# calculation
#
# \return
# - The weighted average
# - The square of the uncertainty in the weighted average
#
# \exception IndexError is raised if a and ae2 are not the same length
# \exception TypeError is raised if a is not of type double
# \exception TypeError is raised if a and ae2 are not the same type

def weighted_average(a, ae2, start, fin):

    """
    ---------------------------------------------------------------------------
    This function takes the weighted average of a slice of a NessiList.

    Parameters:
    __________

    -> a is the NessiList from which to calculate the weighted average
    -> ae2 is the square of the uncertainty in the associated NessiList
       from which calculate the weighted average
    -> start is the bin of the NessiList from which to start the calculation
    -> fin the bin of the NessiList at which to end the calculation

    Returns 2 doubles
    ______________________

    <- the weighted average of the NessiList slice
    <- the square of the uncertainty associated with the weighted
       average

    Exceptions:
    __________

    <- IndexError is raised if a and ae2 are not the same length
    <- TypeError is raised if a is found not to be of type double
    <- TypeError is raised if a and ae2 are not the same type

    """

    if (a.__type__ != a.DOUBLE):
        raise TypeError("Function only useable for doubles")

    if (a.__type__ != ae2.__type__):
        raise TypeError("Incompatible types passed to weighted_average")

    import vpair_bind

    weighted_ave = vpair_bind.DoubleVPair()
    utils_bind.weighted_average_d(a.__array__, ae2.__array__,
                                  start, fin, weighted_ave)

    return (weighted_ave.val, weighted_ave.val_err2)

##
# \}

