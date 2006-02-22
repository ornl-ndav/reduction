###############################################################################
#
# File that contains common procedures for the tests
#
# $Id$
#
###############################################################################

from utils_bind import vector_is_equals_f
from utils_bind import vector_is_equals_d
from utils_bind import vector_is_equals_i
from utils_bind import vector_is_equals_u


def printVector(object, last=10):
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

    if funcName.endswith("_f"):
        dataval = vector_is_equals_f(output, truth_output)
        err2val = vector_is_equals_f(output_err2, truth_output_err2)
    elif funcName.endswith("_d"):
        dataval = vector_is_equals_d(output, truth_output)
        err2val = vector_is_equals_d(output_err2, truth_output_err2)
    elif funcName.endswith("_i"):
        dataval = vector_is_equals_i(output, truth_output)
        err2val = vector_is_equals_i(output_err2, truth_output_err2)
    elif funcName.endswith("_u"):
        dataval = vector_is_equals_u(output, truth_output)
        err2val = vector_is_equals_u(output_err2, truth_output_err2)
    else:
        raise TypeError, "Function type not recognized!"

    mess = funcName
    if len(funcName) > 30:
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

def makeCheck1(funcName, output, truth_output):

    """
    
       This function checks output and truth vectors for data

       funcName          : this is the name of the Swig binding layer function
       output            : this is the data array to be checked
       truth_output      : this is the truth data array to be checked against
    """

    dataval = ""

    if funcName.endswith("_f"):
        dataval = vector_is_equals_f(output, truth_output)
    elif funcName.endswith("_d"):
        dataval = vector_is_equals_d(output, truth_output)
    elif funcName.endswith("_i"):
        dataval = vector_is_equals_i(output, truth_output)
    elif funcName.endswith("_u"):
        dataval = vector_is_equals_u(output, truth_output)
    else:
        raise TypeError, "Function type not recognized!"

    mess = funcName
    mess += "............................."

    if dataval == False:
        mess += " Data Not OK"
    else:
        mess += " Functionality OK"

    return mess
