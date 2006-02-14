###############################################################################
#
# File that contains common procedures for the tests
#
# $Id$
#
###############################################################################

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


def makeCheck(dataval, err2val):
    mess = ""
    if dataval == False or err2val == False:
        if dataval == False:
            mess += " Data Not OK "
        elif err2val == False:
            mess += " Err2 Not OK"
    else:
        mess += " OK"

    return mess
