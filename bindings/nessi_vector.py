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
# \brief The purpose of this module is to provide an abstraction layer that
# hide the call to the functions according to the type of the instance.
#
# This class plays the role of a template for the function called
#
# For example: let us add together two NessiVectors of type float.
# Once the two NessiVector have been defined and fill with data, using the
# function <i>add</i> is like using the function <i>add_f</i>
# \code
# >>> NessiVector_result = add(NessiVector_1, NessiVector_2)
# \endcode
#

##
# \defgroup NessiVector nessi_vector::NessiVector
# \{
class NessiVector (list):

    FLOAT = "float"
    DOUBLE = "double"
    UINT = "uint"
    UNSIGNED = "unsigned"
    UNSIGNED_INT = "unsigned int"
    INT = "int"


##
# \ingroup __init__ NessiVector
#
# \brief   Initialization of an instance.
# A NessiVector can be defined in 4 ways.
#
# - Without any argument:
# \code
# >>> MyVector1 = NessiVector()
# \endcode
# in such case, the NessiVector is empty and of type <i>double</i> by default.
#
# - By declaring its size:
# \code
# >>> MyVector2 = NessiVector(2)
# \endcode
# MyVector2 contains 2 elements, set to 0, of type <i>double</i> (by default)
#
# - By declaring its type:
# \code
# >>> MyVector3 = NessiVector(type="float")
# \endcode
# MyVector3 is an empty NessiVector of type <i>float</i>
#
# - By declaring its size and type:
# \code
# >>> MyVector4 = NessiVector(4,"int")
# \endcode
# or
# \code
# >>> MyVector4 = NessiVector(length=4,type="int")
# \endcode
# \f$MyVector4\f$ is a 4 elements long, initialized to 0, NessiVector of type
# <i>int</i>
#
# \param self (INPUT) is the name of the NessiVector
# \param length (INPUT/OPTIONAL) is the length of the instance (0 by default)
# \param type (INPUT/OPTIONAL) is the type of the instance (<i>double</i> by
# default)
    def __init__(self, length=0, type=DOUBLE):

        if type.lower()==NessiVector.UNSIGNED_INT or \
               type.lower()==NessiVector.UNSIGNED or \
               type.lower()==NessiVector.UINT:
            self.__type__=self.UINT

            if length >= 0:
                self.__array__ = \
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
                with negative length"

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
# \ingroup append NessiVector
#
# Function used to append elements to a NessiVector
#
# This function is used to append a value to an instance of the NessiVector,
# <i>MyNessiVector</i>:
# \code
# >>> MyNessiVector.append(10.5)
# \endcode
# The size of the instance increases of 1 unit and the new element appended is
# the new last element of the instance. That can be a confusion in the case the
# size of the instance has already been declared during the initialization
# process. For example, if a NessiVector has been defined has a 5 elements
# long of type <i>float</i>
# \code
# >>> MyVector = NessiVector(5)
# \endcode
# the <i>append</i> method will add the new element after the 5 first "0".
# elements
# \code
# >>> MyVector.append(10.5)
# >>> MyVector[5]
# 10.5
# \endcode
# It is also possible to append several values in the same time as illustrated
# here:
# \code
# >>> MyNessiVector.append(1,2,3,4,5,6,7,8)
# \endcode
# This is the same as appending 1, then 2, then 3, and so on.... one after
# the other.
# \code
# >>> MyVector.append(1)
# >>> MyVector.append(2)
# >>> MyVector.append(3)
# >>> MyVector.append(4)
# ...
# \endcode
#
# \param self (INPUT) is the name of the NessiVector
# \param number (INPUT) is the number to append
#
    def append(self,*number):
        for num in number:
            self.__array__.append(num)

##
# \ingroup __repr__ NessiVector
#
# Function that is used to get the real state of a NessiVector
# \code
# >>> MyVector = NessiVector()
# >>> MyVector.append(1,2,3,4,5)
# >>> MyVector
# [1.0,2.0,3.0,4.0,5.0]
# \endcode
#
    def __repr__(self):
      return self.__str__()

##
# \ingroup __iter__ NessiVector
#
# Function not implemented yet
#
    def __iter__(self):
        print "Not implemented yet"

##
# \ingroup __getitem__ NessiVector
#
# Function used to get an element of a NessiVector.
# To get the \f$i^{th}\f$ value of the NessiVector \f$MyVectorA\f$,
# \code
# >>> MyVectorA[i]
# \endcode
# The last index of the NessiVector is displayed if one ask for an element
# of the NessiVector outside its range
#
    def __getitem__(self,m):     # need to throw exception when m>len(self)
        return self.__array__[m]

##
# \ingroup __getslice__ NessiVector
#
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
# \ingroup __len__ NessiVector
#
# Function used to get the length of a NessiVector
#
# \code
# >>> len(MyVectorA)
# \endcode
#
# \param self (INPUT) is the name of the NessiVector
# \return
# - The length of the NessiVector
#
    def __len__(self):
        return len(self.__array__)

##
# \ingroup __add__ NessiVector
#
# The operator \f$+\f$ allows to add two NessiVector together or each member
# of a NessiVector with a scalar
#
# To add two NessiVectors together or a NessiVector with a scalar, instead of
# using the function <i>add</i> provided by the NessiVectorUtils module,
# you can simply use the following technique:
# \code
# >>> NessiVector_VV = NessiVector_1 + NessiVector_2
# >>> NessiVector_VS = NessiVector + Scalar
# \endcode
# \return The resulting NessiVector
#
    def __add__(self,right):
        try:
            if (self.__type__ != right.__type__):
                 raise AttributeError, "NessiVectors don't have the same type"
            if (len(self)!=len(right)):
                raise IndexError
            else:
                c = NessiVector(type=self.__type__)
                for (a,b) in map(None,self.__array__,right.__array__):
                    c.append(a+b)
                return c
        except AttributeError:
            c = NessiVector(type=self.__type__)
            for i in range(len(self)):
                c.append(right+self.__array__[i])
            return c
        except IndexError:
            raise IndexError,"NessiVectors don't have the same size"

##
# \ingroup __radd__ NessiVector
#
# The operator \f$+\f$ allows to add a scalar with a NessiVector.
#
# To add each element of a NessiVector with a scalar, instead of using
# the function <i>add</i> provided by the NessiVectorUtils module, you
# can simply use the following technique:
# \code
# >>> NessiVector_SV = Scalar + NessiVector
# \endcode
# \return The resulting NessiVector
#
    def __radd__(self,left):
        c=NessiVector(type=self.__type__)
        for i in range(len(self)):
            c.append(self.__array__[i]+left)
        return c

##
# \ingroup __sub__ NessiVector
#
# The operator \f$-\f$ allows to substract two NessiVectors or each member of
# a NessiVector by a scalar.
#
# To substract one NessiVector from another or each member of a NessiVector
# by a scalar, instead of using the function <i>sub</i> provided by the
# NessiVectorUtils module, you can simply use the following technique:
# \code
# >>> NessiVector_VV = NessiVector_1 - NessiVector_2
# >>> NessiVector_VS = NessiVector - Scalar
# \endcode
#
# \return the resulting NessiVector
#
    def __sub__(self,right):
        try:
            if (self.__type__ != right.__type__):
                 raise AttributeError, "NessiVectors don't have the same type"
            if (len(self)!=len(right)):
                raise IndexError
            else:
                c = NessiVector(type=self.__type__)
                for (a,b) in map(None,self.__array__,right.__array__):
                    c.append(a-b)
                return c
        except AttributeError:
            c = NessiVector(type=self.__type__)
            for i in range(len(self)):
                c.append(self.__array__[i]-right)
            return c
        except IndexError:
            raise IndexError,"NessiVectors don't have the same size"
##
# \ingroup __rsub__ NessiVector
#
# The operator \f$-\f$ allows to substract a scalar by a NessiVector.
#
# To substract each element of a NessiVector from a scalar, instead of
# using the function <i>sub</i> provided by the NessiVectorUtils module,
# you can simply use the following technique:
# \code
# >>> NessiVector_SV = Scalar - NessiVector
# \endcode
#
# \return the resulting NessiVector
#
    def __rsub__(self,left):
        c=NessiVector(type=self.__type__)
        for i in range(len(self)):
            c.append(left - self.__array__[i])
        return c

##
# \ingroup __mult__ NessiVector
#
# The operator \f$\times\f$ allows to multiply two NessiVectors.
#
# To multiply two NessiVectors or each member of a NessiVector by a scalar,
# instead of using the function <i>mult</i> provided by the NessiVectorUtils
# module, you can simply use the following technique:
# \code
# >>> NessiVector_VV = NessiVector_1 * times NessiVector_2
# >>> NessiVector_VS = NessiVector * Scalar
# \endcode
#
    def __mul__(self,right):
        try:
            if (self.__type__ != right.__type__):
                 raise AttributeError, "NessiVectors don't have the same type"
            if (len(self)!=len(right)):
                raise IndexError
            else:
                c = NessiVector(type=self.__type__)
                for (a,b) in map(None,self.__array__,right.__array__):
                    c.append(a*b)
                return c
        except AttributeError:
            c = NessiVector(type=self.__type__)
            for i in range(len(self)):
                c.append(right*self.__array__[i])
            return c
        except IndexError:
            raise IndexError,"NessiVectors don't have the same size"

##
# \ingroup __rmult__ NessiVector
#
# The operator \f$\times\f$ allows to multiply a scalar by a NessiVector.
#
# To multiply each element of a NessiVector by a scalar, instead of using
# the function <i>mult</i> provided by the NessiVectorUtils module, you
# can simply use the following technique:
# \code
# >>> NessiVector_SV = scalar *  times NessiVector
# \endcode
#
# \return The resulting NessiVector
#
    def __rmul__(self,left):
        c=NessiVector(type=self.__type__)
        for i in range(len(self)):
            c.append(left * self.__array__[i])
        return c

##
# \ingroup __div__ NessiVector
#
# The operator \f$/\f$ allows to divide two NessiVectors.
#
# To divide two NessiVectors or each element of a NessiVector by a scalar,
# instead of using the function <i>div</i> provided by the NessiVectorUtils
# module, you can simply use the following technique:
# \code
# >>> NessiVector_VV = NessiVector_1 / NessiVector_2
# >>> NessiVector_VS = NessiVector / Scalar
# \endcode
#
    def __div__(self,right):
        try:
            if (self.__type__ != right.__type__):
                 raise AttributeError, "NessiVectors don't have the same type"
            if (len(self)!=len(right)):
                raise IndexError
            else:
                c = NessiVector(type=self.__type__)
                for (a,b) in map(None,self.__array__,right.__array__):
                    c.append(a/b)
                return c
        except AttributeError:
            c = NessiVector(type=self.__type__)
            for i in range(len(self)):
                c.append(self.__array__[i]/right)
            return c
        except IndexError:
            raise IndexError,"NessiVectors don't have the same size"

##
# \ingroup __rdiv__ NessiVector
#
# The operator \f$/\f$ allows to divide a scalar by a NessiVector.
#
# To divide a scalar by each element of a NessiVector, instead of using
# the function <i>div</i> provided by the NessiVectorUtils module, you
# can simply use the following technique:
# \code
# >>> NessiVector_SV = scalar /  times NessiVector
# \endcode
#
# \return The resulting NessiVector
#
    def __rdiv__(self,left):
        c=NessiVector(type=self.__type__)
        for i in range(len(self)):
            c.append(left / self.__array__[i])
        return c



##
# \ingroup __contains__ NessiVector
#
# Function "__contains__" not implemented yet
#
    def __contains__(self):
        print  "Not implemented yet"

##
# \ingroup __eq__ NessiVector
#
# Function "__eq__" not implemented yet
#
    def __eq__(self):
        raise exception, "Not implemented yet"

##
# \ingroup __ge__ NessiVector
#
# Function "__ge__" not implemented yet
#
    def __ge__(self):
        raise exception, "Not implemented yet"

##
# \ingroup __gt__ NessiVector
#
# Function "__gt__" not implemented yet
#
    def __gt__(self):
        raise exception, "Not implemented yet"

##
# \ingroup __ne__ NessiVector
#
# Function "__ne__" not implemented yet
#
    def __ne__(self):
        raise exception, "Not implemented yet"

##
# \ingroup __lt__ NessiVector
#
# Function "__lt__" not implemented yet
#
    def __lt__(self):
        raise exception, "Not implemented yet"

##
# \ingroup index NessiVector
#
# Function used to find index of a item by matching values
#
    def index(self,item):
        for i in range(len(self.__array__)):
            if self.__array__[i]==item:
                return i
        raise ValueError,"NessiVector.index(x): x not in list"

##
# \ingroup pop NessiVector
#
# Function used to remove the last element of the NessiVector
#
    def pop(self):
        if len(self.__array__)<=0:
            raise IndexError, "pop from empty Vector"
        else:
            return self.__array__.pop()

##
# \ingroup __str__ NessiVector
#
# This method displays elements of a NessiVector.
#
#  If the NessiVector contains more than 10 elements, the 10 first elements,
# follow by 3 dots ". . ." and the last element of the NessiVector are
# displayed.
# The default number of elements displayed can be changed by giving this number
# as second variable to the <i>print</i> method.
#
# \param self (INPUT) is the name of the NessiVector
# \param last (INPUT/OPTIONAL) is the number of element to display, 10 by
# default
#
# \return
# - a list of the n first elements, 3 dots and last element of the NessiVector,
# if the NessiVector contains more than n elements
# - a list of all the elements of the NessiVector, if the NessiVector is
# smaller than n.
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
# \defgroup max_vect nessi_vector::max_vect
# \{

##
# Give the maximum value of the NessiVector's elements
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

##
# Give the minimum value of the NessiVector's elements
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

##
# \defgroup print_multi nessi_vector::print_multi
# \{

##
# Display side by side the first n elements of two, or three NessiVectors.
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

    # find maximum value and then set the tab

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


##
# \}
