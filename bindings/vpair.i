// vpair.i - SWIG interface
//
// $Id$
//
%module vpair_bind
%{
#include "vpair.hpp"
%}

// Need to ignore guard names from header files
%ignore _VPAIR_HPP;

%include "vpair.hpp"

%template(DoubleVPair) VPair<double>;
%template(IntVPair) VPair<int>;
