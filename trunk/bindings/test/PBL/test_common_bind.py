###############################################################################
#
# File that contains common procedures for the tests
#
# $Id$
#
###############################################################################

##
# \file bindings/PBL/test_common_bind.py
#

from utils_bind import compare
from utils_bind import vector_is_equals_d
from utils_bind import vector_is_equals_i

##
# \defgroup printVector test_common_bind::printVector
# \{

##
# \brief This function prints out a certain number of elements including the
# last.
#
# This function takes an array and prints out the first 10 elements of the
# array and the last element (if the array is larger than 10). An optional
# argument can be passed that changes the number of elements printed. The
# last element is always printed.
#
# \param object (INPUT) The array to be printed
# \param last (INPUT/OPTIONAL) The number of elements from the beginning of the
#        array to be printed

def printVector(object, last=10):
    """
    
       This function takes an array and prints out the first 10 elements of the
       array and the last element (if the array is larger than 10). An optional
       argument can be passed that changes the number of elements printed. The
       last element is always printed.

       object  :  The array to be printed
       last    :  The number of initial array elements to print
    """
    lenobj = len(object)

    if lenobj < last:
        last = lenobj

    for i in range(0, last, 1):
        print object[i],

    if lenobj > last:
        print "...",
        key = lenobj - 1
        print object[key]
        print
    else:
        print

##
# \}
#

##
# \defgroup makeCheck test_common_bind::makeCheck
# \{

##
# \brief This function checks vector sets against one another
#
# Thisfunction checks output and truth vectors for both data and
# square of the uncertainty in the data (err2) arrays.
#
# \param funcName (INPUT) Name of the PBL function that was used to generate
#        the output
# \param output (INPUT) Data array to be checked
# \param truth_output (INPUT) Truth data array to be checked against
# \param output_err2 (INPUT) Err2 array to be checked
# \param truth_output_err2 (INPUT) Truth err2 array to be checked against

def makeCheck(funcName, output, truth_output, output_err2, truth_output_err2):

    """
    
       This function checks output and truth vectors for both data and
       square of the uncertainty in the data (err2) arrays.

       funcName          : this is the name of the Swig binding layer function
       output            : this is the data array to be checked
       truth_output      : this is the truth data array to be checked against
       output_err2       : this is the err2 array to be checked
       truth_output_err2 : this is the truth err2 array to be checked against
    """

    dataval = ""
    err2val = ""

    if funcName.endswith("_d"):
        dataval = vector_is_equals_d(output, truth_output)
        err2val = vector_is_equals_d(output_err2, truth_output_err2)
    elif funcName.endswith("_i"):
        dataval = vector_is_equals_i(output, truth_output)
        err2val = vector_is_equals_i(output_err2, truth_output_err2)
    else:
        raise TypeError, "Function type not recognized!"

    mess = funcName
    if len(funcName) > 34:
        mess += "..................."
    elif len(funcName) > 30 and len(funcName) <= 34:
        mess += "........................."
    else:
        mess += "............................."

    if dataval == False or err2val == False:

        if dataval == False:
            if err2val == False:
                mess += " Data and Err2 Not OK"
            else:
                mess += " Data Not OK"
        elif err2val == False:
            mess += " Err2 Not OK"

    else:
        mess += " Functionality OK"

    return mess

##
# \}
#

##
# \defgroup makeCheck1 test_common_bind::makeCheck1
# \{

def makeCheck1(funcName, output, truth_output):

    """
    
       This function checks output and truth vectors for data

       funcName          : this is the name of the Swig binding layer function
       output            : this is the data array to be checked
       truth_output      : this is the truth data array to be checked against
    """

    dataval = ""

    if funcName.endswith("_d"):
        dataval = vector_is_equals_d(output, truth_output)
    elif funcName.endswith("_i"):
        dataval = vector_is_equals_i(output, truth_output)
    else:
        raise TypeError, "Function type not recognized!"

    mess = funcName
    if len(funcName) > 34:
        mess += "..................."
    elif len(funcName) > 30 and len(funcName) <= 34:
        mess += "........................."
    else:
        mess += "............................."

    if dataval == False:
        mess += " Data Not OK"
    else:
        mess += " Functionality OK"

    return mess

##
# \}
#

##
# \defgroup makeCheck2 test_common_bind::makeCheck2
# \{

def makeCheck2(funcName, output, truth_output, output_err2, truth_output_err2):

    """
    
       This function checks output and truth vectors for both data and
       square of the uncertainty in the data (err2) arrays.

       funcName          : this is the name of the Swig binding layer function
       output            : this is the value to be checked
       truth_output      : this is the truth value to be checked against
       output_err2       : this is the err2 value to be checked
       truth_output_err2 : this is the truth err2 value to be checked against
    """

    dataval = -1
    err2val = -1
    
    dataval = compare(output, truth_output)
    err2val = compare(output_err2, truth_output_err2)

    mess = funcName
    if len(funcName) > 34:
        mess += "................"
    elif len(funcName) > 30 and len(funcName) <= 34:
        mess += "......................"
    else:
        mess += ".........................."

    if dataval != 0 or err2val != 0:

        if dataval != 0:
            if err2val !=0:
                mess += " Data and Err2 Not OK"
            else:
                mess += " Data Not OK"
        elif err2val != 0:
            mess += " Err2 Not OK"

    else:
        mess += " Functionality OK"

    return mess

##
# \}
#
