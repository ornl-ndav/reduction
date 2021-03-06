###############################################################################
#
# File that contains common procedures for the tests
#
# $Id$
#
###############################################################################

##
# \file bindings/test/PBL/test_common_bind.py
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
# \} // end of printVector group
#

##
# \defgroup makeCheck test_common_bind::makeCheck
# \{

##
# \brief This function checks vector or value pairs against one another
#
# This function checks output and truth vectors or values for both data and
# square of the uncertainty in the data (err2) vectors or values. It can also
# handle just output and truth vectors only.
#
# \param funcName (INPUT) Name of the PBL function that was used to generate
#        the output
# \param output (INPUT) Data vector or value to be checked
# \param truth_output (INPUT) Truth data vector or value to be checked against
# \param output_err2 (INPUT/OPTIONAL) Err2 vector or value to be checked
# \param truth_output_err2 (INPUT/OPTIONAL) Truth err2 vector or value to be
#        checked against

def makeCheck(funcName, output, truth_output,
              output_err2=None, truth_output_err2=None):
   """

       This function checks output and truth vectors or values for both data
       and square of the uncertainty in the data (err2) vectors or values. It
       can also handle just output and truth vectors only.

       funcName          : this is the name of the PBL function
       output            : this is the vector or value to be checked
       truth_output      : this is the truth vector or value to be checked
                           against
       output_err2       : this is the err2 vector or value to be checked
       truth_output_err2 : this is the truth err2 vector or value to be
                           checked against
    """

   mess = funcName
   if len(funcName) > 34:
       mess += "..................."
   elif len(funcName) > 30 and len(funcName) <= 34:
       mess += "........................."
   else:
       mess += "............................."

   try:
       output.__type__()

       if funcName.endswith("_d"):
           dataval = vector_is_equals_d(output, truth_output)
           if output_err2 is not None and truth_output_err2 is not None:
               err2val = vector_is_equals_d(output_err2, truth_output_err2)
           else:
               err2val = True
       elif funcName.endswith("_i"):
            dataval = vector_is_equals_i(output, truth_output)
            if output_err2 is not None and truth_output_err2 is not None:
                err2val = vector_is_equals_i(output_err2, truth_output_err2)
            else:
                err2val = True
       else:
           raise TypeError("Function type not recognized!")

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

   except AttributeError:
       dataval = compare(output, truth_output)
       if output_err2 is not None and truth_output_err2 is not None:
           err2val = compare(output_err2, truth_output_err2)
       else:
           # Make it OK
           err2val = 0

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

##
# \}  // end of makeCheck group
#

##
# \defgroup makeSizeCheck test_common_bind::makeSizeCheck
# \{

##
# \brief This function checks the sizes of the vectors against one another
#
# This function checks the sizes of output and truth vectors for both data and
# square of the uncertainty in the data (err2) vectors. It can also handle
# just output and truth vectors only.
#
# \param funcName (INPUT) Name of the PBL function that was used to generate
#        the output
# \param output (INPUT) Data vector to be checked
# \param truth_output (INPUT) Truth data vector to be checked against
# \param output_err2 (INPUT/OPTIONAL) Err2 vector to be checked
# \param truth_output_err2 (INPUT/OPTIONAL) Truth err2 vector to be checked
#        against

def makeSizeCheck(funcName, output, truth_output,
                  output_err2=None, truth_output_err2=None):
   """

       This function checks the sizes of output and truth vectors for both data
       and square of the uncertainty in the data (err2) vectors. It can also
       handle just output and truth vectors only.

       funcName          : this is the name of the PBL function
       output            : this is the vector to be checked
       truth_output      : this is the truth vector to be checked
                           against
       output_err2       : this is the err2 vector to be checked
       truth_output_err2 : this is the truth err2 vector to be checked against
    """

   mess = funcName
   if len(funcName) > 34:
       mess += "..................."
   elif len(funcName) > 30 and len(funcName) <= 34:
       mess += "........................."
   else:
       mess += "............................."

   try:
       output.__type__()

       dataval = (len(output) == len(truth_output))
       if output_err2 is not None and truth_output_err2 is not None:
           err2val = (len(output_err2) == len(truth_output_err2))
       else:
           err2val = True

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

   except AttributeError:
       raise RuntimeError("Function expects arrays only.")

   return mess

##
# \}  // end of makeSizeCheck group
#
