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

# SNS-FIXME: Desparately needs documentation (and review of you)

##
#\file bindings/nessi_list.py
#

##
# \namespace nessi_vector
#
# \brief The purpose of this module is to provide an abstraction layer that
# hide the call to the functions according to the type of the instance.
#
# This class plays the role of a template for the function called
#
# For example: let us add together two NessiLists of type float.
# Once the two NessiList have been defined and fill with data, using the
# function <i>add</i> is like using the function <i>add_f</i>
# \code
# >>> NessiList_result = add(NessiList_1, NessiList_2)
# \endcode
#

##
# \defgroup NessiList nessi_vector::NessiList
# \{
class NessiList (list):

    FLOAT = "float"
    DOUBLE = "double"
    UINT = "uint"
    UNSIGNED = "unsigned"
    UNSIGNED_INT = "unsigned int"
    INT = "int"

##
# \ingroup __init__ NessiList
#
# \brief   Initialization of an instance.
# A NessiList can be defined in 4 ways.
#
# - Without any argument:
# \code
# >>> MyVector1 = NessiList()
# \endcode
# in such case, the NessiList is empty and of type <i>double</i> by default.
#
# - By declaring its size:
# \code
# >>> MyVector2 = NessiList(2)
# \endcode
# MyVector2 contains 2 elements, set to 0, of type <i>double</i> (by default)
#
# - By declaring its type:
# \code
# >>> MyVector3 = NessiList(type="float")
# \endcode
# MyVector3 is an empty NessiList of type <i>float</i>
#
# - By declaring its size and type:
# \code
# >>> MyVector4 = NessiList(4,"int")
# \endcode
# or
# \code
# >>> MyVector4 = NessiList(length=4,type="int")
# \endcode
# \f$MyVector4\f$ is a 4 elements long, initialized to 0, NessiList of type
# <i>int</i>
#
# \param self (INPUT) is the name of the NessiList
# \param length (INPUT/OPTIONAL) is the length of the instance (0 by default)
# \param type (INPUT/OPTIONAL) is the type of the instance (<i>double</i> by
# default)
    def __init__(self, length=0, **kwargs):
        import nessi_vector_bind

        # check the length argument
        length=int(length)
        if length<0:
            raise Exception, "Cannot instantiate Vector with negative length"

        # get the type from the keyword arguments or set the default
        if(kwargs.has_key("type")):
            type=kwargs["type"].lower()
            if(type.lower()==NessiList.UNSIGNED_INT):
                type=NessiList.UINT
            elif(type.lower()==NessiList.UNSIGNED):
                type=NessiList.UINT
            else:
                type=type.lower() # lowercase everything else so code
                                  # below works
        else:
            type=NessiList.DOUBLE # set the default value
        self.__type__=type

        # call the correct instructor
        if type==NessiList.UINT:
            self.__array__ = nessi_vector_bind.UnsignedIntNessiVector(length)
        elif type==NessiList.INT:
            self.__array__ = nessi_vector_bind.IntNessiVector(length)
        elif type == NessiList.FLOAT:
            self.__array__ = nessi_vector_bind.FloatNessiVector(length)
        elif type == NessiList.DOUBLE:
            self.__array__ = nessi_vector_bind.DoubleNessiVector(length)
        else:
            raise Exception,"type [%s] not supported by NessiList" % type

##
# \ingroup append NessiList
#
# Function used to append elements to a NessiList
#
# This function is used to append a value to an instance of the NessiList,
# <i>MyNessiList</i>:
# \code
# >>> MyNessiList.append(10.5)
# \endcode
# The size of the instance increases of 1 unit and the new element appended is
# the new last element of the instance. That can be a confusion in the case the
# size of the instance has already been declared during the initialization
# process. For example, if a NessiList has been defined has a 5 elements
# long of type <i>double</i>
# \code
# >>> MyVector = NessiList(5)
# \endcode
# the <i>append</i> method will add the new element after the 5 first "0".
# elements
# \code
# >>> MyVector.append(10.5)
# >>> MyVector[5]
# 10.5
# \endcode
#
# \param self (INPUT) is the name of the NessiList
# \param number (INPUT) is the number to append
#
    def append(self,number):
        self.__array__.append(number)


##
# \ingroup extend NessiList
#
# Function used to append elements to a NessiList
#
# This function is used to append one or more values to an instance of
# the NessiList,
# <i>MyNessiList</i>:
# \code
# >>> MyNessiList.extend(10.5)
# \endcode
# The size of the instance increases of 1 unit and the new element appended is
# the new last element of the instance. That can be a confusion in the case the
# size of the instance has already been declared during the initialization
# process. For example, if a NessiList has been defined has a 5 elements
# long of type <i>double</i>
# \code
# >>> MyVector = NessiList(5)
# \endcode
# the <i>extend</i> method will add the new element after the 5 first "0".
# elements
# \code
# >>> MyVector.extend(10.5)
# >>> MyVector[5]
# 10.5
# \endcode
# It is also possible to extend several values in the same time as
# illustrated here:
# \code
# >>> MyNessiList.extend(1,2,3,4,5,6,7,8)
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
# \param self (INPUT) is the name of the NessiList
# \param *number (INPUT) is the number(s) to append
#
    def extend(self,*number):
        for num in number:
            try:
                for i in num:
                    self.__array__.append(i)
            except TypeError:
                    self.__array__.append(num)

##
# \ingroup __repr__ NessiList
#
# Function that is used to get the real state of a NessiList
# \code
# >>> MyVector = NessiList()
# >>> MyVector.append(1,2,3,4,5)
# >>> MyVector
# [1.0,2.0,3.0,4.0,5.0]
# \endcode
#
    def __repr__(self):
        return self.__str__()

##
# \ingroup __iter__ NessiList
#
# Function returns an iterator for a NessiList
#
    def __iter__(self):
        return iter(self.__array__)

##
# \ingroup __reversed__ NessiList
#
# Function returns a backwards iterator for a NessiList
#
    def __reversed__(self):
        i=len(self.__array__)-1
        while True:
            try:
                yield self.__array__[i]
            except IndexError:
                raise StopIteration
            i=i-1

##
# \ingroup __getitem__ NessiList
#
# Function used to get an element of a NessiList.
# To get the \f$i^{th}\f$ value of the NessiList \f$MyVectorA\f$,
# \code
# >>> MyVectorA[i]
# \endcode
# The last index of the NessiList is displayed if one ask for an element
# of the NessiList outside its range
#
    def __getitem__(self,m):     # need to throw exception when m>len(self)
        return self.__array__[m]

##
# \ingroup __setitem__ NessiList
#
# Function used to set an element of a NessiList.
# To set the \f$i^{th}\f$ value of the NessiList \f$MyVectorA\f$,
# \code
# >>> MyVectorA[i]=5
# \endcode
#
    def __setitem__(self,m,val):
        return self.__array__.__setitem__(m,val)

##
# \ingroup __getslice__ NessiList
#
# Function used to get a range of values from a NessiList. Negative
# indices are not supported.
#
# \param self (INPUT) is the name of the NessiList
# \param i (INPUT/OPTIONAL) is the index of the first element to get (0 by
# default, i.e., first element of the NessiList)
# \param j (INPUT/OPTIONAL) is the index + 1 of the last element to get (-1 by
# default, i.e., last element of the NessiList)
# \return
# - The elements defined by the slice
#
    def __getslice__(self,i=0,j=-1):
        return self.__array__[i:j]

##
# \ingroup __setslice__ NessiList
#
# Function used to get a range of values from a NessiList. Negative
# indices are not supported.
#
    def __setslice__(self,i,j,val):
        return self.__array__.__setslice__(i,j,val)

##
# \ingroup __len__ NessiList
#
# Function used to get the length of a NessiList
#
# \code
# >>> len(MyVectorA)
# \endcode
#
# \param self (INPUT) is the name of the NessiList
# \return
# - The length of the NessiList
#
    def __len__(self):
        return len(self.__array__)

##
# \ingroup __add__ NessiList
#
# The operator \f$+\f$ allows to add two NessiList together or each member
# of a NessiList with a scalar
#
# To add two NessiLists together or a NessiList with a scalar, instead of
# using the function <i>add</i> provided by the NessiListUtils module,
# you can simply use the following technique:
# \code
# >>> NessiList_VV = NessiList_1 + NessiList_2
# >>> NessiList_VS = NessiList + Scalar
# \endcode
# \return The resulting NessiList
#
    def __add__(self,right):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot add things of unequal length"
            result=NessiList(type=self.__type__)

            for (a,b) in map(None,self,right):
                result.append(a+b)
            return result

        except TypeError: # must be a scalar
            result=NessiList(type=self.__type__)
            for a in self:
                result.append(a+right)
            return result

        raise Exception,"This statement should never be reached"

##
# \ingroup __radd__ NessiList
#
# The operator \f$+\f$ allows to add a scalar with a NessiList.
#
# To add each element of a NessiList with a scalar, instead of using
# the function <i>add</i> provided by the NessiListUtils module, you
# can simply use the following technique:
# \code
# >>> NessiList_SV = Scalar + NessiList
# \endcode
# \return The resulting NessiList
#
    def __radd__(self,left):
        return self+left

##
# \ingroup __iadd__ NessiList
#
# The operator \f$+=\f$ allows to add a NessiList in place
#
# To add each element of a NessiList with a scalar, instead of using
# the function <i>add</i> provided by the NessiListUtils module, you
# can simply use the following technique:
# \code
# >>> NessiList_SV = Scalar + NessiList
# \endcode
# \return The resulting NessiList
#
    def __iadd__(self,right):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot add things of unequal length"

            for i in range(len(self)):
                self[i]=self[i]+right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i]=self[i]+right
            return self

        raise Exception,"This statement should never be reached"

#
# \ingroup __sub__ NessiList
#
# The operator \f$-\f$ allows to subtract two NessiLists or each member of
# a NessiList by a scalar.
#
# To substract one NessiList from another or each member of a NessiList
# by a scalar, instead of using the function <i>sub</i> provided by the
# NessiListUtils module, you can simply use the following technique:
# \code
# >>> NessiList_VV = NessiList_1 - NessiList_2
# >>> NessiList_VS = NessiList - Scalar
# \endcode
#
# \return the resulting NessiList
#
    def __sub__(self,right):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot subtract things of unequal length"
            result=NessiList(type=self.__type__)

            for (a,b) in map(None,self,right):
                result.append(a-b)
            return result

        except TypeError: # must be a scalar
            result=NessiList(type=self.__type__)
            for a in self:
                result.append(a-right)
            return result

        raise Exception,"This statement should never be reached"

##
# \ingroup __rsub__ NessiList
#
# The operator \f$-\f$ allows to subtract a scalar by a NessiList.
#
# To substract each element of a NessiList from a scalar, instead of
# using the function <i>sub</i> provided by the NessiListUtils module,
# you can simply use the following technique:
# \code
# >>> NessiList_SV = Scalar - NessiList
# \endcode
#
# \return the resulting NessiList
#
    def __rsub__(self,left):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot subtract things of unequal length"
            result=NessiList(type=self.__type__)

            for (a,b) in map(None,self,right):
                result.append(b-a)
            return result

        except TypeError: # must be a scalar
            result=NessiList(type=self.__type__)
            for a in self:
                result.append(left-a)
            return result

        raise Exception,"This statement should never be reached"

##
# \ingroup __isub__ NessiList
#
# The operator \f$-=\f$ allows to subtract a NessiList inplace
#
# To substract each element of a NessiList from a scalar, instead of
# using the function <i>sub</i> provided by the NessiListUtils module,
# you can simply use the following technique:
# \code
# >>> NessiList_SV = Scalar - NessiList
# \endcode
#
# \return the resulting NessiList
#
    def __isub__(self,right):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot subtract things of unequal length"

            for i in range(len(self)):
                self[i]=self[i]-right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i]=self[i]-right
            return self

        raise Exception,"This statement should never be reached"

##
# \ingroup __mul__ NessiList
#
# The operator \f$\times\f$ allows to multiply two NessiLists.
#
# To multiply two NessiLists or each member of a NessiList by a scalar,
# instead of using the function <i>mult</i> provided by the NessiListUtils
# module, you can simply use the following technique:
# \code
# >>> NessiList_VV = NessiList_1 * times NessiList_2
# >>> NessiList_VS = NessiList * Scalar
# \endcode
#
    def __mul__(self,right):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot multiply things of unequal length"
            result=NessiList(type=self.__type__)

            for (a,b) in map(None,self,right):
                result.append(a*b)
            return result

        except TypeError: # must be a scalar
            result=NessiList(type=self.__type__)
            for a in self:
                result.append(a*right)
            return result

        raise Exception,"This statement should never be reached"

##
# \ingroup __rmul__ NessiList
#
# The operator \f$\times\f$ allows to multiply a scalar by a NessiList.
#
# To multiply each element of a NessiList by a scalar, instead of using
# the function <i>mult</i> provided by the NessiListUtils module, you
# can simply use the following technique:
# \code
# >>> NessiList_SV = scalar *  times NessiList
# \endcode
#
# \return The resulting NessiList
#
    def __rmul__(self,left):
        return self*left

##
# \ingroup __imul__ NessiList
#
# The operator \f$\times=\f$ allows to multiply a NessiList in place.
#
# To multiply each element of a NessiList by a scalar, instead of using
# the function <i>mult</i> provided by the NessiListUtils module, you
# can simply use the following technique:
# \code
# >>> NessiList_SV = scalar *  times NessiList
# \endcode
#
# \return The resulting NessiList
#
    def __imul__(self,right):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot multiply things of unequal length"

            for i in range(len(self)):
                self[i]=self[i]*right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i]=self[i]*right
            return self

        raise Exception,"This statement should never be reached"

##
# \ingroup __div__ NessiList
#
# The operator \f$/\f$ allows to divide two NessiLists.
#
# To divide two NessiLists or each element of a NessiList by a scalar,
# instead of using the function <i>div</i> provided by the NessiListUtils
# module, you can simply use the following technique:
# \code
# >>> NessiList_VV = NessiList_1 / NessiList_2
# >>> NessiList_VS = NessiList / Scalar
# \endcode
#
    def __div__(self,right):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot divide things of unequal length"
            result=NessiList(type=self.__type__)

            for (a,b) in map(None,self,right):
                result.append(a/b)
            return result

        except TypeError: # must be a scalar
            result=NessiList(type=self.__type__)
            for a in self:
                result.append(a/right)
            return result

        raise Exception,"This statement should never be reached"

##
# \ingroup __rdiv__ NessiList
#
# The operator \f$/\f$ allows to divide a scalar by a NessiList.
#
# To divide a scalar by each element of a NessiList, instead of using
# the function <i>div</i> provided by the NessiListUtils module, you
# can simply use the following technique:
# \code
# >>> NessiList_SV = scalar /  times NessiList
# \endcode
#
# \return The resulting NessiList
#
    def __rdiv__(self,left):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot divide things of unequal length"

            for i in range(len(self)):
                self[i]=self[i]/right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i]=self[i]/right
            return self

        raise Exception,"This statement should never be reached"

##
# \ingroup __idiv__ NessiList
#
# The operator \f$/=\f$ allows to divide a NessiList in place
#
# To divide a scalar by each element of a NessiList, instead of using
# the function <i>div</i> provided by the NessiListUtils module, you
# can simply use the following technique:
# \code
# >>> NessiList_SV = scalar /  times NessiList
# \endcode
#
# \return The resulting NessiList
#
    def __idiv__(self,right):
        try:
            if len(self)!=len(right):
                raise ValueError,"Cannot divide things of unequal length"

            for i in range(len(self)):
                self[i]=self[i]/right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i]=self[i]/right
            return self

        raise Exception,"This statement should never be reached"

##
# \ingroup __contains__ NessiList
#
# Function "__contains__" needs documentation
#
    def __contains__(self,value):
        try:
            self.index(value)
            return True
        except ValueError:
            return False

##
# \ingroup __eq__ NessiList
#
# Function "__eq__" not implemented yet
#
    def __eq__(self,other):
        # check if they have the same length
        try:
            if len(self)!=len(other):
                return False
        except:
            return False

        # deep comparison
        import utils
        try:
            for (mine,yours) in map(None,self,other):
                if utils.compare(mine,yours)!=0:
                    return False
        except:
            return False

        # anything that gets here must be okay
        return True


##
# \ingroup __ge__ NessiList
#
# Function "__ge__" not implemented yet
#
    def __ge__(self,other):
        # deep comparison
        import utils
        try:
            for (mine,yours) in map(None,self,other):
                if(utils.compare(mine,yours)<0):
                    return False
        except:
            return False

        # anything that gets here must be okay
        return True

##
# \ingroup __gt__ NessiList
#
# Function "__gt__" not implemented yet
#
    def __gt__(self,other):
        # deep comparison
        import utils
        try:
            for (mine,yours) in map(None,self,other):
                if(utils.compare(mine,yours)!=1):
                    return False
        except:
            return False

        # anything that gets here must be okay
        return True

##
# \ingroup __ne__ NessiList
#
# Function "__ne__" not implemented yet
#
    def __ne__(self,other):
        return not self.__eq__(other)

##
# \ingroup __lt__ NessiList
#
# Function "__lt__" not implemented yet
#
    def __lt__(self,other):
        return not self.__ge__(other)

##
# \ingroup __le__ NessiList
#
# Function "__le__" not implemented yet
#
    def __le__(self,other):
        return not self.__gt__(other)

##
# \ingroup index NessiList
#
# Function used to find index of a item by matching values.
#
    def index(self,item,start=0,stop=-1):
        # fix the arguments
        if stop<start:
            stop=len(self.__array__)

        # search for the next occurence
        import utils
        for i in range(start,stop):
            if utils.compare(self.__array__[i],item)==0:
                return i
        raise ValueError,"NessiList.index(x): x not in list"

##
# \ingroup count NessiList
#
# Function used to count the number of occurences of a value
#
    def count(self,value):
        start=0
        count=0
        try:
            while True:
                start=self.index(value,start)+1
                count=count+1
        except ValueError:
            pass
            
        return count

##
# \ingroup pop NessiList
#
# Function used to remove the last element of the NessiList
#
    def pop(self,index=-1):
        if len(self.__array__)<=0:
            raise IndexError, "pop from empty Vector"

        result=self[index]
        del self[index]
        return result

##
# \ingroup __str__ NessiList
#
# This method displays elements of a NessiList.
#
#  If the NessiList contains more than 10 elements, the 10 first elements,
# follow by 3 dots ". . ." and the last element of the NessiList are
# displayed.
# The default number of elements displayed can be changed by giving this number
# as second variable to the <i>print</i> method.
#
# \param self (INPUT) is the name of the NessiList
# \param last (INPUT/OPTIONAL) is the number of element to display, 10 by
# default
#
# \return
# - a list of the n first elements, 3 dots and last element of the NessiList,
# if the NessiList contains more than n elements
# - a list of all the elements of the NessiList, if the NessiList is
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

    def insert(self,index,object):
        # insert before index
        raise NotImplementedError,"This operation is not currently supported"

    def __delitem__(self,index):
        del self.__array__[index]

    def __delslice__(self,i=0,j=-1):
        del self.__array__[i:j]

    def remove(self,value):
        # remove first occurence of value
        index=self.index(value)
        del self[index]

    def reverse(self):
        # reverse in place
        import axis_manip
        axis_manip.reverse_array_nc(self)
        return self

    def sort(self,cmp=None,key=None,reverse=False):
        raise NotImplementedError,"This function is not allowed"

##
# \}


##
# \defgroup max_vect nessi_vector::max_vect
# \{

##
# Give the maximum value of the NessiList's elements
#
# \param array (INPUT) is the name of the NessiList
#
# \return The maximum value of the NessiList <i>object</i>
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
# Give the minimum value of the NessiList's elements
#
# \param array (INPUT) is the name of the NessiList
#
# \return The minimum value of the NessiList <i>object</i>.
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
# Display side by side the first n elements of two, or three NessiLists.
#
# \param n (INPUT) is number of element to display
# \param object1 (INPUT) is the name of the first NessiList
# \param object2 (INPUT) is the name of the second NessiList
# \param object3 (INPUT/OPTIONAL) is the name of the third NessiList
#
# \return display of the first n elements of the two, or three NessiLists.
def print_multi(n,object1,object2,object3=NessiList()):

    tab="\t\t"
    str_output = ""

    # find maximum value and then set the tab

    if (max_vect(object1) <= 9999):
        pass
    else:
        tab = tab + "\t"

    for i in range(0,n):

        if (object1.__type__ == NessiList.FLOAT or
            object1.__type__ == NessiList.DOUBLE):

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

