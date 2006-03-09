// nessi_vector.i - SWIG interface
//
// $Id$
//
%module nessi_vector_bind
%{
#include "nessi.hpp"
%}

// Need to ignore guard names from header files
%ignore _NESSI_HPP;

%include <std_vector.i>
%include "nessi.hpp"

namespace std {
	%template(IntVector) vector<int>;
	%template(DoubleVector) vector<double>;
}

namespace Nessi {
	%template(IntNessiVector) Vector<int>;
	%template(DoubleNessiVector) Vector<double>;
}
