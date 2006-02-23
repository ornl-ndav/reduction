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
#\file bindings/nessi_vector.py 
#
import array_manip_bind
import nessi_vector_bind

##
# \namespace nessi_vector
#
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
#
##
# \defgroup py_NessiVector NessiVector
# \{
class NessiVector (list):

    FLOAT = "float"
    DOUBLE = "double"
    UINT = "uint"
    UNSIGNED = "unsigned"
    UNSIGNED_INT = "unsigned int"
    INT = "int"

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
    def __init__(self, length=0, type=DOUBLE):

        if type.lower()==NessiVector.UNSIGNED_INT or \
        type.lower()==NessiVector.UNSIGNED or \
        type.lower()==NessiVector.UINT:
            self.__type__=self.UINT

            if length >= 0:
                self.__array__ =     \
            nessi_vector_bind.UnsignedIntNessiVector(length)
            else:
                raise Exception, "Cannot instantiate Vector \
                        with negative length"

        elif type.lower()==NessiVector.INT:
            self.__type__=self.INT

            if length >= 0:
                self.__array__ = \
            nessi_vector_bind.IntNessiVector(length)
            else:
                raise Exception, "Cannot instantiate Vector \
                with negative length"

        elif type.lower() == NessiVector.FLOAT:
            self.__type__=self.FLOAT

            if length >= 0:
                self.__array__ = \
            nessi_vector_bind.FloatNessiVector(length)
            else:
                raise Exception, "Cannot instantiate Vector \
                with  negative length"

        elif type.lower() == NessiVector.DOUBLE:
            self.__type__ = self.DOUBLE

            if length >= 0:
                self.__array__ = \
            nessi_vector_bind.DoubleNessiVector(length)
            else:
                raise Exception, "Cannot instantiate Vector \
                with negative length"
        else:
            raise Exception,"type not supported by NessiVector"

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
        for num in number:
            self.__array__.append(num)

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
        return self.__array__[m]
        
##
# Function used to get a range of values from a NessiVector. Negative
# indices are not supported.
#
# \param self (INPUT) is the name of the NessiVector
# \param i (INPUT/OPTIONAL) is the index of the first element to get (0 by
# default, i.e., first element of the NessiVector)
# \param j (INPUT/OPTIONAL) is the index + 1 of the last element to get (-1 by
# default, i.e., last element of the NessiVector)
# \return
# - The elements defined by the slice
#
    def __getslice__(self,i=0,j=-1):
        return self.__array__[i:j]

##
# Function used to get the length of a NessiVector
#
# \f[
# >>> len(MyVectorA)
# \f]
#
# \param self (INPUT) is the name of the NessiVector
# \return 
# - The length of the NessiVector
#

    def __len__(self):
        return len(self.__array__)

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
        c = NessiVector(len(self))
        for i in range(len(self)):
            c.__array__[i]=self.__array__[i]+right.__array__[i]
        return c

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
        c = NessiVector(len(self))
        for i in range(len(self)):
            c.__array__[i]=self.__array__[i]-right.__array__[i]
        return c

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
        c = NessiVector(len(self))
        for i in range(len(self)):
            c.__array__[i]=self.__array__[i]*right.__array__[i]
        return c

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
        c = NessiVector(len(self))
        for i in range(len(self)):
            c.__array__[i]=self.__array__[i]/right.__array__[i]
        return c

##
# Function "__contains__" not implemented yet
#
    def __contains__(self):
        print  "Not implemented yet"

##
# Function "__eq__" not implemented yet
#

    def __eq__(self):
        raise exception, "Not implemented yet"

##
# Function "__ge__" not implemented yet
#
    def __ge__(self):
        raise exception, "Not implemented yet"

##
# Function "__gt__" not implemented yet
#
    def __gt__(self):
        raise exception, "Not implemented yet"

##
# Function "__ne__" not implemented yet
#
    def __ne__(self):
        raise exception, "Not implemented yet"

##
# Function "__lt__" not implemented yet
#
    def __lt__(self):
        raise exception, "Not implemented yet"

##
# Function "pop" not implemented yet"
#
    def pop(self):
        if len(self.__array__)<=0:
            raise IndexError, "pop from empty Vector"
        else:
			return self.__array__.pop()


##
# \brief This method displays elements of a NessiVector.
#
#  If the NessiVector contains more than 10 elements, the 10 first elements,
# follow by 3 dots ". . ." and the last element of the NessiVector are displayed.
# The default number of elements displayed can be changed by giving this number
# as second variable to the <i>print</i> method.
#
# \param self (INPUT) is the name of the NessiVector
# \param last (INPUT/OPTIONAL) is the number of element to display, 10 by default
#
# \return
# - n first elements, 3 dots and last element of the NessiVector,
# if the NessiVector contains more than n elements
# - all the elements of the NessiVector, if the NessiVector is smaller than n.
#
# The number are displayed with 16 digits after the decimal separator.
#

    def __str__(self,last=10):

        result=[]
        
        if len(self)<last:
            last=len(self)

        # print the first n elements
        for i in range(0,last):
            result.append(str(self.__array__[i]))

        # print elipses and the last element
        if len(self) > last:
            result.append("...")
            result.append(str(self.__array__[len(self)-1]))

        return "["+",".join(result)+"]"

##
#\}
#

##
# \defgroup print_multi nessi_vector::print_multi
# \{
#

##
# \brief Display side by side the first n elements of two, or three NessiVectors.
#
# \param n (INPUT) is number of element to display
# \param object1 (INPUT) is the name of the first NessiVector
# \param object2 (INPUT) is the name of the second NessiVector
# \param object3 (INPUT/OPTIONAL) is the name of the third NessiVector
#
# \return display of the first n elements of the two, or three NessiVectors.

def print_multi(n,object1,object2,object3=NessiVector()):

    tab="\t\t"
    str_output = ""

    #find maximum value and then set the tab

    if (max_vect(object1) <= 9999):
        pass
    else:
        tab = tab + "\t"

    for i in range(0,n):

        if (object1.__type__ == NessiVector.FLOAT or
            object1.__type__ == NessiVector.DOUBLE):

                str_output = str_output + "%7.16f " \
                    %object1[i] + tab + \
                    "%7.16f " %object2[i]

                if len(object3) !=0:
                    str_output = str_output + \
                    tab + "%7.16f \n" %object3[i]

        else:
            for i in range(0,n):
                str_output = str_output + "%d " %object1[i] \
                    + tab + "%d " %object2[i]

                if len(object3) !=0:
                    print str_output + tab + "%d \n" %object3[i]

        str_output = str_output

    print str_output

##
# \}
#

##
# \defgroup max_vect nessi_vector::max_vect
# \{
#

##
# \brief Give the maximum value of the NessiVector's elements
#
# \param array (INPUT) is the name of the NessiVector
#
# \return The maximum value of the NessiVector <i>object</i>
#
def max_vect(array):
    max_value = array[0]
    for it in array:
        if it > max_value:
            max_value = it

    return max_value

##
# \}

##
# \defgroup min_vect nessi_vector::min_vect
# \{
#

##
# \brief Give the minimum value of the NessiVector's elements
#
# \param array (INPUT) is the name of the NessiVector
#
# \return The minimum value of the NessiVector <i>object</i>.
#
def min_vect(array):
    min_value = array[0]
    for it in array:
        if it < min_value:
            min_value = it

    return min_value

##
# \}