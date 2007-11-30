###############################################################################
#
# File that contains common procedures for the tests
#
# $Id$
#
###############################################################################

from utils_bind import vector_is_equals_d
from utils_bind import vector_is_equals_i
import utils

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

def MakeCheck(function_type, output, truth_output, output_err2,
              truth_output_err2):
    """
       This function checks output and truth vectors for both data and
       square of the uncertainty in the data (err2) arrays.

       function_type     : this is the type of the Swig binding layer function
       output            : this is the data array to be checked
       truth_output      : this is the truth data array to be checked against
       output_err2       : this is the err2 array to be checked
       truth_output_err2 : this is the truth err2 array to be checked against
    """

    dataval = ""
    err2val = ""

    if function_type == "double" or function_type == "int" or \
        function_type == "vv" or function_type == "vs" or \
        function_type == "sv":
        dataval = utils.vector_is_equals(output, truth_output)
        err2val = utils.vector_is_equals(output_err2, truth_output_err2)
    else:
        raise TypeError("Function type not recognized!")

    if function_type == "vv":
        mess = "vector-vector"
    elif function_type == "vs":
        mess = "vector-scalar"
    elif function_type == "sv":
        mess = "scalar-vector"
    else:
        mess = function_type

    if function_type == "double":
        mess += "............................."
    else:
        mess += "................................"

    if not dataval or not err2val:

        if not dataval:
            if not err2val:
                mess += " Data and Err2 Not OK"
            else:
                mess += " Data Not OK"
        elif not err2val:
            mess += " Err2 Not OK"
    else:
        mess += " Functionality OK"

    return mess

def MakeCheck1(function_type, output, truth_output, output_err2=None,
               truth_output_err2=None):
    """
       This function checks output and truth vectors for both data and
       square of the uncertainty in the data (err2) arrays.

       function_type     : this is the type of the Swig binding layer function
       output            : this is the data array to be checked
       truth_output      : this is the truth data array to be checked against
       output_err2       : this is the err2 array to be checked
       truth_output_err2 : this is the truth err2 array to be checked against
    """

    dataval = ""
    err2val = ""

    dataval = utils.compare(output, truth_output)
    if output_err2 is not None and truth_output_err2 is not None:
        err2val = utils.compare(output_err2, truth_output_err2)
    else:
        # Make it OK
        err2val = 0

    mess = "scalar-scalar"

    if function_type == "double":
        mess += "............................."
    else:
        mess += "................................"

    if dataval or err2val:

        if dataval:
            if err2val:
                mess += " Data and Err2 Not OK"
            else:
                mess += " Data Not OK"
        elif err2val:
            mess += " Err2 Not OK"

    else:
        mess += " Functionality OK"

    return mess

def MakeCheck2(function_type, output, truth_output):
    """
       This function checks output and truth vectors for data arrays.

       function_type     : this is the type of the Swig binding layer function
       output            : this is the data array to be checked
       truth_output      : this is the truth data array to be checked against
    """

    dataval = ""

    dataval = utils.vector_is_equals(output, truth_output)

    mess = function_type

    if function_type == "double":
        mess += "............................."
    else:
        mess += "................................"

    if not dataval:
        mess += " Data Not OK"
    else:
        mess += " Functionality OK"

    return mess

