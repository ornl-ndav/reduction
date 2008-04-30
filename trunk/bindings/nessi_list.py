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
#\file bindings/nessi_list.py
#

"""
   This module creates a NessiList class that provides an abstraction layer
   for the PBL NessiVector class.

   There are also a few helper functions in this module that deal with finding
   the maximum or the minimum of a NessiList and print up to three NessiLists
   side-by-side.
"""

import nessi_vector_bind

from scl_defs import VERSION as __version__

##
# \namespace nessi_list
#
# \brief The module provides an abstraction layer for the PBL NessiVector
#        class that handles data and uncertainty storage.
#
# This module creates a NessiList class that provides an abstraction layer
# for the PBL NessiVector class.
#
# There are also a few helper functions in this module that deal with finding
# the maximum or the minimum of a NessiList and print up to three NessiLists
# side-by-side.

##
# \defgroup NessiList nessi_list::NessiList
# \{
class NessiList (list):

    DOUBLE = "double"
    INT = "int"

##
# \ingroup __init__ NessiList
#
# \brief Initialization of an instance of NessiList.
#
# A NessiList can be defined in 4 ways.
#
# - Without any argument:
# \code
# >>> MyNessiList1 = NessiList()
# \endcode
# in such case, the NessiList is empty and of type <i>double</i> by default.
#
# - By declaring its size:
# \code
# >>> MyNessiList2 = NessiList(2)
# \endcode
# MyNessiList2 contains 2 elements, set to 0, of type <i>double</i> (by
# default)
#
# - By declaring its type:
# \code
# >>> MyNessiList3 = NessiList(type="int")
# \endcode
# MyNessiList3 is an empty NessiList of type <i>int</i>
#
# - By declaring its size and type:
# \code
# >>> MyNessiList4 = NessiList(4,"int")
# \endcode
# or
# \code
# >>> MyNessiList4 = NessiList(length=4,type="int")
# \endcode
# MyNessiList4 is a 4 elements long, initialized to 0, NessiList of type
# <i>int</i>
#
# \param self <i>this</i>
# \param length (INPUT/OPTIONAL) is the length of the instance (0 by default)
# \param kwargs (INPUT/OPTIONAL) is a list of keywords for the class. The
#        keyword <i>type</i> is used to specifiy the type of the instance
#        (<i>double</i> by default)
#
# \exception Exception is raised if the type given to the instantiation is
#            not recognized
# \exception IndexError is raised if the NessiList is instantiated with a
#            negative length

    def __init__(self, length=0, **kwargs):
        """
        -----------------------------------------------------------------------
         A NessiList can be defined in 4 ways.

         - Without any argument:

         >>> MyNessiList1 = NessiList()

         in such case, the NessiList is empty and of type double by default.

         - By declaring its size:

         >>> MyNessiList2 = NessiList(2)

         MyNessiList2 contains 2 elements, set to 0, of type double (by
         default)

         - By declaring its type:

         >>> MyNessiList3 = NessiList(type=\"int\")

         MyNessiList3 is an empty NessiList of type int

         - By declaring its size and type:

         >>> MyNessiList4 = NessiList(4,\"int\")

         or

         >>> MyNessiList4 = NessiList(length=4,type=\"int\")

         MyNessiList4 is a 4 elements long, initialized to 0, NessiList of type
         int

         Parameters:
         ----------
         -> length is the length of the instance (0 by default)
         -> kwargs is a list of keywords for the class. The keyword \"type\"
            is used to specifiy the type of the instance (double by default)
            array=<<Type>NessiVector or None> is used to pass a
                  <Type>NessiVector to the instance and avoid a duplicate
                  constructor call

         Exceptions:
         ----------
         <- Exception is raised if the type given to the instantiation is
            not recognized
         <- IndexError is raised if the NessiList is instantiated with a
            negative length

        """

        # check the length argument
        length=int(length)
        if length<0:
            raise IndexError("Cannot instantiate List with negative length")

        # get the type from the keyword arguments or set the default
        if(kwargs.has_key("type")):
            type = kwargs["type"].lower()
            type = type.lower() # lowercase everything else so code
                                # below works
        else:
            type = NessiList.DOUBLE # set the default value
        self.__type__ = type

        try:
            array = kwargs["array"]
            use_array = True
        except KeyError:
            use_array = False

        # call the correct instructor
        if type == NessiList.INT:
            if not use_array:
                self.__array__ = nessi_vector_bind.IntNessiVector(length)
            else:
                self.__array__ = array
        elif type == NessiList.DOUBLE:
            if not use_array:
                self.__array__ = nessi_vector_bind.DoubleNessiVector(length)
            else:
                self.__array__ = array
        else:
            raise Exception("type [%s] not supported by NessiList" % type)

##
# \ingroup __deepcopy__ NessiList
#
# \brief Function used to provide a deep copy of a NessiList
#
# This function provides a mechanism for getting a deep copy of a NessiList
# using the following convention:
# \code
# a = NessiList()
# import copy
# b = copy.deepcopy(a)
# \endcode
#
# \param self <i>this</i>
# \param memo (INPUT/OPTIONAL) is a dictionary
#
# \return A deeply copied NessiList

    def __deepcopy__(self, memo = {}):
        """
        This function provides a mechanism for getting a deep copy of a
        NessiList using the following convention:

        a = NessiList()
        import copy
        b = copy.deepcopy(a)

        Parameters:
        ----------
        -> memo (INPUT/OPTIONAL) is a dictionary

        Returns:
        -------
        <- A deeply copied NessiList
        """
        
        from copy import deepcopy
        result = self.__class__(array=None)
        memo[id(self)] = result
        result.__type__ = self.__type__
        if self.__type__ == NessiList.INT:
            result.__array__ = nessi_vector_bind.IntNessiVector(self.__array__)
        elif self.__type__ == NessiList.DOUBLE:
            result.__array__ = nessi_vector_bind.DoubleNessiVector(\
                self.__array__)
        return result
    
##
# \ingroup append NessiList
#
# \brief Function used to append elements to a NessiList
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
# >>> MyList = NessiList(5)
# \endcode
# the <i>append</i> method will add the new element after the 5 first "0".
# elements
# \code
# >>> MyList.append(10.5)
# >>> MyList[5]
# 10.5
# \endcode
#
# \param self <i>this</i>
# \param number (INPUT) is the number to append

    def append(self, number):
        """
        -----------------------------------------------------------------------
        This function is used to append a value to an instance of a NessiList,
        MyNessiList:

        >>> MyNessiList.append(10.5)

        The size of the instance increases of 1 unit and the new element
        appended is the new last element of the instance. That can be a
        confusion in the case the size of the instance has already been
        declared during the initialization process. For example, if a
        NessiList has been defined has a 5 elements long of type double

        >>> MyList = NessiList(5)

        the append method will add the new element after the 5 first \"0\"
        elements

        >>> MyList.append(10.5)
        >>> MyList[5]
        10.5

        Parameters:
        ----------
        -> number is the number to append

        """

        if(self.__type__ == self.DOUBLE):
            self.__array__.append(float(number))
        elif(self.__type__ == self.INT):
            self.__array__.append(int(number))


##
# \ingroup extend NessiList
#
# \brief Function used to append elements to a NessiList
#
# This function is used to append one or more values to an instance of
# the NessiList, <i>MyNessiList</i>:
# \code
# >>> MyNessiList.extend(10.5)
# \endcode
# The size of the instance increases of 1 unit and the new element appended is
# the new last element of the instance. That can be a confusion in the case the
# size of the instance has already been declared during the initialization
# process. For example, if a NessiList has been defined has a 5 elements
# long of type <i>double</i>
# \code
# >>> MyList = NessiList(5)
# \endcode
# the <i>extend</i> method will add the new element after the 5 first "0".
# elements
# \code
# >>> MyList.extend(10.5)
# >>> MyList[5]
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
# >>> MyNessiList.append(1)
# >>> MyNessiList.append(2)
# >>> MyNessiList.append(3)
# >>> MyNessiList.append(4)
# ...
# \endcode
# It is also possible to extend the NessiList by passing it a Python list:
# \code
# >>> MyNessiList.extend([1,2,3,4,5,6,7,8])
# \endcode
#
# \param self <i>this</i>
# \param *number (INPUT) is(are) the number(s) to append to the NessiList

    def extend(self, *number):
        """
        -----------------------------------------------------------------------
        This function is used to append one or more values to an instance of
        the NessiList, MyNessiList:

        >>> MyNessiList.extend(10.5)

        The size of the instance increases of 1 unit and the new element
        appended is the new last element of the instance. That can be a
        confusion in the case the size of the instance has already been
        declared during the initialization process. For example, if a
        NessiList has been defined has a 5 elements long of type double

        >>> MyList = NessiList(5)

        the extend method will add the new element after the 5 first \"0\"
        elements

        >>> MyList.extend(10.5)
        >>> MyList[5]
        10.5

        It is also possible to extend several values in the same time as
        illustrated here:

        >>> MyNessiList.extend(1,2,3,4,5,6,7,8)

        This is the same as appending 1, then 2, then 3, and so on.... one
        after the other.

        >>> MyNessiList.append(1)
        >>> MyNessiList.append(2)
        >>> MyNessiList.append(3)
        >>> MyNessiList.append(4)
        ...

        Parameters:
        ----------
        -> *number is(are) the number(s) to append to the NessiList

        """

        for num in number:
            try:
                for i in num:
                    self.append(i)
            except TypeError:
                self.append(num)

##
# \ingroup __repr__ NessiList
#
# \brief Function that is used to get the representation of a NessiList
#
# This function is used to return the representation of a NessiList
#
# \code
# >>> MyNessiList = NessiList()
# >>> MyNessiList.append(1,2,3,4,5)
# >>> MyNessiList
# [1.0,2.0,3.0,4.0,5.0]
# \endcode
#
# \param self <i>this</i>
#
# \return The string representation of the NessiList. It uses the
#         <i>__str__</i> function

    def __repr__(self):
        """
        -----------------------------------------------------------------------
        This function is used to return the representation of a NessiList

        >>> MyNessiList = NessiList()
        >>> MyNessiList.append(1,2,3,4,5)
        >>> MyNessiList
        [1.0,2.0,3.0,4.0,5.0]

        Return:
        ------
        <- The string representation of the NessiList. It uses the __str__
           function

        """

        return self.__str__()

##
# \ingroup __iter__ NessiList
#
# \brief Function returns an iterator for a NessiList
#
# This function returns an iterator for a NessiList
#
# \param self <i>this</i>
#
# \return an iterator for the NessiList

    def __iter__(self):
        """
        -----------------------------------------------------------------------
        This function returns an iterator for a NessiList

        Return:
        ------
        <- an iterator for the NessiList

        """

        return iter(self.__array__)

##
# \ingroup __reversed__ NessiList
#
# \brief Function returns a backwards iterator for a NessiList
#
# This function returns a backwards iterator for a NessiList
#
# \param self <i>this</i>
#
# \return a backwards iterator for the NessiList
#
# \exception StopIteration is raise if the index accessed is not in the
#            NessiList

    def __reversed__(self):
        """
        -----------------------------------------------------------------------
        This function returns a backwards iterator for a NessiList

        Return:
        ------
        <- a backwards iterator for the NessiList

        Exceptions:
        ----------
        <- StopIteration is raise if the index accessed is not in the NessiList

        """

        i = len(self.__array__) - 1
        while True:
            try:
                yield self.__array__[i]
            except IndexError:
                raise StopIteration
            i = i - 1

##
# \ingroup __getitem__ NessiList
#
# \brief Function used to get an element of a NessiList.
#
# This function is used to retrieve a particular element of a NessiList
#
# To get the \f$i^{th}\f$ value of the NessiList \f$MyNessiList\f$,
# \code
# >>> MyNessiList[i]
# \endcode
#
# \param self <i>this</i>
# \param m (INPUT) is the index of the element to be retrieved
#
# \return the value at the given index
#
# \exception IndexError is raised if m > len(self) - 1

    def __getitem__(self, m):
        """
        -----------------------------------------------------------------------
        This function is used to retrieve a particular element of a NessiList

        To get the ith value of the NessiList MyNessiList,

        >>> MyNessiList[i]

        Parameters:
        ----------
        -> m is the index of the element to be retrieved

        Return:
        ------
        <- the value at the given index

        Exceptions:
        ---------
        <- IndexError is raised if m > len(self) - 1

        """

        return self.__array__[m]

##
# \ingroup __setitem__ NessiList
#
# \brief Function used to set an element of a NessiList.
#
# This function is used to a particular element of a NessiList to the provided
# value.
#
# To set the \f$i^{th}\f$ value of the NessiList \f$MyNessiList\f$,
# \code
# >>> MyNessiList[i]=5
# \endcode
#
# \param self <i>this</i>
# \param m (INPUT) is the index of the element to replace
# \param val (INPUT) is the value to replace the exisiting element with

    def __setitem__(self, m, val):
        """
        -----------------------------------------------------------------------
        This function is used to a particular element of a NessiList to the
        provided value.

        To set the ith value of the NessiList MyNessiList,
        >>> MyNessiList[i]=5

        Parameters:
        ----------
        -> m is the index of the element to replace
        -> val is the value to replace the exisiting element with

        """

        return self.__array__.__setitem__(m, val)

##
# \ingroup __getslice__ NessiList
#
# \brief Function used to get a range of values from a NessiList.
#
# This function is used to return a slice (range of values) from a NessiList.
# Optional input parameters can be used to set the indicies of the slice.
# Negative indices are not supported.
#
# \param self <i>this</i>
# \param i (INPUT/OPTIONAL) is the index of the first element to get (0 by
# default, i.e., first element of the NessiList)
# \param j (INPUT/OPTIONAL) is the index + 1 of the last element to get (-1 by
# default, i.e., last element of the NessiLst)
#
# \return The elements defined by the slice

    def __getslice__(self, i=0, j=-1):
        """
        -----------------------------------------------------------------------
        This function is used to return a slice (range of values) from a
        NessiList. Optional input parameters can be used to set the indicies
        of the slice. Negative indices are not supported.

        Parameters:
        ----------
        -> i is the index of the first element to get (0 by default, i.e.,
           first element of the NessiList)
        -> j is the index + 1 of the last element to get (-1 by default, i.e.,
           last element of the NessiList)

        Return:
        ------
        <- the elements defined by the slice

        """
        slice = self.__array__[i:j]
        result = NessiList(type=self.__type__)
        result.__array__.__set_from_Vector__(slice)
        del slice
        return result

##
# \ingroup __setslice__ NessiList
#
# \brief Function used to get a range of values from a NessiList.
#
# This function is used to set a range of elements to the provided value.
# Negative indices are not supported.
#
# \param self <i>this</i>
# \param i (INPUT) is the index to start the element replacement
# \param j (INPUT) is the index to end the element replacement
# \param val (INPUT) is the value to replace the NessiList's elements with

    def __setslice__(self, i, j, val):
        """
        -----------------------------------------------------------------------
        This function is used to set a range of elements to the provided value.
        Negative indices are not supported.

        Parameters:
        ----------
        -> i is the index to start the element replacement
        -> j is the index to end the element replacement
        -> val is the value to replace the NessiList's elements with

        """

        return self.__array__.__setslice__(i, j, val)

##
# \ingroup __len__ NessiList
#
# \brief Function used to get the length of the NessiList
#
# This function is used to return the length of the NessiList
# \code
# >>> len(MyNessiList)
# \endcode
#
# \param self <i>this</i>
#
# \return The length of the NessiList

    def __len__(self):
        """
        -----------------------------------------------------------------------
         This function is used to return the length of the NessiList

         >>> len(MyNessiList)

         Return:
         ------
         <- the length of the NessiList

        """

        return len(self.__array__)

##
# \ingroup __add__ NessiList
#
# \brief The operator \f$+\f$ allows to add two NessiList together or each
#        member of a NessiList with a scalar
#
# This operation allows one to add two NessiList together or each member of a
# NessiList with a scalar
#
# To add two NessiLists together or a NessiList with a scalar, use the
# following technique:
# \code
# >>> NessiList_VV = NessiList_1 + NessiList_2
# >>> NessiList_VS = NessiList + Scalar
# \endcode
#
# \return The resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __add__(self, right):
        """
        -----------------------------------------------------------------------
        This operation allows one to add two NessiList together or each member
        of a NessiList with a scalar

        To add two NessiLists together or a NessiList with a scalar, use the
        following technique:

        >>> NessiList_VV = NessiList_1 + NessiList_2
        >>> NessiList_VS = NessiList + Scalar

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """

        try:
            if len(self) != len(right):
                raise ValueError("Cannot add things of unequal length")
            result = NessiList(type=self.__type__)

            for (a, b) in map(None, self, right):
                result.append(a+b)
            return result

        except TypeError: # must be a scalar
            result = NessiList(type=self.__type__)
            for a in self:
                result.append(a+right)
            return result

        raise Exception("This statement should never be reached")

##
# \ingroup __radd__ NessiList
#
# \brief The operator \f$+\f$ allows to add a scalar with a NessiList.
#
# This operation allows to add a scalar with a NessiList
#
# To add each element of a NessiList with a scalar, use the following
# technique:
# \code
# >>> NessiList_SV = Scalar + NessiList
# \endcode
#
# \return The resulting NessiList

    def __radd__(self, left):
        """
        -----------------------------------------------------------------------
        This operation allows to add a scalar with a NessiList

        To add each element of a NessiList with a scalar, use the following
        technique:

        >>> NessiList_SV = Scalar + NessiList

        Return:
        ------
        <- the resulting NessiList

        """

        return self+left

##
# \ingroup __iadd__ NessiList
#
# The operator \f$+=\f$ allows to add a NessiList in place
#
# This operation allows one to add a NessiList in place
#
# To add each element of a NessiList with a scalar, use the following
# technique:
# \code
# >>> NessiList_SV = Scalar + NessiList
# \endcode
#
# \return The resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __iadd__(self, right):
        """
        -----------------------------------------------------------------------
        This operation allows one to add a NessiList in place

        To add each element of a NessiList with a scalar, use the following
        technique:

        >>> NessiList_SV = Scalar + NessiList

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """

        try:
            if len(self) != len(right):
                raise ValueError("Cannot add things of unequal length")

            for i in range(len(self)):
                self[i] = self[i] + right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i]=self[i]+right
            return self

        raise Exception("This statement should never be reached")

##
# \ingroup __sub__ NessiList
#
# \brief The operator \f$-\f$ allows to subtract two NessiLists or each member
#        of a NessiList by a scalar.
#
# This operation allows one to subtract two NessiLists or each member of a
# NessiList by a scalar
#
# To substract one NessiList from another or each member of a NessiList
# by a scalar, use the following technique:
# \code
# >>> NessiList_VV = NessiList_1 - NessiList_2
# >>> NessiList_VS = NessiList - Scalar
# \endcode
#
# \return the resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __sub__(self, right):
        """
        -----------------------------------------------------------------------
        This operation allows one to subtract two NessiLists or each member of
        a NessiList by a scalar

        To substract one NessiList from another or each member of a NessiList
        by a scalar, use the following technique:

        >>> NessiList_VV = NessiList_1 - NessiList_2
        >>> NessiList_VS = NessiList - Scalar

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """

        try:
            if len(self) != len(right):
                raise ValueError("Cannot subtract things of unequal length")
            result = NessiList(type=self.__type__)

            for (a, b) in map(None, self, right):
                result.append(a-b)
            return result

        except TypeError: # must be a scalar
            result = NessiList(type=self.__type__)
            for a in self:
                result.append(a-right)
            return result

        raise Exception("This statement should never be reached")

##
# \ingroup __rsub__ NessiList
#
# \brief The operator \f$-\f$ allows to subtract a scalar by a NessiList.
#
# This operation allows one to subtract a scalar by a NessiList
#
# To substract each element of a NessiList from a scalar, use the following
# technique:
# \code
# >>> NessiList_SV = Scalar - NessiList
# \endcode
#
# \return the resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __rsub__(self, left):
        """
        -----------------------------------------------------------------------
        This operation allows one to subtract a scalar by a NessiList

        To substract each element of a NessiList from a scalar, use the
        following technique:

        >>> NessiList_SV = Scalar - NessiList

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """

        try:
            if len(self) != len(right):
                raise ValueError("Cannot subtract things of unequal length")
            result = NessiList(type=self.__type__)

            for (a, b) in map(None, self, right):
                result.append(b-a)
            return result

        except TypeError: # must be a scalar
            result = NessiList(type=self.__type__)
            for a in self:
                result.append(left-a)
            return result

        raise Exception("This statement should never be reached")

##
# \ingroup __isub__ NessiList
#
# \brief The operator \f$-=\f$ allows to subtract a NessiList in place
#
# This operation allows one to subtract a NessiList in place
#
# To substract each element of a NessiList from a scalar, use the following
# technique:
# \code
# >>> NessiList_SV = Scalar - NessiList
# \endcode
#
# \return the resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __isub__(self, right):
        """
        -----------------------------------------------------------------------
        This operation allows one to subtract a NessiList in place

        To substract each element of a NessiList from a scalar, use the
        following technique:

        >>> NessiList_SV = Scalar - NessiList

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """
        try:
            if len(self) !=len (right):
                raise ValueError("Cannot subtract things of unequal length")

            for i in range(len(self)):
                self[i] = self[i] - right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i] = self[i] - right
            return self

        raise Exception("This statement should never be reached")

##
# \ingroup __mul__ NessiList
#
# \brief The operator \f$\times\f$ allows to multiply two NessiLists or each
#        member of a NessiList by a scalar.
#
# This operation allows one to multiply two NessiLists or each member of a
# NessiList by a scalar
#
# To multiply two NessiLists or each member of a NessiList by a scalar,
# use the following technique:
# \code
# >>> NessiList_VV = NessiList_1 * times NessiList_2
# >>> NessiList_VS = NessiList * Scalar
# \endcode
#
# \return the resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __mul__(self, right):
        """
        -----------------------------------------------------------------------
        This operation allows one to multiply two NessiLists or each member of
        a NessiList by a scalar

        To multiply two NessiLists or each member of a NessiList by a scalar,
        use the following technique:
        >>> NessiList_VV = NessiList_1 * times NessiList_2
        >>> NessiList_VS = NessiList * Scalar

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """

        try:
            if len(self) != len(right):
                raise ValueError("Cannot multiply things of unequal length")
            result = NessiList(type=self.__type__)

            for (a, b) in map(None, self, right):
                result.append(a*b)
            return result

        except TypeError: # must be a scalar
            result = NessiList(type=self.__type__)
            for a in self:
                result.append(a*right)
            return result

        raise Exception("This statement should never be reached")

##
# \ingroup __rmul__ NessiList
#
# The operator \f$\times\f$ allows to multiply a scalar by a NessiList.
#
# This operation allows one to multiply a scalar by a NessiList
#
# To multiply each element of a NessiList by a scalar, use the following
# technique:
# \code
# >>> NessiList_SV = scalar * NessiList
# \endcode
#
# \return The resulting NessiList

    def __rmul__(self, left):
        """
        -----------------------------------------------------------------------
        This operation allows one to multiply a scalar by a NessiList

        To multiply each element of a NessiList by a scalar, use the following
        technique:

        >>> NessiList_SV = scalar * NessiList

        Return:
        ------
        <- the resulting NessiList

        """

        return self*left

##
# \ingroup __imul__ NessiList
#
# The operator \f$\times=\f$ allows to multiply a NessiList in place.
#
# This operation allows one to multiply a NessiList in place
#
# To multiply each element of a NessiList by a scalar, use the following
# technique:
# \code
# >>> NessiList_SV = scalar * NessiList
# \endcode
#
# \return The resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __imul__(self, right):
        """
        -----------------------------------------------------------------------
        This operation allows one to multiply a NessiList in place

        To multiply each element of a NessiList by a scalar, use the following
        technique:

        >>> NessiList_SV = scalar * NessiList

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """
        try:
            if len(self) != len(right):
                raise ValueError("Cannot multiply things of unequal length")

            for i in range(len(self)):
                self[i] = self[i] * right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i] = self[i] * right
            return self

        raise Exception("This statement should never be reached")

##
# \ingroup __div__ NessiList
#
# \brief The operator \f$/\f$ allows to divide two NessiLists or each member
#        of a NessiList with a scalar.
#
# This operation allows one to divide two NessiLists or each member of a
# NessiList with a scalar
#
# To divide two NessiLists or each element of a NessiList by a scalar,
# use the following technique:
# \code
# >>> NessiList_VV = NessiList_1 / NessiList_2
# >>> NessiList_VS = NessiList / Scalar
# \endcode
#
# \return The resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __div__(self, right):
        """
        -----------------------------------------------------------------------
        This operation allows one to divide two NessiLists or each member of a
        NessiList with a scalar

        To divide two NessiLists or each element of a NessiList by a scalar,
        use the following technique:

        >>> NessiList_VV = NessiList_1 / NessiList_2
        >>> NessiList_VS = NessiList / Scalar

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """

        try:
            if len(self) != len(right):
                raise ValueError("Cannot divide things of unequal length")
            result = NessiList(type=self.__type__)

            for (a, b) in map(None, self, right):
                result.append(a/b)
            return result

        except TypeError: # must be a scalar
            result = NessiList(type=self.__type__)
            for a in self:
                result.append(a/right)
            return result

        raise Exception("This statement should never be reached")

##
# \ingroup __rdiv__ NessiList
#
# \brief The operator \f$/\f$ allows to divide a scalar by a NessiList.
#
# This operation allows one to divide a scalar by a NessiList
#
# To divide a scalar by each element of a NessiList, use the following
# technique:
# \code
# >>> NessiList_SV = scalar / NessiList
# \endcode
#
# \return The resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __rdiv__(self, left):
        """
        -----------------------------------------------------------------------
        The operator / allows to divide a scalar by a NessiList.

        To divide a scalar by each element of a NessiList, instead of using
        the function div provided by the NessiListUtils module, you can simply
        use the following technique:

        >>> NessiList_SV = scalar / NessiList

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """

        try:
            if len(self) != len(right):
                raise ValueError("Cannot divide things of unequal length")

            for i in range(len(self)):
                self[i] = self[i] / right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i] = self[i] / right
            return self

        raise Exception("This statement should never be reached")

##
# \ingroup __idiv__ NessiList
#
# \brief The operator \f$/=\f$ allows to divide a NessiList in place
#
# This operation allows one to divide a NessiList in place
#
# To divide a scalar by each element of a NessiList, use the following
# technique:
# \code
# >>> NessiList_SV = scalar / NessiList
# \endcode
#
# \return The resulting NessiList
#
# \exception Exception is raised if everything goes wrong
# \exception ValueError is raised if the two NessiLists are not of equal length

    def __idiv__(self, right):
        """
        -----------------------------------------------------------------------
        This operation allows one to divide a NessiList in place

        To divide a scalar by each element of a NessiList, use the following
        technique:

        >>> NessiList_SV = scalar / NessiList

        Return:
        ------
        <- the resulting NessiList

        Exceptions:
        ----------
        <- Exception is raised if everything goes wrong
        <- ValueError is raised if the two NessiLists are not of equal
           length

        """

        try:
            if len(self) != len(right):
                raise ValueError("Cannot divide things of unequal length")

            for i in range(len(self)):
                self[i] = self[i] / right[i]
            return self

        except TypeError: # must be a scalar
            for i in range(len(self)):
                self[i] = self[i] / right
            return self

        raise Exception("This statement should never be reached")

##
# \ingroup __contains__ NessiList
#
# \brief Function that searches the NessiList for a particular value
#
# This function searches the NessiList looking for the value provided.
#
# \param self <i>this</i>
# \param value (INPUT) is the value to search the NessiList for
#
# \return A boolean that is True if the value is in the NessiList and False
#         if not

    def __contains__(self, value):
        """
        -----------------------------------------------------------------------
        This function searches the NessiList looking for the value provided.

        Parameters:
        ----------
        -> value is the value to search the NessiList for

        Return:
        ------
        <- A boolean that is True if the value is in the NessiList and False
           if not

        """

        try:
            self.index(value)
            return True
        except ValueError:
            return False

##
# \ingroup __eq__ NessiList
#
# \brief Function that determines if all elements of NessiList are equal to
#        another NessiList
#
# This function determines if all the elements of the NessiList are equal to
# the given NessiList.
#
# \param self <i>this</i>
# \param other (INPUT) is the NessiList to compare
#
# \return A boolean that is True if all the elements are equal to the compared
#         NessiList and False if not

    def __eq__(self, other):
        """
        -----------------------------------------------------------------------
        This function determines if all the elements of the NessiList are
        equal to the given NessiList.

        Parameters:
        ----------
        -> other is the NessiList to compare

        Return:
        ------
        <- A boolean that is True if all the elements are equal to the compared
           NessiList and False if not

        """

        # check if they have the same length
        try:
            if len(self) != len(other):
                return False
        except:
            return False

        import utils

        # do it in c if they are both NessiLists
        if self.__class__ == other.__class__:
            return utils.vector_is_equals(self, other)

        # deep comparison
        try:
            for (mine, yours) in map(None, self, other):
                if utils.compare(mine, yours) != 0:
                    return False
        except:
            return False

        # anything that gets here must be okay
        return True


##
# \ingroup __ge__ NessiList
#
# \brief Function that determines if all elements of NessiList are greater than
#        or equal to another NessiList
#
# This function determines if all the elements of the NessiList are greater
# than or equal to the given NessiList.
#
# \param self <i>this</i>
# \param other (INPUT) is the NessiList to compare
#
# \return A boolean that is True if all the elements are greater than or equal
#         to the compared NessiList and False if not

    def __ge__(self, other):
        """
        -----------------------------------------------------------------------
        This function determines if all the elements of the NessiList are
        greater than or equal to the given NessiList.

        Parameters:
        ----------
        -> other is the NessiList to compare

        Return:
        ------
        <- A boolean that is True if all the elements are greater than or equal
           to the compared NessiList and False if not

        """

        # deep comparison
        import utils
        try:
            for (mine, yours) in map(None, self, other):
                if(utils.compare(mine, yours) < 0):
                    return False
        except:
            return False

        # anything that gets here must be okay
        return True

##
# \ingroup __gt__ NessiList
#
# \brief Function that determines if all elements of NessiList are greater than
#        another NessiList
#
# This function determines if all the elements of the NessiList are greater
# than the given NessiList.
#
# \param self <i>this</i>
# \param other (INPUT) is the NessiList to compare
#
# \return A boolean that is True if all the elements are greater than the
#         compared NessiList and False if not

    def __gt__(self, other):
        """
        -----------------------------------------------------------------------
        This function determines if all the elements of the NessiList are
        greater than the given NessiList.

        Parameters:
        ----------
        -> other is the NessiList to compare

        Return:
        ------
        <- A boolean that is True if all the elements are greater than the
           compared NessiList and False if not

        """

        # deep comparison
        import utils
        try:
            for (mine, yours) in map(None, self, other):
                if(utils.compare(mine,yours) != 1):
                    return False
        except:
            return False

        # anything that gets here must be okay
        return True

##
# \ingroup __ne__ NessiList
#
# \brief Function that determines if all elements of NessiList are not equal
#        to another NessiList
#
# This function determines if all the elements of the NessiList are not equal
# to the given NessiList. It uses the <i>__eq__</i> function to complete the
# task.
#
# \param self <i>this</i>
# \param other (INPUT) is the NessiList to compare
#
# \return A boolean that is True if all the elements are not equal to the
#         compared NessiList and False if not

    def __ne__(self, other):
        """
        -----------------------------------------------------------------------
        This function determines if all the elements of the NessiList are not
        equal to the given NessiList. It uses the __eq__ function to complete
        the task.

        Parameters:
        ----------
        -> other is the NessiList to compare

        Return:
        ------
        <- A boolean that is True if all the elements are not equal to the
           compared NessiList and False if not

        """

        return not self.__eq__(other)

##
# \ingroup __lt__ NessiList
#
# \brief Function that determines if all elements of NessiList are less than
#        another NessiList
#
# This function determines if all the elements of the NessiList are less than
# the given NessiList. It uses the <i>__ge__</i> function to complete the task.
#
# \param self <i>this</i>
# \param other (INPUT) is the NessiList to compare
#
# \return A boolean that is True if all the elements are less than the compared
#         NessiList and False if not

    def __lt__(self, other):
        """
        -----------------------------------------------------------------------
        This function determines if all the elements of the NessiList are less
        than the given NessiList. It uses the __ge__ function to complete the
        task.

        Parameters:
        ----------
        -> other is the NessiList to compare

        Return:
        ------
        <- A boolean that is True if all the elements are less than the
           compared NessiList and False if not

        """

        return not self.__ge__(other)

##
# \ingroup __le__ NessiList
#
# \brief Function that determines if all elements of NessiList are less than
#        or equal to another NessiList
#
# This function determines if all the elements of the NessiList are less than
# or equal to the given NessiList. It uses the <i>__gt__</i> function to
# complete the task.
#
# \param self <i>this</i>
# \param other (INPUT) is the NessiList to compare
#
# \return A boolean that is True if all the elements are less than or equal to
#         the compared NessiList and False if not

    def __le__(self, other):
        """
        -----------------------------------------------------------------------
        This function determines if all the elements of the NessiList are less
        than or equal to the given NessiList. It uses the __gt__ function to
        complete the task.

        Parameters:
        ----------
        -> other is the NessiList to compare

        Return:
        ------
        <- A boolean that is True if all the elements are less than or equal to
           the compared NessiList and False if not

        """

        return not self.__gt__(other)

##
# \ingroup index NessiList
#
# \brief Function used to find index of a item by matching values.
#
# This function is used to return the index of a requested item from the
# NessiList. Optional arguments to narrow the search range can be provided.
#
# \param self <i>this</i>
# \param item (INPUT) is the item to search for in the NessiList
# \param start (INPUT/OPTIONAL) is the index location to begin the search
# \param stop (INPUT/OPTIONAL) is the index location to stop the search
#
# \return the index of the requested item
#
# \exception ValueError is raised if the item in not found in the NessiList

    def index(self, item, start=0, stop=-1):
        """
        -----------------------------------------------------------------------
        This function is used to return the index of a requested item from the
        NessiList. Optional arguments to narrow the search range can be
        provided.

        Parameters:
        ----------
        -> item is the item to search for in the NessiList
        -> start is the index location to begin the search
        -> stop is the index location to stop the search

        Return:
        ------
        <- the index of the requested item

        Exceptions:
        ----------
        <- ValueError is raised if the item in not found in the NessiList

        """

        # fix the arguments
        if stop < start:
            stop = len(self.__array__)

        # search for the next occurence
        import utils
        for i in range(start, stop):
            if utils.compare(self.__array__[i], item) == 0:
                return i
        raise ValueError("NessiList.index(x): x not in list")

##
# \ingroup count NessiList
#
# \brief Function used to count the number of occurrences of a value
#
# This function takes a given value and counts the number of occurrences of
# that value in the NessiList.
#
# \param self <i>this</i>
# \param value (INPUT) is the value to the number of occurrences for
#
# \return the number of occurrences of the requested value

    def count(self, value):
        """
        -----------------------------------------------------------------------
        This function takes a given value and counts the number of occurrences
        of that value in the NessiList.

        Parameters:
        ----------
        -> value is the value to the number of occurrences for

        Return:
        ------
        <- the number of occurrences of the requested value

        """

        start = 0
        count = 0
        try:
            while True:
                start = self.index(value, start) + 1
                count = count + 1
        except ValueError:
            pass

        return count

##
# \ingroup pop NessiList
#
# \brief Function used to remove an element from the NessiList and return it
#        to the caller.
#
# This function is used to remove an element from the NessiList and return it
# to the caller. By not providing an index, the default behavior is to pop
# the last element from the NessiList.
#
# \param self <i>this</i>
# \param index (INPUT/OPTIONAL) is the index of the element which to pop from
#        the NessiList
#
# \return the object at the index requested
#
# \exception IndexError is raised is the NessiList is empty

    def pop(self, index=-1):
        """
        -----------------------------------------------------------------------
        This function is used to remove an element from the NessiList and
        return it to the caller. By not providing an index, the default
        behavior is to pop the last element from the NessiList.

        Parameters:
        ----------
        -> index is the index of the element which to pop from the NessiList

        Return:
        ------
        <- the object at the index requested

        Exceptions:
        ----------
        <- IndexError is raised is the NessiList is empty

        """

        if len(self.__array__) <= 0:
            raise IndexError("Cannot pop from an empty NessiList")

        result = self[index]
        del self[index]
        return result

##
# \ingroup __str__ NessiList
#
# \brief Function that displays elements of a NessiList.
#
# This function displays the elements of a NessiList. If the NessiList
# contains more than 10 elements, the 10 first elements, follow by 3 dots
# ". . ." and the last element of the NessiList are displayed.
#
# The default number of elements displayed can be changed by giving this number
# as parameter to the <i>__str__</i> method.
#
# \param self <i>this</i>
# \param last (INPUT/OPTIONAL) is the number of elements to display, 10 by
#        default
#
# \return
# - a list of the n first elements, 3 dots and last element of the NessiList,
# if the NessiList contains more than n elements
# - a list of all the elements of the NessiList, if the NessiList is
# smaller than n.

    def __str__(self, last=10):
        """
        -----------------------------------------------------------------------
        This function displays the elements of a NessiList. If the NessiList
        contains more than 10 elements, the 10 first elements, follow by 3 dots
        \". . .\" and the last element of the NessiList are displayed.

        The default number of elements displayed can be changed by giving this
        number as parameter to the __str__ method.

        Parameters:
        ----------
        -> last is the number of elements to display, 10 by default

        Returns:
        -------
        <- a list of the n first elements, 3 dots and last element of the
           NessiList, if the NessiList contains more than n elements
        <- a list of all the elements of the NessiList, if the NessiList is
           smaller than n.

        """

        result = []

        if len(self) < last:
            last = len(self)

        # print the first n elements
        for i in range(0, last):
            result.append(str(self.__array__[i]))

        # print elipses and the last element
        if len(self) > last:
            result.append("...")
            result.append(str(self.__array__[len(self) - 1]))

        return "["+",".join(result)+"]"

##
# \ingroup insert NessiList
#
# \brief Function that inserts an object in the NessiList at the specified
#        index
#
# This function provides a method to insert an object into the NessiList at
# the provided index location. Currently, this method is not supported.
#
# \param self <i>this</i>
# \param index (INPUT) is the index location to place the incoming object
# \param object (INPUT) is the object to be inserted
#
# \exception NotImplementedError is raised when the function is called since
#            the operation is not supported

    def insert(self, index, object):
        """
        -----------------------------------------------------------------------
        This function provides a method to insert an object into the NessiList
        at the provided index location. Currently, this method is not
        supported.

        Parameters:
        ----------
        -> index (INPUT) is the index location to place the incoming object
        -> object (INPUT) is the object to be inserted

        Exceptions:
        ----------
        <- NotImplementedError is raised when the function is called since the
           operation is not supported

        """
        # insert before index
        raise NotImplementedError("This operation is not currently supported")

##
# \ingroup __delitem__ NessiList
#
# \brief Function that deletes an element from the NessiList based on an index
#
# This function deletes an element from the NessiList based on the index
# provided.
#
# \param self <i>this</i>
# \param index (INPUT) is the index of the element to be deleted

    def __delitem__(self, index):
        """
        -----------------------------------------------------------------------
        This function deletes an element from the NessiList based on the index
        provided.

        Parameters:
        ----------
        -> index is the index of the element to be deleted

        """

        del self.__array__[index]

##
# \ingroup __delslice__ NessiList
#
# \brief Function that removes a slice from the NessiList
#
# This function removes a slice of the Nessiist based on the range provided.
#
# \param self <i>this</i>
# \param i (INPUT/OPTIONAL) is the starting position from which to remove
#        elements
# \param j (INPUT/OPTIONAL) is the ending position at which to stop removing
#        elements

    def __delslice__(self, i=0, j=-1):
        """
        -----------------------------------------------------------------------
        This function removes a slice of the Nessiist based on the range
        provided.

        Parameters:
        ----------
        -> i is the starting position from which to remove elements
        -> j is the ending position at which to stop removing elements

        """

        del self.__array__[i:j]

##
# \ingroup remove NessiList
#
# \brief Function that removes an element based on the provided value
#
# This function removes an element from the NessiList based on the provided
# value.
#
# \param self <i>this</i>
# \param value (INPUT) is the value of the element to be removed

    def remove(self, value):
        """
        -----------------------------------------------------------------------
        This function removes an element from the NessiList based on the
        provided value.

        Parameters:
        ----------
        -> value is the value of the element to be removed

        """

        # remove first occurence of value
        index = self.index(value)
        del self[index]

##
# \ingroup reverse NessiList
#
# \brief Function that reverses the elements of the NessiList
#
# This function takes the elements of the NessiList and reverses their order.
# It uses the <i>axis_manip</i> module function <i>reverse_array_nc</i> to
# reverse the list in place.
#
# \param self <i>this</i>
#
# \return the list in reversed order

    def reverse(self):
        """
        -----------------------------------------------------------------------
        This function takes the elements of the NessiList and reverses their
        order. It uses the axis_manip module function reverse_array_nc to
        reverse the list in place.

        Return:
        ------
        <- the list in reversed order

        """

        # reverse in place
        import axis_manip
        axis_manip.reverse_array_nc(self)
        return self

##
# \ingroup sort NessiList
#
# \brief Function that sorts the elements of the NessiList
#
# This function sorts the elements of a NessiList according to the provided
# specifications. This function, however, is not allowed in the current
# scheme.
#
# \exception NotImplementedError is raised if the function is called since
#            sort is not allowed on a NessiList

    def sort(self, cmp=None, key=None, reverse=False):
        """
        -----------------------------------------------------------------------
        This function sorts the elements of a NessiList according to the
        provided specifications. This function, however, is not allowed in the
        current scheme.

        Exceptions:
        ----------
        <- NotImplementedError is raised if the function is called since sort
           is not allowed on a NessiList

        """

        raise NotImplementedError("This function is not allowed")

##
# \}

##
# \ingroup toNumpy NessiList
#
# \brief Function that returns a NumPy representation of the NessiList
#
# This function will return a NumPy representation of the internal NessiList
# array.
#
# \param bin_centers This allows the bin centers to be returned rather than
# the array itself. This is useful for NessiLists holding histogram axes. The
# default value is <em>False</em>.
# \param kwargs (INPUT/OPTIONAL) is a list of keywords by the method.
# - <em>reshape</em>: A tuple containing the dimension sizes for a\n
#                     multi-dimensional representation.
#
# \return A NumPy representation of the NessiList

    def toNumPy(self, bin_centers=False, **kwargs):
        """
        _______________________________________________________________________
        This function will return a NumPy representation of the internal
        NessiList array.

        Parameters:
        ----------
        -> bin_centers a boolean which returns the bin centers
        -> kwargs is a list of keywords by the method.
           - reshape: A tuple containing the dimension sizes for a
                      multi-dimensional representation.

        Return:
        ------
        <- The NumPy representation of the NessiList
        """
        try:
            reshape = kwargs["reshape"]
        except KeyError:
            reshape = None

        if bin_centers:
            import utils
            array = utils.calc_bin_centers(self)[0]
        else:
            array = self

        import numpy
        if reshape is not None:
            return numpy.array(list(array)).reshape(reshape)
        else:
            return numpy.array(list(array))
        
##
# \}

##
# \defgroup max_vect nessi_list::max_vect
# \{

##
# Give the maximum value of the NessiList's elements
#
# \param array (INPUT) is a NessiList
#
# \return The maximum value of the NessiList
#
def max_vect(array):
    """
    ---------------------------------------------------------------------------
    Give the maximum value of the NessiList's elements

    Parameters:
    ----------
    -> array is a NessiList

    Return:
    ------
    <- the maximum value of the NessiList

    """

    max_value = array[0]
    for it in array:
        if it > max_value:
            max_value = it

    return max_value
##
# \}

##
# \defgroup min_vect nessi_list::min_vect
# \{

##
# Give the minimum value of the NessiList's elements
#
# \param array (INPUT) is a NessiList
#
# \return The minimum value of the NessiList
#
def min_vect(array):
    """
    ---------------------------------------------------------------------------
    Give the minimum value of the NessiList's elements

    Parameters:
    ----------
    -> array is a NessiList

    Return:
    ------
    <- the minimum value of the NessiList

    """

    min_value = array[0]
    for it in array:
        if it < min_value:
            min_value = it

    return min_value
##
# \}

##
# \defgroup print_multi nessi_list::print_multi
# \{

##
# Display side by side the first n elements of two, or three NessiLists.
#
# \param n (INPUT) is number of element to display
# \param object1 (INPUT) is the name of the first NessiList
# \param object2 (INPUT) is the name of the second NessiList
# \param object3 (INPUT/OPTIONAL) is the name of the third NessiList
#
def print_multi(n, object1, object2, object3=NessiList()):
    """
    ---------------------------------------------------------------------------
    Display side by side the first n elements of two, or three NessiLists.

    Parameters:
    ----------
    -> n is number of element to display
    -> object1 is the name of the first NessiList
    -> object2 is the name of the second NessiList
    -> object3 is the name of the third NessiList (optional)

    """

    tab = "\t\t"
    str_output = ""

    # find maximum value and then set the tab

    if (max_vect(object1) <= 9999):
        pass
    else:
        tab = tab + "\t"

    for i in range(0, n):

        if object1.__type__ == NessiList.DOUBLE:

            str_output = str_output + "%7.16f " \
                         % object1[i] + tab + \
                         "%7.16f " % object2[i]
            
            if len(object3) != 0:
                str_output = str_output + \
                             tab + "%7.16f \n" % object3[i]

        else:
            for i in range(0, n):
                str_output = str_output + "%d " % object1[i] \
                             + tab + "%d " % object2[i]
                
                if len(object3) != 0:
                    print str_output + tab + "%d \n" % object3[i]

        str_output = str_output

    print str_output
##
# \}

